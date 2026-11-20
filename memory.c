
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int global_var = 150;
int bss_var;

int main() {
    int local_var = 30;
    static int local_static = 20;

    int *heap_var = malloc(sizeof(int));
    *heap_var = 50;

    printf("===== MEMORY LAYOUT =====\n");

    printf("Global Initialized (Data): %p\n", (void *)&global_var);
    printf("Global Uninitialized (BSS): %p\n", (void *)&bss_var);
    printf("Local Variable (Stack): %p\n", (void *)&local_var);
    printf("Static Variable (Data): %p\n", (void *)&local_static);
    printf("Dynamic Variable (Heap): %p\n", (void *)heap_var);

    printf("\n===== ADDRESS COMPARISON =====\n");

    uintptr_t stack = (uintptr_t)&local_var;
    uintptr_t heap = (uintptr_t)heap_var;

    printf("Stack Address: %p\n", (void *)&local_var);
    printf("Heap Address: %p\n", (void *)heap_var);

    printf("Stack-Heap Address Difference: %llu bytes\n",
        (unsigned long long)(stack > heap ? stack - heap : heap - stack));

    free(heap_var);
    return 0;
}
