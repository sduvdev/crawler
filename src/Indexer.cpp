#include "Indexer.h"

#include <sstream>

/**
 * @brief Adds content to the index.
 * @param url The URL of the page.
 * @param content The content of the page.
 */
void Indexer::addToIndex(const std::string &url, const std::string &content) {
    std::istringstream stream(content);
    std::string word;
    while (stream >> word) {
        index[word].insert(url);
    }
}

/**
 * @brief Searches the index for pages containing the given term.
 * @param term The search term.
 * @return A set of URLs containing the term.
 */
std::unordered_set<std::string> Indexer::search(const std::string &term) const {
    auto it = index.find(term);
    if (it != index.end()) {
        return it->second;
    }
    return {};
}

/**
 * @brief Searches the index for pages containing all the given terms.
 * @param terms The search terms.
 * @return A set of URLs containing all the terms.
 */
std::unordered_set<std::string> Indexer::searchMultiple(
    const std::vector<std::string> &terms) const {
    std::unordered_set<std::string> result;
    for (const auto &term : terms) {
        auto it = index.find(term);
        if (it != index.end()) {
            if (result.empty()) {
                result = it->second;
            } else {
                std::unordered_set<std::string> intersection;
                for (const auto &url : result) {
                    if (it->second.find(url) != it->second.end()) {
                        intersection.insert(url);
                    }
                }
                result = intersection;
            }
        } else {
            return {};
        }
    }
    return result;
}

/**
 * @brief Searches the index for pages containing the given term but excluding pages containing any
 * of the exclude terms.
 * @param term The search term.
 * @param exclude_terms The terms to exclude.
 * @return A set of URLs containing the term but not the exclude terms.
 */
std::unordered_set<std::string> Indexer::searchWithExclusion(
    const std::string &term, const std::vector<std::string> &exclude_terms) const {
    auto result = search(term);
    for (const auto &exclude_term : exclude_terms) {
        auto it = index.find(exclude_term);
        if (it != index.end()) {
            for (const auto &url : it->second) {
                result.erase(url);
            }
        }
    }
    return result;
}
