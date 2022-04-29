#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

bool isOnlyWhiteSpace(string str);
bool isIdentCharacter(char ch);

class Preprocessor {
	private:
		vector<pair<string, string>> macroTable;
        vector<string> fileTextLines;
        string processedText;
        string errorText;
        bool preProcessorError;
        bool exitOnError;
		
		// Open a file in a specific mode
		void openFile(string fileName);
        // Write processed text to a file
        void writeFile(string fileName);
        // Update Macro value if exists or append new one
        void addMacro(string macroIden, string macroVal);
		// Get all macros and values and set it in the macroTable
        void getMacros(string macroLine, int lineno);
        // Replace all macro values in the rest of the program
        void replaceMacros();
        // Print Macros
        void printMacros();
        // Process Text
        void processText();
        // Reset Preprocessor class
        void resetPreProcessor();
		
	public:
		// Preprocessor Constructor
		Preprocessor();
		// Return processed text
        string processFileText(string fileName, string processedFileName);
        // Return macroTable
        vector<pair<string, string>> getMacroTable();
};