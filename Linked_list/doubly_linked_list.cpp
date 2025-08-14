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

                                newnode->next = head;
                                head->pre = newnode;
                                head = newnode;
                        }
                }
                void insert_pos(int val , int pos)
                {
                        int i =0;
                        node * temp = head;
                        node * newnode = new node(val);
                        if(pos ==0){
                                insert_front(val);
                                return;
                        }
                        while(i < pos-1 && temp!= nullptr)
                        {
                                temp = temp->next;
                                i++;
                        }
                        if(temp == nullptr)
                        {
                                cout<<"Invalid position: "<<endl;
                                return;
                        }
                        newnode->pre =  temp;
                        newnode->next = temp->next;
                        temp->next = newnode;
                        if(newnode->next!=nullptr){
                        newnode->next->pre = newnode;
                        }
                }
                void delete_front()
                {
                        if(head ==nullptr){
                                cout<<"The list is Empty"<<endl;
                                return;}
                        node *temp = head;
                        head = head->next;
                        delete temp;
                        cout<<"The node is deleted"<<endl;
                }
                void delete_back()
                {
                        node *temp = tail;
                        if(head ==nullptr)
                        {
                                cout<<"The list is empty "<<endl;
                                return;
                        }
                        if(head == tail)
                        {
                                head = tail = nullptr;

                        }
                        else{

                        tail =tail->pre;
                        tail->next = nullptr;
                        }
                        delete temp;
                        cout<<"The node is deleted "<<endl;
                }
                void delete_pos(int pos)
                {
                        node * temp = head;
                        if(pos ==0)
                        {
                                delete_front();
                                return;
                        }
                         if(head == nullptr)
                        {
                                cout<<"The list is empty "<<endl;
                                return;
                        }
                        else
                        {
                                int i=0;
                                while(i<pos-1 && temp->next!=nullptr)
                                {
                                        temp = temp->next;
                                        i++;
                                }
                                node *temp2 = temp->next;
                                if(temp == nullptr || temp->next == nullptr){
                                            cout<<"invalid position"<<endl;
                                             return;
                                 }
                                if(temp2 == tail)
                                {
                                        tail =temp;
                                }
                                temp->next = temp2->next;
                                if(temp2->next !=nullptr){
                                temp2->next->pre= temp;
                                }

                                delete temp2;
                                cout<<"The node is deleted"<<endl;

                        }
                }
                void display()
                {
                        if(head == nullptr)
                        {
                                cout<<"Nothing in the list "<<endl;
                                return;
                        }
                        node *temp  = head;
                        cout<<"LIST : ";
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
                cout<<"3.insert_pos"<<endl;
                cout<<"4.delete_front"<<endl;
                cout<<"5.delete_back"<<endl;
                cout<<"6.delete_pos"<<endl;
                cout<<"7.display"<<endl;
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
                        int num2,pos;
                        cout<<"enter the number: ";
                        cin>>num2;
                        cout<<"enter the position: ";
                        cin>>pos;
                        dl.insert_pos(num2,pos);
                        break;
                case 4:
                        dl.delete_front();
                        break;
                case 5:
                        dl.delete_back();
                        break;
                case 6:
                        int pos2;
                        cout<<"Enter the position which node want to delete: ";
                        cin>>pos2;
                        dl.delete_pos(pos2);
                        break;
                case 7:
                        dl.display();
                        break;
                case 0:
                        break;
                default:
                        break;
                }

        }while(choice!=0);
}
