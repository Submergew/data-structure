//
// Created by wangz on 2024/8/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//节点结构体
struct LinkNode
{
    struct LinkNode * next;
};

//队列结构体
struct LQueue
{
    struct LinkNode pHeader; //头节点
    int m_Size;  //队列大小
    struct LinkNode * pTail; //尾节点指针

};

typedef void * LinkQueue;

//初始化队列
LinkQueue init_LinkQueue();
//入列
void push_LinkQueue(LinkQueue queue);
//出列
void pop_LinkQueue(LinkQueue queue);
//返回对头
void *front_LinkQueue(LinkQueue queue);
//返回队尾
void *back_LinkQueue(LinkQueue queue);
//返回队列大小
int size_LinkQueue(LinkQueue queue);
//判断是否为空
int isEmpty(LinkQueue queue);
//销毁队列
void destroy_LinkQueue(LinkQueue queue);