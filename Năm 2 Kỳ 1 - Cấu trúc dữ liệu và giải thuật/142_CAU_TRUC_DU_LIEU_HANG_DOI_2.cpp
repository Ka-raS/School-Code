#include <iostream>
#include <queue>

class Queue {
public:
    void execute(const std::string &command) {
        switch (command.back()) {
        case 'H':  // PUSH
            return push();

        case 'T':  // PRINTFRONT
            return front();

        case 'P':  // POP
            return pop();
        }
    }

private:
    void push() {
        int value;
        std::cin >> value;
        m_data.emplace(value);
    }

    void front() const {
        if (m_data.empty()) {
            std::cout << "NONE\n";
        } else {
            std::cout << m_data.front() << '\n';
        }
    }

    void pop() {
        if (m_data.empty() == false) {
            m_data.pop();
        }
    }

private:
    std::queue<int> m_data;
};

void runProgram() {
    Queue queue;
    std::string command;
    int commandsCount;
    std::cin >> commandsCount;

    while (std::cin >> command) {
        queue.execute(command);
    }
}

int main() {
    runProgram();
}