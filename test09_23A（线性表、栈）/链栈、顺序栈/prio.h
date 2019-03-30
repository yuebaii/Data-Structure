#pragma once
//存放运算符的优先级

/*********************************************************************************************************
  运算符优先级，数值越小优先级越高
*********************************************************************************************************/
#define OPERA_PRIO_PLUS_IN            4                                 /*  栈内 +                      */
#define OPERA_PRIO_MINUS_IN           4                                 /*  栈内 -                      */
#define OPERA_PRIO_MULTIPLY_IN        2                                 /*  栈内 *                      */
#define OPERA_PRIO_DIVISION_IN        2                                 /*  栈内 /                      */
#define OPERA_PRIO_LEFT_BRACKETS_IN   10                                /*  栈内 (                      */
#define OPERA_PRIO_LEFT_MIDKUOHAO_IN  11                                /*  栈内 [                      */
#define OPERA_PRIO_LEFT_BIGKUOHAO_IN  12                                /*  栈内 {                      */

#define OPERA_PRIO_PLUS_OUT           5                                 /*  栈外 +                      */
#define OPERA_PRIO_MINUS_OUT          5                                 /*  栈外 -                      */
#define OPERA_PRIO_MULTIPLY_OUT       3                                 /*  栈外 *                      */
#define OPERA_PRIO_DIVISION_OUT       3                                 /*  栈外 /                      */
#define OPERA_PRIO_LEFT_BRACKETS_OUT  1                                 /*  栈外 (                      */
#define OPERA_PRIO_LEFT_MIDKUOHAO_OUT 0                                 /*  栈外 [                      */
#define OPERA_PRIO_LEFT_BIGKUOHAO_OUT -1                                /*  栈外 {                      */
#define OPERA_PRIO_RIGHT_MIDKUOHAO_OUT 11                               /*  栈外 ]                      */
#define OPERA_PRIO_RIGHT_BIGKUOHAO_OUT 12                               /*  栈外 }                      */
#define OPERA_PRIO_RIGHT_BRACKETS_OUT 10                                /*  栈外 )                      */
#define OPERA_PRIO_ERR                -1   