#include <stdio.h>
#include <stdlib.h>
#include "Shared/Menu.h"
#include "Contact/Contact.h"
#include "Contact/ContactServices.h"

int main(){
    int counterId = 0;
    int totalContacts = 0;
    Contact *contacts = malloc(1 * sizeof(Contact));
    int menuOption = 0;

    do{
        showMenu();
        scanf("%d", &menuOption);
        while (getchar() != '\n');


        switch (menuOption) {
            case 1: showAllContacts(contacts, totalContacts); break;
            case 2: searchContact(); break;
            case 3: registerContact(&contacts, &totalContacts, &counterId); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 0: printf("Loggin out...\n"); break;
            default: printf("Invalid Option.\n");
        }

    } while (menuOption != 0);
};