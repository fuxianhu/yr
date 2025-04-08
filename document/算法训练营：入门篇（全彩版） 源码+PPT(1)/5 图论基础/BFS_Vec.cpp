#include<iostream> //基于vector的广度优先遍历 
#include<vector>  //引入头文件<vector>
#include<queue>  //引入队列头文件
#include<cstring>
using namespace std;
const int maxn=10005; //节点数最大值
vector<int> E[maxn];//每个节点定义一个vector,存储其邻接点
bool visited[maxn];  //访问标记数组
int n,m; //节点数，边数 

void CreateVec(){ //用vector存储有向图 
	int u,v;
	cin>>n>>m; 
	for(int i=0;i<m;i++){ //m为边数
		cin>>u>>v; //一条边的两个节点编号 
		E[u].push_back(v); //有向图，只有u-->v的边 
	}
}

void BFS_Vec(int s){ //基于vector的广度优先遍历
    queue<int>Q;   //创建一个普通队列(先进先出)，里面存放int类型
    cout<<s<<"\t";
    visited[s]=true; //标记已访问 
    Q.push(s);      //s入队
    while(!Q.empty()){ //如果队列不空
        int u=Q.front();  //取出队头
        Q.pop();      //队头出队
        for(int i=0;i<E[u].size();i++){  //依次检查u的所有邻接点
            int v=E[u][i];   //u的邻接点v
			if(!visited[v]){ //v未被访问
            	cout<<v<<"\t";
            	visited[v]=true;
            	Q.push(v);
            }
        }
    }
}

void printg(){ //输出邻接表
	cout<<"----------邻接表如下：----------"<<endl;
	for(int u=1;u<=n;u++){
		cout<<u<<"-->";
		for(int i=0;i<E[u].size();i++){//访问u的所有邻接点 
			int v=E[u][i];
			cout<<"["<<v<<"]  ";
		}
		cout<<endl;
	}
}

int main(){
    CreateVec(); //创建有向图邻接表
    printg(); //输出邻接表
    memset(visited,0,sizeof(visited));
    BFS_Vec(1); //从1开始广度优先遍历 
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
