#include<iostream>
using namespace std;
class node{
        public:
                int data;
                node* next;
                node * pre;

                node(int val)
                {
                        data = val;
                        next = nullptr;
                        pre = nullptr;
                }
};
class doubly{
        public:
                node * head = nullptr;
                node *tail = nullptr;
                void insert_back(int val)
                {
                        node * newnode  = new node(val);
                        if(head == nullptr)
                        {
                                head = tail = newnode;

                        }
                        else
                        {
                                while(tail->next!=nullptr)
                                {
                                        tail = tail->next;
                                }
                                tail->next= newnode;
                                newnode->pre = tail;
                                tail = newnode;
                        }
                }
                void insert_front(int val)
                {
                        node *newnode = new node(val);
                        if(head == nullptr)
                                head = tail = newnode;
                        else
                        {
                                tail->next = newnode->pre;
                                newnode->next = head;
                                head->pre = newnode;
                                head = newnode;
                        }
                }
                void display()
                {
                        node *temp  = head;
                        while(temp!=nullptr)
                        {
                                cout<<temp->data<<" ";
                                temp = temp->next;
                        }
                        cout<<endl;
                }
};
int main()
{
        doubly dl;
        int choice;
        do{
                cout<<"1.insert_back"<<endl;
                cout<<"2.insert_front"<<endl;
                cout<<"3.display"<<endl;
                cout<<"0.exit"<<endl;
                cout<<"Enter your choice:";
                cin>>choice;
                switch(choice){
                case 1:
                        int num;
                        cout<<"enter the value: ";
                        cin>>num;
                        dl.insert_back(num);
                        break;
                case 2:
                        int num1;
                        cout<<"enter the number: ";
                        cin>>num1;
                        dl.insert_front(num1);
                        break;
                case 3:
                        dl.display();
                        break;
                case 0:
                        break;
                default:
                        break;
                }

        }while(choice!=0);
}
