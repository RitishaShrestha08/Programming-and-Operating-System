# Programming and Operating System Practicals

## Overview

This repository contains practical programs developed as part of the Programming and Operating System course. The project demonstrates important operating system concepts using the C programming language.

The programs are compiled and executed using Docker, making them easier to run in a consistent environment. GitHub Actions is also used to automate the building and execution of the programs.

## Objectives

- Understand memory management and memory layout in C.
- Identify different memory segments used by a program.
- Understand process IDs and parent process IDs.
- Display basic process information using system calls.
- Learn how to compile and execute C programs using Docker.
- Automate program execution using GitHub Actions.

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Containerization:** Docker
- **Version Control:** Git and GitHub
- **Automation:** GitHub Actions

---

# Practical 1: Memory Layout Program

## Objective

To observe where different variables are stored in memory and understand the memory layout of a C program.

## Concepts Covered

| Memory Segment | Description |
|---|---|
| Data Segment | Stores initialized global and static variables. |
| BSS Segment | Stores uninitialized global and static variables. |
| Stack Segment | Stores local variables and function-related data. |
| Heap Segment | Stores dynamically allocated memory. |

## Program Features

The program:

1. Declares a global initialized variable.
2. Declares a global uninitialized variable.
3. Creates a local variable inside `main()`.
4. Creates a static local variable.
5. Dynamically allocates memory using `malloc()`.
6. Displays the memory addresses using `%p`.
7. Calculates the difference between stack and heap addresses.
8. Releases dynamically allocated memory using `free()`.

## Expected Output

The output displays the memory addresses of the variables in different memory segments.

**Note:** Memory addresses may change every time the program executes because of operating system memory management and Address Space Layout Randomization (ASLR).

---

# Practical 2: Process Information Program

## Objective

To retrieve and display basic information about a running process using system calls in C.

## Concepts Covered

| Concept | Description |
|---|---|
| PID | Process ID, which uniquely identifies a running process. |
| PPID | Parent Process ID of the current process. |
| `getpid()` | Returns the current process ID. |
| `getppid()` | Returns the parent process ID. |
| `time()` | Gets the current calendar time. |
| `localtime()` | Converts time into local date and time information. |
| `asctime()` | Converts time information into a readable string. |

## Program Features

The program:

1. Retrieves its own process ID using `getpid()`.
2. Retrieves its parent process ID using `getppid()`.
3. Gets the current system time using `time()`.
4. Converts the time using `localtime()`.
5. Displays the process information.
6. Prints `/proc/self/exe` as the executable path reference.

**Note:** The current program prints `/proc/self/exe` as a text string; it does not resolve the actual executable path.

## Expected Output

```text
=== Process Information ===
My Process ID (PID): 1
Parent Process ID: 0
Current Time: Fri Nov 20 14:00:00 2026
Executable Path: /proc/self/exe
```

**Note:** The PID, PPID, and date/time shown above are examples. Actual values will vary depending on the execution environment.

---

# Project Structure

```text
Programming-and-Operating-System/
│
├── memory.c
├── procinfo.c
├── Dockerfile
├── README.md
│
└── .github/
    └── workflows/
        └── docker.yml
```

---

# Running the Programs Using Docker

## Step 1: Build the Docker Image

Make sure Docker Desktop is running, then open a terminal in the project directory.

```bash
docker build -t os-practicals .
```

## Step 2: Run the Memory Layout Program

```bash
docker run --rm os-practicals ./memory
```

## Step 3: Run the Process Information Program

```bash
docker run --rm os-practicals ./procinfo
```

Both programs are compiled into the same Docker image but executed separately.

---

# Dockerfile

The Dockerfile uses the GCC image to compile both C programs.

```dockerfile
FROM gcc:latest

WORKDIR /app

COPY memory.c procinfo.c ./

RUN gcc memory.c -o memory
RUN gcc procinfo.c -o procinfo

CMD ["./memory"]
```

---

# GitHub Actions Automation

GitHub Actions is used to automatically build the Docker image and execute both practical programs.

The workflow file is located at:

```text
.github/workflows/docker.yml
```

## Workflow Steps

1. Checks out the GitHub repository.
2. Builds the Docker image.
3. Runs the Memory Layout program.
4. Runs the Process Information program.

The workflow runs automatically whenever changes are pushed to the `main` branch. It can also be started manually using the GitHub Actions interface.

## Checking Workflow Results

1. Open the GitHub repository.
2. Click the **Actions** tab.
3. Select **Run OS Practical Programs**.
4. Check the workflow execution results.

A green check mark indicates that the workflow completed successfully.

---

# Learning Outcomes

After completing these practicals, the following concepts were understood:

- Different memory segments in a C program.
- Stack and heap memory allocation.
- Global, static, and local variables.
- Dynamic memory allocation using `malloc()` and `free()`.
- Process identification using PID and PPID.
- Basic process-related system calls.
- Compiling and executing C programs using GCC.
- Containerizing applications using Docker.
- Automating builds and program execution using GitHub Actions.

---

# Conclusion

These practical programs helped demonstrate important concepts of programming and operating systems, particularly memory organization and process management.

Docker provided a consistent environment for compiling and running the programs, while GitHub Actions automated the build and execution process. This project provided practical experience with C programming, operating system concepts, containerization, and basic CI/CD automation.

---

**Repository:** [Programming-and-Operating-System](https://github.com/RitishaShrestha08/Programming-and-Operating-System)
