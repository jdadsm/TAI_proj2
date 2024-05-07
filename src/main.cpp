#include "MainClass.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;


int main(int argc, char* argv[]) {
    int k = 2;
    int alpha = 1;
    string nameToSaveModel = "";
    string filePathPos = "data/pos_data_train.csv";
    string filePathNeg = "data/neg_data_train.csv";
    string filePathPosTest = "data/pos_data_test.csv";
    string filePathNegTest = "data/neg_data_test.csv";

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-fp" && i + 1 < argc) {
            filePathPos = argv[++i];
        } else if (arg == "-fn" && i + 1 < argc) {
            filePathNeg = argv[++i];
        } else if (arg == "-k" && i + 1 < argc) {
            k = std::stoi(argv[++i]);
        } else if (arg == "-a" && i + 1 < argc) {
            alpha = std::stoi(argv[++i]);
        } else if (arg == "-s" && i + 1 < argc) {
            nameToSaveModel = argv[++i];
        }
    }

    
    MainClass main(k,alpha);

    main.readData(filePathPos,filePathNeg,filePathPosTest,filePathNegTest);

    auto start = std::chrono::high_resolution_clock::now();
 
  
    main.trainModels();
    
    auto end = std::chrono::high_resolution_clock::now();


    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Training Time: " << duration.count() << " seconds" << std::endl;



    if(nameToSaveModel!=""){
        main.saveModels(nameToSaveModel);
    }

    main.printHashTableNeg();
    //main.printHashTablePos();

    auto start1 = std::chrono::high_resolution_clock::now();
 
  
    main.testModels();
    
    auto end1 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::seconds>(end1 - start1);
    std::cout << "Testing Time: " << duration1.count() << " seconds" << std::endl;
    
    main.printConfusionMatrix();

    cout << "Recall: " << main.recall() << endl;
    cout << "Precision: " << main.precision() << endl;
    cout << "Accuracy: " << main.accuracy() << endl;
    cout << "F1score: " << main.f_score() << endl;
    

    return 0;
}