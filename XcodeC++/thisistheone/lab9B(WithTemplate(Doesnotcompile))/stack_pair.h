#ifndef STACK_PAIR_h
#define STACK_PAIR_h

template <class T>
class stack_pair {
public:
    static const int CAPACITY = 30;
    
    stack_pair();

    /*
     * Insert an element into the stack
     *
     * Precondition: stack is not full,.
     */
    void push_a(T element);
    void push_b(T element);

    /**
     * Remove an element from the stack and return it
     *
     * Precondition: stack is not empty.
     */
    T pop_a();
    T pop_b();


    bool isEmpty_a() const;
     bool isEmpty_b() const;

    bool isFull_a() const;
    bool isFull_b() const;



    
private:
    
    T data[CAPACITY];
    size_t top_a;
    size_t top_b;
};

#include "stack_pair.template"


#endif // stack_pair_h


