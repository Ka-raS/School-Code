#include <iostream>

struct Node
{
    int value;
    Node *next;
};

void input(Node *&head)
{
    int len;
    std::cin >> len;
    if (len <= 0)
        return;

    head = new Node;
    Node *current = head;

    for (int i = 0; i < len; ++i)
    {
        std::cin >> current->value;
        if (i < len - 1)
        {
            current->next = new Node;
            current = current->next;
        }
        else
            current->next = nullptr;
    }
}

void remove(Node *&head, const int target)
{
    while (head->value == target && head != nullptr)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    if (head == nullptr)
        return;

    Node *previous = head;
    Node *current = head->next;
    while (current != nullptr)
    {
        if (current->value == target)
        {
            previous->next = current->next;
            delete current;
            current = previous->next;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

void output(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->value << ' ';
        current = current->next;
    }
}

void removeListNode(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main()
{
    Node *head = nullptr;
    input(head);

    int target;
    std::cin >> target;
    remove(head, target);
    output(head);
    removeListNode(head);
}