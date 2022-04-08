#include "header.h"
using namespace std;

void SortAll(int r)
{
	long long perm10 = 0, perm100 = 0, perm1000 = 0, perm5000 = 0, perm10000 = 0, perm20000 = 0, perm50000 = 0;
	long long comp10 = 0, comp100 = 0, comp1000 = 0, comp5000 = 0, comp10000 = 0, comp20000 = 0, comp50000 = 0;
	cout << "\n\n        Кiлькiсть порiвнянь" << "        Кiлькiсть перестановок\n";

	long long* arr10 = CreateArr(10, r);
	BubbleSort(arr10, 10, perm10, comp10);
	cout << setw(7) << "10:" << setw(20) << comp10 << setw(30) << perm10 << endl;
	delete[] arr10;

	long long* arr100 = CreateArr(100, r);
	BubbleSort(arr100, 100, perm100, comp100);
	cout << setw(7) << "100:" << setw(20) << comp100 << setw(30) << perm100 << endl;
	delete[] arr100;

	long long* arr1000 = CreateArr(1000, r);
	BubbleSort(arr1000, 1000, perm1000, comp1000);
	cout << setw(7) << "1000:" << setw(20) << comp1000 << setw(30) << perm1000 << endl;
	delete[] arr1000;

	long long* arr5000 = CreateArr(5000, r);
	BubbleSort(arr5000, 5000, perm5000, comp5000);
	cout << setw(7) << "5000:" << setw(20) << comp5000 << setw(30) << perm5000 << endl;
	delete[] arr5000;

	long long* arr10000 = CreateArr(10000, r);
	BubbleSort(arr10000, 10000, perm10000, comp10000);
	cout << setw(7) << "10000:" << setw(20) << comp10000 << setw(30) << perm10000 << endl;
	delete[] arr10000;

	long long* arr20000 = CreateArr(20000, r);
	BubbleSort(arr20000, 20000, perm20000, comp20000);
	cout << setw(7) << "20000:" << setw(20) << comp20000 << setw(30) << perm20000 << endl;
	delete[] arr20000;

	long long* arr50000 = CreateArr(50000, r);
	BubbleSort(arr50000, 50000, perm50000, comp50000);
	cout << setw(7) << "50000:" << setw(20) << comp50000 << setw(30) << perm50000 << endl;
	delete[] arr50000;
}

void SortAndOutput100(int r)
{
	long long perm100 = 0, comp100 = 0;
	long long* arr100 = CreateArr(100, r);
	cout << "\n\nВихiдний масив:\n";
	OutputArr(arr100, 100);
	BubbleSort(arr100, 100, perm100, comp100);
	cout << "Вiдсортований масив:\n";
	OutputArr(arr100, 100);
	cout << "     |                     |                        |"
		<< "\n  n  | Кiлькiсть порiвнянь |" << " Кiлькiсть перестановок |\n"
		<< "_____|_____________________|________________________|\n";
	cout << "  100|" << setw(21) << comp100 << "|" << setw(24) << perm100 << "|" << endl;
	delete[] arr100;
}

void SortAndOutput10_100_1000(long long* arr10, long long* arr100, long long* arr1000)
{
	cout << "\n\nВихiднi масиви:\n";
	cout << setw(7) << "10:"; OutputArr(arr10, 10);
	cout << endl;
	cout << setw(7) << "100:"; OutputArr(arr100, 100);
	cout << setw(7) << "1000:"; OutputArr(arr1000, 1000);
	BubbleSort(arr10, 10);
	BubbleSort(arr100, 100);
	BubbleSort(arr1000, 1000);
	cout << "\nВiдсортованi масиви:\n";
	cout << setw(7) << "10:"; OutputArr(arr10, 10);
	cout << endl;
	cout << setw(7) << "100:"; OutputArr(arr100, 100);
	cout << setw(7) << "1000:"; OutputArr(arr1000, 1000);
}

void OutputArr(long long arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (i % 20 != 19)
			cout << setw(7) << arr[i];
		else
			cout << setw(7) << arr[i] << endl;
	}
	cout << endl;
}

long long* CreateArr(int n, int r)
{
	srand(time(NULL));
	long long* arr = new long long[n];
	if (r == 1) {
		for (int i = 0; i < n; ++i)
			arr[i] = i + 1;
	}
	else if (r == 2) {
		for (int i = 0; i < n; ++i)
			arr[i] = n - i;
	}
	else {
		for (int i = 0; i < n; ++i)
		{
			arr[i] = i + 1;
		}
		srand(time(NULL));
		for (int i = 0; i < n; ++i) {
			int temp = arr[i];
			int k = rand() % n;
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
	return arr;
}

void BubbleSort(long long arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - 1; ++j)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void BubbleSort(long long arr[], int n, long long& perm, long long& comp)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - 1; ++j)
		{
			comp++;
			if (arr[j] > arr[j + 1])
			{
				perm++;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}
