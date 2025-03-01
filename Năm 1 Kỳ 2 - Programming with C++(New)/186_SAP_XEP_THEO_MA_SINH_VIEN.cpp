#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student
{
private:
    std::string student_id;
    std::string full_name;
    std::string class_name;
    std::string email;

public:
    friend std::istream &operator>>(std::istream &input, Student &student)
    {
        std::getline(input, student.student_id);
        std::getline(input, student.full_name);
        std::getline(input, student.class_name);
        std::getline(input, student.email);
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Student &student)
    {
        output << student.student_id << ' '
               << student.full_name << ' '
               << student.class_name << ' '
               << student.email << '\n';
        return output;
    }

    const std::string &get_student_id() const { return student_id; }
};

int main()
{
    Student student;
    std::vector<Student> vector_students;

    while (std::cin >> student)
        vector_students.push_back(student);

    auto compare_function = [](const Student &A, const Student &B)
    { return A.get_student_id() < B.get_student_id(); };
    std::sort(vector_students.begin(), vector_students.end(), compare_function);

    for (const Student &each_student : vector_students)
        std::cout << each_student;

    return 0;
}