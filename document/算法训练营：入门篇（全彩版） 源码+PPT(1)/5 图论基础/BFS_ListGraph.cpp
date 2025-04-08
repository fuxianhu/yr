#include<iostream>//基于链式前向星的广度优先遍历 
#include<cstring>
#include<queue>  //引入队列头文件
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

void BFS_ListGraph(int s){ //基于链式前向星的广度优先遍历
	queue<int>Q;   //创建一个普通队列(先进先出)，里面存放int类型
	cout<<s<<"\t";
	visited[s]=true; //标记已访问 
	Q.push(s);      //s入队
	while(!Q.empty()){ //如果队列不空
		int u=Q.front();  //取出队头
		Q.pop();      //队头出队
		for(int i=head[u];~i;i=e[i].next){//依次检查u的所有邻接点,i!=-1可以写为~i
			int v=e[i].to; //u的邻接点v
			if(!visited[v]){ //v未被访问
				cout<<v<<"\t";
				visited[v]=true;
				Q.push(v);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	init();
	int x,y,w;
	for(int i=1;i<=m;i++){ 
		cin>>x>>y;
		add(x,y); //有向图，只有u-->v的边 
	}
	BFS_ListGraph(1);
	return 0;
}
/*
6 9
1 2
1 3
2 4
3 2
3 5
4 3
4 6
5 4
5 6
*/
