#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data" << value << endl;
    }
};
void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *&tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail->next != temp);
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    cout << endl;
    // insertNode(tail, 3, 5);
    insertNode(tail, 3, 6);
    insertNode(tail, 6, 5);
    print(tail);
    return 0;
}
