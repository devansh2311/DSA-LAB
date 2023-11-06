#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

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

int search_LL(Node * head, int n)
{
    int count = 0;
    while(head!=NULL)
    {
        if(head->data == n)
        {
            return count;
        }
        head = head->next;
        count++;
    }
    cout << "Element not present in your LL !!" << endl;
}


int main()
{
    Node* head = take_input();
    cout << "The LL is: " << endl;
    print_LL(head);
    cout << endl;
    int search_data;
    cout << "Enter the data to be searched in the LL : " << endl;
    cin >> search_data;
    int index = search_LL(head, search_data); 
    cout << "The element is present at index : " << index << endl;
}