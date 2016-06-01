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
static int32_t teclas;

TASK(Inicializacion)
{
   ciaak_start();
   leds = ciaaPOSIX_open(SALIDAS, ciaaPOSIX_O_RDWR);
   teclas = ciaaPOSIX_open(ENTRADAS, ciaaPOSIX_O_RDONLY);
   SetRelAlarm(ActivarPeriodica, 350, 50);
   TerminateTask();
}

TASK(Periodica)
{
   uint8_t actual;
   uint8_t salidas;
   static uint8_t entradas;

   ciaaPOSIX_read(leds, &salidas, 1);
   ciaaPOSIX_read(teclas, &actual, 1);
   actual = ~actual;

   salidas ^= LED_VERDE;
   if (((actual ^ entradas) & (actual & TECLA_1)))
   {
      ActivateTask(LedAzul);
   } 
   ciaaPOSIX_write(leds, &salidas, 1);


   if (((actual ^ entradas) & (actual & TECLA_2)))
   {
      ActivateTask(LedAmarillo);
   }
   ciaaPOSIX_write(leds, &salidas, 1);

   entradas = actual;
   TerminateTask();
}

TASK(LedAzul)
{
   uint8_t salidas;

   ciaaPOSIX_read(leds, &salidas, 1);
   salidas ^= LED_RGB_AZUL;
   ciaaPOSIX_write(leds, &salidas, 1);

   TerminateTask();
}

TASK(LedAmarillo)
{
   uint8_t salidas;

   ciaaPOSIX_read(leds, &salidas, 1);
   salidas ^= LED_AMARILLO;
   ciaaPOSIX_write(leds, &salidas, 1);

   TerminateTask();
}
