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
        for (int num = 0; num < 9999; num=num+10){
            wait(.05);
                /*digi4 = (num < 1000) ? BLANK : (num/1000);
                digi3 = (num < 100) ? BLANK : ((num-(num/1000)*1000)/100);
                digi2 = (num < 10) ? BLANK : (num-(((num-(num/1000)*1000)/100)*100-(num/1000)*1000))/10;
                digi1 = num%10;
            ser.printf("i = %d\r\n   1's = %d\r\n  10's = %d \r\n 100's = %d\r\n1000's = %d\r\n", num, digi1, digi2, digi3, digi4);
            test.displayOneNum(digi1);
            test.displayOneNum(digi2);
            test.writeBit2(digi3);
            test.displayOneNum(digi4);*/
            test.displayFourNums(num);
            led = 1 ^ led;
        }
    }
}