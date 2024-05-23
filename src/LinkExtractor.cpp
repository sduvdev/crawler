#include "LinkExtractor.h"

#include <iostream>

std::vector<std::string> LinkExtractor::extractLinks(const std::string& html) {
    std::vector<std::string> links;
    GumboOutput* output = gumbo_parse(html.c_str());
    searchForLinks(output->root, links);
    gumbo_destroy_output(&kGumboDefaultOptions, output);
    return links;
}

void LinkExtractor::searchForLinks(GumboNode* node, std::vector<std::string>& links) {
    if (node->type != GUMBO_NODE_ELEMENT) {
        return;
    }

    if (node->v.element.tag == GUMBO_TAG_A) {
        GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
        if (href) {
            links.push_back(href->value);
            std::cout << "Found link: " << href->value << std::endl;
        }
    }

    const GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        searchForLinks(static_cast<GumboNode*>(children->data[i]), links);
    }
}