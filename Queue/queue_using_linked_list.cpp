#include<iostream>
using namespace std;
class node{
        public:
                int data;
                node * next;

                node(int val)
                {
                        data = val;
                        next = nullptr;
                }
};
class ll{
        public:
                node * head = nullptr;
                node * temp = nullptr;

		void enque(int val)
                {
                        node * newnode = new node(val);
                        if(head == nullptr)
                                head = temp = newnode;
                        else
                        {
                                while(temp->next!=nullptr)
                                {
                                        temp = temp->next;

                                }
                                temp->next =newnode;
                        }


                }

		void deque()
                {
                        if(head ==nullptr)
                                cout<<"The Queue is Empty"<<endl;
                        else{
                        node * temp1 = head;
                        head = head->next;
			 cout<<"The dequeued value:"<<temp1->data<<endl;
                        delete temp1;
                       
                        }
                }

                void display()
                {
                        temp = head;
			cout<<"Queue: ";
                        while(temp!=nullptr)
                        {
				
                                cout<<temp->data<<" ";
                                temp= temp->next;
                        }
                        cout<<endl;
                }
};
int main()
{
        ll list;
        int choice;
        do{
                cout<<"1.Enqueue"<<endl;
                cout<<"2.Dequeue"<<endl;
                cout<<"3.display"<<endl;
                cout<<"0.exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;
                switch(choice)
                {
                        case 1:
                                int num;
                                cout<<"Enter a number:";
                                cin>>num;
                                list.enque(num);
                                break;
                        case 2:
                              
                                list.deque();
				break;
                                
                        case 3:
                                list.display();
                                break;
                        case 0:
                                break;
                        default:
                                break;
                }


                }while(choice!=0);
}


