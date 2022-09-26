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
        p=L->next;

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
}