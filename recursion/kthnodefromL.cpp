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
void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
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
    int k = 3;
    kthnodefromL(head, k);
    return 0;
}
