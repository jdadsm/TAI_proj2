#ifndef MARKOV_MODEL_HPP
#define MARKOV_MODEL_HPP

#include <string>
#include <unordered_map>
#include <iostream>

class HashTable {
private:
    std::unordered_map<std::string, std::unordered_map<char, unsigned int>> table;

public:
    void increment(const std::string& context, char nextChar);
    void printHashTable();
    double calculateProbability(const std::string& context,char nextChar,int alpha);
};

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
