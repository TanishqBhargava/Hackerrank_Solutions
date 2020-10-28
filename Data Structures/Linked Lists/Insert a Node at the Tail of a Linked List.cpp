/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) 
{
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* c = head;
    if(head == NULL)
        return temp;
    while(c->next != NULL)
        c = c->next;
    c->next = temp;
    return head;
}
