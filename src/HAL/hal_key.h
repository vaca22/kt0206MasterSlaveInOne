/*
 * hal_key.h
 *
 *  Created on: Oct 11, 2019
 *      Author: chenbowen
 */

#ifndef HAL_KEY_H_
#define HAL_KEY_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdint.h>

/*
 * ENUM DEFINES
 ****************************************************************************************
 */
enum {
    HAL_KEY_N = 0,      /// no click
    HAL_KEY_S = 1,      /// single click
    HAL_KEY_D = 2,      /// double click
    HAL_KEY_T = 3,      /// triple click
    HAL_KEY_L = 10,     /// long press
};

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */


/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
/**
 * 获取按键信息
 * @param  u8KeyPressFlg 按键标志
 * @return               按键结果
 */
uint8_t HAL_KEY_Read(uint8_t u8KeyPressFlg);

#endif /* HAL_KEY_H_ */
