#include "MainClass.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
MainClass::MainClass(int k, int alpha) : ai(k, alpha), human(k, alpha) {
}
void MainClass:: readData(string filename){
    
    vector<pair<string, int>> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return ;
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

    input_data = data;
}

void MainClass:: trainModels(){ 
    for (const auto& pair : input_data) {
        const string& text = pair.first;
        int label = pair.second;
        if(label == 1){
            ai.train(text);
            std::cout << "AI bits: " << ai.bitsToCompress(text)<< std::endl;
    
        }else if(label == 0){
            human.train(text);
            std::cout << "Human bits: " <<human.bitsToCompress(text) << std::endl;
        }
    }
}

int MainClass:: predict(string text, int label){
    double ai_bits = ai.bitsToCompress(text);
    double human_bits = human.bitsToCompress(text);
    int pred_label = 1;
    if(human_bits<ai_bits){
        pred_label = 0;
    }
    fillConfusionMatrix(pred_label,label);
    return pred_label;
    
}




