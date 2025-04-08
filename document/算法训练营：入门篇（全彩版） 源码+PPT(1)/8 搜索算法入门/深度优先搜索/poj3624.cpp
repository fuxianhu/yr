#include<cstdio>//�����Ż���tle 
#include<algorithm>
using namespace std;
const int maxn=3500;
int w[maxn],v[maxn],ww[maxn],vv[maxn];//��������ֵ
int n,m;//����������
int cw,cp; //��ǰ��������ǰ��ֵ
int bestp; //��ǰ���ż�ֵ
struct goods{
    int id; //���
    double d;//��λ������ֵ
}a[maxn];

bool cmp(goods a,goods b){//������Ʒ��λ������ֵ�ɴ�С����
    return a.d>b.d;
}

double Bound(int i){//��ǰ�������ܼ�ֵcp��ʣ�����������ɵ�����ֵ
    int cleft=m-cw;//ʣ�౳������
    double brp=0.0;
    while(i<=n&&w[i]<=cleft){
        cleft-=w[i];
        brp+=v[i];
        i++;
    }
    if(i<=n)
        brp+=1.0*v[i]/w[i]*cleft;
    return cp+brp;
}

void Backtrack(int t){
    if(t>n){
        bestp=cp;
        return;
    }
    if(cw+w[t]<=m){//Լ��
        cw+=w[t];
        cp+=v[t];
        Backtrack(t+1);
        cw-=w[t];
        cp-=v[t];
    }
	if(Bound(t+1)>bestp)//�޽� 
       Backtrack(t+1);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&ww[i],&vv[i]);
    for(int i=1;i<=n;i++){
        a[i].id=i;
        a[i].d=1.0*vv[i]/ww[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
    	w[i]=ww[a[i].id];
		v[i]=vv[a[i].id];
	} 
    Backtrack(1);
    printf("%d\n",bestp);
    return 0;
}
