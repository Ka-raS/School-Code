#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

struct Person
{
private:
    struct Date
    {
    private:
        int day;
        int month;
        int year;

    public:
        void str_to_date(std::string date)
        {
            std::stringstream ss(date);
            std::getline(ss, date, '/');
            day = std::stoi(date);
            std::getline(ss, date, '/');
            month = std::stoi(date);
            std::getline(ss, date);
            year = std::stoi(date);
        }
        const bool operator<(const Person::Date &other) const
        {
            if (year != other.year)
                return year > other.year;
            if (month != other.month)
                return month > other.month;
            return day > other.day;
        }
        const bool operator>(const Person::Date &other) const
        {
            if (year != other.year)
                return year < other.year;
            if (month != other.month)
                return month < other.month;
            return day < other.day;
        }
    };

    std::string name;
    Date birthdate;

public:
    friend std::istream &operator>>(std::istream &input, Person &A)
    {
        input >> A.name;
        std::string date;
        input >> date;
        A.birthdate.str_to_date(date);

        return input;
    }
    friend std::ostream &operator<<(std::ostream &output, const Person &A)
    {
        output << A.name;
        return output;
    }
    const Person::Date get_birthdate() const { return birthdate; }
};

const Person &find_youngest(const std::vector<Person> &A)
{
    const Person *youngest = &A.front();
    for (const Person &X : A)
        if (youngest->get_birthdate() > X.get_birthdate())
            youngest = &X;
    return *youngest;
}

const Person &find_oldest(const std::vector<Person> &A)
{
    const Person *oldest = &A.front();
    for (const Person &X : A)
        if (oldest->get_birthdate() < X.get_birthdate())
            oldest = &X;
    return *oldest;
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<Person> A(n);

    for (Person &X : A)
        std::cin >> X;

    const Person &youngest = find_youngest(A),
                 &oldest = find_oldest(A);

    std::cout << youngest << '\n'
              << oldest;

    return 0;
}