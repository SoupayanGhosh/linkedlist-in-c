#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node *root = NULL;

void append(int data) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->link = NULL;

    if (root == NULL) {
        root = p;
    } else {
        struct Node* temp = root;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = p;
    }
}

void addafter(int addafter, int data) {
    struct Node* temp = root;
    while (temp != NULL && temp->data != addafter) {
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Data %d not found in the list\n", addafter);
        return;
    }

    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->link = temp->link;
    temp->link = p;
}

void delete(int data) {
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = root;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Data %d not found\n", data);
        return; 
    }

    if (prev == NULL) {
        root = temp->link;
    } else {
        prev->link = temp->link;
    }

    free(temp);
}

void addbegin(int data) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->link = root;
    root = p;
}

void display() {
    struct Node* temp = root;
    if (temp == NULL) {
        printf("List is empty\n");
        return; // Return statement fixed to match void return type
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int length() {
    int count = 0;
    struct Node* temp = root;
    while (temp != NULL) {
        count++; // Typo fixed
        temp = temp->link;
    }
    return count;
}

int main() {
    int ch, data;

    while (1) {
         printf("Enter Choice For Operation:\n");
        printf("1. Append\n");
        printf("2. Add after\n");
        printf("3. Add begin\n");
        printf("4. Display\n");
        printf("5. Delete\n");
        printf("6. Length\n");
        printf("7. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(data);
                break;
            case 2:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter data after which to add: ");
                int afterData;
                scanf("%d", &afterData);
                addafter(afterData, data);
                break;
            case 3:
                printf("Enter data to add at the beginning: ");
                scanf("%d", &data);
                addbegin(data);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 6:
                printf("Length of the linked list: %d\n", length());
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
