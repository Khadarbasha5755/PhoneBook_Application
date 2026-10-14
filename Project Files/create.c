#include "phonebook.h"

Contact *create_node(void)
{
    Contact *new_contact;

    new_contact = (Contact *)malloc(sizeof(Contact));

    if (new_contact == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    memset(new_contact, 0, sizeof(Contact));
    new_contact->next = NULL;

    return new_contact;
}

void create_contact(Contact **head)
{
    Contact *new_contact;
    char answer;

    new_contact = create_node();

    if (new_contact == NULL)
        return;

    printf("\nEnter contact name: ");
    read_line(new_contact->name, MAX_NAME);

    if (strlen(new_contact->name) == 0)
    {
        printf("Name cannot be empty.\n");
        free(new_contact);
        return;
    }

    if (contact_exists(*head, new_contact->name))
    {
        printf("Contact already exists. Duplicate contacts are not allowed.\n");
        free(new_contact);
        return;
    }

    /*
     * Enter first phone number
     */
    while (1)
    {
        printf("Enter number-1: ");
        read_line(new_contact->phone[0], MAX_PHONE);

        if (strlen(new_contact->phone[0]) == 0)
        {
            printf("Phone number cannot be empty.\n");
            continue;
        }

        new_contact->phone_count = 1;
        break;
    }

    /*
     * Add more phone numbers
     */
    while (new_contact->phone_count < MAX_NUMBERS)
    {
        printf("Do you want to add another number to the same name: (Y/N): ");
        scanf(" %c", &answer);
        clear_input_buffer();

        if (answer == 'N' || answer == 'n')
            break;

        if (answer == 'Y' || answer == 'y')
        {
            while (1)
            {
                printf("Enter number-%d: ",
                       new_contact->phone_count + 1);

                read_line(new_contact->phone[new_contact->phone_count],
                          MAX_PHONE);

                if (strlen(new_contact->phone[new_contact->phone_count]) == 0)
                {
                    printf("Phone number cannot be empty.\n");
                    continue;
                }

                /*
                 * Check whether this number is already
                 * present for the same contact.
                 */
                if (number_exists(new_contact,
                                  new_contact->phone[new_contact->phone_count]))
                {
                    printf("Number already exists for this contact.\n");
                    printf("Please enter a different number.\n");
                    continue;
                }

                new_contact->phone_count++;
                break;
            }
        }
        else
        {
            printf("Please enter Y or N.\n");
        }
    }

    /*
     * Add email
     */
    printf("Do you want to add email: (Y/N): ");
    scanf(" %c", &answer);
    clear_input_buffer();

    if (answer == 'Y' || answer == 'y')
    {
        printf("Enter email: ");
        read_line(new_contact->email, MAX_EMAIL);
    }

    /*
     * Add address
     */
    printf("Do you want to add address: (Y/N): ");
    scanf(" %c", &answer);
    clear_input_buffer();

    if (answer == 'Y' || answer == 'y')
    {
        printf("Enter address: ");
        read_line(new_contact->address, MAX_ADDRESS);
    }

    /*
     * Add contact to linked list
     */
    if (*head == NULL)
    {
        *head = new_contact;
    }
    else
    {
        Contact *temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_contact;
    }

    printf("Contact created successfully.\n");
}