#include "Crawler.h"

#include <iostream>
#include <queue>
#include <regex>
#include <thread>

Crawler::Crawler(const std::vector<std::string> &start_urls,
                 std::shared_ptr<IDownloader> downloader,
                 std::shared_ptr<ILinkExtractor> link_extractor, std::shared_ptr<Indexer> indexer,
                 const std::vector<std::string> &domains, size_t max_pages, size_t num_threads)
    : start_urls(start_urls),
      downloader(downloader),
      link_extractor(link_extractor),
      indexer(indexer),
      domains(domains),
      max_pages(max_pages),
      pages_crawled(0),
      num_threads(num_threads) {}

void Crawler::startCrawling() {
    for (const auto &url : start_urls) {
        to_visit.push(url);
    }

    std::vector<std::thread> threads;
    for (size_t i = 0; i < num_threads; ++i) {
        threads.emplace_back(&Crawler::worker, this);
    }

    for (auto &thread : threads) {
        thread.join();
    }
}

void Crawler::worker() {
    while (true) {
        std::string current_url;

        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            if (to_visit.empty() || pages_crawled >= max_pages) {
                return;
            }

            current_url = to_visit.front();
            to_visit.pop();
        }

        if (visited.find(current_url) == visited.end()) {
            processPage(current_url);
            visited.insert(current_url);
            pages_crawled++;
        }
    }
}

void Crawler::processPage(const std::string &url) {
    bool in_domain = false;
    for (const auto &domain : domains) {
        if (url.find(domain) != std::string::npos) {
            in_domain = true;
            break;
        }
    }

    if (!in_domain) {
        std::cout << "Skipping URL outside of specified domains: " << url << std::endl;
        return;
    }

    try {
        std::string content = downloader->downloadPage(url);
        indexer->addToIndex(url, content);
        auto links = link_extractor->extractLinks(content);

        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            for (const auto &link : links) {
                link_map[url].insert(link);
                if (visited.find(link) == visited.end()) {
                    to_visit.push(link);
                }
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error processing page " << url << ": " << e.what() << std::endl;
    }
}

void Crawler::printLinkMap() const {
    for (const auto &entry : link_map) {
        std::cout << "Page: " << entry.first << std::endl;
        for (const auto &link : entry.second) {
            std::cout << "  -> " << link << std::endl;
        }
    }
}
