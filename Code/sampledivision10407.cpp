#include<bits/stdc++.h>
using namespace std;
int n,m,mcd;
bool i;

int gcd ( int a, int b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}

int main(){


    cin >> n;
    while(n != 0){
        i = true;
        cin >> m;
        while( m != 0){
            if(i) {
                    mcd = abs(n-m);
                    i = false;
            }
            else{
                mcd = gcd(mcd,abs(n-m));
            }
            cin >> m;

        }
        cout << mcd << endl;
        cin >> n;
    }

}

