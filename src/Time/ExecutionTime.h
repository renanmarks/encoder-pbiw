/* 
 * File:   ExecutionTime.h
 * Author: renato
 *
 * Created on 18 de Janeiro de 2012, 16:47
 */

#ifndef EXECUTIONTIME_H
#define	EXECUTIONTIME_H

#include <ctime>
#include<sys/time.h>
#include <sys/resource.h>

namespace Time {

    class ExecutionTime {
        public:
            void start();
            void finish();
  
            
        private:
            clock_t t0;
            clock_t tf;
            // --------------------
            struct rusage time;
            struct timeval begin, end;
            double total;
    };
}

#endif	/* EXECUTIONTIME_H */

