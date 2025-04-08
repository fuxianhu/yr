#include<bits/stdc++.h> //万能头文件 
using namespace std;
int f[50]; 
int main(){
	int n,k;
	f[1]=f[2]=1;
	for(int i=3;i<=30;i++)
		f[i]=f[i-1]+f[i-2];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cout<<f[k]<<endl;
	}
	return 0;
}
