#include "phonebook.h"

void delete_contact(Contact **head)
{
    Contact *temp;
    Contact *previous;
    char name[MAX_NAME];

    if (*head == NULL)
    {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to delete: ");
    read_line(name, MAX_NAME);

    temp = *head;
    previous = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (previous == NULL)
                *head = temp->next;
            else
                previous->next = temp->next;

            free(temp);
            printf("Contact deleted successfully.\n");
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    printf("Contact not found.\n");
}
