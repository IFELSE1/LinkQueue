/**
  ******************************************************************************
  * @file           : linkqueue.c
  * @author         : liuchengfei
  * @version        : v1.0
  * @date           : 2017.09
  * @brief          : 
  *
  ******************************************************************************
  * @attention  ��ʽ�洢����
  *
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "ringqueue.h" 
#include <stdbool.h>
#include <stdint.h>

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private function ----------------------------------------------------------*/

/* Exported function ----------------------------------------------------------*/

/**
  * @brief  ���г�ʼ��
  * @param  None
  * @retval None
  */
 void LinkQueueInit(LinkQueue *Q)
 {
	
 }

 /**
  * @brief  �����
  * @param  [out]*Q ������ָ��
		    [in]element: Ҫ�����β��Ԫ��		
  * @retval None
  */
 FUN_StatusTypeDef EnQueue(LinkQueue *Q, QElemType element)
 {
	QueuePtr m_qnode = (QueuePtr)malloc(sizeof(QNode));
	if(!m_qnode)  /* �洢����ʧ�� */
	{
		return FUN_ERROR;
	}
	m_qnode->data = element;
	m_qnode->next = NULL;
	Q->rear->next = m_qnode;	/* ��β�ڵ� ���ָ���¼���Ľڵ� */
	
	Q->rear = m_qnode;		    /* ���¼���Ľڵ�����Ϊ��β�ڵ� */
		
    return FUN_OK;
 }
  /**
  * @brief  ������
  * @param  [in]*Q ������ָ��
		    [out]*element: ��������е�ֵ��ָ��		
  * @retval None
  */
FUN_StatusTypeDef DeQueue(LinkQueue *Q, QElemType* element)
{
	QueuePtr m_qnode;
	if(Q->front == Q->rear)
	{
		return FUN_ERROR;
	}
	m_qnode = Q->front->next; 
	*element = P->data;              /* ��Ҫɾ���Ľڵ��ֵ���浽ָ���� */
    Q->front->next = m_qnode->next;
	
	if(Q->rear == m_qnode)
	{
		Q->rear = Q->front;
	}
	free(m_qnode);
    return FUN_OK;
 }
 
 	









/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/

