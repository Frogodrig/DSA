#include<iostream>
using namespace std;

class A {

    public:
    void sayHello() {

        cout<<"Hello Aditya Awasthi"<<endl;
    }

    void sayHello(string name) {

        cout<<"Hello "<<name<<endl;
    } //Compile Time Polymorphism - Function Overloading

    // int sayHello() {

    //     cout<<"Hello Aditya Awasthi"<<endl;
    // } //Changing only return type will not be considered as overloading and won't work

    // int sayHello(string name) {

    //     cout<<"Hello Aditya Awasthi"<<endl;
    // } //This will also not work as the difference is only in the return type (compare line 12 and 22)

    int sayHello(string name, int n) {

        cout<<"Hello Aditya Awasthi"<<endl;
        return 1;
    } //This will work

    /*Note: Function overloading can also be implemented by using default arguments func(int a, int b, int c=0, int d=1)
    can call this function by passing 2 arguments, 3 or all arguments also*/

};

class B {

    public:
    int a;
    int b;

    public:
    int add() {
        return a + b;
    }

    void operator + (B &obj) {
        int val1 = this -> a; //The value of the object that called the operator
        int val2 = obj.a; //The value of the object passed to the operator 
        cout<<"output: "<<val2 - val1 <<endl;
    } //Operator oveloading
};

int main() {
    
    A obj;
    obj.sayHello();


    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;

    return 0;
}
