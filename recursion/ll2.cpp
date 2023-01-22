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
// void getlen(node *&head, int *len)
// {
//     if (head == NULL)
//     {
//         return;
//     }
//     *len++;
//     getlen(head->next, len);
// }
// void kthlast2(node *&head, int &k)
// {
//     int *len = 0;
//     getlen(head, &len);
//     if (*len - k == 0)
//     {
//         cout << head->data << "  ";
//     }
//     kthlast2(head->next, k);
// }
// pointr issue

void kthlast(node *&head, int &k)
{
    if (head == NULL)
    {
        return;
    }

    kthlast(head->next, k);
    k--;
    if (k == 0)
    {
        cout << head->data << " ";
    }
}
void reverse(node *&head)
{
    node *temp = head;
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }
    node *prev = NULL;
    node *curr = head;
    node *next1 = NULL;
    while (curr != NULL)
    {
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
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
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    node *n1 = new node(5);
    head = tail = n1;
    insertattail(tail, 4);
    insertattail(tail, 1);
    insertattail(tail, 3);
    insertattail(tail, 2);

    return 0;
}