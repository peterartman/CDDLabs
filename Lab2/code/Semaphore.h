/*
This work is licensed under the  Creative Commons Attribution-ShareAlike 4.0 International Licence.
To view of this licence, visit http://creativecommons.org/licenses/by-sa/4.0/.

*/
/*! \mainapge Semaphore file for Lab Two
 * \file Semaphore.cpp
 * \brief A Semaphore Implementation
 */


#ifndef SEMAPHORE_H
#define SEMAPHORE_H 
#include <mutex>
#include <condition_variable>
#include <chrono>
/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/


class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
          : m_uiCount(uiCount) { };
    void Wait();
    template< typename R,typename P >
    bool Wait(const std::chrono::duration<R,P>& crRelTime);
    void Signal();

};

#endif
