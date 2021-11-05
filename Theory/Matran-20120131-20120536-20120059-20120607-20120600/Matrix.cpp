#include <iostream>
using namespace std;

template <class T>
class Matrix
{
private:
    int _soDong;
    int _soCot;
    T **_arr;

public:
    Matrix();
    Matrix(int soDong, int soCot)
    {
        this->_soCot = soCot;
        this->_soDong = soDong;

        this->_arr = new T *[this->_soDong];

        for (int i = 0; i < this->_soCot; i++)
        {
            this->_arr[i] = new T[this->_soCot];
            for (int j = 0; j < this->_soCot; j++)
                this->_arr[i][j] = 0;
        }
    }
    Matrix operator=(const Matrix &matrix)
    {
        this->_soCot = matrix._soCot;
        this->_soDong = matrix._soDong;

        this->_arr = new T *[this->_soDong];

        for (int i = 0; i < this->_soCot; i++)
        {
            this->_arr[i] = new T[this->_soCot];
            for (int j = 0; j < this->_soCot; j++)
                this->_arr[i][j] = matrix._arr[i][j];
        }

        return *this;
    }

    ~Matrix()
    {
        for (int i = 0; i < this->_soDong; i++)
        {
            if (this->_arr[i])
            {
                delete[] this->_arr[i];
            }
        }

        if (this->_arr)
        {
            delete[] this->_arr;
        }
    }

    T findMax()
    {
        T maxValue = this->_arr[0][0];

        for (int i = 0; i < this->_soDong; i++)
        {
            for (int j = 0; j < this->_soCot; j++)
            {
                if (this->_arr[i][j] > maxValue)
                {
                    maxValue = this->_arr[i][j];
                }
            }
        }

        return maxValue;
    }

    T *&operator[](const int &index) const
    {
        if (index < _soDong)
            return _arr[index];
        return nullptr;
    }
    friend istream& operator>>(istream &is, const Matrix<T> &m) {
        is >> m._soDong >> m._soCot;

        m._soCot = soCot;
        m._soDong = soDong;

        m_arr = new T *[m._soDong];

        for (int i = 0; i < m._soCot; i++)
        {
            m._arr[i] = new T[m._soCot];
            for (int j = 0; j < m._soCot; j++)
                m._arr[i][j] = 0;
        }
        
        for (int i = 0; i < m._soDong; i++)
        {
            for (int j = 0; j < m._soCot; j++)
            {
                is >> m._arr[i][j];
            }

    }
    return is;

    }
    friend ostream& operator<<(ostream &os, const Matrix<T> &m);
};


template <class T>
ostream &operator<<(ostream &os, const Matrix<T> &m)
{
    for (int i = 0; i < m._soDong; i++)
    {
        for (int j = 0; j < m._soCot; j++)
        {
            os << m._arr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main()
{
    Matrix<int> ma(4, 5);

    cout << ma;
    return 0;
}