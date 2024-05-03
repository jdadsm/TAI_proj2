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
};

class MarkovModel {
private:
    HashTable table;
    int k;
    std::string text;

public:
    MarkovModel( int k);
    void train(const std::string& text);
    void printHashTable();
};

#endif // MARKOV_MODEL_HPP
