# 🧮 Arbitrary Precision Calculator (APC)

## 📌 Overview

An **Arbitrary Precision Calculator** developed in **C using Doubly Linked Lists** to perform arithmetic operations on large integers beyond the limits of standard data types.

Each digit is stored in a separate node, allowing calculations without integer overflow caused by fixed-size numeric types.

## 🚀 Features

- Addition of large integers
- Subtraction with negative result handling
- Multiplication using digit-by-digit calculation
- Integer division
- Doubly Linked List implementation
- Dynamic memory allocation
- Input validation
- Menu-driven interface

## 🛠️ Technologies Used

- **Language:** C
- **Data Structure:** Doubly Linked List
- **Compiler:** GCC
- **Build Tool:** Makefile

## 📂 Project Structure

```text
Arbitrary-Precision-Calculator/
├── main.c
├── apc.c
├── apc.h
├── common.h
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── Makefile
└── README.md
```

## ⚙️ How It Works

The calculator stores each digit of an integer in a separate doubly linked list node.

For example, `12345` is represented as:

```text
NULL <- 1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL
```

Arithmetic operations are performed digit by digit using carry, borrow, and traditional multiplication and division algorithms.

## 💻 Compilation and Execution

**Compile using GCC:**

```bash
gcc main.c apc.c addition.c subtraction.c multiplication.c division.c -o apc
```

**Run:**

```bash
./apc
```

Alternatively, build using:

```bash
make
```

## 🖥️ Sample Output

```text
Enter first operand: 12345
Enter second operand: 67890

Choose operation:
1. Addition
2. Subtraction
3. Multiplication
4. Division

Enter your choice: 1

Result: NULL->8->0->2->3->5->NULL
```

**Result:** 80235

## ⚠️ Limitations

- Supports non-negative integer inputs only.
- Division returns an integer quotient.
- Input is currently limited to 999 characters per operand.
- Results are displayed in linked-list format.

## 🎯 Concepts Used

Doubly Linked Lists, Pointers, Dynamic Memory Allocation, Data Structures, Arithmetic Algorithms, and Modular Programming.

## 👨‍💻 Author

**Sudeep Shetty**

Developed as a Data Structures project using C programming.
