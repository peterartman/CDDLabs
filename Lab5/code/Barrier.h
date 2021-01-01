/*! \mainapge Lab Five
 * \file Barrier.h
 * \brief A header file for Reusable Barier class
 * \author Joseph Kehoe, Piotr Artman
 * \date 30 DEC 2020
 * \copyright This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http: *www.gnu.org/licenses/>.
 * 
 * \section desc_sec Description
 * 
 * The header file for Reusable Barier class
 * This is file created for Lab 5.
 * 
 * \section dep_sec Dependencies
 *
 * This barrier header depends on Semaphore header
 *
 */
#pragma once
#include "Semaphore.h"
class Barrier{
private:
  int numThreads;
  int current_count;
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> turnstile1;
  std::shared_ptr<Semaphore> turnstile2;
public:
  Barrier(int numThreads);
  virtual ~Barrier();
  void wait();
  void phase_one();
  void phase_two(); 
};
/* Barrier.h ends here */