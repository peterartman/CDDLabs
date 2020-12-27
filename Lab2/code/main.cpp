/*! \mainapge Lab TWo
 * \file main.cpp
 * \brief Lab2, an implementation of threads using semafores
 * \author Joseph Kehoe, Piotr Artman
 * \date 7 November 2020
 * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence,
 * for more information visit <A HREF="http://creativecommons.org/licenses/by-sa/4.0/.">http://creativecommons.org/licenses/by-sa/4.0/.</A>
 * \section desc_sec Description
 * 
 * This is file is part of Lab 2
 * and contains code with implementation of threads by usig semafores.
 * 
 * \section dep_sec Dependencies
 *
 * This code depens on:
 * "Semaphore.h" header,
 * <iostream> library,
 * <thread> libarary,
 * <unistd.h> header
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
  /**
  * \fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay)
  * \brief This function will be executed after delay
  * \param delay  This integer is used to set duration of sleep
  * \param theSemaphore this parameter is used for flow control
  */
 /*! displays a message first*/
 void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
  /**
  * \fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay)
  * \brief This is task one to execute
  * \param int delay is used to set duration delay betwen first and second task
  * \param theSemaphore pointer is used for flow control
  */
/*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  /**
  * \fn void taskTwo(std::shared_ptr<Semaphore> theSemaphore)
  * \brief This is second task to exacute
  * \param theSemaphore pointer is used for flow control
  */
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  /**
  * \fn int main(void)
  * \brief This is function with implementation of taskOne and taskTwo
  * \var sem Semaphore is used for flow control
  * \var thread threadOne is the first thread
  * \var thread threadTwo is the second thread
  */
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Threads starts here */
  int taskOneDelay=5;
  /**
  * \param taskOneDelay
  * \brief This integer is used to set duration of delay for task one.
  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
}
