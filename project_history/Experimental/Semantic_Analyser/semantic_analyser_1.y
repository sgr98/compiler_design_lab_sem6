%{	
	#include <fstream>
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include <vector>
	#include <fstream>

	using namespace std;

	extern FILE *yyin;

	extern "C"
	{
		int yyparse(void);
		int yylex(void);
		void yyerror(const char* s) {
			fprintf (stderr, "%s\n", s);
			exit(EXIT_SUCCESS);
		}
		int yywrap() {
			return 1;
		}
	}
	int DEBUG_CODE = -1;

	string TAC = "";

	// INT		:	1
	// FLOAT	:	2
	// CHAR		:	3
	// BOOLEAN	:	4
	// FUNCTION	:	5
	class Entry {
		public:
			string identifier;
			int type;
			bool initialised;

			Entry(string iden, int tp, bool initial) {
				identifier = iden;
				type = tp;
				initialised = initial;
			}
	};
	vector<Entry> symbolTable;

	vector<string> vars_st;
	vector<bool> vars_in;

	int currIden = 0;


	// Function Declarations
	int getIndexFromSymbolTable(string iden);
	void updateSymbolTable(string iden, int tp, bool initial);
	void printSymbolTable();
	void generateTACFile();
%}

%start program_start
%union {char *str; int type;}

%token MAIN VOID RETURN INT FLOAT CHAR BOOLEAN
%token IF ELIF ELSE LOOP BREAK CONTINUE
%token <str> IDENTIFIER BOOLEAN_LIT FLOAT_LIT INT_LIT CHAR_LIT
%token SEMICOLON COMMA LP RP LC RC
%token ADD_ASSIGN_OP SUB_ASSIGN_OP MUL_ASSIGN_OP DIV_ASSIGN_OP REM_ASSIGN_OP
%token EQUAL_OP NOT_EQUAL_OP MRTE LSTE MRT LST
%token LOGICAL_AND_OP LOGICAL_OR_OP EXCLAMATION_OP
%token <str> ASSIGN_OP ADD_OP SUB_OP MUL_OP DIV_OP REM_OP

%type <type> data_type 
%type <str> ident_nont

%%

program_start:  program	
				{
					if(DEBUG_CODE == 1)
						cout << "program_start\n\n";
					
					// printSymbolTable();
					int n = symbolTable.size();
					for(int i = 0; i < n; i++) {
						TAC += (symbolTable[i].identifier + "." + to_string(symbolTable[i].type) + "\n");
					}
					TAC = TAC.substr(0, TAC.length() - 1);
					// cout << TAC;
					generateTACFile();
				}
            	;

program:	functions MAIN block	
			{
				if(DEBUG_CODE == 1)
					printf("program 1\n");
			}

        |	MAIN block              
			{
				if(DEBUG_CODE == 1)
					printf("program 2\n");
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

function_declaration:	VOID ident_nont LP params RP block		
						{
							if(DEBUG_CODE == 1)
								printf("function_declaration 1\n");
						}

					|	data_type ident_nont LP params RP block	
						{
							if(DEBUG_CODE == 1)
								printf("function_declaration 2\n");
						}
                    ;

params:		param               
			{
				if(DEBUG_CODE == 1)
					printf("params 1\n");
			}

		|	params COMMA param	
			{
				if(DEBUG_CODE == 1)
					printf("params 2\n");
			}

		|	                    
			{
				if(DEBUG_CODE == 1)
					printf("params 3\n");
			}
        ;

param:		data_type ident_nont	
			{
				if(DEBUG_CODE == 1)
					printf("param\n");
			}
    	;

block:		LC statements RC	
			{
				if(DEBUG_CODE == 1)
					printf("block 1\n");
			}

        |   LC RC	            
			{
				if(DEBUG_CODE == 1)
					printf("block 2\n");
			}
        ;

statements:		statement               
				{
					if(DEBUG_CODE == 1)
						printf("statements 1\n");
				}

			|	statements statement	
				{
					if(DEBUG_CODE == 1)
						printf("statements 2\n");
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

			|	return_statement SEMICOLON       
				{
					if(DEBUG_CODE == 1)
						printf("statement 3\n");
				}
            ;

variable_declaration:		data_type variable	
							{	
								if(DEBUG_CODE == 1)
									printf("variable_declaration ");
								int n = vars_in.size();
								for(int i = 0; i < n; i++) {
									int in = getIndexFromSymbolTable(vars_st[i]);
									if(in == -1) {
										symbolTable.push_back(Entry(vars_st[i], $1, vars_in[i]));
									}
									else {
										yyerror("Syntax Error");
									}
								}
								vars_in.clear();
								vars_st.clear();
							}
                        ;

variable:		ident_nont                                      
				{	
					vars_st.push_back(string($1));
					vars_in.push_back(false);

					//TAC = TAC + string($1) + "\n";

					if(DEBUG_CODE == 1)
						printf("variable 1 ");
				}

			|	ident_nont ASSIGN_OP expression                 
				{
					vars_st.push_back(string($1));
					vars_in.push_back(true);

					// TAC = TAC +

					if(DEBUG_CODE == 1)
						printf("variable 2 ");
				}

			|	variable COMMA ident_nont                       
				{
					vars_st.push_back(string($3));
					vars_in.push_back(false);

					//TAC = TAC + string($1) + "\n";

					if(DEBUG_CODE == 1)
						printf("variable 3 ");
				}

			|	variable COMMA ident_nont ASSIGN_OP expression  
				{
					vars_st.push_back(string($3));
					vars_in.push_back(true);
					if(DEBUG_CODE == 1)
						printf("variable 4 ");
				}
            ;

expression:		assign_expression	
				{
					if(DEBUG_CODE == 1)
						printf("expression 1 ");
				}

			|	op_expression       
				{
					if(DEBUG_CODE == 1)
						printf("expression 2 ");
				}
            ;

assign_expression:		ident_nont ASSIGN_OP op_expression      
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 1 ");
						}

					|	ident_nont ADD_ASSIGN_OP op_expression  
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 2 ");
						}

					|	ident_nont SUB_ASSIGN_OP op_expression  
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 3 ");
						}

					|	ident_nont MUL_ASSIGN_OP op_expression  
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 4 ");
						}

					|	ident_nont DIV_ASSIGN_OP op_expression  
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 5 ");
						}

					|	ident_nont REM_ASSIGN_OP op_expression  
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 6 ");
						}
                    ;

op_expression:		sub_expression                      		
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 1 ");
					}

				|	op_expression ADD_OP sub_expression         
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 2 ");
					}

				|	op_expression SUB_OP sub_expression         
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 3 ");
					}


				|	op_expression EQUAL_OP op_expression        
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 4 ");
					}

				|	op_expression NOT_EQUAL_OP op_expression    
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 5 ");
					}

				| 	op_expression LST op_expression             
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 6 ");
					}

				| 	op_expression LSTE op_expression            
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 7 ");
					}

				| 	op_expression MRT op_expression             
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 8 ");
					}

				| 	op_expression MRTE op_expression            
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 9 ");
					}


				|	op_expression LOGICAL_OR_OP sub_expression	
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 10 ");
					}

				|	EXCLAMATION_OP op_expression                
					{
						if(DEBUG_CODE == 1)
							printf("op_expression 11 ");
					}
                ;

sub_expression:		term                                			
					{
						if(DEBUG_CODE == 1)
							printf("sub_expression 1 ");
					}

                |	sub_expression MUL_OP sub_expression 	        
					{
						if(DEBUG_CODE == 1)
							printf("sub_expression 2 ");
					}

				|	sub_expression DIV_OP sub_expression          	
					{
						if(DEBUG_CODE == 1)
							printf("sub_expression 3 ");
					}

				|	sub_expression REM_OP sub_expression          	
					{
						if(DEBUG_CODE == 1)
							printf("sub_expression 4 ");
					}

				|	sub_expression LOGICAL_AND_OP sub_expression	
					{
						if(DEBUG_CODE == 1)
							printf("sub_expression 5 ");
					}

				|	LP op_expression RP                 			
					{
						if(DEBUG_CODE == 1)
							printf("sub_expression 6 ");
					}
                ;

return_statement:		RETURN op_expression	
						{
							if(DEBUG_CODE == 1)
								printf("return_statement ");
						}
                    ;

term:		BOOLEAN_LIT     
		{
			if(DEBUG_CODE == 1)
				printf("term 1 ");
		}

		|	FLOAT_LIT       
		{
			if(DEBUG_CODE == 1)
				printf("term 2 ");
		}

		|	INT_LIT         
		{
			if(DEBUG_CODE == 1)
				printf("term 3 ");
		}

		|	CHAR_LIT        
		{
			if(DEBUG_CODE == 1)
				printf("term 4 ");
		}

		|	functional_call 
		{
			if(DEBUG_CODE == 1)
				printf("term 5 ");
		}

		|	ident_nont		
		{
			if(DEBUG_CODE == 1)
				printf("term 6 ");
		}
        ;

functional_call:	ident_nont LP args RP	
					{
						if(DEBUG_CODE == 1)
							printf("functional_call 6 ");
					}
                ;

args:		term            
			{
				if(DEBUG_CODE == 1)
					printf("args 1 ");
			}

		|	args COMMA term 
			{
				if(DEBUG_CODE == 1)
					printf("args 2 ");
			}

		|	                
			{
				if(DEBUG_CODE == 1)
					printf("args 3 ");
			}
        ;

data_type:		INT		
				{
					$$ = 1;
					if(DEBUG_CODE == 1)
						printf("data_type 1 ");
				}

			|	FLOAT 	
				{
					$$ = 2;
					if(DEBUG_CODE == 1)
						printf("data_type 2 ");
				}

			|	CHAR    
				{
					$$ = 3;
					if(DEBUG_CODE == 1)
						printf("data_type 3 ");
				}

			|	BOOLEAN	
				{
					$$ = 4;
					if(DEBUG_CODE == 1)
						printf("data_type 4 ");
				}
			;

ident_nont:		IDENTIFIER	
				{	
					$$ = $1;
					if(DEBUG_CODE == 1)
						printf("ident_nont ");
				}
			;

%%

int getIndexFromSymbolTable(string iden) {
	int n = symbolTable.size();
	for(int i = 0; i < n; i++)
		if(iden.compare(symbolTable[i].identifier) == 0)
			return i;
	return -1;
}

void updateSymbolTable(string iden, int tp, bool initial) {
	int in = getIndexFromSymbolTable(iden);
	if(in == -1)
		symbolTable.push_back(Entry(iden, tp, initial));
	else
		symbolTable[in].initialised = initial;
}

void printSymbolTable() {
	int n = symbolTable.size();
	for(int i = 0; i < n; i++)
		cout << symbolTable[i].identifier << "\t" << symbolTable[i].type 
		<< "\t" << symbolTable[i].initialised << endl;
}

void generateTACFile() {
	ofstream tacFile("file.tac");
	tacFile << TAC;
	tacFile.close();
}

// ./parser arithmetic.xgvs
int main(int argc, char *argv[]) {
	if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
           yyin = fp;
		else
			cout << "Error opening file\n";
    }

	yyparse();
	return 0;
}