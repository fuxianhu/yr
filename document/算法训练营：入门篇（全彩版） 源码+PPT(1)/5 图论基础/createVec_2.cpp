#include<iostream>//用vector存储有向图
#include<vector>
#include<map> 
using namespace std;
const int maxn=10005; //结点数最大值
vector<int> E[maxn]; //每个结点定义一个vector,存储其邻接点
map<string,int>mp; //map映射，字符串映射一个整数编号 
int n,m; //节点数，边数 

void createVec(){ //用vector存储有向图 
	string s1,s2;
	int k=1;
	cin>>n>>m; 
	for(int i=1;i<=m;i++){ //m为边数 
		cin>>s1>>s2;//一条边的两个节点的字符串 
		if(mp[s1]==0)
			mp[s1]=k++;//映射一个节点编号 
		if(mp[s2]==0)
			mp[s2]=k++;
		E[mp[s1]].push_back(mp[s2]);
	} 
}

void printg(){//输出邻接表
	cout<<"----------邻接表如下：----------"<<endl;
	for(int u=1;u<=n;u++){ //节点编号从1开始 
		cout<<u<<"-->";
		for(int i=0;i<E[u].size();i++){ //访问u的所有邻接点 
			int v=E[u][i];
			cout<<"["<<v<<"]\t";
		}
		cout<<endl;
	}
}

int main(){
    createVec();//创建有向图邻接表
    printg();//输出邻接表
    return 0;
}
/*测试数据
4 5
beijing shanghai
beijing shenzhen
shanghai guangzhou
shanghai shenzhen
guangzhou shenzhen
*/
