# 排序函数

<!-- vscode-markdown-toc -->
* 1. [索引与位序](#)
* 2. [交换两个数据位置](#-1)
* 3. [打印数组](#-1)
* 4. [冒泡排序](#-1)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name=''></a>索引与位序
```c
#define LENGTH2INDEX(x) (x-1);
#define INDEX2LENGTH(x) (x+1);
```

##  2. <a name='-1'></a>交换两个数据位置
```c
void swap_int(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
```

##  3. <a name='-1'></a>打印数组

```c
void print_int_array(int *array, int length)
{
    int index = LENGTH2INDEX(length);
    for (int i = 0; i <= index; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

```

##  4. <a name='-1'></a>冒泡排序

```c
/*
@brief 冒泡排序
    时间复杂度 O(n^2)
    稳定
    空间复杂度 O(1)
@param int* array 数组
@param int length 位序
    与索引不同
@return 无
*/
void bubble_sort(int *array, int length)
{
    int max_index = LENGTH2INDEX(length);
    /* 确定排序趟数 max_index - 1 */
    for (int i = max_index; i > 0; i--)
    {
        /* 确定比较的元素个数 其中 i是此趟排序确定的 索引 */
        for (int j = 1; j <= i; j++)
        {
            array[j] > array[j - 1] ?: swap_int(&array[j], &array[j - 1]);
        }
    }
}
```