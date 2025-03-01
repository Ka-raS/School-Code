#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

class Teacher
{
private:
    std::string full_name;
    std::string major;

    std::string id;
    std::string first_name;
    std::string major_code;

    void set_first_name()
    {
        // position of the last ' ' char
        size_t last_space = full_name.rfind(' ');

        // if full name has 1 word
        if (last_space == std::string::npos)
            first_name = full_name;
        else
            first_name = full_name.substr(last_space + 1);
    }

    void set_major_code()
    {
        std::string buf;
        std::stringstream major_sstream(major);
        while (major_sstream >> buf)
            major_code.push_back(std::toupper(buf.front()));
    }

public:
    void set_id(const int n)
    {
        std::ostringstream id_oss;
        id_oss << std::setw(2) << std::setfill('0') << n;
        id = id_oss.str();
    }

    const std::string &get_first_name() const { return first_name; }
    const std::string &get_id() const { return id; }

    friend std::istream &operator>>(std::istream &input, Teacher &teacher)
    {
        std::getline(input, teacher.full_name);
        std::getline(input, teacher.major);
        teacher.set_first_name();
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

    bool is_major(const std::string &search) const { return major_code == search; }
};

void input(std::vector<Teacher> &vector_teachers, int num_of_teachers, std::vector<std::string> &vector_searches, int num_of_searches)
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
    auto convert = [](const std::string &str)
    {
        std::string ans;

        std::string buf;
        std::stringstream sstream(str);
        while (sstream >> buf)
            ans.push_back(std::toupper(buf.front()));

        return ans;
    };

    for (std::string search : vector_searches)
    {
        search = convert(search);
        std::cout << "DANH SACH GIANG VIEN BO MON " << search << ":\n";
        for (const Teacher &teacher : vector_teachers)
            if (teacher.is_major(search))
                std::cout << teacher;
    }
}

int main()
{
    int num_of_teachers;
    std::vector<Teacher> vector_teachers(num_of_teachers);
    int num_of_searches;
    std::vector<std::string> vector_searches;

    input(vector_teachers, num_of_teachers, vector_searches, num_of_searches);
    output(vector_teachers, vector_searches);

    return 0;
}