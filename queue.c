#include <stdio.h>
#include <stdlib.h>

int *queue, front = -1, rear = -1, capacity;

void enqueue()
{
    int x;
    printf("Enter the element to be enqueued: ");
    scanf("%d", &x);
    if (rear == capacity - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = x;
    printf("%d enqueued to queue\n", x);
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    int x = queue[front];
    front++;
    printf("%d dequeued from queue\n", x);
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);
    queue = (int *)malloc(sizeof(int) * capacity);
    int choice;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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
