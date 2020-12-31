/*! \mainapge Lab Four
 * \file main.cpp
 * \brief A program that demonstrates Mutual Exclusion using the Semaphore class.
 * \author Joseph Kehoe, Piotr Artman
 * \date 28 DEC 2020
 * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence
 * \section desc_sec Description
 * 
 * This is file created for Lab 4.
 * 
 * \section dep_sec Dependencies
 *
 * This code depens on
 * Semaphore header
 * iostream library
 * thread library
 * vector library
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100; /*!< Detailed description after the member */

int sharedVariable=0; /*!< shared variable to update in mutaual exlusion exercise*/

void updateTask(std::shared_ptr<Semaphore> firstSemafore, int numUpdates){
  for(int i=0;i<numUpdates;i++){
    firstSemafore->Wait();
    sharedVariable++;
    firstSemafore->Signal();

  }
  
}
/*! \fn updateTask 
 *  \brief Displays a message that is split in to 2 sections to show how a rendezvous works
 *  \param firstSemaphore is a semaphore used for mutual exclusion
 *  \param numUpdates numUpdates contains an integer representing information on how many times sharedVariable have to be updated
 */

int main(void){
  std::vector<std::thread> vt(num_threads); /*!< A vector structure initiated for number of threads */
  std::shared_ptr<Semaphore> aSemaphore ( new Semaphore(1)); /*!< A semapore passed to ech thread  */
  /**< Launch the threads  */
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

/*! \fn main
 *  \brief This function implements mutual exclusion and displays two 
 */