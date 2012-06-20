#ifndef __WORLDPACKET_H
#define __WORLDPACKET_H

#include "common.h"

class WorldPacket 
{
    public:
        WorldPacket(){}
        void Initialize(uint16 opcode){}
        uint16 GetOpcode() const { return m_opcode; }
        void SetOpcode(uint16 opcode) { m_opcode = opcode; }
    protected:
        uint16 m_opcode;
};
#endif
