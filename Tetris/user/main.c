#include "main.h"


//u8 Random;

Shape Shape_Structer={0};


int main(void)
{
        
        
        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
        
        systick_init();
        usart_init();
        ADCx_Init();
        LCD_Init();
        printf("[%s][%d]\r\n", __func__, __LINE__);
        LCD_SetColors(RED,BLACK);
        LCD_Clear(0,0,240,320,GREY);   //清屏
        LCD_DrawLine(0,48,151,48);      //设置游戏区
        LCD_DrawLine(151,48,151,320);   //设置游戏区
        LCD_SetTextColor(BLUE);
        LCD_DisplayStringEx(40,10,32,32,(uint8_t *)"俄罗斯方块",0);
        
        
        Shape_Structer.CurNum = Make_Random();
        Shape_Structer.NextNum = Make_Random();
        
        BASIC_TIM_Init();
        KEY_GPIO_Config();
        Creat_Shap( );
        while(1)
        {
                
                LCD_Tetris_Show();
                Key_Board_Scan();
//                printf("[%s][%d]\r\n", __func__, __LINE__);
                printf("\n\n\n\n");
                delay_ms(100);
        }
}



void Key_Board_Scan(void)
{
        if(Key_Scan(KEY_LEFT_GPIO_PORT,KEY_LEFT_GPIO_PIN)==KEY_ON)
        {
                delay_ms(10);
                if(Key_Scan(KEY_LEFT_GPIO_PORT,KEY_LEFT_GPIO_PIN)==KEY_ON)
                {
                        //左移函数
                        Tetris_Left();
                }
        }
        
        if(Key_Scan(KEY_RIGHT_GPIO_PORT,KEY_RIGHT_GPIO_PIN)==KEY_ON)
        {
                delay_ms(10);
                if(Key_Scan(KEY_RIGHT_GPIO_PORT,KEY_RIGHT_GPIO_PIN)==KEY_ON)
                {
                        //右移函数
                        Tetris_Right();
                }
        }
        
        if(Key_Scan(KEY_DOWN_GPIO_PORT,KEY_DOWN_GPIO_PIN)==KEY_ON)
        {
                delay_ms(10);
                if(Key_Scan(KEY_DOWN_GPIO_PORT,KEY_DOWN_GPIO_PIN)==KEY_ON)
                {
                        //快速下降函数
                }
        }
        
        if(Key_Scan(KEY_PAUSE_GPIO_PORT,KEY_PAUSE_GPIO_PIN)==KEY_ON)
        {
                delay_ms(10);
                if(Key_Scan(KEY_PAUSE_GPIO_PORT,KEY_PAUSE_GPIO_PIN)==KEY_ON)
                {
                        //暂停函数
                }
        }
        
        if(Key_Scan(KEY_RESET_GPIO_PORT,KEY_RESET_GPIO_PIN)==KEY_ON)
        {
                delay_ms(10);
                if(Key_Scan(KEY_RESET_GPIO_PORT,KEY_RESET_GPIO_PIN)==KEY_ON)
                {
                        //复位函数
                }
        }
        
        if(Key_Scan(KEY_ROTATE_GPIO_PORT,KEY_ROTATE_GPIO_PIN)==KEY_ON)
        {
                delay_ms(10);
                if(Key_Scan(KEY_ROTATE_GPIO_PORT,KEY_ROTATE_GPIO_PIN)==KEY_ON)
                {
                        //变形函数
                        Tetris_Rotate();
                }
        }
}


u8 Make_Random (void)
{
        srand(ADC_ConvertedValue);
        return (rand()%19);
}






