#include<iostream>
#include<string>

using namespace std;

string reverse(string s) {
    int len = s.length();
    for(int i = 0; i < len/2 ; i++){
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    return s;
}

void convert_to_binary(char c) {
    int d = (int) c;
    string byte = "";

    int i = 0;
    int a = 1;
    while(i < 8) {
        char temp;
        // cout << "ca => " << a << endl;
        if (c & a)
            temp = '1';
        else
            temp = '0';
        byte += temp;
        a = a << 1;
        i++;
    }
    byte = reverse(byte);
    cout << byte << " ";
}

int main() {
    char a = 'B';
    unsigned int b = 20;
    signed int c = -5;
    float d = 40.5;
    double e = -5.25;
    
    cout << "char => \t";
    char *ap = &a;
    for(int i = 0; i < sizeof(a); i++) {
        convert_to_binary(ap[i]);
    }
    cout << endl;

    cout << "unsigned int => ";
    char *bp = (char *) &b;
    for(int i = 0; i < sizeof(b); i++) {
        convert_to_binary(bp[i]);
    }
    cout << endl;

    cout << "signed int => \t";
    char *cp = (char *) &c;
    for(int i = 0; i < sizeof(b); i++) {
        convert_to_binary(cp[i]);
    }
    cout << endl;

    cout << "float => \t";
    char *dp = (char *) &d;
    for(int i = 0; i < sizeof(d); i++) {
        convert_to_binary(dp[i]);
    }
    cout << endl;

    cout << "double => \t";
    char *ep = (char *) &e;
    for(int i = 0; i < sizeof(e); i++) {
        convert_to_binary(ep[i]);
    }
    cout << endl;

    return 0;
}