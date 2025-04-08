#include<bits/stdc++.h>
using namespace std;

int main(){
	stack<int>s; //定义一个栈 
	int x;
	while(true){
		cin>>x;
		if(x==0) break;
		s.push(x);     //入栈	
	}
	while(!s.empty()){ //栈不空 
		cout<<s.top()<<" ";  //输出栈顶 
		s.pop();      //出栈
	}
	return 0;
}
