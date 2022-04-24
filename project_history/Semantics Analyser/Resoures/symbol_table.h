#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class SymbolTableNode {
    public:
        string IDEN;
        int type;
        int scope;

        SymbolTableNode(string iden, int tp, int scp);
};

class SymbolTable {
    private:
        vector<SymbolTableNode> internalSymbolTable;

    public:
        SymbolTable();

        bool functionIDENExists(string IDEN) {
            int n = internalSymbolTable.size();
            for(int i = 0; i < n; i++) {
                if(IDEN.compare(internalSymbolTable[i].IDEN) == 0)
                    return true;
            }
            return false;
        }

        bool IDENExists(string IDEN, int scope) {
            int n = internalSymbolTable.size();
            for(int i = 0; i < n; i++) {
                if(IDEN.compare(internalSymbolTable[i].IDEN) == 0 
                && scope == internalSymbolTable[i].scope)
                    return true;
            }
            return false;
        }

        int addIDEN(string IDEN, int type, int scope) {
            if(IDENExists(IDEN, scope))
                return -1;
            SymbolTableNode stn(IDEN, type, scope);
            internalSymbolTable.push_back(stn);
            return 1;
        }

        void printTable() {
            int n = internalSymbolTable.size();
            cout << "IDENTIFIER\t|\tTYPE\t|\tSCOPE\n";
            cout << "----------------|---------------|-------------\n";
            for(int i = 0; i < n; i++) {
                cout << internalSymbolTable[i].IDEN << "\t|\t"
                    << internalSymbolTable[i].type << "\t|\t"
                    << internalSymbolTable[i].scope << "\n";
            }
        }
};