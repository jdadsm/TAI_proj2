#include "HashTable.hpp"

void HashTable::increment(const std::string& context, char nextChar) {
    table[context][nextChar]++;
}

double HashTable::calculateProbability(const std::string& context,char nextChar,int alpha){
    // convem verifiar se context + next char existe na tabela
    std::unordered_map<char, unsigned int> nextChars = table[context];
    int target = 0;
    int all_counts = 0;
    int size = 0;
    for (const auto& pair : nextChars) {
        if (pair.first == nextChar)target = pair.second;
        all_counts+=pair.second;
        size++;
    }
    return static_cast<double>(target + alpha) / (all_counts + alpha * 62);
   
}
void HashTable::printHashTable() {
    std::cout << "Hashtable:" << std::endl;
    for (const auto& outer_entry : table) {
        std::cout << "Context: " << outer_entry.first << std::endl;
        const auto& inner_map = outer_entry.second;
        for (const auto& inner_entry : inner_map) {
            std::cout << "  Next Char: " << inner_entry.first << ", Count: " << inner_entry.second << std::endl;

        }
    }
}