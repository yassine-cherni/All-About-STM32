#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

// Pin Definitions
#define START_BUTTON_PIN GPIO_PIN_0  // Start button
#define STOP_BUTTON_PIN  GPIO_PIN_1  // Stop button
#define SERVO_PIN        GPIO_PIN_2  // Servo motor PWM
#define ULTRASONIC_TRIG  GPIO_PIN_3  // Ultrasonic trigger
#define ULTRASONIC_ECHO  GPIO_PIN_4  // Ultrasonic echo

#define LED1_PIN         GPIO_PIN_5  // LED for filling station
#define LED2_PIN         GPIO_PIN_6  // LED for filling completed
#define LED3_PIN         GPIO_PIN_7  // LED for capping station
#define LED4_PIN         GPIO_PIN_8  // LED for capping completed

#define GPIO_PORT        GPIOA
#define GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

void SystemClock_Config(void);
void GPIO_Init(void);
void Servo_Move(uint8_t angle);
uint32_t Measure_Distance(void);
void Delay_ms(uint16_t ms);

// Process states
typedef enum {
    IDLE,
    DETECT_FILLING,
    FILLING,
    DETECT_CAPPING,
    CAPPING
} ProcessState;

ProcessState state = IDLE;

int main(void) {
    HAL_Init();
    SystemClock_Config();
    GPIO_Init();

    while (1) {
        // Check if the stop button is pressed
        if (HAL_GPIO_ReadPin(GPIO_PORT, STOP_BUTTON_PIN) == GPIO_PIN_SET) {
            // Reset system to initial state
            state = IDLE;
            HAL_GPIO_WritePin(GPIO_PORT, LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN, GPIO_PIN_RESET);
            Servo_Move(0);  // Servo reset
            continue;
        }

        // Main process workflow
        switch (state) {
            case IDLE:
                // Wait for the start button
                if (HAL_GPIO_ReadPin(GPIO_PORT, START_BUTTON_PIN) == GPIO_PIN_SET) {
                    state = DETECT_FILLING;
                }
                break;

            case DETECT_FILLING:
                // Detect object at filling station
                if (Measure_Distance() <= 10) {
                    HAL_GPIO_WritePin(GPIO_PORT, LED1_PIN, GPIO_PIN_SET); // Turn on LED1
                    state = FILLING;
                }
                break;

            case FILLING:
                // Simulate filling process
                HAL_GPIO_WritePin(GPIO_PORT, LED2_PIN, GPIO_PIN_SET); // Turn on LED2
                Delay_ms(2000);  // Filling delay
                HAL_GPIO_WritePin(GPIO_PORT, LED2_PIN, GPIO_PIN_RESET); // Turn off LED2
                HAL_GPIO_WritePin(GPIO_PORT, LED1_PIN, GPIO_PIN_RESET); // Turn off LED1
                Servo_Move(90);  // Move conveyor
                Delay_ms(1000);  // Conveyor delay
                Servo_Move(0);   // Stop conveyor
                state = DETECT_CAPPING;
                break;

            case DETECT_CAPPING:
                // Detect object at capping station
                if (Measure_Distance() <= 10) {
                    HAL_GPIO_WritePin(GPIO_PORT, LED3_PIN, GPIO_PIN_SET); // Turn on LED3
                    state = CAPPING;
                }
                break;

            case CAPPING:
                // Simulate capping process
                HAL_GPIO_WritePin(GPIO_PORT, LED4_PIN, GPIO_PIN_SET); // Turn on LED4
                Delay_ms(2000);  // Capping delay
                HAL_GPIO_WritePin(GPIO_PORT, LED4_PIN, GPIO_PIN_RESET); // Turn off LED4
                HAL_GPIO_WritePin(GPIO_PORT, LED3_PIN, GPIO_PIN_RESET); // Turn off LED3
                Servo_Move(90);  // Move conveyor
                Delay_ms(1000);  // Conveyor delay
                Servo_Move(0);   // Stop conveyor
                state = DETECT_FILLING; // Loop back to detect filling
                break;
        }
    }
}

// GPIO Initialization
void GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_CLK_ENABLE();

    // Configure LED pins
    GPIO_InitStruct.Pin = LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

    // Configure Start and Stop Button pins
    GPIO_InitStruct.Pin = START_BUTTON_PIN | STOP_BUTTON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

    // Configure Servo pin
    GPIO_InitStruct.Pin = SERVO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

    // Configure Ultrasonic pins
    GPIO_InitStruct.Pin = ULTRASONIC_TRIG | ULTRASONIC_ECHO;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);
}

// Servo Control Function
void Servo_Move(uint8_t angle) {
    uint16_t pulse = 500 + (angle * 2000 / 180); // Convert angle to pulse width
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
}

// Measure Distance with Ultrasonic Sensor
uint32_t Measure_Distance(void) {
    HAL_GPIO_WritePin(GPIO_PORT, ULTRASONIC_TRIG, GPIO_PIN_SET);
    Delay_ms(10);
    HAL_GPIO_WritePin(GPIO_PORT, ULTRASONIC_TRIG, GPIO_PIN_RESET);

    while (HAL_GPIO_ReadPin(GPIO_PORT, ULTRASONIC_ECHO) == GPIO_PIN_RESET);
    uint32_t start = HAL_GetTick();
    while (HAL_GPIO_ReadPin(GPIO_PORT, ULTRASONIC_ECHO) == GPIO_PIN_SET);
    uint32_t end = HAL_GetTick();

    return (end - start) * 0.034 / 2; // Distance in cm
}

// Delay Function
void Delay_ms(uint16_t ms) {
    HAL_Delay(ms);
}
