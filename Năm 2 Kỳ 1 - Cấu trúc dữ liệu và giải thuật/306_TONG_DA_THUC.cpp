#include <iostream>
#include <sstream>

struct Monominal;
class Expression
{
public:
    Expression operator+(const Expression &);
    friend std::istream &operator>>(std::istream &, Expression &);
    friend std::ostream &operator<<(std::ostream &, const Expression &);

    Expression();
    ~Expression();

private:
    void append(const Expression &);
    void sort();
    void simplify();

private:
    Monominal *head;
};

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        Expression A, B;
        std::cin >> A >> B;
        std::cout << A + B << std::endl;
    }
}

struct Monominal
{
    int coefficient;
    int exponent;
    Monominal *next;
};

Expression Expression::operator+(const Expression &other)
{
    Expression sum;
    sum.append(*this);
    sum.append(other);
    sum.sort();
    sum.simplify();
    return sum;
}

std::istream &operator>>(std::istream &in, Expression &expression)
{
    // istream = "3*x^8 + 7*x^2 + 4*x^0"

    std::string str;
    std::getline(in >> std::ws, str);
    std::istringstream ss(str);

    expression.head = new Monominal;
    Monominal *current = expression.head;
    while (ss.peek() != EOF)
    {
        current->next = new Monominal;
        current = current->next;

        // monominal = k*x^n

        std::getline(ss, str, '*'); // str = k, current monominal = x^n
        current->coefficient = std::stoi(str);

        std::getline(ss, str, '^'); // str = "x^", current monominal = n
        std::getline(ss, str, ' '); // str = n
        current->exponent = std::stoi(str);

        if (ss.peek() == EOF)
            break;
        std::getline(ss, str, ' '); // str = "+ ", to remove '+'
    }

    current->next = nullptr;
    current = expression.head;
    expression.head = expression.head->next;
    delete current;

    return in;
}

std::ostream &operator<<(std::ostream &out, const Expression &expression)
{
    if (expression.head == nullptr)
        return out;

    out << expression.head->coefficient << "*x^" << expression.head->exponent;

    Monominal *current = expression.head->next;
    while (current != nullptr)
    {
        out << " + " << current->coefficient << "*x^" << current->exponent;
        current = current->next;
    }
    return out;
}

void Expression::append(const Expression &other)
{
    if (other.head == nullptr)
        return;

    Monominal *thisCurrent, *otherCurrent = other.head;
    if (this->head == nullptr)
    {
        this->head = new Monominal;
        this->head->coefficient = otherCurrent->coefficient;
        this->head->exponent = otherCurrent->exponent;

        thisCurrent = this->head;
        otherCurrent = otherCurrent->next;
    }
    else
    {
        thisCurrent = this->head;
        while (thisCurrent->next != nullptr)
            thisCurrent = thisCurrent->next;
    }

    while (otherCurrent != nullptr)
    {
        thisCurrent->next = new Monominal;
        thisCurrent = thisCurrent->next;

        thisCurrent->coefficient = otherCurrent->coefficient;
        thisCurrent->exponent = otherCurrent->exponent;

        otherCurrent = otherCurrent->next;
    }

    thisCurrent->next = nullptr;
}

void Expression::sort()
{
    if (head == nullptr)
        return;

    bool swapped = true;
    while (swapped == true)
    {
        swapped = false;
        Monominal *current = head;
        while (current->next != nullptr)
        {
            if (current->exponent < current->next->exponent)
            {
                swapped = true;

                int tmp = current->coefficient;
                current->coefficient = current->next->coefficient;
                current->next->coefficient = tmp;

                tmp = current->exponent;
                current->exponent = current->next->exponent;
                current->next->exponent = tmp;
            }
            current = current->next;
        }
    }
}

void Expression::simplify()
{
    if (head == nullptr)
        return;

    Monominal *current = head;
    while (current->next != nullptr)
    {
        if (current->exponent == current->next->exponent)
        {
            current->coefficient += current->next->coefficient;
            Monominal *tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        }
        else
            current = current->next;
    }
}

Expression::Expression() { head = nullptr; }

Expression::~Expression()
{
    while (head != nullptr)
    {
        Monominal *current = head;
        head = head->next;
        delete current;
    }
}
