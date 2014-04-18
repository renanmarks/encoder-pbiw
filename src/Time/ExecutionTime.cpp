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
 * File:   ExecutionTime.cpp
 * Author: renato
 * 
 * Created on 18 de Janeiro de 2012, 16:47
 */

#include "ExecutionTime.h"
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <iomanip>
//#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>

namespace Time {

    void
    ExecutionTime::start(){
        t0 = clock();
        //----------------------------
        // Inicio da medicao do tempo.
        gettimeofday(&begin, NULL);
    }
    
    void
    ExecutionTime::finish(){
        double tempo_gasto;
        
        tf = clock();
        tempo_gasto = ( (double) (tf - t0) ) / CLOCKS_PER_SEC;
        
        if(tempo_gasto > 0){
            printf("\n\nPrint Tempo gasto: %.16lf s\n", tempo_gasto);       
            std::cout << "Cout Tempo gasto: " << std::setprecision(10) << tempo_gasto << " s" << std::endl;
        }
        else {
            tempo_gasto = (( (double) (tf - t0) )/ ((double)CLOCKS_PER_SEC/1000));
               
            printf("\n\nPrint Tempo gasto: %.16lf m\n", tempo_gasto);
            std::cout << "Cout Tempo gasto: " << std::setprecision(10) << tempo_gasto << " m" << std::endl;
        }
        
        std::cout << "-------------------------------\n";
        
        //------------------------------------------------

        //Fim da medicao do tempo.
        gettimeofday(&end, NULL);

        //ANALISE DO TEMPO
        total = (end.tv_sec - begin.tv_sec) * 1000000 +
        (end.tv_usec - begin.tv_usec);

        getrusage(0,&time);
 
        printf("Time used by user: %.4lf seconds. \n",
        time.ru_utime.tv_sec + time.ru_utime.tv_usec*0.000001);

        printf("Time used by system: %.4lf seconds. \n",
        time.ru_stime.tv_sec + time.ru_stime.tv_usec*0.000001);

        printf("Total time, system time added to the user time: %.4lf seconds. \n",
        time.ru_stime.tv_sec + time.ru_stime.tv_usec*0.000001 +
        time.ru_utime.tv_sec + time.ru_utime.tv_usec*0.000001);

        printf("Time clock: %.4lf seconds\n\n\n", total/1000000);
        
 

    }
    
   
  

}