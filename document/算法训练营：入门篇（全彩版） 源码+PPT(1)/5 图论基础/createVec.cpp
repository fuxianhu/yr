#include<iostream>//用vector存储无向图
#include<vector>//引入头文件<vector>
using namespace std;
const int maxn=10005; //节点数最大值
vector<int> E[maxn];//每个节点定义一个vector,存储其邻接点
int n,m; //节点数，边数 

void createVec(){ //用vector存储无向图 
	int u,v;
	cin>>n>>m; 
	for(int i=1;i<=m;i++){ //m为边数
		cin>>u>>v; //一条边的两个节点编号 
		E[u].push_back(v);
		E[v].push_back(u);
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
    createVec();//创建无向图邻接表
    printg();//输出邻接表
    return 0;
}
/*测试数据
4 5
1 2
1 4
2 3
2 4
3 4
*/
