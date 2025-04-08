#include<iostream>
using namespace std;
const int maxn=100;
int a[maxn],n;

int BinarySearch(int x){ //���ֲ���
	int l=0,r=n-1; 
	while(l<=r){
		int mid=(l+r)/2;  //midΪ���ҷ�Χ���м�ֵ
		if(x==a[mid])      //���ҳɹ�
			return mid;
		else if(x<a[mid]) //��ǰ�벿�ֲ���
			r=mid-1;
		else            //�ں�벿�ֲ���
			l=mid+1;
	}
	return -1;
}

int recursionBS(int l,int r,int x){ //���ֲ���,�ݹ��㷨
	if(l>r)  //�ݹ��������
		return -1;
	int mid=(l+r)/2; //����midֵ
	if(x==a[mid])    //���ҳɹ�
		return mid;
	else if(x<a[mid]) //��ǰ�벿�ֲ���
		return recursionBS(l,mid-1,x);
	else             //�ں�벿�ֲ���
		return recursionBS(mid+1,r,x);
}

int main(){
    int x;
    cin>>n;
    for(int i=0;i<n;i++)
       cin>>a[i];
    cin>>x;
    int i=BinarySearch(x);
    //int i=recursionBS(0,n-1,x);
    if(i==-1)
		cout<<"������û��Ҫ���ҵ�Ԫ�ء�"<<endl;
    else
		cout<<"Ҫ���ҵ�Ԫ���ڵ�"<<i+1<<"λ��"<<endl;//λ����±��1
    return 0;
}
/*�������� 
11
5 8 15 17 25 30 34 39 45 52 60
17
*/
