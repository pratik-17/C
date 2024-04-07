#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void at_end(struct node **head, int d);

int main()
{
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 20;
    temp->next = NULL;
    head->next = temp;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=30;
    temp->next = NULL;
    head->next->next = temp;

    int data = 200;
    at_end(&head, data);

    struct node *ptr = head;
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }

    return 0;

}

void at_end(struct node **head, int d)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    
    if(*head == NULL)
    {

        *head = temp;

    }

    else
    {
        struct node *last = *head;
        while (last->next != NULL)
        {
            last = last->next;

        }
        last->next = temp;
        
    }
}