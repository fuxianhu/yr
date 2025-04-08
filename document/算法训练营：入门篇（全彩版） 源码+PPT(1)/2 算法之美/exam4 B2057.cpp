#include<iostream>
using namespace std;
int n,a[105];

int maxval(int a[],int n){ //a[n]作为参数时，要分开写，a[]也可以使用*a
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

