#include <iostream>
#include <vector>
#include "MarkovModel.hpp"
#include <fstream>
#include <sstream>

using namespace std;

vector<pair<string,int>> readData(string filename){
    
    vector<pair<string, int>> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return data;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string text;
        int label;

        if (getline(iss, text, ',') && (iss >> label)) {
            data.push_back({text, label});
        } else {
            cerr << "Error: Invalid line format in file " << filename << endl;
            continue;
        }
    }

    file.close();

    return data;
}

int main() {
    
    int k = 2;
    string filePath = "data/tiny.csv";
    //provavelmente é boa ideia remover espaços, pontuação e caratéres estranhos
    vector<pair<string,int>> data = readData(filePath);

    MarkovModel human(k);
    MarkovModel ai(k);
    
    for (const auto& pair : data) {
        const string& text = pair.first;
        int label = pair.second;
        if(label == 1){
            ai.train(text);
        }else if(label == 0){
            human.train(text);
        }
    }
    
    ai.printHashTable();
    human.printHashTable();

    //falta fazer a parte equivalente ao calculateBits deles e as funções das métricas

    return 0;
}