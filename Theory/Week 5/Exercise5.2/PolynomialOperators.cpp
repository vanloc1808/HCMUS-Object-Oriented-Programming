#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include "Polynomial.h"


///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////OPERATORS/////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

//ARITHMETIC OPERATORS//

Polynomial Polynomial::operator+(const Polynomial& p) {
    int degree = std::max(this->m_degree, p.m_degree);
    double* coeff = new double[degree + 1];

    for (int i = 0; i <= degree; i++) {
        double temp = 0;
        if (degree - i <= this->m_degree) {
            temp += this->m_coefficients[this->m_degree - degree + i];
        }

        if (degree - i <= p.m_degree) {
            temp += p.m_coefficients[p.m_degree - degree + i];
        }

        coeff[i] = temp;

    }

    Polynomial ans(degree, coeff);
    ans.simplify();

    delete[]coeff;
    coeff = nullptr;

    return ans;
}

Polynomial Polynomial::operator-(const Polynomial& p) {
    int degree = std::max(this->m_degree, p.m_degree);
    double* coeff = new double[degree + 1];

    for (int i = 0; i <= degree; i++) {
        double temp = 0;
        if (degree - i <= this->m_degree) {
            temp += this->m_coefficients[this->m_degree - degree + i];
        }

        if (degree - i <= p.m_degree) {
            temp -= p.m_coefficients[p.m_degree - degree + i];
        }

        coeff[i] = temp;

    }

    Polynomial ans(degree, coeff);
    ans.simplify();

    delete[]coeff;
    coeff = nullptr;

    return ans;
}

Polynomial Polynomial::operator*(const Polynomial& p) {
    int degree = this->m_degree + p.m_degree;
    double* coeff = new double[degree + 1];

    for (int i = 0; i <= degree; i++) {
        coeff[i] = 0;
    }

    std::vector<std::pair<double, int>> pa;

    for (int i = 0; i <= this->m_degree; i++) {
        for (int j = 0; j <= p.m_degree; j++) {
            double c = this->m_coefficients[i] * p.m_coefficients[j];
            int d = this->m_degree - i + p.m_degree - j;
            std::pair<double, int> temp = std::make_pair(c, d);
            pa.push_back(temp);
        }
    }

    for (int i = 0; i < pa.size(); i++) {
        std::pair<double, int> temp = pa[i];

        int idx = degree - temp.second;
        double c = temp.first;

        coeff[idx] += temp.first;
    }

    Polynomial ans(degree, coeff);
    ans.simplify();

    delete[]coeff;
    coeff = nullptr;
    
    return ans;
}

Polynomial Polynomial::operator/(const Polynomial& p) {
    int degree = std::max(this->m_degree - p.m_degree, 0);
    double* coeff = new double[degree + 1];

    Polynomial q(*this);

    int i = 0;
    for (; ; i++) {
        if (q.m_degree < p.m_degree) {
            break;
        }

        coeff[i] = q.m_coefficients[0] / p.m_coefficients[0];
        int curDeg = degree - i;
        double* curCoeff = new double[curDeg + 1];

        curCoeff[0] = coeff[i];
        for (int j = 1; j <= curDeg; j++) {
            curCoeff[j] = 0;
        }

        Polynomial temp(curDeg, curCoeff);
        delete[]curCoeff;
        curCoeff = nullptr;

        q = q - temp * p;
    }

    for (i; i <= degree; i++) {
        coeff[i] = 0;
    }

    Polynomial ans(degree, coeff);

    return ans;

} 

Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (*this == p) {
        return *this;
    }
    this->m_degree = p.m_degree;

    if (this->m_coefficients) {
        delete[]this->m_coefficients;
        //this->m_coefficients = nullptr;
    }

    this->m_coefficients = new double[this->m_degree + 1];

    for(int i = 0; i <= this->m_degree; i++) {
        this->m_coefficients[i] = p.m_coefficients[i];
    }

    return *this;
}

bool Polynomial::operator>(const Polynomial& p) {
    if (this->compare(p) == 1) {
        return true;
    }

    return false;
}

bool Polynomial::operator<(const Polynomial& p) {
    if (this->compare(p) == -1) {
        return true;
    }

    return false;
}

bool Polynomial::operator==(const Polynomial& p) {
    if (this->m_degree != p.m_degree) {
        return false;
    }

    int deg = this->m_degree;
    for (int i = 0; i <= deg; i++) {
        if (this->m_coefficients[i] != p.m_coefficients[i]) {
            return false;
        }
    }

    return true;
}

bool Polynomial::operator>=(const Polynomial& p) {
    if (*this < p) {
        return false;
    }

    return true;
}

bool Polynomial::operator<=(const Polynomial& p) {
    if (*this > p) {
        return false;
    }

    return true;
}

bool Polynomial::operator!=(const Polynomial& p) {
    if (*this == p) {
        return false;
    }

    return true;
}

//CALCULUS OPERATORS//
Polynomial Polynomial::operator!() {
    return this->derivative();
}

Polynomial Polynomial::operator~() {
    return this->integral();
}

std::istream& operator>>(std::istream& inDev, Polynomial& p) {
    int deg;
    inDev >> deg;
    if (deg < 0) {
        deg = 0;
    }
    
    p.m_degree = deg;
    
    p.m_coefficients = new double[deg + 1];
    for (int i = 0; i <= deg; i++) {
        inDev >> p.m_coefficients[i];
    }

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, Polynomial& p) {
    for (int i = 0; i <= p.m_degree; i++) {
        if (i == p.m_degree && p.m_coefficients[i] == 0) {
            outDev << p.m_coefficients[i];
        }
        if (p.m_coefficients[i] == 0) {
            continue;
        }

        outDev << p.m_coefficients[i];
        if (i < p.m_degree) {
            outDev << "x^" << p.m_degree - i << " + ";
        }
    }
    outDev << "\n";

    return outDev;
}