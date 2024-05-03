#include "MainClass.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
MainClass::MainClass(int k, int alpha) : ai(k, alpha), human(k, alpha) {
}
void MainClass:: readData(string filePathPos, string filePathNeg){
    
    vector<string> dataPos;
    vector<string> dataNeg;
    ifstream filePos(filePathPos);
    ifstream fileNeg(filePathNeg);

    if (!filePos.is_open()) {
        cerr << "Error: Unable to open file " << filePathPos << endl;
        return ;
    }

    if (!fileNeg.is_open()) {
        cerr << "Error: Unable to open file " << filePathNeg << endl;
        return ;
    }

    string line;
    while (getline(filePos, line)) {
        dataPos.push_back(line);
        cout << "\nText: " << line << endl;
    }

    filePos.close();

    while (getline(fileNeg, line)) {
        dataNeg.push_back(line);
        cout << "\nText: " << line << endl;
    }

    fileNeg.close();

    input_data_pos = dataPos;
    input_data_neg = dataNeg;
}

void MainClass:: trainModels(){ 
    for (const string text : input_data_pos) {
        ai.train(text);
        std::cout << "AI bits: " << ai.bitsToCompress(text)<< std::endl;
    }

    for (const string text : input_data_neg) {
        human.train(text);
        std::cout << "Human bits: " <<human.bitsToCompress(text) << std::endl;
    }
}

int MainClass:: predict(string text, int label){
    double ai_bits = ai.bitsToCompress(text);
    double human_bits = human.bitsToCompress(text);
    cout << "\nBits to compress in human model: " << human_bits << endl;
    cout << "Bits to compress in AI model: " << ai_bits << endl;
    int pred_label = 1;
    if(human_bits<ai_bits){
        pred_label = 0;
    }
    fillConfusionMatrix(pred_label,label);
    return pred_label;
    
}




