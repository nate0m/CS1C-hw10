#include <iostream>

using namespace std;

int x;
int& getRef () 
{
    return x;
}

int getVal ()
{
    return x;
}

string getName ()
{
    return "Alex";
}

void printReference (const string & str)
{
    cout << str;
}
 
void printReference (string && str)
{
    cout << str;
}


void foo(int * p_int)
{
    cout << *p_int;
}

void goo(int * const & r_p_int)
{
   cout << *r_p_int;
}

int main()
{

    getRef() = 4;

    getVal();

    getName();
    string name = getName();

    const string & clv_name_brv = getName(); // ok
    //string& lv_name_brv = getName(); // NOT ok

    const string && crv_name_brv = getName(); // ok
    string&& rv_name_brv = getName(); // also ok - praise be!

    string me( "alex" );
    printReference( me ); // calls the first printReference function, taking an lvalue reference
    printReference( getName() ); // calls the second printReference function, taking a mutable rvalue reference


    int a;
    a = 100; // here, a is an lvalue
    int * p_int = &a;

    foo(p_int);
    goo(p_int);
    goo(&a);


    return 0;
}
