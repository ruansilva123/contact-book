#include <stdio.h>
#include "Shared/Menu.h"
#include "Contact/ContactServices.h"

typedef struct {
    int id;
    char name[100];
    char phone[11];
    int isPersonal;
} Contact;

int main(){
    int menuOption = 0;

    do{
        showMenu();
        scanf("%d", &menuOption);

        switch (menuOption) {
            case 1: showAllContacts(); break;
            case 2: searchContact(); break;
            case 3: registerContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 0: printf("Loggin out...\n"); break;
            default: printf("Invalid Option.\n");
        }

    }while (menuOption != 0);
};