#ifndef CONTACT_SERVICE_H
#define CONTACT_SERVICE_H

void showAllContacts(Contact *contacts, int totalContacts);
void searchContactByName(Contact *contacts, int totalContacts);
void registerContact(Contact **contacts, int *totalContacts, int *counterId);
void editContact();
void deleteContact();

#endif