#include<iostream>
#include "array.h"
#include<cstdlib>

using namespace std;

void Msort(Array<int> v, int ini, int fin)
{
	if(ini<fin)
	{
	  int cen = (ini+fin)/2;
	  Msort(v, ini, cen);
	  Msort(v, cent+1, fin);
	  Mezcla(v, ini, cen, fin);
	}
}

void Mezcla(Array<int> v, int ini, int cen, int fin)
{
	int i=ini, j=cen+1, k=ini;
	Array<int> aux(v.get_size());

	while((i <= cen) && (j <= fin))
	{
		if(v[i]<v[j])
		{
			aux[k]=v[i];
			i++;
		}
		else
		{
			aux[k]=v[j];
			j++;
		}
	k++;
	}
	if(i > cen)
	while(j <= fin)
	{
		aux[k]=v[j];
		j++;
		k++;
	}
	else
	while(i<=cen)
	{
		aux[k]=v[i];
		i++;
		k++;
	}

	for(int k=ini; k<=fin; k++)
		v[k]=aux[k];

}


int main()
{
	Array<int> arr(10);

	for(int i=0; i<arr.get_size();i++)
	arr[i]=rand()%100;

	Qsort(arr,0, arr.get_size()-1);

	arr.imprimir();




}
