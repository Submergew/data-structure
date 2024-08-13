
#include <stdio.h>
#include <stdlib.h>

#define Status int
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int SElemType; // 假设栈的元素类型为 int

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack *S) {
    // 动态分配内存给栈
    (*S).base = (SElemType *)malloc(MAXSIZE * sizeof(SElemType)); // 或者S.base = new SElemType[MAXSIZE
;    if (!(*S).base) return ERROR; // 检查内存分配是否成功
    (*S).top = (*S).base; // 初始化栈顶指针  栈空： top = base
    (*S).stacksize = MAXSIZE; // 设置栈的大小
    return OK;
}

int main() {
    SqStack S;
    if (InitStack(&S) == ERROR) {
        printf("Stack initialization failed.\n");
        return ERROR;
    }

    return 0;
}