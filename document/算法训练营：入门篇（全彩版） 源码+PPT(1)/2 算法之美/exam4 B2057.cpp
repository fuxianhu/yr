#include<iostream>
using namespace std;
int n,a[105];

int maxval(int a[],int n){ //a[n]��Ϊ����ʱ��Ҫ�ֿ�д��a[]Ҳ����ʹ��*a
	int ans=0;
	for(int i=0;i<n;i++)
		if(ans<a[i])
			ans=a[i];
	return ans;
} 

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<maxval(a,n)<<endl;
	return 0;
}

