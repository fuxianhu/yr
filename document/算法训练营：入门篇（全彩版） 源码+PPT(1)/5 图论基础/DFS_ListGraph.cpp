#include<iostream>//������ʽǰ���ǵ�������ȱ��� 
#include<cstring>
using namespace std;
const int maxn=100+5;
int head[maxn];
bool visited[maxn];  //���ʱ������
int n,m,cnt;

struct Edge{
	int to,next;
}e[maxn*maxn];

void init(){//��ʼ�� 
	memset(head,-1,sizeof(head));
	memset(visited,0,sizeof(visited));
	cnt=0;
}

void add(int u,int v){//���һ����u--v 
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
}

void DFS_ListGraph(int u){//������ʽǰ���ǵ�������ȱ���
	cout<<u<<"\t";
	visited[u]=true;
	for(int i=head[u];~i;i=e[i].next){ //���μ��u�������ڽӵ�,i!=-1����дΪ~i
		int v=e[i].to;  //u���ڽӵ�v 
		if(!visited[v]) //vδ������
			DFS_ListGraph(v); //��v��ʼ�ݹ�������ȱ���
	}
} 

int main(){
	cin>>n>>m;
	init();
	int x,y,w;
	for(int i=1;i<=m;i++){ 
		cin>>x>>y;
		add(x,y);//����ͼ,��ӱ�
		add(y,x);//����ͼ,��ӷ���� 
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
