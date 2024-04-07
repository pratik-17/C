#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void add_at_beg(struct node **head, int d);

int main()
{
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 2;
    temp->next = NULL;
    head->next = temp;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 3;
    temp->next = NULL;
    head->next->next = temp;

    int data = 4;
    add_at_beg(&head, data);

    struct node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}

void add_at_beg(struct node **head, int d)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = *head;
    *head = temp;
}
