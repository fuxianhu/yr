#include<iostream>
#include<algorithm>
const int N=105;
using namespace std;
double w[N],c; //�Ŷ����������飬���������� 

int main(){
    int n;
    cin>>c>>n;
	for(int i=0;i<n;i++) //����ÿ����Ʒ����
		cin>>w[i];
	sort(w,w+n); //���Ŷ�������������
	double tmp=0.0;  //��װ�ص����ϵĹŶ�����
	int ans=0;  //��װ�صĹŶ�����
	for(int i=0;i<n;i++){
	    tmp+=w[i];
	    if(tmp>c) break;
	    ans++;  
	}
	cout<<ans<<endl;
    return 0;
}
/*�������� 
30 8
4 10 7 11 3 5 14 2
*/ 
