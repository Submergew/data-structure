//
// Created by wangz on 2024/8/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024  //队列最大大小
typedef void * SeqQueue;
//初始化队列
SeqQueue init_SeqQueue();
//入队
void push_SeqQueue(SeqQueue queue,void *data);
//出队
void pop_SeqQueue(SeqQueue queue);
//返回队头
void *front_SeqQueue(SeqQueue queue);
//返回队尾
void *back_SeqQueue(SeqQueue queue);
//返回队列大小
int size_SeqQueue(SeqQueue queue);
//判断队列是否为空
int isEmpty(SeqQueue queue);
//销毁队列
void destroy_SeqQueue(SeqQueue queue);



int main()
{


    return 0;
}