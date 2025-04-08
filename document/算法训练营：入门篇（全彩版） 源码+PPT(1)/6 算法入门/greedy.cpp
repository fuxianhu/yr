#include<iostream>
#include<algorithm>
const int N=105;
using namespace std;
double w[N],c; //古董的重量数组，船的载重量 

int main(){
    int n;
    cin>>c>>n;
	for(int i=0;i<n;i++) //输入每个物品重量
		cin>>w[i];
	sort(w,w+n); //按古董重量升序排序
	double tmp=0.0;  //已装载到船上的古董重量
	int ans=0;  //已装载的古董个数
	for(int i=0;i<n;i++){
	    tmp+=w[i];
	    if(tmp>c) break;
	    ans++;  
	}
	cout<<ans<<endl;
    return 0;
}
/*测试样例 
30 8
4 10 7 11 3 5 14 2
*/ 
