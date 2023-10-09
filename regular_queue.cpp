#include<iostream>
using namespace std;

int n=20; // global variable 

class queue{
    int* arr; 
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front =-1;
        back =-1;
    }

    void enqueue(int x){
        if(back==n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void dequeue(){
        if(front==-1 ||  front>back){
            cout<<"no more elements present :"<<endl;
            return;
        }
        front++;
    }

    int q_front(){
        if(front==-1 ||  front>back){
            cout<<"no elements in queue :"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front==-1 ||  front>back){
            return true;
        }
        return false;       
    }
};

int main(){

    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<q.q_front()<<endl;
    q.dequeue();

    cout<<q.q_front()<<endl;
    q.dequeue();

    cout<<q.q_front()<<endl;
    q.dequeue();

    cout<<q.q_front()<<endl;
    q.dequeue();

    cout<<q.empty();
    return 0;
}