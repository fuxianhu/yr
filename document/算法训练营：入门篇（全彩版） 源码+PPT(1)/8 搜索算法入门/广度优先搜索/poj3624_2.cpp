#include<cstdio>//优先队列式bfs 
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=3500;
int w[maxn],v[maxn],ww[maxn],vv[maxn];//重量，价值
int n,m;//数量，容量
int bestp; //当前最优价值
int sumv=0;   //sumv为所有物品的总价值
struct goods{
	int id; //序号
	double d;//单位重量价值
}a[maxn];

struct node{//定义节点,记录当前节点的解信息
    int cp; //已装入背包的物品价值
    double up; //价值上界
    int rw; //背包剩余容量
    int id; //物品号
    node() {}
    node(int _cp,double _up,int _rw,int _id){
        cp=_cp;
        up=_up;
        rw=_rw;
        id=_id;
    }
};

bool cmp(goods a,goods b){//按照物品单位重量价值由大到小排序
	return a.d>b.d;
}

bool operator <(const node &a, const node &b){//队列优先级。up越大越优先
	return a.up<b.up;
}

double Bound(node z){//计算节点的上界 
    int t=z.id;      //物品序号
    int cleft=z.rw;//剩余容量
    double brp=0.0;  //剩余容量可以装入的最大价值
    while(t<=n&&w[t]<=cleft){
        cleft-=w[t];
		brp+=v[t++];
    }
    if(t<=n)
        brp+=1.0*v[t]/w[t]*cleft;
    return z.cp+brp;
}

int priorbfs(){//优先队列式分支限界法
	priority_queue<node> q;  //创建一个优先队列
	double tup; //上界
	q.push(node(0,sumv,m,1));//初始化,根节点加入优先队列
	while(!q.empty()){
		node cur,lc,rc; //当前节点，左孩子，右孩子 
		cur=q.top();    //取队头
		q.pop();       //出队
		int t=cur.id; //当前处理的物品序号
		if(t>n||cur.rw==0)
			continue;
		if(cur.up<=bestp) //不再扩展
	    	continue;
		if(cur.rw>=w[t]){ //扩展左孩子，满足约束条件，可以放入背包
			lc.cp=cur.cp+v[t];
			lc.rw=cur.rw-w[t];
			lc.id=t+1;
			tup=Bound(lc); //计算左孩子上界
			lc=node(lc.cp,tup,lc.rw,lc.id);
			if(lc.cp>bestp)  //比最优值大才更新
				bestp=lc.cp;
			q.push(lc);      //左孩子入队
		}
		rc.cp=cur.cp;
		rc.rw=cur.rw;
		rc.id=t+1;
		tup=Bound(rc);  //计算右孩子上界
		if(tup>bestp){ //扩展右孩子，满足限界条件，不放入
			rc=node(rc.cp,tup,rc.rw,rc.id);
			q.push(rc); //右孩子入队
		}
	}
	return bestp;//返回最优值
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
