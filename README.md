Municipal Financial Management System (MFMS) Project

Group Members

1. Viren Halweendo – 225089521
2. Jesse Museta - 224050036
3. peter kamati 224080806
4. **[Full Name] – [Student Number]**
5. **[Full Name] – [Student Number]**
6. **[Full Name] – [Student Number]**
7. **[Full Name] – [Student Number]**


## 1. Project Description

The Municipal Financial Management System (MFMS) is a menu-driven C application designed to simulate the management of important municipal financial information.

The system allows users to manage employees, departmental budgets, suppliers and municipal assets. It also provides reports and calculations to help users view and analyse stored information.

The system was developed using the C programming language and demonstrates the use of arrays, structures, functions, loops, conditions, input validation and string processing.


## 2. System Features

### Employee Management

* Add employees
* Display employee information
* Search for employees
* Calculate total salary
* Prevent duplicate employee IDs

### Budget Management

* Add departmental budgets
* Display budgets
* Search for budgets
* Calculate remaining budget
* Identify departments that exceed their budget
* Prevent duplicate budget IDs

### Supplier Management

* Add suppliers
* Display supplier information
* Search for suppliers
* Compare suppliers
* Store supplier contact information
* Prevent duplicate supplier IDs

### Asset Management

* Add municipal assets
* Display asset information
* Search for assets
* Store asset value, department and condition
* Prevent duplicate asset IDs

### Reports

The system provides reports for:

* Employees
* Budgets
* Suppliers
* Assets

The reports provide summary information such as employee salary statistics, total budgets, expenditure and remaining budgets.


## 3. Technologies Used

* **Programming Language:** C
* **Standard:** C99
* **Compiler:** GCC
* **IDE:** Visual Studio Code
* **Version Control:** Git
* **Repository:** GitHub
* **Operating System:** Windows


## 4. Project Structure

```text
Municipality-Financial-Management-System-SIMULATION/
│
├── main.c
├── employees.c
├── employees.h
├── budgets.c
├── budgets.h
├── suppliers.c
├── suppliers.h
├── assets.c
├── assets.h
├── reports.c
├── reports.h
├── input.c
├── input.h
└── README.md
```

### File Descriptions

| File          | Description                                  |
| ------------- | -------------------------------------------- |
| `main.c`      | Contains the main program and main menu      |
| `employees.c` | Employee management functions                |
| `employees.h` | Employee structure and function declarations |
| `budgets.c`   | Budget management functions                  |
| `budgets.h`   | Budget structure and function declarations   |
| `suppliers.c` | Supplier management functions                |
| `suppliers.h` | Supplier structure and function declarations |
| `assets.c`    | Asset management functions                   |
| `assets.h`    | Asset structure and function declarations    |
| `reports.c`   | Report generation functions                  |
| `reports.h`   | Report function declarations                 |
| `input.c`     | Input validation functions                   |
| `input.h`     | Input validation declarations                |


## 5. How to Compile the Program

Open the project folder in Visual Studio Code and open the terminal.

Compile the program using:

```powershell
gcc main.c employees.c budgets.c suppliers.c assets.c reports.c input.c -o mfms
```

If the compilation is successful, an executable named `mfms.exe` will be created.


## 6. How to Run the Program

In the VS Code terminal, run:

```powershell
.\mfms
```

The main menu will then be displayed.


## 7. Main Menu

The system provides the following main menu options:

```text
====================================
 MUNICIPAL FINANCIAL MANAGEMENT SYSTEM
====================================
1. Employee Management
2. Budget Management
3. Supplier Management
4. Asset Management
5. Reports
0. Exit
```

Users select an option to access the required management module.


## 8. Input Validation

The system includes input validation to reduce incorrect data entry.

Validation includes:

* Checking that numeric values are entered correctly
* Preventing empty text fields
* Preventing duplicate IDs
* Validating employee IDs
* Validating budget IDs
* Validating supplier IDs
* Validating asset IDs
* Checking numeric salary, budget and asset values

The input validation functions are stored separately in `input.c` and `input.h`.


## 9. C Concepts Used

The project demonstrates the following C programming concepts:

* Structures
* Arrays
* Functions
* Function parameters
* Return values
* Loops
* Conditional statements
* Switch statements
* Input validation
* Modular programming
* Header files
* External variables
* String processing


## 10. String Functions Used

The project uses the required C string functions:

### `strlen()`

Used to check the length of user-entered text and prevent empty input.

### `strcmp()`

Used when comparing supplier information, such as supplier locations.

### `strcpy()`

Used to copy strings from one character array to another.

### `strcat()`

Used to join strings together, such as combining supplier email and telephone information.


## 11. Modular Design

The system is divided into separate modules instead of placing all functionality inside `main.c`.

The main modules are:

* Employee Management
* Budget Management
* Supplier Management
* Asset Management
* Reports
* Input Validation

Each module has its own `.c` and `.h` files where appropriate. This makes the program easier to understand, maintain and develop.


## 12. GitHub Development

Git and GitHub were used to manage the development history of the project.

The project was developed progressively through separate commits for major features and improvements.

Examples of development stages include:

* Initial project setup
* Main menu
* Employee management
* Budget management
* Supplier management
* Asset management
* Reports
* Input validation
* String processing
* Duplicate ID validation
* Numeric input validation
* Modularisation of the system

The complete development history can be viewed through the GitHub commit history.


## 13. GitHub Repository

**Repository:** Abary06/Municipality-Financial-Management-System-SIMULATION: Clear development history of the C code.



## 14. Submitted By

**Submitted by: 225089521 – Viren Halweendo**
