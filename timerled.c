/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== timerled.c ========
 */
/* For usleep() */
#include <unistd.h>

#include <stdlib.h>
#include <ti/devices/cc32xx/inc/hw_types.h>
#include <stddef.h>
#include <ti/drivers/GPIO.h>
/* Driver Header files */

#include <ti/devices/cc32xx/driverlib/pin.h>
#include <ti/drivers/Timer.h>

/* Board Header file */
#include "Board.h"
int T =2000;

int flag =0;

Timer_Handle timer0;
 Timer_Params params;

/* Callback used for toggling the LED. */
void timerCallback(Timer_Handle myHandle);
void gpioButtonFxn0(uint_least8_t index);


/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{

    /* Call driver init functions */
    GPIO_init();

    GPIO_setConfig(Board_GPIO_BUTTON0, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);



        /* install Button callback */
        GPIO_setCallback(Board_GPIO_BUTTON0, gpioButtonFxn0);

        /* Enable interrupts */
        GPIO_enableInt(Board_GPIO_BUTTON0);
    Timer_init();

    /* Configure the LED pin */
    GPIO_setConfig(Board_GPIO_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Turn off user LED */
    GPIO_write(Board_GPIO_LED0, Board_GPIO_LED_OFF);

    /* Setting up the timer in continuous callback mode that calls the callback
     * function every 1,000,000 microseconds, or 1 second.
     */
    Timer_Params_init(&params);
    params.period = T;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timerCallback;

    timer0 = Timer_open(Board_TIMER0, &params);

    if (timer0 == NULL) {
        /* Failed to initialized timer */
        while (1) {}
    }

    if (Timer_start(timer0) == Timer_STATUS_ERROR) {
        /* Failed to start timer */
        while (1) {}
    }
while(1)

{
sleep(1);
    flag=0;
}
    return (NULL);
}

/*
 * This callback is called every 1,000,000 microseconds, or 1 second. Because
 * the LED is toggled each time this function is called, the LED will blink at
 * a rate of once every 2 seconds.
 * */
void timerCallback(Timer_Handle myHandle)
{
    GPIO_toggle(Board_GPIO_LED0);
}
void gpioButtonFxn0(uint_least8_t index)
{
    //for a 500 Hz Frequency we Have T=2000 and duty =100
    //for 1Khz we have T=1000 and duty =100
    //1.5KHz Frequency we have a T=666;
    //2khz Frequency he have a T =500
    //3KHz Frequency we have a T =333


    if(T==2000 && flag ==0 )
    {
        T=1000;

        flag=1;

        Timer_close(timer0);

         Timer_Params_init(&params);
     params.period = T;
     params.periodUnits = Timer_PERIOD_US;
     params.timerMode = Timer_CONTINUOUS_CALLBACK;
     params.timerCallback = timerCallback;

     timer0 = Timer_open(Board_TIMER0, &params);
     Timer_start(timer0);

    }

    if(T==1000 && flag ==0 )
    {
        T=666;

        flag=1;
        Timer_close(timer0);

              Timer_Params_init(&params);
          params.period = T;
          params.periodUnits = Timer_PERIOD_US;
          params.timerMode = Timer_CONTINUOUS_CALLBACK;
          params.timerCallback = timerCallback;

          timer0 = Timer_open(Board_TIMER0, &params);
          Timer_start(timer0);
    }
    if(T==666 && flag ==0 )
    {
        T=500;

        flag=1;
        Timer_close(timer0);

              Timer_Params_init(&params);
          params.period = T;
          params.periodUnits = Timer_PERIOD_US;
          params.timerMode = Timer_CONTINUOUS_CALLBACK;
          params.timerCallback = timerCallback;

          timer0 = Timer_open(Board_TIMER0, &params);
          Timer_start(timer0);
    }
    if(T==500 && flag ==0 )
    {
        T=333;

        flag=1;
        Timer_close(timer0);

              Timer_Params_init(&params);
          params.period = T;
          params.periodUnits = Timer_PERIOD_US;
          params.timerMode = Timer_CONTINUOUS_CALLBACK;
          params.timerCallback = timerCallback;

          timer0 = Timer_open(Board_TIMER0, &params);
          Timer_start(timer0);
    }

    if(T==333 && flag ==0 )
    {
        T=2000;

        flag=1;
        Timer_close(timer0);

              Timer_Params_init(&params);
          params.period = T;
          params.periodUnits = Timer_PERIOD_US;
          params.timerMode = Timer_CONTINUOUS_CALLBACK;
          params.timerCallback = timerCallback;

          timer0 = Timer_open(Board_TIMER0, &params);
          Timer_start(timer0);
    }

}

