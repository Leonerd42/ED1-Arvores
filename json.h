#include <stdio.h>
#include <stdlib.h>

typedef struct reg* no; 
typedef struct reg{
	int num;
	no esq;
	no dir;
}oi;

void escreve(no fila,FILE* arq, int rec){
	no q = fila;
	int i;
	for(i=1;i<rec;i++)	putc('\t', arq);
	putc('{',arq);
	putc('"',arq);
	fprintf(arq,"numero");
	putc('"',arq);
	putc(':',arq);
	putc(' ',arq);
	putc('"',arq);
	fprintf(arq,"%d",q->num);
	putc('"',arq);
	
	//caso haja outra propriedade usar este modelo
//	putc(',')
//	putc('"',arq);
//	fprintf(arq,/*"outra propriedade*/");
//	putc('"',arq);
//	putc(':',arq);
//	putc(' ',arq);
//	putc('"',arq);
//	fprintf(arq,"%d",/*valor da outra propiedade*/);
//	putc('"',arq);
	
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
		for(i=1;i<rec;i++)	putc('\t', arq);
		putc(']',arq);
		putc('\n',arq);
	}
	for(i=1;i<rec;i++)	putc('\t', arq);
	putc('}',arq);
}

void salva(no fila){
	FILE* arq = fopen("a.json", "w");
	escreve(fila, arq, 1);
	fclose(arq);
}
