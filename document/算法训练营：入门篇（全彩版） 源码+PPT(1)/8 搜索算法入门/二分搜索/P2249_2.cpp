#include<iostream>
using namespace std;
const int maxn=1e6+5;
int a[maxn],n,m;

int BinarySearch(int left,int right,int x){ //���ֲ���,�ݹ��㷨
	if(left>=right){  //�ݹ��������
		if(a[left]==x) return left;
		else return -1;
	}
	int mid=(left+right)/2; //����midֵ
	if(x<=a[mid])     //��ǰ�벿�ֲ���
		return BinarySearch(left,mid,x);
	else             //�ں�벿�ֲ���
		return BinarySearch(mid+1,right,x);
}

int main(){
	int x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    for(int i=1;i<=m;i++){
    	cin>>x;
    	int k=BinarySearch(1,n,x);
    	cout<<k<<" ";
	}
    return 0;
}
