#include <iostream>
using namespace std;

class Node
{  
   public:
   int num;
   Node *next;
}*head=NULL,*tail=NULL;
  
   void AddNode(int n)
   {
      Node *tmp=new Node;
      tmp->num=n;
      tmp->next=NULL;
      if(head=NULL)
      {
         head=tmp;
         tail=tmp;
      }
      else
      {
         tail->next=tmp;
         tail=tail->next;
      }
   }
   void Insert(int data, int position)
   {
      Node *n=new Node;
      n->num=data;  
      if(position==0)
      {
      n->next=head;
      head=n;
     }
     else
     {
         Node *c=new Node;
         int count=1;
         c=head;
         while(count!=position)
         {
          c=c->next;
          count++;
         }
      n->next=c->next;
      c->next=n;
     }
   }
   void deleteNode(int pos)
   {
      int count=0;
      Node* temp, *temp1;
      temp = head  ;
      if(head==NULL)
      {
        cout<<"\n \nLinked List Empty !!!";
      }
      else if(pos == 0)
      {
        head = head->next;
        delete temp;
      }
      else
      {
      while(count!= pos-1)
      {
         temp = temp->next;
         count++;   
      }
      temp1 = temp->next;
      temp->next = temp1->next;
      temp1->next=NULL;
      delete temp1;
   }
   }
   void displayList()
   {
    if(head==NULL)
      cout << "\nThe List is empty";
    
    else
    {
      Node *temp = head;
      while(temp != NULL)
      {
       cout << temp->num;
       cout<<" ";
       temp = temp->next;
      }
     }
    }
   
int main()
{
    int ch,x;
    char cha;
    int pos;
    cout<<"\n \nPROGRAM TO USE THE CONCEPT OF LINKED LIST";
    do 
    {
       cout<<"\n1. Add a node \n2. Insert a node at a place \n3. Delete a node \n4.Display ";
       cout<<"\nPlease enter your choice: ";
       cin>>ch;
       switch(ch)
       {
       case 1:
       {
              cout<<"\nEnter the data: ";
              cin>>x;
              AddNode(x);
        }
       case 2:
         {     cout<<"\nEnter the data to be inserted";
              cin>>x;
              cout<<"\nEnter the position to insert the node";
              cin>>pos;
              Insert(x,pos);
          }
       case 3:
           {   cout<<"\nEnter the position of node to be deleted ";
              cin>>pos;
              deleteNode(pos);
            }
       case 4:
             { displayList();
              }
       default:
             { cout<<"\nWrong choice !!!!";}
    }
    cout<<"Do you want to continue? (y/n)";
    cin>>cha;
    }
    while(cha=='y' || cha=='Y');
    return 0;
}

