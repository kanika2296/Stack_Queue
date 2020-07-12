#include <iostream>
#include <new>
using namespace std;

template <typename T>
class ABQ // queue
{

    public:
        T* queue ; //array-pointer to queue
        int maxCapacity; // max capacity
        int count; // number of items
        float scale; // scaling factor
        int front;
        int rear;
        int resize;
            // default constructor 
        ABQ() 
        {
            scale = 2.0f;
            maxCapacity=1;
            count = 0;      // top = count-1
            queue = new T[maxCapacity];
            rear = 0;
            front = 0;
            resize = 0;
        }
        // parameterized : capacity 
        ABQ(int capacity) 
        {
            maxCapacity=capacity;
            count = 0;  
            scale = 2.0f;
            queue = new T[maxCapacity];  
            rear = 0;
            front = 0;
			resize = 0;        
        }
        // parameterized : capacity + scaling factor 
        ABQ(int capacity, float scale_factor) // constructor with capacity
        {
            scale = scale_factor;
            maxCapacity=capacity;
            count = 0;  
            queue = new T[maxCapacity]; 
            rear = 0;
            front = 0;  
			resize = 0;      
        }
        // copy constructor
        ABQ(const ABQ& d) //copy 
        {
            try
            {

              queue = new T[d.maxCapacity];
              
              maxCapacity = d.maxCapacity;
              count = d.count;
              rear = count;
              front = 0;
              for (int i = 0,j=d.front; j < d.rear; j++,i++)
                    queue[i] = d.queue[j];
            }
            catch (bad_alloc e)
            {
              cout << e.what() << endl;
            }
        }
        // operator = constructor
        ABQ operator=(const ABQ& d) 
        {
            if (count > 0)
            {
              count = 0;
              delete[] queue;
            }
            try 
            {
                maxCapacity = d.maxCapacity;
                count = d.count;
                rear = count;
                front = 0;
                for (int i = 0,j=d.front; j < d.rear; j++,i++)
                    queue[i] = d.queue[j];
            }
            catch (bad_alloc e)
            {
              cout << e.what() << endl;
            }
        
            return *this;
        }
        // Destructor - frees memory
        ~ABQ()
        {
            delete[] queue;
        }
        // returns maximum capacity
        unsigned int getMaxCapacity()
        {
            return maxCapacity;
        }
        // returns number of elements 
        unsigned int getSize()
        {
            return count;
        }
        // check if stack is full
        bool isFull()
        {
            if(maxCapacity < count)
                return true;
            return false;
        }
        // checks if capacity is half
        bool isLessHalf()
        {
            if(count < maxCapacity/scale)
                return true;
            return false;
        }
        // enqueue data
        void enqueue(T data)
        {
            try 
            {
                count++;
                if(isFull())
                {
                   T *tmp;
                   tmp = queue;
                   //cout <<"here";
                   maxCapacity = maxCapacity*scale;
                   queue = new T[maxCapacity];
                    for (int i = 0,j=front; j < rear; i++,j++)
                        queue[i] = tmp[j];
                    rear = count-1;
                    front=0;
                    queue[rear] = data;
                    rear++;
                    resize++;
                    delete[] tmp;
                }
                else
                {
                    queue[rear] = data;
                    rear++;
                }
            }
            catch(bad_alloc e)
            {
                cout << e.what() <<endl;
            }

        }
        T dequeue()
        {
            try
            {  
                if (count == 0)
                    throw runtime_error("An error has occurred.");
                else
                {
                    T *tmp;
                    tmp = queue;
                    T item = tmp[front];
                    count--;
                    front++;
                    if(isLessHalf())
                    {
                        maxCapacity = maxCapacity/scale;
                        queue = new T[maxCapacity];
                        for (int i = 0,j=front; j < rear; i++,j++)
                            queue[i] = tmp[j];
                        rear = count;
                        front = 0;
                        resize++;
                        delete[] tmp;
                    }
                return item;
                }
            }
            catch (runtime_error e)
            {
                cout << e.what() <<endl;
            }
        }
        T peek()
        {
            try
            {
                if(count == 0)
                    throw runtime_error("An error has occurred.");
                else 
                    return queue[front]; 
            }
            catch (runtime_error e)
            {
                cout << e.what() <<endl;
            }
        }
        T* getData()
        {
            return queue;
        }
};
