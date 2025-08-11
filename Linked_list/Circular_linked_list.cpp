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
                void insert_pos(int num , int pos)
                {
                        temp = head;
                        int i=0;
                        if(pos ==0)
                        {
                                insert_front(val);
                                return;
                        }
                        while(i < pos-1 && temp->next!=head)
                        {
                                temp = temp->next;
                                i++;

                        }
                        if(temp == head || temp->next!=head)
                        {
                                cout<<"Invalid position";
                                return;
                        }
                        node * temp2 = temp1->next;
                        temp1->next = temp2->next;
                        delete temp2;
                        cout<<"The node is deleted"<<endl;

                }
                void display(){
                        temp = head;
                                while(temp->next!=head)
                        {
                                cout<<temp->data<<" ";
                                temp =temp->next;
                        }
                                cout<<temp->data;
                }


};
int main()
{
        circular_linked ll;
        ll.insert_front(7);
        ll.insert_back(5);
        ll.insert_back(45);
        ll.insert_front(34);
        ll.insert_pos(23,1);
        ll.display();
}
