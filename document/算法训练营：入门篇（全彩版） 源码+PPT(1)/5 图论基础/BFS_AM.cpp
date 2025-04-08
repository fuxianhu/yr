#include<iostream>
#include<queue>  //引入队列头文件
#include<cstring>
using namespace std;
const int maxn=100;   //顶点数最大值
bool visited[maxn];  //访问标记数组
int G[maxn][maxn];  //邻接矩阵 
int n,m;    //顶点数，边数

void BFS_AM(int s){ //基于邻接矩阵的广度优先遍历
    queue<int>Q;   //创建一个普通队列(先进先出)，里面存放int类型
    cout<<s<<"\t";
    visited[s]=true; //标记已访问 
    Q.push(s);      //s入队
    while(!Q.empty()){ //如果队列不空
        int u=Q.front();  //取出队头
        Q.pop();      //队头出队
        for(int v=1;v<=n;v++){  //依次检查节点
            if(G[u][v]&&!visited[v]){ //u、v邻接而且v未被访问
            	cout<<v<<"\t";
            	visited[v]=true;
            	Q.push(v);
            }
        }
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
		G[u][v]=1; //有向图，只有u-->v的边 
	}
	printg();
	memset(visited,0,sizeof(visited));
	BFS_AM(1); //从节点1开始广度优先遍历 
    return 0;
}
/*测试数据 
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
