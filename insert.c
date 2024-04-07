#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    int data;
    struct linkedList *next;
};

void traverse(struct linkedList *node)
{
    while (node != NULL)
    {
        printf("%d\t", node->data);
        node = node->next;
    }
}

struct linkedList *insertAtStart(struct linkedList *head, int data)
{
    struct linkedList *pointer = (struct linkedList *)malloc(sizeof(struct linkedList));
    pointer->data = data;
    pointer->next = head;
    head = pointer;
    return head;
}

struct linkedList *insertAtIndex(struct linkedList *head, int data, int index)
{
    struct linkedList *pointer = (struct linkedList *)malloc(sizeof(struct linkedList));
    pointer->data = data;

    struct linkedList *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    pointer->next = p->next;
    p->next = pointer;
    return head;
}

struct linkedList *insertAtEnd(struct linkedList *head, int data)
{
    struct linkedList *pointer = (struct linkedList *)malloc(sizeof(struct linkedList));
    struct linkedList *p = head;
    pointer->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = pointer;
    pointer->next = NULL;
    return head;
}

int main()
{
    int numNodes, a, add_beg;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the data to insert at beg: ");
    scanf("%d", &add_beg);

    if (numNodes <= 0)
    {
        printf("Invalid number of nodes. Exiting...\n");
        return 1;
    }

    struct linkedList *head = NULL, *temp = NULL;

    for (int i = 0; i < numNodes; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &a);

        struct linkedList *newNode = (struct linkedList *)malloc(sizeof(struct linkedList));
        newNode->data = a;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nOriginal linkedList Elements: ");
    traverse(head);

    printf("\nAfter Insertion at Begin: ");
    head = insertAtStart(head, add_beg);
    traverse(head);


    return 0;
}
