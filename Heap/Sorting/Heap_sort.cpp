#include<iostream>
using namespace std;
class heap
{
    public:
    int arr[100];
    int size =0;

    void insert(int val)
    {
        size ++;
        arr[size] = val;
        int i =size;

        int parent = i/2;
        while(i>1 && arr[parent]< arr[i])
        {
            swap(arr[parent], arr[i]);
            i = parent ;
            parent = i/2;
        }

    }

    void pdelete()
        {
        
             int temp = arr[1];
             arr[1] = arr[size];
             arr[size] = temp;
             size--;
             int i = 1;
             while( (2*i) <=size)
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
    
};

int main()
{
    heap obj;
    
    obj.insert(7);
    obj.insert(2);
    obj.insert(5);
    obj.insert(10);
    obj.insert(1);

    int s = obj.size;

    for(int i =0 ;  i < s ; i++)
    {
        obj.pdelete();
    }

    for(int i =1 ; i <= s ;i++)
    {
        cout<<obj.arr[i]<<" ";
    }
}
