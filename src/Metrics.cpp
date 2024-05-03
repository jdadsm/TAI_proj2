class Metrics {
private:
    std::unordered_map<std::string, std::unordered_map<char, unsigned int>> table;

public:
    void increment(const std::string& context, char nextChar);
    void printHashTable();
    double calculateProbability(const std::string& context,char nextChar,int alpha);
};