#include "MarkovModel.hpp"
#include "HashTable.hpp"
#include <cmath>
#include <fstream>
using namespace std;

MarkovModel::MarkovModel(int k,int alpha) : k(k),alpha(alpha) {}

void MarkovModel::train(const string& text) {
    if ((k+1)>text.length()) return ;
    for (int i = 0; i <= text.length() - (k+1); ++i) {
        string context = text.substr(i, k);
        char nextChar = text[i + k];
        table.increment(context, nextChar);
    }
}
double MarkovModel::bitsToCompress(const string& text) {
    double sum = 0;
    if ((k+1)>text.length()) return -log2(table.calculateProbability("", '.',alpha));
    for (int i = 0; i <= text.length() - (k+1); ++i) {
        string context = text.substr(i, k);
        char nextChar = text[i + k];
        sum-=log2(table.calculateProbability(context, nextChar,alpha));
    }
    return sum;
}
void MarkovModel::printHashTable() {
    table.printHashTable();
}

int MarkovModel::getK(){
    return k;
}

int MarkovModel::getAlpha(){
    return alpha;
}

HashTable MarkovModel::getTable(){
    return table;
}
void MarkovModel::setTable(HashTable newTable) {
    table = newTable;
}