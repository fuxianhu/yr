#include<bits/stdc++.h> //背包问题（可切割） 
using namespace std;
struct node{//定义结构体 
	double w;//重量 
	double v;//价值 
	double p;//价值重量比v/w 
}a[105];
int n;//金币数量 
double c,sum=0;//背包容量，可以带走的金币总数

bool cmp(node a,node b){//排序优先级 
	return a.p>b.p;//按价值重量比从大到小排序
}

int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].v;
		a[i].p=a[i].v/a[i].w;//价值重量比=价格/重量 
	}
	sort(a+1,a+n+1,cmp);//按价值重量比从大到小排序
	for(int i=1;i<=n;++i){
		if(a[i].w<=c){//金币的重量<=背包剩余容量
			c-=a[i].w;//更新背包剩余容量 
			sum+=a[i].v;//累加金币的价值 
		}
		else{
			sum+=c*a[i].p;//如果装不下就分割金币装满剩余容量，部分装入 
			break;
		}
	}
	printf("%.2f",sum);//保留小数点后两位输出
	return 0; 
}
