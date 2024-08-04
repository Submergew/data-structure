//
// Created by wangz on 2024/8/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 假设的动态数组结构体
typedef struct {
    int *pAddr;    // 数组的指针
    int m_Size;    // 数组的当前大小
} dynamicArry;

// 删除数组中指定位置的元素
void removeByPos_dynamicArry(dynamicArry *arr, int pos) {
    if (arr == NULL || arr->pAddr == NULL) {
        return; // 无效的数组或指针
    }
    if (pos < 0 || pos >= arr->m_Size) {
        return; // 无效的位置
    }

    // 从pos位置开始，将后面的元素向前移动一位
    for (int i = pos; i < arr->m_Size - 1; i++) {
        arr->pAddr[i] = arr->pAddr[i + 1];
    }

    // 减少数组大小
    arr->m_Size--;

    // 重新分配数组大小（如果需要）
    arr->pAddr = (int *)realloc(arr->pAddr, arr->m_Size * sizeof(int));
}

int main() {
    // 创建并初始化一个动态数组
    dynamicArry arr;
    arr.pAddr = (int *)malloc(5 * sizeof(int));
    arr.m_Size = 5;
    for (int i = 0; i < arr.m_Size; i++) {
        arr.pAddr[i] = i + 1; // 填充一些数据
    }

    // 打印原始数组
    printf("Original array: ");
    for (int i = 0; i < arr.m_Size; i++) {
        printf("%d ", arr.pAddr[i]);
    }
    printf("\n");

    // 删除数组中的第二个元素（索引为1）
    removeByPos_dynamicArry(&arr, 1);

    // 打印修改后的数组
    printf("Modified array: ");
    for (int i = 0; i < arr.m_Size; i++) {
        printf("%d ", arr.pAddr[i]);
    }
    printf("\n");

    // 释放动态数组的内存
    free(arr.pAddr);

    return 0;
}