#include<stdio.h>
#include<string.h>
#define MAXSIZE 255
#define OK 1
#define ERROR 0


typedef struct{
	char ch[MAXSIZE+1];	//从1开始存储，索引0闲置不用
	int length;	//串当前大小 
}SString;


//初始化串
int StringCreate(SString &C,int n){
	C.length=0;
	for(int i=1;i<=n;i++){
		printf("请输入第%d个元素\n",i);
		scanf("%c",&C.ch[i]);
		getchar();
		C.length++;
	}
}



/*通过计算返回子串T的next数组。*/
//由于主串最长前缀=子串最长后缀，等价于求子串最长前缀=子串最长后缀
void get_next(SString s, int *next)
{
    int i=1,j=0;
    next[0]=-1;
    next[1]=0;
    while (i<s.length)
    {
        /* code */
        if(j==0||s.ch[i]==s.ch[j]){
            i++;
            j++;

            next[i]=j;//存储i前的最长前缀

        }
        else{
            //回溯
            j=next[j];
        }
    }
    

}

int KMP(SString M,SString T,int pos)
{
    int next[MAXSIZE+1];
    int i=pos;
    int j=0;

    get_next(T,next);


    for(int k=0;k<T.length;k++){
        printf("%d",next[k]);
    }

    while(i<=M.length&&j<=T.length){
        if(M.ch[i]==T.ch[j]||j==0){
            ++i;
            ++j;
        }
        else{
            j=next[j];
        }
    }
     printf("%s","\r\n");
 printf("%d",j);
      printf("%s","\r\n");
 printf("%d",i);
      printf("%s","\r\n");
    if(j>=T.length){
        printf("%s","111");
        return i-T.length;
    }
    else{
                printf("%s","222");
        return 0;
    }
}



int main(){
    SString T;
    SString M;
    int n=6;
    int m=9;
    StringCreate(T,n);
    StringCreate(M,m);
    int pos=0;
    int res=KMP(M,T,pos);
    printf("%s","搜索位置为");
    printf("%d",res);


}