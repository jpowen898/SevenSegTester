#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H
#include <mbed.h>

#define REGISTER_CNT 1 

class SevenSegment
{
    private:
    char segment [33][8] =  {{1,1,1,1,1,1,0,0}, //#0  //{A,B,C,D,E,F,G,dec}
                            {0,1,1,0,0,0,0,0}, //#1
                            {1,1,0,1,1,0,1,0}, //#2
                            {1,1,1,1,0,0,1,0}, //#3
                            {0,1,1,0,0,1,1,0}, //#4
                            {1,0,1,1,0,1,1,0}, //#5
                            {1,0,1,1,1,1,1,0}, //#6
                            {1,1,1,0,0,0,0,0}, //#7
                            {1,1,1,1,1,1,1,0}, //#8
                            {1,1,1,1,0,1,1,0}, //#9
                            {1,1,1,0,1,1,1,0}, //#A
                            {0,0,1,1,1,1,1,0}, //#b
                            {1,0,0,1,1,1,0,0}, //#C
                            {0,1,1,1,1,0,1,0}, //#d
                            {1,0,0,1,1,1,1,0}, //#E
                            {1,0,0,0,1,1,1,0}, //#F
                            {1,1,1,1,1,1,0,1}, //#0.  //{A,B,C,D,E,F,G,dec}
                            {0,1,1,0,0,0,0,1}, //#1.
                            {1,1,0,1,1,0,1,1}, //#2.
                            {1,1,1,1,0,0,1,1}, //#3.
                            {0,1,1,0,0,1,1,1}, //#4.
                            {1,0,1,1,0,1,1,1}, //#5.
                            {1,0,1,1,1,1,1,1}, //#6.
                            {1,1,1,0,0,0,0,1}, //#7.
                            {1,1,1,1,1,1,1,1}, //#8.
                            {1,1,1,1,0,1,1,1}, //#9.
                            {1,1,1,0,1,1,1,1}, //#A.
                            {0,0,1,1,1,1,1,1}, //#b.
                            {1,0,0,1,1,1,0,1}, //#C.
                            {0,1,1,1,1,0,1,1}, //#d.
                            {1,0,0,1,1,1,1,1}, //#E.
                            {1,0,0,0,1,1,1,1}, //#F.
                            {0,0,0,0,0,0,0,1}};
    DigitalOut DSERIAL, RCLK, SRCLK; 
    public:
    SevenSegment(PinName ser, PinName srclk, PinName rclk);
    ~SevenSegment();
    void displayOneNum(const int num);
    bool displayFourNums(const int num);
    bool displayTwoNums(const int num);
    bool clear();
    void on();
    void off();

    void updateRegister();
    void updateOutput();
    void writeBit(unsigned char bit);
    void writeArray(char arr[8*REGISTER_CNT]);
};
#endif