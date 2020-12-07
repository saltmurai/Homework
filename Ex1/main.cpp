#include <iostream>
#include <cmath>

using namespace std;

class DT
{
    int n;
    double *a;

public:
    DT();
    DT(int n1);
    DT(const DT &d2); //ham tao sao chep;
    ~DT();
    int getN() { return n; }
    friend ostream &operator<<(ostream &os, const DT &d);
    friend istream &operator>>(istream &is, DT &d);
    DT &operator-()
    {
        for (int i = 0; i <= this->n; i++)
        {
            this->a[i] = -this->a[i];
        }
        return *this;
    }
    DT operator+(DT &d2);
    DT operator-(DT &d2);
    DT operator*(const DT &d2);
    DT &operator=(const DT &d2);
    double operator^(const double &x);
    double *add(DT &d2);
    double *multiply(DT &d2);
    double operator[](int i)
    {
        if (i < 0)
            return double(n);
        else
            return a[i];
    }
};

DT::DT()
{
    this->a = NULL;
    this->n = 0;
    cout << "Su dung ham tao khong doi" << endl;
}

DT::DT(int n1)
{
    this->n = n1;
    this->a = new double[n1 + 1];
    cout << "Su dung ham tao mot doi da thuc bac:" << n1 << endl;
}

DT::~DT()
{
    cout << "\n";
    cout << "Xoa " << a << " tai " << this;
    delete[] a;
}

ostream &operator<<(ostream &os, const DT &d)
{
    cout << d.a[0];
    for (int i = 1; i <= d.n; i++)
    {
        if (d.a[i] >= 0)
        {
            cout << " + " << d.a[i] << "x^" << i;
        }
        else
        {
            cout << " - " << -d.a[i] << "x^" << i;
        }
    }
    return os;
}

istream &operator>>(istream &is, DT &d)
{
    cout << "Ham bac: ";
    is >> d.n;
    d.a = new double[d.n + 1];
    cout << "Nhap he so cho: " << endl;
    for (int i = 0; i <= d.n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> d.a[i];
    }
    return is;
}

DT DT::operator+(DT &d2)
{
    DT sum;
    sum.n = max(n, d2.n);
    sum.a = new double[sum.n + 1];
    sum.a = this->add(d2);
    return sum;
}

DT DT::operator-(DT &d2)
{
    DT sub;
    sub.n = max(n, d2.n);
    sub.a = new double[sub.n + 1];
    sub.a = this->add(-d2);
    return sub;
}

DT DT::operator*(const DT &d2)
{
    DT prod;
    DT d2_clone(d2);
    prod.n = d2.n + n;
    prod.a = new double[prod.n + 1];
    prod.a = this->multiply(d2_clone);
    return prod;
}

DT &DT::operator=(const DT &d2)
{
    if (n != d2.n)
    {
        delete[] a;
        n = d2.n;
        a = new double[n + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        a[i] = d2.a[i];
    }
    return *this;
}

double DT::operator^(const double &x)
{
    double f = 0;
    for (int i = 0; i <= n; i++)
    {
        f += a[i] * pow(x, i);
    }
    return f;
}

double *DT::add(DT &d2)
{
    int size = max(n, d2.n);
    double *sum;
    sum = new double[size + 1];

    for (int i = 0; i <= n; i++)
        sum[i] = a[i];

    for (int i = 0; i <= d2.n; i++)
        sum[i] += d2.a[i];
    return sum;
}

double *DT::multiply(DT &d2)
{
    int size = n + d2.n;
    double *mul;
    mul = new double[size + 1];

    for (int i = 0; i <= size; i++)
    {
        mul[i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= d2.n; j++)
            mul[i + j] += a[i] * d2.a[j];
    }
    return mul;
}

DT::DT(const DT &d2)
{
    cout << "goi ham tao sao chep" << endl;
    this->n = d2.n;
    this->a = new double[d2.n + 1];
    for (int i = 0; i <= d2.n; ++i)
    {
        this->a[i] = d2.a[i];
    }
}

double F(DT &f, double x)
{
    double F = 0;
    int size = f.getN();
    for (int i = 0; i <= size; i++)
    {
        F += f[i] * pow(x, i);
    }
    return F;
}

int main()
{
    cout << "Tao cac da thuc p,q,r,s" << endl;
    DT p, q, r, s, f;
    cin >> p >> q >> r >> s;
    f = -(p + q) * (r - s);
    cout << "\n";
    cout << "f = -(f + q) * (r - s) = " << f << endl;
    cout << "\n";
    cout << "Tinh gia tri cua f tai x = 3" << endl;
    double a = f ^ 3;
    cout << "f(3) = " << a << endl;
    cout << "\n";
    cout << "Tinh gia tri cua f tai x = 3 bang ham F" << endl;
    cout << "f(3) = " << F(f, 3) << endl;
    cout << "\n";
    cout << "Truy nhap vao a[3] cua f: " << f[3] << endl;
}