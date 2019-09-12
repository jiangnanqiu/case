//
//链表解决约瑟夫环.c
//链表
//
//Created by heiheimeishaonan on 2019/8/5
//Copyright © 2019年 heiheimeishaonan.All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>

//定义链表的结构体
struct Node{
	int num;
	struct Node *next;
};

int main(){
	struct Node *head,*tail;	//声明头指针和尾指针
	int people,start,length;	//people表示参加游戏的人数，start表示从第几个人开始，length表示每次数几个人

	//规定约瑟夫环的一些基本变量，并且要求people大于0和people大于等于start
	do{
		printf("请输入你想要参加的人数，从第几名开始以及每次数的人数\n");
		scanf("%d",&people);
		scanf("%d",&start);
		scanf("%d",&length);
		if(people<=0)
			printf("People must be more than 0!\n");
		if(people<start)
			printf("People must be more than start!\n");
	}while(people<=0 && people<start);

	//初始化约瑟夫环
	head = tail = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->num = 1;
	head->next = head;	//让head自己成一个环
	tail = head;
	//对head环进行插入
	int i;
	for(i=2 ;i<=people;i++){
		struct Node* new = (struct Node*)malloc(sizeof(struct Node));
		new->num = i;
		new->next = tail->next;	//新节点指向尾节点的下一个节点
		tail->next = new;	//将新节点接在尾节点后面
		tail = new;	//移动尾节点
	}

	//定义当前的，上一个的和淘汰的人
	struct Node* cur = NULL;
	struct Node* prev = NULL;
	struct Node* del = NULL;

	//当people==1时
	if(people==1){
		printf("The last one is %d",head->num);
	}

	//当people!=1,length==1,start==1时
	else if(people!=1 && length==1 && start==1){
		cur = head;
		//从头节点开始逐个删除
		while(head->next != head){
			del = cur;
			cur = head = del->next;
			tail->next = head;
			printf("In this turn we delete %d\n",del->num);
			free(del);
		}
		printf("The last one is %d\n",cur->num);
	}

	//剩下的情况
	else{
		cur = prev = head;
		//将prev移动到要start的前一个人
		for(i=1;i<start-1;i++){
			prev = prev->next;
		}
		//将cur移动到start
		for(i=1;i<start;i++){
			cur = cur->next;
		}
		if(start == 1){
			prev = tail;
		}
		while(head->next != head){
			//按照length的步伐移动
			for(i=1;i<length;i++){
				prev = prev->next;
				cur = cur->next;
			}
			del = cur;
			prev->next = del->next;
			cur = cur->next;
			//如果删除的是头节点，就将头节点向后移一位
			if(del == head){
				head = head->next;
			}
			printf("In this turn we delete %d\n",del->num);
			free(del);
		}
		printf("The last one is %d\n",head->num);
	}
	return 0;
}
