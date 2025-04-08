#include<iostream> //创建无向网的链式前向星 
#include<cstring>
using namespace std;
const int maxn=100+5;
int head[maxn];
int n,m,cnt;

struct Edge{
	int to,w,next;
}e[maxn*maxn];

void init(){//初始化 
	memset(head,-1,sizeof(head));
	cnt=0;
}

void add(int u,int v,int w){//添加一条边u-v，边权为w 
 	e[cnt].to=v;
 	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
} 

void printg(){//输出链式前向星
	cout<<"----------链式前向星如下：----------"<<endl;
	for(int v=1;v<=n;v++){
		cout<<v<<"：  ";
		for(int i=head[v];~i;i=e[i].next){
			int v=e[i].to,w=e[i].w;
			cout<<"["<<v<<" "<<w<<"]\t";
		}
		cout<<endl;
	}
}

int main(){
	cin>>n>>m;
	init();
	int x,y,w;
	for(int i=1;i<=m;i++){ 
		cin>>x>>y>>w;
		add(x,y,w);//添加边
		add(y,x,w);//添加反向边 
	}
	printg();
	return 0;
}
/*
4 5
1 2 5
1 4 3
2 3 8
2 4 12
3 4 9
*/
