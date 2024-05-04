#ifndef MAIN_CLASS_HPP
#define MAIN_CLASS_HPP

#include "MarkovModel.hpp" 
#include "Metrics.hpp"
#include <string>
#include <vector>

class MainClass:public Metrics {
private:
    MarkovModel ai;
    MarkovModel human;
    std::vector<std::string> input_data_pos;
    std::vector<std::string> input_data_neg;
    std::vector<std::string> input_data_pos_test;
    std::vector<std::string> input_data_neg_test;
    bool saveModel;

public:
    MainClass( int k,int alpha=1, bool saveModel=false);
    MainClass( MarkovModel ai, MarkovModel human);
    void trainModels();
    void readData(std::string filePathPos, std::string filePathNeg
    ,std::string filePathPosTest,std::string filePathNegTest);
    int predict(std::string text, int label);
    void testModels();
    void save_model(const MarkovModel& obj, const char* filename);
    MarkovModel load_model(const char* filename);
};

#endif
