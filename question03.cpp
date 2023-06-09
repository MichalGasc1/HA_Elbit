// Question 3 - implementation
//
//	without using STL containers implement the following:
//	A class for a dynamic int array, let's call it "CVectorInt" that -
//      1. doubles its size automatically when its full (allocates twice the size and moves the data),
//	    2. halves its size when it is half empty (allocates half of the size and moves the data)
//      3. can be told the initial capacity (num of ints) in a constructor
//      4. have a method called "reserve" - that Requests that the vector capacity be at least enough to contain n elements.
//     If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n
//     5. have a method called "capacity" - that returns the number of int elements allocated
//     6. have a method called "size" - that returns the number of elements actually inserted
//     7. have a method called "empty" - that returns true/false according to amount of actual elements in the data
//     8. have a method called "clear" - that frees all the data and resets the size
//     9. have a method called "push_back" - that adds an int elements at the end
//    10. have a method called "pop_back" - that removes an int elements at the end and return it
//    11. have a method called "remove"  - that removes an int elements at specific index
//    12. have an interface to access the data at a specific index using subscript "[]"
//
// make sure to handle edge cases such as memory issues, size issues etc.
#include <iostream>
#include <stdexcept>
using namespace std;


class CVectorInt
{
private:
    int* array;
    int cur_capacity;
    int cur_size = 0;




public:
    CVectorInt()
    {
        array = new int[1];
        cur_capacity = 1;
    }

    CVectorInt(int c)
    {
        array = new int[c];
        cur_capacity = c;
    }



    /**
     *
     * @param x
     * This method add x to the end of the array.
     * If the array is full, the method doubles the size of the array.
     */
    void push_back(int num)
    {
        // check if in the next iteration the array will be full

            // check if in the next iteration the array will be full
            if (cur_size  == cur_capacity)
            {
                cur_capacity = cur_capacity*2;
                int* temp_array = new int [cur_capacity];
                for (int i = 0; i < cur_size; i++)
                {
                    temp_array[i] = array[i];
                }
                delete[] array;
                array = temp_array;
            }


        array[cur_size] = num;
        cur_size +=1;
    }


    void reserve(int n)
    {
        if (cur_capacity < n ) {
            cur_capacity = n;
            int* temp_array = new int[cur_capacity];
            for(int i = 0; i < cur_size ; i++)
            {
                temp_array[i] = array[i];
            }
            delete [] array;
            array = temp_array;
        }
    }

    /**
     * remove the last element in the array and return it and resize the array size if needed.
     * @return the last element
     */
    int pop_back()
    {
        int ret_val = array[cur_size];
        //the array is half empty
        if(cur_size  <= int(cur_capacity/2))
        {
            cur_capacity = int(cur_capacity/2);
            int* temp_array = new int[cur_capacity];
            for(int i = 0; i < cur_size - 1; i++)
            {
                temp_array[i] = array[i];
            }
            delete[] array;
            array = temp_array;
        }
        //delete the "pointer" to the last value.
        cur_size -=1;
        return ret_val;
    }

    int& operator[](int idx)
    {
        if(idx < cur_size && 0 <= idx) return array[idx];
    }

    /*
     * removes an int elements at specific index
     */
    void remove(int idx)
    {
        int* temp_array = new int[cur_size];
        for(int i = 0; i < idx; i++)
        {
            temp_array[i] = array[i];
        }
        for(int i = idx; i < cur_size - 1 ; i++)
        {
            temp_array[i] = array[i+1];
        }
        cur_size-=1;
        delete [] array;
        array = temp_array;
    }

    void clear()
    {
        delete [] array;
        cur_size = 0;
        cur_capacity = 0 ;
    }

    bool empty() {
        return cur_size == 0 ;
    }

    int size()
    {
        return cur_size;
    }

    int capacity()
    {
        return cur_capacity;
    }




protected:

};

int main(int argc, char* argv[])
{

    try
    {
        CVectorInt v(5);

        for (int i = 0; i < 5; i++)
        {
            v.push_back(i);
        }
        std::cout << "the size is: " << v.size() << std::endl;
        std::cout << "the capacity is: " << v.capacity() << std::endl;
        v.push_back(1);
        std::cout << "the size is: " << v.size() << std::endl;
        std::cout << "the capacity is: " << v.capacity() << std::endl;
        while (!v.empty())
        {
            v.pop_back();
        }
        std::cout << "the size is: " << v.size() << std::endl;
        std::cout << "the capacity is: " << v.capacity() << std::endl;
        v.reserve(15);
        std::cout << "the size is: " << v.size() << std::endl;
        std::cout << "the capacity is: " << v.capacity() << std::endl;
        for (int i = 0; i < 15; i++)
        {
            v.push_back(i);

        }
        v[5] = 3;
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
        v.clear();
        std::cout << "the size is: " << v.size() << std::endl;
        std::cout << "the capacity is: " << v.capacity() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

