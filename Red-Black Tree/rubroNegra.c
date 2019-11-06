
#include "rubroNegra.h"

/* funcao: RN *nodeRN()
   *  acao:        funcao que cria um novo no o qual dever� ser inserido na �rvore
   *  entrada:     elemento de informa��o do novo n�
   *  saida:       ponteiro para um n�
*/
RN *nodeRN(void *inf, arvore *T){
    RN *ptr = (RN *)malloc(sizeof(RN));
    if(ptr){
        ptr->chave=inf;
        ptr->cor=RUBRO;				//para este algoritmo, um novo n� sempre ser� RUBRO
        ptr->esq= T->sentinela;		//Um n� sempre ser� inserido como folha, logo seus dois filhos s�o sentinela
        ptr->dir= T->sentinela;
        ptr->pai= T->sentinela;
        return ptr;
    }
    return NULL;
}


/* funcao: RN *nodeSentinela()
   *  acao:        funcao que cria o n� sentinela
   *  entrada:     void
   *  saida:       ponteiro para um n� sentinela
*/
RN *nodeSentinela(){
    RN *ptr = (RN *)malloc(sizeof(RN));
    if(ptr){
        ptr->chave=0;
        ptr->cor=NEGRO;
        ptr->esq=NULL;
        ptr->dir=NULL;
        ptr->pai=NULL;
        return ptr;
    }
    return NULL;
}

/* funcao: arvore *criaArvore()
   *  acao:        funcao que cria uma nova �rvore (estrutura que aponta para a raiz
                   de uma arvore RN bem como para o n� sentinela)
   *  entrada:     void
   *  saida:       ponteiro para uma arvore
*/
arvore *criaArvore(){
	arvore *T= (arvore*)malloc(sizeof(arvore));
	if(T){
		T->sentinela= nodeSentinela();
		T->raiz= T->sentinela;
		return T;
	}
	return NULL;
}


/* funcao: void rotEsq(arvore *T, RN *x)
   *  acao:        funcao que realiza rota��o esquerda sobre uma �rvore
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       void
*/
void rotEsq(arvore *T, RN *x){
    RN *y = x->dir;

    x->dir = y->esq;
    if (y->esq != T->sentinela) y->esq->pai = x;

    y->pai = x->pai;
    if (x->pai == T->sentinela) T->raiz= y;
    else if(x == x->pai->esq) x->pai->esq = y;
    else x->pai->dir = y;

    y->esq = x;
    x->pai = y;
}

/* funcao: void rotDir(arvore *T, RN *x)
   *  acao:        funcao que realiza rota��o direita sobre uma �rvore
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       void
*/
void rotDir(arvore *T, RN *x){
    RN *y = x->esq;

    x->esq = y->dir;
    if (y->dir != T->sentinela) y->dir->pai = x;

    y->pai = x->pai;
    if (x->pai == T->sentinela) T->raiz=y;
    else if(x == x->pai->dir) x->pai->dir = y;
    else x->pai->esq = y;

    y->dir = x;
    x->pai = y;
}

/* funcao: RN *buscaRN(arvore *T, RN *z, int chave)
   *  acao:        funcao que busca por um n� na �rvore
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       ponteiro para um n�
*/
RN *buscaRN(arvore *T, RN *z, void *chave, int (*compara)(void*, void*)){
    if(z == T->sentinela){
        printf("\nEsta chave nao existe");
        return NULL;
    }
    if(compara(z->chave, chave) == 0)
        return z;
    if(compara(z->chave, chave) > 0)
        return buscaRN(T, z->esq, chave, compara);
    else
        return buscaRN(T, z->dir, chave, compara);
}

/* funcao: void consertaInsertRN(arvore *T, RN *z)
   *  acao:        fun��o que avalia e reestabelece as propriedades da �rvore RN para o n� inserido
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       void
*/
void consertaInsertRN(arvore *T, RN *z){
    while(z->pai->cor == RUBRO){	//como z � rubro, a propriedade 4 foi violada

        if(z->pai == z->pai->pai->esq){
            RN *tio = z->pai->pai->dir;

            if(tio->cor == RUBRO){  //CASO 1
                printf("\nConsertaInsert: Entrou no Caso 1.1");
				z->pai->cor=NEGRO;
                tio->cor = NEGRO;
                z->pai->pai->cor = RUBRO;
                z= z->pai->pai;
            }

            else{
				if(z == z->pai->dir){  //CASO 2
                	printf("\nConsertaInsert: Entrou no Caso 1.2");
					z = z->pai;
                	rotEsq(T,z);
        		}
        		printf("\nConsertaInsert: Entrou no Caso 1.3");
                z->pai->cor = NEGRO;   //CASO 3
                z->pai->pai->cor = RUBRO;
                rotDir(T,z->pai->pai);
            }
        }
        else{
            RN *tio = z->pai->pai->esq;
            if(tio->cor == RUBRO){    //CASO 1
                printf("\nConsertaInsert: Entrou no Caso 2.1");
				z->pai->cor=NEGRO;
                tio->cor = NEGRO;
                z->pai->pai->cor = RUBRO;
                z=z->pai->pai;
            }
            else{
				if(z == z->pai->esq){  //CASO 2
                	printf("\nConsertaInsert: Entrou no Caso 2.2");
					z = z->pai;
                	rotDir(T,z);
        		}
        		printf("\nConsertaInsert: Entrou no Caso 2.3");
                z->pai->cor = NEGRO;  //CASO 3
                z->pai->pai->cor = RUBRO;
                rotEsq(T,z->pai->pai);
            }
		}
    }
    T->raiz->cor= NEGRO;
}

/* funcao: void insertRN(arvore *T, int inf)
   *  acao:        funcao que insere um novo n� na �rvore
   *  entrada:     ponteiro para a arvore eelemento de informa��o a ser inserido
   *  saida:       void
*/
void insertRN(arvore *T, void *inf, int (*compara)(void*, void*)){
    RN *z = nodeRN(inf, T);
    RN *pai = T->sentinela;
    RN *x = T->raiz;

    while(x != T->sentinela){
		pai = x;
        if(compara(z->chave, x->chave) < 0) x= x->esq;
        else x= x->dir;
    }
    z->pai = pai;

    if(pai == T->sentinela)
        T->raiz = z;
    else if(compara(z->chave, pai->chave) < 0)
        pai->esq = z;
    else pai->dir = z;

    consertaInsertRN(T,z);
}

/* funcao: void transplantRN(arvore *T, RN *u, RN *v)
   *  acao:        funcao que realiza os reapontamentos necess�rios na remo��o de determinado n�
   *  entrada:     ponteiro para a arvore e ponteiros para dois n�s distintos
   *  saida:       void
*/
void transplantRN(arvore *T, RN *u, RN *v){
    if(u->pai == T->sentinela) T->raiz= v;
    else if(u == u->pai->esq) u->pai->esq= v;
    else u->pai->dir= v;
    v->pai= u->pai;
}

/* funcao: RN *menor(arvore *T, RN *x)
   *  acao:        funcao que busca o sucessor de um n�
                   (sucessor = filho mais a esquerda da sub�rvore direita de determinada �rvore)
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       ponteiro para um n�
*/
RN *menor(arvore *T, RN *x){
	while (x->esq != T->sentinela)
		x= x->esq;
	return x;
}

/* funcao: void consertaDeleteRN(arvore *T,RN *x)
   *  acao:        fun��o que avalia e reestabelece as propriedades da �rvore RN para o n� inserido
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       void
*/
void consertaDeleteRN(arvore *T,RN *x){
	RN *w;
	while((x != T->raiz) && (x->cor == NEGRO)){
		if(x == x->pai->esq){
			w= x->pai->dir;
			if(w->cor == RUBRO){		//CASO 1
				printf("\nConsertaDelete: Entrou no Caso 1.1");
				w->cor= NEGRO;
				x->pai->cor= RUBRO;
				rotEsq(T, x->pai);
				w= x->pai->dir;
			}
			if((w->esq->cor == NEGRO)&&(w->dir->cor == NEGRO)){		//CASO 2
				printf("\nConsertaDelete: Entrou no Caso 1.2");
				w->cor= RUBRO;
				x= x->pai;
			}
			else{
				if(w->dir->cor == NEGRO){	//CASO 3
					printf("\nConsertaDelete: Entrou no Caso 1.3");
					w->esq->cor= NEGRO;
					w->cor= RUBRO;
					rotDir(T, w);
					w= x->pai->dir;
				}							//CASO 4
				printf("\nConsertaDelete: Entrou no Caso 1.4");
				w->cor= x->pai->cor;		
				x->pai->cor= NEGRO;
				w->dir->cor= NEGRO;
				rotEsq(T, x->pai);
				x= T->raiz;
			}
		}
		else{
			w= x->pai->esq;
			if(w->cor == RUBRO){		//CASO 1
				printf("\nConsertaDelete: Entrou no Caso 2.1");
				w->cor= NEGRO;
				x->pai->cor= RUBRO;
				rotDir(T, x->pai);
				w= x->pai->esq;
			}
			if((w->esq->cor == NEGRO)&&(w->dir->cor == NEGRO)){		//CASO 2
				printf("\nConsertaDelete: Entrou no Caso 2.2");
				w->cor= RUBRO;
				x= x->pai;
			}
			else{
				if(w->dir->cor == NEGRO){	//CASO 3
					printf("\nConsertaDelete: Entrou no Caso 2.3");
					w->esq->cor= NEGRO;
					w->cor= RUBRO;
					rotEsq(T, w);
					w= x->pai->esq;
				}							//CASO 4
				printf("\nConsertaDelete: Entrou no Caso 2.4");
				w->cor= x->pai->cor;
				x->pai->cor= NEGRO;
				w->dir->cor= NEGRO;
				rotDir(T, x->pai);
				x= T->raiz;
			}
		}
	}
	x->cor= NEGRO;
}

/* funcao: void deleteRN(arvore *T, int inf)
   *  acao:        funcao que remove um n� da �rvore
   *  entrada:     ponteiro para a arvore e elemento de informa��o a ser removido
   *  saida:       void
*/
void deleteRN(arvore *T, void *inf, int (*compara)(void*, void*)){
	RN *z= buscaRN(T, T->raiz, inf, compara);
	RN *x;
	RN *y= z;
	int corY= y->cor;
	if(z->esq == T->sentinela){
		x= z->dir;
		transplantRN(T, z, z->dir);
	}
	else if(z->dir == T->sentinela){
		x= z->esq;
		transplantRN(T, z, z->esq);
	}
	else{
		y= menor(T, z->dir);
		corY= y->cor;
		x= y->dir;
		if(y->pai == z)	x->pai= y;
		else{
			transplantRN(T, y, y->dir);
			y->dir= z->dir;
			y->dir->pai= y;
		}
		transplantRN(T, z, y);
		y->esq= z->esq;
		y->esq->pai= y;
		y->cor= z->cor;
	}
	free(z);
	if(corY == NEGRO)
		consertaDeleteRN(T, x);
}

