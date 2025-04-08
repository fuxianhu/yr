#include<bits/stdc++.h>
using namespace std; 
int main(){
	int y,m;  //Äê£¬ÔÂ·Ý 
	scanf("%d%d",&y,&m);
	switch(m){
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			printf("31");
			break;
		case 4:case 6:case 9:case 11:
			printf("30");
			break;
		case 2:
			if(y%400==0||(y%4==0&&y%100!=0))
				printf("29");
			else
				printf("28");
			break;
    }
    return 0;
}
