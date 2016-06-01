#ifndef _BOARD_H_
#define _BOARD_H_

#define ENTRADAS        "/dev/dio/in/0"
#define SALIDAS         "/dev/dio/out/0"

#if (edu_ciaa_nxp == BOARD)
#define LED_RGB_ROJO    0x01
#define LED_RGB_VERDE   0x02
#define LED_RGB_AZUL    0x04
#define LED_AMARILLO    0x08
#define LED_ROJO        0x10
#define LED_VERDE       0x20

#define LED_R           LED_RGB_ROJO
#define LED_G           LED_RGB_VERDE
#define LED_B           LED_RGB_AZUL
#define LED_1           LED_AMARILLO
#define LED_2           LED_ROJO
#define LED_3           LED_VERDE

#define TECLA_1         0x01
#define TECLA_2         0x02
#define TECLA_3         0x04
#define TECLA_4         0x08

#define TEC_1           TECLA_1
#define TEC_2           TECLA_2
#define TEC_3           TECLA_3
#define TEC_4           TECLA_4

#define PULS_0          TECLA_1
#define PULS_1          TECLA_2
#define PULS_2          TECLA_3
#define PULS_3          TECLA_4
#endif

#endif