/*****************************************************************************/
/*                                                                           */
/*                                alignment.h                                */
/*                                                                           */
/*                             Address aligment                              */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 2011,      Ullrich von Bassewitz                                      */
/*                Roemerstrasse 52                                           */
/*                70794 Filderstadt                                          */
/* EMail:         uz@cc65.org                                                */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/



#ifndef ALIGNMENT_H
#define ALIGNMENT_H



/* common */
#include "inline.h"



/*****************************************************************************/
/*                                   Data                                    */
/*****************************************************************************/



/* The C file contains a list of primes up to 256, so we can factorize numbers
 * up to 0x10000 or somewhat more. The FactorizedNumber structure below
 * contains the powers of the primes from the prime table. The size of the
 * table (= the number of primes contained therein) is the constant below.
 */
#define PRIME_COUNT     54




/* A number together with its prime factors */
typedef struct FactorizedNumber FactorizedNumber;
struct FactorizedNumber {
    unsigned long       Value;                  /* The actual number */
    unsigned char       Powers[PRIME_COUNT];    /* Powers of the factors */
};



/*****************************************************************************/
/*                                   Code                                    */
/*****************************************************************************/



void Factorize (unsigned long Value, FactorizedNumber* F);
/* Factorize a value between 1 and 0x10000. */

FactorizedNumber* LCM (const FactorizedNumber* Left,
                       const FactorizedNumber* Right,
                       FactorizedNumber* Res);
/* Calculate the least common multiple of two factorized numbers and return
 * the result.
 */

unsigned long AlignAddr (unsigned long Addr, unsigned long Alignment);
/* Align an address to the given alignment */



/* End of alignment.h */

#endif


