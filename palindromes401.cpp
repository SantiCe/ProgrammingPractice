#include<bits/stdc++.h>
using namespace std;


char rev(char c){
    switch(c){
        case 'A': return 'A';
        case '3': return 'E';
        case 'E': return '3';
        case 'H': return c;
        case 'I': return c;
        case 'J': return 'L';
        case 'L': return 'J';
        case 'M': return c;
        case 'O': return c;
        case 'S': return '2';
        case 'T': return c;
        case 'U': return c;
        case 'V': return c;
        case 'W': return c;
        case 'X': return c;
        case 'Z': return '5';
        case '1': return '1';
        case '2': return 'S';
        case '5': return 'Z';
        case '8': return '8';
        default:
            return ' ';
    }
}

int main(){
    string s;
    while(cin >> s){
        bool pali = true;
        bool reve = true;
        const char *ar = s.c_str();
        for(int i=0; i <= (s.size()/2 - (s.size()+1)%2); i ++){
            int o = s.size()-1-i;
            if(ar[i] != ar[o]) pali = false;
            if(ar[o] != rev(ar[i])) reve = false;
        }
        cout << s << " -- is ";
        if(pali && reve){
            cout << "a mirrored palindrome.";
        }
        else if(pali && !reve){
            cout << "a regular palindrome.";
        }
        else if(!pali && reve){
            cout << "a mirrored string.";
        }
        else{
            cout << "not a palindrome.";
        }
        cout << endl << endl;
    }
}

