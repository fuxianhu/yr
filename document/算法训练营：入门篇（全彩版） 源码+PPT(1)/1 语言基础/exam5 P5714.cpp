#include<iostream>
using namespace std;

int main(){
	float m,h,bmi;
	cin>>m>>h;
	bmi=m/(h*h);
	if(bmi<18.5)
	    cout<<"Underweight";
	else if(bmi<24)
    	cout<<"Normal";
	else
    	cout<<bmi<<"\nOverweight";
	return 0;
}
