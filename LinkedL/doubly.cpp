#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
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
    cout << endl;
}
int getlen(Node *&head)
{
    if (head == NULL)
    {
        return -1;
    }
    Node *temp = head;
    int counter = 0;
    while (temp != NULL)
    {

        temp = temp->next;
        counter++;
    }
    return counter;
}
void insertathead(Node *&head, int d)
{
    Node *nodeToInsert = new Node(d);
    if (head == NULL)
    {
        head = nodeToInsert;
        return;
    }

    nodeToInsert->next = head;
    head->prev = nodeToInsert;
    head = nodeToInsert;
}
void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void inserrtatMiddle(Node *&head, int pos, int d)
{
    Node *nodetoInsert = new Node(d);
    if (pos == 1)
    {
        insertathead(head, d);
    }
    Node *previous = head;
    int count = 1;
    while (count < pos - 1 && previous != NULL)
    {
        previous = previous->next;
        count++;
    }
    if (previous->next == NULL)
    {
        nodetoInsert->next = NULL;
        previous->next = nodetoInsert;
        nodetoInsert->prev = previous;
        return;
    }
    nodetoInsert->next = previous->next;
    previous->next = nodetoInsert;
    nodetoInsert->prev = previous;
    nodetoInsert->next->prev = nodetoInsert;
}
void deletenode(Node *&head, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        temp->next->prev = NULL;
        temp->prev = NULL;
        delete (temp);
        return;
    }
    int count = 1;
    Node *previ = head;
    while (count < pos && temp != NULL)
    {
        previ = temp;
        temp = temp->next;
        count++;
    }
    previ->next = temp->next;
    temp->next->prev = previ;
    temp->next = NULL;
    temp->prev = NULL;
    delete (temp);
}
int main()
{

    Node *node1 = new Node(23);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertathead(head, 63);
    insertathead(head, 60);
    insertathead(head, 78);
    print(head);
    cout << getlen(head) << endl;
    insertattail(tail, 345);
    print(head);
    inserrtatMiddle(head, 3, 88);
    print(head);
    deletenode(head, 3);
    print(head);

    print(head);

    return 0;
}