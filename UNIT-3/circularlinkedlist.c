#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void create_cll();
void display();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_specific();

void main()
{
    int option;

    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a specific node");
        printf("\n 10: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1: create_cll();
                    printf("\n CIRCULAR LINKED LIST CREATED");
                    break;
            case 2: display();
                    break;
            case 3: insert_beg();
                    break;
            case 4: insert_end();
                    break;
            case 5: insert_before();
                    break;
            case 6: insert_after();
                    break;
            case 7: delete_beg();
                    break;
            case 8: delete_end();
                    break;
            case 9: delete_specific();
                    break;
        }
    } while(option != 10);
}

void create_cll()
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if(start == NULL) {
            new_node -> next = new_node;
            start = new_node;
        } else {
            ptr = start;
            while(ptr -> next != start)
                ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> next = start;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
}

void display()
{
    struct node *ptr;
    if(start == NULL) {
        printf("\n List is empty");
        return;
    }
    ptr = start;
    while(1) {
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
        if(ptr == start)
            break;
    }
}

void insert_beg()
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;

    if(start == NULL) {
        new_node -> next = new_node;
        start = new_node;
        return;
    }

    ptr = start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> next = start;
    start = new_node;
}

void insert_end()
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;

    if(start == NULL) {
        new_node -> next = new_node;
        start = new_node;
        return;
    }

    ptr = start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> next = start;
}

void insert_before()
{
    struct node *new_node, *ptr, *preptr;
    int num, val, found = 0;
    if(start == NULL) {
        printf("\n List is empty");
        return;
    }
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;

    if(start->data == val) {
        insert_beg();
        free(new_node);
        return;
    }

    ptr = start;
    while(ptr -> next != start) {
        preptr = ptr;
        ptr = ptr -> next;
        if(ptr -> data == val) {
            preptr -> next = new_node;
            new_node -> next = ptr;
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("\n Value not found...");
        free(new_node);
    }
}

void insert_after()
{
    struct node *new_node, *ptr;
    int num, val, found = 0;
    if(start == NULL) {
        printf("\n List is empty");
        return;
    }
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;

    ptr = start;
    while(1) {
        if(ptr -> data == val) {
            new_node -> next = ptr -> next;
            ptr -> next = new_node;
            found = 1;
            break;
        }
        ptr = ptr -> next;
        if(ptr == start)
            break;
    }
    if(found == 0) {
        printf("\n Value not found...");
        free(new_node);
    }
}

void delete_beg()
{
    struct node *ptr;
    if(start == NULL) {
        printf("\n List is empty");
        return;
    }

    if(start->next == start) {
        free(start);
        start = NULL;
        return;
    }

    ptr = start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = start -> next;
    free(start);
    start = ptr -> next;
}

void delete_end()
{
    struct node *ptr, *preptr;
    if(start == NULL) {
        printf("\n List is empty");
        return;
    }

    if(start->next == start) {
        free(start);
        start = NULL;
        return;
    }

    ptr = start;
    while(ptr -> next != start) {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = ptr -> next;
    free(ptr);
}

void delete_specific()
{
    struct node *ptr, *preptr;
    int val, found = 0;
    if(start == NULL) {
        printf("\n List is empty");
        return;
    }

    printf("\n Enter the value of the node to be deleted : ");
    scanf("%d", &val);

    if(start->data == val) {
        delete_beg();
        return;
    }

    ptr = start;
    while(ptr -> next != start) {
        preptr = ptr;
        ptr = ptr -> next;
        if(ptr -> data == val) {
            preptr -> next = ptr -> next;
            free(ptr);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("\n Value not found...");
}
