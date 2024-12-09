#include "stm32f4xx.h"

// Adjust GPIO Pin Definitions based on STM32F407 Discovery
#define BUTTON_START_PIN    GPIO_PIN_0   // Example: Start button connected to PA0
#define BUTTON_STOP_PIN     GPIO_PIN_1   // Example: Stop button connected to PA1
#define SENSOR_BR_PIN       GPIO_PIN_2   // Level sensor connected to PA2
#define SENSOR_BRB_PIN      GPIO_PIN_3   // Presence sensor connected to PA3
#define SENSOR_BO_PIN       GPIO_PIN_4   // Upper limit switch connected to PA4
#define SENSOR_BL_PIN       GPIO_PIN_5   // Lower limit switch connected to PA5
#define SENSOR_BRE_PIN      GPIO_PIN_6   // Bottle at capping station connected to PA6
#define SENSOR_ET_PIN       GPIO_PIN_7   // Conveyor sensor connected to PA7
#define SENSOR_EP_PIN       GPIO_PIN_8   // Carton sensor connected to PA8
#define ACTUATOR_VR_PIN     GPIO_PIN_9   // Distributor DS0 (Vr) connected to PA9
#define ACTUATOR_VE_PIN     GPIO_PIN_10  // Distributor DS1 (Ve) connected to PA10
#define MOTOR_K1_PIN        GPIO_PIN_11  // Motor control (K1) connected to PA11

// Define GPIO Port (Assuming all pins are connected to GPIOA)
#define GPIO_PORT           GPIOA
#define GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()

// Prototypes
void Init(void);
void Run(void);
void Stop(void);

// Global Variables
uint8_t cycle_started = 0;
uint8_t bottles_filled = 0;

int main(void) {
    HAL_Init();  // Initialize HAL Library
    Init();      // Configure GPIOs

    while (1) {
        if (HAL_GPIO_ReadPin(GPIO_PORT, BUTTON_START_PIN) == GPIO_PIN_SET) {
            cycle_started = 1;  // Start the process
            Run();
        }

        if (HAL_GPIO_ReadPin(GPIO_PORT, BUTTON_STOP_PIN) == GPIO_PIN_SET) {
            Stop();  // Stop the process
        }
    }
}

// GPIO Initialization
void Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Enable GPIO Clock
    GPIO_CLK_ENABLE();

    // Configure input pins for sensors and buttons
    GPIO_InitStruct.Pin = BUTTON_START_PIN | BUTTON_STOP_PIN | SENSOR_BR_PIN | SENSOR_BRB_PIN |
                          SENSOR_BO_PIN | SENSOR_BL_PIN | SENSOR_BRE_PIN | SENSOR_ET_PIN | SENSOR_EP_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

    // Configure output pins for actuators and motor
    GPIO_InitStruct.Pin = ACTUATOR_VR_PIN | ACTUATOR_VE_PIN | MOTOR_K1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

    // Initialize outputs to low state
    HAL_GPIO_WritePin(GPIO_PORT, ACTUATOR_VR_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIO_PORT, ACTUATOR_VE_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIO_PORT, MOTOR_K1_PIN, GPIO_PIN_RESET);
}

// Process Logic
void Run(void) {
    if (!cycle_started) return;

    // Start conveyor motor
    HAL_GPIO_WritePin(GPIO_PORT, MOTOR_K1_PIN, GPIO_PIN_SET);

    // Wait for a bottle to be detected
    while (HAL_GPIO_ReadPin(GPIO_PORT, SENSOR_BRB_PIN) != GPIO_PIN_SET);

    // Fill the bottle
    HAL_GPIO_WritePin(GPIO_PORT, ACTUATOR_VR_PIN, GPIO_PIN_SET); // Activate DS0 (Vr)
    while (HAL_GPIO_ReadPin(GPIO_PORT, SENSOR_BR_PIN) != GPIO_PIN_SET); // Wait for fill level
    HAL_GPIO_WritePin(GPIO_PORT, ACTUATOR_VR_PIN, GPIO_PIN_RESET); // Deactivate DS0

    // Wait for the bottle to be at the capping station
    while (HAL_GPIO_ReadPin(GPIO_PORT, SENSOR_BRE_PIN) != GPIO_PIN_SET);

    // Cap the bottle
    HAL_GPIO_WritePin(GPIO_PORT, ACTUATOR_VE_PIN, GPIO_PIN_SET); // Activate DS1 (Ve down)
    while (HAL_GPIO_ReadPin(GPIO_PORT, SENSOR_BO_PIN) != GPIO_PIN_SET); // Wait for upper limit
    HAL_GPIO_WritePin(GPIO_PORT, ACTUATOR_VE_PIN, GPIO_PIN_RESET); // Deactivate DS1
    while (HAL_GPIO_ReadPin(GPIO_PORT, SENSOR_BL_PIN) != GPIO_PIN_SET); // Wait for lower limit

    // Increment the bottle count
    bottles_filled++;

    // Check if 3 bottles are filled
    if (bottles_filled >= 3) {
        Stop();
    }
}

// Stop Logic
void Stop(void) {
    cycle_started = 0;
    bottles_filled = 0;

    // Stop all actuators and motor
    HAL_GPIO_WritePin(GPIO_PORT, MOTOR_K1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIO_PORT, ACTUATOR_VR_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIO_PORT, ACTUATOR_VE_PIN, GPIO_PIN_RESET);
}
