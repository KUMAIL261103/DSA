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
node *kgroupreverse(node *&head, int k)
{
    if (k <= 0 || head == NULL)
    {
        return NULL;
    }
    int count = 0;
    node *curr = head;
    node *next;
    node *prev = NULL;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = kgroupreverse(next, k);
    }
    return prev;
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
    head = kgroupreverse(head, 3);
    print2(head);

    return 0;
}