#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    for(int i = 1; i <= 100; i ++) cout << i << " " << f(i) << endl;
    cin >> n;
    while(n != 0){
        if(n >= 101) m = n-10;
        else m = 91;
        cout << "f("<<n<<") = "<<m<<endl;
        cin >> n;
    }
}



