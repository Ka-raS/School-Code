#include <iostream>
#include <sstream>
#include <iomanip>

class ListingSpecialDates
{
public:
    static void start();
};

int main()
{
    ListingSpecialDates::start();
}

class SpecialDate // date with only '0' or '2'
{
public:
    bool toNextDate();
    static SpecialDate firstSpecialDate();
    friend std::ostream &operator<<(std::ostream &out, const SpecialDate &date);

private:
    int day;
    int month;
    int year;
};

void ListingSpecialDates::start()
{
    SpecialDate date = SpecialDate::firstSpecialDate();
    do
    {
        std::cout << date << std::endl;
    } while (date.toNextDate());
}

bool SpecialDate::toNextDate()
{
    std::string year = std::to_string(this->year);

    std::size_t i = year.rfind('0');
    if (i != std::string::npos)
    {
        year[i] = '2';
        while (++i < year.size())
            year[i] = '0';

        this->year = std::stoi(year);
        return true; // year changed
    }

    // year is 2222
    switch (this->day)
    {
    case 02:
        this->day = 20;
        break;

    case 20:
        this->day = 22;
        break;

    case 22:
        // date is 22/02/2222
        // no next date
        return false;
    }

    this->year = 2000;
    return true;
}

// 02/02/2000
SpecialDate SpecialDate::firstSpecialDate()
{
    SpecialDate firstDate;
    firstDate.day = 2;
    firstDate.month = 2;
    firstDate.year = 2000;
    return firstDate;
}

std::ostream &operator<<(std::ostream &out, const SpecialDate &date)
{
    out << std::setw(2) << std::setfill('0') << date.day << '/'
        << std::setw(2) << std::setfill('0') << date.month << '/'
        << std::setw(4) << std::setfill('0') << date.year;
    return out;
}