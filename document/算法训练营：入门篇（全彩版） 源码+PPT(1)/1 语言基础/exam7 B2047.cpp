#include<bits/stdc++.h>
using namespace std;

int main(){
	float x,y;
	cin>>x;  //ÊäÈëÊı¾İ·¶Î§0<=x<20 
	if(x<5)	  
		y=-x+2.5;
	else if(x<10)
		y=2-1.5*(x-3)*(x-3);
	else
		y=x/2-1.5;
	cout<<fixed<<setprecision(3)<<y;
	return 0;
}
