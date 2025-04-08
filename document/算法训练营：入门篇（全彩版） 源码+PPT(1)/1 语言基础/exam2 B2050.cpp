#include<bits/stdc++.h> //万能头文件 
using namespace std;

int main(){
	int a,b,c;  //三角形的边
	cin>>a>>b>>c; 
	if(a+b>c && a+c>b && b+c>a) //两边之和大于第三边 
		cout<<1<<endl;
	else
		cout<<0<<endl;
	return 0;
}
