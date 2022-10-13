#include <iostream>
#include <queue>
using namespace std;

bool BFSvisited[50];  //标记结点是否被访问过

//边
typedef struct Edge{
    int adj;	//邻接点对应的的下标 
    Edge *next;	//指向下一个结点 
}Edge;
 
//顶点
typedef struct{
    int data;	//顶点信息 
    Edge *first;	//指向第一个邻接点 
}Node;

//图
typedef struct{
    Node Node[15];	//顶点 
    int numVertex, numEdge;	//顶点数，边数 
}Graph;

//遍历，直到找到该顶点在图中的存储位置（即下标） 
int local(Graph G, int val){
    for(int i=0; i<G.numVertex; i++){
        if(G.Node[i].data == val)
            return i;	//返回该顶点在图中的存储位置
    }
    return -1;
}

void CreateGraph(Graph &G){	//创建图，用邻接表存储 
    cout << "请输入顶点数和边数:";
    cin  >> G.numVertex >> G.numEdge;
    for(int i=0; i<G.numVertex; i++){
		G.Node[i].data = i+1;	//结点信息初始化，也可以自己输入
		G.Node[i].first = NULL;
	}
	
	int v1, v2;
	cout << "请输入每条边的起点和终点:" << endl;
    for(int k=0; k<G.numEdge; k++){
        cin >> v1 >> v2;	//输入起点和终点的顶点信息 
        int src = local(G, v1);	
        int des = local(G, v2);
        if(G.Node[src].first == NULL){	//该结点的第一个邻接结点为空时 
            Edge *e = new Edge;
            e->adj = des;
            e->next = NULL;
            G.Node[src].first = e;	//给第一个邻接结点赋值 
        }
        else{	//该结点的第一个邻接结点不为空时
            Edge *p = G.Node[src].first;
            while(p->next != NULL){
                p = p->next;	//先循环到最后一个邻接节点处 
            }
            Edge *e = new Edge;
            e->adj = des;
            e->next = NULL;
            p->next = e;	//再在最后添加一个新的邻接节点 
        }
    }
}

void Print(Graph G){	//按下标输出各个顶点信息 
    cout<<"所建立的邻接表如以下所示："<<endl;
    for(int i=0; i<G.numVertex; i++){
        cout << "[" << i << "]" << ")";	//先输出顶点信息
        Edge *e = G.Node[i].first;
        while(e){	//然后就开始遍历输出每个结点的信息 
            cout << "-->" << "[" << e->adj << "]";
            e = e->next;
        }
        cout << endl;
    }
}

void BFSTraverse(Graph G){	//广度搜索 
    queue<int> q;	//定义队列 
    for(int i=0; i<G.numVertex; i++)
        BFSvisited[i] = false;	//全部结点设为未访问过 
    for(int i=0; i<G.numVertex; i++){
        if(!BFSvisited[i]){
            BFSvisited[i] = true;	//标记为已访问，然后输出 
            cout << endl << "广度遍历：" << G.Node[i].data << " ";
            q.push(i);	
            while(!q.empty()){
                int count = q.front();
                q.pop();
                Edge *p = G.Node[count].first;	//指向下标为count的第一个邻接节点 
                while(p){
                    if(!BFSvisited[p->adj]){	//若结点未访问过 
                        BFSvisited[p->adj] = true;
                        cout << G.Node[p->adj].data << " ";
                        q.push(p->adj);
                    }
                    p = p->next;
                }
            }
        }
    }
}

int main(){
	Graph G;
	CreateGraph(G);
	BFSTraverse(G);
	return 0;
}
