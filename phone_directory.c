#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact* prev;
    struct Contact* next;
} Contact;

Contact* head = NULL;

Contact* createContact(char* name, char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->prev = NULL;
    newContact->next = NULL;
    return newContact;
}

void addContact(char* name, char* phone) {
    Contact* newContact = createContact(name, phone);
    if (head == NULL) {
        head = newContact;
    } else {
        Contact* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
        newContact->prev = temp;
    }
    printf("Contact added: %s, %s\n", name, phone);
}

void display() {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }
    Contact* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

void delete(char* name) {
    Contact* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;   
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Contact deleted: %s\n", name);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found: %s\n", name);
}

void searchContact(char* name) {
    Contact* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found: %s\n", name);
}

// Function to free the memory of the contact list
void freeContacts() {
    Contact* temp = head;
    while (temp != NULL) {
        Contact* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    head = NULL;
}

int main() {
    int choice;
    char name[50];
    char phone[15];

    do {
        printf("\nPhone Directory Application\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n"); // Added search option
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; 
                printf("Enter phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0'; 
                addContact(name, phone);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter name of the contact to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  
                delete(name);
                break;
            case 4:
                printf("Enter name of the contact to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  
                searchContact(name); // Call to search function
                break;
            case 5:
                freeContacts();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
