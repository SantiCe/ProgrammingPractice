#include<bits/stdc++.h>
using namespace std;

int countZeros(int n){
    if(n == 0) return 1;
    stringstream ss;
    ss << n;
    string str = ss.str();
    int len = log10(n)+1;
    char c[len];
    strcpy(c,str.c_str());
    int coun = 0;
    for(int i = 0; i < len; i ++){
        if(c[i] == '0')coun++;
    }
    return coun;
}


int main(){
    int cou = 0;
    for(int j = 10; j <= 10000000000000; j*=10){
    int i = 0;
    if(j != 10) i = j/10;
    for(i < j; i ++){
        cou += countZeros(i);
    }
    cout << "0,"<<j-1<<": "<<cou<<endl;
    }
}
