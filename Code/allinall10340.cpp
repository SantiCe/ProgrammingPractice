#include<bits/stdc++.h>
using namespace std;

bool checkSubsequence(string ss, string ls){
    char s[ss.size()];
    memcpy(s,ss.c_str(),ss.size());
    char l[ls.size()];
    memcpy(l,ls.c_str(),ls.size());
    int start = 0;

    for(int i = 0; i < ss.size(); i ++){
        char c = s[i];
        for(;start < ls.size(); start++){
            if(c == l[start]){
                break;
            };
        }
        if(start == ls.size()) return false;
        start++;
    }
    return true;
}

int main(){
    string s,l;
    string line;
    while(cin >> s >> l){
        if(checkSubsequence(s,l)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
