#ifndef IDOWNLOADER_H
#define IDOWNLOADER_H

#include <string>

/**
 * @brief Interface for downloading web pages.
 */
class IDownloader {
   public:
    virtual ~IDownloader() = default;
    /**
     * @brief Downloads the content of a given URL.
     * @param url The URL to download.
     * @return The HTML content of the page.
     */
    virtual std::string downloadPage(const std::string& url) = 0;
};

#endif  // IDOWNLOADER_H