#include<iostream>
#include<string>
using namespace std;
int n,root,lc[100],rc[100];
string s;

void preorder(int t){
	if(t!='*'-'a'){
		cout<<char(t+'a');
		preorder(lc[t]);
		preorder(rc[t]);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(!i)
			root=s[0]-'a';
		lc[s[0]-'a']=s[1]-'a';
		rc[s[0]-'a']=s[2]-'a';
	}
	preorder(root);
	return 0;
} 
