#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void increment(int x);
void increment_with_pointers(int *x);
void twice_as_big (int array[], int size);
void printing_the_string(char *s1);
void one_dimentional(int *A);
void two_dimentional(int *A[3]);
void three_dimentional(int *A[2][2]);
void print_hello_world();
int* add(int* a, int* b);
void say_hi(char *name);
int addition(int a, int b);
int compare(const void* a, const void* b);
void A_function();
void B_function(void (*ptr)());

int main(){
    // asigning pointers and working with pointers

    int a = 10;
    int *p = &a;
    printf("%d\n", *p); // *p = 10
    printf("%d\n", a); // a = 10
    *p = 12;
    printf("%d\n", *p); // *p = 12
    printf("%d\n", a); // a = 12
    int b = 20;
    *p = b;
    printf("%d\n", *p); // *p = 20
    printf("%d\n", a); // a = 20

    a = 10;
    p = &a;
    printf("%d\n", p); // p = x
    printf("%d\n", p + 1); // p = x + 4 (my compiler does x - 4)(int is 4 bytes)
    printf("%d\n", *(p + 1)); // *(p + 1) = some garbage value, cuz there is nothing put in that adress (x+4)
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // how memory works with pointers, arithmetic with pointers, typecasting, void pointers - genric pointers

    int n = 1025; // 1025 = 00000000 00000000 00000100 00000001b (4 bytes)
    int *p1 = &n;
    printf("The address of n (p1) is %d and the value of n (*p1) is %d\n", p1, *p1);
    char *p2;
    p2 = (char *)p1; // we make p2 point to p1, but only to the size of a char (if there is no (char *) then error) (it's called typecasting)
    // the value of *p2 is 1, cuz the first byte is 00000001b
    // the address of p2 is going to be the same as p1, cuz they both point to the smallest the first byte's adress
    printf("The address of n (p2 = (char *)p1) now is %d and the value of n (*p2) now is %d\n", p2, *p2);
    void *p0;
    p0 = p1; // void pointers do not need typecasting
    printf("The adress of n (p0) is %d\n", p0); 
    // printf("The adress of n (*p0) is %d", *p0);  // This will give us an error, cuz we cannot derefrence void pointers
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // pointers to pointers

    int number = 10;
    int *q = &number;
    int **w = &q;
    int ***e;
    e = &w;
    printf("%d\n", **w); // **w = 10
    *q = 12;
    printf("%d\n", number); // number = 12
    ***e = **w + *q;
    printf("%d %d %d %d\n", number, *q, **w, ***e); // 24 24 24 24
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // pointers as function arguments - call by reference

    int x = 10;
    increment(x); // won't increment our local x
    increment_with_pointers(&x); // will increment our local x
    printf("x = %d\n", x); // x = 11
    // The adresses of x in main and in the increment function are different (they are differenet variables, they are both local variables - only work in that part of function).
    
    // The application's memory for a program, which is borrowed memory from the ram of our computer, is divided into 4 parts
    // Heap - used for dynamic memory allocation (the program may ask for more memory for the heap part during its execution and it may vary during the program's run time)
    // Stack - the place where all the local variables are placed (decided how much memory before the program starts)
    // Static/Global - global and static variabales are placed here (decided how much memory before the program starts)
    // Code(text) - the instructions of the code (decided how much memory before the program starts)
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // pointers and arrays

    int k = 10;
    int *point = &k;
    printf("%d\n", *(point + 1)); // random, cuz there is nothing inicialized in the address the the pointer p+1 stores

    int A[5] = {1, 2, 3, 4, 5};
    // A++; // error
    int *array_p = &(A[0]); // the same as int *array_p = A; , cuz A gives us a pointer to the first element of the array
    printf("The array (it's first element) is within the address %d and it holds the value of %d\n", array_p, *array_p);
    printf("The second element's adress is %d and its value is %d\n", array_p + 1, *(array_p + 1));
    printf("These numbers are the same as in previous prints: %d %d %d %d\n", A, *A, A + 1, *(A + 1));

    // Adress - &(A[i]) and  (A + i)
    // Value  -   A[i]  and  *(A + i)

    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // arrays as function arguments

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int size = sizeof(array) / sizeof(array[0]); // We couldn't do this in the twice_as_big function
    // because we pass the pointer to the first element of the array to the function, so there is no way to find out the size of the array in the function
    printf("size of array is %d\n", size);
    twice_as_big(array, size);

    printf("The elements in the array are now:\n");
    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }
    printf("\n\n");

    // ---------------------------------------------------------------------------------------------------------
    // Character arrays and pointers

    char s1[] = "Hello";
    char s2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char *s3  = "Hello"; // a pointer is 8 byte in a 64bit machine and 4 byte in a 32bit machine
    //s3[0] = 'A'; // error
    printf("The length of these strings are: %lu %lu %lu\n", strlen(s1), strlen(s2), strlen(s3));
    printf("The size of these arrays are: %lu %lu %lu\n", sizeof(s1), sizeof(s2), sizeof(s3));
    printing_the_string(s1);

    int *wierd;
    printf("The size of a pointer is %lu\n", sizeof(wierd));
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // pointers and multi-dimentional arrays

    int B[2][3] = {2, 3, 6, 4, 5, 8};
    // int *p = B; // warning (video says should be error), cuz B will return a pointer to a one dimentional array of 3 integers
    int (*pointer_to_a_one_dimentional_array)[3] = B;

    printf("B = &B[0] = *B = B[0] = &B[0][0] = %d  %d  %d  %d  %d\n", B, &B[0], *B, B[0], &B[0][0]);
    printf("B + 1 = &B[1] = *(B + 1) = B[1] = &B[1][0] = %d  %d  %d  %d  %d\n", B + 1, &B[1], *(B + 1), B[1], &B[1][0]);
    printf("*(B + 1) + 2 = B[1] + 2 = &B[1][2] = %d  %d  %d\n", *(B + 1) + 2, B[1] + 2, &B[1][2]);
    printf("*(*B+1) = B[0][1] = *(B[0] + 1) = %d  %d  %d\n", *(*B+1), B[0][1], *(B[0] + 1));

    // B[i][j] = *(B[i] + j) = *(*(B+i) + j)
    printf("\n");

    int C[3][2][2] = {{{2,5},{7,9}},{{3,4},{6,1}},{{0,8},{11,13}}};
    int (*pointer_to_a_two_dimentional_array)[2][2] = C;
    // C[i][j][k] = *(C[i][j] + k) = *(*(C[i] + j) + k) = *(*(*(C+i)+j)+k)
    printf("C = *C = C[0] = &C[0][0] = %d  %d  %d  %d\n", C, *C, C[0], &C[0][0]);
    printf("*(C[0][0] +1) = C[0][0][1] = %d  %d\n", *(C[0][0] + 1), C[0][0][1]);
    printf("*(C[1] + 1) = C[1][1] = *(*(C + 1)+ 1) = &C[1][1][0] = %d  %d  %d  %d\n", *(C[1] + 1), C[1][1], *(*(C + 1)+ 1), &C[1][1][0]);
    printf("\n");

    int D1[] = {1, 2, 3};
    one_dimentional(D1);
    two_dimentional(B);
    three_dimentional(C);


    // ---------------------------------------------------------------------------------------------------------
    // pointers and dynamic memory

    // stackoverflow
    // Application's memory gained from the machine's RAM is diveided into 4 places, heap, stack, global/static, Code(text)
    // The stack memory stores all the functions and local variables.
    // So stackoverlow may happen if there are a lot of functions that are calling each other. For example, function A() calls function B(), function B() calls function C() and so on.
    // So if the there are a lot of functions that are calling each other, this may result of lack of memory space that is given for the stack place of memory and stackoverflow may happen.
    // For example a bad recursion function (a function that calls itself) that never end may result stackoverflow and our program may crash

    // Dynamic memory allocation is used in the heap part of application's memory

    // Malloc creates the size of sizeof(x) memory in the heap storage and malloc returns a void pointer to main, which points to the adress of the heap storage where the memory was allocated
    // We use typecasting while using malloc, for example:(int *), because malloc returns a void pointer, but we need a specific pointer 

    int *dynamic = (int *) malloc(20 * sizeof(int));
    for (int i = 0; i < 20; ++i){
        *(dynamic + i) = i + 1;
        printf("%d ", *(dynamic + i));
    }
    printf("\n");
    free(dynamic);
    
    // The results will be the same, because free() tells the OS that I am not going to use that part of heap anymore, so if you want to, u can overwrite the values that are stored in that part when u need to
    // The values there after free() are kept, but they are just understood as garbage values
    for (int i = 0; i < 20; ++i){
        *(dynamic + i) = i + 1;
        printf("%d ", *(dynamic + i));
    }
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // malloc, calloc, realloc and free

    // malloc - void* malloc(size_t size)    size_t - stores positive integers (like unsigned int)
    // calloc - void* calloc(size_t num, size_t size)   size - size of data type, num - number of elements of a particular data type
    //      calloc inicializes all byte values with zeros, while malloc doesn't do that, meaning that with malloc the values will be random garbage values
    // realloc - void* realloc(void* ptr, size_t size)    ptr - pointer to the starting address of the existing block , size - size of the new block
    //      realloc extends the memory for the pointer or if that is not posible, copies the values into an other place of the heap where the realloced memory now fits
    // free - 

    int size_of_array = 6;
    //int static_array[size_of_array]; // taip negalima !!! C89 tai skaitytų kaip error, nes programa turi žinoti, kiek skirti atminties masyvui kompiliavimo metu, o ne programos leidimo metu
    int *dynamic_array_malloc = (int *) malloc(size_of_array * sizeof(int));
    int *dynamic_array_calloc = (int *) calloc(size_of_array, sizeof(int));
    for (int i = 0; i < size_of_array; ++i){
        *(dynamic_array_malloc + i) = i + 1;
        printf("%d ", *(dynamic_array_malloc + i));
    }
    printf("\n");

    for (int i = 0; i < size_of_array; ++i){
        printf("%d ", *(dynamic_array_calloc + i));
    }
    printf("\n");

    dynamic_array_malloc = (int *) realloc(dynamic_array_malloc, size_of_array*2*sizeof(int));
    for (int i = 0; i < size_of_array*2; ++i){
        printf("%d ", *(dynamic_array_malloc + i));
    }
    printf("\n");

    dynamic_array_malloc = (int *) realloc(dynamic_array_malloc, 0); // this is equivalent to free(dynamic_array_malloc)
    int *equivalent_malloc = (int *) realloc(NULL, size_of_array*sizeof(int)); // this is equivalent to malloc(size_of_array*sizeof(int))
    free(dynamic_array_calloc);
    free(equivalent_malloc);
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // pointers as function returns

    int num1 = 2, num2 = 4;
    int *ptr = add(&num1, &num2);
    print_hello_world();
    printf("Sum = %d\n", *ptr);
    free(ptr);
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------
    // function pointers

    void (*function_pointer)(char *);
    function_pointer = say_hi;
    function_pointer("Tom");

    int (*function_pointer2)(int, int);
    function_pointer2 = addition;
    int answer = function_pointer2(2, 6);
    printf("Sum = %d\n", answer);

    printf("\n");


    // ---------------------------------------------------------------------------------------------------------
    // function pointers and callbacks

    // the name of a function returns a pointer

    void (*another_pointer)() = A_function;
    B_function(another_pointer);
    // these two lines could also just be writen as B(A), because the name of a function returns a pointer

    int array_to_sort[] = {1, -55, 8, 77, 479, -2651, -6, 0, -5, 5, 1, 2, 54, -4, 446};
    int size_of_array_to_sort = sizeof(array_to_sort) / sizeof(array_to_sort[0]);
    qsort(array_to_sort, size_of_array_to_sort, sizeof(int), compare);
    for (int i = 0; i < size_of_array_to_sort; ++i){
        printf("%d ", array_to_sort[i]);
    }
    printf("\n\n");

    return 0;
}

// call by value
void increment(int x){
    x = x + 1;

    return;
}

// call by reference
void increment_with_pointers(int *x){
    *x = (*x) + 1;

    return;
}

// this function reseaves only the pointer to the array not the whole array, which makes sence,
//   cuz there are cases when arrays are very big so there would be no point to copy the whole array again.
//   But this means there is no possible way to find out how big our array is if we don't pass the variable size to this function
void twice_as_big (int array[], int size){  //int *array and int array[] is the same

    for (int i = 0; i < size; ++i){
        array[i] = array[i] * 2;
    }

    return;
}

void printing_the_string(char *s1){
    char *x = s1;
    printf("The word stored int s1 is:\n");
    int i = 0;
    while (*s1 != '\0'){
        printf("%c", *s1);
        ++s1;
    }
    printf("\n");
    s1 = x;
    printf("The word stored int s1 after changing its first character is:\n");
    s1[0] = 'A';
    while (*s1 != '\0'){
        printf("%c", *s1);
        ++s1;
    }
    printf("\n");

    return;
}

void one_dimentional(int *A){ // could also be int A[]

}
void two_dimentional(int *A[3]){ // could also be int A[][3]

}
void three_dimentional(int *A[2][2]){ // could also be int A[][2][2]

}

void print_hello_world(){
    printf("Hello world\n");
    return;
}

int* add(int* a, int* b){ // but this function is not ok, cuz now I can't free(c), cuz using memory allocation again the answer may be overwriten
    int* c = (int *) malloc(sizeof(int));
    *c = (*a) + (*b);
    return c;
}

void say_hi(char *name){
    printf("Hello %s\n", name);
    return;
}

int addition(int a, int b){
    return a+b;
}

int compare(const void* a, const void* b){
    int A = *((int *) a);
    int B = *((int *) b);
    return A-B; // if B-A then decreasing order
}

void A_function(){
    printf("hello\n");
}

void B_function(void (*ptr)()){
    ptr();
}