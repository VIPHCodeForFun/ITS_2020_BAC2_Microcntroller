  idf_component_register(
    SRCS "led-blink-with-pwm.c"
         "../hal/pin-hal.c"
         "../hal/timer-hal.c"
         "../hal/pwm-hal.c"
    INCLUDE_DIRS ".")


    
