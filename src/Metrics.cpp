#include "Metrics.hpp"
#include <iostream> 
#include <iomanip>
void Metrics::fillConfusionMatrix(int pred_label,int label){
    if(pred_label== 1 && label==1){
        confusionMatrix["true_positive"]++;
    }else if(pred_label== 0 && label==1){
        confusionMatrix["false_negative"]++;
    }else if(pred_label== 0 && label==0){
        confusionMatrix["true_negative"]++;
    }else{
        confusionMatrix["false_positive"]++;
    }
}

float Metrics::recall() {
    return confusionMatrix["true_positive"] / (confusionMatrix["true_positive"]+ confusionMatrix["false_negative"]);
}

float Metrics::precision() {
    return confusionMatrix["true_positive"] / (confusionMatrix["true_positive"] + confusionMatrix["false_positive"]);
}

float Metrics::f_score() {
    return 2* precision() * recall() / (precision() + recall());
}

float Metrics::accuracy() {
    float total_predictions = confusionMatrix["true_positive"] + confusionMatrix["false_negative"] + confusionMatrix["true_negative"] + confusionMatrix["false_positive"];
    float correct_predictions = confusionMatrix["true_positive"] + confusionMatrix["true_negative"];
    return correct_predictions / total_predictions;
}

void Metrics::printConfusionMatrix() {
    std::cout << "Confusion Matrix:\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "                           Predicted\n";
    std::cout << "                  |   Positive    |   Negative   |\n";
    std::cout << "Actual | Positive |" << std::setw(8) << confusionMatrix["true_positive"] << std::setw(8)<< "|" << std::setw(8) << confusionMatrix["false_negative"] << std::setw(8) << "|\n";
    std::cout << "       | Negative |" << std::setw(8) << confusionMatrix["false_positive"] << std::setw(8)<< "|" << std::setw(8) << confusionMatrix["true_negative"] << std::setw(8) << "|\n";
    std::cout << "---------------------------------------------\n";
}