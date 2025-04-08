#include<iostream>
#include<queue>  //�������ͷ�ļ�
#include<cstring>
using namespace std;
const int maxn=100;   //���������ֵ
bool visited[maxn];  //���ʱ������
int G[maxn][maxn];  //�ڽӾ��� 
int n,m;    //������������

void BFS_AM(int s){ //�����ڽӾ���Ĺ�����ȱ���
    queue<int>Q;   //����һ����ͨ����(�Ƚ��ȳ�)��������int����
    cout<<s<<"\t";
    visited[s]=true; //����ѷ��� 
    Q.push(s);      //s���
    while(!Q.empty()){ //������в���
        int u=Q.front();  //ȡ����ͷ
        Q.pop();      //��ͷ����
        for(int v=1;v<=n;v++){  //���μ��ڵ�
            if(G[u][v]&&!visited[v]){ //u��v�ڽӶ���vδ������
            	cout<<v<<"\t";
            	visited[v]=true;
            	Q.push(v);
            }
        }
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
		G[u][v]=1; //����ͼ��ֻ��u-->v�ı� 
	}
	printg();
	memset(visited,0,sizeof(visited));
	BFS_AM(1); //�ӽڵ�1��ʼ������ȱ��� 
    return 0;
}
/*�������� 
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
