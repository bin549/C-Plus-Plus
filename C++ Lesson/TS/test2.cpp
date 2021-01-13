#include <iostream>

// 1)动态创建二维数组。
unsigned char** new_array2d(unsigned int row, unsigned int column)
{
	unsigned char** array2d = new unsigned char*[row];
	for (unsigned int i = 0; i < row; i++)
	{
		array2d[i] = new unsigned char[column];
	}
	return array2d;
}

//2)释放二维数组。
void delete_array2d(unsigned char** array2d, unsigned int row)
{
	for (unsigned int i = 0; i < row; i++)
		delete[] array2d[i];
	delete[] array2d;
}

// 3)为二维数组随机赋值，每一个元素的值范围为0~255。
void set_array2d(unsigned char** array2d, unsigned int row, unsigned int column)
{
	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = 0; j < column; j++)
		{
			array2d[i][j] = rand() % 256;
		}
	}
}

// 5) 打印数组。
void print_array1d(unsigned int array[], unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		std::cout << array[i] << "   ";
	}
}
void print_array2d(unsigned char** array2d, unsigned int row, unsigned int column) 
{
	std::cout << std::endl;
	for (unsigned int i = 0; i < row; i++)
	{
		std::cout << std::endl;
		for (unsigned int j = 0; j < column; j++)
		{
			std::cout << array2d[i][j] << "   ";
		}
	}
}


//4)统计数组中的值分别为0~255的个数，也就是0~255这256个数每一个出现的个数。
unsigned int* histgram(unsigned char** array2d, unsigned int row, unsigned int column)
{
	// 思路：循环数组中的值，根据里面的值找到要统计的一维数组索引的位置，找到后将其值自增1
	// 将用于统计的数组全部的值初始化为0
	unsigned int count[256] = {0};
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			count[array2d[i][j]]++;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 256; i++)
	{
		std::cout << count[i] << " ";
	}
	return count;
}

// 6) 根据给定的数组的左角 坐 标、高、宽，取出子数组，如图1所示
unsigned char** get_sub_array(unsigned char** array2d, unsigned int row_index, unsigned int column_index, unsigned int height, unsigned int width)
{

}

// 7)  从所创建的二维数组中，按任意取出3x3的子数组（例如从位置(1,1)取3x3子数组），并将子数组的值转换为0-1值，即大于等于128的为1，小于128为0。
void gray_to_binary(unsigned char** array2d, unsigned int row, unsigned int column);

//8) 对（7）所获得的3x3的二维数组（如图2所示），设每一个元素按顺时针顺序标注为a0,a1,a2,a3,a4,a5,a6,a7,a8共9个元素。现作如下处理：
	//a) 数组四周元素与中间元素作异或运算(两个元素值相同为0，不同为1)，即a0 = a0 ^ a8; a1 = a1 ^ a8; ……; a7 = a7 ^ a8;

	/*b)四周元素与中间元素异或运算后，组成下列四种排列
		1 a0，a1，a2，a3，a4，a5，a6，a7
		2 a2，a3，a4，a5，a6，a7，a0，a1
		3 a4，a5，a6，a7，a0，a1，a2，a3
		4 a6，a7，a0，a1，a2，a3，a4，a5
   	   将上面四种排列转换为十进制数，求这个四个十进制数的最小值。*/
unsigned int find_min_value(unsigned char** array2d);

int main()
{
    std::cout << "请输入列数和行数\n"; 
	int row, column;
	std::cin >> row >> column;
	unsigned char** array2d = new_array2d(row, column);
	set_array2d(array2d, row, column);
	print_array2d(array2d, row, column);
	unsigned int* count;
	histgram(array2d, row, column);

	return 0;
}	