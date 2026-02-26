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

void Print()
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Delete node at position n (1-based index)
void Reverse()
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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

    Print();   // 2 1 8 6 3

    Reverse();
    Print();

    Free();
    
    return 0;
}
