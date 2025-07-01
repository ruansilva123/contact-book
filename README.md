# CONTACT BOOK

The project was created in C for the final assignment of the **Algorithms class at UDESC**. The goal of the project is to develop a contact book that allows users to manage all their contacts through a CLI interface.

## :dart: Features developed

- List all contacts
- Search a contact by name
- Register a new contact
- Edit a contact
- Delete a contact

## :bar_chart: About data savings

The project uses the **stdlib.h** library to create a dynamic array, allowing the user to save as many contacts as they want. You can see more in [ContactServices.c](https://github.com/ruansilva123/contact-book/blob/main/Contact/ContactServices.c).

## :gear: How execute this project

1. Clone this project

       https://github.com/ruansilva123/contact-book.git

2. Open the projec in your machine

        cd contact-book

3. Run the below command to compile

        gcc main.c Shared/Menu.c Contact/ContactServices.c -o contact_program

4. Run the executable

        ./contact_program
