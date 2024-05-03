#include "MarkovModel.hpp"
#include "HashTable.hpp"
#include <cmath>

MarkovModel::MarkovModel(int k,int alpha) : k(k),alpha(alpha) {}

void MarkovModel::train(const std::string& text) {
    for (int i = 0; i <= text.length() - (k+1); ++i) {
        std::string context = text.substr(i, k);
        char nextChar = text[i + k];
        table.increment(context, nextChar);
    }
}
double MarkovModel::bitsToCompress(const std::string& text) {
    double sum = 0;
    for (int i = 0; i <= text.length() - (k+1); ++i) {
        std::string context = text.substr(i, k);
        char nextChar = text[i + k];
        sum-=log2(table.calculateProbability(context, nextChar,alpha));
    }
    return sum;
}
void MarkovModel::printHashTable() {
    table.printHashTable();
}
