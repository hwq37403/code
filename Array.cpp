#include <stdfix.h>
#include <iostream>
using namespace std;



class Array
{
private:
    /* data */

public:
    Array(/* args */);
    ~Array();
    typedef struct LNode { //定义单链表结点类型
        int data; //数据域
        struct LNode *next; //指针域
        }LNode,*LinkList;

    //1.时间复杂度O(n) 因为L为引用，是直接对原链表进行操作的，故不会因此断链
    void Del_X_3(LinkList &L,int x){
    //递归实现在单链表L中删除值为x的结点
    LNode *p; //p指向待删除结点
    if(L==NULL)
        return;
    if(L->data==x){
        p=L;//删除L
        L=L->next;//L指向下一节点
        free(p);
        Del_X_3(L,x);//递归调用
    }else{
        Del_X_3(L->next,x);
    }
    }

    //2.关键点在于创建一个pre结点，保留当前p结点的前驱结点，避免删除结点后断链
    //时间复杂度为O(n)。空间复杂度为O(1)
    void Del_X_1(LinkList &L,int x){
        LNode *p=L->next,*pre=L,*q;//pre指向p结点的前一个结点，q指向要删除的结点
        while(p!=NULL){
            if(p->data==x){
                q=p;//将q指向要删除的结点
                p=p->next;
                pre->next=p;//保证不会断链
                free(q);
            }
            else{
                //将pre移到p，p指向下一个指针域
                pre=p;
                p=p->next;
            }
        }

    }

    //3.先递归输出它后面的结点,再输出该结点自身，链表就反向输出了
    void R_Print(LinkList L){
        //从尾到头输出单链表L中每个结点的值
        if(L->next!=NULL){
            R_Print(L->next); //递归
        }

        if(L!=NULL) 
        cout<<L->data;// 逆向输出

    }

    void R_Ignore_Head(LinkList L){
        if(L!=NULL) R_Print(L->next);
    }

    //5.头插法，原地逆转链表
    LinkList Reverse_l(LinkList L){
        //L是带头结点的单链表，本算法将L就地逆转
        LNode *p,*r;//p为工作指针，r为p的后继，以防止断链
        p=L->next;//指向第一个元素结点
        L->next=NULL;// 头结点单独摘出
        while(p!=NULL){
            r=p->next;//暂存p的后继,
            p->next=L->next;//p结点插到头结点之后,也就是p的后继改为L的后继，所谓的头插法
            L->next=p;//将L后继指向p结点,就连起来了
            p=r;
        }
        return L;

    }

    //6.对链表排序
    //1.直接插入排序,头插法,tips:要设置前继指针*pre和后继指针*r

    //2.通过数组复制，用O(nlog2n)的算法对数组进行排序，再放回链表

    //7.两有序链表合并
    void MergeList(LinkList &La,LinkList &Lb){
        //合并两个升序链表（带头结点）,并使合并后的链表递减排列
        LNode *r,*pa=La->next,*pb=Lb->next;
        La->next=NULL;

        while(pa&&pb)//两表均不为空时
        {
            if(pa->data<=pb->data){
                //说明应该将pa->data通过头插法插入
                r=pa->next;
                pa->next=La->next;
                La->next=pa;
                pa=r;
            }
            else{
                r=pb->next;
                pb->next=Lb->next;
                Lb->next=pb;
                pb=r;
            }
        }

        if(pa){
            pb=pa;//如果pa还有剩余，将pa剩余链表赋给pb
        }

        while(pb){
            r=pb->next;
            pb->next=L->next;//头插法，保证降序
            L->next=pb;
            pb=r;
        }

        //释放Lb
        free(Lb);
    }
    

    //8.归并两升序链表的集合
    LinkList Union(LinkList &la,LinkList &lb){
        LNode *pa,*pb,*pc,*u;
        pa=la->next;
        pb=lb->next;
        pc=la;

        while(pa&&pb){
            if(pa->data==pb->data){
                pc->next=pa;//将pa的结果放于结果表里
                pc=pa;//pc指向pa,也就是pc->next
                pa=pa->next;//pa移到下一个指针
                u=pb;
                pb=pb->next;
                free(u);     
            }
            else if(pa->data<=pb->data){
                u=pa;
                pa=pa->next;
                free(u);
            }
            else{
                u=pb;
                pb=pb->next;
                free(u);
            }
        }

        //while结束后，判断pa或者pb
        while(pa){
            u=pa;
            pa=pa->next;
            free(u);
        }
        while(pb){
            u=pb;
            pb=pb->next;
            free(u);
        }
        pc->next=NULL;//结果链表尾指针设为NULL
        free(lb);
        return la;//返回la头结点的链表
    }


    //9.判断循环双链表是否对称
    int Symmetry(DLinkList L){
        DNode *p=L->next,*q=L->prior;
        while(p!=q&&q->next!=p){
            p=p->next;
            q=q->prior;
        }
        else
            return 0;
        return 1;//比较结束后返回1
    }
    //tips: 一定要写成q->next!=p,不然偶数个，最后两个点没有遍历就跳出循环了

};