#include <stdint.h>
/*******************************
Hardware timer setup library.
*******************************/

/*
 * Enumeration for all 8-bit timer operation modes.
 */
typedef enum __attribute__ ((__packed__))
                {TIMER8_WGM_NORMAL,
                TIMER8_WGM_FASTPWM_8BIT, TIMER8_WGM_FASTPWM_OCRA,
                TIMER8_WGM_PCPWM_8BIT,  TIMER8_WGM_PCPWM_OCRA,
                TIMER8_WGM_CTC} timer8_wgm_t;

/*
 * Enumeration for all 16-bit timer operation modes.
 */
typedef enum  __attribute__ ((__packed__))
                {TIMER16_WGM_NORMAL,
                TIMER16_WGM_PCPWM_8BIT, TIMER16_WGM_PCPWM_9BIT,
                TIMER16_WGM_PCPWM_10BIT, TIMER16_WGM_PCPWM_ICR,
                TIMER16_WGM_PCPWM_OCRA,
                TIMER16_WGM_CTC_OCRA, TIMER16_WGM_CTC_ICR,
                TIMER16_WGM_PFCPWM_ICR, TIMER16_WGM_PFCPWM_OCRA,
                TIMER16_WGM_FASTPWM_8BIT, TIMER16_WGM_FASTPWM_9BIT,
                TIMER16_WGM_FASTPWM_10BIT,TIMER16_WGM_FASTPWM_ICR,
                TIMER16_WGM_FASTPWM_OCRA} timer16_wgm_t;

/*
 * Enumeration for selecting COM bits. Contains the possibilities defined for
 * Fast PWM on Channel A, but can be used for any mode or channel. Read the
 * datasheet for more information, use with care.
 */
typedef enum __attribute__ ((__packed__))
                {TIMER8_COM_DISCONNECTED, TIMER8_COM_TOGGLE,
                TIMER8_COM_NONINVERTED, TIMER8_COM_INVERTED} timer_com_t;

typedef enum __attribute__ ((__packed__))
              {TIMER16_PRESCALER_STOPPED, TIMER16_PRESCALER_1,
                TIMER16_PRESCALER_8, TIMER16_PRESCALER_64,
                TIMER16_PRESCALER_256, TIMER16_PRESCALER_1024,
                TIMER16_PRESCALER_EXT_FALLING, TIMER16_PRESCALER_EXT_RISING}
              timer_prescaler_t;

/*
 * Defines for 8-bit Timers Interrupts
 */
#define TIMER8_INTERRUPT_TO  (1<<0) //Timer Overflow Interrupt, TOIE
#define TIMER8_INTERRUPT_OCA (1<<1) //Output Compare Match A, OCIEA
#define TIMER8_INTERRUPT_OCB (1<<2) //Output Compare Match B, OCIEB

/*
 * Defines for 16-bit Timers Interrupts
 */
#define TIMER16_INTERRUPT_TO  (1<<0) //Timer Overflow Interrupt, TOIE
#define TIMER16_INTERRUPT_OCA (1<<1) //Output Compare Match A, OCIEA
#define TIMER16_INTERRUPT_OCB (1<<2) //Output Compare Match B, OCIEB
#define TIMER16_INTERRUPT_IC  (1<<5) //Input Capture, ICIE


/*
 * Initialize 8-bit Timer 0.
 */
void Timer0_initialize(timer8_wgm_t wgm, timer_com_t comA, timer_com_t comB,
                        uint8_t interrupts);


/*
 * Initialize 16-bit Timer 1.
 */
void Timer1_initialize(timer16_wgm_t wgm, timer_com_t comA, timer_com_t comB,
                        uint8_t interrupts);


/*
 * Initialize 8-bit Timer 2.
 */
void Timer2_initialize(timer8_wgm_t wgm, timer_com_t comA, timer_com_t comB,
                        uint8_t interrupts);


/*
 * Start/change prescaler on Timer0.
 */
void Timer0_prescaler(timer_prescaler_t prescaler);


/*
 * Start/change prescaler on Timer0.
 */
void Timer1_prescaler(timer_prescaler_t prescaler);


/*
 * Start/change prescaler on Timer0.
 */
void Timer2_prescaler(timer_prescaler_t prescaler);
