#include<bits/stdc++.h>
using namespace std;

int main(){
	stack<int>s; //����һ��ջ 
	int x;
	while(true){
		cin>>x;
		if(x==0) break;
		s.push(x);     //��ջ	
	}
	while(!s.empty()){ //ջ���� 
		cout<<s.top()<<" ";  //���ջ�� 
		s.pop();      //��ջ
	}
	return 0;
}
