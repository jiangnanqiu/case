//
//链表解决约瑟夫环.c
//链表
//
//Created by heiheimeishaonan on 2019/8/11
//Copyright © 2019年 heiheimeishaonan.All rights reserved.
//
#include<stdio.h>

//快速排序的递归函数，array表示被排序的数组，head标记第一个数的位置，tail标记最后一个数的位置
void fastSort(int* array,int head,int tail){
	int baseNumber;	//找到的基准数的位置
	int changeNumber;	//要移动的数
	int left,right;	//用于标记左右边的数
	int temp;	//交换时的中间数
	baseNumber = head;
	left = head+1;
	right = tail;
	//递归出口
	if(left > right)
		return;
	if(left == right){
		if(array[baseNumber] > array[left]){
			int t = array[left];
			array[left] = array[baseNumber];
			array[baseNumber] = t;
		}
		return;
	}
	changeNumber = array[baseNumber];
	//进行快排
	while(left <= right){
		if(array[left] < changeNumber){
			left++;
			continue;
		}
		if(array[right] >= changeNumber){
			right--;
			continue;
		}
		temp = array[left];
		array[left] = array[right];
		array[right] = temp;
		left++;
		right--;
	}
	//将递归数移动到合适的位置
	for(int i=baseNumber+1;i<=right;i++){
		array[i-1] = array[i];
	}
	array[right] = changeNumber;
	//重复递归
	fastSort(array,head,right-1);
	fastSort(array,right+1,tail);
	return;
}

int main(int argc, char const *argv[])
{
	int a[100],num;	//定义排序数组以及数组元素个数
	printf("Please input the number of array:");
	scanf("%d",&num);
	printf("Please input the number in your array one by one:\n");
	for(int i=0;i<num;i++){
		scanf("%d",&a[i]);
	}
	fastSort(a,0,num-1);
	//打印排序好的结果
	for(int i=0;i<num;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}