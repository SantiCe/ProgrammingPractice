#include<bits/stdc++.h>
using namespace std;

char convert(char c){
    if(c == '-' || c == '0' || c == '1')return c;
    else{
        int x = c-'A';
        if(x <= 14) return '0' + (x/3 + 2);
        else{
            if(x >= 15 && x <= 18) return '7';
            else if (x >= 19 && x <= 21) return '8';
            else return '9';
        }
    }
}

int main(){
    string s;
    while(cin >> s){
        char *c = &s[0u];
        for(int i = 0; i < s.length(); i ++){
            cout << convert(c[i]);
        }
        cout << endl;
    }
}
