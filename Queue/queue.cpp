#include<iostream>
using namespace std;
class queue
{
 int arr[10];
 int front;
 int rear;
 int max_size = 10;
  public:
 queue()
{
        front = rear=-1;
}
void read()
        {
                int a;
                cout<<"Enter the number of elements less than 10: ";
                cin>>a;
                front =0;
                for(int i =front ; i < a; i++)
                {
                        cout<<"Enter the element value  "<<i+1<<": ";
                        cin>>arr[i];
                }
                rear = a-1;
        }


  void enqueue(int val)
  {
          if(rear == max_size-1)
          {
                  cout<<"The queue is full "<<endl;
                  return;
          }
          if(front ==-1)
        {
                front =0;
                arr[front]= val;
                rear++;

        }
          else
          {
                  rear = rear+1;
                  arr[rear] = val;

          }

  }
void dequeue()
{

        if(front==rear && front !=-1)
        {
                cout<<"The dequeued element is: "<<arr[front]<<endl;
                front = rear =-1;

        }
        if(front ==-1)
        {
                cout<<"The queue is EMPTY "<<endl;
        }
        else
        {
                cout<<"The dequeued element is : "<<arr[front]<<endl;
                front++;
        }

}
void display()
{
        if(front ==-1)
        {
                cout<<"The queue is empty nothing to Print "<<endl;
        }
        else{
        for(int i =front ;i <= rear;i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        }
}
};
int main(){
        queue q;
        q.read();
        int x;
        do{
                cout<<"1.enqueue"<<endl;
                cout<<"2.dequeue"<<endl;
                cout<<"3.display"<<endl;
                cout<<"0.exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>x;
                switch(x)
                {
                        case 1:
                                int value;
                                cout<<"Enter the value need to be enqueued :";
                                cin>>value;
                                q.enqueue(value);
                                break;
                        case 2:
                                q.dequeue();
                                break;
                        case 3:
                                q.display();
                                break;
                        default:
                                break;
                }

                }while(x !=0);

        }
