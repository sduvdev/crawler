#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <curl/curl.h>

#include <string>

#include "IDownloader.h"

/**
 * @brief Class for downloading web pages using libcurl.
 */
class Downloader : public IDownloader {
   public:
    /**
     * @brief Downloads the content of a given URL.
     * @param url The URL to download.
     * @return The HTML content of the page.
     */
    std::string downloadPage(const std::string& url) override;

   private:
    /**
     * @brief Callback function for writing downloaded data.
     * @param contents Pointer to the data.
     * @param size Size of each data element.
     * @param nmemb Number of data elements.
     * @param userp Pointer to user data.
     * @return The number of bytes written.
     */
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif  // DOWNLOADER_H