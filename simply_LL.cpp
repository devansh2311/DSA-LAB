// Taking input and printing a simply LL
#include <iostream>
using namespace std;

class Node{

public:
    int data;
    Node *next; // to store the address of next pointer

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node* take_input()
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

void print_LL(Node *head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


int main()
{
    Node *head = take_input();
    print_LL(head);
}