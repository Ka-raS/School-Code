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
void output(Node *);
void removeDuplicates(Node *&head)
{
    if (head == nullptr)
        return;

    Node *it = head;
    while (it != nullptr)
    {
        Node *jt = it;
        while (jt->next != nullptr)
        {
            if (jt->next->value == it->value)
            {
                Node *tmp = jt->next->next;
                delete jt->next;
                jt->next = tmp;
            }
            else
                jt = jt->next;
        }
        it = it->next;
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

void removeListNode(Node *&head)
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
    removeDuplicates(head);
    output(head);
    removeListNode(head);
}