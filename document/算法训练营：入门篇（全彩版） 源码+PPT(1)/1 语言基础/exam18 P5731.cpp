#include<bits/stdc++.h> //万能头文件 
using namespace std;
int a[20][20];
int main(){
	int n,x,y,total=1;
	scanf("%d",&n);
	x=y=1; 
	a[1][1]=1;
	while(total<n*n){
		while(y+1<=n&&!a[x][y+1])//向右 
			a[x][++y]=++total;
		while(x+1<=n&&!a[x+1][y])//向下 
			a[++x][y]=++total;
		while(y-1>0&&!a[x][y-1])//向左
			a[x][--y]=++total;
		while(x-1>0&&!a[x-1][y])//向上 
			a[--x][y]=++total;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%3d",a[i][j]);
		if(i<n) printf("\n");
	}
	return 0;
}
