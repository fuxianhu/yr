#include<bits/stdc++.h> //万能头文件 
using namespace std;
int n,ans=0;
bool flag;
 
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		flag=true;
		for(int j=2;j*j<=i;j++){//试除法判断素数 
			if(i%j==0){
				flag=false;
				break;
			}
		}
		if(flag)
			ans++;
	}
	cout<<ans;
	return 0;
}
