#include<stdio.h>

void bubbleSort(int* v, int tam);

int main()
{
    int v[5] = {5,1,2,4,3};

    bubbleSort(v,5);

    printf("%d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);

    return 0;
}

void bubbleSort(int* v, int tam)
{
    int i, continua, aux, fim = tam;
    do
    {   
        continua = 0;
        for(i=0;i<(fim-1);i++)
        {
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = 1;
            }
        }
        fim--;
    }while(continua!=0);
}