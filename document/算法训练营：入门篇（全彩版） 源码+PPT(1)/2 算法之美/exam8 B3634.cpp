#include<iostream>
using namespace std;

int gcd(int n,int m) { //���Լ��
    if(m==0) return n;
    return gcd(m,n%m);
}

int gcd2(int n,int m) { //ѭ���� 
    while(m){
        int t=n%m;
		n=m;
		m=t;
	}
	return n;
}

long long lcm(int n,int m) { //��С������������long long,�������
    return (long long)n*m/gcd(n,m); //��Ҫת��Ϊlong long,�������
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<" "<<lcm(a,b);
    return 0;
}
