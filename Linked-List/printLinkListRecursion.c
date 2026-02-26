// Print the linked list using the recursion in a reverse order
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

// Insert node at the END of the linked list
void Insert(int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void Print(struct Node* p)
{
    if (p == NULL) return;
    Print(p -> next);    
    printf("%d ", p -> data);
}

void Free()
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        struct Node* next = temp->next;  // save next node
        free(temp);                      // free current node
        temp = next;                     // move forward
    }
    head = NULL; // list is now empty
}

int main()
{
    head = NULL;

    Insert(2);
    Insert(1);
    Insert(8);
    Insert(6);
    Insert(3);

    Print(head);   // 2 1 8 6 3
    printf("\n");
    
    Free();
    
    return 0;
}
