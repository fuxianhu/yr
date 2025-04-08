#include<iostream>
using namespace std;
struct student{
	string name;
	int x,y,z;
}a[1005];

int main(){
	int n,max=0,sum=0,k=0; 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].x>>a[i].y>>a[i].z;
		sum=a[i].x+a[i].y+a[i].z;
		if(max<sum){
			max=sum;
			k=i;
		}
	}
	cout<<a[k].name<<" "<<a[k].x<<" "<<a[k].y<<" "<<a[k].z<<endl;
	return 0;
}
