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

Node *insert_node(Node *head, int i, int data)
{
    Node* newNode = new Node(data);
    Node *temp = head;
    int count = 0;

    if(i==0)
    {
        newNode->next = head;
        head = newNode;  
        return head;  
    }

    // taking temp to pos where node is to be inserted
    while(temp!=NULL && count < i-1)
    {
        temp = temp->next;
        count++;
    }

    // now inserting in b/w
    if(temp!=NULL)
    {
        Node* a = temp;
        newNode -> next = a->next;
        temp->next = newNode;
    }
    return head;
}

int main()
{
    Node* head = take_input();
    cout << "The LL is: " << endl;
    print_LL(head);
    cout << endl;
    int i, data;
    cout << "Enter the index where u want to insert the data:" << endl;
    cin >> i;
    cout << "Enter the data to be inserted :" << endl;
    cin >> data;
    head = insert_node(head, i, data);
    cout << "LL After Insertion : " << endl;
    print_LL(head);
}