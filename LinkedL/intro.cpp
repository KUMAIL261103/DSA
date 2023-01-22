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
void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void insertatTail(Node *&tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp;
}
void insertatmiddle(Node *&head, Node *&tail, int pos, int d)
{
    Node *temp = new Node(d);
    Node *prev = head;
    if (pos == 1)
    {
        insertathead(head, d);
        return;
    }
    int count = 1;
    while (prev != NULL && count < pos - 1)
    {
        prev = prev->next;
        count++;
    }
    if (prev->next == NULL)
    {
        insertatTail(tail, d);
        return;
    }
    temp->next = prev->next;
    prev->next = temp;
}
void deleteNode(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;
    Node *prev = head;
    int count = 1;
    if (pos == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete (temp);
        return;
    }
    while (count < pos && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        prev->next = NULL;
        tail = prev;
        temp->next = NULL;
        delete (temp);
        return;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete (temp);
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    insertathead(head, 23);
    insertathead(head, 34);
    insertatTail(tail, 44);
    insertatTail(tail, 87);
    insertatmiddle(head, tail, 3, 4);
    insertatmiddle(head, tail, 7, 22);
    print(head);
    cout << endl;
    cout << "head is at " << head->data << endl;
    cout << "tail is at " << tail->data << endl;
    deleteNode(head, tail, 3);
    deleteNode(head, tail, 6);
    print(head);
    cout << endl;
    cout << "head is at " << head->data << endl;
    cout << "tail is at " << tail->data << endl;
    return 0;
}