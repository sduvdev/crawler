#ifndef CRAWLER_H
#define CRAWLER_H

#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "IDownloader.h"
#include "ILinkExtractor.h"
#include "Indexer.h"

/**
 * @brief Class for crawling web pages starting from a given set of URLs.
 */
class Crawler {
   public:
    Crawler(const std::vector<std::string>& start_urls, std::shared_ptr<IDownloader> downloader,
            std::shared_ptr<ILinkExtractor> link_extractor, std::shared_ptr<Indexer> indexer,
            const std::vector<std::string>& domains, size_t max_pages, size_t num_threads);

    void startCrawling();
    void printLinkMap() const;

   private:
    void processPage(const std::string& url);
    void worker();

    std::vector<std::string> start_urls;     /**< The starting URLs for the crawling process. */
    std::shared_ptr<IDownloader> downloader; /**< Downloader for fetching web pages. */
    std::shared_ptr<ILinkExtractor>
        link_extractor;               /**< Link extractor for extracting links from web pages. */
    std::shared_ptr<Indexer> indexer; /**< Indexer for indexing web page content. */
    std::unordered_set<std::string> visited; /**< Set of visited URLs. */
    std::unordered_map<std::string, std::unordered_set<std::string>>
        link_map;                     /**< Map of links between pages. */
    std::vector<std::string> domains; /**< Domains to restrict crawling. */
    size_t max_pages;                 /**< Maximum number of pages to crawl. */
    size_t pages_crawled;             /**< Number of pages crawled so far. */
    size_t num_threads;               /**< Number of threads to use for crawling. */

    std::mutex queue_mutex;           /**< Mutex for thread-safe access to the queue. */
    std::queue<std::string> to_visit; /**< Queue of URLs to visit. */
};

#endif  // CRAWLER_H
