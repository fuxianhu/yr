#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[105][105];
char s[105];
 
bool match(int l,int r){ //判断括号是否匹配 
	if(s[l]=='('&&s[r]==')') return 1;
	if(s[l]=='['&&s[r]==']') return 1;
	return 0;
}
 
int main(){
    while(~scanf("%s",s)&&s[0]!='e'){ //读到文件尾且首字符不为'e'
        int n=strlen(s);
        memset(dp,0,sizeof(dp));
        for(int d=2;d<=n;d++){  //枚举区间长度 
            for(int i=0;i<n-d+1;i++){ //枚举起点 
                int j=i+d-1;    //枚举终点 
                if(match(i,j))
                    dp[i][j]=dp[i+1][j-1]+2;
                for(int k=i;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);  
            }
        }
        printf("%d\n", dp[0][n-1]);
    }
    return 0;
}
