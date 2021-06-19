/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"




// main function
int main()
{
    // Initialise the digital pin PA_5 as an output
    DigitalOut led(PA_5);
    // Initialise the digital button PC_13 as an input
    DigitalIn button(PC_13);
    // declare pc object for console output
    Serial pc(SERIAL_TX,SERIAL_RX);
    //counter stores the number of button presses
    int counter=0;
    //configure button with internal pull up resistor?
    button.mode(PullUp);  
    // boolean that stores whether the button has been pressed
    bool buttonpress=false;
    //while loop to obtain input
    while (true) {
        /* if statement to change the previous boolean, sleep_for is used to
        prevent multiple inputs from being counted due to bouncing*/
        if(!button)
        {
            ThisThread::sleep_for(400);
            buttonpress=!buttonpress;
            
        }
        // resets buttonpress boolean to false for next cycle and increase the counter while printing it to console
        if(buttonpress==true)
        {
            buttonpress=false;
            counter=counter+1;
            pc.printf("counter is %d \n",counter);
       }
       //turn led on after 10 button presses, otherwise it's kept off
        if(counter>=10)
        {
        led=1;
        }
        else
        {
            led=0;
        }
    }
}
