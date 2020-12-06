#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
    string name;
    float score;

public:
    string getName() { return name; }
    float getScore() { return score; }
    Student()
    {
        this->name = "no name";
        this->score = 0;
    }
    Student(string aName, float aScore)
    {
        this->name = aName;
        this->score = aScore;
    }

    friend ostream &operator<<(ostream &os, const Student &z);
    friend istream &operator>>(istream &is, Student &z);
};

ostream &operator<<(ostream &os, const Student &z)
{
    cout << "Name: " << z.name << "| Score: " << z.score;
    return os;
}
istream &operator>>(istream &is, Student &z)
{
    cout << "Enter name: ";
    fflush(stdin);
    getline(cin, z.name);
    cout << "Enter score: ";
    cin >> z.score;
    return is;
}
bool operator<(Student &a, Student &b)
{
    return a.getScore() < b.getScore();
}

void printStudentList(int N, Student *A)
{
    for (int i = 0; i < N; i++)
    {
        cout << "\nNo. " << i + 1 << endl;
        cout << *(A + i);
    }
}
//Hàm nhập dữ liệu cho mảng học sinh
void inputStudentData(int N, Student *A)
{
    for (int i = 0; i < N; i++)
    {
        cout << "+) Enter data for student no. " << i + 1 << endl;
        cin >> A[i];
    }
}
int main()
{
    int N;
    Student studentArray[100];
    cout << "Enter number of student: ";
    cin >> N;
    inputStudentData(N, studentArray);
    cout << "Truoc khi sap xep:";
    printStudentList(N, studentArray);
    sort(studentArray, studentArray + N);
    cout << "\nSau khi sap xep: ";
    printStudentList(N, studentArray);
    return 0;
}