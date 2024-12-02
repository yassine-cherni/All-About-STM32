while (1)
{
    /* USER CODE BEGIN WHILE */
    
    // Set PB5 high
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    HAL_Delay(1000); // Wait for 1 second
    
    // Set PB5 low
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_Delay(1000); // Wait for 1 second

    /* USER CODE END WHILE */
}

// or

while (1)
{
    /* USER CODE BEGIN WHILE */

    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);  // Toggle the state of PB5
    HAL_Delay(250);  // Wait for 250 milliseconds

    /* USER CODE END WHILE */
}
HAL_GPIO_WritePin(GPIOB, GPIO_pin_5, GPIO_PIN_SET);
