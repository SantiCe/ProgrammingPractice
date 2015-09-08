#include<bits/stdc++.h>
using namespace std;

struct Node{
    int start, finish, ans;
    Node *left, *right;

    Node(int from, int to){
        start = from;
        finish = to;
        ans = 0;
        if(from == to) left = right = NULL;
        else{
            left = new Node(from,(from+to)/2);
            right = new Node((from+to)/2 + 1,to);
        }
    }

    void update(int pos, int val){
        if(start == finish){
            ans = val;
            return;
        }
        if(pos<=(start+finish)/2)
            left ->update(pos,val);
        else
            right ->update(pos,val);
        ans = max(left->ans,right->ans);
    }

    int query(int from, int to){
        if(start == from && finish == to){
            return ans;
        }
        if(to <=(start+finish)/2)
            return left->query(from,to);
        if(from > (start+finish)/2)
            return right->query(from,to);
        else return max(left->query(from,(start+finish)/2), right->query((start+finish)/2 +1, to));
    }
};

int solve(long long n){
    if(n == 1) return 1;
    if(n % 2 == 0) return solve(n/2)+1;
    if(3*n+1 < 0){
        cout << n << " la totea " << endl;
        return 0;
    }
    else return solve(3*n+1)+1;
}

int main(){
    Node* root = new Node(1,1000000);
    for(int i = 1; i < 1000000; i ++){
        root->update(i,solve(i));
    }

    int i,j;

    while(cin >> i >> j){
        int n,m;
        if(i > j){
            m = i; n = j;
        }
        else{
            m = j; n = i;
        }
        cout << i << " " << j << " " << root->query(n,m) << endl;
    }
    return 0;
}


