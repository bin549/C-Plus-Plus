#include "./Matrix.h"

template <class T>
void Matrix<T>::Initialize()
{
	mat_ = new T*[rows_];
	for (int i = 0; i < rows_; i++)
		mat_[i] = new T[cols_];
}

template <class T>
Matrix<T>::Matrix()
{
	rows_ = 1;
	cols_ = 1;
	Initialize();
	mat_[0][0] = (T)0.0;
}

template <class T>
Matrix<T>::Matrix(int rows, int cols)
{
	rows_ = rows;
	cols_ = cols;
	Initialize();
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			mat_[i][j] = (T)0.0;
		}
	}
}

template <class T>
Matrix<T>::Matrix(int rows, int cols, T init_value)
{
	rows_ = rows;
	cols_ = cols;
	Initialize();
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			mat_[i][j] = init_value;
		}
	}
}


template <class T>
Matrix<T>::Matrix(initializer_list<initializer_list<T>> m)
{
	rows_ = m.size(); 

	cols_ = (m.begin())->size();
	Initialize();
	int i = 0, j = 0;
	for (auto row : m)
	{
		for (T column : row)
		{
			mat_[i][j++] = column;
		}
		j = 0;
		i++;
	}
}

template <class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows_; i++)
	{
		delete[] mat_[i];
	}
	delete[] mat_;
}

template <class T>
Matrix<T>::Matrix(const Matrix & m)
{
	rows_ = m.get_rows();
	cols_ = m.get_cols();
	Initialize();
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			mat_[i][j] = m.mat_[i][j];
		}
	}
}

template <class T>
Matrix<T> Matrix<T>::operator=(const Matrix& m)
{
	rows_ = m.get_rows();
	cols_ = m.get_cols();
	Initialize();
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			mat_[i][j] = m.mat_[i][j];
		}
	}
	return (*this);
}

template <class T>
void Matrix<T>::swapRows(int a, int b)
{
	a--;
	b--;
	T *temp = this->mat_[a];
	this->mat_[a] = this->mat_[b];
	this->mat_[b] = temp;
}

template <class T>
Matrix<T> operator+(const Matrix<T>& A, T k)
{
	Matrix<T> m(A);
	for (int i = 0; i < m.rows_; i++)
	{
		for (int j = 0; j < m.cols_; j++)
		{
			m.mat_[i][j] += k;
		}
	}
	return m;
}

template <class T>
T operator+(T k, const Matrix<T>& A)
{
	for (int i = 0; i < A.rows_; i++)
	{
		for (int j = 0; j < A.cols_; j++)
		{
			k += A.mat_[i][j];
		}
	}
	return k;
}

template <class T>
Matrix<T> operator*(const Matrix<T>& A, T k)
{
	Matrix<T> m(A);
	for (int i = 0; i < m.rows_; i++)
	{
		for (int j = 0; j < m.cols_; j++)
		{
			m.mat_[i][j] *= k;
		}
	}
	return m;
}

template <class T>
T operator*(T k, const Matrix<T>& A)
{
	for (int i = 0; i < A.rows_; i++)
	{
		for (int j = 0; j < A.cols_; j++)
		{
			k *= A.mat_[i][j];
		}
	}
	return k;
}

template <class T>
Matrix<T> operator-(const Matrix<T>& A, T k)
{
	Matrix<T> m(A);
	for (int i = 0; i < m.rows_; i++)
	{
		for (int j = 0; j < m.cols_; j++)
		{
			m.mat_[i][j] -= k;
		}
	}
	return m;
}

template <class T>
Matrix<T> operator+(const Matrix<T>& A, const Matrix<T>& B)
{
	if (A.get_rows() != B.get_rows() || A.get_cols() != B.get_cols())
		throw 0;
	Matrix<T> m(A.get_rows(), A.get_cols());
	for (int i = 0; i < A.get_rows(); i++)
	{
		for (int j = 0; j < A.get_cols(); j++)
		{
			m.mat_[i][j] = A.mat_[i][j] + B.mat_[i][j];
		}
	}
	return m;
}

template <class T>
Matrix<T> operator-(const Matrix<T>& A, const Matrix<T>& B)
{
	if (A.get_rows() != B.get_rows() || A.get_cols() != B.get_cols())
		throw 0;
	Matrix<T> m(A.get_rows(), A.get_cols());
	for (int i = 0; i < A.get_rows(); i++)
	{
		for (int j = 0; j < A.get_cols(); j++)
		{
			m.mat_[i][j] = A.mat_[i][j] - B.mat_[i][j];
		}
	}
	return m;
}

template <class T>
Matrix<T> operator*(const Matrix<T>& A, const Matrix<T>& B)
{
	if (A.get_cols() != B.get_rows())
		throw 0;
	Matrix<T> m(A.get_rows(), B.get_cols());

	for (int i = 0; i < A.rows_; i++)
	{
		for (int j = 0; j < B.cols_; j++)
		{
			for (int k = 0; k < A.cols_; k++)
			{
				m.mat_[i][j] += A.mat_[i][k] * B.mat_[k][j];
			}
		}
	}
	return m;
}

template <class T>
Matrix<T> operator%(const Matrix<T>& A, const Matrix<T>& B)
{
	if (A.get_rows() != B.get_rows() || A.get_cols() != B.get_cols())
		throw 0;
	Matrix<T> m(A.get_rows(), A.get_cols());
	for (int i = 0; i < A.get_rows(); i++)
	{
		for (int j = 0; j < A.get_cols(); j++)
		{
			m.mat_[i][j] = A.mat_[i][j] * B.mat_[i][j];
		}
	}
	return m;
}

template <class T>
Matrix<T> operator/(const Matrix<T>& A, const Matrix<T>& B)
{
	if (A.get_rows() != B.get_rows() || A.get_cols() != B.get_cols())
		throw 0;
	Matrix<T> m(A.get_rows(), A.get_cols());
	for (int i = 0; i < A.get_rows(); i++)
	{
		for (int j = 0; j < A.get_cols(); j++)
		{
			m.mat_[i][j] = A.mat_[i][j] / B.mat_[i][j];
		}
	}
	return m;
}

template <class T>
Matrix<T> operator^(const Matrix<T>& A, T t)
{
	if (A.get_rows() != A.get_cols())
		throw 0;
	Matrix<T> B = A;
	Matrix<T> R(A.get_cols(), A.get_cols());
	while (--t > 0)
	{
		for (int i = 0; i < A.rows_; i++)
		{
			for (int j = 0; j < A.rows_; j++)
			{
				for (int k = 0; k < A.rows_; k++)
				{
					R.mat_[i][j] += B.mat_[i][k] * B.mat_[k][j];
				}
			}
		}
		B = R;
	}
	return B;
}


template <class T>
void Matrix<T>::printMatrix()
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			cout << mat_[i][j] << " ";
		}
		cout << endl;
	}
}

template <class T>
Matrix<T> Matrix<T>::zeros(int rows, int cols)
{
	Matrix<T> zerosMatric(rows, cols);
	return zerosMatric;
}

template <class T>
Matrix<T> Matrix<T>::eye(int size)
{
	Matrix<T> eyeMatric(size, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				eyeMatric.mat_[i][j] = 1;
			else
			{
				eyeMatric.mat_[i][j] = 0;
			}
		}
	}
	return eyeMatric;
}

template <class T>
Matrix<T> Matrix<T>::randu(int rows, int cols)
{
	default_random_engine random(time(NULL));
	uniform_int_distribution<T> dis(0, 100);
	Matrix<T> randuMatric(rows, cols);
	for (int i = 0; i < randuMatric.get_rows(); i++)
	{
		for (int j = 0; j < randuMatric.get_cols(); j++)
		{
			randuMatric.mat_[i][j] = dis(random);
		}
	}
	return randuMatric;
}

double gaussrand()
{
	static double V1, V2, S;
	int phase = 0;
	double X;
	if (phase == 0)
	{
		do 
		{
			double U1 = (double)rand() / RAND_MAX;
			double U2 = (double)rand() / RAND_MAX;
			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
		} while (S >= 1 || S == 0);
		X = V1 * sqrt(-2 * log(S) / S);
	}
	else
		X = V2 * sqrt(-2 * log(S) / S);
	phase = 1 - phase;
	return X;
}

template <class T>
Matrix<T> Matrix<T>::randn(int rows, int cols)
{
	Matrix<T> randnMatric(rows, cols);
	for (int i = 0; i < randnMatric.get_rows(); i++)
	{
		for (int j = 0; j < randnMatric.get_cols(); j++)
		{
			randnMatric.mat_[i][j] = gaussrand();
		}
	}
	return randnMatric;
}

template <class T>
void Matrix<T>::Load(string filename)
{
}


template <class T>
void Matrix<T>::Write(string filename)
{
	FILE * fp;
	filename.append("/matrix.txt");
	fopen_s(&fp, filename.c_str(), "w");
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			fprintf(fp, "%d ", mat_[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}


template <typename T>
Matrix<T> AugmentMatrix(Matrix<T>& A,  Matrix<T>& B)
{
	if (A.get_rows() != B.get_rows())
	{
		cout << "两矩阵的增广矩阵两矩阵的行数必须一致" << endl;
		abort();
	}
	Matrix<T> m(A.get_rows(), A.get_cols() + B.get_cols());
	int row, col;
	for (row = 0; row < A.get_rows(); row++)
	{
		for (col = 0; col < A.get_cols(); col++)
			m.set_mat(row, col, A.get_mat(row, col));
	}
	int col_flag = col;
	for (row = 0; row < B.get_rows(); row++)
	{
		for (col = 0; col < B.get_cols(); col++)
			m.set_mat(row, col + col_flag, B.get_mat(row, col));
	}
	return m;
}

template <typename T>
Matrix<T> GaussianElimination(const Matrix<T>& B)
{
	Matrix<T> A = B;
	for (int i = 0; i < A.get_rows() - 1; i++)
	{
		int pos = 0;
		for (int j = 0; j < A.get_cols(); j++)
		{
			if (A.get_mat(i, j))
			{
				pos = j;
				break;
			}
		}

		if (A.get_mat(i, pos) != 1 && A.get_mat(i, pos) != 0)
		{
			T tmp = A.get_mat(i, pos);
			for (int j = pos; j < A.get_cols(); j++)
			{
				A.set_mat(i, j, A.get_mat(i, j) / tmp);
			}
		}

		for (int j = i + 1; j < A.get_rows(); j++)
		{
			if (!A.get_mat(j, pos))
				continue;
			T tmp = A.get_mat(j, pos);
 			for (int k = pos; k < A.get_cols(); k++)
			{
				A.set_mat(j, k, A.get_mat(j, k) - A.get_mat(i, k)*tmp);
			}
		}
	}

	for (int i = A.get_rows() - 1; i > 0; i--)
	{
		int pos = 0;
		for (int j = 0; j < A.get_cols(); j++)
		{
			if (A.get_mat(i, j))
			{
				pos = j;
				break;
			}
		}

		if (A.get_mat(i, pos) != 1 && A.get_mat(i, pos) != 0)
		{
			T tmp = A.get_mat(i, pos);
			for (int j = pos; j < A.get_cols(); j++)
			{
				A.set_mat(i, j, A.get_mat(i, j) / tmp);
			}
		}

		for (int j = 0; j < i; j++)
		{
			if (!A.get_mat(j,pos))
				continue;
			T tmp = A.get_mat(j, pos);
			for (int k = pos; k < A.get_cols(); k++)
			{
				A.set_mat(j, k, A.get_mat(j, k) - A.get_mat(i, k) * tmp);
			}
		}
	}
	return A;
}



template <typename T>
Matrix<T> Inverse(Matrix<T>& A)
{
	if (A.get_rows() != A.get_cols())
	{
		cout << "只有方阵能求逆矩阵" << endl;
		abort();
	}
	// 备份
	Matrix<T> A_Copy(A.get_cols(), A.get_rows);
	A_Copy = A;
	Matrix<T> E = Matrix<int>::eye(A.get_cols());
	// 思路，将原矩阵和单位矩阵进行初等行变换知道原矩阵转换为单位矩阵，此时的原单位矩阵则为逆矩阵
	
}
