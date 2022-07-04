//Implement your own sizeOf function
//We can only subtract pointers, we can't add, multiply or divide them

#include<iostream>
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)
using namespace std;

int main()
{
    double x;
    printf("%ld", my_sizeof(x));
    return 0;
}

//(&type+1) - (&type)  will give you how many variables of type 'type' can be stored in the memory difference 
//Here in the case of double only one as (&x+1) - (&x) will give 1, but we need the byte size and double has a size of 8
//Typecasting it into char* and taking the difference will tell us how many variables of type char can be stored in the given memory space (the difference)
//Since each char requires the only 1B of memory, therefore (amount of memory)/1  will give a result of 8 in our example.
//We are using macros because in the case of functions we will need to define all data types.(function overloading)