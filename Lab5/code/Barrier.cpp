#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>


Barrier::Barrier(int numThreads)
{
    this->numThreads = numThreads;
    current_count = 0;
    mutex.reset(new Semaphore(1));
    turnstile1.reset(new Semaphore(0));
    turnstile2.reset(new Semaphore(1));
}


Barrier::~Barrier()
{
    mutex.reset();
    turnstile1.reset();
    turnstile2.reset();
}


void Barrier::phase_one()
{
    mutex->Wait();
    ++current_count;
    if (current_count == numThreads)
    {
        turnstile2->Wait();
        turnstile1->Signal();
    }
    mutex->Signal();
    turnstile1->Wait();
    turnstile1->Signal();

}


void Barrier::phase_two()
{
    mutex->Wait();
    --current_count;
    if (current_count == 0)
    {
        turnstile1->Wait();
        turnstile2->Signal();
    }
    mutex->Signal();
    turnstile2->Wait();
    turnstile2->Signal();

}


void Barrier::wait()
{
    phase_one();
    phase_two();
}



// 
// Barrier.cpp ends here