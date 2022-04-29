#include<string.h>
#include<iostream>
using namespace std;
int main(){
    string buffer = "Hello";
    if(buffer.find("ed")!=string::npos){
        cout<<"it works"<<endl;
    }
    //cout<<buffer.find("He");
}