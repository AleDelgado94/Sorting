#include<iostream>
#include "array.h"
#include<cstdlib>

using namespace std;

/*******************************************************
TRAZA:

44			55	12	42	94	18	6	67	
 0			 1   2   3   4   5  6    7    POS
ordenada	No ordenada

//////////////////////////////////////////////////////

i=1

44 < 55		j=1
valor=55

44	55	12	42	94	18	6	67

//////////////////////////////////////////////////////

i=2

valor =12

12<55, 12<44

12	44	55	42	94	18	6	67

///////////////////////////////////////////////////////

i=3

valor = 42

12	42	44	55	94	18	6	67

///////////////////////////////////////////////////////

i=4

vector[i]=94

12	42	44	55	94	18	6	67

///////////////////////////////////////////////////////

i=5

vector[i]=18

12	18	42	44	55	94	6	67

///////////////////////////////////////////////////////

i=6

vector[i]=6

6	12	18	42	44	55	94	67

///////////////////////////////////////////////////////

i=7

vector[i]=67

6	12	18	42	44	55	67	94

///////////////////////////////////////////////////////

************************************************************/

void insertar(Array<int>& vector, int i, int x)
{
	
	int j=0;
	vector[0]=x;
	j = i-1;
	
	while((x < vector[j])&&(j>0))
	{
		vector[j+1]=vector[j];
		j--;
	}
	
/*	int j;  
	
	for(int i=1; i<vector.get_size();i++)
	{
		j = i;
		x = vector[i];
		vector[0]=x;
		
		while(x < vector[j-1])
		{
			vector[j]=vector[j-1];
			j--;
		}
		
		vector[j]=x;
	}
	*/
}



void ordenacion_insercion(Array<int>& vector)
{
	for(int i=0; i<vector.get_size(); i++)
			insertar(vector, i, vector[i]);
}


int main()
{
	Array<int> arr(10);
	
	for(int i=0; i<10; i++)
	{
		arr[i]=rand() % 10;
	}
	
	arr.imprimir();
	
	ordenacion_insercion(arr);
	
	arr.imprimir();
	
}

