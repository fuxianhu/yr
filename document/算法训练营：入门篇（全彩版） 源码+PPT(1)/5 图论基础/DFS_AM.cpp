#include<iostream>  //�����ڽӾ����������ȱ���
#include<cstring>
using namespace std;
const int maxn=100;   //���������ֵ
bool visited[maxn];  //���ʱ������
int G[maxn][maxn];  //�ڽӾ��� 
int n,m;    //������������

void DFS_AM(int u){//�����ڽӾ����������ȱ���
	cout<<u<<"\t";
	visited[u]=true;
	for(int v=1;v<=n;v++){//���μ�����нڵ�
		if(G[u][v]&&!visited[v])//u��v�ڽӶ���vδ������
			DFS_AM(v);//��v��ʼ�ݹ�������ȱ���
	} 
}

void printg(){//����ڽӾ���
    cout<<"ͼ���ڽӾ���Ϊ��"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
			cout<<G[i][j]<<"\t";
        cout<<endl;
    }
}

int main(){
	int u,v;   //һ���ߵ����������� 
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		G[u][v]=G[v][u]=1;  //����ͼ��˫�� 
	}
	printg();
	memset(visited,0,sizeof(visited));
	DFS_AM(1); //�ӽڵ�1��ʼ������ȱ��� 
    return 0;
}
/*�������� 
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
