#include<bits/stdc++.h>
using namespace std;
const double PI=3.14159;//圆周率 

int main(){
    double r,a,b,c;  //半径，直径，周长，面积 
    scanf("%lf",&r); //输入半径 
    a=2*r; 
	b=2*PI*r;
	c=PI*r*r;
	printf("%.4f %.4f %.4f",a,b,c);  
    return 0;
}
