#include<iostream>//��������ͼ���ڽӾ���
using namespace std;
const int maxn=10005; //��������ֵ
int G[maxn][maxn]; //�ڽӾ���
int n,m; //����������� 

void createAM(){ //��������ͼ���ڽӾ��� 
    int u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++) //��ʼ������ֵΪ0��������������ʼ��Ϊ�����
		for(int j=1;j<=n;j++)
			G[i][j]=0;
    for(int i=1;i<=m;i++){ //mΪ����
		cin>>u>>v; //һ���ߵ����������
		G[u][v]=G[v][u]=1; //�ڽӾ�����1
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
    createAM();
    printg();
    return 0;
}
/*��������
4 5
1 2
1 4
2 3
2 4
3 4
*/
