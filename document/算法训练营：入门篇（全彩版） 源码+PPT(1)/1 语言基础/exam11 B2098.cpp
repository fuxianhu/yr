#include<bits/stdc++.h> //����ͷ�ļ� 
using namespace std;
int n,a[20010],cnt[110];
 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;//���ִ���
		if(cnt[a[i]]==1)//����ǵ�һ�γ��־����
			cout<<a[i]<<" ";
	}
	return 0;
}
