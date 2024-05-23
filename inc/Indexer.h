#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief Class for indexing web page content and searching the index.
 */
class Indexer {
   public:
    void addToIndex(const std::string& url, const std::string& content);

    std::unordered_set<std::string> search(const std::string& term) const;
    std::unordered_set<std::string> searchMultiple(const std::vector<std::string>& terms) const;
    std::unordered_set<std::string> searchWithExclusion(
        const std::string& term, const std::vector<std::string>& exclude_terms) const;

   private:
    std::unordered_map<std::string, std::unordered_set<std::string>>
        index; /**< Inverted index of terms to URLs. */
};

#endif  // INDEXER_H
