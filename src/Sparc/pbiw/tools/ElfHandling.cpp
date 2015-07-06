/* 
 * File:   ElfHandling.cpp
 * Author: renato
 * 
 * Created on January 28, 2013, 3:23 PM
 */
#include <iostream>
#include <string.h>

#include "ElfHandling.h"
#include "ParseFile.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    ElfHandling::ElfHandling(string fileName):file(fileName) {
    }

    ElfHandling::ElfHandling(Encode* encoded, string fileName):encode(encoded), file(fileName) {
    }

    ElfHandling::~ElfHandling() {
    }

    void
    ElfHandling::setEncode(Encode* encode) {
        this->encode = encode;
    }

    void
    ElfHandling::clearSectionText() {
        elfio elf;
        elf.load(file);

        for (int i = 0; i < elf.sections.size(); ++i) {
            if (!strcasecmp(elf.sections[i]->get_name().c_str(), ".text")) {
                elf.sections[i]->set_data('\0', 0);
                elf.save(file);
            }
        }
    }

    Encode*
    ElfHandling::getEncode() {
        return encode;
    }

    void
    ElfHandling::setCodeOnELF(string data, string section, int alignment, int operation) {
        elfio elf;
        elf.load(file);

        int index;
        for (int i = 0; i < elf.sections.size(); ++i) {
            if (!strcasecmp(elf.sections[i]->get_name().c_str(), section.c_str())) {
                index = elf.sections[i]->get_index();
                break;
            }
        }

        elf.sections[index]->set_addr_align(alignment);
        elf.sections[index]->set_data(data);

        int index_seg = setSegmentSize(elf);

//        if (operation) {
//            elf.segments[index_seg]->set_memory_size(elf.segments[index_seg]->get_memory_size() - data.length());
//            elf.segments[index_seg]->set_file_size(elf.segments[index_seg]->get_file_size() - data.length());
//        } else {
//            elf.segments[index_seg]->set_memory_size(elf.segments[index_seg]->get_memory_size() + data.length() * 0.25 * (4 - alignment));
//            elf.segments[index_seg]->set_file_size(elf.segments[index_seg]->get_file_size() + data.length() * 0.25 * (4 - alignment));
//        }

        elf.save(file);
    }

    int
    ElfHandling::setSegmentSize(elfio& elf) {
        for (int i = 0; i < elf.segments.size(); ++i) {
            for (int j = 0; j < elf.segments[i]->get_sections_num(); ++j) {
                int index_section = elf.segments[i]->get_section_index_at(j);

                if (!elf.sections[index_section]->get_name().compare(".text")) {
                    return i;
                }
            }
        }
    }

    void
    ElfHandling::setDecodedInstructions(OriginalInstDeque& originalInstructions, int alignment) {
        OriginalInstDeque::iterator it;
        string data = "";

        for (it = originalInstructions.begin(); it < originalInstructions.end(); it++) {
            data += it->getHexInstruction();
        }

        setCodeOnELF(data, ".text", alignment, decoding);
    }
    
    void
    ElfHandling::setEncodedInstructions() {
        EncInstDeque dequeInst = this->encode->getEncodedInstructions();
        EncInstDeque::iterator it;
        string text = "";

        for (it = dequeInst.begin(); it < dequeInst.end(); it++) {
            text += (*it)->getHexEncodeInstruction();
        }

        setCodeOnELF(text, ".text", encode->getInstrucionLayout().getAlign(), encoding);
    }

    void
    ElfHandling::addEncodedPatterns() {
        elfio elf;
        elf.load(file);

        section* sec = elf.sections.add(".pattern");
        sec->set_type(SHT_PROGBITS);
        sec->set_flags(SHF_ALLOC | SHF_EXECINSTR);
        sec->set_addr_align(0x3);
        
        EncPattDeque dequePatt = this->encode->getEncodedPatterns();
        EncPattDeque::iterator it;
        
        string text = "";

        for (it = dequePatt.begin(); it < dequePatt.end(); it++) {
            text += (*it)->getHexEncodePattern();
        }

        sec->set_data(text);
        elf.save(file);
    }
    
    void
    ElfHandling::addLayoutSection() {
        elfio elf;
        elf.load(file);

        section* sec = elf.sections.add(".layout");
        sec->set_type(SHT_PROGBITS);
        sec->set_flags(SHF_ALLOC | SHF_EXECINSTR);
        sec->set_addr_align(0x1);
        
        EncPattDeque dequePatt = this->encode->getEncodedPatterns();
        EncPattDeque::iterator it;
        
        string text = "";

        for (it = dequePatt.begin(); it < dequePatt.end(); it++) {
            text += (*it)->getHexEncodePattern();
        }

        sec->set_data(encode->encodeLayout());
        elf.save(file);
    }

}

}

}
