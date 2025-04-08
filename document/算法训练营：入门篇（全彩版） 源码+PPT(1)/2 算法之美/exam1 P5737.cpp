#include<iostream>
using namespace std;
int ans[1500];

bool judge(int year){ //ÅÐ¶ÏÊÇ·ñÎªÈòÄê 
	if((year%4==0&&year%100!=0)||year%400==0)
		return true; 
	else
		return false; 
}

int main(){
	int x,y,cnt=0;
	cin>>x>>y;
	for(int i=x;i<=y;i++){
		if(judge(i))
			ans[cnt++]=i;
	} 
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)
		cout<<ans[i]<<" ";
	return 0;
}
