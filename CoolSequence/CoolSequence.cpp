#include <algorithm>
#include<iostream>
#include<vector>
#include<iterator>
#include<array>
using namespace std;
bool IsCool( int arrCool[],int n){
	
	std::cout << "Valoarea lui n este: " << n << std::endl;
	std::sort(arrCool, arrCool + n);
	/*for (int i = 0; i < n ; i++)
	{
		std::cout << arrCool[i] << " ";
	}*/
	//std::cout << std::endl;
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
	int const n=10;
	int arr[n]= { 1, 5, 3, 2, 4, 6, 3, 4, 2, 0 };
	int const k=5;
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
			std::cout << SecArr[t] << " ";
		std::cout << std::endl;
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
	std::cout << "Elemntul maxim dintr-o sectiune cool este: " << maxs << std::endl;
	

	return 0;
}
