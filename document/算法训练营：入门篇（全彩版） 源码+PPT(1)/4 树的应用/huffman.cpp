#include<iostream>
using namespace std;
#define MAXVALUE  0x3f3f3f3f
#define MAXBIT    100
#define MAXLEAF   100
#define MAXNODE   MAXLEAF*2 -1

typedef struct{ //节点结构体
    double weight; //权值 
    int parent;  //父节点 
    int lchild;  //左孩子 
    int rchild;  //右孩子 
    char value;  //节点字符 
}HNodeType;       

typedef struct{ //编码结构体
    int bit[MAXBIT];
    int start;
}HCodeType;
       
HNodeType HuffNode[MAXNODE]; //节点结构体数组
HCodeType HuffCode[MAXLEAF];//编码结构体数组

void HuffmanTree (HNodeType HuffNode[],int n){//构造哈夫曼树
    int x1, x2; //x1、x2：两个最小权值节点在数组中的下标
    double m1,m2; //m1、m2：两个最小权值
    for(int i=0; i<2*n-1;i++){ //初始化存放哈夫曼树数组 HuffNode[]
        HuffNode[i].weight=0;
        HuffNode[i].parent=-1;
        HuffNode[i].lchild=-1;
        HuffNode[i].rchild=-1;
    }
    for(int i=0;i<n;i++) //输入n个叶子的字符和权值
        cin>>HuffNode[i].value>>HuffNode[i].weight;
    for(int i=0;i<n-1;i++){ //执行n-1次合并
        m1=m2=MAXVALUE;
        x1=x2=0;
        //找出权值最小、无父节点的两个节点，合并为一棵二叉树
        for(int j=0;j<n+i;j++){
            if(HuffNode[j].weight<m1&&HuffNode[j].parent==-1){
                m2=m1;
                x2=x1;
                m1=HuffNode[j].weight;
                x1=j;
        	}
            else if(HuffNode[j].weight<m2&&HuffNode[j].parent==-1){
            	m2=HuffNode[j].weight;
            	x2=j;
            }
        }
        //更新两个子节点点 x1、x2 的父节点信息
        HuffNode[x1].parent  = n+i;
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = m1+m2;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
        cout<<"round "<<i+1<<":  "<<HuffNode[x1].weight<<"  "<<HuffNode[x2].weight<<endl; /* 用于测试 */
    }
}

void HuffmanCode(HCodeType HuffCode[],int n){//哈夫曼树编码
    HCodeType cd;      //定义一个临时变量来存放编码信息
    int c,p;
    for(int i=0;i<n;i++){
        cd.start=n-1;
        c=i;
        p=HuffNode[c].parent;
        while(p!=-1){
            if(HuffNode[p].lchild==c)
                cd.bit[cd.start]=0;
            else
                cd.bit[cd.start]=1;
            cd.start--;        //前移一位
            c=p;
            p=HuffNode[c].parent; //向上移动 
        }
        //把叶子节点的编码信息从临时编码cd中复制出来，放入编码结构体数组
        for(int j=cd.start+1;j<n;j++)
        	HuffCode[i].bit[j]=cd.bit[j];
        HuffCode[i].start=cd.start;
    }
}

int main(){
    int n;
    cin>>n;
    HuffmanTree(HuffNode,n);  //构造哈夫曼树
    HuffmanCode(HuffCode,n);  //哈夫曼树编码
    for(int i=0;i<n;i++){    //输出已保存好的所有存在编码的哈夫曼编码
        cout<<HuffNode[i].value<<": ";
        for(int j=HuffCode[i].start+1;j<n;j++)
            cout<<HuffCode[i].bit[j];
        cout<<endl;
    }
    return 0;
}
/*
6
a 0.05
b 0.32
c 0.18
d 0.07
e 0.25
f 0.13
*/
