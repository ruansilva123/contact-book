#ifndef CONTACT_H
#define CONTACT_H

typedef struct {
    int id;
    char name[100];
    char phone[16];
    int isPersonal;
} Contact;

#endif