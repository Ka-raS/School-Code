#include <iostream>
#include <vector>

class Stack {
public:
    Stack() { m_data.reserve(200); }

    void execute(const std::string &command) {
        switch (command.back()) {
        case 'h':  // command = "push"
            push();
            break;

        case 'p':  // command = "pop"
            pop();
            break;

        case 'w':  // command = "show"
            show();
            break;
        }
    }

private:
    void push() {
        int value;
        std::cin >> value;
        m_data.emplace_back(value);
    }

    void pop() { m_data.pop_back(); }

    void show() const {
        if (m_data.empty()) {
            std::cout << "empty\n";
            return;
        }
        for (const int number : m_data) {
            std::cout << number << ' ';
        }
        std::cout << '\n';
    }

private:
    std::vector<int> m_data;
};

void runProgram() {
    Stack stack;
    std::string command;
    while (std::cin >> command) {
        stack.execute(command);
    }
}

int main() {
    runProgram();
}