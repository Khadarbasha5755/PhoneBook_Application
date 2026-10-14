#include "phonebook.h"

void read_line(char *str, int size)
{
    if (fgets(str, size, stdin) != NULL)
    {
        str[strcspn(str, "\n")] = '\0';
    }
}

void clear_input_buffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

Contact *find_node(Contact *head, const char *name)
{
    Contact *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

int contact_exists(Contact *head, const char *name)
{
    if (find_node(head, name) != NULL)
        return 1;

    return 0;
}

int number_exists(Contact *contact, const char *number)
{
    int i;

    if (contact == NULL)
        return 0;

    for (i = 0; i < contact->phone_count; i++)
    {
        if (strcmp(contact->phone[i], number) == 0)
            return 1;
    }

    return 0;
}