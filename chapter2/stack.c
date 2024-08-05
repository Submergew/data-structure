//
// Created by wangz on 2024/8/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 1024

struct Stack
{
    //栈中数组
    void * data[MAX];
    //栈大小
    int m_Size;
};

typedef void * SeqStack;

//初始化栈
SeqStack init_SeqStack()
{
    struct Stack* myStack = malloc(sizeof(struct Stack));
    if (myStack == NULL)
    {
        return NULL;
    }
    memset (myStack->data, 0, sizeof(void *)*MAX);
    myStack->m_Size = 0;
    return myStack;

}

//入栈
void push_SeqStack(SeqStack stack ,void *data)
{
    //本质 数组尾插
    if (stack = NULL)
    {
        return ;
    }
    if (data == NULL)
    {

        return;
    }
    struct Stack * myStack = stack;
    //判断栈是否满
    if (myStack->m_Size == MAX)
    {
        return;
    }
    //数组进行尾插
    myStack->data[myStack->m_Size] = data;
    //更新栈的大小
    myStack->m_Size++;

}
//出栈
void  pop_SeqStack(SeqStack stack)
{
    //出栈本质  数组尾删除

    if (stack == NULL)
    {
        return;
    }

    struct Stack * mystack = stack;

    if (mystack->m_Size == 0 )
    {
        return;
    }
    mystack->data[mystack->m_Size-1] = NULL;

    mystack->m_Size--;

}
//返回栈顶
void * top_SeqStack(SeqStack stack)
{
    //本质 返回数组的最后一个元素
    if(stack == NULL)
    {
        return NULL;
    }

    struct Stack* mystack = stack;
    if(mystack->m_Size == 0)
    {
        return NULL;
    }

    return mystack->data[mystack->m_Size-1];

}
//返回栈大小
int size_SeqStack(SeqStack stack)
{
    if (stack == NULL)
    {
        return 0;
    }
    struct Stack*mystack = stack;
    return mystack->m_Size;
}
//判断栈是否为空
int isEmpty_SeqStack(SeqStack stack)
{
    if (stack == NULL)
    {
        return -1; // 传入空指针 返回真 栈也是空
    }
    struct Stack*mystack = stack;
    if(mystack->m_Size == 0)
    {
        return 1;  // 1 代表真  栈确实为空
    }
    return 0; //不为空 假

}
//销毁
void destroy_SeqStack(SeqStack stack)
{
    if (stack == NULL)
    {
        return;
    }
    free(stack);
    stack = NULL;
}

struct Person
{
    char name[64];
    int age;
};


//测试栈
void test1()
{
    //创建栈
    SeqStack myStack = init_SeqStack();


    //创建数据
    struct Person p1 = {"aaa",11};
    struct Person p2 = {"bbb",22};
    struct Person p3 = {"ccc",33};
    struct Person p4 = {"ddd",44};
    struct Person p5 = {"eee",55};

    //入栈
    push_SeqStack(myStack,&p1);
    push_SeqStack(myStack,&p2);
    push_SeqStack(myStack,&p3);
    push_SeqStack(myStack,&p4);
    push_SeqStack(myStack,&p5);


    printf("栈的大小为:%d\n",size_SeqStack(myStack));



    while (isEmpty_SeqStack(myStack) == 0) //栈不为空 开始查看栈顶 并且出栈
    {
        struct Person *pTop  = top_SeqStack(myStack);
        printf("栈顶元素- 姓名:%s 年龄:%d\n",pTop->name,pTop->age);

        //出栈
        pop_SeqStack(myStack);

    }
    printf("栈的大小为:%d\n",size_SeqStack(myStack));
}


int main()
{

    test1();
    return 0;
}
