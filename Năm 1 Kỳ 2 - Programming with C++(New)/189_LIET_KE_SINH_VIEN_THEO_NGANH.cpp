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
    std::string major;

    void set_major()
    {
        for (size_t i = 3; i <= 6; i++)
            major.push_back(id.at(i));
        if (class_name.front() == 'E')
            if (major == "DCCN" || major == "DCAT")
                major.clear();
    }

public:
    friend std::istream &operator>>(std::istream &input, Student &student)
    {
        std::getline(input, student.id);
        std::getline(input, student.full_name);
        std::getline(input, student.class_name);
        std::getline(input, student.email);
        student.set_major();
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

    const std::string &get_major() const { return major; }
    bool is_major(const std::string &search) const { return major == search; }
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
    auto upper = [](std::string &str)
    {
        for (char &c : str)
            c = std::toupper(c);
    };

    auto convert = [](const std::string &str)
    {
        if (str == "KE TOAN")
            return "DCKT";
        if (str == "CONG NGHE THONG TIN")
            return "DCCN";
        if (str == "AN TOAN THONG TIN")
            return "DCAT";
        if (str == "VIEN THONG")
            return "DCVT";
        if (str == "DIEN TU")
            return "DCDT";
    };

    for (std::string search : vector_searches)
    {
        upper(search);
        std::cout << "DANH SACH SINH VIEN NGANH " << search << ":\n";
        search = convert(search);
        for (const Student &student : vector_students)
            if (student.is_major(search))
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