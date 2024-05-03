#include "MainClass.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "MainClass.hpp"
using namespace std;


int main() {
    
    int k = 2;
    int alpha = 1;
    string filePath = "data/tiny.csv";
    //provavelmente é boa ideia remover espaços, pontuação e caratéres estranhos
    //vector<pair<string,int>> data = readData(filePath);

    MarkovModel human(k,alpha);
   
    string text = "abcdfgfjkgaskvnlksajhfgaslkvnsjakfpkasnlhak";
    ai.train(text);
    human.train(text);
    std::cout << "AI bits: " << ai.bitsToCompress(text)<< std::endl;
    std::cout << "Human bits: " <<human.bitsToCompress(text) << std::endl;
    //ai.printHashTable();
    //human.printHashTable();
    //falta fazer a parte equivalente ao calculateBits deles e as funções das métricas
    //criar classe para juntar dois modelos e tomar decisoes
    return 0;
}