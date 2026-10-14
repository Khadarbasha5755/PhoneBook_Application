# 📱 PhoneBook Application in C

A menu-driven contact management application developed using the C programming language. The application allows users to create, display, search, edit, and delete contacts. It uses a linked list for dynamic contact management and file handling to preserve contact information between program executions.

## 🎯 Project Overview

The PhoneBook Application is designed to simplify contact management through a command-line interface. Users can maintain contact details and perform common operations through a menu-driven system.

The project demonstrates the practical use of C programming concepts, including structures, pointers, linked lists, dynamic memory allocation, string manipulation, file handling, and modular programming.

Contact information is stored in a file, allowing saved data to be loaded when the application starts again.

## 🎯 Objectives

* Develop a contact management application using C.
* Implement a linked list to manage contacts dynamically.
* Provide operations for creating, viewing, searching, editing, and deleting contacts.
* Use file handling to maintain contact information between executions.
* Organize the program into multiple source files for better maintainability.
* Use functions and pointers to improve code reusability.
* Simplify compilation through a Makefile.

## ✨ Key Features

* **Create Contacts:** Add new contacts with the required details.
* **Display Contacts:** View the available contact information.
* **Search Contacts:** Find contacts using a name or partial name.
* **Case-Insensitive Search:** Search without distinguishing uppercase and lowercase letters, if supported by the implementation.
* **Multiple Phone Numbers:** Maintain multiple phone numbers for a contact, according to the implemented limit.
* **Edit Contacts:** Modify existing contact details.
* **Delete Contacts:** Remove unwanted contacts.
* **Persistent Storage:** Save and reload contact information using file handling.
* **Modular Design:** Separate program functionality into multiple source files.
* **Automated Compilation:** Compile the application using a Makefile.

## 🛠️ Technologies Used

| Technology                   | Purpose                                          |
| ---------------------------- | ------------------------------------------------ |
| C Programming                | Application development                          |
| GCC / MinGW GCC              | C compilation                                    |
| Singly Linked List           | Dynamic contact management                       |
| Structures and Pointers      | Organizing and accessing contact data            |
| Dynamic Memory Allocation    | Allocating memory for contact nodes              |
| File Handling                | Saving and retrieving contact information        |
| GNU Make                     | Automating compilation                           |
| Linux / Windows              | Supported environments, subject to compatibility |
| VS Code / Vim / Code::Blocks | Code editing and development                     |


## 📋 Application Menu

When the application starts, the following menu is displayed:

```text
------------------ MENU ---------------------------
c/C : Create a new contact
p/P : Print all contacts
d/D : Delete contact
f/F : Find contact
e/E : Edit a contact
s/S : Save the contacts to a file
q/Q : Quit the application
---------------------------------------------------
Enter your choice:
```

### Menu Options

* **Create Contact (`c/C`):** Add a new contact to the phonebook.
* **Print Contacts (`p/P`):** Display all available contacts.
* **Delete Contact (`d/D`):** Delete an existing contact.
* **Find Contact (`f/F`):** Search for a contact using the supported search criteria.
* **Edit Contact (`e/E`):** Modify the details of an existing contact.
* **Save Contacts (`s/S`):** Save contact information to a file for future use.
* **Quit Application (`q/Q`):** Exit the application.

**Note:** Both uppercase and lowercase characters are accepted for menu choices.



## ⚙️ How the System Works

The application follows a menu-driven execution flow.

1. **Initialization:** The program initializes its required data structures.
2. **Load Contacts:** Previously saved contact information is loaded from the data file, if available.
3. **Display Menu:** The user selects an operation.
4. **Process the Request:** The application performs the selected operation.
5. **Manage Contacts:** Contact information is accessed and modified using linked-list operations.
6. **Save Changes:** Updated contact information is saved according to the application's file-handling logic.
7. **Repeat or Exit:** The user can perform additional operations or exit the application.


## 💻 C Programming Concepts Demonstrated

| Concept                   | Description                                              |
| ------------------------- | -------------------------------------------------------- |
| Structures (`struct`)     | Group related contact information into one data type.    |
| Pointers                  | Access memory locations and link contact nodes.          |
| Singly Linked List        | Store and traverse contacts dynamically.                 |
| Dynamic Memory Allocation | Allocate and release memory for contact nodes.           |
| Functions                 | Divide operations into reusable functions.               |
| Modular Programming       | Organize functionality across multiple source files.     |
| String Handling           | Process and compare contact names and other text.        |
| File Handling             | Store and retrieve contact information.                  |
| Conditional Statements    | Execute operations based on user selections.             |
| Loops                     | Traverse the linked list and repeat the menu.            |
| Header Files              | Share declarations and definitions across source files.  |
| Makefile                  | Automate the compilation process.                        |
| Error Handling            | Manage invalid input and file errors, where implemented. |

## 🚀 How to Run the Project

### Prerequisites

Install a compatible C compiler, such as GCC or MinGW GCC.

GNU Make is also required if you want to build the project using the supplied Makefile.

### Option 1: Compile on Linux

**Step 1: Open the terminal and navigate to the project directory.**

**Step 2: Compile the application.**

```bash
make
```

**Step 3: Run the application.**

```bash
./phonebook
```

**Step 4: Clean generated build files when required.**

```bash
make clean
```

Check the `clean` rule before running it to ensure that it does not delete your saved contact data.

### Option 2: Compile on Windows Using GCC

Install MinGW GCC or GCC through MSYS2 and open a suitable terminal.

Navigate to the project directory and compile the source files:

```bash
gcc main.c create.c print.c find.c edit.c delete.c file.c helper.c -o phonebook.exe
```

Run the application in Command Prompt:

```cmd
phonebook.exe
```

Or in PowerShell:

```powershell
.\phonebook.exe
```

**Important:** Adjust the filenames in the compilation command to match your project. If your code uses platform-specific functions, additional changes may be necessary for Windows compatibility.

### Option 3: Use a C IDE

You can also use an IDE such as Code::Blocks, Dev-C++, or VS Code with a configured C compiler.

1. Open the project folder.
2. Add all required C source files to the build.
3. Configure the compiler.
4. Build the application.
5. Run the generated executable.

## 📂 Project Structure

```text
PhoneBook_Application/
│
├── 📁 Project Files/
│   ├── Makefile
│   ├── create.c
│   ├── delete.c
│   ├── edit.c
│   ├── file.c
│   ├── find.c
│   ├── helper.c
│   ├── main.c
│   ├── phonebook.dat
│   ├── phonebook.h
│   └── print.c
│
└── README.md
```

**Note:** The file names above should match the actual repository. The data file is generated at runtime if the implementation creates it automatically.

## 🔮 Future Enhancements

The application can be extended with the following features:

* Sort contacts alphabetically.
* Search contacts by phone number or email address.
* Add validation for phone numbers and email addresses.
* Import and export contacts in CSV format.
* Implement backup and restore functionality.
* Improve error handling and data recovery.
* Add contact groups and a favorites feature.
* Develop a graphical user interface.
* Improve portability across operating systems and compilers.

## 📚 Learning Outcomes

This project provides practical experience in:

* Applying C programming to a real-world application.
* Understanding structures, pointers, and linked lists.
* Managing memory dynamically.
* Working with files for persistent storage.
* Implementing string manipulation and searching.
* Designing modular programs using multiple source files.
* Creating and using a Makefile.
* Compiling, debugging, and testing C programs.
* Understanding software organization and maintainability.
* Documenting a project for GitHub and technical review.

## 👨‍💻 Author

**Shaik Khadar Basha**

GitHub: [Khadarbasha5755](https://github.com/Khadarbasha5755)

---

*Developed as part of a C Mini Project.*
