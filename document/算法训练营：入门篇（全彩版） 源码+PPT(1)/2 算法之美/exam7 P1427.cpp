#include<bits/stdc++.h>
using namespace std;

void print(){
    int x;
    cin>>x;
    if(x==0) return;
    print();
    cout<<x<<" ";
}

int main(){
    print();
    return 0;
}
