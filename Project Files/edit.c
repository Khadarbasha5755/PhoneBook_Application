#include "phonebook.h"

static void edit_phone_numbers(Contact *contact)
{
    char answer;
    int i;

    printf("\nCurrent phone numbers:\n");

    for (i = 0; i < contact->phone_count; i++)
        printf("%d. %s\n", i + 1, contact->phone[i]);

    printf("Do you want to change the phone numbers: (Y/N): ");
    scanf(" %c", &answer);
    clear_input_buffer();

    if (answer == 'Y' || answer == 'y')
    {
        contact->phone_count = 0;

        while (contact->phone_count < MAX_NUMBERS)
        {
            printf("Enter number-%d: ", contact->phone_count + 1);
            read_line(contact->phone[contact->phone_count], MAX_PHONE);

            if (strlen(contact->phone[contact->phone_count]) > 0)
                contact->phone_count++;

            if (contact->phone_count == MAX_NUMBERS)
                break;

            printf("Do you want to add another number: (Y/N): ");
            scanf(" %c", &answer);
            clear_input_buffer();

            if (answer == 'N' || answer == 'n')
                break;
        }
    }
}

void edit_contact(Contact *head)
{
    char name[MAX_NAME];
    char answer;
    Contact *contact;

    if (head == NULL)
    {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to edit: ");
    read_line(name, MAX_NAME);

    contact = find_node(head, name);

    if (contact == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    printf("\nCurrent contact details:");
    print_one_contact(contact);

    printf("Do you want to edit name: (Y/N): ");
    scanf(" %c", &answer);
    clear_input_buffer();

    if (answer == 'Y' || answer == 'y')
    {
        char new_name[MAX_NAME];

        printf("Enter new name: ");
        read_line(new_name, MAX_NAME);

        if (contact_exists(head, new_name) &&
            strcmp(contact->name, new_name) != 0)
        {
            printf("Another contact already has this name.\n");
        }
        else if (strlen(new_name) > 0)
        {
            strcpy(contact->name, new_name);
        }
    }

    edit_phone_numbers(contact);

    printf("Do you want to change/add email: (Y/N): ");
    scanf(" %c", &answer);
    clear_input_buffer();

    if (answer == 'Y' || answer == 'y')
    {
        printf("Enter email: ");
        read_line(contact->email, MAX_EMAIL);
    }

    printf("Do you want to change/add address: (Y/N): ");
    scanf(" %c", &answer);
    clear_input_buffer();

    if (answer == 'Y' || answer == 'y')
    {
        printf("Enter address: ");
        read_line(contact->address, MAX_ADDRESS);
    }

    printf("Contact updated successfully.\n");
}
