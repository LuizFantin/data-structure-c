#include<stdio.h>

#include "hashtable.c"

#define MAXSIZEHT 11
#define MAXSIZEW 30




int loadDic(Hash *hashtable)
{
	FILE *fp=fopen("palavras.txt","a+");
    if(fp==NULL)
	    {
		  printf("\a\a\n\n\n\n\n\nERRO AO ABRIR O ARQUIVO!\n\n\n\n\n\n");
		  system("pause");
		  return -1;
		}
	
	int pos, x=0;
	char aux[MAXSIZEW];
	while(!feof(fp))
	{
			fgets(aux,MAXSIZEW,fp);
			strtok(aux, "\n");
			pos = functionHT(aux,MAXSIZEHT);
			printf("\nloadDic: Palavra=%s Posicao=%d Numero = %d",aux,pos,x+1);
			insertHT(hashtable,MAXSIZEHT,aux);
			x++;
	}
	printf("\nTAMANHO TOTAL=%d Palavras",x);
	return 1;
}

int main()
{
	Hash hashtable[MAXSIZEHT];
	char word[MAXSIZEW];
	int resp,pos;
	Node *aux,*middle = NULL,*end = NULL;
	
	createHT(hashtable,MAXSIZEHT);
	loadDic(hashtable);
	printHT(hashtable,MAXSIZEHT);
	do
	{
		printf("\nDigite a palavra a ser buscada=");
		fflush(stdin);
		gets(word);
		pos = functionHT(word,MAXSIZEHT);
		printf("\nPalavra=%s Posicao=%d",word,pos);
		if(hashtable[pos].first != NULL){
			middle = meio(hashtable[pos].first,tamanhoList(hashtable[pos].first,NULL));
			end = final(hashtable[pos].first);
		}
		aux = searchHT(hashtable[pos].first,middle,end,word);
		deleteHT(hashtable,MAXSIZEHT,word);
		printHT(hashtable,MAXSIZEHT);
		printf("\nBuscar mais? 1-SIM ou 2-NAO");
		scanf("%d",&resp);
	}while(resp==1);
	
	getchar();
	return 0;	

}