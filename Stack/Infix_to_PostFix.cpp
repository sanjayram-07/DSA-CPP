#include<iostream>
using namespace std;
class eval{
Press ENpublic:type command to continue
                int top =-1;
                int arr[20];
                string ans;
                int precedence(char a)
                {
                        if(a=='+'||a=='-')return 1;
                        if(a=='*'||a=='/')return 2;
                        if(a=='^')return 3;
                        return 0;
                }
                void push(char a)
                {
                        if(top ==-1)
                        {
                                arr[0] = a;
                                top++;
                        }
                        else
                        {
                                top++;
                                arr[top] =a;
                        }


                }
                char pop()
                {
                        return arr[top--];

                }
                void postfix(string num)
                {
                        for(int i =0; i < num.length() ;i++){

                        if(num[i] =='+' || num[i]=='-' || num[i] =='*' || num[i] =='/' || num[i]=='^' || num[i]=='(' ||num[i] ==')')
                        {
                                if(top ==-1)
                                push(num[i]);
                                else if(precedence(num[i]) > precedence(arr[top]))
                                                push(num[i]);
                                else if(precedence(num[i]) < precedence(arr[top]))
                                                ans+=pop();
                                else if(precedence(num[i]) == precedence(arr[top]))
                                        {
                                                ans+=pop();
                                                push(num[i]);
                                        }

                        }
                        else
                        ans+=num[i];

                        }
                        while(top!=-1){
                                ans+=pop();
                        }
                }
                void display()
                {
                        cout<<"Expression : "<<ans;
                }

};
int main()
{
        string a;
        eval obj;
        cout<<"Enter the expression ";
        cin>>a;
        obj.postfix(a);
        obj.display();
}
