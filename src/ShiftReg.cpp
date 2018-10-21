#include "mbed.h"
#include "ShiftReg.h"

ShiftReg::ShiftReg(PinName ser, PinName clk) : DSERIAL(ser), CLK(clk) {
    DSERIAL = 0;
    CLK = 0;
}

void ShiftReg::updateOutput(){
    CLK = 1;
    wait(.1);
    CLK = 0;
}
//Writes a bit to the shift register
void ShiftReg::writeBit(int bit){
    if(CLK == 1){
        CLK = 0;
        wait(.01);
    }
    DSERIAL = bit;
    wait(.01);
    CLK = 1;
    wait(.01);
    CLK = 0;
    }

void ShiftReg::on(){ writeBit(1); }
void ShiftReg::off(){ writeBit(0); }