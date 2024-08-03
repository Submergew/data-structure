
#include <stdio.h>
#include <stdlib.h>

// 动态数组结构体
struct dynamicArray
{
    // 真实在堆区开辟数组的指针
    void* pAddr; // 修改为 void* 而不是 void**
    // 数组容量
    int m_Capacity;
    // 数组大小
    int m_Size;
};

// 初始化数组
struct dynamicArray* init_dynamicArray(int capacity) // 修改函数名
{
    if(capacity <= 0)
    {
        return NULL;
    }

    // 给数组分配内存
    struct dynamicArray* arr = malloc(sizeof(struct dynamicArray));
    if (arr == NULL)
    {
        return NULL;
    }

    // 给属性初始化
    arr->pAddr = malloc(sizeof(void*) * capacity); // 这里应该是 sizeof(void*) 而不是 sizeof(void**)
    if (arr->pAddr == NULL)
    {
        free(arr); // 释放之前分配的内存
        return NULL;
    }

    // 容量初始化
    arr->m_Capacity = capacity;
    // 大小初始化
    arr->m_Size = 0;

    return arr;
}

// 释放动态数组内存的函数
void free_dynamicArray(struct dynamicArray* arr)
{
    if (arr)
    {
        free(arr->pAddr); // 释放数组元素内存
        free(arr); // 释放数组结构体内存
    }
}

int main()
{
    struct dynamicArray* myArray = init_dynamicArray(10);
    if (myArray)
    {
        // 使用 myArray 进行操作
        // ...

        free_dynamicArray(myArray); // 记得释放内存
    }

    return 0;
}