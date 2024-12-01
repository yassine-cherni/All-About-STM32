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
