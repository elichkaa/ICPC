int num = 1024;

// reference to number, when we change number/ref ref/number changes as well
// esentially an alias for number
int& ref = num;

// pointer to number, the adress where number is stored
int* address = &num;
// a way to get the value of a pointer through dereferencing him
int deref = *address;
// we can assign references to dereferenced pointers
int &ref2 = *address;
cout << num;

// double pointer
int ival = 100;
int *firstPointer = &ival;
int **secondPointer = &firstPointer;
// dereferencing a double pointer
int value = **secondPointer;

// pointer to a reference is not allowed
// however, because the pointer is an object, we can
// define a reference to a pointer.
int i = 42;
int *p;
int *&r = pointer;
r = &i; // r refers to a pointer; assigning &i to r makes p refer to i
*r = 0; // dereferencing r yields i and we assign i to 0