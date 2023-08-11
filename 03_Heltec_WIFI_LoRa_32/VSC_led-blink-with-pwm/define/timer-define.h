#ifndef TIMER_DEFINE_H_
#define TIMER_DEFINE_H_

#include "../define/pin-define.h" // for REG(x)

/* Timer 0 configuration and control registers p.504*/
/** Timer 0 configuration register
TIMGn_Tx_EN             TIMGn_Tx_EN When set, the timer x time-base counter is enabled. (R/W)
TIMGn_Tx_INCREASE       TIMGn_Tx_INCREASE When set, the timer x time-base counter will increment every clock tick.
                        When cleared, the timer x time-base counter will decrement. (R/W)
TIMGn_Tx_AUTORELOAD     When set, timer x auto-reload at alarm is enabled. (R/W)
TIMGn_Tx_DIVIDER        Timer x clock (Tx_clk) prescale value. (R/W)
TIMGn_Tx_EDGE_INT_EN    When set, an alarm will generate an edge type interrupt. (R/W)
TIMGn_Tx_LEVEL_INT_EN   When set, an alarm will generate a level type interrupt. (R/W)
TIMGn_Tx_ALARM_EN       When set, the alarm is enabled. This bit is automatically cleared once an alarm occurs. (R/W)
*/
#define TIMG0_T0CONFIG_REG REG(0x3ff5F000)
/** TIMGn_TxLO_REG
    After writing to TIMGn_TxUPDATE_REG, the low 32 bits of the time -
    base counter of timer x can be read here.(RO)*/
#define TIMG0_T0LO_REG REG(0x3FF5F004)
/** TIMGn_TxHI_REG
    After writing to TIMGn_TxUPDATE_REG, the high 32 bits of the time-base counter
    of timer x can be read here. (RO)*/
#define TIMG0_T0HI_REG REG(0x3FF5F008)
/** TIMGn_TxUPDATE_REG
    Write any value to trigger a timer x time-base counter value update (timer x
    current value will be stored in registers above). (WO)*/
#define TIMG0_T0UPDATE_REG REG(0x3FF5F00C)

#endif /* TIMER_DEFINE_H_ */