#include <algorithm>
#include<iostream>
#include<vector>
#include<iterator>
#include<array>
using namespace std;
void Distincte(int arr[], int n){
	// sa se afiseze elementele distincte din array
	std::cout << "Elementele distincte din sir sunt: \n";
	bool ok;
	std::cout << arr[0]<<" ";
	for (int i = 1; i < n; i++)
	{
		ok = 1;
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] == arr[i])
				ok = 0;
		if (ok == 1)
			std::cout << arr[i] << " ";
	}

}
bool IsCool( int arrCool[],int n){
	/*
	std::cout << "Valoarea lui n este: " << n << std::endl;*/
	std::sort(arrCool, arrCool + n);
	if (arrCool[0] != (arrCool[n - 1] - n+1))
		return false;
	for (int i = 0; i <n-1; i++)
	{
		if (arrCool[i] == (arrCool[i + 1]))
			return false;
	}
	return true;
}

int main()
{
	int maxs = 0, poz=0;
	bool cool = false;
	int h = 0;
	int const n=11;
	int arr[n]= { 1, 5, 3, 2, 4, 6, 3, 4, 2, 0, 1 };
	int const k=3;
	//TO DO: sa se afiseze n si k si sa se citeasca numerele de la tastatura 
	for (int t = 0; t < n; ++t)
		std::cout << arr[t] << " ";
	std::cout << std::endl;
	int SecArr[k];
	int arrC[k];
	for (int i = 0; i <= n - k; i++)
	{
		h = 0;
		for (int j = i; j < i + k; j++)
		{
			SecArr[h] = arr[j];
			h++;
		}
		for (int t = 0; t < k; ++t)
			arrC[t]=SecArr[t];
		if (IsCool(arrC,k))
		{
			cool = true;
			poz=*std::max_element(arr+i, arr + k+i);
			if (arr[poz] > maxs)
				maxs = arr[poz];
			std::cout << "Aceasta secventa este COOL: ";
			for (int t = 0; t < k; ++t)
				{
					std::cout << SecArr[t] << " ";
				}
			std::cout << std::endl;
		}
	}
	
	if (cool == false)
		std::cout << "Nu avem nicio secventa cool in sir\n";
	else
		std::cout << "Elementul maxim dintr-o sectiune cool este: " << maxs << std::endl;
	Distincte(arr, n);
	
	return 0; 
	

}
