#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *take_input()
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1) // whenever we enter -1 LL ends
    {
        Node* newNode = new Node(data);
        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }
    return head;
}

void *print_LL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* delete_node(Node* head, int i)
{
    int count = 0;
    Node* temp = head;

    if(head==NULL || head->next==NULL ) //case with sinngle or no element
    {
        return head;
    }
    
    if(i==0)
    {
        Node* temp1 = head;
        head = head->next;
        delete temp1;
        return head;
    }

    while(temp!=NULL && count<i-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp!=NULL)
    {
        Node *a = temp->next;
        temp->next = a->next;
        delete a;
    }
    return head;
}

int main()
{
    Node* head = take_input();
    cout << "The LL is: " << endl;
    print_LL(head);
    cout << endl;
    int i;
    cout << "Enter the index whose data u want to delete: " << endl;
    cin >> i;
    head = delete_node(head, i);
    cout << "LL After Deletion : " << endl;
    print_LL(head);
}