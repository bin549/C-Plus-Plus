// 未实现功能
/*  
	Inverse(Matrix<T>& A);
	GaussianKernel(T k, T sigma);template <typename T>
	Matrix<T> GaussianFilte
	Load
*/

#include <initializer_list>
#include <string>
#include <random>
#include <time.h>

using namespace std;

template <class T>
class Matrix
{
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(int rows, int cols, T init_value);
	Matrix(initializer_list<initializer_list<T>> m);
	~Matrix();
	Matrix(const Matrix& mat); 
	Matrix operator=(const Matrix& mat);
	int get_rows() const { return rows_; }
	int get_cols() const { return cols_; }
	void swapRows(int a, int b);
	void Initialize();
	template <class U>
	friend Matrix<U> operator+(const Matrix<U>& A, U k);
	template <class U>
	friend U operator+(U k, const Matrix<U>& A);
	template <class U>
	friend Matrix<U> operator-(const Matrix<U>& A, U k);
	template <class U>
	friend Matrix<U> operator*(const Matrix<U>& A, U k);
	template <class U>
	friend U operator*(U k, const Matrix<U>& A);
	template <class U>
	friend Matrix<U> operator+(const Matrix<U>& A, const Matrix<U>& B);
	template <class U>
	friend Matrix<U> operator-(const Matrix<U>& A, const Matrix<U>& B);
	template <class U>
	friend Matrix<U> operator*(const Matrix<U>& A, const Matrix<U>& B);
	template <class U>
	friend Matrix<U> operator%(const Matrix<U>& A, const Matrix<U>& B);
	template <class U>
	friend Matrix<U> operator/(const Matrix<U>& A, const Matrix<U>& B);
	template <class U>
	friend Matrix<U> operator^(const Matrix<U>& A, U t);
	void printMatrix();
	static Matrix zeros(int rows, int cols);
	static Matrix eye(int size);
	static Matrix randu(int rows, int cols);
	static Matrix randn(int rows, int cols);
	void Load(string filename);						//----
	void Write(string filename);					//----
	T get_mat(int row, int col) { return mat_[row][col]; }
	void set_mat(int row, int col, T val) { mat_[row][col] = val; }
private:
	int rows_;
	int cols_;
	T** mat_;
};

template <typename T>
Matrix<T> AugmentMatrix(Matrix<T>& A, Matrix<T>& B);

template <typename T>
Matrix<T> GaussianElimination(const Matrix<T>& B);

template <typename T>
Matrix<T> Inverse(Matrix<T>& A);		//----

template <typename T>
Matrix<T> GaussianKernel(T k, T sigma);		//----

template <typename T>
Matrix<T> GaussianFilter(Matrix<T> A, Matrix<T> H);		//----

