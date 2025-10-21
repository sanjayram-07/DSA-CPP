#include<iostream>
using namespace std;
class pqueue
{
    public:
    int arr[100];
    int size =0;
void insert(int value)
{
        size++;
        int i = size;
        arr[i] = value;

        int parent = i/2;
        while(i>1 && arr[parent]< arr[i])
            {
                swap(arr[parent],arr[i]);
                i = parent;
                parent = i/2;
            }       

}

void pdelete()
{
    if(size==0)
    {
        cout<<"The Queue is Empty"<<endl;
        return;
    }

    cout<<"The deleted value : "<<arr[1]<<endl;
    arr[1] = arr[size];
    size--;

    int i=1;
    while((2*i) <= size)
    {
        int child = 2*i;
        if( child+1 <= size && arr[child] < arr[child+1])
        {
            child = child+1;
        }
        if(arr[i]<arr[child])
        {
            swap(arr[i],arr[child]);
            i = child;
        }
        else{
            break;
        }
    
    }

}

void display()
{

        if (size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        
        for(int i =1 ;i <=size;i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        
}

};
int main()
{
        pqueue q;
      
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
                                q.insert(value);
                                break;

                        case 2:
                                q.pdelete();
                                break;
                        case 3:
                            q.display();
                            break;
                       
                        default:
                                break;
                }

                }while(x !=0);

        }
