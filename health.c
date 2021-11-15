#include "common.h"
#include "health.h"

#define DEADLEFT 15
#define BENCHPRESS 15
#define SQUARTS 15
//������ 0.01kg ���Ҹ� ���� ������ (1)���帮��Ʈ 15ȸ, (2)��ġ������ 15ȸ, (3)����Ʈ 15ȸ �Դϴ�. 

void check(Node2 *L2, Node *L, char *check_p){
	Node *p;
	p=L;

	Node2 *p01;
	p01=L2;
	
	printf("[2]��� Ȯ���ϱ�\n"); 
	
	
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.phone,check_p)==0){ //��ȭ��ȣ�� �����Ͱ� ������ 
			printf("[%s���� ���]\n",p->data.name); 
		
				while(p01->link2!=NULL){
					p01=p01->link2;
					if(strcmp(p01->data2.phone,check_p)==0){
					printf("���帮��Ʈ : %d\n", p01->data2.deadlift);
					printf("��ġ������ : %d\n", p01->data2.benchpress);
					printf("����Ʈ : %d\n\n", p01->data2.squats);
					}
				}
			printf("%s���� ���� �����Դ� %.2lf�Դϴ�.\n\n",p->data.name, p->data.weight);
		}
	}	
}

int drop(Node2 *L2, Node *L, char *check_p, int *count01){
	char yn[20];
	
	printf("[3]ȸ��Ż��\n"); 
	
	while(1){
		printf("ȸ��Ż�� �����Ͻðڽ��ϱ�?(Y/N) : ");
		scanf("%s", yn);
		if(strcmp(yn,"Y")==0){
			Nodedelete(L2, L, check_p, count01);
			return 1;
		}
		else if(strcmp(yn,"N")==0){
			printf("ȸ��Ż�� �ߴ��մϴ�.\n\n\n");
			return 0; 
		}
		else{
			printf("'Y' or 'N'�� �Է����ּ���.\n"); 
		}
	}
	memberrecord(L,check_p);
	historyrecord(L2,check_p);

	printf("\n");
}

void Nodedelete(Node2 *L2, Node *L, char *check_p, int *count01){
 	Node *p, *k;
	p=L;
	//�̵��ϴ�p�� ����Ű��k 
	int i;
	
	Node2 *p0, *k0;
	p0=L2;
	
	while(p->link!=NULL){ //ȸ�� �����ϱ� 
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
		while(p0->link2!=NULL){ //��� �����ϱ� 
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
	printf("[4]memeber ���ϱ��...\n"); 
	FILE *ofp;

	Node *p;
	 
	p=L;
	
	ofp=fopen("member.txt","w"); //���� �������� ����
	if(ofp==NULL){
		printf("��� ���� ���� ����.\n");
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
	printf("[4]history ���ϱ��...\n"); 
	FILE *ofp;
	int i;
	
	Node2 *p2;
	 
	p2=L2;

	ofp=fopen("history.txt","w"); //���� �������� ����
	if(ofp==NULL){
		printf("��� ���� ���� ����.\n");
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
	printf("�����Դϴ�.\n\n"); 
}
