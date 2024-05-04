#include "MainClass.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main() {
    int k = 2;
    int alpha = 1;
    string nameToSaveModel = "model1.bin";

    MainClass main(k,alpha);

    string filePathPos = "data/pos_data_train.csv";
    string filePathNeg = "data/neg_data_train.csv";
    string filePathPosTest = "data/pos_data_test.csv";
    string filePathNegTest = "data/neg_data_test.csv";
    main.readData(filePathPos,filePathNeg,filePathPosTest,filePathNegTest);

    main.trainModels();
   
    if(nameToSaveModel!=""){
        main.saveModels(nameToSaveModel);
    }

    main.testModels();
    main.printConfusionMatrix();

    cout << "Recall: " << main.recall() << endl;
    cout << "Precision: " << main.precision() << endl;
    cout << "Accuracy: " << main.accuracy() << endl;
    cout << "F1score: " << main.f_score() << endl;
    

    return 0;
}