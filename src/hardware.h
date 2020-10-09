#ifdef ENV_DEV
#define PIN_EYES_LED_1 13
#define PIN_EYES_LED_2 12
#define PIN_BUTTON 2
#endif

#ifdef ENV_PROD
#define PIN_EYES_LED_1 PB3
#define PIN_EYES_LED_2 PB4
#define PIN_BUTTON PB1
#endif
