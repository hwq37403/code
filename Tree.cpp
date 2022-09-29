#include <stdfix.h>
#include <iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define MAXSIZE 255
#define OK 1
#define ERROR 0

class Tree{

public:

typedef struct BinTreeNode{//定义线索二叉树结点类型
        int data;//数据域
        struct BinTreeNode *lchild,*rchild;
        int ltag,rtag;

    }BinTreeNode,*BinTreeList;
    //线索化二叉树
    void CreateBinTree(BinTreeList &L){
        BinTreeList *pre=NULL;
        InOrderBinTree(L,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
    //中序遍历创建线索二叉树
    void InOrderBinTree(BinTreeList &L,BinTreeList &pre){

        if(L==NULL)
            return;

        BinTreeNode *p;
        p=L->lchild;

        InOrderBinTree(p->lchild,pre);
        if(p->lchild==NULL){
            p->ltag=1;
            p->lchild=pre;
        }
        if(p->rchild==NULL&&pre!=NULL){
            pre->rtag=1;
            pre->rchild=p;
        }
        pre=L;//指向根结点
        InOrderBinTree(p->rchild,pre);
        


    }
    

    //非递归后序遍历
    void PostOrder(BinTreeList T){
        InitStack(S);//初始化栈
        p=T;
        r=NULL;
        while (p||!IsEmpty()s)
        {
            /* code */
            if (p)
            {
                push(S,p);//最左边入栈
                p=p->lchild;
            }else{
                GetTop(S,p);//读取栈顶结点，但不出栈
                if(p->rchild&&p->rchild!=r)//若右子树存在，且未被访问过
                    p=p->rchild;
                else{
                    pop(S,p);//将结点弹出
                    visit(p->data);//访问该节点
                    r=p;//记录最近访问过的结点
                    p=NULL; //结点访问完后，重置p指针

                }
            }//else
            
        }//while
        
    }

    //二叉树的非递归查找算法
    BSTNode *BST_Search(BiTree T,ElemTYpe key){
        while(T!=NULL&&key!=T->data){
            if(key<T->data){
                T=T->lchild;//小于，则在左子树查
            }else{
                T=T->rchild;//大于，则在右子树查
            }
        }
        return T;
    }
};