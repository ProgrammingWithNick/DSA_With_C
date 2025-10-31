#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push() {
    int value;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to push: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack.\n", value);
}

void pop() {
    if (top == NULL)
        printf("Stack Underflow! Stack is empty.\n");
    else {
        struct Node *temp = top;
        printf("%d popped from stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct Node *temp = top;
    if (temp == NULL)
        printf("Stack is empty.\n");
    else
    {
        printf("Stack elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
