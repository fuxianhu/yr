#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt=0;
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(s[i]!=' ')
			cnt++; 
	cout<<cnt;
	return 0;
 } 
