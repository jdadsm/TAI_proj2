#include "MainClass.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


int main() {
    int k = 2;
    int alpha = 1;
    bool saveModel = true;
    MainClass main(k,alpha,saveModel);

    //provavelmente é boa ideia remover espaços, pontuação e caratéres estranhos
    //string filePathPos = "data/tiny_pos.csv";
    //string filePathNeg = "data/tiny_neg.csv";
    string filePathPos = "data/pos_data.csv";
    string filePathNeg = "data/neg_data.csv";
    string filePathPosTest = "data/tiny_pos_test.csv";
    string filePathNegTest = "data/tiny_neg_test.csv";
    main.readData(filePathPos,filePathNeg,filePathPosTest,filePathNegTest);

    main.trainModels();
   
    main.testModels();
    cout << "Accuracy: " << main.accuracy() << endl;
    cout << "F1score: " << main.f_score() << endl;
    main.printConfusionMatrix();

    return 0;
}