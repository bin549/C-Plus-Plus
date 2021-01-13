#include <iostream>
using namespace std;

void print_array(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

int find_pairs(int array[], int n, int sum)
{
	int pairs = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i]+array[j] == sum)
			{
				pairs++;
			}
		}
	}
	return pairs;
}

int main()
{
	int array[] ={ 1, 5, 7, 5, 8, 9, 11, 12 };
	int n = sizeof array / sizeof array[0];
	int sum = 12;
	cout << "Original array: ";
	print_array(array, n);
	cout << "\nNumber of pairs whose sum equal to " << sum << " is ";
	cout << find_pairs(array, n, sum) << endl;
	cin.get();
	return 0;
}