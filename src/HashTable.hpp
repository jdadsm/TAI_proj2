#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class HashTable {
private:
    std::unordered_map<std::string, std::unordered_map<char, unsigned int>> table;

public:
    void increment(const std::string& context, char nextChar);
    void printHashTable();
    double calculateProbability(const std::string& context, char nextChar, int alpha);
    std::string serializeHashtable();
    void deserializeHashtable(const std::string& serializedData);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    const std::unordered_map<std::string, std::unordered_map<char, unsigned int>>& getTable() const;
    void setTable(const std::unordered_map<std::string, std::unordered_map<char, unsigned int>>& newTable);

};
#endif