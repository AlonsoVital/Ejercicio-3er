#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find (int lista[], int n)
{
	int a, index;
	
	a=1000000;
	index=-1;
		
	for(int i=0; i<n; i++)
		if(lista[i]<a)
		{
			a=lista[i];
			index=i;
		}
	
	return index;
}

int find2 (int lista[], int n)
{
	int a, index;
	
	a=-1000000;
	index=-1;
		
	for(int i=0; i<n; i++)
		if(lista[i]>a)
		{
			a=lista[i];
			index=i;
		}
	
	return index;
}

float prom (int lista[], int n)
{
	float sum=0.0;
	int i;
	
	for(i=0; i<n; i++)
	{
		sum+= lista[i];
	}
	
	return sum/n;
}

float med (int lista[], int n)
{
	int cam[n];
	int i, c, t, j;
	
	for(i=0; i<n; i++)
	{
		cam[i]=lista[i];
	}
	
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(cam[j]>cam[j+1])
			{
				c=cam[j];
				cam[j]=cam[j+1];
				cam[j+1]=t;
			}
		}
	}
	
	if(n%2!=0)
	{
		return cam[n/2];
	}
	
	return (cam[(n-1)/2]+cam[n/2])/2.0;
}

/*
int mod(int lista[], int n)
{
	int moda, datos[0];
	int cuent=0;
	int cuent2=1;
	int i;
	
	moda=datos[0];
	
	for(i=1; i<n; i++)
	{
		if(datos[i]==datos[i-1])
		{
			cuent2++;
		}
		else 
		{
			if (cuent2>cuent)
			{
				cuent=cuent2;
				moda=datos[i-1];
			}
			
			cuent2=1;
		}
	}
	
	return moda;
}

/*
int mod(int lista[], int frecu[], int n)
{
	int moda;
	int num[0];
	int frec=0;
	int i;
	
	moda=num[0];
	
	for(i=0; i<n; i++)
	{
		if(frecu[i]>frec)
		{
			frec=frecu[i];
			moda=num[i];
		}
	}

	return moda;
}
*/

int mod(int lista[], int n)
{
	int max=0;
	int moda=lista[0];
	int i, j;
	
	for(i=0; i<n; i++)
	{
		int count=1;
		for(j=i+1; j<n; j++)
		{
			if(lista[i]==lista[j])
			{
				count++;
			}
		}
		
		if(count>max)
		{
			moda=lista[i];
			max=count;
		}
	}
	
	return moda;
}
int main()
{
	int i, j, n, temp=0, posicion=0;
	srand(time(NULL));
	printf("De cuantos numeros quieres el arreglo: \n");
	scanf("%d", &n);
	int lista[n];
	
	for(i=0; i<n; i++)
	{
		lista[i]= rand()%(30)+1;
	}
	
	printf("Lista sin ordenar: \n");
	
	for(i=0; i<n; i++)
	{
		printf(" %d ", lista[i]);
	}
	
	printf("\n");
	
	for(i=0; i<n; i++)
	{
		posicion=i;
		
		for(j=i+1; j<n; j++)
		{
			if(lista[posicion]>lista[j])
				posicion = j;
		}
		
		if(posicion!=i)
		{
			temp=lista[i];
			lista[i]=lista[posicion];
			lista[posicion]=temp;
		}
	}
	
	printf("Lista ordenada: \n");
	
	for(i=0; i<n; i++)
	{
		printf(" %d ", lista[i]);
	}
	
	printf("\n\nElemento Menor: %d", lista[find(lista, n)]);
	
	printf("\nElemento Mayor: %d", lista[find2(lista, n)]);
	
	printf("\n");
	
	printf("\nMedia: %f", prom(lista, n));
	printf("\nMediana: %f", med(lista, n));

	printf("\nModa: %d", mod(lista, n));
	
	return 0;
}
