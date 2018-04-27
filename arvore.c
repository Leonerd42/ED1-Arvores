#include "json.h"

int insere(no *fila, int num){
	no p;
	printf("ah 1\n");
	no q;
	printf("ah 2\n");
	q = *fila;
	printf("ah 3\n");
	p = (no) malloc (sizeof(struct reg));
	printf("ah 4\n");
	p->esq = NULL;
	printf("ah 5\n");
	p->dir = NULL;
	printf("ah 6\n");
	p->num=num;
	printf("ah 7\n");
	
	if(!(*fila)){
		*fila = p;
		return 1;		
	}
	printf("ah 8\n");
	
	while(42){
		printf("ah 9\n");
		if(num >= q->num ){
			printf("ah 10 \n");
			printf("ah 11\n");
			if(q->dir)	q = q->dir;
			else{
				q->dir = p;
				printf("ah 12\n");
				return 1;
			}
			printf("ah 13\n");
		}
		else{
			printf("ah 14\n");
			if(q->esq) q = q->esq;
			else{
			printf("ah 15\n");
				printf("ah 16\n");
				q->esq = p;
				printf("ah 17\n");
				return 1;
				printf("ah 18\n");
			}
			printf("ah 19\n");
		}
		printf("ah 20\n");
	}
	
}

void amostra(no fila){
	no q = fila;
	if(q->esq)	amostra(q->esq);
	printf("%d\n",q->num);
	if(q->dir) 	amostra(q->dir);
	
}

int main(int argc, char *argv){
	no fila=NULL;
	
	insere(&fila,4);
	insere(&fila,2);
	insere(&fila,6);
	insere(&fila,1);
	insere(&fila,3);
	insere(&fila,5);
	insere(&fila,7);
	insere(&fila,8);
	insere(&fila,9);
	insere(&fila,10);
	amostra(fila);
	salva(fila);
}
