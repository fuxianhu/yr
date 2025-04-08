#include<iostream>//基于链式前向星的深度优先遍历 
#include<cstring>
using namespace std;
const int maxn=100+5;
int head[maxn];
bool visited[maxn];  //访问标记数组
int n,m,cnt;

struct Edge{
	int to,next;
}e[maxn*maxn];

void init(){//初始化 
	memset(head,-1,sizeof(head));
	memset(visited,0,sizeof(visited));
	cnt=0;
}

void add(int u,int v){//添加一条边u--v 
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
}

void DFS_ListGraph(int u){//基于链式前向星的深度优先遍历
	cout<<u<<"\t";
	visited[u]=true;
	for(int i=head[u];~i;i=e[i].next){ //依次检查u的所有邻接点,i!=-1可以写为~i
		int v=e[i].to;  //u的邻接点v 
		if(!visited[v]) //v未被访问
			DFS_ListGraph(v); //从v开始递归深度优先遍历
	}
} 

int main(){
	cin>>n>>m;
	init();
	int x,y,w;
	for(int i=1;i<=m;i++){ 
		cin>>x>>y;
		add(x,y);//无向图,添加边
		add(y,x);//无向图,添加反向边 
	}
	DFS_ListGraph(1);
	return 0;
}
/*
8 9
1 3
1 2
2 6
2 5
2 4
3 8
3 7
4 5
7 8
*/
