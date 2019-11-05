//Erika Barbosa Gomes
//Everson Henrich da Silva
//Luiz Fantin Neto
//Milena Tavares Roas

#include "quickSortExt.h"   

void lerSup(FILE *arqlS, void *reg, int *lS, int nBytes, short int *ordem)
{
    //posiciona o cursor em lS*nBytes distante do início do arquivo
    //E armazena em reg o registro contido nessa posição
    fseek(arqlS, *(lS)*nBytes, SEEK_SET);
    fread(reg, nBytes, 1, arqlS);
    //decrementa o indicador
    (*lS)--;
    //indica que a próxima leitura é lerInf
    *ordem = 0;
}

void lerInf(FILE *arqlI, void *reg, int *lI, int nBytes, short int *ordem)
{
    //posiciona o cursor em lI*nBytes distante do início do arquivo
    //E armazena em reg o registro contido nessa posição
    fseek(arqlI, *(lI)*nBytes, SEEK_SET);
    fread(reg, nBytes, 1, arqlI);
    //incrementa o indicador
    (*lI)++;
    //indica que a próxima leitura é lerSup
    *ordem = 1;
}

void escSup(FILE *arqES, void *reg, int *eS, int nBytes)
{
    //posiciona o cursor em eS*nBytes distante do início do arquivo
    //E escreve nessa posição o conteúdo de reg
    fseek(arqES, *(eS)*nBytes, SEEK_SET);
    fwrite(reg, nBytes, 1, arqES);
    //decrementa o indicador
    (*eS)--;
}

void escInf(FILE *arqEI, void *reg, int *eI, int nBytes)
{
    //posiciona o cursor em eI*nBytes distante do início do arquivo
    //E escreve nessa posição o conteúdo de reg
    fseek(arqEI, *(eI)*nBytes, SEEK_SET);
    fwrite(reg, nBytes, 1, arqEI);
    //incrementa o indicador
    (*eI)++;
}

void inserirArea(void *area, int *areaOcupada, void *reg,int nBytes, int(*comp)(void*,void*))
{
    int i = *areaOcupada; 
    //Insere o registro de forma ordenada na memória primária
    //Deslocando para direita os registros de valor maior que o registro que será inserido
    while(i > 0)
    {
        if(comp(area + ((i-1)*nBytes), reg) > 0)
            memcpy(area + (i*nBytes), area + ((i-1)*nBytes), nBytes);
        else    
            break;
        i--;
    } 
    //incrementa areaOcupada
    memcpy(area + (i*nBytes), reg, nBytes);
    (*areaOcupada)++;
}

void rmvPrimeiroArea(void *area, int *areaOcupada, int nBytes)
{
    int i = 0;
    //Remove o primeiro registro da memória primária
    //Desloca o vetor em uma posição para esquerda
    for(i = 0;i < *areaOcupada; i++)
        memcpy(area + (i*nBytes), area + ((i+1)*nBytes), nBytes);
    //Decrementa areaOcupada
    (*areaOcupada)--;
}

int particao(FILE *arq,int inicio, int fim, int *i, int *j, int tamArea, int nBytes, int(*comp)(void*,void*))
{
    //aloca espaço na memória primária
    void *area = calloc(tamArea, nBytes);
    int areaOcupada = 0;

    //variável de índice
    int k = 0;
    //variáveis que indicam posição:
    //lI - leitura inferior
    //lS - leitura superior
    //eI - escrita inferior
    //eS - escrita Superior
    int lI = inicio;
    int lS = fim;
    int eI = inicio;
    int eS = fim;
    //variável que indica a ordem de leitura
    unsigned short int ordem = 1;
    
    //Armazenam os limites superiores e inferiores da memória primária
    void *limInf = calloc(1, nBytes);
    void *limSup = calloc(1, nBytes);
    //Flag que indica se limSup teve seu valor alterado
    short int lmSupDif = 0;
    //Flag que indica se limInf teve seu valor alterado
    short int lmInfDif = 0;
    
    //Armazena o registro lido/escrito
    void *registro = calloc(1, nBytes);

    //Retorna -1 se não conseguir alocar espaço na memória primária
    if(area == NULL || limInf == NULL || limSup == NULL || registro == NULL)
        return -1;

    //Indicam a posição da área ordenada no arquivo
    (*i) = inicio - 1;
    (*j) = fim + 1;

    while(lS >= lI)
    {
        if(areaOcupada + 1 < tamArea)
        {
            //Preenche a área na memória principal até areaOcupada = tamArea - 1
            //Lendo de forma alternada entre Leitura Superior e Leitura Inferior
            if(ordem == 1)
                lerSup(arq, registro, &lS, nBytes, &ordem);
            else
                lerInf(arq, registro, &lI, nBytes, &ordem);
            
            inserirArea(area, &areaOcupada, registro, nBytes, comp);
        }
        //areaOcupada = tamArea - 1
        else
        {
            //Interrompe, se necessário, a ordem alternada de leitura para evitar que dados sejam sobrescritos
            if(lI == eI)
                lerInf(arq, registro, &lI, nBytes, &ordem);
            else if(lS == eS)
                lerSup(arq, registro, &lS, nBytes, &ordem);
            else
            {
                //Ordem alternada de leitura
                if(ordem == 1)
                    lerSup(arq, registro, &lS, nBytes, &ordem);
                else
                    lerInf(arq, registro, &lI, nBytes, &ordem);
            }
            //Verifica se o valor lido está dentro dos limites de valor da memória primária
            //Se não tiver será escrito na memória secundária sem ser armazenado na memória primária
            if((lmSupDif == 1) && (comp(registro, limSup) > 0))
            {
                (*j) = eS;
                escSup(arq, registro, &eS, nBytes);
            }
            else if((lmInfDif == 1) && (comp(registro, limInf) < 0))
            {
                (*i) = eI;
                escInf(arq, registro, &eI, nBytes);
            }
            else
            {
                //Valor dentro dos limites superior e inferior
                //armazena na memória primária
                inserirArea(area, &areaOcupada, registro, nBytes, comp);
                //memória primária cheia
                if(eI - inicio < fim - eS) 
                {
                    //Se a área a esquerda for menor remove o menor registro da memória primária
                    //Escreve esse registro na memória secundária
                    //atribui a limInf o valor desse registro
                    escInf(arq, area, &eI, nBytes);
                    memcpy(limInf, area, nBytes);
                    //Muda flag para 1(valor alterado)
                    lmInfDif = 1;
                    rmvPrimeiroArea(area, &areaOcupada, nBytes);
                }
                else
                {
                    //senão remove o registro de maior valor da memória primária 
                    //Escreve esse registro na memória secundária
                    //atribui a limSup o valor desse registro
                    escSup(arq, area + ((areaOcupada-1)*nBytes), &eS, nBytes);
                    memcpy(limSup, area + ((areaOcupada-1)*nBytes), nBytes);
                    //Muda flag para 1(valor alterado)
                    lmSupDif = 1;
                    areaOcupada--;
                }
            }
        }
    }
    //Fim da partição
    //Escreve no arquivo enquanto houver registros na memória primária
    //Escrita realizada na posição indicada por eI
    for(k = 0; k < areaOcupada; k++)
        escInf(arq, area + (k*nBytes), &eI, nBytes);

    //Libera a memória alocada
    free(area);
    free(limInf);
    free(limSup);
    free(registro);
    
    return 0;
}

int quickSortExterno(FILE *arq, int inicio, int fim, int tamArea, int nBytes, int (comp)(void*,void*))
 {
    int i = inicio;
    int j = fim;
    int retorno = 0;
    //Se a área tiver mais que 1 registro
    if(fim - inicio > 1)
    {
        //chama partição para a área do arquivo
        retorno = particao(arq, inicio, fim, &i, &j, tamArea, nBytes, comp);
        //Verifica qual das áreas não-ordenadas é menor
        //Chama recursivamente quickSortExterno para essa área
        //Chama recursivamente quickSortExterno para a outra área
        if((i - inicio) > (fim - j))
        { 
            quickSortExterno(arq, j, fim, tamArea, nBytes, comp);
            quickSortExterno(arq, inicio, i, tamArea, nBytes, comp);
        }
        else
        {
            quickSortExterno(arq, inicio, i, tamArea, nBytes, comp);
            quickSortExterno(arq, j, fim, tamArea, nBytes, comp);
        }
    }
    return retorno;
 }
