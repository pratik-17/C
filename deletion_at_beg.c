#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void delete_at_beg(struct node **head);

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
    temp->data = 30;
    temp->next = NULL;
    head->next->next = temp;

    delete_at_beg(&head);

    struct node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}

void delete_at_beg(struct node **head)
{
    
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);

}
