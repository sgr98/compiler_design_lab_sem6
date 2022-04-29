%{
	#include <fstream>
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include <vector>
	#include <stack>
	#include <fstream>

	using namespace std;

	extern FILE *yyin;

	extern "C"
	{
		// int yyparse(void);
		int yylex();
		void yyerror(const char* s) {
			fprintf (stderr, "%s\n", s);
			// exit(EXIT_SUCCESS);
		}
		int yywrap() {
			return 1;
		}
	}

	// DEBUG CODE 
	int DEBUG_CODE = -1;

	// THREE ADDRESS CODE
	string TAC = "";

	// IMPORTANT GLOBAL VARIABLES
	int DATA_TYPE = 0;
	int SCOPE = 0;
	stack<int> currentScope;
	int FUNCTION = 1;
	int NARGS = 0;
	int ERROR = 0;
	int CURRENT_TAC_INDEX = 1;
	stack<pair<int, int>> currentTAC;	// first = tac_index, second = tac_data_type
	int LABEL = 1;
	stack<int> currentLabel;
	int END_LABEL = 1;
	stack<int> currentEndLabel;
	int LOOP_LABEL = 1;
	stack<int> currentLoopLabel;
	bool isIF = true;

	// SYMBOL TABLE
	class SymbolTableNode {
		public:
			string IDEN;
			int type;
			int scopeIn;
			int scope;
			int fIndex;

			SymbolTableNode(string iden, int tp, int scpIn, int scp, int fInd) {
				IDEN = iden;
				type = tp;
				scopeIn = scpIn;
				scope = scp;
				fIndex = fInd;
			}
	};

	class FunctionTableNode {
		public:
			string IDEN;
			int returnType;
			int nArgs;
			int fnIndex;

			FunctionTableNode(string iden, int rtp, int nargs, int fInd) {
				IDEN = iden;
				returnType = rtp;
				nArgs = nargs;
				fnIndex = fInd;
			}
	};

	class SymbolTable {
		private:
			vector<SymbolTableNode> internalSymbolTable;
			vector<FunctionTableNode> internalFunctionTable;

		public:
			SymbolTable() {

			}

			vector<SymbolTableNode> getSymbolTable() {
				return internalSymbolTable;
			}

			vector<FunctionTableNode> getFunctionTable() {
				return internalFunctionTable;
			}

			int getArgs(int fInd) {
				return internalFunctionTable[fInd - 1].nArgs;
			}

			int getReturnType(int fInd) {
				return internalFunctionTable[fInd - 1].returnType;
			}

			vector<SymbolTableNode> getFunctionTable(int fInd) {
				int nargs = getArgs(fInd);
				int k = 0;

				vector<SymbolTableNode> fVar;
				int n = internalSymbolTable.size();
				for(int i = 0; i < n; i++) {
					if(k >= nargs)
						break;
					if(fInd == internalSymbolTable[i].fIndex) {
						string iden = internalSymbolTable[i].IDEN + "_" + to_string(i);
						SymbolTableNode stn(iden, internalSymbolTable[i].type, internalSymbolTable[i].scopeIn, internalSymbolTable[i].scope, internalSymbolTable[i].fIndex);
						fVar.push_back(stn);
						k++;
					}
				}
				return fVar;
			}

			int getFIndex(string IDEN) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return i + 1;
				}
				return -1;
			}

			int functionIDENExists(string IDEN) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return -2;
				}
				
				n = internalSymbolTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalSymbolTable[i].IDEN) == 0)
						return -1;
				}
				return 1;
			}

			int IDENExists(string IDEN, int scopeIn) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return -2;
				}

				n = internalSymbolTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalSymbolTable[i].IDEN) == 0 
					&& scopeIn == internalSymbolTable[i].scopeIn)
						return -1;
				}
				return 1;
			}

			int addIDEN(string IDEN, int type, int scopeIn, int scope, int fIndex, bool isFun) {
				if(isFun) {
					// type: return type
					// scope: nargs
					int m = functionIDENExists(IDEN);
					if(m < 0)
						return m;
					FunctionTableNode ftn(IDEN, type, scope, fIndex);
					internalFunctionTable.push_back(ftn);
					return 1;
				}
				else {
					int m = IDENExists(IDEN, scopeIn);
					if(m < 0)
						return m;
					SymbolTableNode stn(IDEN, type, scopeIn, scope, fIndex);
					internalSymbolTable.push_back(stn);
					return 1;
				}
			}

			void printTable() {
				int n = internalSymbolTable.size();
				cout << "\nSYMBOL TABLE\n";
				cout << "IDEN\t| TYPE\t| SCPIN\t| SCOPE\t| FINDEX\n";
				cout << "--------|-------|-------|-------|--------\n";
				for(int i = 0; i < n; i++) {
					cout << internalSymbolTable[i].IDEN << "\t| "
						<< internalSymbolTable[i].type << "\t| "
						<< internalSymbolTable[i].scopeIn << "\t| "
						<< internalSymbolTable[i].scope << "\t| "
						<< internalSymbolTable[i].fIndex << "\n";
				}

				n = internalFunctionTable.size();
				cout << "\nFUNCTION TABLE\n";
				cout << "IDEN\t| RTYPE\t| NARGS\t| FINDEX\n";
				cout << "--------|-------|-------|--------\n";
				for(int i = 0; i < n; i++) {
					cout << internalFunctionTable[i].IDEN << "\t| "
						<< internalFunctionTable[i].returnType << "\t| "
						<< internalFunctionTable[i].nArgs << "\t| "
						<< internalFunctionTable[i].fnIndex << "\n";
				}
			}

			int idenDeclared(string IDEN, int scope, int fIndex) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return -2;
				}

				n = internalSymbolTable.size();
				for(int i = n - 1; i >= 0; i--) {
					if(fIndex == internalSymbolTable[i].fIndex
					&& IDEN.compare(internalSymbolTable[i].IDEN) == 0
					&& scope >= internalSymbolTable[i].scope)
						return i;
				}
				return -1;
			}

			int getVarDataType(int in) {
				return internalSymbolTable[in].type;
			}

			int getSymbolTableSize() {
				return internalSymbolTable.size();
			}
	};
	SymbolTable symbolTable;

	// FUNCTION DECLARATIONS
	string constructTACHeader();
	void input_output_TAC(int ind, string iden);
	void assignValToTAC(int typ, string val, int dtype);
	string getBinaryOperator(int op);
	void binaryTAC_expression(int op);
	void assign_expression_TAC(int ind, string iden, int type);
	void generateTACFile(string fileName);
	void conditional_expression_TAC(int type);
	void functional_expression_TAC(int type, string IDEN);
	void return_expression_TAC(int fIndex);
	void printTAC(pair<int, int> temptac);

	// ERROR FUNCTIONS
	void IDENAlreadyExistsError(int m, int errNo);
	void expressionErrors(int errNo);
%}

%start program_start
%union {char *str; int type;}

%token MAIN VOID RETURN INT FLOAT CHAR BOOLEAN
%token IF ELIF ELSE LOOP BREAK CONTINUE
%token INPUT OUTPUT
%token <str> IDENTIFIER BOOLEAN_LIT FLOAT_LIT INT_LIT CHAR_LIT
%token SEMICOLON COMMA LP RP LC RC
%token ADD_ASSIGN_OP SUB_ASSIGN_OP MUL_ASSIGN_OP DIV_ASSIGN_OP REM_ASSIGN_OP
%token EQUAL_OP NOT_EQUAL_OP MRTE LSTE MRT LST
%token LOGICAL_AND_OP LOGICAL_OR_OP EXCLAMATION_OP
%token ASSIGN_OP ADD_OP SUB_OP MUL_OP DIV_OP REM_OP

%%

program_start:  program
				{
					if(ERROR > 0) {
						cout << "\n~~~~~~~~ERROR OCCURED~~~~~~~~\n";	
					}
					else if(ERROR == 0) {
						symbolTable.printTable();
						TAC = constructTACHeader() + TAC;
						generateTACFile("file");
					}
					
					if(DEBUG_CODE == 1)
						printf("program_start\n");
				}
            	;

program:	main_term block
			{
				
				if(DEBUG_CODE == 1)
					printf("program 1\n");
			}

        |	functions main_term block
			{
				
				if(DEBUG_CODE == 1)
					printf("program 2\n");
			}
        ;

main_term:		MAIN
				{
					FUNCTION = 0;
					int m = symbolTable.addIDEN("main", -1, -1, -1, FUNCTION, true);
					if(m < 0) {
						ERROR = 1;
						const char *s = "\nERROR CODE(02200): FUNCTION Identifier with this value already exists";
						yyerror(s);
					}

					TAC += "^ main:\n";

					if(DEBUG_CODE == 1)
						printf("main_term\n");
				}
			;

functions:		function_declaration
				{
					
					if(DEBUG_CODE == 1)
						printf("functions 1\n");
				}

			|	functions function_declaration
				{
					
					if(DEBUG_CODE == 1)
						printf("functions 2\n");
				}
            ;

function_declaration:	VOID IDENTIFIER left_paran right_paran block
						{
							FUNCTION++;
							int m = symbolTable.addIDEN(string($2), 0, -1, 0, FUNCTION -1, true);
							if(m < 0) {
								IDENAlreadyExistsError(m, 1);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 1\n");
						}

					|	VOID IDENTIFIER left_paran params right_paran block
						{
							FUNCTION++;
							int m = symbolTable.addIDEN(string($2), 0, -1, NARGS, FUNCTION - 1, true);
							if(m < 0) {
								IDENAlreadyExistsError(m, 2);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 2\n");
						}

					|	data_type IDENTIFIER left_paran right_paran block
						{
							FUNCTION++;
							int m = symbolTable.addIDEN(string($2), DATA_TYPE, -1, 0, FUNCTION - 1, true);
							if(m < 0) {
								IDENAlreadyExistsError(m, 3);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 3\n");
						}

					|	data_type IDENTIFIER left_paran params right_paran block
						{
							FUNCTION++;
							int m = symbolTable.addIDEN(string($2), DATA_TYPE, -1, NARGS, FUNCTION - 1, true);
							if(m < 0) {
								IDENAlreadyExistsError(m, 4);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 4\n");
						}
                    ;

params:		param
			{
				NARGS++;

				if(DEBUG_CODE == 1)
					printf("params 2\n");
			}

		|	params COMMA param
			{
				NARGS++;

				if(DEBUG_CODE == 1)
					printf("params 2\n");
			}
		;

param:		data_type IDENTIFIER
			{
				int m = symbolTable.addIDEN(string($2), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
				if(m < 0) {
					IDENAlreadyExistsError(m, 5);
				}
				
				if(DEBUG_CODE == 1)
					printf("param \n");
			}
    	;

block:		left_curl right_curl
			{
				
				if(DEBUG_CODE == 1)
					printf("block 1\n");
			}

        |   left_curl statement_list right_curl
			{
				
				if(DEBUG_CODE == 1)
					printf("block 2\n");
			}
        ;

statement_list:		statement
					{
						
						if(DEBUG_CODE == 1)
							printf("statement_list 1\n");
					}

				|	statement_list statement
					{
						
						if(DEBUG_CODE == 1)
							printf("statement_list 2\n");
					}
            	;

statement:		variable_declaration SEMICOLON
				{
					
					if(DEBUG_CODE == 1)
						printf("statement 1\n");
				}

			|	expression SEMICOLON
				{
					
					if(DEBUG_CODE == 1)
						printf("statement 2\n");
				}

			|	conditional_statement
				{
					
					if(DEBUG_CODE == 1)
						printf("statement 3\n");
				}

			|	loop_statement
				{
					
					if(DEBUG_CODE == 1)
						printf("statement 4\n");
				}

			|	return_statement SEMICOLON
				{
					
					if(DEBUG_CODE == 1)
						printf("statement 5\n");
				}

			|	input_output_statement SEMICOLON
				{
					
					if(DEBUG_CODE == 1)
						printf("statement 6\n");
				}

			|	SEMICOLON
				{
					
					if(DEBUG_CODE == 1)
						printf("statement 7\n");
				}
            ;

variable_declaration:	data_type variable_list
						{
							
							if(DEBUG_CODE == 1)
								printf("variable_declaration \n");
						}
                    ;

variable_list:		IDENTIFIER
					{
						int m = symbolTable.addIDEN(string($1), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
						if(m < 0) {
							IDENAlreadyExistsError(m, 6);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 1 ");
					}

				|	IDENTIFIER ASSIGN_OP op_or_expression
					{
						string iden = string($1);
						int m = symbolTable.addIDEN(iden, DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
						if(m < 0) {
							IDENAlreadyExistsError(m, 7);
						}
						else {
							iden += "_" + to_string(symbolTable.getSymbolTableSize() - 1);
							assign_expression_TAC(1, iden, DATA_TYPE);
						}
							
						
						if(DEBUG_CODE == 1)
							printf("variable_list 2 ");
					}

				|	variable_list COMMA IDENTIFIER
					{
						int m = symbolTable.addIDEN(string($3), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
						if(m < 0) {
							IDENAlreadyExistsError(m, 8);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 3 ");
					}

				|	variable_list COMMA IDENTIFIER ASSIGN_OP op_or_expression
					{
						string iden = string($3);
						int m = symbolTable.addIDEN(iden, DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
						if(m < 0) {
							IDENAlreadyExistsError(m, 9);
						}
						else {
							iden += "_" + to_string(symbolTable.getSymbolTableSize() - 1);
							assign_expression_TAC(1, iden, DATA_TYPE);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 4 ");
					}
				;

expression:		assign_expression
				{
					
					if(DEBUG_CODE == 1)
						printf("expression 1 ");
				}

			|	op_or_expression
				{
					
					if(DEBUG_CODE == 1)
						printf("expression 2 ");
				}
            ;

assign_expression:		IDENTIFIER ASSIGN_OP op_or_expression
						{
							string iden = string($1);
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(1, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 1 ");
						}

					|	IDENTIFIER ADD_ASSIGN_OP op_or_expression
						{
							string iden = string($1);
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(2, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 2 ");
						}

					|	IDENTIFIER SUB_ASSIGN_OP op_or_expression
						{
							string iden = string($1);
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(3, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 3 ");
						}

					|	IDENTIFIER MUL_ASSIGN_OP op_or_expression
						{
							string iden = string($1);
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(4, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 4 ");
						}

					|	IDENTIFIER DIV_ASSIGN_OP op_or_expression
						{
							string iden = string($1);
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(5, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 5 ");
						}

					|	IDENTIFIER REM_ASSIGN_OP op_or_expression
						{
							string iden = string($1);
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(6, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 6 ");
						}
                    ;

op_or_expression:   op_and_expression
                    {
                        
						if(DEBUG_CODE == 1)
							printf("op_or_expression 1 ");
                    }

                |	op_or_expression LOGICAL_OR_OP op_and_expression
                    {
						binaryTAC_expression(1);
                        
						if(DEBUG_CODE == 1)
							printf("op_or_expression 2 ");
                    }
                ;

op_and_expression:      op_rel_expression
                        {
                            
							if(DEBUG_CODE == 1)
								printf("op_and_expression 1 ");
                        }

                    |	op_and_expression LOGICAL_AND_OP op_rel_expression
                        {
							binaryTAC_expression(2);
                            
							if(DEBUG_CODE == 1)
								printf("op_and_expression 2 ");
                        }
                    ;

op_rel_expression:      op_condt_expression
                        {
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 1 ");
                        }

                    |	op_rel_expression EQUAL_OP op_condt_expression
                        {
							binaryTAC_expression(3);
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 2 ");
                        }
                    
                    |	op_rel_expression NOT_EQUAL_OP op_condt_expression
                        {
							binaryTAC_expression(4);
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 3 ");
                        }
                    ;

op_condt_expression:    op_additive_expression
                        {
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 1 ");
                        }

                    |	op_condt_expression LST op_additive_expression
                        {
							binaryTAC_expression(5);
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 2 ");
                        }

                    |	op_condt_expression LSTE op_additive_expression
                        {
							binaryTAC_expression(6);
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 3 ");
                        }

                    |	op_condt_expression MRT op_additive_expression
                        {
							binaryTAC_expression(7);
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 4 ");
                        }

                    |	op_condt_expression MRTE op_additive_expression
                        {
							binaryTAC_expression(8);
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 5 ");
                        }
                    ;

op_additive_expression:     op_multiplicative_expression
                            {
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 1 ");
                            }

                        |	op_additive_expression ADD_OP op_multiplicative_expression
                            {
								binaryTAC_expression(9);
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 2 ");
                            }

                        |	op_additive_expression SUB_OP op_multiplicative_expression
                            {
								binaryTAC_expression(10);
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 3 ");
                            }
                        ;

op_multiplicative_expression:       op_neg_expression
                                    {
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 1 ");
                                    }

                                |	op_multiplicative_expression MUL_OP op_neg_expression
                                    {
										binaryTAC_expression(11);
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 2 ");
                                    }

                                |	op_multiplicative_expression DIV_OP op_neg_expression
                                    {
										binaryTAC_expression(12);
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 3 ");
                                    }
                                
                                |	op_multiplicative_expression REM_OP op_neg_expression
                                    {
										binaryTAC_expression(13);
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 4 ");
                                    }
                                ;

op_neg_expression:      factor
                        {
                            
							if(DEBUG_CODE == 1)
								printf("op_neg_expression 1 ");
                        }

                    |	EXCLAMATION_OP factor
                        {
							if(currentTAC.size() >= 1) {
								pair<int, int> tempTac = currentTAC.top();
								currentTAC.pop();
								if(tempTac.second != 4) {
									expressionErrors(14);
								}
								else {
									TAC += "t" + to_string(CURRENT_TAC_INDEX);
									TAC += " = ! ";
									TAC += "t" + to_string(tempTac.first) + "\n";
									pair<int, int> newTac;
									newTac.first = CURRENT_TAC_INDEX;
									newTac.second = tempTac.second;
									// printTAC(newTac);
									currentTAC.push(newTac);
									CURRENT_TAC_INDEX++;
								}
							}
							
							if(DEBUG_CODE == 1)
								printf("op_neg_expression 2 ");
                        }
                    ;

conditional_statement:		simple_if
							{
								conditional_expression_TAC(4);
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 1 ");
							}

						|	simple_if simple_else
							{
								conditional_expression_TAC(3);
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 2 ");
							}

						|	simple_if ladder_elif
							{
								conditional_expression_TAC(3);
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 3 ");
							}

						|	simple_if ladder_elif simple_else
							{
								conditional_expression_TAC(3);
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 4 ");
							}
						;

simple_if:		if_term left_paran op_or_expression right_paran_cond block
				{

					if(DEBUG_CODE == 1)
						printf("simple_if ");
				}
			;

ladder_elif:	elif_term left_paran op_or_expression right_paran_cond block
				{
					
					if(DEBUG_CODE == 1)
						printf("ladder_elif 1 ");
				}

			|	elif_term left_paran op_or_expression right_paran_cond block ladder_elif
				{
					
					if(DEBUG_CODE == 1)
						printf("ladder_elif 2 ");
				}
			;

simple_else:	else_term block
				{
					
					if(DEBUG_CODE == 1)
						printf("simple_else ");
				}
			;

if_term:		IF
				{
					isIF = true;

					if(DEBUG_CODE == 1)
						printf("IF ");
				}
			;

elif_term:		ELIF
				{
					isIF = false;
					conditional_expression_TAC(2);

					if(DEBUG_CODE == 1)
						printf("ELIF ");
				}
			;

else_term:		ELSE
				{
					isIF = false;
					conditional_expression_TAC(2);

					if(DEBUG_CODE == 1)
						printf("ELSE ");	
				}
			;

loop_statement:		loop_term left_paran op_or_expression right_paran_cond block
					{
						conditional_expression_TAC(6);
						conditional_expression_TAC(4);
						
						if(DEBUG_CODE == 1)
							printf("loop_statement ");
					}
				;

loop_term:		LOOP 
				{
					conditional_expression_TAC(5);
					
					if(DEBUG_CODE == 1)
						printf("loop_statement ");
				}
			;

right_paran_cond:		RP
						{	
							SCOPE--;
							currentScope.pop();

							conditional_expression_TAC(1);
							
							if(DEBUG_CODE == 1)
								printf("RP ");
						}
					;

return_statement:	RETURN op_or_expression
					{
						return_expression_TAC(FUNCTION - 1);
						
						if(DEBUG_CODE == 1)
							printf("return_statement ");
					}
				;

input_output_statement:		IDENTIFIER ASSIGN_OP INPUT
							{
								string iden = string($1);
								int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
								if(m < 0) {
									IDENAlreadyExistsError(m, 12);
								} 	
								else {
									iden += "_" + to_string(m);
									input_output_TAC(1, iden);
								}
						
								if(DEBUG_CODE == 1)
									printf("input_output_statement 1 ");
							}

						|	OUTPUT ASSIGN_OP IDENTIFIER
							{
								string iden = string($3);
								int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
								if(m < 0) {
									IDENAlreadyExistsError(m, 12);
								} 	
								else {
									iden += "_" + to_string(m);
									input_output_TAC(2, iden);
								}
						
								if(DEBUG_CODE == 1)
									printf("input_output_statement 2 ");
							}
						;

factor:		term
			{
				
				if(DEBUG_CODE == 1)
					printf("factor 1 ");
			}

		|	LP op_or_expression RP
			{
				
				if(DEBUG_CODE == 1)
					printf("factor 2 ");
			}
		;
term:		BOOLEAN_LIT
			{
				assignValToTAC(4, string($1), 4);

				if(DEBUG_CODE == 1)
					printf("term 1 ");
			}

		|	FLOAT_LIT
			{
				assignValToTAC(2, string($1), 2);
				
				if(DEBUG_CODE == 1)
					printf("term 2 ");
			}

		|	INT_LIT
			{
				assignValToTAC(1, string($1), 1);

				if(DEBUG_CODE == 1)
					printf("term 3 ");
			}

		|	CHAR_LIT
			{
				assignValToTAC(3, string($1), 3);
				
				if(DEBUG_CODE == 1)
					printf("term 4 ");
			}

		|	functional_call
			{
				
				if(DEBUG_CODE == 1)
					printf("term 5 ");
			}

		|	IDENTIFIER
			{
				string iden = string($1);
				int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
				if(m < 0) {
					IDENAlreadyExistsError(m, 12);
				}
				else {
					iden += "_" + to_string(m);
					assignValToTAC(0, iden, symbolTable.getVarDataType(m));
				}
				
				if(DEBUG_CODE == 1)
					printf("term 6 ");
			}
        ;

functional_call:	IDENTIFIER LP RP
					{
						int m = symbolTable.functionIDENExists(string($1));
						if(m != -2) {
							IDENAlreadyExistsError(m, 10);
						}

						functional_expression_TAC(1, string($1));
						
						if(DEBUG_CODE == 1)
							printf("functional_call 1 ");
					}

				|	IDENTIFIER LP args RP
					{
						int m = symbolTable.functionIDENExists(string($1));
						if(m != -2) {
							IDENAlreadyExistsError(m, 11);
						}

						functional_expression_TAC(2, string($1));
						
						if(DEBUG_CODE == 1)
							printf("functional_call 2 ");
					}
                ;

args:		op_or_expression
			{
				
				if(DEBUG_CODE == 1)
					printf("args 1 ");
			}

		|	args COMMA op_or_expression
			{
				
				if(DEBUG_CODE == 1)
					printf("args 2 ");
			}
        ;

data_type:		INT
				{	
					DATA_TYPE = 1;
					
					if(DEBUG_CODE == 1)
						printf("data_type 1 ");
				}

			|	FLOAT
				{
					DATA_TYPE = 2;
					
					if(DEBUG_CODE == 1)
						printf("data_type 2 ");
				}

			|	CHAR
				{	
					DATA_TYPE = 3;
					
					if(DEBUG_CODE == 1)
						printf("data_type 3 ");
				}

			|	BOOLEAN
				{
					DATA_TYPE = 4;
					
					if(DEBUG_CODE == 1)
						printf("data_type 4 ");
				}
			;

left_paran:		LP
				{	
					SCOPE++;
					currentScope.push(SCOPE);
					
					if(DEBUG_CODE == 1)
						printf("LP ");
				}
			;

right_paran:	RP
				{	
					SCOPE--;
					currentScope.pop();

					conditional_expression_TAC(7);
					
					if(DEBUG_CODE == 1)
						printf("RP ");
				}
			;

left_curl:		LC
				{	
					SCOPE++;
					currentScope.push(SCOPE);
					
					if(DEBUG_CODE == 1)
						printf("LC ");
				}
			;

right_curl:		RC
				{	
					currentScope.pop();
					
					if(DEBUG_CODE == 1)
						printf("RC ");
				}
			;
%%

string constructTACHeader() {
	string header = "";
	vector<SymbolTableNode> internalSymbolTable = symbolTable.getSymbolTable();
	vector<FunctionTableNode> internalFunctionTable = symbolTable.getFunctionTable();

	int n;
	n = internalSymbolTable.size();
	header += to_string(n) + "\n";
	for(int i = 0; i < n; i++) {
		header += "$";
		header += internalSymbolTable[i].IDEN + "_" + to_string(i) + ".";
		header += to_string(internalSymbolTable[i].type) + ".";
		header += to_string(internalSymbolTable[i].scopeIn) + ".";
		header += to_string(internalSymbolTable[i].scope) + ".";
		header += to_string(internalSymbolTable[i].fIndex) + "\n";
	}

	n = internalFunctionTable.size();
	header += to_string(n) + "\n";
	for(int i = 0; i < n; i++) {
		header += "#";
		header += internalFunctionTable[i].IDEN + ".";
		header += to_string(internalFunctionTable[i].returnType) + ".";
		header += to_string(internalFunctionTable[i].nArgs) + ".";
		header += to_string(internalFunctionTable[i].fnIndex) + "\n";
	}

	return header;
}

void input_output_TAC(int ind, string iden) {
	// ind = 1	:	INPUT
	// ind = 2	:	OUTPUT
	
	if(ind == 1) {
		TAC += "@input = $" + iden + "\n";
	}
	else if(ind == 2) {
		TAC += "@output = $" + iden + "\n";
	}
}

void assignValToTAC(int typ, string val, int dtype) {
	pair<int, int> newTac;
	if(typ == 0) {
		TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = $" + val + "\n";
		newTac.second = dtype;
	}
	else if(typ >= 1 && typ <= 4) {
		TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = " + val + "\n";
		newTac.second = typ;
	}
	newTac.first = CURRENT_TAC_INDEX;
	// printTAC(newTac);
	currentTAC.push(newTac);
	CURRENT_TAC_INDEX++;
}

string getBinaryOperator(int op) {
	switch(op) {
		case 1:
			return "||";
		case 2:
			return "&&";
		case 3:
			return "==";
		case 4:
			return "!=";
		case 5:
			return "<";
		case 6:
			return "<=";
		case 7:
			return ">";
		case 8:
			return ">=";
		case 9:
			return "+";
		case 10:
			return "-";
		case 11:
			return "*";
		case 12:
			return "/";
		case 13:
			return "%";
		default:
			return "";
	}
}

void binaryTAC_expression(int op) {
	if(currentTAC.size() >= 2) {
		string opr = getBinaryOperator(op);

		pair<int, int> tempTac1 = currentTAC.top();
		currentTAC.pop();
		pair<int, int> tempTac2 = currentTAC.top();
		currentTAC.pop();

		bool errorOccured = false;
		switch(op) {
			case 1:
			case 2:
				errorOccured = tempTac1.second != 4;
				errorOccured = errorOccured || tempTac1.second != tempTac2.second;
				break;
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				errorOccured = tempTac1.second != tempTac2.second;
				break;
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
				errorOccured = tempTac1.second == 4;
				// if(tempTac1.second != tempTac2.second) {
				// 	if((tempTac1.second == 3 && tempTac2.second == 1)
				// 	|| (tempTac1.second == 1 && tempTac2.second == 3)) {

				// 	}
				// 	else
				// 		errorOccured = true;
				// }
				errorOccured = errorOccured || tempTac1.second != tempTac2.second;
				break;
			default:
				break;
		}

		if(errorOccured) {
			expressionErrors(op);
			return;
		}

		TAC += "t" + to_string(CURRENT_TAC_INDEX);
		TAC += " = ";
		TAC += "t" + to_string(tempTac2.first);
		TAC += " " + opr + " ";
		TAC += "t" + to_string(tempTac1.first) + "\n";

		pair<int, int> newTac;
		newTac.first = CURRENT_TAC_INDEX;
		if(op >= 3 && op <= 8) {
			newTac.second = 4;
		}
		else {
			newTac.second = tempTac1.second;
		}
		// printTAC(newTac);
		currentTAC.push(newTac);
		CURRENT_TAC_INDEX++;
	}
}

void assign_expression_TAC(int ind, string iden, int type) {
	if(currentTAC.size() >= 1) {
		pair<int, int> tempTac = currentTAC.top();
		currentTAC.pop();

		if(type == 2) {
			if(!(tempTac.second == 2 || tempTac.second == 1)) {
				// cout << "ee\n";
				expressionErrors(0);
				return;
			}
		}
		else {
			if(type != tempTac.second) {
				// cout << "dd\n";
				expressionErrors(0);
				return;
			}
		}

		if(ind == 1) {
			TAC += "$" + iden;
			TAC += " = ";
			TAC += "t" + to_string(tempTac.first) + "\n";
		}
		else if(ind >= 2 && ind <= 6) {
			if(!(type == 1 || type == 2)) {
				expressionErrors(0);
				return;
			}

			TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = $" + iden + "\n";
			CURRENT_TAC_INDEX++;

			TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = ";

			if(ind == 2) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " + ";
			}
			else if(ind == 3) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " - ";
			}
			else if(ind == 4) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " * ";
			}
			else if(ind == 5) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " / ";
			}
			else if(ind == 6) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " % ";
			}
			
			TAC += "t" + to_string(tempTac.first) + "\n";
			CURRENT_TAC_INDEX++;

			TAC += "$" + iden;
			TAC += " = ";
			TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + "\n";
		}
	}
}

void generateTACFile(string fileName) {
	fileName += ".tac";
	ofstream tacFile(fileName);
	tacFile << TAC;
	tacFile.close();
}

void conditional_expression_TAC(int type) {
	if(type == 1) {
		if(currentTAC.size() >= 1) {
			pair<int, int> tempTac = currentTAC.top();
			currentTAC.pop();

			TAC += "@if = t" + to_string(tempTac.first);
			TAC += " ^ LABEL" + to_string(LABEL) + "\n";

			currentLabel.push(LABEL);
			LABEL++;

			if(isIF) {
				currentEndLabel.push(END_LABEL);
				END_LABEL++;
			}
		}
	}
	else if(type == 2) {
		if(currentEndLabel.size() >= 1) {
			TAC += "JUMP ^ END" + to_string(currentEndLabel.top()) + "\n";
		}
		// FIX THIS

		if(currentLabel.size() >= 1) {
			TAC += "^ LABEL" + to_string(currentLabel.top()) + ":\n";
			currentLabel.pop();
		}
	}
	else if(type == 3) {
		if(currentEndLabel.size() >= 1) {
			TAC += "^ END" + to_string(currentEndLabel.top()) + ":\n";
			currentEndLabel.pop();
		}
	}
	else if(type == 4) {
		if(currentLabel.size() >= 1) {
			TAC += "^ LABEL" + to_string(currentLabel.top()) + ":\n";
			currentLabel.pop();
		}
	}
	else if(type == 5) {
		TAC += "^ LOOP_LABEL" + to_string(LOOP_LABEL) + ":\n";
		currentLoopLabel.push(LOOP_LABEL);
		LOOP_LABEL++;
	}
	else if(type == 6) {
		if(currentLoopLabel.size() >= 1) {
			TAC += "JUMP ^ LOOP_LABEL" + to_string(currentLoopLabel.top()) + "\n";
			currentLoopLabel.pop();
		}
	}
	else if(type == 7) {
		TAC += "^ FUNC_LABEL" + to_string(FUNCTION) + ":\n";
	}
}

void functional_expression_TAC(int type, string IDEN) {
	int fInd = symbolTable.getFIndex(IDEN);

	if(type == 1) {
		TAC += "JAL ^ FUNC_LABEL" + to_string(fInd) + "\n";
	}
	else if(type == 2) {
		int nargs = symbolTable.getArgs(fInd);
		if(currentTAC.size() >= nargs) {
			vector<SymbolTableNode> fVar = symbolTable.getFunctionTable(fInd);
			for(int i = 0; i < nargs; i++) {
				pair<int, int> tempTac = currentTAC.top();
				currentTAC.pop();

				TAC += "$" + fVar[nargs - i - 1].IDEN;
				TAC += " = ";
				TAC += "t" + to_string(tempTac.first) + "\n";
			}
		}
		else {
			string t = "\nERROR CODE(02040): Unequal number of arguments in function call";
			
			ERROR = 1;
			const char *s = t.c_str();
			yyerror(s);
			return;
		}
		TAC += "JAL ^ FUNC_LABEL" + to_string(fInd) + "\n";
		
		pair<int, int> newTac;
		TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = v1\n";
		newTac.first = CURRENT_TAC_INDEX;
		newTac.second = symbolTable.getReturnType(fInd);
		// printTAC(newTac);
		currentTAC.push(newTac);
		CURRENT_TAC_INDEX++;
	}
	else if(type == 3) {
		
	}
}

void return_expression_TAC(int fIndex) {
	if(currentTAC.size() >= 1) {
		// int retType = symbolTable.getReturnType(fIndex);
		// if(retType == 0) {
		// 	string t = "\nERROR CODE(02041): VOID return type function trying to return a value.\n";
			
		// 	ERROR = 1;
		// 	const char *s = t.c_str();
		// 	yyerror(s);
		// 	return;
		// }

		pair<int, int> tempTac = currentTAC.top();

		// if(retType != tempTac.second) {
		// 	string t = "\nERROR CODE(02042): Return type of function does not match returned value.\n";
			
		// 	ERROR = 1;
		// 	const char *s = t.c_str();
		// 	yyerror(s);
		// 	return;
		// }

		currentTAC.pop();
		TAC += "v1 = t" + to_string(tempTac.first) + "\n";
		TAC += "JR ^ RA\n";
	}
}

void printTAC(pair<int, int> temptac) {
	cout << "TAC: " << temptac.first << "." << temptac.second << endl;
}

void IDENAlreadyExistsError(int m, int errNo) {
	// errNo:
	// 1-4		:	Function Declaration
	// 5		:	Function parameter declaration
	// 6-9		:	Variable Declaration
	// 10-11	:	Function Call
	// 12		:	Variable Call

	int k = errNo * 2;
	string t = "";

	if(errNo >= 1 && errNo <= 4) {
		if(m == -1) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Function declaration. Identifier with this value is already declared.";
		}
		else if(m == -2) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Function declaration. Functional Identifier with this value is already declared.";
		}
	}
	else if(errNo == 5) {
		if(m == -1) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Parameter declaration. Identifier with this value is already declared.";
		}
		else if(m == -2) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Parameter declaration. Functional Identifier with this value is already declared.";
		}
	}
	else if(errNo >= 6 && errNo <= 9) {
		if(m == -1) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Variable declaration. Identifier with this value is already declared.";
		}
		else if(m == -2) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Variable declaration. Functional Identifier with this value is already declared.";
		}
	}
	else if(errNo >= 10 && errNo <= 11) {
		if(m == -1) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): No function was declared with this Identifier. A variable was.";
		}
		else if(m == 1) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): No function was declared with this Identifier.";
		}
	}
	else if(errNo == 12) {
		if(m == -2) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): No variable was declared with this Identifier. A function was.";
		}
		else if(m == -1) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): No variable was declared with this Identifier.";
		}
	}

	ERROR = 1;
	const char *s = t.c_str();
	yyerror(s);
}

void expressionErrors(int errNo) {
	string t = "";

	switch(errNo) {
		case 0:
			t = "\nERROR CODE(02025): Incorrect data types for assignment";
			break;
		case 1:
			t = "\nERROR CODE(02026): Error occured with ||";
			break;
		case 2:
			t = "\nERROR CODE(02027): Error occured with &&";
			break;
		case 3:
			t = "\nERROR CODE(02028): Error occured with ==";
			break;
		case 4:
			t = "\nERROR CODE(02029): Error occured with !=";
			break;
		case 5:
			t = "\nERROR CODE(02030): Error occured with <";
			break;
		case 6:
			t = "\nERROR CODE(02031): Error occured with <=";
			break;
		case 7:
			t = "\nERROR CODE(02032): Error occured with >";
			break;
		case 8:
			t = "\nERROR CODE(02033): Error occured with >=";
			break;
		case 9:
			t = "\nERROR CODE(02034): Error occured with +";
			break;
		case 10:
			t = "\nERROR CODE(02035): Error occured with -";
			break;
		case 11:
			t = "\nERROR CODE(02036): Error occured with *";
			break;
		case 12:
			t = "\nERROR CODE(02037): Error occured with /";
			break;
		case 13:
			t = "\nERROR CODE(02038): Error occured with %";
			break;
		case 14:
			t = "\nERROR CODE(02039): Error occured with !";
			break;
		default:
			break;
	}

	ERROR = 1;
	const char *s = t.c_str();
	yyerror(s);
}

int main(int argc, char *argv[]) {
    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
           yyin = fp;
		else
			printf("Error opening file\n");
    }

    yyparse();
	// printf("Hello\n");
    return 0;
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 