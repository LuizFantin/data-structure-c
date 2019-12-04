//Erika Barbosa Gomes
//Everson Henrich da Silva
//Luiz Fantin Neto
//Milena Tavares Roas

/*ÁRVORE B EM DISCO*/

#include "arvoreB.h"

/*
1- A primeira página no arquivo tem indPag (da estrutura pag) igual a 1.
2- Se a árvore está vazia, o campo numRaiz (da estrutura infoArvore) é igual a -1.
*/


//Função que cria árvore e inicializa os campos de informação da árvore
infoArvore *criaArvore(){
	infoArvore *arv= (infoArvore*)malloc(sizeof(infoArvore));
	if(arv){
		arv->numRaiz= -1;
		arv->numPags= 0;
		arv->tamPag= sizeof(pag);
		arv->numPagsLivres= 0;
		return arv;
	}
	return NULL;
}

//Função que cria página de uma árvore e inicializa seus campos
pag *criaPagina(artigo *art, int num){
	int i;
	pag *pagina= (pag*)malloc(sizeof(pag));
	if(pagina){
		pagina->indPag= num;
		pagina->m= 1;
		memcpy(&(pagina->s[0]), art, sizeof(artigo));
		for(i=0;i<=2*ORDEM + 1;i++){
            pagina->p[i]=-1;
		}
		pagina->livre= 0;
	}
	return pagina;
}

//Função que carrega uma página do disco
pag *lePagina(FILE *arq, int p, pag *pagina){
	fseek(arq, sizeof(infoArvore), SEEK_SET);
	fseek(arq, (p-1)*sizeof(pag), SEEK_CUR);
	
	fread(pagina, sizeof(pag), 1, arq);
	return pagina;
}

//Função que as informações da árvore B
infoArvore *leArvoreB(FILE *arq){
	infoArvore *arv = (infoArvore*)malloc(sizeof(infoArvore));

	if(arv != NULL)
	{	
		rewind(arq);
		fread(arv, sizeof(infoArvore), 1, arq);
	}
	return arv;
}


//função que escreve a página do disco
pag *escrevePagina(FILE *arq, int p, pag *pagina){
	fseek(arq, sizeof(infoArvore), SEEK_SET);
	fseek(arq, (p-1)*sizeof(pag), SEEK_CUR);
	
	fwrite(pagina, sizeof(pag), 1, arq);
	return pagina;
}

/* funcao: void BuscaArvoreB(FILE *arq, int chave, int f, int g)
   *  acao:        funcao que busca por uma dada chave na árvore B;
   *  entrada:     arquivo que contém a árvore, chave buscada, inteiro auxiliar f, inteiro auxiliar g
   *  saida:       void
*/
int buscaArvoreB(FILE *arq, int *pt, int chave, int *f, int *g){
	infoArvore *arv = criaArvore();
	pag *pagina = (pag*)malloc(sizeof(pag));
	fseek(arq, 0, SEEK_SET);
	fread(arv, sizeof(infoArvore), 1, arq);		//grava em "arv" o bloco de informações da árvore
	int pai;
	pai= -1;
	
	*pt= arv->numRaiz;				
	int p= *pt;
	
	*pt= -1;
	*f= 0;
	int i;
	int m;
	
	while(p != -1){
		i = 0; 
		pai = *pt;
		*g = 0;
		*pt = p;
		pagina= lePagina(arq, p, pagina);
	
		m = pagina->m;
		// printf("\nNumero de chaves na pagina: %d" ,pagina->m);
		while(i < m){
			if(chave > pagina->s[i].id){
				i++;
				*g= i;
			}
			else{
				if(chave == pagina->s[i].id){
					p= -1;
					*f= 1;
				}
				else{
					p= pagina->p[i];	
				}
				i= m+1;
			}
		}
		if(i == m)
			p= pagina->p[m];
	}
	return pai;
}

//Função que determina a posição no disco onde a pagina deverá ser inserida
int ondeInserir(FILE *arq, infoArvore *arv){
    int p;
    pag *pagina = (pag*)malloc(sizeof(pag));

    if(arv->numPagsLivres==0){

    	return arv->numPags+1;
	}
    else{
       for(p = 1; p <= arv->numPags; p++){
		    if(pagina!=NULL)
			{
				pagina = lePagina(arq, p, pagina);
				if(pagina->livre == 1){
					free(pagina);
					return p;
				}
			}
       }
    }
}

//Função que insere um artigo em uma determinada página de forma ordenada
void insereOrdem(pag *pagina, artigo *art, int g){
    int i;
    int m= pagina->m;
    pagina->p[m+1]= pagina->p[m];
    for(i=m; i!=g ; i--){
    	memcpy(&(pagina->s[i]), &(pagina->s[i-1]), sizeof(artigo));
        pagina->p[i]= pagina->p[i-1];
    }
    memcpy(&(pagina->s[g]), art, sizeof(artigo));
}

//Função que faz cisão das páginas
pag *cisao(FILE *arq, infoArvore *arv, pag *P, pag *pai){
	int i;
	artigo *aux = (artigo*)malloc(sizeof(artigo));
	pag *Q = criaPagina(&(P->s[ORDEM+1]), ondeInserir(arq, arv));	
	
	for(i=ORDEM+1; i<=2*ORDEM; i++){
		memcpy(&(Q->s[i - (ORDEM+1)]), &(P->s[i]), sizeof(artigo));
		memcpy(&(Q->p[i - (ORDEM+1)]), &(P->p[i]), sizeof(artigo));
	}
	memcpy(&(Q->p[i - (ORDEM+1)]), &(P->p[i]), sizeof(artigo));
	memcpy(aux, &(P->s[ORDEM]), sizeof(artigo));
	P->m= ORDEM;
	Q->m= ORDEM;
	P= escrevePagina(arq, P->indPag, P);
	Q= escrevePagina(arq, Q->indPag, Q);
	(arv->numPags)++;
	
	if(arv->numPagsLivres > 0 && ondeInserir(arq, arv) <= arv->numPags)
		(arv->numPagsLivres)-=1;
	
	if(pai == NULL){
		pag *novaRaiz= criaPagina(aux, ondeInserir(arq, arv));		
		novaRaiz->p[0]= P->indPag;
		novaRaiz->p[1]= Q->indPag;
		arv->numRaiz = novaRaiz->indPag;
		escrevePagina(arq, ondeInserir(arq, arv), novaRaiz);
		(arv->numPags)++;
		return novaRaiz;
	}	
	for(i=0; i < pai->m; i++){
		if(aux->id < pai->s[i].id){
			insereOrdem(pai, aux, i);
			break;
		}
	}
	if(i==pai->m)
		insereOrdem(pai, aux, i);

	(pai->m)++;
	
	pai->p[i+1]= Q->indPag;
	pai= escrevePagina(arq, pai->indPag, pai);
	fseek(arq, 0, SEEK_SET);
	fwrite(arv, sizeof(infoArvore), 1, arq);
	return pai;
}

void insereArvoreB(FILE *arq, artigo *art, int existeArq){		//se existeArq=0 não existe arquivo
    int chave = art->id;
    int pt;
	int f;
	int g;
	pag *pagina;
	infoArvore *arv = criaArvore();
	int indPai;
	pag *pai;
	pai = (pag*)malloc(sizeof(pag));

    if(existeArq==0){
        //se o arquivo estiver vazio
        pagina = criaPagina(art,1);
        arv->numPags++;
        arv->numRaiz = 1;
        fwrite(arv, sizeof(infoArvore), 1, arq);
        fwrite(pagina, sizeof(pag), 1, arq);
        printf("\nPrimeiro artigo inserido! Chave: %d", pagina->s[0].id);
    }
    else{
    	fseek(arq, 0, SEEK_SET);
        indPai= buscaArvoreB(arq, &pt, chave, &f, &g);
		if(f==1)
            printf("\nInsercao invalida!");
		else{
			if(indPai == -1)
				pai= NULL;
			else
				pai= lePagina(arq, indPai, pai);  
        	fseek(arq, 0, SEEK_SET);
            fread(arv, sizeof(infoArvore), 1, arq);
            pagina= (pag*)malloc(sizeof(pag));
            pagina = lePagina(arq, pt, pagina);
            insereOrdem(pagina, art, g);
            pagina->m = pagina->m +1;
            pagina= escrevePagina(arq, pt, pagina);
        
			while(pagina->m > 2*ORDEM){
				pagina = cisao(arq, arv, pagina, pai);

				indPai = buscaArvoreB(arq, &pt, pagina->s[0].id, &f, &g);
				if(indPai == -1)
					pai = NULL;

				rewind(arq);
				fwrite(arv, sizeof(infoArvore), 1, arq);
			}
			if(pagina != pai)
				free(pagina);
			printf("\nA artigo inserido com sucesso!\nChave %d\n\n", art->id);
		}
    }
	
	free(arv);
	free(pai);
	return;
}

void removeChave(pag *pagina, int g)
{
	int i = 0;

	for(i = g; i < pagina->m; i++)
	{
		memcpy(&(pagina->s[i]), &(pagina->s[i+1]), sizeof(artigo));
		memcpy(&(pagina->p[i]), &(pagina->p[i+1]), sizeof(artigo));
	}
	(pagina->m)--;
	return;
}

pag *buscaSucessor(FILE *arq, pag* pagina, int g, int *indPai)
{
	pag *paginaFolha = (pag*)malloc(sizeof(pag));

	if(paginaFolha != NULL)
	{
		*indPai = pagina->indPag;
		paginaFolha = lePagina(arq, pagina->p[g+1], paginaFolha);
		while(verificaFolha(paginaFolha) == 0)
		{
			*indPai = paginaFolha->indPag;
			paginaFolha = lePagina(arq, paginaFolha->p[0], paginaFolha);
		}
	}
	return paginaFolha;
}

short int verificaFolha(pag *pagina)
{
	int i = 0;
	int folha = 1;

	for(i = 0; i <= pagina->m; i++)
	{
		if(pagina->p[i] != -1)
		{
			folha = 0;
			break;
		}
	}
	return folha;
}

int buscarPai(FILE *arq, pag* pagFilho)
{
	int indPai = 0;
	int f = 0;
	int g = 0;

	indPai = buscaArvoreB(arq, &indPai, pagFilho->s[0].id, &f, &g);

	return indPai;
}


pag *buscaPaginas(FILE *arq, int indPagP,int *posW, pag* pagPai)
{
	int i = 0;

	pag *pagIrma = (pag*)malloc(sizeof(pag));
	pag *aux = (pag*)malloc(sizeof(pag));

	if(pagIrma != NULL && aux != NULL)
	{
		for(i = 0; i <= pagPai->m; i++)
		{
			if(pagPai->p[i] == indPagP)
				break;
		}
		if(i == 0)
		{
			*posW = 0;
			pagIrma = lePagina(arq, pagPai->p[i+1], pagIrma);
		}
		else if(i == pagPai->m)
		{
			*posW = pagPai->m - 1;
			pagIrma = lePagina(arq, pagPai->p[i-1], pagIrma);
		}
		else
		{
			
			pagIrma = lePagina(arq, pagPai->p[i+1], pagIrma);
			aux = lePagina(arq, pagPai->p[i-1], aux);
			if(pagIrma->m >= aux->m)
			{
				*posW = i;
				free(aux);
			}
			else
			{
				free(pagIrma);
				pagIrma = aux;
				*posW = i - 1;
			}
		}
	}
	return pagIrma;
}

int concatenarPaginas(FILE *arq, pag* pagP, pag *pagQ, pag *pagPai, int posW)
{
	int i = 0;
	infoArvore *arv;
	arv = leArvoreB(arq);
	int raiz = 0;

	if(arv != NULL)
	{
		if(pagP->s[0].id < pagQ->s[0].id)
		{
			insereOrdem(pagP, &(pagPai->s[posW]), pagP->m);
			(pagP->m)++;
			removeChave(pagPai, posW);
			pagPai->p[posW] = pagP->indPag;
			while(pagQ->m > 0)
			{
				insereOrdem(pagP, &(pagQ->s[0]), pagP->m);
				pagP->p[pagP->m] = pagQ->p[0];
				pagP->p[(pagP->m)+1] = pagQ->p[1];
				(pagP->m)++;
				removeChave(pagQ, 0);
			}
			pagQ->livre = 1;
			(arv->numPagsLivres)++;

			if((pagPai->indPag == arv->numRaiz) && (pagPai->m == 0))
			{
				pagPai->livre = 1;
				(arv->numPagsLivres)++;
				(arv->numRaiz) = pagP->indPag;
			}
			rewind(arq);
			fwrite(arv, sizeof(infoArvore), 1, arq);
		}
		else
		{
			insereOrdem(pagP, &(pagPai->s[posW]), 0);
			(pagP->m)++;
			removeChave(pagPai, posW);
			while(pagQ->m > 0)
			{
				insereOrdem(pagP, &(pagQ->s[(pagQ->m)-1]), 0);
				pagP->p[0] = pagQ->p[(pagQ->m)];
				pagP->p[1] = pagQ->p[(pagP->m)+1];
				(pagP->m)++;
				removeChave(pagQ, (pagQ->m)-1);
			}
			pagQ->livre = 1;
			(arv->numPagsLivres)++;

			if((pagPai->indPag == arv->numRaiz) && (pagPai->m == 0))
			{
				pagPai->livre = 1;
				(arv->numPagsLivres)++;
				(arv->numRaiz) = pagP->indPag;
			}
			rewind(arq);
			fwrite(arv, sizeof(infoArvore), 1, arq);
		}
	}
	raiz = arv->numRaiz;
	free(arv);
	return raiz;
}

void redistribuirPaginas(FILE *arq, pag* pagP, pag *pagQ, pag *pagPai, int posW)
{
	int i = 0;
	int numChaves = pagQ->m - (ORDEM+1);

	if(pagP->s[0].id < pagQ->s[0].id)
	{
		insereOrdem(pagP, &(pagPai->s[posW]), pagP->m);
		(pagP->m)++;
		pagP->p[pagP->m] = pagQ->p[0];
		for(i = 0;i < numChaves; i++)
		{
			insereOrdem(pagP, &(pagQ->s[0]), pagP->m);
			pagP->p[pagP->m] = pagQ->p[0];
			pagP->p[(pagP->m)+1] = pagQ->p[1];
			(pagP->m)++;
			removeChave(pagQ, 0);
		}
		memcpy(&(pagPai->s[posW]), &(pagQ->s[0]), sizeof(artigo));
		removeChave(pagQ, 0);
	}
	else
	{
		insereOrdem(pagP, &(pagPai->s[posW]), 0);
		(pagP->m)++;
		pagP->p[0] = pagQ->p[pagQ->m];
		for(i = 0;i < numChaves; i++)
		{
			insereOrdem(pagP, &(pagQ->s[(pagQ->m)-1]), 0);
			pagP->p[0] = pagQ->p[pagP->m];
			pagP->p[1] = pagQ->p[(pagP->m)+1];
			(pagP->m)++;
			removeChave(pagQ, (pagQ->m)-1);
		}
		memcpy(&(pagPai->s[posW]), &(pagQ->s[(pagQ->m)-1]), sizeof(artigo));
		removeChave(pagQ, (pagQ->m)-1);
	}
	return;
}

void removeArvoreB(FILE *arq, artigo *art)
{
	pag *pagina = NULL;
	pag *pagAux = NULL;
	pag *pagQ = NULL;
	artigo aux;
	int posW = 0;
	int pt = 0;
	int f = 0;
	int g = 0;
	int indPai = 0;
	int i = 0;
	int indRaiz = 0;


	indPai = buscaArvoreB(arq, &pt, art->id, &f, &g);
	if(f == 1)
	{
		printf("\nArtigo encontrado na pagina %d, posicao %d\n", pt, g);
		pagina = (pag*)malloc(sizeof(pag));
		pagAux = (pag*)malloc(sizeof(pag));
		
		if(pagina != NULL && pagAux != NULL)
		{
			pagina = lePagina(arq, pt, pagina);
			if(verificaFolha(pagina) == 0)
			{
				pagAux = buscaSucessor(arq, pagina, g, &indPai);
				if(pagAux != NULL)
				{
					memcpy(&aux, &(pagAux->s[0]), sizeof(artigo));
					memcpy(&(pagAux->s[0]), &(pagina->s[g]) , sizeof(artigo));
					memcpy(&(pagina->s[g]), &aux, sizeof(artigo));

					pagina = escrevePagina(arq, pagina->indPag, pagina);
					memcpy(pagina, pagAux, sizeof(pag));
					removeChave(pagina, 0);
				}
			}
			else
				removeChave(pagina, g);

			printf("Artigo removido!\n");

			
			if(indPai == -1)
			{
				pagina = escrevePagina(arq, pagina->indPag, pagina);
				printf("O processo de remocao do artigo ocorreu com sucesso.\n");
			}

			else
			{	
				if(pagina->m >= ORDEM)
					pagina = escrevePagina(arq, pagina->indPag, pagina);
				while(pagina->m < ORDEM)
				{
					indPai = buscarPai(arq, pagina);
					pagAux = lePagina(arq, indPai, pagAux);
					pagQ = buscaPaginas(arq, pagina->indPag, &posW, pagAux);
					if(pagQ != NULL)
					{
						if(pagina->m + pagQ->m < 2*ORDEM)
						{
							indRaiz = concatenarPaginas(arq, pagina, pagQ, pagAux, posW);
							pagAux = escrevePagina(arq, pagAux->indPag, pagAux);
							pagQ = escrevePagina(arq, pagQ->indPag, pagQ);
							pagina = escrevePagina(arq, pagina->indPag, pagina);

							if(pagina->indPag != indRaiz)
								memcpy(pagina, pagAux, sizeof(pag));
						}
						else
						{
							redistribuirPaginas(arq, pagina, pagQ, pagAux, posW);
							pagAux = escrevePagina(arq, pagAux->indPag, pagAux);
							pagQ = escrevePagina(arq, pagQ->indPag, pagQ);
							pagina = escrevePagina(arq, pagina->indPag, pagina);
						}
					}
				}
				printf("O processo de remocao do artigo ocorreu com sucesso.\n");	
			}	

			free(pagAux);
			free(pagQ);
			free(pagina);
		}
	}
	else
		printf("\nRemocao nao foi realizada.\nArtigo nao encontrado!\n");
	
	return;
}

//Função pede dados do Artigo
void pedeArtigo(artigo *art){
	printf("\nPreencha os campos do artigo:: ");
	printf("\nID: ");
	scanf("%d", &(art->id));
	printf("\nAno: ");
	scanf("%d", &(art->ano));
	printf("\nAutor: ");
	scanf(" %[^\n]s", art->autor);
	printf("\nTitulo: ");
	scanf(" %[^\n]s", art->titulo);
	printf("\nRevista: ");
	scanf(" %[^\n]s", art->revista);
	printf("\nDOI: ");
	scanf(" %s", art->DOI);
	printf("\nPalavra Chave: ");
	scanf(" %[^\n]s", art->palavraChave);
}


void mostrarArtigo(FILE *arq, int *pt, int *g)
{
    pag *pagina = (pag*)malloc(sizeof(pag));
    pagina = lePagina(arq,*pt,pagina);

    printf("\nID: %d \n",pagina->s[*g].id);
    printf("Ano: %d \n",pagina->s[*g].ano);
    printf("Autor: %s \n",pagina->s[*g].autor);
    printf("Titulo: %s \n",pagina->s[*g].titulo);
    printf("Revista: %s \n",pagina->s[*g].revista);
    printf("DOI: %s \n",pagina->s[*g].DOI);
    printf("Palavra Chave: %s \n",pagina->s[*g].palavraChave);
}

void imprimirPaginas(FILE *arq, infoArvore *arv)
{
    int i = 0;
    int j = 0;
    pag *pagina;
    

    if(pagina != NULL)
    {
        rewind(arq);
        fread(arv, sizeof(infoArvore), 1, arq);

        printf("\n\t\t==========INFORMACOES DO ARQUIVO==========\n");
        
        printf("\n\t\tO arquivo corrente tem %d paginas\n ", arv->numPags);
        printf("\nPAGINA RAIZ %d\n", arv->numRaiz);
        for(i = 1; i <= arv->numPags; i++)
        {
            pagina = (pag*)malloc(sizeof(pag));
            pagina = lePagina(arq, i, pagina);
            if(pagina->livre == 0)
            {
                printf("\t\tPAGINA %d de %d\n", i, arv->numPags);
                verificaFolha(pagina) == 1 ? printf("\n\tPAGINA FOLHA") : printf("\n");
                for(j=0; j<pagina->m; j++)
                {
                    printf("\nApontador %d: %d", j, pagina->p[j]);
                    printf("\tChave do artigo %d: %d", j, pagina->s[j].id);
                }
                printf("\t\t\nApontador %d: %d\n\n", j, pagina->p[j]);
            }
            free(pagina);
        }
    }
    
    return;
}
