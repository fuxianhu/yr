#include<bits/stdc++.h>
using namespace std;
const double PI=3.14159;//Բ���� 

int main(){
    double r,a,b,c;  //�뾶��ֱ�����ܳ������ 
    scanf("%lf",&r); //����뾶 
    a=2*r; 
	b=2*PI*r;
	c=PI*r*r;
	printf("%.4f %.4f %.4f",a,b,c);  
    return 0;
}
