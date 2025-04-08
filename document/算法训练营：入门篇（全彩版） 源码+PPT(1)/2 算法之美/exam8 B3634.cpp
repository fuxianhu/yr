#include<iostream>
using namespace std;

int gcd(int n,int m) { //最大公约数
    if(m==0) return n;
    return gcd(m,n%m);
}

int gcd2(int n,int m) { //循环法 
    while(m){
        int t=n%m;
		n=m;
		m=t;
	}
	return n;
}

long long lcm(int n,int m) { //最小公倍数，定义long long,以免溢出
    return (long long)n*m/gcd(n,m); //需要转换为long long,以免溢出
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<" "<<lcm(a,b);
    return 0;
}
