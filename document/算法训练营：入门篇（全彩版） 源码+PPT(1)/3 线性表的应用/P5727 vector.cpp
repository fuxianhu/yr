#include<bits/stdc++.h> //�ǹȲ���
using namespace std;

int main(){
	int n;
	vector<int>a;
	cin>>n;
	while(n!=1){          
		a.push_back(n);   //�������� 
		if(n%2) n=3*n+1; //��������3��1 
		else n/=2;       //ż��������2 
	}
	a.push_back(1);  //������1�������� 
	for(int j=a.size()-1;j>=0;j--) //������� 
		cout<<a[j]<<' ';
	return 0;
}
