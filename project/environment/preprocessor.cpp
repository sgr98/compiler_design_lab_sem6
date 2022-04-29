#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include "preprocessor.h"

using namespace std;

bool isOnlyWhiteSpace(string str) {
    int len = str.length();
    for(int i = 0; i < len; i++)
        if(!(str[i] == ' ' || str[i] == '\t'))
            return false;
    return true;
}

bool isIdentCharacter(char ch) {
    if( (ch >= 48 && ch <= 57) || 
        (ch >= 65 && ch <= 90) ||
        (ch >= 97 && ch <= 122) ||
        (ch == 95))
        return true;
    return false;
}
		
void Preprocessor::openFile(string fileName) {
    string line;
    ifstream myfile(fileName);

    if (myfile.is_open()) {
        while(getline(myfile, line))
            fileTextLines.push_back(line);
        myfile.close();
    }
    else {
        errorText = "\nERROR CODE(01001): Error while Preprocessing, error opening file " + fileName 
        + ". Check whether file name/path entered is correct.";
        preProcessorError = true;
        exitOnError = true;
    }
}

void Preprocessor::writeFile(string fileName) {
    string line;
    ofstream myfile(fileName);

    if (myfile.is_open()) {
        myfile << processedText;
        myfile.close();
    }
    else {
        errorText = "\nERROR CODE(01002): Error while Preprocessing, error writing or creating file "
        + fileName;
        preProcessorError = true;
        exitOnError = true;
    }
} 

void Preprocessor::addMacro(string macroIden, string macroVal) {
    int n = macroTable.size();
    int in = -1;
    for(int i = 0; i < n; i++) {
        if(macroIden.compare(macroTable[i].first) == 0) {
            macroTable[i].second = macroVal;
            return;
        }
    }
    pair<string, string> macro;
    macro.first = macroIden;
    macro.second = macroVal;
    macroTable.push_back(macro);
}

void Preprocessor::getMacros(string macroLine, int lineno) {
    string macroName = "";
    string macroVal = "";

    int len = macroLine.length();
    int i = 3;

    while(i < len && (macroLine[i] == ' ' || macroLine[i] == '\t'))
        i++;
    if(i >= len) {
        preProcessorError = true;
        errorText += "\nERROR CODE(01004): Preprocessing error. Neither identifier nor value provided for the macro at line "
            + to_string(lineno) + ".";
        return;
    }
    while(i < len && !(macroLine[i] == ' ' || macroLine[i] == '\t')) {
        if(isIdentCharacter(macroLine[i]))
            macroName += macroLine[i];
        else {
            preProcessorError = true;
            errorText += "\nERROR CODE(01005): Preprocessing error. Invalid character used for macro at line "
                + to_string(lineno) + ".";
            return;
        }
        i++;
    }

    while(i < len && (macroLine[i] == ' ' || macroLine[i] == '\t'))
        i++;
    if(i >= len) {
        preProcessorError = true;
        errorText += "\nERROR CODE(01006): Preprocessing error. No value provided for the macro "
            + macroName + " at line " + to_string(lineno) + ".";
        return;
    }
    while(i < len && !(macroLine[i] == ' ' || macroLine[i] == '\t')) {
        macroVal += macroLine[i];
        i++;
    }
    
    addMacro(macroName, macroVal);
}

void Preprocessor::replaceMacros() {
    int size = macroTable.size();
    for(int i = 0; i < size; i++) {
        string macroIden = macroTable[i].first;
        string macroVal = macroTable[i].second;
        while(processedText.find(macroIden) < processedText.length()) {
            processedText.replace(processedText.find(macroIden), macroIden.length(), macroVal);
        }
    }
}

void Preprocessor::printMacros() {
    int n = macroTable.size();
    cout << "MACRO\t\t\t|\tVALUE\n";
    for(int i = 0; i < n; i++)
        cout << "==" << macroTable[i].first << "==" << "\t\t\t|\t" << "==" << macroTable[i].second << "==" << endl;
}

void Preprocessor::processText() {
    bool inQuotes = false;
    bool blockComment = false;
    int n = fileTextLines.size();
    for(int i = 0; i < n; i++) {
        string processedLine = "";
        int j = 0;
        int len = fileTextLines[i].length();
        if(fileTextLines[i][0] == '#' && fileTextLines[i][1] == '#' && fileTextLines[i][2] == '#') {
            getMacros(fileTextLines[i], i + 1);
            continue;
        }
        else if(fileTextLines[i][0] == '#' && fileTextLines[i][1] == '#') {
            preProcessorError = true;
            errorText += "\nERROR CODE(01003): Preprocessing error. Incomplete number of # provided at line "
            + to_string(i + 1) + ". Three hashes: ### are requied to define a macro.";
        }
        else if(fileTextLines[i][0] == '#') {
            preProcessorError = true;
            errorText += "\nERROR CODE(01003): Preprocessing error. Incomplete number of # provided at line "
            + to_string(i + 1) + ". Three hashes: ### are requied to define a macro.";
        }
        while(j < len) {
            if(!inQuotes) {
                if(!blockComment) {
                    if(fileTextLines[i][j] == '"') {
                        inQuotes = true;
                        continue;
                    }
                    if(j == len - 1) {
                        processedLine += fileTextLines[i][j];
                        break;
                    }
                    if(fileTextLines[i][j] == '/' && fileTextLines[i][j + 1] == '/') {
                        break;
                    }
                    else if(fileTextLines[i][j] == '/' && fileTextLines[i][j + 1] == '*') {
                        blockComment = true;
                    }
                    else {
                        processedLine += fileTextLines[i][j];
                    }
                }
                else {
                    if(j == len - 1) {
                        break;
                    }
                    if(fileTextLines[i][j] == '*' && fileTextLines[i][j + 1] == '/') {
                        blockComment = false;
                        j++;
                    }
                }
            }
            else {
                processedLine += fileTextLines[i][j];
                if(fileTextLines[i][j] == '"')
                    inQuotes = false;
            }
            j++;
        }
        if(!isOnlyWhiteSpace(processedLine))
            processedText += (processedLine + "\n");
    }
}

void Preprocessor::resetPreProcessor() {
    macroTable.clear();
    fileTextLines.clear();
    processedText = "";
    errorText = "";
    preProcessorError = false;
    exitOnError = false;
}

// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////

Preprocessor::Preprocessor() {
    resetPreProcessor();
}

string Preprocessor::processFileText(string fileName, string processedFileName) {
    openFile(fileName);
    if(exitOnError) {
        cout << errorText << "\n\n";
        return errorText;
    }
    processText();
    if(!preProcessorError) {
        replaceMacros();
        writeFile(processedFileName);
    }
    if(exitOnError) {
        cout << errorText << "\n\n";
        return errorText;
    }
    // printMacros();
    if(preProcessorError) {
        cout << errorText << "\n\n";
        return errorText;
    }
    resetPreProcessor();
    return processedText;
}

vector<pair<string, string>> Preprocessor::getMacroTable() {
    return macroTable;
}
