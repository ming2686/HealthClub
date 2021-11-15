#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member{
	char name[20]; //이름
	char phone[20]; //전화번호 
	int height; //키	
	int weight; //몸무게 
	int targetweight; //목표 몸무 
	char sickness[30]; //질병사항 
};

struct health{
	struct member m;
	
	int deadlift;
	int benchpress;
	int squats;
};

typedef struct node {
	struct member data;
	struct node *link;
}Node;

Node *create();
void printNode(Node *);

int menu();

void menu_sub();
int exercisemenu();

void exercisemenu_sub();

void exercise_checkmenu(); 
void ex_deadlift();
void ex_benchpress();
void ex_squats();

struct member join(Node *);//회원가입 
void addNode(Node *, struct member);

int entrance(Node *, struct member);//입장하기 
int searchNode(Node *, char *, int);

int exercise();//운동하기 
void check();//운동량 확인 
void drop();//회원탈퇴 
void record();//파일 기록하기 
void err();//에러
 
int main(int argc, char *argv[]) {
	struct health h;
	struct member memb;
	Node *L=create();
	
	int num;
	
	while((num=menu())!=3){
		switch(num){
			case 1:
				printNode(L);
				memb=join(L);
				addNode(L, memb);
				printNode(L);
				break;
			case 2:
				if(entrance(L, memb)==1){
					menu_sub();
				}
				break;
			default:
				err();
				break;
		}
	}
	return 0;
}

Node *create(){
	Node *L = (Node*)malloc(sizeof(Node));
	
	strcpy(L->data.name, ""); //이름 초기화 
	strcpy(L->data.phone, ""); //전화번호 초기화 
	L->data.height=0; //키 초기화 
	L->data.weight=0; //몸무게 초기화 
	strcpy(L->data.sickness, ""); //질병사항 초기화 
	
	L->link=NULL;	
	
	return L;
}

void printNode(Node *L){
	Node *p;
	 
	p=L;
	while(p->link!=NULL){
		p=p->link;
		printf("이름 : %s\n", p->data.name);
		printf("전화번호 : %s\n", p->data.phone);
		printf("키 : %d\n", p->data.height);
		printf("몸무게 : %d\n", p->data.weight);
		printf("목표 몸무게 : %d\n", p->data.targetweight);
		printf("질병사항 : %s\n", p->data.sickness);
		printf("\n");
	}
	printf("\n");
}

 struct member join(Node *L){
 	struct member t;
 	
	Node *p;
	
	int check=0;
	
 	printf("[1]회원가입\n"); 
	printf("(1) 성명 : ");
	scanf("%s",t.name);
	while(1){
		printf("(2) 전화번호 : ");
		scanf("%s",t.phone);
		check=0;	
		p=L;
		while(p->link!=NULL){
			p=p->link;
			if(strcmp(p->data.phone,t.phone)==0){
				check=1;
			}
		}
		if(check==1){
			printf("중복된 전화번호가 있습니다!! 다시입력하세요!!\n");
		}
		else break;
	}
	printf("(3) 키 : ");
	scanf("%d",&t.height);
	printf("(4) 몸무게 : ");
	scanf("%d",&t.weight);
	printf("(5) 목표 몸무게 : ");
	scanf("%d",&t.targetweight);
	printf("(6) 질병사항 : ");
	scanf("%s",t.sickness);
	printf("\n");
	
 	return t;
 }
 	

void addNode(Node *L, struct member data){
	Node *p, *n;
	
	n=create();
	n->data=data;
	
	p=L;
	while(p->link!=NULL){
		p=p->link;
	}
	p->link=n;
}

int entrance(Node *L, struct member data){
	struct member t;
	
	char checkphone[20];
	char checkname[20];
	
	int check=0;
	
	printf("[2]입장하기\n"); 

	printf("(1) 전화번호 : "); //동명이인이 있을 수 있으니 전화번호로 먼저 check 
	scanf("%s", checkphone);

	if(searchNode(L, checkphone, 1)==1){
		printf("(2) 이름 :");
		scanf("%s", checkname);
	
		if(searchNode(L, checkname, 2)==2){
			printf("회원정보확인 완료!! 입장가능합니다!!\n\n"); 
			return 1;	
		}
		else{
			printf("가입된 이름과 전화번호가 일치하지 않습니다!! 가입후 이용하세요!!\n\n"); 
			return 0;
		}
	}
	
	else{
		printf("가입된 전화번호가 없습니다!! 가입후 이용하세요!!\n\n"); 
		return 0;
	}
}

int searchNode(Node *L, char *srch, int method){ //char 이름, 전화번호 
	Node *p;
	p=L;
	int check=-1;
	
	while(p->link!=NULL){
		p=p->link;
		if(method==1){
			if(strcmp(p->data.phone,srch)==0){ //전화번호랑 데이터가 같을때 
				check=1;
			}
		}
		if(method==2){
			if(strcmp(p->data.name,srch)==0){ //전화번호랑 데이터가 같을때 
				check=2;
			}
		}
	}
	
	return check;
}

int menu(){
	int num=0;
	
	printf("[♡유밍의 헬스클럽 프로젝트♡]\n");  
	printf("[1]회원가입\n"); 
	printf("[2]입장하기\n");
	printf("[3]종료하기\n");
	printf("번호를 입력하세요 :"); 
	scanf("%d",&num);
	printf("\n");
	
	return num;
}

void menu_sub(){
	struct health h;
	struct member memb;
	
	int num;
	
	while((num=exercisemenu())!=5){
		switch(num){
			case 1:
				exercise();
				break;
			case 2:
				check();
				break;
			case 3:
				drop();
				break;
			case 4:
				record();
				break;
			default:
				err();
				break;
		}
	}
	
	return 0;
}

int exercisemenu(){
	int num=0;
	
	printf("[♡유밍의 헬스클럽 프로젝트♡]\n");  
	printf("[1]운동하기\n"); 
	printf("[2]운동량 확인하기\n"); 
	printf("[3]회원탈퇴\n"); 
	printf("[4]파일기록\n"); 
	printf("[5]종료하기\n"); 
	printf("번호를 입력하세요 :"); 
	scanf("%d",&num);
	printf("\n");
	 
	return num;
}

void exercisemenu_sub(){
	struct health h;
	struct member memb;
	
	int num;
	
	while((num=exercise())!=5){
		switch(num){
			case 1:
				exercise_checkmenu(); 
				break;
			case 2:
				check();
				break;
			case 3:
				drop();
				break;
			case 4:
				record();
				break;
			default:
				err();
				break;
		}
	}
	
	return 0;
}

void exercise_checkmenu(){
	struct health h;
	struct member memb;
	
	int num;
	
	while((num=exercise())!=4){
		switch(num){
			case 1:
				ex_deadlift();
				break;
			case 2:
				ex_benchpress();
				break;
			case 3:
				ex_squats();
				break;
			default:
				err();
				break;
		}
	}
	
	return 0;
}

int exercise(){
	int num;
	
	printf("[1]운동하기\n"); 
	printf("(1) 데드리프트\n");
	printf("(2) 벤치프레스\n");
	printf("(3) 스쿼트\n");
	printf("(4) 종료하기;\n\n");
	
	return num;	
}

void ex_deadlift(){
	printf("[데드리프트]\n");
	/*
	몇회할지입력받고
	10
	성공했습니까? y -> -0.001
	 n-> +0.002 
	*/
}

void ex_benchpress(){	
	printf("[벤치프레스]\n");
}

void ex_squats(){
	printf("[스쿼트]\n");
}


void check(){
	
	printf("[2]운동량 확인하기\n"); 

}

void drop(){
	
	printf("[3]회원탈퇴\n"); 
	
}

void  record(){
	
	printf("[4]파일기록\n"); 

}

void err(){
	printf("에러입니다.\n\n"); 
}
