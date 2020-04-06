/**
  ******************************************************************************
  * @project Bad Apple
  * @author  Richie Li
  * @version V1.0.0
  * @date    2020.04.06
  * @brief   Main funcation entrance, use C99 mode at least.
  ******************************************************************************
  */
#include "bsp.h"
#include "oled.h"

/* ����1��������230400��
   ����ͨ�Ÿ�ʽ��[0]֡ͷ0xEE, [1~1024]���ݶ�, [1025]֡β0xED
   ��ȷ���ջظ���λ��1�����մ���ظ�0,����μ�bsp_usart.c
   OLED��Ļ������Ƶ�е�λ�ðڷż��ɣ��������¸�дOLED_ShowPicture�����Ľ��뷽ʽ
   ʹ��C99��׼
 */

extern uint8_t Rcvbuf[15][1024],RxFrame,TxFrame;

int main(void)
{
	BSP_Init();
	OLED_Init();
	OLED_Clear();
	LED0 = 1;
	
	while(1)
	{
		if(RxFrame != TxFrame)
		{
			OLED_ShowPicture(0,0,128,8,Rcvbuf[TxFrame]);
			if(++TxFrame >= 16)	TxFrame = 0;
		}
	}
}
