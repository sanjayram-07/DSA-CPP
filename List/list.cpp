#include<iostream>
using namespace std;
class list{
        private:
                int arr[100];
                int lenght;
                int max = 100;
                int n=0;
        public:
                list()
                {
                        lenght =0;
                }
                void read()
                {
                        cout<<"enter how many nuber want to enter:";
                        cin>>n;
                        for(int i=0; i < n ;i++)
                        {
                                cout<<"enter number"<<i<<":";
                                cin>>arr[i];
                        }
                        lenght = n ;
                }

                void insert_front(int val){
                        if(lenght ==max)
                                cout<<"The list is full"<<endl;

                        for(int i =lenght ; i>=0; i--)
                        {
                                arr[i+1]= arr[i];

                        }
                        arr[0]=val;
                        lenght++;
                }
                void insert_back(int val)
                {
                          if(lenght ==max)
                                cout<<"The list is full"<<endl;
                        arr[lenght]=val;
                        lenght++;
                }
                void insert_pos(int pos , int val)
                {
                          if(lenght ==max)
                                 cout<<"The list is full"<<endl;
                        for(int i=lenght ;i >=pos ; i--)
                        {
                                arr[i+1] = arr[i];
                        }
                        arr[pos] =val;
                        lenght++;
                }
                void delete_front()
                {
                        if(lenght ==0)
                                cout<<"cannot delete list is empty";
                        for(int i =0; i<lenght ; i++)
                                {
                                        arr[i]=arr[i+1];
                                }
                        lenght--;
                }
                void delete_back()
                {
                        if(lenght ==0)
                                cout<<"cannot delete list is empty";
                        lenght--;
                }
                void delete_pos(int pos)
                {
                        if(lenght ==0)
                                cout<<"cannot delete list is empty";
                        for(int i=pos ; i <lenght;i++)
                        {
                                arr[i] = arr[i+1];
                        }
                        lenght--;
                }
                int search(int val)
                {
                        for(int i =0 ; i <lenght; i++)
                        {
                                if(arr[i] == val)
                                        return i;
                        }
                        return -1;
                }
                void delete_ele(int val)
                {
                        int a = search(val);
                        if(a==-1)
                                cout<<"The value does not exist in the list";
                        for(int i=a; i < lenght;i++)
                        {
                                arr[i] = arr[i+1];
                        }
                        lenght--;
                }
                void min_max()
                {
                        int small=arr[0], big= arr[0];
                        for(int i =0 ; i < lenght ; i++)
                        {
                                if(arr[i] < small)
                                {
                                        small = arr[i];
                                }
                                if(arr[i] > big)
                                {
                                        big = arr[i];
                                }
                        }
                        cout<<"The max element of the array is :"<<big<<endl;
                        cout<<"The min element of teh array is : " <<small<<endl;
                }
                void is_empty()
                {
                        if(lenght==0)
                                cout<<"The list is empty"<<endl;
                        else
                                cout<<"The list is Not empty"<<endl;
                }
                void is_full()
                {
                        if(lenght==max)
                        {cout<<"The list is full"<<endl;
                        }
                        else
                                cout<<"The list is Not full"<<endl;
                }
                void display()
                {
                        for(int i=0 ; i<lenght ; i++)
                        {
                                cout<<arr[i]<<"  ";
                        }
                        cout<<endl;
                }
};
int main()
{
        list ll;
        ll.read();
        int choice;
        do{
                cout<<"1.insert_front"<<endl;
                cout<<"2.insret_back"<<endl;
                cout<<"3.insert_pos"<<endl;
                cout<<"4.delete_front"<<endl;
                cout<<"5.delete_back"<<endl;
                cout<<"6.delete_pos"<<endl;
                cout<<"7.display"<<endl;
                cout<<"8.delete_element"<<endl;
                cout<<"9.min_max"<<endl;
                cout<<"10.is_empty"<<endl;
                cout<<"11.is_full"<<endl;
                cout<<"12. exit"<<endl;
                cout<<"enter your choice:"<<endl;
                cin>>choice;
                switch(choice)
                {
                        case 1 :
                                int num2;
                                cout<<"enter a number:";
                                cin>>num2;
                                ll.insert_front(num2);
                                break;
                        case 2:
                                int nu;
                                cout<<"enter a number:";
                                cin>>nu;
                                ll.insert_back(nu);
                                break;
                        case 3:
                                int pos1 , num1 ;
                                cout<<"enter the pos and number:";
                                cin>>pos1;
                                cin>>num1;
                                ll.insert_pos(pos1,num1);
                                break;
                        case 4 :
                                ll.delete_front();
                                break;
                        case 5:
                                ll.delete_back();
                                break;
                        case 6:
                                int pos2;
                                cout<<"enter a pos :";
                                cin>>pos2;
                                ll.delete_pos(pos2);
                                break;
                        case 7:
                                ll.display();
                                break;
                        case 8:
                                int num3;
                                cout<<"enter a num:";
                                cin>>num3;
                                ll.delete_ele(num3);
                                break;
                        case 9:
                                ll.min_max();
                                break;
                        case 10:
                                ll.is_empty();
                                break;
                        case 11:
                                ll.is_full();
                                break;
                        case 12:
                                break;

                }



        }while(choice !=12);

}
