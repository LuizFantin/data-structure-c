/*
    input: a unsorted array
    output: a sorted array using Heap Sort Algorithm
*/

#include<stdio.h>

void heapSort(int* v,int N);
void criaHeap(int* v,int inicio, int fim);

int main()
{
    int v[5] = {3,4,2,5,1};

    heapSort(v,5);

    printf("%d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);

    return 0;
}

void criaHeap(int* v, int inicio, int fim)
{
    int aux = v[inicio];
    int j = inicio*2+1;
    while(j <= fim)
    {
        if(j < fim)
        {
            if(v[j] < v[j+1])
                j = j + 1;
        }

        if(aux < v[j])
        {
            v[inicio] = v[j];
            inicio = j;
            j = 2*inicio + 1;
        }
        else
            j = fim + 1;
    }
    v[inicio] = aux;
}

void heapSort(int* v, int N)
{
    int i, aux;
    for(i=(N-1)/2; i>=0; i--)
        criaHeap(v,i,N-1);
    for(i = N-1; i >= 1; i--)
    {
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v,0,i-1);
    }
}