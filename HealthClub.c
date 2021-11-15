#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member{
	char name[20]; //�̸�
	char phone[20]; //��ȭ��ȣ 
	int height; //Ű	
	int weight; //������ 
	int targetweight; //��ǥ ���� 
	char sickness[30]; //�������� 
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

struct member join(Node *);//ȸ������ 
void addNode(Node *, struct member);

int entrance(Node *, struct member);//�����ϱ� 
int searchNode(Node *, char *, int);

int exercise();//��ϱ� 
void check();//��� Ȯ�� 
void drop();//ȸ��Ż�� 
void record();//���� ����ϱ� 
void err();//����
 
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
	
	strcpy(L->data.name, ""); //�̸� �ʱ�ȭ 
	strcpy(L->data.phone, ""); //��ȭ��ȣ �ʱ�ȭ 
	L->data.height=0; //Ű �ʱ�ȭ 
	L->data.weight=0; //������ �ʱ�ȭ 
	strcpy(L->data.sickness, ""); //�������� �ʱ�ȭ 
	
	L->link=NULL;	
	
	return L;
}

void printNode(Node *L){
	Node *p;
	 
	p=L;
	while(p->link!=NULL){
		p=p->link;
		printf("�̸� : %s\n", p->data.name);
		printf("��ȭ��ȣ : %s\n", p->data.phone);
		printf("Ű : %d\n", p->data.height);
		printf("������ : %d\n", p->data.weight);
		printf("��ǥ ������ : %d\n", p->data.targetweight);
		printf("�������� : %s\n", p->data.sickness);
		printf("\n");
	}
	printf("\n");
}

 struct member join(Node *L){
 	struct member t;
 	
	Node *p;
	
	int check=0;
	
 	printf("[1]ȸ������\n"); 
	printf("(1) ���� : ");
	scanf("%s",t.name);
	while(1){
		printf("(2) ��ȭ��ȣ : ");
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
			printf("�ߺ��� ��ȭ��ȣ�� �ֽ��ϴ�!! �ٽ��Է��ϼ���!!\n");
		}
		else break;
	}
	printf("(3) Ű : ");
	scanf("%d",&t.height);
	printf("(4) ������ : ");
	scanf("%d",&t.weight);
	printf("(5) ��ǥ ������ : ");
	scanf("%d",&t.targetweight);
	printf("(6) �������� : ");
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
	
	printf("[2]�����ϱ�\n"); 

	printf("(1) ��ȭ��ȣ : "); //���������� ���� �� ������ ��ȭ��ȣ�� ���� check 
	scanf("%s", checkphone);

	if(searchNode(L, checkphone, 1)==1){
		printf("(2) �̸� :");
		scanf("%s", checkname);
	
		if(searchNode(L, checkname, 2)==2){
			printf("ȸ������Ȯ�� �Ϸ�!! ���尡���մϴ�!!\n\n"); 
			return 1;	
		}
		else{
			printf("���Ե� �̸��� ��ȭ��ȣ�� ��ġ���� �ʽ��ϴ�!! ������ �̿��ϼ���!!\n\n"); 
			return 0;
		}
	}
	
	else{
		printf("���Ե� ��ȭ��ȣ�� �����ϴ�!! ������ �̿��ϼ���!!\n\n"); 
		return 0;
	}
}

int searchNode(Node *L, char *srch, int method){ //char �̸�, ��ȭ��ȣ 
	Node *p;
	p=L;
	int check=-1;
	
	while(p->link!=NULL){
		p=p->link;
		if(method==1){
			if(strcmp(p->data.phone,srch)==0){ //��ȭ��ȣ�� �����Ͱ� ������ 
				check=1;
			}
		}
		if(method==2){
			if(strcmp(p->data.name,srch)==0){ //��ȭ��ȣ�� �����Ͱ� ������ 
				check=2;
			}
		}
	}
	
	return check;
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
	
	printf("[1]��ϱ�\n"); 
	printf("(1) ���帮��Ʈ\n");
	printf("(2) ��ġ������\n");
	printf("(3) ����Ʈ\n");
	printf("(4) �����ϱ�;\n\n");
	
	return num;	
}

void ex_deadlift(){
	printf("[���帮��Ʈ]\n");
	/*
	��ȸ�����Է¹ް�
	10
	�����߽��ϱ�? y -> -0.001
	 n-> +0.002 
	*/
}

void ex_benchpress(){	
	printf("[��ġ������]\n");
}

void ex_squats(){
	printf("[����Ʈ]\n");
}


void check(){
	
	printf("[2]��� Ȯ���ϱ�\n"); 

}

void drop(){
	
	printf("[3]ȸ��Ż��\n"); 
	
}

void  record(){
	
	printf("[4]���ϱ��\n"); 

}

void err(){
	printf("�����Դϴ�.\n\n"); 
}
