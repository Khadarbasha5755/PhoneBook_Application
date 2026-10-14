#include "phonebook.h"
#include <ctype.h>

static int starts_with_ignore_case(const char *name, const char *search)
{
    int i = 0;

    while (search[i] != '\0')
    {
        if (name[i] == '\0')
            return 0;

        if (tolower((unsigned char)name[i]) !=
            tolower((unsigned char)search[i]))
            return 0;

        i++;
    }

    return 1;
}

void find_contact(Contact *head)
{
    char search[MAX_NAME];
    Contact *temp;
    int found = 0;

    if (head == NULL)
    {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name or starting letter: ");
    read_line(search, MAX_NAME);

    if (strlen(search) == 0)
    {
        printf("Search text cannot be empty.\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        if (starts_with_ignore_case(temp->name, search))
        {
            print_one_contact(temp);
            found = 1;
        }

        temp = temp->next;
    }

    if (!found)
        printf("No matching contacts found.\n");
}