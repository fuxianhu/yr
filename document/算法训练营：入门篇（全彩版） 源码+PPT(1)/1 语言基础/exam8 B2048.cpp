#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,ans=8;
	char c;
	cin>>x>>c;
	if(x>1000){	  
		x-=1000;
		ans+=((x-1)/500+1)*4; //上取整方法：(n-1)/k+1
	}
	if(c=='y')
		ans+=5;
	cout<<ans;
	return 0;
}
