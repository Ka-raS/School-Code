#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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

void input(std::vector<Company> &vector_companies, int &num_of_companies, std::vector<std::pair<int, int>> &vector_searches, int &num_of_searches)
{
    std::cin >> num_of_companies;
    std::cin.ignore();
    vector_companies.resize(num_of_companies);
    for (Company &company : vector_companies)
        std::cin >> company;

    std::cin >> num_of_searches;
    vector_searches.resize(num_of_searches);
    for (std::pair<int, int> &search : vector_searches)
    {
        int &min = search.first,
            &max = search.second;
        std::cin >> min >> max;
    }
}

void output(const std::vector<Company> &vector_companies, const std::vector<std::pair<int, int>> &vector_searches)
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

    for (const std::pair<int, int> search : vector_searches)
    {
        const int &min = search.first,
                  &max = search.second;
        std::vector<std::reference_wrapper<const Company>> list;
        for (const Company &company : vector_companies)
        {
            const int num_of_applicants = company.get_num_of_applicants();
            if (num_of_applicants >= min && num_of_applicants <= max)
                list.push_back(company);
        }

        std::sort(list.begin(), list.end(), compare_function);
        std::cout << "DANH SACH DOANH NGHIEP NHAN TU "
                  << search.first << " DEN "
                  << search.second << " SINH VIEN:\n";
        for (const Company &company : list)
            std::cout << company;
    }
}

int main()
{
    int num_of_companies;
    std::vector<Company> vector_companies;
    int num_of_searches;
    std::vector<std::pair<int, int>> vector_searches;

    input(vector_companies, num_of_companies, vector_searches, num_of_searches);
    output(vector_companies, vector_searches);

    num_of_companies = 0;
    vector_companies.clear();
    num_of_searches = 0;
    vector_searches.clear();
    return 0;
}