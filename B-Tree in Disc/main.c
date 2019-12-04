#include "arvoreB.h"


void menu(FILE *arq, unsigned short int arqVazio)
{
    int op = 0;
    int resp = 1;
    int chave = 0;
    int pt = 0;
    int f = 0;
    int g = 0;

    artigo *art;
    infoArvore *arv;

    art = (artigo*)malloc(sizeof(artigo));
    arv = criaArvore();
    if(!arqVazio)
    {
        rewind(arq);
        fread(arv, sizeof(infoArvore), 1, arq);
    }

    do
    {
        printf("\n---------------------------------\n");
        printf("(1) - Inserir artigo na arvore B\n");
        printf("(2) - Buscar artigo na arvore B\n");
        printf("(3) - Remover artigo da arvore B\n");
        printf("(4) - Imprimir estrutura da arvore B\n");
        printf("\nInforme a operacao desejada\n:::");
        scanf("%d", &op);

        if(op!=1 && op!=2 && op!=3 && op!=4){
			printf("\nOperacao invalida!\n");
			continue;
		}
        else if(op == 1)
        {
            pedeArtigo(art);
            if(!arqVazio)
                insereArvoreB(arq, art, 1);
            else
            {
                insereArvoreB(arq, art, 0);
                arqVazio = 0;
            }
        }
        else if(op == 2)
        {
            if(!arqVazio)
            {
                printf("\nInforme o id do artigo buscado: ");
				scanf("%d", &chave);
				
				buscaArvoreB(arq, &pt, chave, &f, &g);
				if(f==0)
					printf("\nArtigo nao encontrado!");
				else{
					printf("\nO artigo foi encontrado na pagina %d, na posicao %d", pt, g);
                    mostrarArtigo(arq,&pt,&g);
                }
            }
            else
                printf("\nNao foi possivel buscar, pois a arvore esta vazia!");
        }
        else if(op == 3)
        {
            printf("Digite o ID do artigo a ser removido: ");
            scanf("%d",&(art->id));
            removeArvoreB(arq, art);
        }
        else
        {
            imprimirPaginas(arq, arv);
        }
        
        printf("\n\n\nDeseja realizar outra operacao? \n(1) - Sim\n(2) - Nao\n::: ");
		scanf("%d", &resp);
    } while (resp == 1);


    free(art);
    free(arv);

    return;
}


int main()
{
    FILE *arq;
    int arqVazio = 0;

    arq = fopen(fileName, "rb+");

    if(arq == NULL)
    {
        arqVazio = 1;
        printf("\nArquivo inexistente\nCriando um arquivo...");
        arq = fopen(fileName, "wb+");
        if(arq != NULL)
        {
            printf("\nArquivo criado com sucesso\n\n");
            menu(arq, arqVazio);
            fclose(arq);
        }
        else
        {
            printf("\nNao foi possivel criar o arquivo");
            printf("\nO programa sera encerrado\n\n");
        }
    }
    else
    {
        menu(arq, arqVazio);
        fclose(arq);
    }
    return 0;
}