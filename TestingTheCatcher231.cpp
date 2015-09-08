#include<bits/stdc++.h>
using namespace std;

vector<int> X;
int n;

// Input: X[] is a zero-based sequence of length n
// Output: L -> The length of the longest increasing subsequence.
int LIS(){
    int P[n];
    int M[n+1];

    int L = 0;
    for(int i = 0; i < n; i ++){
        // Binary search for the largest positive j <= L such that X[M[j]] < X[i]
        int lo = 1, hi = L;
        while(lo <= hi){
            int mid = (lo+hi)/2 + ((lo+hi)%2);
            if(X[M[mid]] == X[i]){
                lo = mid;
                break;
            }
            else if(X[M[mid]] < X[i])
                lo = mid+1;
            else
                hi = mid-1;
        }
        int newL=lo;
        P[i] = M[newL-1];
        M[newL] = i;

        if(newL > L) L = newL;
    }

    return L;

    // To reconstruct
    /*int S[L];
    int k = M[L];
    for(int i = L-1; i >= 0; i--){
        S[i] = X[k];
        k = P[k];
    }*/
}


int main(){
    int x;
    cin >> x;
    int cas = 1;
    while(x != -1){
        X.clear();
        X.push_back(-x);
        cin >> x;
        while(x!=-1){
            X.push_back(-x);
            cin >> x;
        }
        n = X.size();
        if(cas != 1) cout << endl;
        cout << "Test #"<<cas<<":"<<endl;
        cout << "  maximum possible interceptions: "<<LIS() << endl;
        ++cas;
        cin >> x;
    }
}
