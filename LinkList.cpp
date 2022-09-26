#include <stdio.h>
#include <stdlib.h>
 
struct Test
{
	int data;
	struct Test *next;
};
 
void printLinklist(struct Test *head) //验证链表打印函数
{
	struct Test *point = head;
	
	while(point != NULL)
	{
		printf("the data of the Linklist is:%d\n",point->data);
		point = point->next;
	}
}
 
struct Test* creatLinklistofBehind(struct Test *head)  //尾插法创建链表
{
	struct Test *now= NULL;
	struct Test *point = head;
	//head->data = 1;   //如果用方法一 便在头结点的data不存储数据
	
	while(1)  //循环建立链表
	{
        //动态申请一个名称为now的Node*指针类型的节点
		now = (struct Test*)malloc(sizeof(struct Test));
       
		now->next = NULL;             //初始化now的next指针为空指针，指向NULL 
		printf("Please Input the data to the newLink:\n");
		scanf("%d",&(now->data));     //对data进行赋值
		
		if(now->data == 0)            //当data=0 时退出
		{
			printf("the data is 0:Quit!\n");
			printf("\n");
			free(now);                //释放now指针
			return head;              //返回Test型指针
		}
		//注意如果用方法一 便动态建立头节点，并head ，point=now的操作要同时进行，保证两指针都是指向 相同头节点地址
		if(head == NULL)              
		{
			head = now;
            point=now;
		}
		else{
		    while(point->next != NULL)
	  	    {
				point = point->next;  //让point指针指向下一个结点，保证它指向链表尾部 
			}
			    point->next = now;    //让point指针指向的结点的next成员指向新建结点now
		}
    }
}
 
 
int main()
{
    //方法一 直接在creatLinklistofBehind 定义出头指针及其初始化
	struct Test *head = NULL;    
    //方法二 可以先动态申请一个名称为head的Test*指针类型的头节点
	/*head = (struct Test *)malloc(sizeof(struct Test));  
	head->next = NULL;            //初始化next=NULL
	*/
	head = creatLinklistofBehind(head);
 
   
	printLinklist(head);
	system("pause");
	return 0;
}