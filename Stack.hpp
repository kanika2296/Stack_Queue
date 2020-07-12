#include <iostream>
#include <time.h> 
#include <new>
using namespace std;

template <typename T>
class ABS // stack
{

    public:
        T* stack; 			//array-pointer to stack
        int maxCapacity; 	// max capacity
        int count; 			// number of item
        float scale; 
		clock_t t1; 
        clock_t t2; 

        // default constructor 
        ABS() 
        {
            scale = 2.0f;
            maxCapacity=1;
            count = 0;      // top = count-1
            stack = new T[maxCapacity];
            t1 = clock(); 
        }
        // parameterized : capacity 
        ABS(int capacity) 
        {
            maxCapacity=capacity;
            t1 = clock(); 
            count = 0;  
            scale = 2.0f;
            stack = new T[maxCapacity];          
        }
        // parameterized : capacity + scaling factor 
        ABS(int capacity, float scale_factor) // constructor with capacity
        {
            scale = scale_factor;
            maxCapacity=capacity;
            t1 = clock(); 
            count = 0;  
            stack = new T[maxCapacity];          
        }
        // copy constructor
        ABS(const ABS& d) //copy 
        {
            try
            {

              stack = new T[d.maxCapacity];
              t1 = clock(); 
              maxCapacity = d.maxCapacity;
              count = d.count;
              for (int i = 0; i < count; i++)
                    stack[i] = d.stack[i];
            }
            catch (bad_alloc e)
            {
              cout << e.what() << endl;
            }
        }
        // operator = constructor
        ABS operator=(const ABS& d) 
        {
            if (count > 0)
            {
              count = 0;
              delete[] stack;
            }
            try 
            {
            	t1 = clock(); 
                maxCapacity = d.maxCapacity;
                count = d.count;
                for (int i = 0; i < count; i++)
                    stack[i] = d.stack[i];
            }
            catch (bad_alloc e)
            {
              cout << e.what() << endl;
            }
        
            return *this;
        }
        // Destructor - frees memory
        ~ABS()
        {
            delete[] stack;
            t2 = clock()-t1; 
            double time_taken = ((double)t2)/CLOCKS_PER_SEC; 
    		printf("fun() took %f seconds to execute \n", time_taken); 
        }

        // push item 
        void push(T data) // push
        {    
            try 
            {
                count++;
                if(isFull())
                {
                   T *tmp;
                   tmp = stack;
                   //cout <<"here";
                   maxCapacity = maxCapacity*scale;
                   stack = new T[maxCapacity];
                    for (int i = 0; i < count - 1; i++)
                        stack[i] = tmp[i];
                    stack[count-1]=data;
                   	delete[] tmp;
                }
                else
                {
                    stack[count-1] = data;
                }
            }
            catch(bad_alloc e)
            {
                cout << e.what() <<endl;
            }
        }
        // check if stack is full
        bool isFull()
        {
            if(maxCapacity < count)
                return true;
            return false;
        }
        // returns maximum capacity
        unsigned int getMaxCapacity()
        {
            return maxCapacity;
        }
        // pops item
        T pop()
        {
            try
            {  
                if (count == 0)
                	throw runtime_error("An error has occurred.");
                else
                {
	                T *tmp;
	                tmp = stack;
	                count--;
	                if(isLessHalf())
	                {
	                    maxCapacity = maxCapacity/scale;
	                    stack = new T[maxCapacity];
	                    for (int i = 0; i < count; i++)
	                        stack[i] = tmp[i];
	                    delete[] tmp;
	                }
	            }
	            return stack[count];
            }
            catch (runtime_error e)
            {
            	cout << e.what() <<endl;
            }
        }
        // checks if capacity is half
        bool isLessHalf()
        {
            if(count < maxCapacity/scale)
                return true;
            return false;
        }
        // returns number of elements 
        unsigned int getSize()
        {
            return count;
        }
        T peek()
        {
            try
            {
	            if(count == 0)
	            	throw runtime_error("An error has occurred.");
	            else 
	            	return stack[count-1]; 
            }
            catch (runtime_error e)
            {
            	cout << e.what() <<endl;
            }
        }
        T* getData()
        {
            return stack;
        }
};
