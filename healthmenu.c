#include "common.h"
#include "health.h"

#define DEADLEFT 15
#define BENCHPRESS 15
#define SQUARTS 15
//������ 0.01kg ���Ҹ� ���� ������ (1)���帮��Ʈ 15ȸ, (2)��ġ������ 15ȸ, (3)����Ʈ 15ȸ �Դϴ�. 

enum running { RUN=1, CHECK, DROP, FSAVE, QUIT}; 

Node *create(){
	Node *L = (Node*)malloc(sizeof(Node));
	
	strcpy(L->data.name, ""); //�̸� �ʱ�ȭ 
	strcpy(L->data.phone, ""); //��ȭ��ȣ �ʱ�ȭ 
	L->data.height=0; //Ű �ʱ�ȭ 
	L->data.weight=0; //������ �ʱ�ȭ 
	strcpy(L->data.sickness, ""); //�������� �ʱ�ȭ 
	
	L->link=NULL;	
	
	return L;
}

Node2 *create2(){
	Node2 *L2 = (Node2*)malloc(sizeof(Node2));
	
	strcpy(L2->data2.phone, ""); //��ȭ��ȣ �ʱ�ȭ 
	
	L2->data2.deadlift=0; //���帮��Ʈ �ʱ�ȭ 
	L2->data2.benchpress=0; //��ġ������ �ʱ�ȭ 
	L2->data2.squats=0; //����Ʈ �ʱ�ȭ 
	
	L2->link2=NULL;	
	
	return L2;
}

void printNode(Node *L){
	Node *p;
	 
	p=L;
	while(p->link!=NULL){
		p=p->link;
		printf("�̸� : %s\n", p->data.name);
		printf("��ȭ��ȣ : %s\n", p->data.phone);
		printf("Ű : %d\n", p->data.height);
		printf("������ : %.2lf\n", p->data.weight);
		printf("��ǥ ������ : %.2lf\n", p->data.targetweight);
		printf("�������� : %s\n", p->data.sickness);
		printf("\n");
	}
	printf("\n");
}

void printNode2(Node2 *L2){
	Node2 *p;
	 
	p=L2;
	
	while(p->link2!=NULL){
		p=p->link2;
		printf("��ȭ��ȣ : %s\n", p->data2.phone);
		printf("���帮��Ʈ : %d\n", p->data2.deadlift);
		printf("��ġ������ : %d\n", p->data2.benchpress);
		printf("����Ʈ : %d\n", p->data2.squats);
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
	
	printf("[�������� �ｺŬ�� ������Ʈ��]\n");  
	printf("[1]ȸ������\n"); 
	printf("[2]�����ϱ�\n");
	printf("[3]�����ϱ�\n");
	printf("��ȣ�� �Է��ϼ��� :"); 
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
	
	printf("[�������� �ｺŬ�� ������Ʈ��]\n");  
	printf("[1]��ϱ�\n"); 
	printf("[2]��� Ȯ���ϱ�\n"); 
	printf("[3]ȸ��Ż��\n"); 
	printf("[4]���ϱ��\n"); 
	printf("[5]�����ϱ�\n"); 
	printf("��ȣ�� �Է��ϼ��� :"); 
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
	
	printf("(1) ���帮��Ʈ Ƚ�� :");
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
			printf("'Y' or 'N'�� �Է����ּ���.\n"); 
		}
	}
	printf("\n");
	printf("(2) ��ġ������ Ƚ�� :");
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
			printf("'Y' or 'N'�� �Է����ּ���.\n"); 
		}
	}
	printf("\n");
	printf("(3) ����Ʈ Ƚ�� :");
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
			printf("'Y' or 'N'�� �Է����ּ���.\n"); 
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

void searchNode2(Node2 *L2, Node *L, char *check_p, int check){ //ȸ�� phone���� Ȯ���Ͽ� ������ ����ϱ� 
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
					printf("��� �����߽��ϴ�!! 0.01kg �����Ͽ����ϴ�!!\n\n");
				}
				else{
					printf("��ǥ ������ �޼��� �����Ͽ����ϴ�!!\n\n");
					return ; 
				}
				break;
			}
			if(check==1){
				p->data.weight = p->data.weight + 0.02;
				printf("��� �����߽��ϴ�.. 0.02kg �����Ͽ����ϴ�..\n\n");
				break;
			}	
		}
	}
	
}


