#ifndef METRICS_HPP
#define METRICS_HPP

#include <unordered_map>
#include <string>

using namespace std;

class Metrics {
private:
    unordered_map<string, int> confusionMatrix;
public:
    void fillConfusionMatrix(int prediction,int real_value);
    float recall();
    float precision();
    float f_score();
    float accuracy();
    void printConfusionMatrix();
};

#endif
