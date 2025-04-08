#include<iostream>
using namespace std;

int fib(int n){  
	if(n==1||n==2)   
		return 1;
	return fib(n-1)+fib(n-2);
}

int main(){
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cout<<fib(k)<<endl;
	}
	return 0;
}
