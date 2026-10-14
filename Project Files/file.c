#include "phonebook.h"

#define DATA_FILE "phonebook.dat"

void save_contacts(Contact *head)
{
    FILE *fp;
    Contact *temp = head;

    fp = fopen(DATA_FILE, "wb");

    if (fp == NULL)
    {
        perror("phonebook.dat");
        return;
    }

    while (temp != NULL)
    {
        fwrite(temp->name, sizeof(temp->name), 1, fp);
        fwrite(&temp->phone_count, sizeof(temp->phone_count), 1, fp);
        fwrite(temp->phone, sizeof(temp->phone), 1, fp);
        fwrite(temp->email, sizeof(temp->email), 1, fp);
        fwrite(temp->address, sizeof(temp->address), 1, fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("All contacts saved successfully.\n");
}

void sync_file(Contact **head)
{
    FILE *fp;
    Contact *new_contact;
    Contact *temp;
    int phone_count;

    fp = fopen(DATA_FILE, "rb");

    if (fp == NULL)
        return;

    while (1)
    {
        new_contact = create_node();

        if (new_contact == NULL)
            break;

        if (fread(new_contact->name, sizeof(new_contact->name), 1, fp) != 1)
        {
            free(new_contact);
            break;
        }

        if (fread(&phone_count, sizeof(phone_count), 1, fp) != 1)
        {
            free(new_contact);
            break;
        }

        if (fread(new_contact->phone, sizeof(new_contact->phone), 1, fp) != 1)
        {
            free(new_contact);
            break;
        }

        if (fread(new_contact->email, sizeof(new_contact->email), 1, fp) != 1)
        {
            free(new_contact);
            break;
        }

        if (fread(new_contact->address, sizeof(new_contact->address), 1, fp) != 1)
        {
            free(new_contact);
            break;
        }

        new_contact->phone_count = phone_count;
        new_contact->next = NULL;

        if (*head == NULL)
        {
            *head = new_contact;
        }
        else
        {
            temp = *head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = new_contact;
        }
    }

    fclose(fp);
}
