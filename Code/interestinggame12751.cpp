    #include<bits/stdc++.h>
    using namespace std;

    int N,T,X,K,U,cas;
    long long beef;

    int main(){
        cin >> T;
        cas = 1;
        while(cas <= T){
            cin >> N >> K >> X;
            U = X+K-1;
            beef = ((N-U)*(N+U+1) + X*(X-1))/2;
            cout << "Case "<<cas<<": "<<beef<<endl;
            cas++;
        }
    }
