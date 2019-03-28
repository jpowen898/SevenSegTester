#include <mbed.h>

#include "ShiftReg.h"
#include "ShiftOut.h"
#include "SevenSegment.h"

int main() {
    DigitalOut led(D6);
    Serial ser(USBTX, USBRX);
    SevenSegment test(D11, D12, D13);
    //SevenSegment test(P0_28, P0_8, P0_9);
    /*int digi1 = 0;
    int digi2 = 0;
    int digi3 = 0;
    int digi4 = 0;
    const int BLANK = 34;*/
    while(1) {
        led = 0;
        test.clear();
        for (int num = -220; num <= 9999; num++){
            wait(.05);
            test.displayFourNums(num);
            led = 1 ^ led;
        }
    }
}