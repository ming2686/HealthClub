#ifndef _common_h
#define _common_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member{
	char name[20]; //�̸�
	char phone[20]; //��ȭ��ȣ 
	int height; //Ű	
	double weight; //������ 
	double targetweight; //��ǥ ���� 
	char sickness[30]; //�������� 
};

struct health{
	char phone[20]; //��ȭ��ȣ 
	
	int deadlift; //���帮��Ʈ 
	int benchpress; //��ġ������ 
	int squats;//����Ʈ 
};

typedef struct node {
	struct member data;
	struct node *link;
}Node; //����� ���� ��� 

typedef struct node2 {
	struct health data2;
	struct node2 *link2; 
}Node2; //����� ���� ��� 

#endif
