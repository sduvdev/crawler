#ifndef ILINKEXTRACTOR_H
#define ILINKEXTRACTOR_H

#include <string>
#include <vector>

/**
 * @brief Interface for extracting links from HTML content.
 */
class ILinkExtractor {
   public:
    virtual ~ILinkExtractor() = default;
    /**
     * @brief Extracts links from a given HTML page.
     * @param html The HTML content of the page.
     * @return A vector of extracted links.
     */
    virtual std::vector<std::string> extractLinks(const std::string& html) = 0;
};

#endif  // ILINKEXTRACTOR_H