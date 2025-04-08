#include<iostream>//������ʽǰ���ǵĹ�����ȱ��� 
#include<cstring>
#include<queue>  //�������ͷ�ļ�
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

void BFS_ListGraph(int s){ //������ʽǰ���ǵĹ�����ȱ���
	queue<int>Q;   //����һ����ͨ����(�Ƚ��ȳ�)��������int����
	cout<<s<<"\t";
	visited[s]=true; //����ѷ��� 
	Q.push(s);      //s���
	while(!Q.empty()){ //������в���
		int u=Q.front();  //ȡ����ͷ
		Q.pop();      //��ͷ����
		for(int i=head[u];~i;i=e[i].next){//���μ��u�������ڽӵ�,i!=-1����дΪ~i
			int v=e[i].to; //u���ڽӵ�v
			if(!visited[v]){ //vδ������
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
		add(x,y); //����ͼ��ֻ��u-->v�ı� 
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
