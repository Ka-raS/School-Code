#include <deque>
#include <iostream>

class Deque {
public:
    void execute(const std::string &command) {
        switch (command[5]) {
        case 'R':  // PUSHFRONT
            return pushFront();

        case 'F':  // PRINTFRONT
            return front();

        case 'O':  // POPFRONT
            return popFront();

        case 'A':  // PUSHBACK
            return pushBack();

        case 'B':  // PRINTBACK
            return back();

        case 'C':  // POPBACK
            return popBack();
        }
    }

private:
    void pushFront() {
        int value;
        std::cin >> value;
        m_data.emplace_front(value);
    }

    void front() const {
        if (m_data.empty()) {
            std::cout << "NONE\n";
        } else {
            std::cout << m_data.front() << '\n';
        }
    }

    void popFront() {
        if (m_data.empty() == false) {
            m_data.pop_front();
        }
    }

    void pushBack() {
        int value;
        std::cin >> value;
        m_data.emplace_back(value);
    }

    void back() const {
        if (m_data.empty()) {
            std::cout << "NONE\n";
        } else {
            std::cout << m_data.back() << '\n';
        }
    }

    void popBack() {
        if (m_data.empty() == false) {
            m_data.pop_back();
        }
    }

private:
    std::deque<int> m_data;
};

void runProgram() {
    Deque deque;
    std::string command;
    int commandsCount;
    std::cin >> commandsCount;

    while (std::cin >> command) {
        deque.execute(command);
    }
}

int main() {
    runProgram();
}