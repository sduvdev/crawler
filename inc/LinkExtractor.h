#ifndef LINKEXTRACTOR_H
#define LINKEXTRACTOR_H

#include <gumbo.h>

#include <string>
#include <vector>

#include "ILinkExtractor.h"

/**
 * @brief Class for extracting links from HTML content using Gumbo.
 */
class LinkExtractor : public ILinkExtractor {
   public:
    /**
     * @brief Extracts links from a given HTML page.
     * @param html The HTML content of the page.
     * @return A vector of extracted links.
     */
    std::vector<std::string> extractLinks(const std::string& html) override;

   private:
    /**
     * @brief Searches for links in a GumboNode.
     * @param node The GumboNode to search for links.
     * @param links A reference to a vector of links to be populated.
     */
    void searchForLinks(GumboNode* node, std::vector<std::string>& links);
};

#endif  // LINKEXTRACTOR_H