/*
 * hal_key.c
 *
 *  Created on: Oct 11, 2019
 *      Author: chenbowen
 */
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "hal_key.h"

/*
 * MACRO DEFINES
 ****************************************************************************************
 */
#define KEY_STATE_0     0 /// 按键状态
#define KEY_STATE_1     1
#define KEY_STATE_2     2
#define KEY_STATE_3     3

#define SINGLE_KEY_TIME     3    /// SINGLE_KEY_TIME*10MS = 30MS 判定单击的时间长度，软件消抖
#define KEY_INTERVAL        50   /// KEY_INTERVAL*10MS = 500MS 判定双击的时间间隔
#define LONG_KEY_TIME       150  /// LONG_KEY_TIME*10MS = 1.5s 判定长按的时间长度

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/*
 * LOCAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */


/*
 * LOCAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */
uint8_t KEY_Driver(uint8_t u8KeyPressFlg)
{
    volatile static uint8_t vsu8KeyState  = KEY_STATE_1;
    volatile static uint32_t vsu32KeyTime = 0;
    uint8_t u8KeyPress, u8KeyReturn;

    u8KeyReturn = HAL_KEY_N;                        /// 清除 返回按键值

    u8KeyPress = u8KeyPressFlg;                     /// 读取当前键值

    switch (vsu8KeyState) {
    case KEY_STATE_1:                               /// 按键状态1：软件消抖（确定按键是否有效，而不是误触）。按键有效的定义：按键持续按下超过设定的消抖时间
        if (!u8KeyPress) {
            vsu8KeyState = KEY_STATE_2;             /// 如果按键时间超过消抖时间，即判定为按下的按键有效。按键有效包括两种：单击或者长按，进入状态2，继续判定到底是那种有效按键
        }
        break;
    case KEY_STATE_2:                               /// 按键状态2：判定按键有效的种类:是单击还是长按
        if (u8KeyPress) {                           /// 如果按键再设定的长按时间内释放，则判定为单击
            vsu32KeyTime = 0;
            u8KeyReturn = HAL_KEY_S;                /// 返回有效按键值：单击
            vsu8KeyState = KEY_STATE_1;             /// 返回按键状态0，继续等待按键
        } else {
            vsu32KeyTime++;
            if (vsu32KeyTime >= LONG_KEY_TIME) {    /// 如果按键时间超过设定的长按时间1s，则判定为长按
                vsu32KeyTime = 0;
                u8KeyReturn = HAL_KEY_L;            /// 返回有效按键值：长按
                vsu8KeyState = KEY_STATE_1;         /// 去状态3，等待按键释放
            }
        }
        break;
    default:                                        /// 特殊情况：key_state是其他值的情况，清零key_state。这种情况一般出现在没有初始化key_state，第一次执行这个函数的时候
        vsu8KeyState = KEY_STATE_1;
        break;
    }

    return u8KeyReturn;                             /// 返回按键值
}

/*
 * EXPORTED FUNCTION DEFINITIONS
 ****************************************************************************************
 */
uint8_t HAL_KEY_Read(uint8_t u8KeyPressFlg)
{
    volatile static uint8_t vsu8KeyState = 0, vsu8KeyTime = 0;
    uint8_t u8KeyReturn, u8KeyTemp = 0;

    u8KeyReturn = HAL_KEY_N;                        /// 清零 返回按键值

    u8KeyTemp = KEY_Driver(u8KeyPressFlg);          /// 读取键值

    switch (vsu8KeyState) {
    case KEY_STATE_0:                               /// 按键状态0：等待有效按键（通过KYE_Driver返回的有效按键值）
        if (u8KeyTemp == HAL_KEY_S) {               /// 如果是单击，不马上返回单击按键值，先进入按键状态1，判断是否有双击的可能
            vsu8KeyTime = 0;                        /// 清零计时
            vsu8KeyState = KEY_STATE_1;
        } else {                                    /// 如果不是单击，直接返回按键值。这里的按键值可能是长按，无效按键
            u8KeyReturn = u8KeyTemp;                /// 返回按键值
        }
        break;
    case KEY_STATE_1:                               /// 按键状态1：判定是否有双击
        if (u8KeyTemp == HAL_KEY_S) {               /// 有单击后，如果在设定的时间间隔300ms内，再次有单击，则为双击，但是不马上返回有效按键值为单击，先进入按键状态2，判断是否有三击
            vsu8KeyTime = 0;                        /// 清零时间间隔
            vsu8KeyState = KEY_STATE_2;             /// 改变按键状态值
        } else {                                    /// 有单击后，如果在设定的时间间隔300ms内，没有单击出现，则判定为单击
            vsu8KeyTime++;                          /// 计数时间间隔
            if (vsu8KeyTime >= KEY_INTERVAL) {      /// 超过时间间隔
                vsu8KeyTime = 0;                    /// 清零时间间隔
                u8KeyReturn = HAL_KEY_S;            /// 返回有效按键单击
                vsu8KeyState = KEY_STATE_0;         /// 返回按键状态0，等待新的有效按键
            }
        }
        break;
    case KEY_STATE_2:                               /// 按键状态2：判定是否有三击
        if (u8KeyTemp == HAL_KEY_S) {               /// 有双击后，如果在设定的时间间隔300ms内，再次有单击，则为三击，马上返回有效按键值为三击
            vsu8KeyTime = 0;                        /// 清零时间间隔
            u8KeyReturn = HAL_KEY_T;                /// 返回有效按键三击
            vsu8KeyState = KEY_STATE_0;             /// 返回按键状态0，等待新的有效按键
        } else {                                    /// 有双击后，如果在设定的时间间隔300ms内，没有单击出现，则判定为双击
            vsu8KeyTime++;                          /// 计数时间间隔
            if (vsu8KeyTime >= KEY_INTERVAL) {      /// 超过时间间隔
                vsu8KeyTime = 0;                    /// 清零时间间隔
                u8KeyReturn = HAL_KEY_D;            /// 返回有效按键双击
                vsu8KeyState = KEY_STATE_0;         /// 返回按键状态0，等待新的有效按键
            }
        }
        break;
    default:                                        /// 特殊情况：key_state是其他值的情况，清零key_state。这种情况一般出现在没有初始化key_state，第一次执行这个函数的时候
        vsu8KeyState = KEY_STATE_0;
        break;
    }

    return  u8KeyReturn;                            /// 返回按键值
}

/*
 * PATCH DECLARATION
 ****************************************************************************************
 */
/// Patch table structure declaration
struct aaa {

};

/// Patch function table instance declear
const struct aaa bbb;

/// Patch function table API
const struct aaa *ccc = &bbb;

/*
 * PATCH FUNCTIONS INSTANCE
 ****************************************************************************************
 */


/*
 * PATCH FUNCTION TABLE INSTANCE
 ****************************************************************************************
 */
const struct aaa bbb = {

};
