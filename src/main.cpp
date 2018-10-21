#include <mbed.h>
#include <SevenSegment.h>
#include "ShiftReg.h"


int main() {
    DigitalOut led(D0);
    // put your setup code here, to run once:
    SevenSegment test(D14, D15);
    //ShiftReg test(D14, D15);
    while(1) {
        //test.on();
        
        for (int i = 0; i < 8; i++){
            test.off();
        }
        
        test.off();
        test.off();
        test.on();
        /*  wait(.5);
        test.on();
        wait(.5);
        test.off();
        test.off();*/
        wait(2);
        for (int i = 0; i < 8; i++){
            test.off();
            wait(.5);
        }
        test.clear();
        //test.off();
        // put your main code here, to run repeatedly:
    }
}