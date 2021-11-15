#include "common.h"
#include "health.h"

#define DEADLEFT 15
#define BENCHPRESS 15
#define SQUARTS 15
//몸무게 0.01kg 감소를 위한 기준은 (1)데드리프트 15회, (2)벤치프레스 15회, (3)스쿼트 15회 입니다. 

void check(Node2 *L2, Node *L, char *check_p){
	Node *p;
	p=L;

	Node2 *p01;
	p01=L2;
	
	printf("[2]운동량 확인하기\n"); 
	
	
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.phone,check_p)==0){ //전화번호랑 데이터가 같을때 
			printf("[%s님의 운동량]\n",p->data.name); 
		
				while(p01->link2!=NULL){
					p01=p01->link2;
					if(strcmp(p01->data2.phone,check_p)==0){
					printf("데드리프트 : %d\n", p01->data2.deadlift);
					printf("벤치프레스 : %d\n", p01->data2.benchpress);
					printf("스쿼트 : %d\n\n", p01->data2.squats);
					}
				}
			printf("%s님의 현재 몸무게는 %.2lf입니다.\n\n",p->data.name, p->data.weight);
		}
	}	
}

int drop(Node2 *L2, Node *L, char *check_p, int *count01){
	char yn[20];
	
	printf("[3]회원탈퇴\n"); 
	
	while(1){
		printf("회원탈퇴를 진행하시겠습니까?(Y/N) : ");
		scanf("%s", yn);
		if(strcmp(yn,"Y")==0){
			Nodedelete(L2, L, check_p, count01);
			return 1;
		}
		else if(strcmp(yn,"N")==0){
			printf("회원탈퇴를 중단합니다.\n\n\n");
			return 0; 
		}
		else{
			printf("'Y' or 'N'로 입력해주세요.\n"); 
		}
	}
	memberrecord(L,check_p);
	historyrecord(L2,check_p);

	printf("\n");
}

void Nodedelete(Node2 *L2, Node *L, char *check_p, int *count01){
 	Node *p, *k;
	p=L;
	//이동하는p를 가리키는k 
	int i;
	
	Node2 *p0, *k0;
	p0=L2;
	
	while(p->link!=NULL){ //회원 삭제하기 
		k=p;
		p=p->link;
		if(strcmp(p->data.phone,check_p)==0){	
			k->link=p->link;
			free(p);
			break; 
		}
	}

	for(i=0;i<*(count01);i++){
		p0=L2;
		while(p0->link2!=NULL){ //운동량 삭제하기 
		k0=p0;
		p0=p0->link2;
			if(strcmp(p0->data2.phone,check_p)==0){	
				k0->link2=p0->link2;
				free(p0);
				break;
	
			}
		}
	}

}

void memberrecord(Node *L, char *check_p){
	printf("[4]memeber 파일기록...\n"); 
	FILE *ofp;

	Node *p;
	 
	p=L;
	
	ofp=fopen("member.txt","w"); //쓰기 전용으로 개방
	if(ofp==NULL){
		printf("출력 파일 개방 실패.\n");
		return ; 
	}
	
	while(p->link!=NULL){
		p=p->link;
		fprintf(ofp,"%s\n", p->data.name);
		fprintf(ofp,"%s\n", p->data.phone);
		fprintf(ofp,"%d\n", p->data.height);
		fprintf(ofp,"%.2lf\n", p->data.weight);
		fprintf(ofp,"%.2lf\n", p->data.targetweight);
		fprintf(ofp,"%s\n", p->data.sickness);
	
	}
	
	fclose(ofp);
}

void historyrecord(Node2 *L2, char *check_p){
	printf("[4]history 파일기록...\n"); 
	FILE *ofp;
	int i;
	
	Node2 *p2;
	 
	p2=L2;

	ofp=fopen("history.txt","w"); //쓰기 전용으로 개방
	if(ofp==NULL){
		printf("출력 파일 개방 실패.\n");
		return ; 
	}
	
	while(p2->link2!=NULL){
		p2=p2->link2;
		fprintf(ofp,"%s\n", p2->data2.phone);
		fprintf(ofp,"%d\n", p2->data2.deadlift);
		fprintf(ofp,"%d\n", p2->data2.benchpress);
		fprintf(ofp,"%d\n", p2->data2.squats);
	}

	fclose(ofp);
}

void err(){
	printf("에러입니다.\n\n"); 
}
