#include <memory>
#include <vector>

#include "Crawler.h"
#include "Downloader.h"
#include "Indexer.h"
#include "LinkExtractor.h"

/**
 * @brief Main function to start the web crawler.
 *
 * This function sets up the necessary components for the web crawler,
 * including the downloader, link extractor, and indexer. It then creates
 * the crawler object with the starting URLs, domain restriction, page limit,
 * and number of threads, and begins the crawling process.
 *
 * @return int Returns 0 upon successful completion.
 */
int main() {
    // Define the starting URLs, the domains for bounded crawling, the maximum number of pages to
    // crawl, and the number of threads
    std::vector<std::string> start_urls = {"https://harrypotter.fandom.com/wiki/Main_Page"};
    std::vector<std::string> domains = {"harrypotter.fandom.com"};
    size_t max_pages = 10;   // Set the maximum number of pages to crawl
    size_t num_threads = 4;  // Set the number of threads for crawling

    // Create the necessary components for the crawler
    auto downloader = std::make_shared<Downloader>();
    auto link_extractor = std::make_shared<LinkExtractor>();
    auto indexer = std::make_shared<Indexer>();

    // Create the Crawler object
    Crawler crawler(start_urls, downloader, link_extractor, indexer, domains, max_pages,
                    num_threads);

    // Start the crawling process
    crawler.startCrawling();

    // Print the link map
    crawler.printLinkMap();

    return 0;
}
