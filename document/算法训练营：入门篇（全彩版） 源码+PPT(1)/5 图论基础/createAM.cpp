#include<iostream>//创建无向图的邻接矩阵
using namespace std;
const int maxn=10005; //结点数最大值
int G[maxn][maxn]; //邻接矩阵
int n,m; //结点数，边数 

void createAM(){ //创建无向图的邻接矩阵 
    int u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++) //初始化所有值为0，如果是网，则初始化为无穷大
		for(int j=1;j<=n;j++)
			G[i][j]=0;
    for(int i=1;i<=m;i++){ //m为边数
		cin>>u>>v; //一条边的两个结点编号
		G[u][v]=G[v][u]=1; //邻接矩阵储置1
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
    createAM();
    printg();
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
