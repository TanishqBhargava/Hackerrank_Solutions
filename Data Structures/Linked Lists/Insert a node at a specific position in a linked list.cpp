/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) 
{
    SinglyLinkedListNode* temp = head;
    for(int i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    SinglyLinkedListNode* ins1 = new SinglyLinkedListNode(data);
    ins1->next = temp->next;
    temp->next = ins1;
    return head;
}
