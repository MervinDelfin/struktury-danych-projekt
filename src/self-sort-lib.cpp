#include<iostream>
using namespace std;
struct node {
   int d;
   node *next;
};
node* CreateNode(int d) {
   node *newnode = new node;
   newnode->d = d;
   newnode->next = NULL;
   return newnode;
}
node* InsertIntoList(node *head, int d) {
   node *temp = CreateNode(d);
   node *t = new node;
   t = head;
   if(head == NULL) {
     head = temp;
     return head;
   } else {
      while(t->next != NULL)
      t = t->next;
      t->next = temp;
   }
   return head;
}
void Display(node *head) {
   node *temp = new node;
   temp = head;
   cout<<"\n The list state is :";
   while(temp->next != NULL) {
      cout<<"->"<<temp->d;
      temp = temp->next;
   }
}
node* SearchItem(node *head, int item) {
   int flag = 0;
   node *temp = new node;
   node *t = new node;
   temp = head;
   if(temp->d == item) {
      // cout<<"\nItem found at head node";
      flag = 5;
      // Display(head);
      return head;
   } else {
      while((temp->next)->next != NULL) {
         if((temp->next)->d == item) {
            // cout<<"\nItem found";
            flag = 5;
            break;
         }
         temp = temp->next;
      }
      t = (temp->next)->next;
      (temp->next)->next = head;
      head = temp->next;
      temp->next = t;
      // if(flag == 5)
      //    Display(head);
      // else
      //    cout<<"\nItem not found.";
   }
   return head;
}
// int main() {
//    int i, n;
//    char ch;
//    node *head = new node;
//    head = NULL;
//    for(i = 1; i < 20; i++)
//       head = InsertIntoList(head, i);
//       Display(head);
//    up:
//       cout<<"\nEnter the Element to be searched: ";
//       cin>>n;
//       head = SearchItem(head, n);
//       cout<<"\n\n\tDo you want to search more...enter choice(y/n)?";
//       cin>>ch;
//       if(ch == 'y' || ch == 'Y')
//          goto up;
//       return 0;
// }