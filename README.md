# Simultaneous-Multi-Threading-Implementation
SMT concurrency implementation in C++, which lets you run a function(functor) simultaneously on multiple threads, 
taking jobs from a queue.

# Usage:
* Create a functor, (class) which implements the () operator, that takes exactly one parameter of any type
* Fill up a queue of the type that the functor takes as parameter
* instantiate a concurrent::PARALLEL object with template parameters of the functor and its respective parameter type
 the constructor takes two parameters:
 1.a functor instantiation
 2.the job queue


# Example: concurrently calculate sum of matrix

![Fill up the matrix ](https://raw.githubusercontent.com/BNandor/Simultaneous-Multi-Threading-Implementation/master/img/feltolt.png)

![Fill up the matrix ](https://raw.githubusercontent.com/BNandor/Simultaneous-Multi-Threading-Implementation/master/img/parameter.png)
