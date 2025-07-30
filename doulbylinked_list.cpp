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
        node* temp = nullptr;
        node* newnode = nullptr;

        void push_back(int val)
        {
            newnode =  new node(val);
            if(head == nullptr)
            {
                head = temp = newnode;
            }
            else
            {
                temp->prev = temp;
                temp->next= newnode;
                
                temp = temp->next;
            }
        }
        void display()
        {
            node * temp1 =head;
            while(temp1!=nullptr)
            {
                cout<<temp1->data<<" ";
                temp1 = temp1->next;
            }
        }
};
int main()
{
    dll s;
    s.push_back(67);
    s.push_back(65);
    s.push_back(44);
    s.display();
}
