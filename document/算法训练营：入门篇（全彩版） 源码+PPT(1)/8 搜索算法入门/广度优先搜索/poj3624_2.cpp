#include<cstdio>//���ȶ���ʽbfs 
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=3500;
int w[maxn],v[maxn],ww[maxn],vv[maxn];//��������ֵ
int n,m;//����������
int bestp; //��ǰ���ż�ֵ
int sumv=0;   //sumvΪ������Ʒ���ܼ�ֵ
struct goods{
	int id; //���
	double d;//��λ������ֵ
}a[maxn];

struct node{//����ڵ�,��¼��ǰ�ڵ�Ľ���Ϣ
    int cp; //��װ�뱳������Ʒ��ֵ
    double up; //��ֵ�Ͻ�
    int rw; //����ʣ������
    int id; //��Ʒ��
    node() {}
    node(int _cp,double _up,int _rw,int _id){
        cp=_cp;
        up=_up;
        rw=_rw;
        id=_id;
    }
};

bool cmp(goods a,goods b){//������Ʒ��λ������ֵ�ɴ�С����
	return a.d>b.d;
}

bool operator <(const node &a, const node &b){//�������ȼ���upԽ��Խ����
	return a.up<b.up;
}

double Bound(node z){//����ڵ���Ͻ� 
    int t=z.id;      //��Ʒ���
    int cleft=z.rw;//ʣ������
    double brp=0.0;  //ʣ����������װ�������ֵ
    while(t<=n&&w[t]<=cleft){
        cleft-=w[t];
		brp+=v[t++];
    }
    if(t<=n)
        brp+=1.0*v[t]/w[t]*cleft;
    return z.cp+brp;
}

int priorbfs(){//���ȶ���ʽ��֧�޽編
	priority_queue<node> q;  //����һ�����ȶ���
	double tup; //�Ͻ�
	q.push(node(0,sumv,m,1));//��ʼ��,���ڵ�������ȶ���
	while(!q.empty()){
		node cur,lc,rc; //��ǰ�ڵ㣬���ӣ��Һ��� 
		cur=q.top();    //ȡ��ͷ
		q.pop();       //����
		int t=cur.id; //��ǰ�������Ʒ���
		if(t>n||cur.rw==0)
			continue;
		if(cur.up<=bestp) //������չ
	    	continue;
		if(cur.rw>=w[t]){ //��չ���ӣ�����Լ�����������Է��뱳��
			lc.cp=cur.cp+v[t];
			lc.rw=cur.rw-w[t];
			lc.id=t+1;
			tup=Bound(lc); //���������Ͻ�
			lc=node(lc.cp,tup,lc.rw,lc.id);
			if(lc.cp>bestp)  //������ֵ��Ÿ���
				bestp=lc.cp;
			q.push(lc);      //�������
		}
		rc.cp=cur.cp;
		rc.rw=cur.rw;
		rc.id=t+1;
		tup=Bound(rc);  //�����Һ����Ͻ�
		if(tup>bestp){ //��չ�Һ��ӣ������޽�������������
			rc=node(rc.cp,tup,rc.rw,rc.id);
			q.push(rc); //�Һ������
		}
	}
	return bestp;//��������ֵ
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&ww[i],&vv[i]);
    for(int i=1;i<=n;i++){
        a[i].id=i;
        a[i].d=1.0*vv[i]/ww[i];
        sumv+=vv[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
    	w[i]=ww[a[i].id];
		v[i]=vv[a[i].id];
	} 
    priorbfs();
    printf("%d\n",bestp);
    return 0;
}
