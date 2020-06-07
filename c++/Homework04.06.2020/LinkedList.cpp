#include <iostream>
#include <stdlib.h>
class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
    LinkedList(){
        head=NULL;
    }
    ~LinkedList();
    void insert(int val);
    void display();
    void deleteElement(int val);
    void empty();
    int getElementByIndex(int index);
    private:
    Node* head;
};
void LinkedList::insert(int val) {
    Node* newnode=new Node();
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else
    {
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
}
int LinkedList::getElementByIndex(int index){
  Node* current = head;
  int count=0;
  while(current!=NULL){
      if(count==index)
      return current->data;
      count++;
      current=current->next;
  }
  return -1;
}
void LinkedList::deleteElement(int index){
  if(head==NULL)
  return;
  Node* temp=head;
  if(index==0){
      head=temp->next;
      free(temp);
      return;
  }
  for(int i=0;temp!=NULL && i<index-1;i++)
      temp=temp->next;
      if(temp==NULL || temp->next==NULL)
      return;
      Node *next=temp->next->next;
      free(temp->next);
      temp->next=next;

  
}
void LinkedList::empty(){
    if(head==NULL)
    return;
    Node* current=head;
    Node* next;
    while (current!=NULL)
    {
        next=current->next;
        delete(current);
        current=next;
    }

    head=NULL;

}
   

void LinkedList::display() {
    if(head==NULL){
        std::cout<<"List is empty!"<<'\n';

    }
   else {
        Node* temp=head;
        while (temp!=NULL)
        {
            std::cout<<temp->data<<" ";
            temp=temp->next;
        }
        std::cout<<'\n';
        
   }
}
int main(){
    LinkedList* list=new LinkedList();
    list->insert(145);
    list->insert(147);
    list->insert(108);
    list->display();
    std::cout<<"Second element is "<<list->getElementByIndex(1)<<'\n';
    list->deleteElement(1);
    std::cout<<"Linked List:"<<'\n';
    list->display();
    list->empty();
    list->display();
    return 0;
}
