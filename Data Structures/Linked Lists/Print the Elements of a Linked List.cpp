/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
void printLinkedList(SinglyLinkedListNode* head) 
{
    // SinglyLInkedList* temp=head;
        while(head)
        {
            cout << head->data << endl;
            head = head->next;
        }
}
