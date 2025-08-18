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

		void pop()
                {
                        if(head ==nullptr)
                                cout<<"The stack is Empty"<<endl;
                        else{
                        node * temp1 = head;
                        head = head->next;
			                  cout<<"The poped value:"<<temp1->data<<endl;
                        delete temp1;
                        
                        }
                }
		 void push(int val)
                {
                        node *newnode = new node(val);
                        if(head ==nullptr)
                        {
                                head = temp = newnode;

                        }
                        else{
                        newnode->next = head;
                        head = newnode;
                        }
                }

                void display()
                {
                        temp = head;
			                  cout<<"STACK:"<<endl;
                        while(temp!=nullptr)
                        {
				
                                cout<<temp->data<<endl;
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
                cout<<"1.push"<<endl;
                cout<<"2.pop"<<endl;
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
                                list.push(num);
                                break;
                        case 2:
                              
                                list.pop();
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


