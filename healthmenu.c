#include "common.h"
#include "health.h"

#define DEADLEFT 15
#define BENCHPRESS 15
#define SQUARTS 15
//몸무게 0.01kg 감소를 위한 기준은 (1)데드리프트 15회, (2)벤치프레스 15회, (3)스쿼트 15회 입니다. 

enum running { RUN=1, CHECK, DROP, FSAVE, QUIT}; 

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

Node2 *create2(){
	Node2 *L2 = (Node2*)malloc(sizeof(Node2));
	
	strcpy(L2->data2.phone, ""); //전화번호 초기화 
	
	L2->data2.deadlift=0; //데드리프트 초기화 
	L2->data2.benchpress=0; //벤치프레스 초기화 
	L2->data2.squats=0; //스쿼트 초기화 
	
	L2->link2=NULL;	
	
	return L2;
}

void printNode(Node *L){
	Node *p;
	 
	p=L;
	while(p->link!=NULL){
		p=p->link;
		printf("이름 : %s\n", p->data.name);
		printf("전화번호 : %s\n", p->data.phone);
		printf("키 : %d\n", p->data.height);
		printf("몸무게 : %.2lf\n", p->data.weight);
		printf("목표 몸무게 : %.2lf\n", p->data.targetweight);
		printf("질병사항 : %s\n", p->data.sickness);
		printf("\n");
	}
	printf("\n");
}

void printNode2(Node2 *L2){
	Node2 *p;
	 
	p=L2;
	
	while(p->link2!=NULL){
		p=p->link2;
		printf("전화번호 : %s\n", p->data2.phone);
		printf("데드리프트 : %d\n", p->data2.deadlift);
		printf("벤치프레스 : %d\n", p->data2.benchpress);
		printf("스쿼트 : %d\n", p->data2.squats);
		printf("\n");
	}
	printf("\n");
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

void addNode2(Node2 *L2, struct health h){
	Node2 *p, *n;
	
	n=create2();
	n->data2=h;

	p=L2;
	while(p->link2!=NULL){
		p=p->link2;
	}
	p->link2=n;
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

void menu_sub(Node2 *L2, Node *L, char *check_p){
	
	enum running num;
	int count01=0;
	 
	while((num=exercisemenu())!=QUIT){
		switch(num){
			case RUN:
				exercisemenu_sub(L2, L, check_p, &count01);
				printNode2(L2);
				break;
			case CHECK:
				check(L2, L, check_p);
				break;
			case DROP:
				if(drop(L2, L, check_p, &count01)==1){
					return ;
				}
				break;
			case FSAVE:
				memberrecord(L, check_p);
				historyrecord(L2, check_p);
				printf("\n");
				break;
			default:
				err();
				break;
		}
	}

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

void exercisemenu_sub(Node2 *L2, Node *L, char *check_p, int *count01){
	struct health h;
	strcpy(h.phone,check_p);
	int check=0;
	int n[3]={0};
	char yn[20];
	
	printf("(1) 데드리프트 횟수 :");
	scanf("%d", &n[0]);
	while(1){
		printf("fin (Y/N) :");
		scanf("%s", yn);
		if(strcmp(yn, "Y")==0){
			if(n[0]>=DEADLEFT){
				h.deadlift=n[0];
				check++;
				break;
			}
			else{
				h.deadlift=0;
				break;
			}
		}
		else if(strcmp(yn, "N")==0){
			h.deadlift=0;
			break;
		}
		else{
			printf("'Y' or 'N'로 입력해주세요.\n"); 
		}
	}
	printf("\n");
	printf("(2) 벤치프레스 횟수 :");
	scanf("%d", &n[1]);
	while(1){
		printf("fin (Y/N) :");
		scanf("%s", yn);
		if(strcmp(yn, "Y")==0){
			if(n[1]>=BENCHPRESS){
				h.benchpress=n[1];
				check++;
				break;
			}
			else{
				h.benchpress=0;
				break;
			}
		}
		else if(strcmp(yn, "N")==0){
			h.benchpress=0; 
			break;
		}
		else{
			printf("'Y' or 'N'로 입력해주세요.\n"); 
		}
	}
	printf("\n");
	printf("(3) 스쿼트 횟수 :");
	scanf("%d", &n[2]);
	while(1){
		printf("fin (Y/N) :");
		scanf("%s", yn);
		if(strcmp(yn, "Y")==0){
			if(n[2]>=SQUARTS){
				h.squats=n[2];
				check++;
				break;
			}
			else{
				h.squats=0;
				break;
			}
		}
		else if(strcmp(yn, "N")==0){
			h.squats=0;
			break;
		}
		else{
			printf("'Y' or 'N'로 입력해주세요.\n"); 
		}
	}
	printf("\n");
	(*count01)++;
	if(check==3){
		searchNode2(L2, L, check_p, 0);
	}
	else{
		searchNode2(L2, L, check_p, 1);
	}

	addNode2(L2, h);
}

void searchNode2(Node2 *L2, Node *L, char *check_p, int check){ //회원 phone으로 확인하여 몸무게 계산하기 
	struct health h;
	struct member m;
		
	h.deadlift=0;
	h.benchpress=0;
	h.squats=0;
	
	Node *p;
	p=L;
	
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.phone,check_p)==0){
			if(check==0){
				if(p->data.targetweight+0.01<=p->data.weight){
					p->data.weight = p->data.weight - 0.01;
					printf("운동에 성공했습니다!! 0.01kg 감량하였습니다!!\n\n");
				}
				else{
					printf("목표 몸무게 달성에 성공하였습니다!!\n\n");
					return ; 
				}
				break;
			}
			if(check==1){
				p->data.weight = p->data.weight + 0.02;
				printf("운동에 실패했습니다.. 0.02kg 증량하였습니다..\n\n");
				break;
			}	
		}
	}
	
}


