#ifndef _common_h
#define _common_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member{
	char name[20]; //이름
	char phone[20]; //전화번호 
	int height; //키	
	double weight; //몸무게 
	double targetweight; //목표 몸무 
	char sickness[30]; //질병사항 
};

struct health{
	char phone[20]; //전화번호 
	
	int deadlift; //데드리프트 
	int benchpress; //벤치프레스 
	int squats;//스쿼트 
};

typedef struct node {
	struct member data;
	struct node *link;
}Node; //멤버에 대한 노드 

typedef struct node2 {
	struct health data2;
	struct node2 *link2; 
}Node2; //운동량에 대한 노드 

#endif
