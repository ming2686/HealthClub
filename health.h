#ifndef _health_h
#define _health_h
#include "common.h"

Node *create();
Node2 *create2();
void printNode(Node *);
void printNode2(Node2 *);

void lodedata(Node2 *, Node *);

int menu(); //[1]ȸ������ [2]�����ϱ� [3]�����ϱ�
struct member join(Node *);//ȸ������ 
void addNode(Node *, struct member);

int entrance(Node2 *, Node *, char *);//�����ϱ� 
int searchNode(Node *, char *, int, char *);

void menu_sub(Node2 *, Node *, char *); //while [1]��ϱ� [2]��� Ȯ���ϱ� [3]ȸ��Ż�� [4]���ϱ�� [5]�����ϱ�
int exercisemenu();//[1]��ϱ� [2]��� Ȯ���ϱ� [3]ȸ��Ż�� [4]���ϱ�� [5]�����ϱ�

void exercisemenu_sub(Node2 *, Node *, char *, int *);//while (1) ���帮��Ʈ(2) ��ġ������ (3) ����Ʈ //���Ƚ�� ����ϱ� 
int exercise(); //[1]��ϱ� (1) ���帮��Ʈ(2) ��ġ������ (3) ����Ʈ
void searchNode2(Node2 *, Node *, char *, int);
void addNode2(Node2 *, struct health);

void check(Node2 *, Node *, char *);//��� Ȯ�� 

int drop(Node2 *, Node *, char *, int *);//ȸ��Ż�� 
void Nodedelete(Node2 *, Node *, char *, int *);

void memberrecord(Node *, char *);
void historyrecord(Node2 *, char *);//���� ����ϱ� 

void err();//����
 
 #endif
