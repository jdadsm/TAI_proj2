#ifndef MARKOV_MODEL_HPP
#define MARKOV_MODEL_HPP

#include "HashTable.hpp" 

class MarkovModel {
private:
    HashTable table;
    int k;
    int alpha;
    bool saveModel;

public:
    MarkovModel(int k=2, int alpha=1);
    void train(const std::string& text);
    void printHashTable();
    double bitsToCompress(const std::string& text);
    int getK();
    int getAlpha();
};

#endif
