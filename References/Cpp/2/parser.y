%{	
	#include<fstream>
	#include<stdio.h>
	#include<iostream>
	#include<vector>

	using namespace std;
	extern FILE* yyin;

	extern "C"
	{
		int yyparse(void);
		int yylex(void);
		void yyerror(const char* s)
		{
			printf("%s\n", s);
		}
		int yywrap()
		{
			return 1;
		}
	}
	//any instantiation code in c++
	vector<string> sampleVector;
%}
%token PRINT
%%
	print: PRINT			{
								cout << "Print is derived" << endl;
								sampleVector.push_back("sample string");
								cout << sampleVector[0] << endl;
								//any code in c++
							}
		;
%%

int main()
{
	//any code in c++
	yyparse();
	return 0;
}
