# My-First
Phone Directory Application - README
Overview:   This is a simple command-line application to manage a phone directory using a doubly linked list. The program allows users to:

Add a contact (name and phone number),
Display all contacts,
Delete a contact by name,
Search for a contact by name and
Exit the program.

The phone directory is managed through a doubly linked list, where each contact is represented by a node containing a name, phone number, and pointers to the previous and next nodes.
A doubly linked list is a type of linked list where each node contains three parts: data, a pointer to the next node, and a pointer to the previous node. This allows traversal in both forward and backward directions. Unlike a singly linked list, which only has a pointer to the next node, a doubly linked list provides greater flexibility in navigating and modifying the list. It supports efficient insertion and deletion at both ends. Common operations include insertion, deletion, and searching for elements in the list.

Features:

Add Contact: Allows users to add a new contact with a name and phone number.

Display Contacts: Displays all contacts in the directory.

Delete Contact: Deletes a contact by name from the directory.

Search Contact: Searches for a contact by name.

Exit: Exits the program and frees allocated memory.


Requirements:

C Compiler: The program is written in C and requires a C compiler to compile and run.   For example: GCC, Clang, or MSVC.
   
Operating System: The program can run on any operating system with a compatible C compiler (Windows, Linux, macOS).


Limitations:
This program doesn't handle invalid input types (e.g., entering non-numeric characters for phone numbers).There is no limit to the number of contacts, other than the system's available memory.Contacts are stored temporarily in memory; the program does not save the data to a file.


License:  
Feel free to modify and improve it for your own use.
