#ifndef METRICS_HPP
#define METRICS_HPP
#include <unordered_map>
#include <string>

class Metrics {
private:
    std::unordered_map<std::string, int> confusionMatrix;
public:
    void fillConfusionMatrix(int prediction,int real_value);
    float recall();
    float precision();
    float f_score();
    float accuracy();
};

#endif // MARKOV_MODEL_HPP
