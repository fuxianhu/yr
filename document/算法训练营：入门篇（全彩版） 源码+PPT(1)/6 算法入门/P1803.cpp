#include<bits/stdc++.h>
using namespace std;
struct node{//定义一个结构体数组，分别储存开始时间和结束时间
	int s; //开始时间
	int e; //结束时间
}a[1000010];

bool cmp(node x,node y){//排序优先级 
	if(x.e==y.e) return x.s>y.s;//如果结束时间相等，开始时间从大到小 
	return x.e<y.e;//按结束时间从小到大（非递减） 
}

int main(){
	int n,cnt=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i].s>>a[i].e;
	sort(a+1,a+n+1,cmp);//排序
	int last=a[1].e;//记录最新选中比赛的结束时间 
	for(int i=2;i<=n;i++){//检查所有比赛 
		if(a[i].s>=last){
			cnt++;       //选择该比赛，计数器增1 
			last=a[i].e; //记录最新选中比赛的结束时间
		}				
	}
	cout<<cnt<<endl;//输出
	return 0;
}
