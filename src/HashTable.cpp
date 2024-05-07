#include "HashTable.hpp"

void HashTable::increment(const std::string& context, char nextChar) {
    table[context][nextChar]++;
}

double HashTable::calculateProbability(const std::string& context, char nextChar, int alpha) {
    auto it = table.find(context);
    int target = 0;
    int all_counts = 0;
    if (it != table.end()) {
        std::unordered_map<char, unsigned int> nextChars = table[context];
        for (const auto& pair : nextChars) {
            if (pair.first == nextChar) target = pair.second;
            all_counts += pair.second;
        }
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

std::string HashTable::serializeHashtable() {
    std::stringstream ss;
    for (const auto& pair : table) {
        ss << pair.first << ":";
        for (const auto& innerPair : pair.second) {
            ss << innerPair.first << "," << innerPair.second << ";";
        }
        ss << "|";
    }
    return ss.str();
}

void HashTable::deserializeHashtable(const std::string& serializedData) {
    table.clear(); // Clear existing data
    std::istringstream iss(serializedData);
    std::string contextData;
    while (std::getline(iss, contextData, '|')) {
        std::istringstream contextStream(contextData);
        std::string context;
        std::getline(contextStream, context, ':');
        std::unordered_map<char, unsigned int> charCounts;
        char ch;
        unsigned int count;
        while (contextStream >> ch) {
            contextStream.ignore(); // Ignore the comma
            contextStream >> count;
            charCounts[ch] = count;
            if (contextStream.peek() == ';') contextStream.ignore();
        }
        table[context] = charCounts;
    }
}


void HashTable::saveToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        std::string serializedData = serializeHashtable();
        outFile << serializedData;
        outFile.close();
        std::cout << "Hashtable saved to file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void HashTable::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::stringstream buffer;
        buffer << inFile.rdbuf();
        std::string serializedData = buffer.str();
        deserializeHashtable(serializedData);
        inFile.close();
        std::cout << "Hashtable loaded from file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
const std::unordered_map<std::string, std::unordered_map<char, unsigned int>>& HashTable::getTable() const {
    return table;
}
void HashTable::setTable(const std::unordered_map<std::string, std::unordered_map<char, unsigned int>>& newTable) {
    table = newTable;
}