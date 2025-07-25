#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
   
    node(int val)
    {
       data=val;
       next= nullptr;
        
    }
};
class ll{
    public:
    node* head=nullptr;
    node* temp=nullptr;
    node* newNode=nullptr;
    
    void push_back(int val)
    {
       newNode = new node(val);
       if(head==nullptr)
       {
           head =temp = newNode;
           
       }
       else
       {
           temp->next= newNode;
           temp = newNode;
       }
       
    }
    
    void print()
    {
        node* tail = nullptr;
        tail = head;
        while(tail!=nullptr){
        cout<<tail->data<<" ";
       tail = tail->next;
        }
        cout<<endl;
    }
    void insert(int val)
    {
        node* insertnode =new node(val);
       
        insertnode->next=head;
         head = insertnode;
    }
    void push(int val)
    {
          node* t = new node(val);

    if (head == nullptr) {
        head = temp = t;  
        return;}
        node* temp1=head;
        while(temp1->next!=nullptr )
        temp1 = temp1->next;
        
        node* tt = new node(val);
          temp1->next=tt;
        tt->next=nullptr;
      
    }
    void custom(int val)
    {
        int i=1;
        int pos =2;
        node* tem = head;
        while(i<pos){
        tem = tem->next;
        i++;}
        node* cus = new node(val);
        cus->next=tem->next;
        tem->next=cus;
        
        
    }

    void delete_front()
    {
        node * te = head;
        head = head->next;
        delete te;

    }
    void length()
    {
        int count =0 ;
        node * te = head;
        while(temp->next!=nullptr)
        {
            count++;
            temp = temp->next; 
        }
        cout<<count<<endl;
    }
};
int main()
{
    ll s;
    s.push_back(5);
    s.push(66);
    s.push(1);
    s.custom(22);
    s.insert(56);
   
    s.delete_front();\
    s.length();
     s.print();

    return 0;
}
