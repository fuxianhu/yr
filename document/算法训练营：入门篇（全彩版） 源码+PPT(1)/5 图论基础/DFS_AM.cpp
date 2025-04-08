#include<iostream>  //基于邻接矩阵的深度优先遍历
#include<cstring>
using namespace std;
const int maxn=100;   //顶点数最大值
bool visited[maxn];  //访问标记数组
int G[maxn][maxn];  //邻接矩阵 
int n,m;    //顶点数，边数

void DFS_AM(int u){//基于邻接矩阵的深度优先遍历
	cout<<u<<"\t";
	visited[u]=true;
	for(int v=1;v<=n;v++){//依次检查所有节点
		if(G[u][v]&&!visited[v])//u、v邻接而且v未被访问
			DFS_AM(v);//从v开始递归深度优先遍历
	} 
}

void printg(){//输出邻接矩阵
    cout<<"图的邻接矩阵为："<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
			cout<<G[i][j]<<"\t";
        cout<<endl;
    }
}

int main(){
	int u,v;   //一条边的两个顶点编号 
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		G[u][v]=G[v][u]=1;  //无向图，双边 
	}
	printg();
	memset(visited,0,sizeof(visited));
	DFS_AM(1); //从节点1开始深度优先遍历 
    return 0;
}
/*测试数据 
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
