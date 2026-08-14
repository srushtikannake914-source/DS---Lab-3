#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is Full!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("%d inserted into queue.\n", value);
}

// Dequeue operation
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Display operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Circular Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

// Main function
int main()
{
    int choice, value;

    do
    {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}