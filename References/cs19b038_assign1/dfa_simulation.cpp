#include <iostream>
#include <fstream>

#include <chrono>
#include <thread>

#define MAX_CHAR_LENGTH 200

using namespace std;

// to convert a char array to an integer, both negative and positive
int strToInt(char a[MAX_CHAR_LENGTH]);

// Class DFA to simulate DFA table
class DFA {
    public:
        // Constructor
        DFA();
        // Print all the details of the DFA
        void printDFA();

        // Getters and Setters for various data members
        void setNumStates(char a[MAX_CHAR_LENGTH]);
        int getNumberOfStates();
        void setStartingState(char a[MAX_CHAR_LENGTH]);
        void setNumFinalStates(char a[MAX_CHAR_LENGTH]);
        void setFinalStates(char a[MAX_CHAR_LENGTH]);
        void setNumInputSymbols(char a[MAX_CHAR_LENGTH]);
        void setInputSymbols(char a[MAX_CHAR_LENGTH]);
        void setTable(int rowIndex, char a[MAX_CHAR_LENGTH]);

        // Check whether an input symbol is valid for the DFA
        int validInput(char t);
        // Check if a particular state is present in the final states
        bool inFinalStates(int state);
        // Check whether a string is acceptable by the DFA
        bool isInputAcceptable(char str[MAX_CHAR_LENGTH]);

    private:
        int numberOfStates;
        int startingState;
        int numberOfFinalStates;
        int *finalStates;
        int numberOfInputSymbols;
        char *inputSymbols;
        int **table;
};


// =========================================================================================
// =========================================================================================
// DFA CLASS METHOD DEFINITIONS STARTS HERE
// =========================================================================================
// =========================================================================================

// Constructor for the DFA class
DFA::DFA() {
    // File input buffer stream object
    ifstream obj;
    // Opening the input file config.txt
    obj.open("./config.txt", ios::in);
    char *str = new char[MAX_CHAR_LENGTH];


    // Setting the value of Number of States
    obj.getline(str, MAX_CHAR_LENGTH);
    setNumStates(str);

    // Setting the value of Starting State
    obj.getline(str, MAX_CHAR_LENGTH);
    setStartingState(str);

    // Setting the value of Number of Final States
    obj.getline(str, MAX_CHAR_LENGTH);
    setNumFinalStates(str);

    // Setting the value of Final States
    this->finalStates = new int[this->numberOfFinalStates];
    obj.getline(str, MAX_CHAR_LENGTH);
    setFinalStates(str);

    // Setting the value of Number of Input Symbols
    obj.getline(str, MAX_CHAR_LENGTH);
    setNumInputSymbols(str);

    // Setting the value of Input Symbols
    this->inputSymbols = new char[this->numberOfInputSymbols];
    obj.getline(str, MAX_CHAR_LENGTH);
    setInputSymbols(str);

    // Setting the value of DFA table
    this->table = new int *[this->numberOfStates];
    for(int i = 0; i < this->numberOfStates; i++)
        this->table[i] = new int[this->numberOfInputSymbols];

    for(int i = 0; i < this->numberOfStates; i++) {
        obj.getline(str, MAX_CHAR_LENGTH);
        setTable(i, str);
    }


    /* 
        Forcing the thread to sleep as a PREVENTIVE MEASURE 
        in order to complete the above READ process through 
        the ifstream.
        (May not be required in this case.)
    */
    this_thread::sleep_for(chrono::milliseconds(100));

    obj.close();
}

// Print all the details of the DFA
void DFA::printDFA() {
    cout << "Total Number of States: " << this->numberOfStates << endl;
    cout << "Starting State: " << this->startingState << endl;
    cout << "Total Number of Final States: " << this->numberOfFinalStates << endl;
    cout << "Final States: ";
    for(int i = 0; i < this->numberOfFinalStates; i++)
        cout << this->finalStates[i] << " ";
    cout << endl;
    cout << "Total Number of Input Symbols: " << this->numberOfInputSymbols << endl;
    cout << "Input Symbols: ";
    for(int i = 0; i < this->numberOfInputSymbols; i++)
        cout << this->inputSymbols[i] << " ";
    cout << endl;
    cout << "DFA TABLE:" << endl;
    for(int i = 0; i < this->numberOfInputSymbols; i++) {
        cout << i + 1 << ": ";
        for(int j = 0; j < this->numberOfInputSymbols; j++)
            cout << this->table[i][j] << " ";
        cout << endl;
    }
}

// =========================================================================================
// =========================================================================================
// Getters and Setters

void DFA::setNumStates(char a[MAX_CHAR_LENGTH]) {
    this->numberOfStates = strToInt(a);
}

int DFA::getNumberOfStates() {
    return this->numberOfStates;
}

void DFA::setStartingState(char a[MAX_CHAR_LENGTH]) {
    this->startingState = strToInt(a);
}

void DFA::setNumFinalStates(char a[MAX_CHAR_LENGTH]) {
    this->numberOfFinalStates = strToInt(a);
}

void DFA::setFinalStates(char a[MAX_CHAR_LENGTH]) {
    char *temp = new char[MAX_CHAR_LENGTH];
    int index = 0;
    int j = 0;
    for(int i = 0; a[i] != '\0'; i++) {
        if(a[i] == ' ') {
            temp[j] = '\0';
            this->finalStates[index] = strToInt(temp);
            index++;
            j = 0;
        }
        else {
            temp[j] = a[i];
            j++;
        }
    }
    temp[j] = '\0';
    this->finalStates[index] = strToInt(temp);
}

void DFA::setNumInputSymbols(char a[MAX_CHAR_LENGTH]) {
    this->numberOfInputSymbols = strToInt(a);
}

void DFA::setInputSymbols(char a[MAX_CHAR_LENGTH]) {
    int index = 0;
    for(int i = 0; a[i] != '\0'; i++) {
        this->inputSymbols[index] = a[i];
        index++;
        i++;
    }
}

void DFA::setTable(int rowIndex, char a[MAX_CHAR_LENGTH]) {
    char *temp = new char[MAX_CHAR_LENGTH];
    int index = 0;
    int j = 0;
    for(int i = 0; a[i] != '\0'; i++) {
        if(a[i] == ' ') {
            temp[j] = '\0';
            this->table[rowIndex][index] = strToInt(temp);
            index++;
            j = 0;
        }
        else {
            temp[j] = a[i];
            j++;
        }
    }
    temp[j] = '\0';
    this->table[rowIndex][index] = strToInt(temp);
}

// =========================================================================================
// =========================================================================================

// Check whether an input symbol is valid for the DFA
int DFA::validInput(char t) {
    for(int i = 0; i < this->numberOfInputSymbols; i++)
        if(t == this->inputSymbols[i])
            return i;
    return -1;
}

// Check if a particular state is present in the final states
bool DFA::inFinalStates(int state) {
    for(int i = 0; i < this->numberOfFinalStates; i++) {
        if(state == this->finalStates[i])
            return true;
    }
    return false;
}

// Check whether a string is acceptable by the DFA
bool DFA::isInputAcceptable(char str[MAX_CHAR_LENGTH]) {
    int currentState = this->startingState;

    for(int i = 0; str[i] != '\0'; i++) {
        char t = str[i];
        int nextIndex = validInput(t);
        if(nextIndex == -1) {
            // cout << "Invalid Input: " << t << ", hence: ";
            return false;
        }
        else {
            int nextState = this->table[currentState - 1][nextIndex];
            currentState = nextState;
            if(currentState == -1)
                return false;
        }
    }

    if(inFinalStates(currentState))
        return true;
    return false;
}

// =========================================================================================
// =========================================================================================
// DFA CLASS METHOD DEFINITIONS ENDS HERE
// =========================================================================================
// =========================================================================================

int main() {
    // Initialising the DFA class
    DFA dfa = DFA();
    // dfa.printDFA();

    // File input buffer stream object
    ifstream obj;
    // Opening the input file config.txt
    obj.open("./config.txt", ios::in);
    char *str = new char[MAX_CHAR_LENGTH];
    // Getting to the line where the string input starts
    int k = 6 + dfa.getNumberOfStates();
    for(int i = 0; i < k; i++)
        obj.getline(str, MAX_CHAR_LENGTH);

    // Testing all strings in the DFA
    obj.getline(str, MAX_CHAR_LENGTH);
    int numberOfTestStrings = strToInt(str);
    while(numberOfTestStrings > 0) {
        obj.getline(str, MAX_CHAR_LENGTH);

        if(dfa.isInputAcceptable(str))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        numberOfTestStrings--;
    }

    obj.close();

    return 0;
}

int strToInt(char a[MAX_CHAR_LENGTH]) {
    int num = 0;
    int i = 0;
    if(a[0] == '-')
        i = 1;

    while(a[i] != '\0') {
        num *= 10;
        int d = (int) a[i];
        d -= 48;
        num += d;
        i++;
    }
    
    if(a[0] == '-')
        num *= -1;
    
    return num;
}