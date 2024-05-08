#include <iostream>
#include <fstream>
#include "MainClass.hpp"
#include <string>
#include <algorithm>
std::string cleanInput(const std::string& input) {
    std::string cleanedText;
    for (char c : input) {
        if (std::isalnum(c)) { // Check if character is alphanumeric
            cleanedText += std::tolower(c); // Convert to lowercase and append
        }
    }
    // Remove spaces from the cleaned text
    cleanedText.erase(std::remove(cleanedText.begin(), cleanedText.end(), ' '), cleanedText.end());
    return cleanedText;
}
std::string loadTextFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return "";
    }

    std::string text;
    std::string line;
    while (std::getline(inFile, line)) {
        text += line + "\n";
    }

    inFile.close();
    return text;
}

std::string decision(double bits_ai, double bits_human) {
    if (bits_ai < bits_human) return "AI";
    return "Human";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = "../data/ai_sentence.txt";
    int k = 2;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-k" && i + 1 < argc) {
            k = std::stoi(argv[++i]);
        }else if (arg == "-f" && i + 1 < argc) {
            filename = argv[++i];
        }
    }

    std::string input = loadTextFromFile(filename);
    MainClass model(k, 1);
    MarkovModel ai = model.getAiModel();
    MarkovModel human = model.getHumanModel();
    HashTable ai_table = ai.getTable();
    HashTable human_table = human.getTable();
    ai_table.loadFromFile("ai.txt");
    human_table.loadFromFile("human.txt");
    ai.setTable(ai_table);
    human.setTable(human_table);

    double ai_bits = ai.bitsToCompress(input);
    double human_bits = human.bitsToCompress(input);
    std::cout << "AI model compression: " << ai_bits << " bits" << std::endl;
    std::cout << "Human model compression: " << human_bits << " bits" << std::endl;
    std::cout << "The source of this text is likely: " << decision(ai_bits, human_bits) << std::endl;

    
    return 0;
}
