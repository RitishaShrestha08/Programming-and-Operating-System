# Programming-and-Operating-System
# Memory Layout Program – C Programming with Docker

## 1. Project Overview

This project demonstrates the memory layout of a C program by identifying different memory segments: Data, BSS, Stack, and Heap.

The program prints the memory addresses of variables using the `%p` format specifier and compares the Stack and Heap addresses.

The project is compiled and executed inside a Docker container.

## 2. Objectives

- Understand the memory layout of a C program.
- Identify Data, BSS, Stack, and Heap segments.
- Print variable memory addresses using `%p`.
- Compare Stack and Heap memory addresses.
- Understand dynamic memory allocation using `malloc()`.
- Compile and execute a C program using Docker.
- Automate program execution using GitHub Actions.

## 3. Technologies Used

- **C Programming:** Writing the memory layout program.
- **GCC Compiler:** Compiling the C source code.
- **Docker:** Building and running the application inside a container.
- **GitHub:** Storing and managing project files.
- **GitHub Actions:** Automating Docker build and execution.

## 4. Memory Segments

| Memory Segment | Description |
|---|---|
| Data Segment | Stores initialized global and static variables. |
| BSS Segment | Stores uninitialized global and static variables. |
| Stack Segment | Stores local variables and function call information. |
| Heap Segment | Stores dynamically allocated memory. |

## 5. Project Structure

```text
Programming-and-Operating-System/
│
├── memory.c
├── Dockerfile
├── README.md
│
└── .github/
    └── workflows/
        └── docker.yml
```

## 6. How to Run the Project Using Docker

### Step 1: Build the Docker Image

```bash
docker build -t memory-layout .
```

### Step 2: Run the Docker Container

```bash
docker run --rm memory-layout
```

### Step 3: View the Output

The program displays:
- Initialized global variable address.
- Uninitialized global variable address.
- Local variable address.
- Static variable address.
- Dynamically allocated variable address.
- Stack and Heap address comparison.

## 7. GitHub Actions Automation

GitHub Actions is used to automate the execution of the program.

Whenever changes are pushed to the `main` branch, the workflow:

1. Checks out the repository.
2. Builds the Docker image.
3. Runs the Docker container.
4. Displays the program output in the Actions logs.

The workflow can also be executed manually from the GitHub Actions tab.

## 8. Expected Output

```text
===== MEMORY LAYOUT =====

Global Initialized (Data): 0x...
Global Uninitialized (BSS): 0x...
Local Variable (Stack): 0x...
Static Variable (Data): 0x...
Dynamic Variable (Heap): 0x...

===== ADDRESS COMPARISON =====

Stack Address: 0x...
Heap Address: 0x...
Stack-Heap Address Difference: ... bytes
```

*Note: Actual memory addresses may vary between executions due to Address Space Layout Randomization (ASLR).*

## 9. Conclusion

This project demonstrates how different variables are stored in the memory segments of a C program. It provides practical experience with memory addresses, dynamic memory allocation, GCC compilation, Docker containerization, and automated execution through GitHub Actions.

---

**Project:** Memory Layout Program  
**Language:** C  
**Platform:** Docker  
**Repository:** Programming-and-Operating-System
