#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1005;
int n;
int dp[N<<1][N<<1];
int s[N<<1][N<<1];
int sum[N<<1];
int a[N<<1];
 
void init(){
    sum[0]=0;
    for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		sum[i]=a[i]+sum[i-1]; //前缀和 
		dp[i][i]=0; //初始化最优值 
		s[i][i]=i; //初始化最优决策 
    }
    for(int i=1;i<n;i++){ //预处理，将环型转化为直线型
		a[n+i]=a[i];
		sum[n+i]=a[n+i]+sum[n+i-1];
		dp[n+i][n+i]=0;
		s[n+i][n+i]=n+i;
    }
}
 
void solve(){
	for(int d=2;d<=n;d++){ //枚举区间长度 
		for(int i=1;i<=2*n-d;i++){ //枚举起点 
			int j=i+d-1;   //枚举终点 
			int tmp=sum[j]-sum[i-1]; //区间和 
			dp[i][j]=INF;
			for(int k=s[i][j-1];k<=s[i+1][j];k++){ //枚举决策点 
				if(dp[i][k]+dp[k+1][j]+tmp<dp[i][j]){
					dp[i][j]=dp[i][k]+dp[k+1][j]+tmp;
					s[i][j]=k;
				}  
			}   
		}
	}
	int ans=INF;
	for(int i=1;i<=n;i++) //求解所有规模为n的最优解的最小值 
		ans=min(ans,dp[i][n+i-1]);
	printf("%d\n",ans);
}
 
int main(){
	while(~scanf("%d",&n)){
		init();
		solve();
	}
	return 0;
}
