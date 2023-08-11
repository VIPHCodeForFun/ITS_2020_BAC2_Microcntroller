#ifndef PWM_DEFINE_H_
#define PWM_DEFINE_H_

#include "../define/pin-define.h" // for REG(x)

/** clock gate for peripherals p. 110
DPORT_PWM1_CLK_EN PWM1 module. (R/W) [17]
DPORT_PWM0_CLK_EN PWM0 module. (R/W) [20]
*/
#define DPORT_PERIP_CLK_EN_REG REG(0x3FF000C0)
/** Configuration register 0 for low-speed channel 0  R/W
 */
#define LEDC_LSCH0_CONF0_REG REG(0x3FF590A0)

#endif /* PWM_DEFINE_H_ */