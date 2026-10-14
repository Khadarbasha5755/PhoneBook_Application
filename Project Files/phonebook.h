#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_PHONE 20
#define MAX_EMAIL 60
#define MAX_ADDRESS 100
#define MAX_NUMBERS 5

typedef enum
{
    NO = 0,
    YES = 1
} Choice;

typedef struct Contact
{
    char name[MAX_NAME];
    char phone[MAX_NUMBERS][MAX_PHONE];
    int phone_count;
    char email[MAX_EMAIL];
    char address[MAX_ADDRESS];

    struct Contact *next;
} Contact;

/* contact operations */
void create_contact(Contact **head);
void print_contacts(Contact *head);
void delete_contact(Contact **head);
void find_contact(Contact *head);
void edit_contact(Contact *head);

/* file operations */
void save_contacts(Contact *head);
void sync_file(Contact **head);

/* helper functions */
Contact *create_node(void);
void read_line(char *str, int size);
int contact_exists(Contact *head, const char *name);
int number_exists(Contact *contact, const char *number);
Contact *find_node(Contact *head, const char *name);
void print_one_contact(Contact *contact);
void clear_input_buffer(void);

#endif
