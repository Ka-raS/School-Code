#include <iostream>
#include <vector>
#include <string>

class Student
{

private:
    std::string id;
    std::string full_name;
    std::string class_name;
    std::string email;
    std::string class_year;

    void set_class_year()
    {
        class_year.push_back(class_name[1]);
        class_year.push_back(class_name[2]);
    }

public:
    friend std::istream &operator>>(std::istream &input, Student &student)
    {
        std::getline(input, student.id);
        std::getline(input, student.full_name);
        std::getline(input, student.class_name);
        std::getline(input, student.email);
        student.set_class_year();
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Student &student)
    {
        output << student.id << ' '
               << student.full_name << ' '
               << student.class_name << ' '
               << student.email << '\n';
        return output;
    }

    bool is_class_of(const std::string &search_class) const { return class_year == search_class; }
};

void input(std::vector<Student> &vector_students, int &num_of_students, std::vector<std::string> &vector_searches, int &num_of_searches)
{
    std::cin >> num_of_students;
    std::cin.ignore();
    vector_students.resize(num_of_students);
    for (Student &student : vector_students)
        std::cin >> student;

    std::cin >> num_of_searches;
    std::cin.ignore();
    vector_searches.resize(num_of_searches);
    for (std::string &search : vector_searches)
        std::getline(std::cin, search);
}

void output(const std::vector<Student> &vector_students, const std::vector<std::string> &vector_searches)
{
    for (const std::string &search : vector_searches)
    {
        std::cout << "DANH SACH SINH VIEN KHOA " << search << ":\n";
        const std::string search_class = search.substr(2);
        for (const Student &student : vector_students)
            if (student.is_class_of(search_class))
                std::cout << student;
    }
}

int main()
{
    int num_of_students;
    std::vector<Student> vector_students;
    vector_students.reserve(1000);
    int num_of_searches;
    std::vector<std::string> vector_searches;
    vector_searches.reserve(1000);

    input(vector_students, num_of_students, vector_searches, num_of_searches);
    output(vector_students, vector_searches);

    return 0;
}