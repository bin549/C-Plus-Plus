#include "student.h"
#include <iostream>

using namespace std;

class Classes
{
public:
	int total_numbers_;
	int max_score_;
	int min_score_;
	float avg_score_;
	Classes()
	{
		total_numbers_ = 0;
		max_score_ = 0;
		min_score_ = 0;
		avg_score_ = 0;
	}
	Classes(int n)
	{
		total_numbers_ = n;
		GenerteStudentsList(n);
	}
	~Classes()
	{
		delete[] students_;
	}
	void Display()
	{
		FindMaxAvgScore();
		cout << "------学生信息-------" << endl;
		for (int i = 0; i < total_numbers_; i++)
		{
			students_[i].Display();
		}

	}
private:
	student* students_;
	void GenerteStudentsList(int n)
	{
		students_ = new student[n];
		for (int i = 1; i <= n; i++)
		{	
			student stu(i, rand()%101);
			students_[i - 1] = stu;
		}
	}

	void FindMaxAvgScore()
	{
		max_score_ = 0;
		min_score_ = 100;
		avg_score_ = 0;
		float sum_score = 0;
		for (int i = 0; i < total_numbers_; i++)
		{
			sum_score += students_[i].get_score();
			if (max_score_ < students_[i].get_score())
			{
				max_score_ = students_[i].get_score();
			}
			if (min_score_ > students_[i].get_score())
			{
				min_score_ = students_[i].get_score();
			}
		}
		avg_score_ = sum_score / total_numbers_;
		cout << "班级分数统计：" << "\n\t平均分:" << avg_score_ << "\n\t最高分:" << max_score_ << "\n\t最低分:" << min_score_ << endl;
	}
};