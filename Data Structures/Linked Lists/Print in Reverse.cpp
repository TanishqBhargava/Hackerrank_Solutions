/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
void reversePrint(SinglyLinkedListNode* head) 
{
    if(head == NULL)
        return;
    reversePrint(head->next);
    cout << head->data << endl;
}
