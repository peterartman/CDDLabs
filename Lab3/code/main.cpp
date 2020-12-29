/*! \mainapge Lab TWo
 * \file main.cpp
 * \brief Lab3, exercise on using rendezvous pattern
 * \author Joseph Kehoe, Piotr Artman
 * \date 28 DEC 2020
 * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence,
 * for more information visit <A HREF="http://creativecommons.org/licenses/by-sa/4.0/.">http://creativecommons.org/licenses/by-sa/4.0/.</A>
 * \section desc_sec Description
 * 
 * This is file is part of Lab 3
 * and contains code with example of rendezvous by usig semafores.
 * 
 * \section dep_sec Dependencies
 *
 * This code depens on:
 * "Semaphore.h" header,
 * <iostream> library,
 * <thread> library,
 * <chrono> library.
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

int getDelayValue()
{
  return rand() % 5;
}

/**
  * \fn int getDelayValue()
  * \brief This function returns random integer between 0 and 5, which represents duration of delay for a thread
  */


void taskOne(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay){
std::this_thread::sleep_for(std::chrono::seconds(delay));
std::cout << "Task one arrived" << std::endl;
  firstSem->Signal();
  //THIS IS RENDEVOUS POINT
  secondSem->Wait();
  std::cout << "Task one left" << std::endl;
}
/**
  * \fn taskOne(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay)
  * \brief This is function defines behaviour for task one.
  * \param firstSem is shared pointer to the first semafore
  * \param secondSem is shared pointer to the second semafore
  * \param delay is duration of delay between arrival of task and entering into rendezvous point
  */

void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem,int delay){
std::this_thread::sleep_for(std::chrono::seconds(delay));
std::cout << "Task two arrived" << std::endl;
secondSem->Signal();
//THIS IS RENDEVOUS POINT
firstSem->Wait();
std::cout << "Task two left" << std::endl;
}
/**
  * \brief This is function defines behaviour for task one.
  * \param firstSem is shared pointer to the first semafore
  * \param secondSem is shared pointer to the second semafore
  * \param delay is duration of delay between arrival of task and entering into rendezvous point
  */

int main(void){
  std::thread firstThread; /*!< a thread with first task*/
  std::thread secondThread; /*!< a thread with second task*/
  std::shared_ptr<Semaphore> sem1(new Semaphore); /*!< a semafore sem1 */
  std::shared_ptr<Semaphore> sem2( new Semaphore);/*!< a semafore sem2 */
  std::cout << "Lanched form main\n";
  firstThread = std::thread(taskTwo, sem1, sem2, getDelayValue());
  secondThread = std::thread(taskOne, sem1, sem2, getDelayValue());
  firstThread.join();
  secondThread.join();
  return 0;
}
/**
  * \fn int main(void)
  * \brief This is function with implementation of rendezvous pattern between taskOne and taskTwo
  * \param void
  * \var firstThread is first thread used to demonstrate rendezvous pattern
  * \var secondThread is second thread used to demonstrate rendezvous pattern
  */