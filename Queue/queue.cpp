#include<iostream>
using namespace std;
class queue{
    int arr[100];
    int front ;
    int rear;

    public:
    queue()
    {
        front = rear =-1;
    }

    void enqueue(int val)
    {
        if(rear == 100)
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
            arr[++rear]= val;
        }


    }
    void dequeue()
    {
        if(front == rear)
        {
            cout<<"the element is "<<arr[front]<<endl;
            front = rear =-1;
        }
        else{
        cout<<"the element is"<<arr[front]<<endl;
        front++;
        }
    }
    void display()
    {
        for(int i=front ; i<= rear ; i++)
        {
            cout<<arr[i]<<" ";
        }
    }

};
int main()
{
    queue q;
    q.enqueue(5);
    q.enqueue(13);
    q.dequeue();
    q.display();

}
