// Question 5
//
//	we want to implement a logic class named MyBool to use in our logic
//	we would like to be able to use the logical and (&&) with instances of this class
//  i.e. to be able to write in the form of myBool1 && myBool2
//	we have also implemented some function using this class
//	"notNull" checks if a pointer is null and return a corresponding MyBool
//  "greaterThanZero" checks if an int pointer points to a positive int and return a corresponding MyBool
//
//	1. Implement this addition in the MyBool class
//  2. Did it compile successfully? yes
//	3. Did it run successfully? yes 
//	4. Explain the result, explain what happened and why
// 
// Answer: 
//-----------
// I added the bool () operator and the && operator, which belong to the myBool object.
// Additionally, I added getM_val because the my_valu field is private and I want it to remain private to prevent direct access to it.
// The reason I added the bool () operator is to define if on an object of type
//
// useful links:
// https://en.cppreference.com/w/cpp/language/operators
// https://cplusplus.com/doc/tutorial/operators/
// https://isocpp.org/wiki/faq/operator-overloading

#include <iostream>

class MyBool
{
public:
    MyBool(bool b) : m_val(b) {};

    friend MyBool& operator&&(MyBool other1, MyBool other2)
    {
        MyBool* ret_myBool = new MyBool(other1.getM_val() && other2.getM_val());
        return *ret_myBool;
    }

    operator bool() const
    {
        if (this == nullptr ) return false;
        return m_val;
    }

    bool getM_val() const
    {
        return  m_val;
    }


private:
    bool m_val;

};



MyBool notNull(int* intPtr)
{
    return intPtr != nullptr;
}

MyBool greaterThanZero(int* intPtr)
{
    if(intPtr == nullptr) return false;
    return *intPtr > 0;
}

int main(int argc, char* argv[])
{
    int* a = nullptr;
    int val = 5;
    int* b = &val;


    // the long way to check
    if (a != nullptr && *a > 0)
    {
        ++*a;
        std::cout << "*a is " << *a << std::endl;
    }

    // using our functions
    if (notNull(b) && greaterThanZero(b))
    {
        ++*b;
        std::cout << "*b is " << *b << std::endl;
    }

    // using our functions again
    if (notNull(a) && greaterThanZero(a))
    {
        ++*a;
        std::cout << "*a is " << *a << std::endl;
    }

    return 0;
}

