#include <iostream>
#include <queue>

class Node
{
public:
    Node(const int _key) : key(_key), left(nullptr), right(nullptr) {}

    void insert(const int child, const char direction)
    {
        switch (direction)
        {
        case 'L':
            if (!this->left)
            {
                this->left = new Node(child);
            }
            break;

        case 'R':
            if (!this->right)
            {
                this->right = new Node(child);
            }
            break;

        default:
            break;
        }
    }

    friend class BinaryTree;

private:
    int key;
    Node *left;
    Node *right;
};

class BinaryTree
{
public:
    ~BinaryTree()
    {
        clear(m_Root);
    }

    void newRoot(const int root)
    {
        clear(m_Root);
        m_Root = new Node(root);
    }

    Node &at(const int value) const
    {
        return *search(m_Root, value);
    }

    void print() const
    {
        std::queue<const Node *> printQueue;
        printQueue.emplace(m_Root);
        while (!printQueue.empty())
        {
            const Node *const current = printQueue.front();
            printQueue.pop();
            if (!current)
            {
                continue;
            }

            std::cout << current->key << ' ';
            printQueue.emplace(current->left);
            printQueue.emplace(current->right);
        }
        std::cout << '\n';
    }

private:
    static Node *search(Node *const root, const int &target)
    {
        if (!root || root->key == target)
            return root;

        Node *const left = search(root->left, target);
        if (left)
            return left;
        return search(root->right, target);
    }

    static void clear(Node *const root)
    {
        if (!root)
            return;
        clear(root->left);
        clear(root->right);
        delete root;
    }

private:
    Node *m_Root = nullptr;
};

void input(BinaryTree &tree)
{
    size_t height;
    std::cin >> height;
    for (size_t row = 0; row < height; ++row)
    {
        int parent;
        int child;
        char direction;
        std::cin >> parent >> child >> direction;

        if (row == 0)
        {
            tree.newRoot(parent);
        }

        tree.at(parent).insert(child, direction);
    }
}

void runProgram()
{
    BinaryTree tree;
    input(tree);
    tree.print();
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        runProgram();
    }
}