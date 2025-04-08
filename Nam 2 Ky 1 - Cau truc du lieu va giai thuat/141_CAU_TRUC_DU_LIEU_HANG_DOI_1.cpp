#include <iostream>
#include <queue>

class Queue {
public:
    void execute(const int command) {
        switch (command) {
        case 1:
            return size();

        case 2:
            return empty();

        case 3:
            return emplace();

        case 4:
            return pop();

        case 5:
            return front();

        case 6:
            return back();
        }
    }

private:
    void size() const { std::cout << m_data.size() << '\n'; }

    void empty() const {
        if (m_data.empty()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    void emplace() {
        int value;
        std::cin >> value;
        m_data.emplace(value);
    }

    void pop() {
        if (m_data.empty() == false) {
            m_data.pop();
        }
    }

    void front() const {
        if (m_data.empty()) {
            std::cout << "-1\n";
        } else {
            std::cout << m_data.front() << '\n';
        }
    }

    void back() const {
        if (m_data.empty()) {
            std::cout << "-1\n";
        } else {
            std::cout << m_data.back() << '\n';
        }
    }

private:
    std::queue<int> m_data;
};

void runProgram() {
    Queue queue;
    int operationsCount;
    std::cin >> operationsCount;

    while (operationsCount--) {
        int command;
        std::cin >> command;
        queue.execute(command);
    }
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}