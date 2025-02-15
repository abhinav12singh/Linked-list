
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL) 
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* rev_linkedlist(node* head)
{
    node *prev=NULL;
    node *curr=head;
    node *Next=head->next;
    while(curr!=NULL && Next!=NULL)
    {    Next=curr->next; 
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    return prev;
}
int main(){
    node* head=takeinput();
    head=rev_linkedlist(head);
    print(head);
    return 0;
}
