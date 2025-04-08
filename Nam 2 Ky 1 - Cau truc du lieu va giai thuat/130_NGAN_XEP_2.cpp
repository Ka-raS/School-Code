#include <iostream>
#include <vector>

class Stack {
public:
    void execute(const std::string &command) {
        switch (command.back()) {
        case 'H':  // command = "PUSH"
            push();
            break;

        case 'T':  // command = "PRINT"
            print();
            break;

        case 'P':  // command = "POP"
            pop();
            break;
        }
    }

private:
    void push() {
        int value;
        std::cin >> value;
        m_data.emplace_back(value);
    }

    void pop() {
        if (!m_data.empty()) {
            m_data.pop_back();
        }
    }

    void print() const {
        if (m_data.empty()) {
            std::cout << "NONE\n";
        } else {
            std::cout << m_data.back() << '\n';
        }
    }

private:
    std::vector<int> m_data;
};

void runProgram() {
    Stack stack;
    int commandCount;
    std::cin >> commandCount;
    std::string command;
    while (std::cin >> command) {
        stack.execute(command);
    }
}

int main() {
    runProgram();
}