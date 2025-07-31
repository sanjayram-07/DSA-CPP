#include<iostream>
using namespace std;
class node{
    
    public:
        int data;
        node* prev;
        node *next;

        node(int val)
        {
            data = val;
            prev = nullptr;
            next = nullptr;
        }
        
        
};
class dll{

    public:
        node* head = nullptr;
        node* tail = nullptr;
       

        void create(int val)
        {
            node* newnode =  new node(val);
            if(head == nullptr)
            {
                head = tail = newnode;
            }
            else
            {
                tail->next= newnode;
                newnode->prev = tail;
                tail = newnode;
            }
        }
        void insert_begin(int val)
        {
            node * newnode = new node(val);
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
        void insert_back(int val)
        {
            node * newnode = new node(val);    
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        void delete_begin()
        {
            node * temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }      
        void delete_end()
        {
            node * temp = tail ;
            tail= tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    
        void display()
        {
            node * temp =head;
            while(temp!=nullptr)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};
int main()
{
    dll s;
    s.create(67);
    s.insert_begin(78);
    s.insert_back(44);
    s.insert_back(76);
    s.delete_begin();
    s.delete_end();
    s.display();
}
