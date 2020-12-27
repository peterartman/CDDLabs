/*
 *This work is licensed under the  Creative Commons Attribution-ShareAlike 4.0 International Licence.
 *To view of this licence, visit http://creativecommons.org/licenses/by-sa/4.0/.
 */
/
/*! \mainapge Lab One
 * \file helloThreads.cpp
 * \brief A file for lab 1.
 * \author Piotr Artman
 * \date 27 DEC 2020
 * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence,
 * for more info visit http://creativecommons.org/licenses/by-sa/4.0/.
 * \section desc_sec Description
 * 
 * This is file created for Lab 1.
 * 
 * \section dep_sec Dependencies
 *
 * This code depens on: <iostream> library, <thread> library and <vector> library.
 * 
 */
#include <iostream>
#include <thread>
#include <vector>


 static const int num_threads = 10;
/*! \var  int $num_threads
    \brief The number of threads we intend to create
 */
 
 /*! \fn void call_from_thread(int tid)
    \brief This function will be called from a thread
    \param tid the thread number
*/ 
 void call_from_thread(int tid) {
          std::cout << "Launched by thread " << tid << std::endl; 
}


 /*! \fn int main()
     \brief The  main function
    
    Forks off 10 threads using a vector of num_threads std::thread objects.
    Then joins each thread with the main thread and exits.
     \return int 0
   
*/
int main() {

	 std::vector<std::thread> vt(num_threads);
 
          /**< Start of threads */
	 int i=0;
	 for(std::thread& t: vt){
	   t=std::thread(call_from_thread,i++);
	 }
         std::cout << "Launched from the main\n";
 
         /**< Conjunction of threads  */
         for (auto& v :vt){
	   v.join();
         }
 
         return 0;
}


