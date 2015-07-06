/* 
 * File:   Field.h
 * Author: renato
 *
 * Created on January 4, 2013, 4:31 PM
 */

#ifndef PBIWSPARC_TOOLS_FIELD_H
#define	PBIWSPARC_TOOLS_FIELD_H

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    
    class Field {
    public:
        Field();
        Field(int f, int s);
        virtual ~Field();
        
        virtual int getFirstField();
        virtual void setFirstField(int first);
        
        virtual int getSizeField();
        virtual void setSizeField(int size);
        
    private:
        int first;
        int size;
    };
}

}

}
#endif	/* FIELD_H */

