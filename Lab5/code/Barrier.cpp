/*! \mainapge Lab Five
 * \file Barrier.cpp
 * \brief Reusable Barier class
 * \author Joseph Kehoe, Piotr Artman
 * \date 30 DEC 2020
 * \copyright This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http: *www.gnu.org/licenses/>.
 * 
 * \section desc_sec Description
 * 
 * This is file created for Lab 4.
 * 
 * \section dep_sec Dependencies
 *
 * This Reusable Barrier class depens on:
 * Semaphore header
 * Semaphore class
 * Barrier header
 * iostream library
 */

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
    mutex.reset(new Semaphore(1));
    turnstileOne.reset(new Semaphore(0));
    turnstileTwo.reset(new Semaphore(0));
}

/** \brief Implementation of Barrier class destructor.
      * This destructor resets turnstileOne and turnstileTwo semafores 
      * aas well as lock semafore.
      */
Barrier::~Barrier()
{
    mutex.reset();
    turnstileOne.reset();
    turnstileTwo.reset();
}

/** \brief Phase one method.
      * This mehod forces all threads to wait 
      * until all threeds arrive.
      */
void Barrier::phase1()
{
    mutex->Wait();
    ++current_count;
    if (current_count == numThreads)
    {
        turnstileTwo->Wait();
        turnstileOne->Signal();
    }
    mutex->Signal();
    turnstileOne->Wait();
    turnstileOne->Signal();
}

/** \brief Phase two method
      * This mehod forces all threads to wait 
      * until all threeds executed critical section.
      */
void Barrier::phase2()
{
    mutex->Wait();
    --current_count;
    if (current_count == 0)
    {
        turnstileTwo->Signal();
    }
    mutex->Signal();
    turnstileTwo->Wait();
}

void Barrier::wait()
{
    phase1();
    phase2();
}
//
// Barrier.cpp ends here
