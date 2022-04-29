#include <iostream>
#include <string>
#include "preprocessor.h"

using namespace std;

// g++ sample.cpp preprocessor.cpp -o sample
// FileName: ./exmp/arithmetic.xvgs
// error_arithmetic_1.xvgs

int main(int argc, char *argv[]) {
    string fileName = "file.xvgs";
    string processedFileName = "target.xvgs";

    if(argc > 2) {
        fileName = string(argv[1]);
        processedFileName = string(argv[2]);
    }
    else if(argc > 1) {
        fileName = string(argv[1]);
    }

    Preprocessor preprocessor;
    string preProcessedText = preprocessor.processFileText(fileName, processedFileName);

    return 0;
}