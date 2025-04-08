#include<bits/stdc++.h> //角谷猜想
using namespace std;

int main(){
	int n;
	vector<int>a;
	cin>>n;
	while(n!=1){          
		a.push_back(n);   //存入数组 
		if(n%2) n=3*n+1; //奇数，乘3加1 
		else n/=2;       //偶数，除以2 
	}
	a.push_back(1);  //把最后的1存入数组 
	for(int j=a.size()-1;j>=0;j--) //倒序输出 
		cout<<a[j]<<' ';
	return 0;
}
