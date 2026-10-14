#include "phonebook.h"

void print_one_contact(Contact *contact)
{
    int i;

    printf("\nName     : %s\n", contact->name);

    for (i = 0; i < contact->phone_count; i++)
        printf("Number-%d : %s\n", i + 1, contact->phone[i]);

    if (strlen(contact->email) > 0)
        printf("Email    : %s\n", contact->email);
    else
        printf("Email    : Not available\n");

    if (strlen(contact->address) > 0)
        printf("Address  : %s\n", contact->address);
    else
        printf("Address  : Not available\n");

    printf("-----------------------------------------------\n");
}

void print_contacts(Contact *head)
{
    Contact *temp = head;

    if (temp == NULL)
    {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\n================ ALL CONTACTS ================\n");

    while (temp != NULL)
    {
        print_one_contact(temp);
        temp = temp->next;
    }
}
