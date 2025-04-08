#include<iostream>
#include<cstdio>
#include<algorithm>//该头文件包含排序函数sort
using namespace std;
struct node{
	int t,id;//接水时间，序号      
}a[1010];

bool cmp(node x,node y){ //定义排序比较优先级 
	return x.t<y.t; //按接水时间非递减 
}

int main(){
	int n;
	double time=0;
	cin>>n;    
	for(int i=1;i<=n;i++){
		cin>>a[i].t;
		a[i].id=i;//序号存起来    
	} 
	sort(a+1,a+n+1,cmp);//排序
	for(int i=1;i<=n;i++)//输入由小到大的编号
		cout<<a[i].id<<" ";
	cout<<endl;
	for(int i=1;i<n;i++)//累加等待时间 
		time+=a[i].t*(n-i); 
	printf("%.2f",time/n);//输出平均时间，保留两位小数 #include<iomanip> cout<<fixed<<setprecision(2)<<time/n;
	return 0; 
}
