#include "MarkovModel.hpp"

void HashTable::increment(const std::string& context, char nextChar) {
    table[context][nextChar]++;
}

void HashTable::printHashTable() {
    std::cout << "Hashtable:" << std::endl;
    for (const auto& outer_entry : table) {
        std::cout << "Next Char: " << outer_entry.first << std::endl;
        const auto& inner_map = outer_entry.second;
        for (const auto& inner_entry : inner_map) {
            std::cout << "  Context: " << inner_entry.first << ", Value: " << inner_entry.second << std::endl;
        }
    }
}

MarkovModel::MarkovModel(int k) : k(k) {}

void MarkovModel::train(const std::string& text) {
    for (int i = 0; i <= text.length() - k; ++i) {
        std::string context = text.substr(i, k);
        char nextChar = text[i + k];
        table.increment(context, nextChar);
    }
}

void MarkovModel::printHashTable() {
    table.printHashTable();
}
