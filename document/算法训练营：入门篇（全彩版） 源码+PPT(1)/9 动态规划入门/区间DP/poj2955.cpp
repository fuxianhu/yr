#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[105][105];
char s[105];
 
bool match(int l,int r){ //�ж������Ƿ�ƥ�� 
	if(s[l]=='('&&s[r]==')') return 1;
	if(s[l]=='['&&s[r]==']') return 1;
	return 0;
}
 
int main(){
    while(~scanf("%s",s)&&s[0]!='e'){ //�����ļ�β�����ַ���Ϊ'e'
        int n=strlen(s);
        memset(dp,0,sizeof(dp));
        for(int d=2;d<=n;d++){  //ö�����䳤�� 
            for(int i=0;i<n-d+1;i++){ //ö����� 
                int j=i+d-1;    //ö���յ� 
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
