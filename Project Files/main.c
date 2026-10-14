#include "phonebook.h"

int main(void)
{
    Contact *head = NULL;
    char choice;

    sync_file(&head);

    while (1)
    {
        printf("\n------------------MENU---------------------------\n");
        printf("c/C: Create a new contact\n");
        printf("p/P: Print all contacts\n");
        printf("d/D: Delete contact\n");
        printf("f/F: Find contact\n");
        printf("e/E: Edit a contact\n");
        printf("s/S: To save the contacts in the file\n");
        printf("q/Q: Quit from app\n");
        printf("-------------------------------------------------\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);
        clear_input_buffer();

        switch (choice)
        {
            case 'c':
            case 'C':
                create_contact(&head);
                break;

            case 'p':
            case 'P':
                print_contacts(head);
                break;

            case 'd':
            case 'D':
                delete_contact(&head);
                break;

            case 'f':
            case 'F':
                find_contact(head);
                break;

            case 'e':
            case 'E':
                edit_contact(head);
                break;

            case 's':
            case 'S':
                save_contacts(head);
                break;

            case 'q':
            case 'Q':
                save_contacts(head);
                printf("Thank you. Phone book closed.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
