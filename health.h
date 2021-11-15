#ifndef _health_h
#define _health_h
#include "common.h"

Node *create();
Node2 *create2();
void printNode(Node *);
void printNode2(Node2 *);

void lodedata(Node2 *, Node *);

int menu(); //[1]회원가입 [2]입장하기 [3]종료하기
struct member join(Node *);//회원가입 
void addNode(Node *, struct member);

int entrance(Node2 *, Node *, char *);//입장하기 
int searchNode(Node *, char *, int, char *);

void menu_sub(Node2 *, Node *, char *); //while [1]운동하기 [2]운동량 확인하기 [3]회원탈퇴 [4]파일기록 [5]종료하기
int exercisemenu();//[1]운동하기 [2]운동량 확인하기 [3]회원탈퇴 [4]파일기록 [5]종료하기

void exercisemenu_sub(Node2 *, Node *, char *, int *);//while (1) 데드리프트(2) 벤치프레스 (3) 스쿼트 //운동량횟수 기록하기 
int exercise(); //[1]운동하기 (1) 데드리프트(2) 벤치프레스 (3) 스쿼트
void searchNode2(Node2 *, Node *, char *, int);
void addNode2(Node2 *, struct health);

void check(Node2 *, Node *, char *);//운동량 확인 

int drop(Node2 *, Node *, char *, int *);//회원탈퇴 
void Nodedelete(Node2 *, Node *, char *, int *);

void memberrecord(Node *, char *);
void historyrecord(Node2 *, char *);//파일 기록하기 

void err();//에러
 
 #endif
