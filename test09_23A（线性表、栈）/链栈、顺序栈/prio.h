#pragma once
//�������������ȼ�

/*********************************************************************************************************
  ��������ȼ�����ֵԽС���ȼ�Խ��
*********************************************************************************************************/
#define OPERA_PRIO_PLUS_IN            4                                 /*  ջ�� +                      */
#define OPERA_PRIO_MINUS_IN           4                                 /*  ջ�� -                      */
#define OPERA_PRIO_MULTIPLY_IN        2                                 /*  ջ�� *                      */
#define OPERA_PRIO_DIVISION_IN        2                                 /*  ջ�� /                      */
#define OPERA_PRIO_LEFT_BRACKETS_IN   10                                /*  ջ�� (                      */
#define OPERA_PRIO_LEFT_MIDKUOHAO_IN  11                                /*  ջ�� [                      */
#define OPERA_PRIO_LEFT_BIGKUOHAO_IN  12                                /*  ջ�� {                      */

#define OPERA_PRIO_PLUS_OUT           5                                 /*  ջ�� +                      */
#define OPERA_PRIO_MINUS_OUT          5                                 /*  ջ�� -                      */
#define OPERA_PRIO_MULTIPLY_OUT       3                                 /*  ջ�� *                      */
#define OPERA_PRIO_DIVISION_OUT       3                                 /*  ջ�� /                      */
#define OPERA_PRIO_LEFT_BRACKETS_OUT  1                                 /*  ջ�� (                      */
#define OPERA_PRIO_LEFT_MIDKUOHAO_OUT 0                                 /*  ջ�� [                      */
#define OPERA_PRIO_LEFT_BIGKUOHAO_OUT -1                                /*  ջ�� {                      */
#define OPERA_PRIO_RIGHT_MIDKUOHAO_OUT 11                               /*  ջ�� ]                      */
#define OPERA_PRIO_RIGHT_BIGKUOHAO_OUT 12                               /*  ջ�� }                      */
#define OPERA_PRIO_RIGHT_BRACKETS_OUT 10                                /*  ջ�� )                      */
#define OPERA_PRIO_ERR                -1   