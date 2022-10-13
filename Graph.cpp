#include <stdfix.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#define MAXSIZE 255
#define OK 1
#define ERROR 0
#define MaxVertexNum 100 //顶点数目的最大值
class Graph
{
public:
    //邻接矩阵
    typedef char VertexType; //顶点的数据类型
    typedef int EdgeType;    //带权图边上权值的数据类型
    typedef struct
    {
        VertexType Vex[MaxVertexNum];              //顶点
        EdgeType Edge[MaxVertexNum][MaxVertexNum]; //领接矩阵，边表
        int vexnum, arcnum;                        //当前顶点数，和弧数
    } MGraph;
    //邻接表
    typedef struct ArcNode
    {
        //边表结点
        int adjvex;           //该弧所指向的顶点位置
        struct ArcNode *next; //指向下一条弧的指针
        // InfoType info; //网的边权值
    } ArcNode;

    typedef struct VNode
    {
        //顶点表结点
        VertexType data; //顶点信息
        ArcNode *first;  //指向第一条依附于该顶点的弧的指针
    } VNode, AdjList[MaxVertexNum];

    typedef struct
    {
        AdjList vertices;   // 邻接表
        int vexnum, arcnum; //顶点数和弧数
    } ALGraph;              //邻接表

    // BFS
    bool visited[MaxVertexNum];
    void BFSTraverse(MGraph G)
    {
        //对图G进行广度优先遍历
        for (int i = 0; i < G.vexnum; i++)
        {
            visited[i] = false; //访问标记数组初始化
        }

        InitQueue(Q); //初始化辅助队列Q

        for (int i = 0; i < G.vexnum; i++)
        {                    //从0号顶点开始遍历
            if (!visited[i]) //对每个连通分量调用一次BFS
                BFS(G, i);   // Vi未访问过，从Vi开始访问BFS
        }
    }

    void BFS(Graph G, int v)
    {
        //从顶点V出发，广度优先遍历图G
        visit(v);          //访问初始顶点v
        visited[v] = true; //对v做已访问标记

        Enqueue(Q, v); //顶点v入队列Q

        while (!isEmpty(Q))
        {
            //当队列不为空时
            DeQueue(Q, v); //顶点v出队列
            for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
            {
                //检测v所有邻接点
                if (!visited[w])
                {
                    // w为v的尚未访问的邻接顶点
                    visit(w);          //访问顶点w
                    visited[w] = true; //对w做已访问标记
                    EnQueue(Q, w);     //顶点w入队列
                }
            }
        }
    }
};