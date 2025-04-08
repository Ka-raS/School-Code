#include <bits/stdc++.h>
using namespace std;

struct SinhVien
{
    int tt;
    string ten, lop, ngay;
    float gpa;
};

void func1(string &A)
{
    string buf;
    stringstream ss(A);
    A.clear();

    while (ss >> buf)
    {
        A.push_back(toupper(buf[0]));
        for (int j = 1; j < buf.size(); j++)
            A.push_back(tolower(buf[j]));
        A.push_back(' ');
    }
}

void func2(string &A)
{
    if (A[1] == '/')
        A.insert(A.begin(), '0');
    if (A[4] == '/')
        A.insert(A.begin() + 3, '0');
}

void nhap(SinhVien *ds, const int N)
{
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        ds[i].tt = i + 1;
        getline(cin, ds[i].ten);
        cin >> ds[i].lop >> ds[i].ngay >> ds[i].gpa;
        cin.ignore();
        func1(ds[i].ten);
        func2(ds[i].ngay);
    }
}

bool cmp(const SinhVien &a, const SinhVien &b)
{
    return a.gpa > b.gpa;
}

void sapxep(SinhVien *ds, const int N)
{
    sort(ds, ds + N, cmp);
}

void in(SinhVien *ds, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "B20DCCN"
             << setfill('0') << setw(3)
             << ds[i].tt << ' '
             << ds[i].ten
             << ds[i].lop << ' '
             << ds[i].ngay << ' '
             << fixed << setprecision(2)
             << ds[i].gpa << '\n';
    }
}

int main()
{
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    sapxep(ds, N);
    in(ds, N);
    return 0;
}