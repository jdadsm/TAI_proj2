#ifndef MARKOV_MODEL_HPP
#define MARKOV_MODEL_HPP
#include "HashTable.hpp" 

class MarkovModel {
private:
    HashTable table;
    int k;
    int alpha;

public:
    MarkovModel( int k,int alpha=1);
    void train(const std::string& text);
    void printHashTable();
    double bitsToCompress(const std::string& text);
};

#endif // MARKOV_MODEL_HPP
