
#include <iostream>
#include "Student.h"

using namespace std;
Student::SortType Student::sort_type = Student::BY_NAME;
template <typename T>
bool greater_than(T a, T b);

template <typename T>
bool less_than(T a, T b);

template <typename T>
void Print(T a[], int n);

template <typename T>
void bubble_sort(T arr[], int len, bool (*compare)(T &, T &));

template <typename T>
bool greater_than(T a, T b)
{
	return a > b;
}

template <>
bool greater_than(char a[], char b[])
{
	return strcmp(a, b) > 0;
}

template <typename T>
bool less_than(T a, T b)
{
	return a < b;
}

template <>
bool less_than(char a[], char b[])
{
	return strcmp(a, b) < 0;
}

template <typename T>
void Print(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void bubble_sort(T arr[], int len, bool (*compare)(T &, T &))
{
	for (int i = len - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if ((*compare)(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()
{
	int int_array[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
	int len = (int)(sizeof(int_array) / sizeof(*int_array));
	cout << "origin int array:" << endl;
	Print(int_array, len);
	cout << "sort: ascending order:" << endl;
	bubble_sort(int_array, len, greater_than);
	Print(int_array, len);
	cout << "sort: descending order:" << endl;
	bubble_sort(int_array, len, less_than);
	Print(int_array, len);

	float float_array[] = {17.5f, 19.1f, 0.6f, 1.9f, 10.5f, 12.4f, 3.8f, 19.7f, 1.5f, 25.4f, 28.6f, 4.4f, 23.8f, 5.4f};
	len = (int)sizeof(float_array) / sizeof(*float_array);
	cout << "origin float array:" << endl;
	Print(float_array, len);
	bubble_sort(float_array, len, greater_than);
	cout << "sort: ascending order:" << endl;
	Print(float_array, len);
	bubble_sort(float_array, len, less_than);
	cout << "sort: descending order:" << endl;
	Print(float_array, len);

	const char *const_char_array[] = {"ye", "meng", "jie"};
	len = (int)sizeof(const_char_array) / sizeof(*const_char_array);
	cout << "origin float array:" << endl;
	Print(const_char_array, len);
	bubble_sort(const_char_array, len, greater_than);
	cout << "sort: ascending order:" << endl;
	Print(const_char_array, len);
	bubble_sort(const_char_array, len, less_than);
	cout << "sort: descending order:" << endl;
	Print(const_char_array, len);

	Student student_array[] = {Student("ye", 100), Student("meng", 60), Student("jie", 70)};
	len = (int)sizeof(student_array) / sizeof(*student_array);
	//sort by name
	cout << "sort student object by name------" << endl;
	Student::sort_type = Student::BY_NAME;
	cout << "origin student array:" << endl;
	Print(student_array, len);
	bubble_sort(student_array, len, greater_than);
	cout << "sort by name: ascending order:" << endl;
	Print(student_array, len);
	bubble_sort(student_array, len, less_than);
	cout << "sort by name: descending order:" << endl;
	Print(student_array, len);

	//sort by score
	cout << "sort student object by score------" << endl;
	Student::sort_type = Student::BY_SCORE;
	cout << "origin student array:" << endl;
	Print(student_array, len);
	bubble_sort(student_array, len, greater_than);
	cout << "sort by score: ascending order:" << endl;
	Print(student_array, len);
	bubble_sort(student_array, len, less_than);
	cout << "sort by score: descending order:" << endl;
	Print(student_array, len);
}