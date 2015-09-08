    #include<bits/stdc++.h>
    using namespace std;

    int n,delta,op,cas,T;
    string s;
    short m[50][50];
    short auxm[50][50];

    void sw(){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                m[i][j] = auxm[i][j];
            }
        }
    }

    void swc(){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                auxm[i][j] = m[i][j];
            }
        }
    }

    void transpose(){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                auxm[i][j] = m[j][i];
            }
        }
        sw();
    }

    void changeRow(int o, int d){
        swc();
        for(int i = 0; i < n; i ++){
            auxm[o][i] = m[d][i];
            auxm[d][i] = m[o][i];
        }
        sw();
    }

    void changeCol(int o, int d){
        swc();
        for(int i = 0; i < n; i ++){
            auxm[i][o] = m[i][d];
            auxm[i][d] = m[i][o];
        }
        sw();
    }

    void inc(){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                m[i][j]=(m[i][j]+delta+550)%10;
            }
        }
    }
    int main(){
        cin >> T;
        cas = 1;
        while(cas <= T){
            delta = 0;
            cin >> n;
            for(int i = 0; i < n; i ++)
            {
                for(int j = 0; j < n; j ++){
                    char cc;
                    cin >> cc;
                    m[i][j] = cc-'0';
                }
            }
            cin >> op;
            for(int oo = 0; oo < op; oo ++){
                cin >> s;
                if(s.compare("transpose") == 0){
                    transpose();
                }
                else if(s.compare("row")==0){
                    short o,d;
                    cin >> o >> d;
                    changeRow(o-1,d-1);
                }
                else if(s.compare("col")==0){
                    short o,d;
                    cin >> o >> d;
                    changeCol(o-1,d-1);
                }
                else if(s.compare("inc")==0){
                    delta++;
                }
                else delta--;
            }
            cout <<"Case #"; cout << cas << endl;
            cas++;
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < n; j ++){
                    m[i][j] = (m[i][j]+550+delta)%10;
                    cout << m[i][j];
                }
                cout << endl;
            }
            cout << endl;

        }
    }
