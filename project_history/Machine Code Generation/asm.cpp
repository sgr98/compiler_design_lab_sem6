#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;

class entry{
    public:
        string variable_name;
        int type;
        string address = "";
        string tac = "";
};
/*string get_initialized(string token, string variable, int type){
    switch(type){
        case 1 : 
                    int pos = token.find('=');
                    char pos_token = check.at(pos+2);

                    if(isdigit(pos_token)){
                        string token_substring = token.substr(pos+2);
                        int space_position = token_substring,find(' ');
                        if(space_position < 0){
                            return token_substring;
                        }
                        else{
                            return "";
                        }
                    } 
        default
    }    
}*/
int main(){
    vector<entry> symbol_table;
    vector<string> initializer;
    ifstream fin;                                           //This is for the input class
    string line_buffer;                                     //Stores each line in the file

    fin.open("file.tac");

    while(fin){
        getline(fin, line_buffer);
        if(line_buffer == "\0"){
            break;
        }
        //int array_size = line_buffer.length();
        char analyzer_array[1000];                              //This array is for analyzing and creating a symbol table for reference

        strcpy(analyzer_array, line_buffer.c_str());            //Copying string to array
        //cout<< "This is the array = " << analyzer_array << endl;
        char* token = strtok(analyzer_array," ");               //Dividing analyzer array into tokens formed from delimitter of " "
        //break;
        while(token!= NULL){
            string token_check = token;
            //cout << "token =" << token_check << endl;
            int token_size = token_check.length();
            //cout << "token_size = " << token_size << endl;
            int pos = token_check.find(".");
            //cout << "pos = "<< pos << endl;
            //break;
            if(pos < token_size && pos >= 0){
                class entry entry_temp;                                 //Temporarily holds the value of current token
                entry_temp.variable_name = token_check.substr(0,pos);                      
                entry_temp.type = stoi(token_check.substr(pos+1));
                //cout << "entry = " << entry_temp.variable_name << endl << "entry_type ="<<entry_temp.type << endl;
                //break;
                if(symbol_table.size() == 0){
                    symbol_table.push_back(entry_temp);
                }
                else{     
                    //This is the code for storing unique variable in the symbol table. As of now deals only with variables
                    for(int i = 0; i < symbol_table.size();i++){
                        if(entry_temp.variable_name != symbol_table[i].variable_name){
                            symbol_table.push_back(entry_temp);
                            break;
                        }
                        else{
                            break;
                        }
                    }
                }
                
            }
            token = strtok(NULL," ");
            //cout<<"true" <<endl;
        }
        //cout << "First Loop has ended" <<endl;
    }
    fin.close();

    /*for(int i = 0; i< symbol_table.size(); i++){
        cout<<symbol_table[i].variable_name;
        cout<<'.'<<symbol_table[i].type<<endl;
    }*/

    ofstream fout;

    fout.open("file.asm");
    fout<<".data\n";
    for(int i = 0; i<symbol_table.size(); i++){
        fout << '\t' << symbol_table[i].variable_name<<": ";
        switch(symbol_table[i].type){
            case 1: fout<< ".word " << "0"  << endl;
                    break;
            case 2: fout<< ".word " << "0.0" << endl;
                    break;
            case 3: fout<< ".byte " << "A" << endl;
                    break;
            case 4: fout<< ".halfword " << "0" << endl;
                    break;
            default: break;
        }
    }
    fout.close();

    fin.open("file.tac");
    
    while(fin){
        getline(fin,line_buffer);

    }
}