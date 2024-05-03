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

public:
    MainClass( int k,int alpha=1);
    void trainModels();
    void readData(std::string filePathPos, std::string filePathNeg);
    int predict(std::string text, int label);
};

#endif // MARKOV_MODEL_HPP
