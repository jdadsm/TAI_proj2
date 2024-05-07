#include "MainClass.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

MainClass::MainClass(int k, int alpha) : ai(k, alpha), human(k, alpha) {
}

void MainClass:: readData(string filePathPos, string filePathNeg,
                            string filePathPosTest,string filePathNegTest){
    
    vector<string> dataPos;
    vector<string> dataNeg;
    vector<string> dataPosTest;
    vector<string> dataNegTest;
    ifstream filePos(filePathPos);
    ifstream fileNeg(filePathNeg);
    ifstream filePosTest(filePathPosTest);
    ifstream fileNegTest(filePathNegTest);

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
        //cout << "\nText: " << line << endl;
    }

    filePos.close();

    while (getline(fileNeg, line)) {
        dataNeg.push_back(line);
        //cout << "\nText: " << line << endl;
    }

    fileNeg.close();

    while (getline(filePosTest, line)) {
        dataPosTest.push_back(line);
        //cout << "\nText: " << line << endl;
    }

    filePos.close();

    while (getline(fileNegTest, line)) {
        dataNegTest.push_back(line);
        //cout << "\nText: " << line << endl;
    }

    fileNeg.close();

    
    input_data_pos = dataPos;
    input_data_neg = dataNeg;
    input_data_pos_test = dataPosTest;
    input_data_neg_test = dataNegTest;
}

void MainClass:: trainModels(){ 
    for (const string text : input_data_pos) {
        ai.train(text);
        //cout << "AI bits: " << ai.bitsToCompress(text)<< endl;
    }
    for (const string text : input_data_neg) {
        human.train(text);
        //cout << "Human bits: " <<human.bitsToCompress(text) << endl;
    }
}

void MainClass:: saveModels(string nameToSaveModel){
    save_model(ai,"models/ai/"+nameToSaveModel+".dat");
    save_model(human,"models/human/"+nameToSaveModel+".dat");
}

int MainClass:: predict(string text, int label=0,bool update_cm=true){
    double ai_bits = ai.bitsToCompress(text);
    double human_bits = human.bitsToCompress(text);
    //cout << "\nBits to compress in human model: " << human_bits << endl;
    //cout << "Bits to compress in AI model: " << ai_bits << endl;
    int pred_label = 1;
    if(human_bits<ai_bits){
        pred_label = 0;
    }
    if(update_cm) fillConfusionMatrix(pred_label,label);
    return pred_label;
    
}

void MainClass:: testModels(){ 
    for (const string text : input_data_pos_test) {
        int predicted_value = predict(text,1);
        //cout << "AI label predict: " << predicted_value << endl;
    }

    for (const string text : input_data_neg_test) {
        int predicted_value = predict(text,0);
        //cout << "Human label predict: " << predicted_value << endl;
    }
}

void MainClass:: save_model(const MarkovModel& obj, const string filename) {
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
        file.close();
        cout << "Model saved to binary file: " << filename << endl;
    } else {
        cerr << "Error: Unable to open file for writing!" << endl;
    }
}

MarkovModel MainClass:: load_model(const string filename) {
    MarkovModel obj;
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
        file.close();
        cout << "Model loaded from binary file: " << filename << endl;
    } else {
        cerr << "Error: Unable to open file for reading!" << endl;
    }
    return obj;
}

void MainClass:: printHashTablePos(){
    ai.printHashTable();
}
void MainClass:: printHashTableNeg(){
    human.printHashTable();
}

MarkovModel MainClass:: getHumanModel(){
    return human;
}

MarkovModel MainClass:: getAiModel(){
    return ai;
}