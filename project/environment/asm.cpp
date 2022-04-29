#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

//Unit of a symbol Table
class SymbolTableNode{
    public:
        string IDEN;
        int type;
        int in_scope;
        int scope;
        int function_scope;
        int function_parameters;
};

//SymbolTable for all identifiers
class SymbolTable{
    
    private: vector<SymbolTableNode> internalSymbolTable;

    public:
            void addIdentifierVariable(char token_array[]){
                SymbolTableNode current_identifier;

                char *token = strtok(token_array,".");
                string IDENT = token;
                current_identifier.IDEN = IDENT.substr(1,IDENT.size()-1);
                token = strtok(NULL,".");
                current_identifier.type = stoi(token);
                token = strtok(NULL,".");
                current_identifier.in_scope = stoi(token);
                token = strtok(NULL,".");
                current_identifier.scope = stoi(token);
                token = strtok(NULL,".");
                current_identifier.function_scope = stoi(token);
                internalSymbolTable.push_back(current_identifier);
            }

            void addIdentiferFunction(char token_array[]){
                SymbolTableNode current_identifier;

                char *token = strtok(token_array,".");
                string IDENT = token;
                current_identifier.IDEN = IDENT.substr(1,IDENT.size()-1);
                token = strtok(NULL,".");
                current_identifier.type = stoi(token);
                token = strtok(NULL,".");
                current_identifier.function_parameters = stoi(token);
                token = strtok(NULL,".");
                current_identifier.function_scope = stoi(token);
                internalSymbolTable.push_back(current_identifier);
            }

            //For Checking if input is correct
            void print_Identifier(){
                for(int i=0; i<internalSymbolTable.size(); i++){
                    cout<<internalSymbolTable[i].IDEN<<".";
                    cout<<internalSymbolTable[i].type<<".";
                    cout<<internalSymbolTable[i].in_scope<<".";
                    cout<<internalSymbolTable[i].scope<<".";
                    cout<<internalSymbolTable[i].function_scope<<endl;
                }
            }

            SymbolTableNode getIdentifierVariable(int i){
                return internalSymbolTable[i];
            }

            SymbolTableNode getIdentifierFunction(int i){
                int index = i + internalSymbolTable.size();
                return internalSymbolTable[index];
            }

            bool checkIdentifier(string IDEN){
                for(int i=0; i<internalSymbolTable.size(); i++){
                    if(internalSymbolTable[i].IDEN == IDEN){
                        return true;
                    }
                }
                return false;
            }
};

class AssemblyInstruction{
        public:
                string temporaryRegisterAssign[9] = {"\0","\0","\0","\0","\0","\0","\0","\0","\0"};
                int number_of_temp_registers = 9;
                bool temporaryRegisterFree[9] = {true,true,true,true,true,true,true,true,true};
                int relationalLabelCount = 1;
                string output;
        public:
                int getTemporaryRegister(string temp_variable){
                    for(int i=0; i<number_of_temp_registers; i++){
                        if(temporaryRegisterFree[i]){
                            temporaryRegisterFree[i]=false;
                            temporaryRegisterAssign[i] = temp_variable;
                            //cout<<endl<<"Temporary Value stored in array:"<<temporaryRegisterAssign[i]<<endl;
                            return i;
                        }
                    }
                    return 0;
                }

                int checkTemporaryRegister(string temp_variable){
                    for(int i=0; i<number_of_temp_registers; i++){
                        if(temporaryRegisterAssign[i]==temp_variable){
                            temporaryRegisterFree[i]=true;
                            temporaryRegisterAssign[i] = "\0";
                            return i;
                        }
                    }
                    return 0;
                }

            void variable_declaration(SymbolTableNode Node){
                string buffer = "\t" + Node.IDEN + ": ";
                switch(Node.type){
                    case 1: buffer = buffer + ".word 0\n";
                            break;
                    case 2: buffer = buffer + ".word 0\n";
                            break;
                    case 3: buffer = buffer + ".byte 0\n";
                            break;
                    case 4: buffer = buffer + ".halfword 0\n";
                            break;
                    default: break;
                }
                 output = output + buffer;
            }
            
            void addInstruction(string line){
                output = output + line;
            }

            void addExpression(string line){
                bool operatorflag = checkOperatorExpression(line);
                bool assignmentflag = checkAssignmentExpression(line);
                bool ioflag = checkIOExpression(line);
                bool relationalflag = checkRelationalExpression(line);
                bool conditionalflag = checkConditionalExpression(line);
                bool loopflag = checkLoopExpression(line);
                bool controlflag = checkControlExpression(line);
                bool labelflag = checkLabelExpression(line);
                bool bitwiseflag = checkBitwiseExpression(line);
                bool functionflag = checkFunctionExpression(line);
                bool mainflag = checkMainExpression(line);
                bool v1flag = checkV1Expression(line);
                if(mainflag){
                    output = output + "main:\n";
                }else if(v1flag){
                    string buffer = createV1Expression(line);
                    output = output + "\t" + buffer + "\n";
                }else if(operatorflag){
                    string buffer = createOperatorExpression(line);
                    output = output + "\t" + buffer + "\n";
                }else if(ioflag){
                    string buffer = createIOExpression(line);
                    output = output + "\t" + buffer + "\n";
                }else if(relationalflag){
                    string buffer = createRelationalExpression(line);
                    output = output + "\t" + buffer + "\n";
                }else if(conditionalflag){
                    string buffer = createConditionalExpression(line);
                    relationalLabelCount++;
                    output = output + "\t" + buffer + "\n";
                }else if(controlflag){
                    string buffer = createControlExpression(line);
                    output = output + "\t" + buffer + "\n";
                }else if(loopflag){
                    string buffer = createLoopExpression(line);
                    output = output + "\t" + buffer + "\n";
                }else if(functionflag){
                    //cout<<"Enterstring"<<endl;
                    string buffer = createFunctionExpression(line);
                    output = output + buffer + "\n";
                }else if(labelflag){
                    string buffer = createLabelExpression(line);
                    output = output + "\t" + buffer + "\n";
                }else if(bitwiseflag){
                    string buffer = createBitwiseExpression(line);
                    output = output + "\t" + buffer +"\n";
                }else if(assignmentflag){
                    string buffer = createAssignmentExpression(line);
                    output = output + "\t" + buffer + "\n";
                }
            }
            bool checkMainExpression(string line){
                if(line.find("main")!=string::npos){
                    return true;
                }
                return false;
            }

            bool checkV1Expression(string line){
                if(line.find("v1")!=string::npos){
                    return true;
                }
                return false;
            }
            bool checkAssignmentExpression(string line){
                if(line.find("=")!=string::npos){
                    return true;
                }
                return false;
            }
            bool checkOperatorExpression(string line){
                if( line.find("+")!=string::npos || (line.find("-")!=string::npos && !(line.find("= -")!=string::npos)) ||
                    line.find("*")!=string::npos || line.find("/")!=string::npos ||
                    line.find("%")!=string::npos ){
                        return true;
                    } 
                    return false;
            }
            bool checkIOExpression(string line){
                if(line.find("@input")!=string::npos||line.find("@output")!=string::npos){
                    return true;
                }
                return false;
            }
            bool checkRelationalExpression(string line){
                if(line.find("<")!=string::npos||line.find("<=")!=string::npos||
                   line.find(">")!=string::npos||line.find(">=")!=string::npos||
                   line.find("==")!=string::npos||line.find("!=")!=string::npos){
                       return true;
                   }
                return false;
            }
            bool checkConditionalExpression(string line){
                if(line.find("@if")!=string::npos){
                    return true;
                }
                return false;
            }

            bool checkLoopExpression(string line){
                if(line.find("LOOP")!=string::npos){
                    return true;
                }
                return false;
            }

            bool checkLabelExpression(string line){
                if(line.find("^")!=string::npos){
                    return true;
                }
                return false;
            }

            bool checkControlExpression(string line){
                if(line.find("JUMP")!=string::npos || line.find("JAL")!=string::npos ||
                   line.find("JR")!=string::npos){
                    //cout<<"Enter"<<endl;
                    return true;
                }
                return false;
            }

            bool checkBitwiseExpression(string line){
                if(line.find("||")!=string::npos || line.find("&&")!=string::npos||
                   line.find("!")!=string::npos){
                       //cout<<"Enter"<<endl;
                    return true;
                }
                return false;
            }

            bool checkFunctionExpression(string line){
                if(line.find("FUNC")!=string::npos){
                    //"<<endl;
                    return true;
                }
                return false;
            }

            string createOperatorExpression(string line){
                int equalpos = line.find("=");
                int operatorpos;
                string address1 = line.substr(0,equalpos-1);
                address1 = removeSpace(address1);
                string address2;
                string address3;
                string instruction;
                if(line.find("+")!=string::npos){
                    operatorpos = line.find("+");
                    address2 = line.substr(equalpos+1,operatorpos-equalpos-1);
                    address2 = removeSpace(address2);
                    address3 = line.substr(operatorpos+1,line.size()-operatorpos+1);
                    address3 = removeSpace(address3);
                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    instruction = "add " + address1 + "," + address2 + "," + address3;
                    return instruction;

                }else if(line.find("-")!=string::npos){
                   operatorpos = line.find("-");
                    address2 = line.substr(equalpos+1,operatorpos-equalpos-1);
                    address2 = removeSpace(address2);
                    address3 = line.substr(operatorpos+1,line.size()-operatorpos+1);
                    address3 = removeSpace(address3);
                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);
                    instruction = "sub " + address1 + "," + address2 + "," + address3;
                    return instruction;
                }else if(line.find("*")!=string::npos){
                    operatorpos = line.find("*");
                    address2 = line.substr(equalpos+1,operatorpos-equalpos-1);
                    address2 = removeSpace(address2);
                    address3 = line.substr(operatorpos+1,line.size()-operatorpos+1);
                    address3 = removeSpace(address3);

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);
                    instruction = "mult " + address2 + "," + address3 + "\n";
                    instruction = instruction + "\tmflo " + address1;
                    return instruction;
                }else if(line.find("/")!=string::npos){
                    operatorpos = line.find("/");
                    address2 = line.substr(equalpos+1,operatorpos-equalpos-1);
                    address2 = removeSpace(address2);
                    address3 = line.substr(operatorpos+1,line.size()-operatorpos+1);
                    address3 = removeSpace(address3);

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);
                    instruction = "div " + address2 + "," + address3 + "\n";
                    instruction = instruction + "\tmflo " + address1;
                    return instruction;
                }else if(line.find("%")!=string::npos){
                    operatorpos = line.find("%");
                    address2 = line.substr(equalpos+1,operatorpos-1);
                    address2 = removeSpace(address2);
                    address3 = line.substr(operatorpos+1,line.size());
                    address3 = removeSpace(address3);

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);
                    instruction = "div " + address2 + "," + address3 + "\n";
                    instruction = instruction + "\tmfhi " + address1;
                    return instruction;
                }

                return "\0";
            }

            string createAssignmentExpression(string line){
                int equalpos = line.find("=");
                string address1 = line.substr(0,equalpos-1);
                address1 = removeSpace(address1);
                string address2 = line.substr(equalpos+1,line.size()-equalpos+1);
                address2 = removeSpace(address2);
                string instruction;
                if(address1.find("$")!=string::npos){
                    int register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    address1 = removedollar(address1);
                    instruction = "sw " + address2 + "," + address1;
                    return instruction;
                }else if(address2.find("$")!=string::npos){
                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    address2 = removedollar(address2);
                    instruction = "lw " + address1 + "," + address2;
                    return instruction;
                }else{
                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    instruction = "li " + address1 + "," + address2;
                    return instruction;
                }
                return "\0";
            }

            string createIOExpression(string line){
                string instruction;
                if(line.find("@input")!=string::npos){
                    int dollarpos = line.find("$");
                    string address1 = line.substr(dollarpos,line.size()-dollarpos);
                    address1 = removedollar(address1);
                    instruction = "li $v0,5\n";
                    instruction = instruction + "\tsyscall\n";
                    instruction = instruction + "\tsw $v0," + address1;
                    //cout<<instruction<<endl; 
                    return instruction;
                }else if(line.find("@output")!=string::npos){
                    int dollarpos = line.find("$");
                    string address1 = line.substr(dollarpos,line.size()-dollarpos);
                    address1 = removedollar(address1);
                    int register1 = getTemporaryRegister("temp");
                    string temporaryRegister = "$t" + to_string(register1);
                    instruction = "li $v0,1\n";
                    instruction = instruction + "\tlw " + temporaryRegister + "," + address1 + "\n";
                    instruction = instruction + "\tmove $a0," + temporaryRegister + "\n";
                    checkAssignmentExpression("temp"); 
                    instruction = instruction + "\tsyscall\n";
                    //cout<<instruction<<endl; 
                    return instruction;
                }
                return "\0";
            }

            string createRelationalExpression(string line){
                string instruction;
                if(line.find("<=")!=string::npos){
                    int equalpos = line.find("=");
                    int relationalpos = line.find("<=");
                    string address1 = line.substr(0,equalpos);
                    //cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(equalpos+1,relationalpos-equalpos-1);
                    address2 = removeSpace(address2);
                    //cout<<endl<<address2<<endl;
                    string address3 = line.substr(relationalpos+2, line.size()-relationalpos+1);
                    address3 = removeSpace(address3);
                    //cout<<endl<<address3<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    instruction = "ble " + address2 + "," + address3 +",L" + to_string(relationalLabelCount) + "\n";
                    instruction = instruction + "\tli " + address1 + ",0\n";
                    instruction = instruction + "\tj L" + to_string(relationalLabelCount+1) + "\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount) + ":\n";
                    instruction = instruction + "\tli " + address1 + ",1\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount+1) + ":\n";
                    checkTemporaryRegister(address1);
                    relationalLabelCount++;
                    //cout<<instruction<<endl;
                    return instruction;
                }else if(line.find(">=")!=string::npos){
                    int equalpos = line.find("=");
                    int relationalpos = line.find(">=");
                    string address1 = line.substr(0,equalpos);
                    //cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(equalpos+1,relationalpos-equalpos-1);
                    address2 = removeSpace(address2);
                    //cout<<endl<<address2<<endl;
                    string address3 = line.substr(relationalpos+2, line.size()-relationalpos+1);
                    address3 = removeSpace(address3);
                    //cout<<endl<<address3<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    instruction = "bge " + address2 + "," + address3 +",L" + to_string(relationalLabelCount) + "\n";
                    instruction = instruction + "\tli " + address1 + ",0\n";
                    instruction = instruction + "\tj L" + to_string(relationalLabelCount+1) + "\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount) + ":\n";
                    instruction = instruction + "\tli " + address1 + ",1\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount+1) + ":\n";
                    checkTemporaryRegister(address1);
                    relationalLabelCount++;
                    //cout<<instruction<<endl;
                    return instruction;
                }else if(line.find("==")!=string::npos){
                    int equalpos = line.find("=");
                    int relationalpos = line.find("==");
                    string address1 = line.substr(0,equalpos);
                    cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(equalpos+1,relationalpos-equalpos-1);
                    address2 = removeSpace(address2);
                    cout<<endl<<address2<<endl;
                    string address3 = line.substr(relationalpos+2, line.size()-relationalpos+1);
                    address3 = removeSpace(address3);
                    cout<<endl<<address3<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    instruction = "beq " + address2 + "," + address3 +",L" + to_string(relationalLabelCount) + "\n";
                    instruction = instruction + "\tli " + address1 + ",0\n";
                    instruction = instruction + "\tj L" + to_string(relationalLabelCount+1) + "\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount) + ":\n";
                    instruction = instruction + "\tli " + address1 + ",1\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount+1) + ":\n";
                    checkTemporaryRegister(address1);
                    relationalLabelCount++;
                    //cout<<instruction<<endl;
                    return instruction;
                }else if(line.find(">")!=string::npos){
                    int equalpos = line.find("=");
                    int relationalpos = line.find(">");
                    string address1 = line.substr(0,equalpos);
                    //cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(equalpos+1,relationalpos-equalpos-1);
                    address2 = removeSpace(address2);
                    //cout<<endl<<address2<<endl;
                    string address3 = line.substr(relationalpos+1, line.size()-relationalpos);
                    address3 = removeSpace(address3);
                    //cout<<endl<<address3<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    instruction = "bgt " + address2 + "," + address3 +",L" + to_string(relationalLabelCount) + "\n";
                    instruction = instruction + "\tli " + address1 + ",0\n";
                    instruction = instruction + "\tj L" + to_string(relationalLabelCount+1) + "\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount) + ":\n";
                    instruction = instruction + "\tli " + address1 + ",1\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount+1) + ":\n";
                    checkTemporaryRegister(address1);
                    relationalLabelCount++;
                    //cout<<instruction<<endl;
                    return instruction;
                }else if(line.find("<")!=string::npos){
                    int equalpos = line.find("=");
                    int relationalpos = line.find("<");
                    string address1 = line.substr(0,equalpos);
                    //cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(equalpos+1,relationalpos-equalpos-1);
                    address2 = removeSpace(address2);
                    //cout<<endl<<address2<<endl;
                    string address3 = line.substr(relationalpos+1, line.size()-relationalpos);
                    address3 = removeSpace(address3);
                    //cout<<endl<<address3<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    instruction = "blt " + address2 + "," + address3 +",L" + to_string(relationalLabelCount) + "\n";
                    instruction = instruction + "\tli " + address1 + ",0\n";
                    instruction = instruction + "\tj L" + to_string(relationalLabelCount+1) + "\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount) + ":\n";
                    instruction = instruction + "\tli " + address1 + ",1\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount+1) + ":\n";
                    checkTemporaryRegister(address1);
                    relationalLabelCount++;
                    //cout<<instruction<<endl;
                    return instruction;
                }else if(line.find("!=")!=string::npos){
                    int equalpos = line.find("=");
                    int relationalpos = line.find("!=");
                    string address1 = line.substr(0,equalpos);
                    //cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(equalpos+1,relationalpos-equalpos-1);
                    address2 = removeSpace(address2);
                    //cout<<endl<<address2<<endl;
                    string address3 = line.substr(relationalpos+2, line.size()-relationalpos);
                    address3 = removeSpace(address3);
                    //cout<<endl<<address3<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    instruction = "bne " + address2 + "," + address3 +",L" + to_string(relationalLabelCount) + "\n";
                    instruction = instruction + "\tli " + address1 + ",0\n";
                    instruction = instruction + "\tj L" + to_string(relationalLabelCount+1) + "\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount) + ":\n";
                    instruction = instruction + "\tli " + address1 + ",1\n";
                    instruction = instruction + "\tL" + to_string(relationalLabelCount+1) + ":\n";
                    checkTemporaryRegister(address1);
                    relationalLabelCount++;
                    //cout<<instruction<<endl;
                    return instruction;
                }
                return "\0";
            }

            string createConditionalExpression(string line){
                string instruction;
                int equalpos = line.find("=");
                int arrowpos = line.find("^");
                string address1 = line.substr(equalpos+1,arrowpos-equalpos-1);
                address1 = removeSpace(address1);
                string address2 = line.substr(arrowpos+1,line.size()-arrowpos);
                address2 = removeSpace(address2);
                
                int register1 = checkTemporaryRegister(address1);
                address1 = "$t" + to_string(register1);
                instruction = "ble " + address1 + ",$zero," + address2;
                //cout<<instruction<<endl;
                return instruction;
            }

            string createLabelExpression(string line){
                string instruction = line;
                int arrowpos = line.find("^");
                instruction = instruction.substr(arrowpos+1,instruction.size()-arrowpos);
                instruction = removeSpace(instruction);
                return instruction;
            }

            string createLoopExpression(string line){
                string instruction=line;
                int arrowpos = line.find("^");
                instruction = instruction.substr(arrowpos+1,instruction.size()-arrowpos);
                instruction = removeSpace(instruction);
                return instruction;
            }

            string createControlExpression(string line){
                string instruction = line;
                if(line.find("JUMP")!=string::npos){
                    int arrowpos = instruction.find("^");
                    instruction = instruction.substr(arrowpos+1,instruction.size()-arrowpos);
                    instruction = removeSpace(instruction);
                    instruction = "\tj " + instruction + "\n";
                    //cout<<instruction<<endl;
                    return instruction;
                }else if(line.find("JAL")!=string::npos){
                    int arrowpos = instruction.find("^");
                    instruction = instruction.substr(arrowpos+1,instruction.size()-arrowpos);
                    instruction = removeSpace(instruction);
                    instruction = "jal " + instruction;
                    cout<<instruction<<endl;
                    return instruction;
                }else if(line.find("JR")!=string::npos){
                    string instruction = "jr $ra";
                    return instruction;
                }
                return "\0";
            }

            string createFunctionExpression(string line){
                string instruction = line;
                int arrowpos = line.find("^");
                instruction = instruction.substr(arrowpos+1,instruction.size()-arrowpos);
                instruction = removeSpace(instruction);
                //cout<<instruction<<endl;
                return instruction;
            }

            string createBitwiseExpression(string line){
                if(line.find("&&")!=string::npos){
                    int equalpos = line.find("=");
                    int relationalpos = line.find("&&");
                    string address1 = line.substr(0,equalpos);
                    //cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(equalpos+1,relationalpos-equalpos-1);
                    address2 = removeSpace(address2);
                    //cout<<endl<<address2<<endl;
                    string address3 = line.substr(relationalpos+2, line.size()-relationalpos);
                    address3 = removeSpace(address3);
                    //cout<<endl<<address3<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    string instruction = "and " + address1 + "," + address2 + "," +address3;
                    //cout<<instruction<<endl;
                    return instruction;
                }else if(line.find("||")!=string::npos){
                    int equalpos = line.find("=");
                    int relationalpos = line.find("||");
                    string address1 = line.substr(0,equalpos);
                    //cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(equalpos+1,relationalpos-equalpos-1);
                    address2 = removeSpace(address2);
                    //cout<<endl<<address2<<endl;
                    string address3 = line.substr(relationalpos+2, line.size()-relationalpos);
                    address3 = removeSpace(address3);
                    //cout<<endl<<address3<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address3);
                    address3 = "$t" + to_string(register1);

                    string instruction = "or " + address1 + "," + address2 + "," +address3;
                    //cout<<instruction<<endl;
                    return instruction;
                }else if(line.find("!")!=string::npos){
                    //cout<<"Entercreate"<<endl;
                    int equalpos = line.find("=");
                    int relationalpos = line.find("!");
                    string address1 = line.substr(0,equalpos);
                    //cout<<endl<<address1<<endl;
                    address1 = removeSpace(address1);
                    
                    string address2 = line.substr(relationalpos+1,line.size() - relationalpos);
                    address2 = removeSpace(address2);
                    //cout<<endl<<address2<<endl;

                    int register1 = getTemporaryRegister(address1);
                    address1 = "$t" + to_string(register1);
                    register1 = checkTemporaryRegister(address2);
                    address2 = "$t" + to_string(register1);


                    string instruction = "not " + address1 + "," + address2;
                    //cout<<instruction<<endl;
                    return instruction;
                }
                return "\0";
            }

            string createV1Expression(string line){
                int equalpos = line.find("=");
                string instruction;
                //cout<<line<<endl;
                string address1 = line.substr(0,equalpos-1);
                address1 = removeSpace(address1);
                string address2 = line.substr(equalpos+1,line.size()-equalpos);
                address2 = removeSpace(address2);
                //cout<<address1<<" "<<address2<<endl;
                if(address1.find("v1")!=string::npos){
                    int register1 = checkTemporaryRegister(address2);
                    instruction = "move $v1,$t" + to_string(register1);
                    //cout<<"address1:"<<instruction<<endl;
                    return instruction;
                }else if(address2.find("v1")!=string::npos){
                    int register1 = getTemporaryRegister(address1);
                    instruction = "move $t" + to_string(register1) + ",$v1";
                    //cout<<"address2:"<<instruction<<endl;
                    return instruction;
                }
                return "\0";
            }
            string removeSpace(string buffer){
                char str[100];
                strcpy(str,buffer.c_str());
                int count = 0;
                for (int i = 0; str[i]; i++)
                     if (str[i] != ' ')
                        str[count++] = str[i];
                str[count] = '\0';

                return str;
            }
            
            string removedollar(string buffer){
                char str[100];
                strcpy(str,buffer.c_str());
                int count = 0;
                for (int i = 0; str[i]; i++)
                     if (str[i] != '$')
                        str[count++] = str[i];
                str[count] = '\0';

                return str;
            }

            string get_output(){
                return output;
            }
};
string variable_declaration(SymbolTableNode);

int main(){
    ifstream fin;                                           //This is for the input class
    string line_buffer;                                     //Stores each line in the file
    SymbolTable Symbol_Table;
    AssemblyInstruction Assembly_output;
    fin.open("file.tac");
    getline(fin,line_buffer);
    int number_of_variables = stoi(line_buffer);

    for(int i = 0; i<number_of_variables; i++){
        getline(fin,line_buffer);
        char token_array[100];
        strcpy(token_array,line_buffer.c_str());

        Symbol_Table.addIdentifierVariable(token_array);
    }

    getline(fin,line_buffer);
    int number_of_functions = stoi(line_buffer);

    for(int i =0 ; i < number_of_functions;i++){
        getline(fin,line_buffer);
        char token_array[100];
        strcpy(token_array,line_buffer.c_str());

        Symbol_Table.addIdentiferFunction(token_array);
    }
    Assembly_output.addInstruction(".data\n");
    for(int i=0; i<number_of_variables;i++){
        SymbolTableNode Node = Symbol_Table.getIdentifierVariable(i);
        Assembly_output.variable_declaration(Node);
    }
    Assembly_output.addInstruction(".text\n.globl main\n\tj main\n");

    while(fin){
        if(line_buffer=="\0")
            break;
        getline(fin,line_buffer);
        //cout<<line_buffer;
        Assembly_output.addExpression(line_buffer);
    }

    Assembly_output.addInstruction("\tli $v0,10\n\tsyscall");

    string output = Assembly_output.get_output();

    // cout<<output;
    fin.close();

    ofstream fout;
    fout.open("file.asm");

    fout<<output;
}
