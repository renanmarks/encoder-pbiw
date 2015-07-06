/* 
 * File:   Field.cpp
 * Author: renato
 * 
 * Created on January 4, 2013, 4:31 PM
 */

#include "Field.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    
    Field::Field() {
    }

    Field::Field(int f, int s):first(f),size(s) {
    }

    Field::~Field() {
    }
    
    int
    Field::getFirstField(){
        return this->first;
    }
    
    void
    Field::setFirstField(int first){
        this->first = first;
    }
    
    int
    Field::getSizeField(){
        return this->size;
    }
    
    void
    Field::setSizeField(int size){
        this->size;
    }
}

}

}
