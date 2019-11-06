

#include "rubroNegra.h"

typedef struct al{
    char nome[100];
    int id;
}aluno;

int compara(void *a, void *b)
{
    aluno *local_a = (aluno*)(a);
    aluno *local_b = (aluno*)(b);

    return (local_a->id) - (local_b->id);
}

/* funcao: void imprimeRN(arvore *T, RN *p, int nivel)
   *  acao:        funcao que imprime uma �rvore
   *  entrada:     ponteiro para a arvore, ponteiro para o n� raiz e o n�vel
   *  saida:       void
*/
void imprimeRN(arvore *T, RN *p, int nivel){
	int aux, i;
	char c;

	if(p == T->sentinela)  return;

	imprimeRN(T, p->dir, nivel+1);

	for(i=0;i<nivel;i++)   printf("      ");

	if(p->cor == 0) c = 'N';
	else   c = 'R';
	printf("(%d):%c\n\n",((aluno*)(p->chave))->id, c);
	imprimeRN(T, p->esq,nivel+1);
}

/*Fun��o Principal*/
int main(){
	arvore *T= criaArvore();

    int resp;
    int i = 0;
    aluno aux;
    void *p;


    printf("\n**************INSERCAO**************\n", i);
	do{
       aluno *al = (aluno*)malloc(sizeof(aluno));

        i++;
        printf("\n**************ALUNO %d**************\n", i);

        printf("Insira o nome: ");
        scanf("%s", al->nome);
        fflush(stdin);

        printf("\nInsira a identificacao: ");
        scanf("%d", &(al->id));

        insertRN(T, (void *)al,compara);
		printf("\n\n");
		
        imprimeRN(T,T->raiz,0);
        printf("\n***********************************\n\n");

        printf("Deseja inserir um novo aluno?\n(1)SIM\t(0)NAO\nResposta: ");
        scanf("%d", &resp);

	}while(resp==1);
	printf("\n\n");
    imprimeRN(T,T->raiz,0);

	printf("\n**************BUSCA**************\n");
	printf("\nDigite o ID a ser buscado:");
	scanf("%d", &(aux.id));
	p = buscaRN(T,T->raiz,(void*)&(aux),compara);
	if(p != NULL)
        printf("\nElemento encontrado!");

	printf("\n\n**************REMOCAO**************\n");

	do{
        printf("Digite o ID a ser removido:");
        scanf("%d", &(aux.id));
        deleteRN(T,(void*)&aux,compara);
        imprimeRN(T,T->raiz,0);
        printf("\n***********************************\n\n");
        printf("Deseja remover outro aluno?\n(1)SIM\t(0)NAO\nResposta:");
        scanf("%d", &resp);

	}while(resp==1);

	printf("\n***********************************\n\n");
	imprimeRN(T, T->raiz,0);

	return 0;
}



