#include <mbed.h>

#include "ShiftReg.h"
#include "ShiftOut.h"

int main() {
    DigitalOut led(D0);
    // put your setup code here, to run once:
    //SevenSegment test(D14, D15);
    //ShiftReg test(D14, D15);
    ShiftOut test(D0, D1, D2, NC, NC);
    while(1) {
        //test.on();
        test.writeBit(1);
        for (int i = 0; i < 16; i++){
            //wait(.5);
            test.writeBit(0);
        }
        //wait(.5);
        //test.off();
        // put your main code here, to run repeatedly:
    }
}