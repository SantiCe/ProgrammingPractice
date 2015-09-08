//Calculate all possible permutations of [8] to get all the possible solutions to the 8 queens problem
#include<bits/stdc++.h>
using namespace std;
struct Sol{

    int* m;

    string toPrint(){
        string s = "{";
        for(int i = 0; i < 8; i ++){
            stringstream ss;
            ss << m[i];
            s = s + ss.str();
            if(i != 7) s = s+",";
        }
        s+="}";
        return s;
    }
};

bool isSolution(Sol sol){
    int* m = sol.m;
    set<int> sums;
    set<int> subs;
    for(int i = 0; i < 8; i ++){
        if(sums.find(i+m[i]) != sums.end()) return false;
        else{
            sums.insert(i+m[i]);
        }
        if(subs.find(i-m[i]) != subs.end()) return false;
        else {
            subs.insert(i-m[i]);
        }
    }
    return true;
}
int main(){
    Sol sol;
    int* m = sol.m;
    for(int i = 0; i < 8; i ++){
        sol.m[i] = i;
    }
    int i = 0;
    ofstream myfile("167in.txt");
    while(next_permutation(m,m+8)){
        //if(i % 20 == 0) cout << "Checking "<< i << endl;
        sol.m = m;
        if(isSolution(sol)) {
                i++;
                myfile << sol.toPrint() << ", ";
        }

    }
    cout << endl <<  i << endl;

}
