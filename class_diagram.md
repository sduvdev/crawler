# Class Diagram

## Crawler

- **Attributes**:
  - `start_urls: vector<string>`
  - `downloader: shared_ptr<IDownloader>`
  - `link_extractor: shared_ptr<ILinkExtractor>`
  - `indexer: shared_ptr<Indexer>`
  - `domains: vector<string>`
  - `max_pages: size_t`
  - `pages_crawled: size_t`
  - `num_threads: size_t`
  - `to_visit: queue<string>`
  - `visited: unordered_set<string>`
  - `queue_mutex: mutex`
  - `visited_mutex: mutex`
  - `link_map: unordered_map<string, unordered_set<string>>`
- **Operations**:
  - `Crawler(start_urls: vector<string>, downloader: shared_ptr<IDownloader>, link_extractor: shared_ptr<ILinkExtractor>, indexer: shared_ptr<Indexer>, domains: vector<string>, max_pages: size_t, num_threads: size_t)`
  - `startCrawling()`
  - `worker()`
  - `processPage(url: string)`
  - `printLinkMap()`

## IDownloader

- **Operations**:
  - `downloadPage(url: string): string`

## Downloader (implements IDownloader)

- **Operations**:
  - `downloadPage(url: string): string`
  - `WriteCallback(contents: void*, size: size_t, nmemb: size_t, userp: void*): size_t`

## ILinkExtractor

- **Operations**:
  - `extractLinks(html: string): vector<string>`

## LinkExtractor (implements ILinkExtractor)

- **Operations**:
  - `extractLinks(html: string): vector<string>`
  - `searchForLinks(node: GumboNode*, links: vector<string>&)`

## Indexer

- **Attributes**:
  - `index: unordered_map<string, unordered_set<string>>`
- **Operations**:
  - `addToIndex(url: string, content: string)`
  - `search(term: string): unordered_set<string>`
  - `searchMultiple(terms: vector<string>): unordered_set<string>`
  - `searchWithExclusion(term: string, exclude_terms: vector<string>): unordered_set<string>`
