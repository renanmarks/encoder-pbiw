/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
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

