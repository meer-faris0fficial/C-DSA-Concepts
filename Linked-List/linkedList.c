#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void Insert(int x)
{
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

// Print Linked List
void Print()
{
    struct Node* temp = head;
    printf("List is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, x;

    printf("How many numbers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the number: ");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    return 0;
}
