/*
This work is licensed under the  Creative Commons Attribution-ShareAlike 4.0 International Licence.
To view of this licence, visit http://creativecommons.org/licenses/by-sa/4.0/.

*/
/*! \mainapge Lab TWo
 * \file main.cpp
 * \brief An implementation of threads using semafores
 * \param Semaphore This parameter is used for flow control
 * \param numUpdates This integer is used to set no of rendezvous
 * \author Joseph Kehoe, Piotr Artman
 * \date 7 November 2020
 * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence
 * \section desc_sec Description
 * 
 * This is file created for Lab 4.
 * 
 * \section dep_sec Dependencies
 *
 * This code depens on
 * Semaphore header
 * iostread library
 * thread library
 * vector library
 */



#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;


/*! \fn updateTask
 *  \brief An Implementation of Mutual Exclusion using Semaphores. 
 *  Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads 
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
/*!
* \fn Update Task
* @param Semaphore1
* @param numUpdates
*/
void updateTask(std::shared_ptr<Semaphore> Semaphore1, int numUpdates){

 
  for(int i=0;i<numUpdates;i++){
    //UPDATE SHARED VARIABLE HERE!
    Semaphore1->Wait();
    sharedVariable++;
    Semaphore1->Signal();

  }
  
}

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore ( new Semaphore(1));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask, aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}