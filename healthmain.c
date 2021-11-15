#include "common.h"
#include "health.h"

int main(int argc, char *argv[]) {
	struct health h;
	struct member memb;
	Node *L=create();
	Node2 *L2=create2();
	char check_p[20];
	
	int num;
	
	lodedata(L2, L);
	
	while((num=menu())!=3){
		switch(num){
			case 1:
				printNode(L);
				memb=join(L);
				addNode(L, memb);
				printNode(L);
				break;
			case 2:
				if(entrance(L2,L, check_p)==1){
					menu_sub(L2,L, check_p);
				}
				break;
			default:
				err();
				break;
		}
	}
	return 0;
}
