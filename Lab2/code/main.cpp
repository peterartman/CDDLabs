/*
This work is licensed under the  Creative Commons Attribution-ShareAlike 4.0 International Licence.
To view of this licence, visit http://creativecommons.org/licenses/by-sa/4.0/.

*/
/*! \mainapge Lab TWo
 * \file main.cpp
 * \brief An implementation of threads using semafores
 * \param theSemaphore this parameter is used for flow control
 * \param delay this integer is used to set duration of sleep for a thread
 * \param taskOneDelay this integere is used to set 
 * \author Joseph Kehoe, Piotr Artman
 * \date 7 November 2020
 * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence
 * \section desc_sec Description
 * 
 * This is file created for Lab 2.
 * 
 * \section dep_sec Dependencies
 *
 * This code depens on
 * Semaphore header
 * iostread library
 * thread library
 * unistd header
 * 
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
  /**
  * @fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay)
  * @brief This function will be executed after delay
  * @param delay  This integer is used to set duration of sleep 
  * @param theSemaphore this parameter is used for flow control
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
  * @fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay)
  * @brief This function will be executed after delay
  * @param delay  This integer is used to set duration of sleep 
  * @param theSemaphore this parameter is used for flow control
  */
/*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  /**
  * @fn void taskTwo(std::shared_ptr<Semaphore> theSemaphore)
  * @brief This function will be executed first
  * @param theSemaphore this parameter is used for flow control
  */
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  /**
  * @fn int main(void)
  * @brief This is function with implementation of taskOne and taskTwo
  * @param sem This parameter is used for flow control
  * @param threadOne Thread one
  * @param threadTwo Thread two
  */
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  /**
  * This integer is used to set duration of sleep for a thread.
  * @param taskOneDelay
  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
}
