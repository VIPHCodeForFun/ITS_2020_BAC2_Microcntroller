#ifndef TIMER_DEFINE_H_
#define TIMER_DEFINE_H_

/*-- General-purpose timer TIM2 ! --*/
#define TIM2_BASE 0x40000000 										// RM0316_Reference_manual p.58
#define TIM2_CR1 (volatile uint32_t *)(TIM2_BASE + 0x00000000) 	// RM0316_Reference_manual p.647
#define TIM2_CR2 (volatile uint32_t *)(TIM2_BASE + 0x00000003)		// RM0316_Reference_manual p.648
// SMCR
// DIER
#define TIM2_SR (volatile uint32_t *)(TIM2_BASE + 0x00000010)		// RM0316_Reference_manual p.654
// EGR
// CCRM1
// CCRM2
// CCER
#define TIM2_CNT (volatile uint32_t *)(TIM2_BASE + 0x00000024) 		// RM0316_Reference_manual p.663
#define TIM2_PSC (volatile uint32_t *)(TIM2_BASE + 0x00000028) 		// RM0316_Reference_manual p.664
#define TIM2_ARR (volatile uint32_t *)(TIM2_BASE + 0x0000002C) 		// RM0316_Reference_manual p.664
#define TIM2_CCR1 (volatile uint32_t *)(TIM2_BASE + 0x00000018) 	// RM0316_Reference_manual p.656
// CCR2
// CCR3
// CCR4
// DCR
// DMAR

/* Basic TIMER 6 p.670*/
#define TIM6_BASE 0x40001000 // p.59
#define TIM6_CR1 (volatile uint32_t *)(TIM6_BASE + 0x00000000)	// TIM6/TIM7 control register 1 (TIMx_CR1) p.677
#define TIM6_CR2 (volatile uint32_t *)(TIM6_BASE + 0x00000004)	// TIM6/TIM7 control register 2 (TIMx_CR2) p.678
#define TIM6_DIER (volatile uint32_t *)(TIM6_BASE + 0x0000000C)	// TIM6/TIM7 DMA/Interrupt enable register (TIMx_DIER) p.679
#define TIM6_SR (volatile uint32_t *)(TIM6_BASE + 0x00000010)	// TIM6/TIM7 status register (TIMx_SR) p.680
#define TIM6_EGR (volatile uint32_t *)(TIM6_BASE + 0x00000014)	// TIM6/TIM7 event generation register (TIMx_EGR) p. 680
#define TIM6_CNT (volatile uint32_t *)(TIM6_BASE + 0x00000024)	// TIM6/TIM7 counter (TIMx_CNT) p.680
#define TIM6_PSC (volatile uint32_t *)(TIM6_BASE + 0x00000028)	// TIM6/TIM7 prescaler (TIMx_PSC) p.681
#define TIM6_ARR (volatile uint32_t *)(TIM6_BASE + 0x0000002C)	// TIM6/TIM7 auto-reload register (TIMx_ARR) p.681









#endif /* TIMER_DEFINE_H_ */
