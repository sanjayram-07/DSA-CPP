#include<iostream>
using namespace std;
class circular{
        int arr[5];
        int front;
        int rear;
        int max_size=5;
        public:
        circular()
        {
                front =rear =-1;
        }
        void read()
        {
                int num;
                cout<<"enter the number of element less than 5 ";
                cin>>num;
                front =0;
                for(int i =0 ; i < num ; i++)
                {
                        cout<<"Enter the value of "<<i+1<<": ";
                        cin>>arr[i];
                }
                rear = num -1;
        }
        void enqueue(int val)
        {
                if((rear+1)%max_size == front){
                        cout<<"The queue is full"<<endl;
                        return;
                }
                if(front ==-1)
                {
                        front =0;
                        arr[front] = val;
                        rear++;
                }
                else
                {
                        rear = (rear+1)%max_size;
                        arr[rear] = val;
                }
        }
        void dequeue()
        {
                if(front ==-1)
                {
                        cout<<"The queue is empty"<<endl;
                        return;
                }
                if(front == rear)
                {
                        cout<<"The dequeued element is :"<<arr[front];
                        front = rear =-1;
                }
                else{
                        cout<<"The dequeued element is :"<<arr[front];
                        front = (front+1)%max_size;
                }
        }
        void display()
        {
                int i = front;
                while(true)
                {
                        if(i==rear){
                                cout<<arr[i];
                                break;}
                        cout<<arr[i]<<"   ";
                        i = (i+1)%max_size;
                }
                cout<<endl;



        }
};
int main()
{
        circular c;
        c.read();
        int x;
        do
        {
                cout<<"1.enqueue"<<endl;
                cout<<"2.dequeue"<<endl;
                cout<<"3.display"<<endl;
                cout<<"0.exit"<<endl;
                cout<<"Enter your choice:";
                cin>>x;
                switch(x)
                {
                        case 1:
                                int val;
                                cout<<"Enter the value need to be enqueud:";
                                cin>>val;
                                c.enqueue(val);
                                break;
                        case 2:
                                c.dequeue();
                                break;
                        case 3:
                                c.display();
                                break;
                        default:
                                break;
                }
        }while(x!=0);

}
