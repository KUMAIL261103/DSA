#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data";
    }
};
node *head = NULL;
void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertattail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertatposition(node *&tail, node *&head, int position, int d)
{
    if (position == 1)
    {
        insertathead(head, d);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertattail(tail, d);
    }
    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void deletenode(int pos, node *&head)
{
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        int count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
    }
}
void print2(node *&head)
{
    node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    cout << temp->data << "->";
    print2(temp->next);
}
void kthnodefromL(node *&head, int &k)
{

    node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    kthnodefromL(temp->next, k);
    k--;
    if (k == 0)
    {
        cout << temp->data;
        return;
    }
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertathead(head, 2);
    insertathead(head, 3);
    insertathead(head, 1);
    insertathead(head, 4);
    insertathead(head, 5);
    insertathead(head, 7);
    insertathead(head, 6);
    insertathead(head, 8);
    insertathead(head, 9);
    print2(head);
    cout << endl;
    int k = 3;
    kthnodefromL(head, k);

    return 0;
}