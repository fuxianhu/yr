#include<iostream>
using namespace std;

int fac(int n){ //�ݹ���n�Ľ׳� 
    if(n==0||n==1) return 1;
    return n*fac(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<fac(n);
    return 0;
}
