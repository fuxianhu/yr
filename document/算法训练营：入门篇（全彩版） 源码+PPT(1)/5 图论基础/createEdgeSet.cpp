#include<iostream>//�߼�����洢
#include<algorithm>
using namespace std;
const int N=100;
int n,m; //����������� 
struct Edge{
    int u,v,w;
}E[N*N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>E[i].u>>E[i].v>>E[i].w;
    return 0;
}
/*�������� 
7 12
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25
*/
