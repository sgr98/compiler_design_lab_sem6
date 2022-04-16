#include <iostream>
#include <string>
#include "preprocessor.h"

using namespace std;

// g++ sample.cpp preprocessor.cpp -o sample
// FileName: ./exmp/arithmetic.xvgs

int main () {
    string fileName = "./exmp/arithmetic.xvgs";
    string processedFileName = "target.xvgs";

    Preprocessor preprocessor;
    string preProcessedText = preprocessor.processFileText(fileName, processedFileName);

    return 0;
}