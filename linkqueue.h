/**
  ******************************************************************************
  * @file           : linkqueue.h
  * @author         : liuchengfei
  * @version        : v1.0
  * @date           : 2017.09
  * @brief          : 
  *
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LINKQUEUE_H
#define __LINKQUEUE_H	 
/* Includes ------------------------------------------------------------------*/
#include "nrf.h"
#include "nrf_delay.h"
#include "simple_hal.h"
#include "nrf_drv_config.h"
#include "pca10028.h"
#include "sys.h"

/* Private types -------------------------------------------------------------*/
/**
  * @brief  
  */
typedef uint8_t QElemType;

/**
  * @brief  ��ʽ�洢�ṹ ���� �Ľڵ�ṹ
  */
typedef struct QNode
{
	QElemType data;
	struct QNode * next;
}QNode,*QueuePtr;
/**
  * @brief  ���е�����ṹ
  */
typedef struct
{
	QueuePtr front,rear;   /* ��ͷ����βָ�� */  	  
}LinkQueue;

/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/ 
void QueueInit(SqQueue* Q);
uint8_t QueueGetLen(SqQueue Q);
FUN_StatusTypeDef EnQueue(SqQueue*Q,QElemType e);
FUN_StatusTypeDef DeQueue(SqQueue*Q,QElemType* e);



#endif /* __LINKQUEUE_H */
/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/

