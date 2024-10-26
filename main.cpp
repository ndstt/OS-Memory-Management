#include <iostream>

// Global variables
int global_var1 = 1;
int global_var2 = 2;
int global_var3 = 3;

// First function to demonstrate stack memory
void print_addresses(void (*func)(), const char* func_name, int* local_var) {
    std::cout << func_name << " - Function address: " << (void*)func << "\n";
    std::cout << "Local variable address: " << local_var << "\n";
    std::cout << "Global variable 1 address: " << &global_var1 << "\n";
    std::cout << "Global variable 2 address: " << &global_var2 << "\n";
    std::cout << "Global variable 3 address: " << &global_var3 << "\n\n";
}

// Functions to demonstrate
void function1() {
    int local_var1 = 10;
    print_addresses(function1, "function1", &local_var1);
}

void function2() {
    int local_var2 = 20;
    print_addresses(function2, "function2", &local_var2);
    function1(); // calling function1 within function2
}

void function3() {
    int local_var3 = 30;
    print_addresses(function3, "function3", &local_var3);
    function2(); // calling function2 within function3
}

void demonstrate_malloc() {
    // Allocate 3 blocks of memory
    int* heap_var1 = (int*)malloc(sizeof(int));
    int* heap_var2 = (int*)malloc(sizeof(int));
    int* heap_var3 = (int*)malloc(sizeof(int));

    // Assign values
    *heap_var1 = 100;
    *heap_var2 = 200;
    *heap_var3 = 300;

    // Print heap memory addresses
    std::cout << "Heap variable 1 address: " << heap_var1 << " with value: " << *heap_var1 << "\n";
    std::cout << "Heap variable 2 address: " << heap_var2 << " with value: " << *heap_var2 << "\n";
    std::cout << "Heap variable 3 address: " << heap_var3 << " with value: " << *heap_var3 << "\n";

    // Free the allocated memory
    free(heap_var1);
    free(heap_var2);
    free(heap_var3);
}

int main() {
    // Demonstrate function call stack
    function3(); // Starts the chain of function calls

    // Demonstrate dynamic memory allocation
    demonstrate_malloc();
    int main_var = 40;
    std::cout << "\nMain - Local variable address: " << &main_var << "\n";

    return 0;
}