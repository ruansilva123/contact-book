#include <stdio.h>
#include <stdlib.h>
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

void searchContact(){
    printf("searth contact");
}

void registerContact(Contact **contacts, int *totalContacts, int *counterId){
    if (*totalContacts != 0) {
        *contacts = realloc(*contacts, ((*totalContacts) + 1) * sizeof(Contact));
    }

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

void editContact(){
    printf("edit");
}

void deleteContact(){
    printf("delete");
}