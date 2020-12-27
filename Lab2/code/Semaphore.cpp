/*! \mainapge Semaphore file for Lab Two
 * \file Semaphore.cpp
 * \brief A file for lab 2 using mutex to implement semaphore functionality.
 * \fn void Semaphore::Wait()
 * \fn bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
 * \fn void Semaphore::Signal()
 * \author Joseph Kehoe, Piotr Artman
 * \date 7 November 2020
 * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence,
 * for more info visit <A HREF="http://creativecommons.org/licenses/by-sa/4.0/.">http://creativecommons.org/licenses/by-sa/4.0/.</A>.
 * \section desc_sec Description
 *
 * Implementaiotn of Semaphore class
 *
 * \section dep_sec Dependencies
 *
 * This code depens on Semaphore.h header
 */

#include "Semaphore.h"

/**
 * \fn void Semaphore::Wait()
 * \brief This function sets semafore to "Wait" state.
 */
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}

/**
 * \fn bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
 * \brief This function sets semafore to "Wait" state.
 */

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
 * \fn void Semaphore::Signal()
 * \brief This function sets semafore to "Signal" state.
 */
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
