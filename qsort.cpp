#include<iostream>
#include "array.h"
#include<cstdlib>

using namespace std;

void Qsort(Array<int>& v, int ini, int fin)
{
	int i = ini;
	int f = fin;
	int p = v[(i+f)/2];

	while(i<=f)
	{
		while(v[i] < p) i++;
		while(v[f] > p) f--;

		if(i <= f)
		{
			int x = v[i];
			v[i]=v[f];
			v[f]=x;
			i++;
			f--;
		}
	}
	if(ini<f) Qsort(v, ini, f);
	if(i<fin) Qsort(v, i, fin);

}


int main()
{
	Array<int> arr(10);

	for(int i=0; i<arr.get_size();i++)
	arr[i]=rand()%100;

	Qsort(arr,0, arr.get_size()-1);

	arr.imprimir();




}
