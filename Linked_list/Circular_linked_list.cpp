
#include<iostream>
using namespace std;
class node{
        public:
                int data;
                node* next;

                node(int val)
                {
                        data = val;
                        next = nullptr;
                }
};
class circular_linked
{
        public:
                node* head = nullptr;
                node* temp = nullptr;
                int length()
                {
                    int i=0;
                    temp = head;
                    while(temp->next !=head)
                    {
                        temp= temp->next;
                        i++;
                    }
                    i++;
                    return i;
                }
                void insert_back(int val)
                {

                        node * newnode = new node(val);
                        if(head == nullptr)
                        {
                                head = temp = newnode;
                                temp->next = head;
                        }
                        else
                        {
                                while(temp->next!=head)
                                {
                                        temp = temp->next;
                                }
                                temp->next = newnode;
                                newnode->next = head;

                        }
                }
                void insert_front(int val)
                {
                        node* newnode = new node(val);
                        if(head == nullptr)
                        {
                                head = temp = newnode;
                                temp->next = head;
                        }
                        else{
                                temp = head;
                                while(temp->next!=head)
                                {
                                        temp= temp->next;
                                }
                                newnode->next = head;
                                head = newnode;
                                temp->next=head;


                        }
                }
                void insert_pos(int val ,int pos)
                {
                        node *newnode = new node(val);
                        temp = head;
                        int i=0;
                        if(pos ==0)
                        {
                                insert_front(val);
                                return;
                        }
                        if(pos ==length())
                        {
                            insert_back(val);
                            return;
                        }
                        while(i < pos-1 && temp->next!=head)
                        {
                                temp = temp->next;
                                i++;

                        }
                        if( temp->next==head)
                        {
                                cout<<"Invalid position"<<endl;
                                return;
                        }
                        newnode->next = temp->next;
                        temp->next = newnode;

                }
                void display(){
                        temp = head;
                        cout<<"LIST : ";
                                while(temp->next!=head)
                        {
                                cout<<temp->data<<" ";
                                temp =temp->next;
                        }
                                cout<<temp->data;
                                cout<<endl;
                }


};
int main()
{
        circular_linked ll;
        int choice;
        do{
            cout<<"1.insert_back"<<endl;
            cout<<"2.insert_front"<<endl;
            cout<<"3.insert_pos"<<endl;
            cout<<"4.display()"<<endl;
            cout<<"0.exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    int num;
                    cout<<"Enter a number:";
                    cin>>num;
                    ll.insert_back(num);
                    break;
                case 2:
                    int num1;
                    cout<<"Enter a number: ";
                    cin>>num1;
                    ll.insert_front(num1);
                    break;

                case 3:
                    int pos;
                    int num2;
                    cout<<"Enter a number : ";
                    cin>>num2;
                    cout<<"Enter the position : ";
                    cin>>pos;
                    ll.insert_pos(num2,pos);
                    break;

                case 4:
                    ll.display();
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        }while(choice!=0);
        
       
}
