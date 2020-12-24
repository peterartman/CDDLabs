/*! \class Barrier
  * \brief Reusabe barier class
  * \author Piotr Artman
  * \version $Revision: 1.0 $
  * \date 20/10/2020
*/

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

/** \brief Implementation of Barrier class constructor.
  * \param numThreads an integer with information how many threads
  * will arrive to the barrier. It is critical to keep information
  * how many thread will arrive to the barrier, otherwise barrier
  * will not manage all threads properly.

  */
Barrier::Barrier(int numThreads)
{
    this->numThreads = numThreads;
    current_count = 0;
    lock.reset(new Semaphore(1));
    turnstileOne.reset(new Semaphore(0));
    turnstileTwo.reset(new Semaphore(1));
}

/** \brief Implementation of Barrier class destructor.
      * This destructor resets turnstileOne and turnstileTwo semafores 
      * aas well as lock semafore.
      */
Barrier::~Barrier()
{
    lock.reset();
    turnstileOne.reset();
    turnstileTwo.reset();
}

/** \brief Phase one method.
      * This mehod forces all threads to wait 
      * until all threeds arrive.
      */
void Barrier::phaseOne()
{
    lock->Wait();
    ++current_count;
    if (current_count == numThreads)
    {
        turnstileTwo->Wait();
        turnstileOne->Signal();
    }
    lock->Signal();
    turnstileOne->Wait();
    turnstileOne->Signal();
}

/** \brief Phase two method
      * This mehod forces all threads to wait 
      * until all threeds executed critical section.
      */
void Barrier::phaseTwo()
{
    lock->Wait();
    --current_count;
    if (current_count == 0)
    {
        turnstileOne->Wait();
        turnstileTwo->Signal();
    }
    lock->Signal();
    turnstileTwo->Wait();
    turnstileTwo->Signal();

}

void Barrier::wait()
{
    phaseOne();
    phaseTwo();
}
    

// 
// Barrier.cpp ends here
