#include<iostream>
using namespace std;
const int maxn=100;
int a[maxn],n;

int BinarySearch(int x){ //二分查找
	int l=0,r=n-1; 
	while(l<=r){
		int mid=(l+r)/2;  //mid为查找范围的中间值
		if(x==a[mid])      //查找成功
			return mid;
		else if(x<a[mid]) //在前半部分查找
			r=mid-1;
		else            //在后半部分查找
			l=mid+1;
	}
	return -1;
}

int recursionBS(int l,int r,int x){ //二分查找,递归算法
	if(l>r)  //递归结束条件
		return -1;
	int mid=(l+r)/2; //计算mid值
	if(x==a[mid])    //查找成功
		return mid;
	else if(x<a[mid]) //在前半部分查找
		return recursionBS(l,mid-1,x);
	else             //在后半部分查找
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
		cout<<"数列中没有要查找的元素。"<<endl;
    else
		cout<<"要查找的元素在第"<<i+1<<"位。"<<endl;//位序和下标差1
    return 0;
}
/*测试数据 
11
5 8 15 17 25 30 34 39 45 52 60
17
*/
