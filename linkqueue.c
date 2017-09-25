/**
  ******************************************************************************
  * @file           : linkqueue.c
  * @author         : liuchengfei
  * @version        : v1.0
  * @date           : 2017.09
  * @brief          : 
  *
  ******************************************************************************
  * @attention  链式存储队列
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
  * @brief  队列初始化
  * @param  None
  * @retval None
  */
 void LinkQueueInit(LinkQueue *Q)
 {
	
 }

 /**
  * @brief  入队列
  * @param  [out]*Q ：队列指针
		    [in]element: 要插入队尾的元素		
  * @retval None
  */
 FUN_StatusTypeDef EnQueue(LinkQueue *Q, QElemType element)
 {
	QueuePtr m_qnode = (QueuePtr)malloc(sizeof(QNode));
	if(!m_qnode)  /* 存储分配失败 */
	{
		return FUN_ERROR;
	}
	m_qnode->data = element;
	m_qnode->next = NULL;
	Q->rear->next = m_qnode;	/* 队尾节点 后继指向新加入的节点 */
	
	Q->rear = m_qnode;		    /* 将新加入的节点设置为队尾节点 */
		
    return FUN_OK;
 }
  /**
  * @brief  出队列
  * @param  [in]*Q ：队列指针
		    [out]*element: 保存出队列的值的指针		
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
	*element = P->data;              /* 将要删除的节点的值保存到指针中 */
    Q->front->next = m_qnode->next;
	
	if(Q->rear == m_qnode)
	{
		Q->rear = Q->front;
	}
	free(m_qnode);
    return FUN_OK;
 }
 
 	









/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/

