/*
 *This work is licensed under the  Creative Commons Attribution-ShareAlike 4.0 International Licence.
 *To view of this licence, visit http://creativecommons.org/licenses/by-sa/4.0/.
 */
/*! 
 * \file main.cpp
 * \author Piotr Artman
 * \date 7 November 2020
 *  * \copyright Creative Commons Attributuion-ShareAlike 4.0 International Licence,
 * for more info visit http://creativecommons.org/licenses/by-sa/4.0/.
 * \brief A file with main() funtion for Lab 1.
 * 
 * \section desc_sec Description
 * 
 * This is file created for Lab 1.
 * 
 * \section dep_sec Dependencies
 *
 * This code depens on stdio.h header
 * 
 */
 
#include <stdio.h>
int main(void)
{
  int i;
  for(i=0;i<10;i++)
    printf("%d",i);
  return 0;
}
/*! \fn  int main(void)
    \brief This funtion prints integers from 0 to 9.
    \returns 0
*/
