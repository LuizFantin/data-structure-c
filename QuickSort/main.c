#include<stdio.h>

void quickSort(int* V,int inicio, int fim);
int particiona(int* V,int inicio, int fim);

int main()
{
    int v[5] = {3,4,2,5,1};

    quickSort(v,0,4);

    printf("%d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);

    return 0;
}

void quickSort(int* v,int inicio, int fim)
{
    int pivo;
    if(fim>inicio)
    {
        pivo = particiona(v,inicio,fim);
        quickSort(v,inicio,pivo-1);
        quickSort(v,pivo+1,fim);
    }
}


int particiona(int* v,int inicio, int fim)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];

    while(esq < dir)
    {
        while(v[esq] <= pivo)
            esq++;
        while(v[dir] > pivo)
            dir--;
        if(esq < dir)
        {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}
