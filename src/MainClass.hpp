#ifndef MAIN_CLASS_HPP
#define MAIN_CLASS_HPP

#include "MarkovModel.hpp" 
#include "Metrics.hpp"
#include <string>
#include <vector>

using namespace std;

class MainClass:public Metrics {
private:
    MarkovModel ai;
    MarkovModel human;
    vector<string> input_data_pos;
    vector<string> input_data_neg;
    vector<string> input_data_pos_test;
    vector<string> input_data_neg_test;

public:
    MainClass(int k,int alpha=1);
    void trainModels();
    void readData(string filePathPos, string filePathNeg,string filePathPosTest,string filePathNegTest);
    int predict(string text, int label);
    void testModels();
    void save_model(const MarkovModel& obj, const string filename);
    MarkovModel load_model(const string filename);
    void saveModels(string nameToSaveModel);
};

#endif
