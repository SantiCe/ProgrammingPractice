#include<bits/stdc++.h>
using namespace std;

int A[2001]; int lis[2001]; int lds[2001];
int size, cases;

int main() {

    cin >> cases;
    while((cases--) > 0){
        cin >> size;
        for(int i = 0; i < size; i ++){
            cin >> A[i];
        }
        if(size == 0) cout << 0 << endl;
        else{
            lis[size-1] = lds[size-1] = 1;
            int m = 1;
            for(int i = size-2; i >= 0; i --){
                lis[i] = lds[i] = 1;
                for(int j = i+1; j < size; j ++){
                    if(A[i] < A[j]){
                        lis[i] = max(lis[i],lis[j]+1);
                    }
                    else if (A[i] > A[j]){
                        lds[i] = max(lds[i],lds[j]+1);
                    }
                }
                m = max(m,lis[i]+lds[i]-1);
            }
            cout << m << endl;
        }

    }

}
