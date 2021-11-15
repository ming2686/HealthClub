#include "common.h"
#include "health.h"

#define DEADLEFT 15
#define BENCHPRESS 15
#define SQUARTS 15
//������ 0.01kg ���Ҹ� ���� ������ (1)���帮��Ʈ 15ȸ, (2)��ġ������ 15ȸ, (3)����Ʈ 15ȸ �Դϴ�. 

void lodedata(Node2 *L2, Node *L){
	FILE *ifp, *ofp;
	struct health h;
	struct member memb;
	int res;
	
	ifp=fopen("member.txt", "r"); //�б��������� ���� 
	if(ifp==NULL){
	//	printf("��� ���� ���� ����.\n");
		return ; 
	}
	while(1){
		res=fscanf(ifp,"%s%s%d%lf%lf%s", memb.name, memb.phone, &memb.height, &memb.weight, &memb.targetweight, memb.sickness);		
		if(res==EOF) break;
		addNode(L, memb);

	}
	fclose(ifp);	
	
	ofp=fopen("history.txt", "r"); //�б��������� ����
	if(ifp=NULL){
	//	printf("��� ���� ���� ����.\n");
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
	scanf("%lf",&t.weight);
	printf("(5) ��ǥ ������ : ");
	scanf("%lf",&t.targetweight);
	printf("(6) �������� : ");
	scanf("%s",t.sickness);
	printf("\n");
	
 	return t;
 }
 
 int entrance(Node2 *L2, Node *L, char *check_p){
	char checkphone[20];
	char checkname[20];
	
	int check=0;
	
	printf("[2]�����ϱ�\n"); 

	printf("(1) ��ȭ��ȣ : "); //���������� ���� �� ������ ��ȭ��ȣ�� ���� check 
	scanf("%s", checkphone);

	if(searchNode(L, checkphone, 1, check_p)==1){
		strcpy(check_p, checkphone);
		
		printf("(2) �̸� :");
		scanf("%s", checkname);
		if(searchNode(L, checkname, 2, check_p)==2){
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

int searchNode(Node *L, char *srch, int method, char *check_p){ //char �̸�, ��ȭ��ȣ 
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
			if(strcmp(p->data.name,srch)==0){ //�̸��̶� �����Ͱ� ������ 
				if(strcmp(p->data.phone,check_p)==0){
					check=2;
				}
			}
		}
	}
	
	return check;
}
