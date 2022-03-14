/*
 * SurroundMove.h
 *
 *  Created on: May 8, 2020
 *      Author: guoax
 */

#ifndef SURROUNDMOVE_H_
#define SURROUNDMOVE_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "nds32_includes.h"
#include "effect_config.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */
#define PATHNUMMAX  5
#ifndef NULL
#define NULL ((void *)0)
#endif
/*
 * ENUM DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */
typedef struct{
	int16_t          AzimuthStart;
	int16_t          AzimuthStop;
	uint16_t         PathTimeMs;
	uint8_t          PathCycNum;
	uint8_t          ClockWise;
}SurroundMovePath_t;

typedef struct{
	int32_t        * HrirLCoeff;
	int32_t        * HrirLState;
	int32_t        * HrirRCoeff;
	int32_t        * HrirRState;

	int32_t        * HrirLoldCoeff;
	int32_t        * HrirLoldState;
	int32_t        * HrirRoldCoeff;
	int32_t        * HrirRoldState;

	uint32_t         HrirCoeffSize;

	int32_t        * pBuff;
	uint32_t         BuffSize;
	uint32_t         Fs;
	uint32_t         OlpLen;
	int32_t        * PathTrack [PATHNUMMAX];
	uint16_t         PathTimeMs[PATHNUMMAX];
	uint8_t          PathPosNum[PATHNUMMAX];
	uint8_t          PathCycNum[PATHNUMMAX];
	uint8_t          PathNum;
	uint8_t          CntBlk;
	uint8_t          CntPos;
	uint8_t          CntCyc;
	uint8_t          CntPath;
	uint8_t          HrirIdx;
	uint8_t          HrirIdxOld;
	uint8_t          En;
}SurroundMoveStru_t;

#pragma pack(1)
typedef struct{
	uint32_t           Fs_Hz;
	SurroundMovePath_t st_Path[PATHNUMMAX];
	uint8_t            PathNum;
	uint8_t            En;
	uint16_t    	   RFU;
}SurroundMovePara_t;
#pragma pack()
/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
void     SurroundMove        (SurroundMoveStru_t *pStru, int32_t *pDataL, int32_t *pDataR, int32_t *pTmpLenx2, uint32_t Len);
uint32_t SurroundMove_MaxBuff(SurroundMoveStru_t *pStru, uint32_t BlkLen);
uint32_t SurroundMoveInit    (SurroundMoveStru_t *pStru, SurroundMovePara_t *pPara, void *pBuff, uint32_t Len);
void     SurroundMoveNew     (SurroundMoveStru_t *pStru, SurroundMovePara_t *pPara);


#endif /* SURROUNDMOVE_H_ */
