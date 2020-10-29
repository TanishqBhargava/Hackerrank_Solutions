/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int key) 
{
    if (key == 0) 
        return head->next;
    head->next = deleteNode(head->next, key-1);
    return head;
}
