#include<bits/stdc++.h> //����ͷ�ļ� 
using namespace std;
int n,ans=0;
bool flag;
 
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		flag=true;
		for(int j=2;j*j<=i;j++){//�Գ����ж����� 
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
