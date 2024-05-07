#ifndef MARKOV_MODEL_HPP
#define MARKOV_MODEL_HPP

#include "HashTable.hpp"

using namespace std;

class MarkovModel {
private:
    HashTable table;
    int k;
    int alpha;

public:
    MarkovModel(int k=2, int alpha=1);
    void train(const string& text);
    void printHashTable();
    double bitsToCompress(const string& text);
    int getK();
    int getAlpha();
    HashTable getTable();
    void setTable(HashTable newTable) ;
};

#endif
