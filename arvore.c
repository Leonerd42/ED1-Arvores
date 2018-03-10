#include <stdio.h>
#include <stdlib.h>

typedef struct reg* no; 
typedef struct reg{
	int num;
	no esq;
	no dir;
}oi;

int insere(no *fila, int num){
	no p;
	no q;
	q = *fila;
	p = (no) malloc (sizeof(struct reg));
	p->num=num;
	p->esq = NULL;
	p->dir = NULL;
	if(!(*fila)){
		*fila = p;
		return 1;		
	}
	while(42){
		if(num >= q->num ){
			if(q->dir)	q = q->dir;
			else{
				q->dir = p;
				return 1;
			}
		}
		else{
			if(q->esq) q = q->esq;
			else{
				q->esq = p;
				return 1;
			}
		}
	}
	
}

void amostra(no fila){
	no q = fila;
	if(q->esq)	amostra(q->esq);
	printf("%d\n",q->num);
	if(q->dir) 	amostra(q->dir);
	
}

void salva(no fila, char c){
	FILE* arq = fopen("a.json", "w");
	if(!arq){
		printf("o arquivo deu ruim WTF\n");
		return 0;
	}
	
	escreve(fila, arq, 1);
	fclose(arq);
}
	
void escreve(no fila,FILE* arq, int rec){
	no q = fila;
	int i;
	//linha
	for(i=1;i<rec;i++)	putc('\t', arq);
	putc('{',arq);
//	putc('\n',arq);
	//liha
//	for(i=1;i<rec;i++)	putc('\t', arq);
	putc('"',arq);
	fprintf(arq,"numero");
	putc('"',arq);
	putc(':',arq);
	putc(' ',arq);
	putc('"',arq);
	fprintf(arq,"%d",q->num);
	putc('"',arq);
	if(q->esq||q->dir){
		putc(',',arq);
		putc('\n',arq);
		for(i=1;i<rec;i++)	putc('\t', arq);
		putc('"',arq);
		fprintf(arq,"children");
		putc('"',arq);
		fprintf(arq,": [");
		putc('\n',arq);
		if(q->esq&&q->dir){
			escreve(q->esq,arq,rec+1);
			for(i=1;i<rec;i++)	putc('\t', arq);
			putc(',',arq);
			putc('\n',arq);
			escreve(q->dir,arq,rec+1);
			putc('\n',arq);
		}	
		else if(q->esq){
			escreve(q->esq,arq,rec+1);
			putc('\n',arq);
		}
		else{
			escreve(q->dir,arq,rec+1);
			putc('\n',arq);
		}
		//liha
		for(i=1;i<rec;i++)	putc('\t', arq);
		putc(']',arq);
		putc('\n',arq);
	}
	for(i=1;i<rec;i++)	putc('\t', arq);
	putc('}',arq);
}

int main(){
	no fila=NULL;
	insere(&fila,5);
	insere(&fila,3);
	insere(&fila,6);
	insere(&fila,2);
	insere(&fila,1);
	insere(&fila,4);
	amostra(fila);
	salva(fila,'a');
}
