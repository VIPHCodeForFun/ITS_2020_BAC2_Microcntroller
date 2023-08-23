#ifndef TIMER_DEFINE_H_
#define TIMER_DEFINE_H_

/**--- TIMER p.536 ------------------------------
 */
#define TIMER_BASE 0x40054000 // Table p.541
// 0x00 TIMEHW Write to bits 63:32 of time always write timelw before timehw
// 0x04 TIMELW Write to bits 31:0 of time writes do not get copied to time until timehw is written
#define TIMEHR (volatile uint32_t *)(TIMER_BASE + 0x00000008) // 0x08 TIMEHR Read from bits 63:32 of time always read timelr before timehr
#define TIMELR (volatile uint32_t *)(TIMER_BASE + 0x0000000c) // 0x0c TIMELR Read from bits 31:0 of time

/**--- Watchdog p.536 ------------------------------
 */
#define WATCHDOG_BASE 0x40058000                               // Table p.548
#define TICK (volatile uint32_t *)(WATCHDOG_BASE + 0x0000002c) // 0x2c TICK Controls the tick generator

#endif /* TIMER_DEFINE_H_ */