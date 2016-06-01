#include "os.h"               /* <= operating system header */
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaak.h"            /* <= ciaa kernel header */
#include "board.h"

int main(void)
{
   /* Starts the operating system in the Application Mode 1 */
   /* This example has only one Application Mode */
   StartOS(Normal);

   /* StartOs shall never returns, but to avoid compiler warnings or errors
    * 0 is returned */
   return 0;
}

void ErrorHook(void)
{
   ShutdownOS(0);
}

static int32_t leds;

TASK(Inicializacion)
{
   ciaak_start();
   leds = ciaaPOSIX_open(SALIDAS, ciaaPOSIX_O_RDWR);
   SetRelAlarm(ActivarPeriodica, 350, 250);
   TerminateTask();
}

TASK(Periodica)
{
   uint8_t salidas;

   ciaaPOSIX_read(leds, &salidas, 1);
   salidas ^= LED_VERDE;
   ciaaPOSIX_write(leds, &salidas, 1);

   TerminateTask();
}