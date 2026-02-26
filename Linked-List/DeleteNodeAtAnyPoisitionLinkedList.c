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
void Delete(int n)
{
    if (head == NULL)
        return;

    struct Node* temp1 = head;

    // Delete first node
    if (n == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }

    // Reach (n-1)th node
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
        if (temp1 == NULL)
            return; // position out of range
    }

    struct Node* temp2 = temp1->next; // nth node
    if (temp2 == NULL)
        return;

    temp1->next = temp2->next;
    free(temp2);
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

    int n;
    printf("Enter the position to be deleted: ");
    scanf("%d", &n);

    Delete(n);
    Print();

    Free();
    
    return 0;
}
