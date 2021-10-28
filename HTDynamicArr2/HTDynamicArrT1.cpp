#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArr(const int* arr, size_t size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << '\t';
}

void fillArray(int* arr, size_t size, int choose)
{
	if (choose == 1)
	{
		for (int i = 0; i < size; ++i)
		{
			cout << "\nPlease enter " << i + 1 << " array element: ";
			cin >> arr[i];
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % (100 + 100) - 100;
	}
}

size_t sizeCheck(const int* arr1,const int* arr2, size_t size1, size_t size2)
{
	size_t counter = 0;
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			if (arr1[i] == arr2[j])
			{
				++counter;
				for (int k = i + 1; k < size1; ++k)
				{
					if (arr1[i] == arr1[k])
					{
						--counter; 
						break;
					}
				}
				break;
			}
		}
	}

	return counter;
}

void Task1(const int* arr1, const int* arr2, int* arr3, size_t size1, size_t size2, size_t size3)
{
	size_t counter = 0;
	for (int i = 0; i < size1; ++i)
	{
		if (counter == size3) //Чтобы не делать лишних итераций цикла
			return;
		for (int j = 0; j < size2; ++j)
		{
			if (arr1[i] == arr2[j])
			{
				arr3[counter] = arr1[i];
				++counter;
				for (int k = i + 1; k < size1; ++k)
				{
					if (arr1[i] == arr1[k])
					{
						--counter;
						break;
					}
				}
				break;
			}
		}
	}
}

int main()
{
	int choose;
	size_t size1, size2, size3;
	srand(time(0));
		
	cout << "Please, enter size M for array A[M]: ";
	cin >> size1;
	cout << "\nPlease, enter size N for array B[N]: ";
	cin >> size2;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	cout << "\nHow do you want to fill array A[M]?\n1 - Manual input.\nOther - Randomly (from -100 to 100)\nEnter: ";
	cin >> choose;
	fillArray(arr1, size1, choose);
	cout << "\nHow do you want to fill array B[N]?\n1 - Manual input.\nOther - Randomly (from -100 to 100)\nEnter: ";
	cin >> choose;
	fillArray(arr2, size2, choose);

	cout << "\nA[" << size1 <<"]:\n";
	printArr(arr1, size1);
	cout << "\nB[" << size2 << "]:\n";
	printArr(arr2, size2);

	size3 = sizeCheck(arr1, arr2, size1, size2);
	if (!size3)
	{
		cerr << "\nThere is 0 elements for this task.";
		delete[] arr1, arr2;
		return 1;
	}

	int* arr3 = new int[size3];
	Task1(arr1, arr2, arr3, size1, size2, size3);

	cout << "\nArr3[" << size3 << "]:\n";
	printArr(arr3, size3);

	delete[] arr1, arr2, arr3;
	return 0;
}