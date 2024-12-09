#include "stm32f4xx.h"

#define TIM2_CLK_ENABLE()    (RCC->APB1ENR |= RCC_APB1ENR_TIM2EN)
#define GPIOA_CLK_ENABLE()   (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN)

#define SERVO_PIN            0  // PA0 (TIM2_CH1)

// Timer parameters for 50Hz PWM
#define PWM_PERIOD           20000  // 20 ms (50 Hz)
#define MIN_PULSE_WIDTH      500    // 0.5 ms (0 degrees)
#define MAX_PULSE_WIDTH      2500   // 2.5 ms (180 degrees)

void SetServoPosition(float angle);

int main(void) {
    // 1. Enable clocks
    GPIOA_CLK_ENABLE();
    TIM2_CLK_ENABLE();

    // 2. Configure PA0 as alternate function (TIM2_CH1)
    GPIOA->MODER &= ~(0x3 << (SERVO_PIN * 2));  // Clear mode bits
    GPIOA->MODER |= (0x2 << (SERVO_PIN * 2));   // Set to alternate function mode
    GPIOA->AFR[0] &= ~(0xF << (SERVO_PIN * 4)); // Clear alternate function bits
    GPIOA->AFR[0] |= (0x1 << (SERVO_PIN * 4));  // Set AF1 (TIM2_CH1)

    // 3. Configure TIM2 for PWM
    TIM2->PSC = 84 - 1;                         // Prescaler: Clock down to 1 MHz (84 MHz / 84)
    TIM2->ARR = PWM_PERIOD - 1;                 // Auto-reload: Set period to 20 ms
    TIM2->CCMR1 |= (0x6 << TIM_CCMR1_OC1M_Pos); // PWM mode 1 (active while counter < CCR1)
    TIM2->CCMR1 |= TIM_CCMR1_OC1PE;             // Enable output preload
    TIM2->CCER |= TIM_CCER_CC1E;                // Enable channel 1 output
    TIM2->CCR1 = MIN_PULSE_WIDTH;               // Initial duty cycle (0 degrees)
    TIM2->CR1 |= TIM_CR1_CEN;                   // Enable TIM2 counter

    // 4. Servo control loop
    while (1) {
        for (float angle = 0; angle <= 180; angle += 10) {
            SetServoPosition(angle);            // Move servo to the desired angle
            for (volatile int i = 0; i < 1000000; i++); // Simple delay
        }
        for (float angle = 180; angle >= 0; angle -= 10) {
            SetServoPosition(angle);            // Move servo to the desired angle
            for (volatile int i = 0; i < 1000000; i++); // Simple delay
        }
    }
}

void SetServoPosition(float angle) {
    // Constrain angle to [0, 180] and calculate pulse width
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;

    uint32_t pulseWidth = MIN_PULSE_WIDTH + (angle / 180.0) * (MAX_PULSE_WIDTH - MIN_PULSE_WIDTH);
    TIM2->CCR1 = pulseWidth; // Update the compare register for PWM duty cycle
}
