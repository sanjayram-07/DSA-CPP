#include<iostream>
using namespace std;
class stack{
        private:
                int arr[10];
                int top;
                int max_size = 10;
        public:
                stack()
                {
                        top=-1;
                }
        void read()
        {
                int num ;
                int val;
                cout<<"The number of element:";
                cin>>num;
                for(int i =0 ; i < num ;i++)
                {
                        cout<<"enter the value:"<<i<<":";
                        cin>>val;
                        top++;
                        arr[top] = val;

                }

        }
        void push(int val)
        {
                if(top ==max_size-1)
                cout<<"stack is full";
                else{
                top++;
                arr[top] = val;
                }
        }
        void pop()
        {
                if(top==-1)
                        cout<<"The stack is Empty"<<endl;
                else
                top--;
        }
        void display()
        {
                for(int i = top ; i>=0; i--)
                {
                        cout<<arr[i]<<endl;
                }
        }
};
int main()
{
        stack a ;
        int choice;
        a.read();
        do{
                cout<<"1.push"<<endl;
                cout<<"2.pop"<<endl;
                cout<<"3.display"<<endl;
                cout<<"0. exit"<<endl;
                cout<<"Enter your choice:";
                cin>>choice;
                switch(choice)
                {
                        case 1 :
                                int n;
                                cout<<"enter a number:";
                                cin>>n;
                                a.push(n);
                                break;
                        case 2:
                                a.pop();
                                break;
                        case 3:
                                a.display();
                                break;
                        case 0:
                                break;
                        default:
                                break;
                }
        }while(choice!=0);

}
