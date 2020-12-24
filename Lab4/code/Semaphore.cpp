#include "Semaphore.h"

/*
This work is licensed under the  Creative Commons Attribution-ShareAlike 4.0 International Licence.
To view of this licence, visit http://creativecommons.org/licenses/by-sa/4.0/.

*/
/*! \mainapge Semaphore file for Lab Two
 * \file Semaphore.cpp
 * \brief A file for lab 4 using mutex to implement semaphore functionality.
 * \fn void Semaphore::Wait()
 * \fn bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
 * \fn void Semaphore::Signal()
 * \author Joseph Kehoe, Piotr Artman
 * \date 7 November 2020
 * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence
 * \section desc_sec Implementaiotn of Semaphore class
 * 
 * \section dep_sec This code depens on semaphore header.
 * \section dep_sec Semaphore.h
 * 
 */


/**
 * @fn void Semaphore::Wait()
 * @brief This function sets semafore to "Wait" state.
 */
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}


template< typename R,typename P >
bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
{
      std::unique_lock< std::mutex > lock(m_mutex);
      if (!m_condition.wait_for(lock,crRelTime,[&]()->bool{ return m_uiCount>0; })){
	  return false;
      }
      --m_uiCount;
      return true;
}

/**
 * @fn void Semaphore::Signal()
 * @brief This function sets semafore to "Signal" state.
 */
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
