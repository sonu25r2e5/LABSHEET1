#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *top = NULL;

void push()
{
    int x;
    printf("Enter the element to be pushed: ");
    scanf("%d", &x);
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = x;
    temp->next = top;
    top = temp;
    printf("%d pushed to stack\n", x);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    int x = top->data;
    struct Stack *temp = top;
    top = top->next;
    free(temp);
    printf("%d popped from stack\n", x);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Stack *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
