#include<bits/stdc++.h> //����ͷ�ļ� 
using namespace std;
int a[20][20];
int main(){
	int n,x,y,total=1;
	scanf("%d",&n);
	x=y=1; 
	a[1][1]=1;
	while(total<n*n){
		while(y+1<=n&&!a[x][y+1])//���� 
			a[x][++y]=++total;
		while(x+1<=n&&!a[x+1][y])//���� 
			a[++x][y]=++total;
		while(y-1>0&&!a[x][y-1])//����
			a[x][--y]=++total;
		while(x-1>0&&!a[x-1][y])//���� 
			a[--x][y]=++total;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%3d",a[i][j]);
		if(i<n) printf("\n");
	}
	return 0;
}
