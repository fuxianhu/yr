#include<iostream>
using namespace std;
#define MAXVALUE  0x3f3f3f3f
#define MAXBIT    100
#define MAXLEAF   100
#define MAXNODE   MAXLEAF*2 -1

typedef struct{ //�ڵ�ṹ��
    double weight; //Ȩֵ 
    int parent;  //���ڵ� 
    int lchild;  //���� 
    int rchild;  //�Һ��� 
    char value;  //�ڵ��ַ� 
}HNodeType;       

typedef struct{ //����ṹ��
    int bit[MAXBIT];
    int start;
}HCodeType;
       
HNodeType HuffNode[MAXNODE]; //�ڵ�ṹ������
HCodeType HuffCode[MAXLEAF];//����ṹ������

void HuffmanTree (HNodeType HuffNode[],int n){//�����������
    int x1, x2; //x1��x2��������СȨֵ�ڵ��������е��±�
    double m1,m2; //m1��m2��������СȨֵ
    for(int i=0; i<2*n-1;i++){ //��ʼ����Ź����������� HuffNode[]
        HuffNode[i].weight=0;
        HuffNode[i].parent=-1;
        HuffNode[i].lchild=-1;
        HuffNode[i].rchild=-1;
    }
    for(int i=0;i<n;i++) //����n��Ҷ�ӵ��ַ���Ȩֵ
        cin>>HuffNode[i].value>>HuffNode[i].weight;
    for(int i=0;i<n-1;i++){ //ִ��n-1�κϲ�
        m1=m2=MAXVALUE;
        x1=x2=0;
        //�ҳ�Ȩֵ��С���޸��ڵ�������ڵ㣬�ϲ�Ϊһ�ö�����
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
        //���������ӽڵ�� x1��x2 �ĸ��ڵ���Ϣ
        HuffNode[x1].parent  = n+i;
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = m1+m2;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
        cout<<"round "<<i+1<<":  "<<HuffNode[x1].weight<<"  "<<HuffNode[x2].weight<<endl; /* ���ڲ��� */
    }
}

void HuffmanCode(HCodeType HuffCode[],int n){//������������
    HCodeType cd;      //����һ����ʱ��������ű�����Ϣ
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
            cd.start--;        //ǰ��һλ
            c=p;
            p=HuffNode[c].parent; //�����ƶ� 
        }
        //��Ҷ�ӽڵ�ı�����Ϣ����ʱ����cd�и��Ƴ������������ṹ������
        for(int j=cd.start+1;j<n;j++)
        	HuffCode[i].bit[j]=cd.bit[j];
        HuffCode[i].start=cd.start;
    }
}

int main(){
    int n;
    cin>>n;
    HuffmanTree(HuffNode,n);  //�����������
    HuffmanCode(HuffCode,n);  //������������
    for(int i=0;i<n;i++){    //����ѱ���õ����д��ڱ���Ĺ���������
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
