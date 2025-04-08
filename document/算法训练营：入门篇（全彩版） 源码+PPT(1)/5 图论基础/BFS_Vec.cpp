#include<iostream> //����vector�Ĺ�����ȱ��� 
#include<vector>  //����ͷ�ļ�<vector>
#include<queue>  //�������ͷ�ļ�
#include<cstring>
using namespace std;
const int maxn=10005; //�ڵ������ֵ
vector<int> E[maxn];//ÿ���ڵ㶨��һ��vector,�洢���ڽӵ�
bool visited[maxn];  //���ʱ������
int n,m; //�ڵ��������� 

void CreateVec(){ //��vector�洢����ͼ 
	int u,v;
	cin>>n>>m; 
	for(int i=0;i<m;i++){ //mΪ����
		cin>>u>>v; //һ���ߵ������ڵ��� 
		E[u].push_back(v); //����ͼ��ֻ��u-->v�ı� 
	}
}

void BFS_Vec(int s){ //����vector�Ĺ�����ȱ���
    queue<int>Q;   //����һ����ͨ����(�Ƚ��ȳ�)��������int����
    cout<<s<<"\t";
    visited[s]=true; //����ѷ��� 
    Q.push(s);      //s���
    while(!Q.empty()){ //������в���
        int u=Q.front();  //ȡ����ͷ
        Q.pop();      //��ͷ����
        for(int i=0;i<E[u].size();i++){  //���μ��u�������ڽӵ�
            int v=E[u][i];   //u���ڽӵ�v
			if(!visited[v]){ //vδ������
            	cout<<v<<"\t";
            	visited[v]=true;
            	Q.push(v);
            }
        }
    }
}

void printg(){ //����ڽӱ�
	cout<<"----------�ڽӱ����£�----------"<<endl;
	for(int u=1;u<=n;u++){
		cout<<u<<"-->";
		for(int i=0;i<E[u].size();i++){//����u�������ڽӵ� 
			int v=E[u][i];
			cout<<"["<<v<<"]  ";
		}
		cout<<endl;
	}
}

int main(){
    CreateVec(); //��������ͼ�ڽӱ�
    printg(); //����ڽӱ�
    memset(visited,0,sizeof(visited));
    BFS_Vec(1); //��1��ʼ������ȱ��� 
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
