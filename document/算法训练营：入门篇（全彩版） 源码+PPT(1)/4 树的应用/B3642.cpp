#include<iostream>
#include<string>
using namespace std;
const int maxn=1e6+5; 
int n,lc[maxn],rc[maxn];

void preorder(int t){
	if(t!=0){
		cout<<t<<" ";
		preorder(lc[t]);
		preorder(rc[t]);
	}
}

void inorder(int t){
	if(t!=0){
		inorder(lc[t]);
		cout<<t<<" ";
		inorder(rc[t]);
	}
}

void posorder(int t){
	if(t!=0){
		posorder(lc[t]);
		posorder(rc[t]);
		cout<<t<<" ";
	}
}

int main(){
	int a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		lc[i]=a;
		rc[i]=b;
	}
	preorder(1);
	cout<<endl;
	inorder(1);
	cout<<endl;
	posorder(1);
	return 0;
} 
