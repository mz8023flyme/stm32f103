#include "main.h"


int main(void)
{
        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
        
        systick_init();
        usart_init();
        SPI_bsp_Init();
        NRF_GPIO_Init();
        
        while(1)
        {
                printf("[%s][%d]", __func__, __LINE__);
                delay_ms(1000);
        }
}


/*
int main(void)
{
        u8 str[32] ="Hello Word" ; //���Ͷ�Ҫ���͵�����
         
        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
        
        systick_init();
        usart_init();
        LED_GPIO_Config();
        SPI_bsp_Init();
        //�ж�NRFΪ�ա���ģʽ�����ų�ʼ��
        NRF_GPIO_Init();
        
        printf("����һ��SPI���Գ���\n");
        if(NRF24L01_Check())
        {
               printf("[%s][%d]\r\n", __func__, __LINE__);
        }
        
        while(1)
        {
//                printf("[%s][%d]\r\n", __func__, __LINE__);
//                delay_ms(1000);
                
                //�ж�NRF�ǽ��ܶ˻��Ƿ��Ͷˣ�������� NRF_Judge_PORT ��⵽Ϊ�͵�ƽ����Ϊ���ܶ�
                  if(GPIO_ReadInputDataBit(NRF_Judge_PORT, NRF_Judge_PIN) == 0) 
                  {
                          //����NRF�Ĺ���ģʽΪ����ģʽ
                          RX_Mode();
//                          printf("\n NRFҪ���������ˣ�\n");
                          while(1)
                          {
                                  if(NRF24L01_RxPacket(Read) == 0)
                                  {
//                                          printf("\n NRF���ܵ������ˣ�\n");
                                          //������ݽ��ܳɹ������̵�
                                          LED_GREEN
//                                          Usart_SendString( USART1,Read);
                                          printf("NRF ���ܵ�������Ϊ��%s\n",Read);
                                  }
                                  else
                                  {
                                          //�������û�н��ܳɹ��������
                                          LED_RED
                                  }
                          }
                          
                         
                  }
                  else
                  {
                          //����NRF�Ĺ���ģʽΪ����ģʽ
                          TX_Mode();
//                          printf("\n NRFҪ���������ˣ�\n");
                          while(1)
                          {
                                  if(NRF24L01_TxPacket(str) == TX_OK)
                                  {
                                          //������ݷ��ͳɹ���������
                                          LED_BLUE
//                                          printf("���ݷ�����ɣ�\n");
                                  }
                                  else
                                  {
                                          //�������û�з��ͳɹ������Ƶ�
                                          LED_YELLOW
                                  }
                          }
                          
                  }
        }
}

*/

