#include <iostream>
#include <vector>
#include <algorithm>

class Company
{
private:
    std::string id;
    std::string name;
    int num_of_applicants;

public:
    friend std::istream &operator>>(std::istream &input, Company &company)
    {
        std::getline(input, company.id);
        std::getline(input, company.name);
        input >> company.num_of_applicants;
        input.ignore();
        return input;
    }
    friend std::ostream &operator<<(std::ostream &output, const Company &company)
    {
        output << company.id << ' '
               << company.name << ' '
               << company.num_of_applicants << '\n';
        return output;
    }
    int get_num_of_applicants() const { return num_of_applicants; }
    const std::string &get_id() const { return id; }
};

void input(std::vector<Company> &vector_companies, int &num_of_companies)
{
    std::cin >> num_of_companies;
    std::cin.ignore();
    vector_companies.resize(num_of_companies);

    for (Company &company : vector_companies)
        std::cin >> company;
}

void descending_applicants_sort(std::vector<Company> &vector_companies)
{
    auto compare_function = [](const Company &A, const Company &B)
    {
        // < 0 if A's applicants < B's applicants
        // = 0 if A's applicants = B's applicants
        // > 0 if A's applicants > B's applicants
        const int applicants_difference = A.get_num_of_applicants() - B.get_num_of_applicants();
        if (applicants_difference)
            return applicants_difference > 0;
        return A.get_id() < B.get_id();
    };
    std::sort(vector_companies.begin(), vector_companies.end(), compare_function);
}

void output(const std::vector<Company> &vector_companies)
{
    for (const Company &company : vector_companies)
        std::cout << company;
}

int main()
{
    int num_of_companies;
    std::vector<Company> vector_companies;

    input(vector_companies, num_of_companies);
    descending_applicants_sort(vector_companies);
    output(vector_companies);

    num_of_companies = 0;
    vector_companies.clear();
    return 0;
}