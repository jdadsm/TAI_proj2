#include "MainClass.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


int main() {
    int k = 2;
    int alpha = 1;
    MainClass main(k,alpha);

    //provavelmente é boa ideia remover espaços, pontuação e caratéres estranhos
    string filePathPos = "data/tiny_pos.csv";
    string filePathNeg = "data/tiny_neg.csv";
    main.readData(filePathPos,filePathNeg);

    main.trainModels();
   
    string text = "abcdfgfjkgaskvnlksajhfgaslkvnsjakfpkasnlhak";
    
    int predicted_label = main.predict(text,0);
    
    cout << "\nPredicted label: " << predicted_label << endl;
    
    return 0;
}