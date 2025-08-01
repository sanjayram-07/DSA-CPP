#include<iostream>
using namespace std;
class circular_queue{
    int arr[5];
    int front ;
    int rear;
    int max_size = 5;

    public:
    circular_queue()
    {
        front = rear =-1;
    }

    void enqueue(int val)
    {
        if((rear+1)%max_size == front)
        {
            cout<<"max_size reached";
        }
        if(front ==-1)
        {
            front =0;
            arr[front] = val;
            rear++;
        }
        else{
            rear = (rear+1)%max_size;
            arr[rear] = val;
            
            }


    }
    void dequeue()
    {
        if(front ==-1)
        {
            cout<<"The queue is Empty "<<endl;
        }
        if(front == rear)
        {
            cout<<"poped the element is "<<arr[front]<<endl;
            front = rear =-1;
        }
        else{
            cout<<"the element is :     "<<arr[front]<<endl;
            front = (front+1)%max_size;
        }
    }
    void display()
    {
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % max_size;
        }
    }

};
int main()
{
    circular_queue q;
    q.enqueue(5);
    q.enqueue(13);
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(89);
    q.dequeue();
    q.enqueue(98);
    q.display();

}
