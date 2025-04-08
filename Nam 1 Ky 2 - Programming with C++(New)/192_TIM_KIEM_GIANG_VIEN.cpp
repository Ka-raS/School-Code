#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

const std::string lower(const std::string &str)
{
    std::string new_str;
    for (const char &c : str)
        new_str.push_back(std::tolower(c));
    return new_str;
}

class Teacher
{
private:
    std::string full_name;
    std::string major;

    std::string id;
    std::string lower_full_name;
    std::string major_code;

    void set_lower_full_name()
    {
        lower_full_name = lower(full_name);
    };
    void set_major_code()
    {
        std::string buf;
        std::stringstream major_sstream(major);
        while (major_sstream >> buf)
            major_code.push_back(std::toupper(buf.front()));
    }

public:
    friend std::istream &operator>>(std::istream &input, Teacher &teacher)
    {
        std::getline(input, teacher.full_name);
        std::getline(input, teacher.major);
        teacher.set_lower_full_name();
        teacher.set_major_code();
        return input;
    }
    friend std::ostream &operator<<(std::ostream &output, const Teacher &teacher)
    {
        output << teacher.id << ' '
               << teacher.full_name << ' '
               << teacher.major_code << '\n';
        return output;
    }

    bool is_search_name(const std::string &search) const
    {
        return lower_full_name.find(search) != std::string::npos;
    }
    void set_id(const int n)
    {
        std::ostringstream id_oss;
        id_oss << "GV" << std::setw(2) << std::setfill('0') << n;
        id = id_oss.str();
    }
};

void input(std::vector<Teacher> &vector_teachers, int &num_of_teachers, std::vector<std::string> &vector_searches, int &num_of_searches)
{
    std::cin >> num_of_teachers;
    std::cin.ignore();
    vector_teachers.resize(num_of_teachers);
    int id_num = 0;
    for (Teacher &teacher : vector_teachers)
    {
        teacher.set_id(++id_num);
        std::cin >> teacher;
    }

    std::cin >> num_of_searches;
    std::cin.ignore();
    vector_searches.resize(num_of_searches);
    for (std::string &search : vector_searches)
        std::getline(std::cin, search);
}

void output(const std::vector<Teacher> &vector_teachers, const std::vector<std::string> &vector_searches)
{
    for (std::string search : vector_searches)
    {
        std::cout << "DANH SACH GIANG VIEN THEO TU KHOA " << search << ":\n";
        search = lower(search);
        for (const Teacher &teacher : vector_teachers)
            if (teacher.is_search_name(search))
                std::cout << teacher;
    }
}

int main()
{
    int num_of_teachers;
    std::vector<Teacher> vector_teachers;
    int num_of_searches;
    std::vector<std::string> vector_searches;

    input(vector_teachers, num_of_teachers, vector_searches, num_of_searches);
    output(vector_teachers, vector_searches);

    num_of_teachers = 0;
    num_of_searches = 0;
    vector_teachers.clear();
    vector_searches.clear();

    return 0;
}