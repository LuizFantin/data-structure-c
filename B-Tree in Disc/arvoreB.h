//Erika Barbosa Gomes
//Everson Henrich da Silva
//Luiz Fantin Neto
//Milena Tavares Roas

/*ÁRVORE B EM DISCO*/

#ifndef _H_ARVOREB
#define _H_ARVOREB

/*Declaração das bibliotecas*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Definição de constantes*/
#define ORDEM 2
#define fileName "arquivo.bin"

/*Estrutura do artigo*/
typedef struct{
    int id;
    int ano;
    char autor[200];
    char titulo[200];
    char revista[200];
    char DOI[20];
    char palavraChave[200];
}artigo;

/*Estrutura de uma página na árvore B*/
typedef struct{
	int indPag;			//se indPag= -1, essa página não existe, a primeira página em disco tem indPag = 1
	int m;				//número de chaves na página
	artigo s[2*ORDEM+1];
	int p[2*ORDEM+2];	//se p[i]= -1, quer dizer que é nulo, ou seja, a página atual não tem esta página filha
	int livre;			//se livre=1, então a página foi removida do arquivo
}pag;

/*Estrutura do cabeçalho da árvore no disco*/
typedef struct{								
	int numRaiz;
	int numPags;
	int tamPag;		
	int numPagsLivres;	
}infoArvore;

/* funcao: infoArvore *criaArvore()
   *  acao:        função que cria árvore e inicializa os campos de informação da árvore;
   *  entrada:     sem entrada;
   *  saida:       ponteiro para infoArvore.
*/
infoArvore *criaArvore();

/* funcao: pag *criaPagina(artigo *art, int num)
   *  acao:        função que cria página de uma árvore e inicializa seus campos;
   *  entrada:     artigo que será inserido na posicao 0, indice da pagina;
   *  saida:       ponteiro para infoArvore.
*/
pag *criaPagina(artigo *art, int num);

/* funcao: pag *lePagina(FILE *arq, int p, pag *pagina)
   *  acao:        função que carrega uma página do disco;
   *  entrada:     arquivo que contem a arvore, indice da pagina, ponteiro para pagina;
   *  saida:       ponteiro para pagina lida.
*/
pag *lePagina(FILE *arq, int p, pag *pagina);

/* funcao: pag *escrevePagina(FILE *arq, int p, pag *pagina)
   *  acao:        função que escreve uma página no disco;
   *  entrada:     arquivo que contem a arvore, indice da pagina, ponteiro para pagina;
   *  saida:       ponteiro para pagina escrita.
*/
pag *escrevePagina(FILE *arq, int p, pag *pagina);


/* funcao: int buscarPai(FILE *arq, pag* pagFilho)
   *  acao:        função busca o indice da pagina pai;
   *  entrada:     arquivo que contem a arvore, poteiro para a pagina filho;
   *  saida:       valor inteiro do indice da pagina pai.
*/
int buscarPai(FILE *arq, pag* pagFilho);


/* funcao: short int verificaFolha(pag *pagina)
   *  acao:        função que verifica se a pagina é uma pagina folha;
   *  entrada:     pagina que vai ser verificada;
   *  saida:       valor inteiro que diz se a pagina é folha ou não
   *  (1 - para pagina folha, 0 - para pagina interna).
*/
short int verificaFolha(pag *pagina);

/* funcao: pag *buscaSucessor(FILE *arq, pag *pagina, int g, int *indPai);
   *  acao:        função que busca o artigo sucessor(possui o id imediatamente maior) do artigo desejado;
   *  entrada:     arquivo que contem a arvore, pagina que contem o artigo, posicao do artigo na pagina,  ponteiro para inteiro indPai;
   *  saida:       pagina folha que contem o sucessor.
*/
pag *buscaSucessor(FILE *arq, pag *pagina, int g, int *indPai);

/* funcao: void removeChave(pag *pagina, int g)
   *  acao:        função que remove da página a chave na posição g ;
   *  entrada:     pagina que contem o artigo, inteiro g;
   *  saida:       sem saída.
*/
void removeChave(pag *pagina, int g);

/* funcao: void removeChave(pag *pagina, int g)
   *  acao:        função que busca as páginas ;
   *  entrada:     pagina que contem o artigo, inteiro g;
   *  saida:       sem saída.
*/
pag *buscaPaginas(FILE *arq, int indPagP,int *posW, pag* pagPai);

/* funcao: int BuscaArvoreB(FILE *arq, int chave, int f, int g)
   *  acao:        funcao que busca por uma dada chave na árvore B;
   *  entrada:     arquivo que contém a árvore, chave buscada, inteiro auxiliar f, inteiro auxiliar g;
   *  saida:       inteiro com o indice da pagina pai.
*/
int buscaArvoreB(FILE *arq, int *pt, int chave, int *f, int *g);

/* funcao: int ondeInserir(FILE *arq, infoArvore *arv)
   *  acao:        função que determina a posição no disco onde a pagina deverá ser inserida;
   *  entrada:     arquivo que contém a árvore, infoArvore que contem o bloco de informações da arvore;
   *  saida:       inteiro com indice de pagina onde deve ser inserido.
*/
int ondeInserir(FILE *arq, infoArvore *arv);

/* funcao: void insereOrdem(pag *pagina, artigo *art, int g)
   *  acao:        função que insere um artigo em uma determinada página de forma ordenada;
   *  entrada:     pagina onde sera feita a inserção, artigo que será inserido e inteiro g que indica a posição na página;
   *  saida:       inteiro com indice de pagina onde deve ser inserido.
*/
void insereOrdem(pag *pagina, artigo *art, int g);

/* funcao: pag *cisao(FILE *arq, infoArvore *arv, pag *P, pag *pai)
   *  acao:        função que faz cisão das páginas;
   *  entrada:     ponteiro para arquivo que contem a arvore, ponteiro para bloco de informações da árvore, página P, página pai;
   *  saida:       Retorna a página pai..
*/
pag *cisao(FILE *arq, infoArvore *arv, pag *P, pag *pai);


/* funcao: void insereArvoreB(FILE *arq, artigo *art, int existeArq);
   *  acao:        função que insere um aritgo na árvore B;
   *  entrada:     ponteiro para arquivo que contem a arvore, ponteiro para o artigo, inteiro que indica se o arquivo já existia;
   *  saida:       sem saída.
*/
void insereArvoreB(FILE *arq, artigo *art, int existeArq);

/* funcao: void pedeArtigo(artigo *art)
   *  acao:        Função que pede dados do Artigo;
   *  entrada:     ponteiro para o artigo;
   *  saida:       sem saída.
*/
void pedeArtigo(artigo *art);


/* funcao: int concatenarPaginas(FILE *arq, pag* pagP, pag *pagQ, pag *pagPai, int posW)
   *  acao:        Função que concatena páginas;
   *  entrada:     ponteiro para o arquivo que contém a árvore, ponteiro para página pagP, 
   *  ponteiro para página pagQ, ponteiro para página pagPai, inteiro posW;
   *  saida:       inteiro que indica o índice da raiz.
*/
int concatenarPaginas(FILE *arq, pag* pagP, pag *pagQ, pag *pagPai, int posW);

/* funcao: void redistribuirPaginas(FILE *arq, pag* pagP, pag *pagQ, pag *pagPai, int posW)
   *  acao:        Função que redistribui as chaves nas páginas;
   *  entrada:     ponteiro para o arquivo que contém a árvore, ponteiro para página pagP, 
   *  ponteiro para página pagQ, ponteiro para página pagPai, inteiro posW;
   *  saida:       sem saida.
*/
void redistribuirPaginas(FILE *arq, pag* pagP, pag *pagQ, pag *pagPai, int posW);

/* funcao: void redistribuirPaginas(FILE *arq, pag* pagP, pag *pagQ, pag *pagPai, int posW)
   *  acao:        Função que remove um artigo da árvore;
   *  entrada:     ponteiro para o arquivo que contém a árvore, ponteiro para o artigo;
   *  saida:       sem saida.
*/
void removeArvoreB(FILE *arq, artigo *art);

/* funcao: void imprimirPaginas(FILE *arq, infoArvore *arv)
   *  acao:        Função que imprime no console as páginas da árvore B;
   *  entrada:     ponteiro para o arquivo que contém a árvore, ponteiro para infoArvore;
   *  saida:       sem saida.
*/
void imprimirPaginas(FILE *arq, infoArvore *arv);


/* funcao: void mostrarArtigo(FILE *arq, int *pt, int *g)
   *  acao:        Função que imprime no console um artigo;
   *  entrada:     ponteiro para o arquivo que contém a árvore, ponteiro para inteiro pt,
   *  ponteiro para inteiro g;
   *  saida:       sem saida.
*/
void mostrarArtigo(FILE *arq, int *pt, int *g);

#endif
