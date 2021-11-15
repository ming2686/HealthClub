#include "common.h"
#include "health.h"

#define DEADLEFT 15
#define BENCHPRESS 15
#define SQUARTS 15
//몸무게 0.01kg 감소를 위한 기준은 (1)데드리프트 15회, (2)벤치프레스 15회, (3)스쿼트 15회 입니다. 

void lodedata(Node2 *L2, Node *L){
	FILE *ifp, *ofp;
	struct health h;
	struct member memb;
	int res;
	
	ifp=fopen("member.txt", "r"); //읽기전용으로 개방 
	if(ifp==NULL){
	//	printf("출력 파일 개방 실패.\n");
		return ; 
	}
	while(1){
		res=fscanf(ifp,"%s%s%d%lf%lf%s", memb.name, memb.phone, &memb.height, &memb.weight, &memb.targetweight, memb.sickness);		
		if(res==EOF) break;
		addNode(L, memb);

	}
	fclose(ifp);	
	
	ofp=fopen("history.txt", "r"); //읽기전용으로 개방
	if(ifp=NULL){
	//	printf("출력 파일 개방 실패.\n");
		return ; 
	}
	while(1){
		res=fscanf(ofp,"%s%d%d%d", h.phone, &h.deadlift, &h.benchpress, &h.squats);	
		if(res==EOF) break;
		addNode2(L2, h);
	
	}

	fclose(ofp);
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
	scanf("%lf",&t.weight);
	printf("(5) 목표 몸무게 : ");
	scanf("%lf",&t.targetweight);
	printf("(6) 질병사항 : ");
	scanf("%s",t.sickness);
	printf("\n");
	
 	return t;
 }
 
 int entrance(Node2 *L2, Node *L, char *check_p){
	char checkphone[20];
	char checkname[20];
	
	int check=0;
	
	printf("[2]입장하기\n"); 

	printf("(1) 전화번호 : "); //동명이인이 있을 수 있으니 전화번호로 먼저 check 
	scanf("%s", checkphone);

	if(searchNode(L, checkphone, 1, check_p)==1){
		strcpy(check_p, checkphone);
		
		printf("(2) 이름 :");
		scanf("%s", checkname);
		if(searchNode(L, checkname, 2, check_p)==2){
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

int searchNode(Node *L, char *srch, int method, char *check_p){ //char 이름, 전화번호 
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
			if(strcmp(p->data.name,srch)==0){ //이름이랑 데이터가 같을때 
				if(strcmp(p->data.phone,check_p)==0){
					check=2;
				}
			}
		}
	}
	
	return check;
}
