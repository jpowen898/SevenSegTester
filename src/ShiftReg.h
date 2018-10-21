#ifndef SHIFTREG_H
#define SHIFTREG_H

#include <mbed.h>
//#include <DigitalOut.h>

//static char stateArr[8*REGISTER_CNT] = {0};
//static bool hasChanged = false;

class ShiftReg {
protected:
    DigitalOut DSERIAL, CLK;

public:
ShiftReg(PinName ser, PinName clk);
~ShiftReg() { };
void updateOutput();
//Writes a bit to the shift register
void writeBit(int bit);
void on();
void off();
};



#endif