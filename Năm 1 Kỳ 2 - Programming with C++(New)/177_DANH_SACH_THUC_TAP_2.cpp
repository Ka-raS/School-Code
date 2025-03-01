#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student
{
private:
    int ordinal;
    std::string id;
    std::string name;
    std::string class_name;
    std::string email;
    std::string company;

public:
    const void set_ordinal(const int n) { ordinal = n; }

    friend std::istream &operator>>(std::istream &input, Student &A)
    {
        std::getline(input, A.id);
        std::getline(input, A.name);
        std::getline(input, A.class_name);
        std::getline(input, A.email);
        std::getline(input, A.company);
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Student &A)
    {
        output << A.ordinal << ' '
               << A.id << ' '
               << A.name << ' '
               << A.class_name << ' '
               << A.email << ' '
               << A.company;
        return output;
    }

    const std::string &get_id() const { return id; }
    const std::string &get_company() const { return company; }
};

const bool compare_function(const Student &A, const Student &B) { return A.get_id() < B.get_id(); }

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<Student> A(n);

    for (int i = 0; i < n; i++)
    {
        A[i].set_ordinal(i + 1);
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), compare_function);

    int q;
    std::cin >> q;
    std::cin.ignore();
    while (q--)
    {
        std::string corporate_name;
        std::getline(std::cin, corporate_name);
        for (const Student &X : A)
            if (X.get_company() == corporate_name)
                std::cout << X << '\n';
    }

    return 0;
}