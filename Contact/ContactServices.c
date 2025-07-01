#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contact.h"

void showAllContacts(Contact *contacts, int totalContacts){
    if (totalContacts == 0) {
        printf("You no have contacts.");
        return;
    }

    for (int i = 0; i < totalContacts; i++) {
        printf("ID: %d | Name: %s | Phone: %s | Type: %s",
            contacts[i].id,
            contacts[i].name,
            contacts[i].phone,
            contacts[i].isPersonal ? "Personal" : "Work"
        );
    }
}

void searchContactByName(Contact *contacts, int totalContacts){
    char name[100];

    printf("Write the name of contact:\n");
    fgets(name, sizeof(name), stdin);
    
    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("ID: %d | Name: %s | Phone: %s | Type: %s",
                contacts[i].id,
                contacts[i].name,
                contacts[i].phone,
                contacts[i].isPersonal ? "Personal" : "Work"
            );
            return;
        }
    }

    printf("Contact not found.");
}

void registerContact(Contact **contacts, int *totalContacts, int *counterId){
    *contacts = realloc(*contacts, ((*totalContacts) + 1) * sizeof(Contact));
    
    (*totalContacts)++;
    (*contacts)[*totalContacts - 1].id = ++(*counterId);

    printf("Write the number: (Ex: +55(47)999999999)\n");
    fgets((*contacts)[*totalContacts - 1].phone, sizeof((*contacts)[*totalContacts - 1].phone), stdin);

    printf("Write the contact name:\n");
    fgets((*contacts)[*totalContacts - 1].name, sizeof((*contacts)[*totalContacts - 1].name), stdin);

    int typeNumberOption = 1;

    do{
        printf("Select the type of number:\n");
        printf("[1] - Personal.\n");
        printf("[2] - Work.");
        scanf("%d", &typeNumberOption);

        switch (typeNumberOption) {
            case 1: (*contacts)[*totalContacts - 1].isPersonal = 1; break;
            case 2: (*contacts)[*totalContacts - 1].isPersonal = 0; break;
            default: printf("Invalid Option.\n");
        }

    } while (typeNumberOption != 1 && typeNumberOption != 2);
}

void editContact(Contact *contacts, int totalContacts){
    int id;

    printf("Write de ID of the contact to edit:\n");
    scanf("%d", &id);
    while (getchar() != '\n');

    for (int i; i < totalContacts; i++) {
        if (id == contacts[i].id) {
            printf("Write the number: (Ex: +55(47)999999999)\n");
            fgets(contacts[i].phone, sizeof(contacts[i].phone), stdin);

            printf("Write the contact name:\n");
            fgets(contacts[i].name, sizeof(contacts[i].name), stdin);

            int typeNumberOption = 1;

            do{
                printf("Select the type of number:\n");
                printf("[1] - Personal.\n");
                printf("[2] - Work.");
                scanf("%d", &typeNumberOption);

                switch (typeNumberOption) {
                    case 1: contacts[i].isPersonal = 1; break;
                    case 2: contacts[i].isPersonal = 0; break;
                    default: printf("Invalid Option.\n");
                }

            } while (typeNumberOption != 1 && typeNumberOption != 2);

            return;
        }
    }

    printf("Contact ID not found.");
}

void deleteContact(Contact **contacts, int *totalContacts){
    if (*totalContacts == 0) {
        printf("No contacts to delete.");
        return;
    }

    int contactId;

    printf("Write the ID of the contact to be deleted:\n");
    scanf("%d", &contactId);

    for (int i = 0; i < *totalContacts; i++) {
        if (contactId == (*contacts)[i].id) {
            for (int j = i; j < *totalContacts - 1; j++) {
                (*contacts)[j] = (*contacts)[j + 1];
            }

            *contacts = realloc(*contacts, (*totalContacts - 1) * sizeof(Contact));

            (*totalContacts)--;
            return;
        }
    }

    printf("Contact ID not found.");
}