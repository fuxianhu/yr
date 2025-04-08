#include<bits/stdc++.h> //万能头文件 
using namespace std;
int n,a[20010],cnt[110];
 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;//出现次数
		if(cnt[a[i]]==1)//如果是第一次出现就输出
			cout<<a[i]<<" ";
	}
	return 0;
}
