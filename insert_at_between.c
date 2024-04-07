#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void at_between(struct node **head, int position, int d);

int main()
{
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 100;
    head->next = NULL;

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 200;
    temp->next = NULL;
    head->next = temp;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 300;
    temp->next = NULL;
    head->next->next = temp;

    int position = 2;
    int data = 9000;
    at_between(&head, position, data);

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}

void at_between(struct node **head, int position, int d)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;

    if (position == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct node *prev = *head;
    for (int i = 1; i < position - 1 && prev != NULL; i++)
    {
        prev = prev->next;
    }

    temp->next = prev->next;
    prev->next = temp;


}