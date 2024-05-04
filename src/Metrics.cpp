#include "Metrics.hpp"
#include <iostream> 
#include <iomanip>

using namespace std;

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
    return static_cast<float> (confusionMatrix["true_positive"]) / (confusionMatrix["true_positive"] + confusionMatrix["false_negative"]);
}

float Metrics::precision() {
    return static_cast<float> (confusionMatrix["true_positive"]) / (confusionMatrix["true_positive"] + confusionMatrix["false_positive"]);
}

float Metrics::f_score() {
    return (2 * precision() * recall()) / (precision() + recall());
}

float Metrics::accuracy() {
    float total_predictions = confusionMatrix["true_positive"] + confusionMatrix["false_negative"] + confusionMatrix["true_negative"] + confusionMatrix["false_positive"];
    float correct_predictions = confusionMatrix["true_positive"] + confusionMatrix["true_negative"];
    return correct_predictions / total_predictions;
}

void Metrics::printConfusionMatrix() {
    cout << "Confusion Matrix:\n";
    cout << "---------------------------------------------\n";
    cout << "                           Predicted\n";
    cout << "                  |   Positive    |   Negative   |\n";
    cout << "Actual | Positive |" << setw(8) << confusionMatrix["true_positive"] << setw(8)<< "|" << setw(8) << confusionMatrix["false_negative"] << setw(8) << "|\n";
    cout << "       | Negative |" << setw(8) << confusionMatrix["false_positive"] << setw(8)<< "|" << setw(8) << confusionMatrix["true_negative"] << setw(8) << "|\n";
    cout << "---------------------------------------------\n";
}