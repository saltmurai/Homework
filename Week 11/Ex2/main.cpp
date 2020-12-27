#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Complex
{
    T real, imag;

public:
    T getReal() { return T; }
    T getImag() { return T; }
    Complex<T>(T r = 0, T i = 0) : real(r), imag(i) {}
    Complex<T> operator+(const Complex<T> &b) const
    {
        Complex z(real + b.real, imag + b.imag);
        return z;
    }
    Complex<T> operator-(const Complex<T> &b) const
    {
        return Complex(real - b.real, imag - b.imag);
    }
    //(a + bi)(c + di) = (ac - bd) + (ad + bc)i
    Complex<T> operator*(const Complex<T> &b) const
    {
        Complex z(real * b.real - b.imag * imag, real * b.imag + imag * b.real);
        return z;
    }
    Complex<T> operator/(const Complex<T> &b) const
    {
        int x = (((this->real) * (b.real)) + ((this->imag) * (b.imag))) / (pow(b.real, 2) + pow(b.imag, 2));
        int y = (((this->real) * (this->imag)) - ((this->real) * (b.imag))) / (pow(b.real, 2) + pow(b.imag, 2));
        Complex z(x,y);
        return z;
    }
    Complex<T> &operator+=(const Complex<T> &b) 
    {
        this->real += b.real;
        this->imag += b.imag;
        return *this;
    }
    Complex<T> &operator-=(const Complex<T> &b) 
    {
        this->real -= b.real;
        this->imag -= b.imag;
        return *this;
    }
    template<typename U>
    friend ostream &operator<<(ostream &os, const Complex<U> &z);
};

ostream &operator<<(ostream &os, const Complex<U> &z)
{
    if (z.imag >= 0)
        os << z.real << " + " << z.imag << "i";
    else
    {
        os << z.real << " - " << z.imag << "i";
    }
    return os;
}

int main()
{
    cout << "Tao cac so phuc B(4, 5), C(6, 7), D(8, 9), E(-3, 5) " << endl;
    Complex A, B(4, 5), C(6, 7), D(8, 9), E(-3, 5);
    B += C;
    cout << "B += C; B = " << B << endl;
    cout << "A =  B*C + (D-E)" << endl;
    A =  B*C + (D-E);
    cout << "A = " << A;
}
