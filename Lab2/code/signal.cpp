#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
/*! \class Signal
    \brief An Implementation of Threads Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions 

*/
/*! displays a message first*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, std::shared_ptr<Semaphore> sem2){
  /**
  * @fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, std::shared_ptr<Semaphore> sem2)
  * @brief This function is displayed fiest
  * @param theSemaphore this parameter is used for flow control
  * @param sem2 this parameter is used for flow control
  */
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
}
/*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore, std::shared_ptr<Semaphore> sem2){
    /**
  * @fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, std::shared_ptr<Semaphore> sem2)
  * @brief This function will be executed after delay
  * @param theSemaphore this parameter is used for flow control
  * @param sem2 this parameter is used for flow control
  */
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
  * @param sem2 This parameter is used for flow control
  * @param threadOne Thread one
  * @param threadTwo Thread two
  * @param delay  This integer is used to set duration of sleep for a thread
  */
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem,sem2);
  threadTwo=std::thread(taskOne,sem,sem2);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
