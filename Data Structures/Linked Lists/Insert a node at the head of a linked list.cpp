/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) 
{
   // this->data = data;
    SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
    temp->next = llist;
    return (temp);
}
