
/******************** include *******************/
#include "KT065x_SeekFreq.h"
#include "KT065xDrv.h"

/**************** Variable *****************/
KT056x_SeekFreqStatus_t  SeekFreqStruct_CHA = {.flag.ChannelNum = 0, .flag.LoadDataOK = 1,};
KT056x_SeekFreqStatus_t  SeekFreqStruct_CHB = {.flag.ChannelNum = 1, .flag.LoadDataOK = 1,};
KT065xM_BpskData_t KT065x_BpskData;

#ifdef	KT0656M_I2SEn
	const KT065xM_I2SConfig_t 	I2SConfig_CHA =
	{
		.LRCLK         =   KT_I2S_LRCLK48K,
		.MCLK          =   KT_I2S_MCLK12P288M,
		.MasterOrSlave =   KT_I2S_SLAVE,        //1:master 0:slave
		.SteroOrMono   =   KT_I2S_STRREO,       //1:stereo 0:Mono
		.LeftOrRight   =   KT_I2S_LEFT,         //1:left 0:right
		.Mode     	   =   KT_I2S_I2SMODE,      //0:
		.DataLength    =   KT_I2S_LENGHT24BIT,  //0:16 1:20 2:24 3:8
	};

	const KT065xM_I2SConfig_t 	I2SConfig_CHB =
	{
		.LRCLK         =   KT_I2S_LRCLK48K,
		.MCLK          =   KT_I2S_MCLK12P288M,
		.MasterOrSlave =   KT_I2S_SLAVE,        //1:master 0:slave
		.SteroOrMono   =   KT_I2S_STRREO,       //1:stereo 0:Mono
		.LeftOrRight   =   KT_I2S_RIGHT,        //1:left 0:right
		.Mode     	   =   KT_I2S_I2SMODE,      //0:
		.DataLength    =   KT_I2S_LENGHT24BIT,  //0:16 1:20 2:24 3:8
	};
#endif

/*************** Const Variable *************/
#ifdef  UserRandomSeek
// 用户自定义搜台频率表
const uint32_t	UserRandomFreq[2][49] =
{
	{
		631000,      // 0
		631600,
		632200,
		632800,
		633400,
		634000,
		634600,
		635200,
		635800,
		636400,

		637000,     // 10
		637600,
		638200,
		638800,
		639400,
		640000,
		640600,
		641200,
		641800,
		642400,

		643000,     // 20
		643600,
		644200,
		644800,
		645400,
		646000,
		646600,
		647200,
		647800,
		648400,

		649000,    // 30
		649600,
		650200,
		650800,
		651400,
		652000,
		652600,
		653200,
		653800,
		654400,

		655000,   // 40
		655600,
		656200,
		656800,
		657400,
		658000,
		658600,
		659200,
		659800,  // 48
	},
	{
		661000,      // 0
		661600,
		662200,
		662800,
		663400,
		664000,
		664600,
		665200,
		665800,
		666400,

		667000,     // 10
		667600,
		668200,
		668800,
		669400,
		670000,
		670600,
		671200,
		671800,
		672400,

		673000,     // 20
		673600,
		674200,
		674800,
		675400,
		676000,
		676600,
		677200,
		677800,
		678400,

		679000,    // 30
		679600,
		680200,
		680800,
		681400,
		682000,
		682600,
		683200,
		683800,
		684400,

		685000,   // 40
		685600,
		686200,
		686800,
		687400,
		688000,
		688600,
		689200,
		689800,  // 48
	}
};
#endif
;

const KT056x_SeekFreqConfig_t  UserSeekFreqConfig =
{
#ifndef  UserRandomSeek                     		// 用户非随机搜台
	.StartFreq[0]				= 645250,           // kHz  起始频率
	.SeekFreqStep[0]			= 1000,             // kHz  步进
	.EndFreq[0]				    = 660250,			// kHz  截至频率

	.StartFreq[1]				= 665250,           // kHz  起始频率
	.SeekFreqStep[1]			= 1000,             // kHz  步进
	.EndFreq[1]				    = 680250,			// kHz  截至频率
#else
	.UserRandomFreqIndexHead[0]	= UserRandomFreq[0],        		// 指向用户自定义随机搜台表
	.UserRandomFreqIndexNum[0]	= sizeof(UserRandomFreq[0])/4,      // 用户自定义随机搜台个数
	.UserRandomFreqIndexHead[1]	= UserRandomFreq[1],        		// 指向用户自定义随机搜台表
	.UserRandomFreqIndexNum[1]	= sizeof(UserRandomFreq[1])/4,      // 用户自定义随机搜台个数
#endif

	.FactoryID				= 0x554e,	// 出厂ID码   'K''T'

	.SeekRssiThresholdHigh	= 50,   	// 搜台时RSSI高门限（收到台时进入门限）
	.SeekRssiThresholdLow	= 35,    	// 搜台时RSSI低门限（当前台消失退出门限）
	.ChangeIDRssiThreshold  = 65,    	// 用户重新对台时需要的RSSI门限,一般要求用户走近接收机才可对台，需要的RSSI门限较大

	.ReadRssiMaxCnt			= 2,       	// 读取RSSI最大次数，如果连续读Rssi值MaxCnt次都小于SeekRssiThresholdHigh门限，则Seek下一个台
	.ReadPilotMaxCnt		= 10,       // 读Pilot最大次数，如果连续读Polit值MaxCnt次都未检测到导频，则Seek下一个台
    .ReadBpskSyncMaxCnt		= 20,       // 读Bpsk同步标志最大次数
    .ReadBpskDataMaxCnt		= 30,       // 读Bpsk数据最大次数

    .ReadRssiFailMaxCnt		= 30,       // 状态机进入到VerifyFreq状态, 如果连续读Rssi值MaxCnt次都小于SeekRssiThresholdLow门限，则Seek下一个台
    .ReadBpskSyncFailMaxCnt	= 30,       // 同上
};

static void CheckFreqID(const SoftI2C_t *I2CDef, KT056x_SeekFreqStatus_t *SeekStatus);
static void CheckFuncID(const SoftI2C_t *I2CDef, KT056x_SeekFreqStatus_t *SeekStatus);

/****************** Function *****************/
void SeekFreqDataLoad(KT056x_SeekFreqStatus_t *SeekStatus)
{
//	eflashPara_t UserFlashDataRead;
//	SeekStatus->FlashSaveDataAddr = (uint32_t)(&__dataX_lma_end) - 0x60000 + 8192;         //
//
//	UserFlashDataRead.Addr 			= SeekStatus->FlashSaveDataAddr;
//	UserFlashDataRead.Len 		 	= sizeof(KT056x_SeekFreqStatus_t);
//	UserFlashDataRead.RegLineMode 	= Reg_SingleLine;
//	UserFlashDataRead.SetLineMode   = 1;
//	UserFlashDataRead.Verify 		= 1;
//	UserFlashDataRead.pBuf 			= (void *)SeekStatus;
//
//	eflashReturn_t ret =
//	{
//			.all32 = eflashRead(&UserFlashDataRead),
//	};
//
//	if(ret.Error)
//	{
//		SeekStatus->flag.Err = 1;         // Flash Read Err!
//	}

    // 存储起始地址从CurrentVolume开始到LastChannelFreq结束，共3word数据
//	uint8_t *pDst = (uint8_t *)&SeekStatus->CurrentVolume;
//#if	1                                   // 保存到寄存器通过关机保存
//	DataLoadfromUserReg(pDst, 0, 12);
//#else              //
//	DataLoadfromFlash(pDst, 12);
//#endif
}

void SeekFreqDataSave(KT056x_SeekFreqStatus_t *SeekStatus)
{
//	eflashPara_t UserFlashDataWrite;
//	SeekStatus->FlashSaveDataAddr = (uint32_t)(&__dataX_lma_end) - 0x60000 + 8192;         //
//
//	UserFlashDataWrite.Addr 		= SeekStatus->FlashSaveDataAddr;
//	UserFlashDataWrite.Len 		 	= sizeof(KT056x_SeekFreqStatus_t);
//	UserFlashDataWrite.RegLineMode 	= Reg_SingleLine;
//	UserFlashDataWrite.SetLineMode  = 1;
//	UserFlashDataWrite.Verify 		= 1;
//	UserFlashDataWrite.pBuf 			= (void *)SeekStatus;
//
//	eflashReturn_t ret =
//	{
//		.all32 = eflashWrite(&UserFlashDataWrite),
//	};
//
//	if(ret.Error)
//	{
//		SeekStatus->flag.Err = 2;         // Flash Write Err!
//	}

    // 存储起始地址从CurrentVolume开始到LastChannelFreq结束，共3word数据
//	uint8_t *pSrc = (uint8_t *)&SeekStatus->CurrentVolume;
//#if 1                             // 保存到寄存器通过关机保存
//	DataSavetoUserReg(pSrc, 0, 12);
//#else               // 保存到Flash
//	DataSavetoFlash(pSrc, 12);
//#endif
}

void KT056x_SeekFreq(const SoftI2C_t *I2CDef, KT056x_SeekFreqStatus_t *SeekStatus)
{
	switch(SeekStatus->State)
	{
		case StartSeek:			// 开始/重新开始搜台
		{
			if(!SeekStatus->flag.FastTuneOK)
			{
				SeekStatus->flag.SeekOK = 0;        // 搜台OK标志清零
				if(SeekStatus->SeekLookBackCnt>=5)                 // 用于计数, 收5个台后往回跳之前的台看是否还在，用于断点附近快速恢复
				{
					SeekStatus->SeekLookBackCnt = 0;

					if(SeekStatus->LastSeekFreqOKIndex!=0)
					{

						#ifdef	UserRandomSeek         // 用户自定义搜台列表
							SeekStatus->CurrentChannelFreq = UserSeekFreqConfig.UserRandomFreqIndexHead[SeekStatus->flag.ChannelNum][SeekStatus->LastSeekFreqOKIndex];
						#else                          // 正常搜台
							SeekStatus->CurrentChannelFreq = UserSeekFreqConfig.StartFreq[SeekStatus->flag.ChannelNum] + UserSeekFreqConfig.SeekFreqStep[SeekStatus->flag.ChannelNum]*SeekStatus->LastSeekFreqOKIndex;
						#endif
						SeekStatus->SeekFreqIndex = SeekStatus->LastSeekFreqOKIndex;
					}
				}
				else
				{
					SeekStatus->SeekLookBackCnt++;
					SeekStatus->CurrentSeekFreqIndex++;
					#ifdef	UserRandomSeek         // 用户自定义搜台列表
						if(SeekStatus->CurrentSeekFreqIndex >= UserSeekFreqConfig.UserRandomFreqIndexNum[SeekStatus->flag.ChannelNum])
						{
							SeekStatus->CurrentSeekFreqIndex = 0;
						}
						SeekStatus->CurrentChannelFreq = UserSeekFreqConfig.UserRandomFreqIndexHead[SeekStatus->flag.ChannelNum][SeekStatus->CurrentSeekFreqIndex];
					#else                          // 正常搜台
						if(UserSeekFreqConfig.EndFreq[SeekStatus->flag.ChannelNum] < (UserSeekFreqConfig.StartFreq[SeekStatus->flag.ChannelNum] + UserSeekFreqConfig.SeekFreqStep[SeekStatus->flag.ChannelNum]*SeekStatus->CurrentSeekFreqIndex))
						{
							SeekStatus->CurrentSeekFreqIndex = 0;
						}
						SeekStatus->CurrentChannelFreq = UserSeekFreqConfig.StartFreq[SeekStatus->flag.ChannelNum] + UserSeekFreqConfig.SeekFreqStep[SeekStatus->flag.ChannelNum]*SeekStatus->CurrentSeekFreqIndex;
					#endif
					SeekStatus->SeekFreqIndex = SeekStatus->CurrentSeekFreqIndex;
				}
				SeekStatus->Tick5msCnt = 0;            // 5ms定时节拍
				SeekStatus->ReadTimerCounter = 0;      // For Read Rssi、ReadPilot、ReadBpskSync、ReadBpskData Counter
//
				KT_WirelessMicRx_DoFastTune(I2CDef, SeekStatus->CurrentChannelFreq);
				SeekStatus->flag.FastTuneOK = 1;
				return;
			}
			else
			{
				if(KT_WirelessMicRx_CheckFastTuneOK(I2CDef))
				{
					SeekStatus->flag.FastTuneOK = 0;                // 继续执行
				}
				else
				{
					return;
				}
			}
			SeekStatus->State = ReadRssi;              // Next Status 读Rssi
		}break;
		case ReadRssi:            // 0x01
		{
			if(SeekStatus->Tick5msCnt>=1)         // Read Rssi Every 1*5ms
			{
				SeekStatus->Tick5msCnt = 0;
				if(KT_WirelessMicRx_GetRSSI(I2CDef)>UserSeekFreqConfig.SeekRssiThresholdHigh)
				{
//					SeekStatus->State = ReadSNR;           // 现跳过读SNR
					SeekStatus->State = ReadPilot;         // Next Status 读pilot
					SeekStatus->ReadTimerCounter = 0;      // For Read Rssi、ReadPilot、ReadBpskSync、ReadBpskData Counter
				}
				else if(SeekStatus->ReadTimerCounter++ >= UserSeekFreqConfig.ReadRssiMaxCnt)
				{
					SeekStatus->State = StartSeek;         // 重新开始搜台
				}
			}
		}break;
		case ReadSNR:                   // 暂不起作用  0x02
		{
			if(SeekStatus->Tick5msCnt>=2)         // Read SNR Every 2*5ms
			{
				SeekStatus->Tick5msCnt = 0;
				if(KT_WirelessMicRx_GetSNR(I2CDef)>0x54)     // 门限可以在KT056x_SeekFreqConfig_t中定义
				{
//					SeekStatus->State = ReadSNR;             // 现跳过读SNR
					SeekStatus->State = ReadPilot;           // Next Status 读pilot
					SeekStatus->ReadTimerCounter = 0;        // For Read Rssi、ReadPilot、ReadBpskSync、ReadBpskData Counter
				}
				else if(SeekStatus->ReadTimerCounter++ >= 0x10)  // 次数可以在KT056x_SeekFreqConfig_t中定义
				{
					SeekStatus->State = StartSeek;         // 重新开始搜台
				}
			}
		}break;
		case ReadPilot:             // 0x03
		{
			if(SeekStatus->Tick5msCnt>=2)         // Read pilot Every 2*5ms
			{
				SeekStatus->Tick5msCnt = 0;
				if(KT_WirelessMicRx_GetPilotStatus(I2CDef))
				{
#ifdef	BpskEn                          // 手柄发了带ID的BPSK数据
					SeekStatus->State = ReadBpskSync;      // Next Status 读BpskSync
#else
					SeekStatus->ReadRssiFailCnt = 0;    	// 读Rssi失败次数,清零
					SeekStatus->ReadBpskSyncFailCnt = 0;	// 读Bpsk失败次数,清零

					KT_WirelessMicRx_Tune(I2CDef, SeekStatus->CurrentChannelFreq);         // Tune
#ifdef	KT0656M_I2SEn
					if(SeekStatus->flag.ChannelNum==0)
                    {
					    KT_WirelessMicRx_SAIInit(I2CDef, &I2SConfig_CHA);       // I2S  Re_Config
                    }
                    else
                    {
                    	KT_WirelessMicRx_SAIInit(I2CDef, &I2SConfig_CHB);       // I2S  Re_Config
                    }
#endif
					SeekStatus->flag.SeekOK = 1;
					SeekStatus->flag.SaveData = 1;   // 需要保存标记置位
					SeekStatus->LastSeekFreqOKIndex = SeekStatus->SeekFreqIndex;           // 保存FreqIndex

					SeekStatus->State = VerifyFreq;        // 跳过BPSK数据校验
#endif
					SeekStatus->ReadTimerCounter = 0;      // For Read Rssi、ReadPilot、ReadBpskSync、ReadBpskData Counter
				}
				else if(SeekStatus->ReadTimerCounter++ >= UserSeekFreqConfig.ReadPilotMaxCnt)
				{
					SeekStatus->State = StartSeek;         // 重新开始搜台
				}
			}
		}break;
		case ReadBpskSync:             // 0x04
		{
			if(SeekStatus->Tick5msCnt>=2)         // Read BpskSync Every 2*5ms
			{
				SeekStatus->Tick5msCnt = 0;
				if(KT_WirelessMicRx_GetBpskSyncStatus(I2CDef))
				{
					SeekStatus->State = ReadBpskData;      // Next Status 读BpskSync
					SeekStatus->flag.BpskSync = 1;         // BPSK 同步OK
					SeekStatus->ReadTimerCounter = 0;      // For Read Rssi、ReadPilot、ReadBpskSync、ReadBpskData Counter
				}
				else if(SeekStatus->ReadTimerCounter++ >= UserSeekFreqConfig.ReadBpskSyncMaxCnt)         // 读BPSK不同步最大失败次数
				{
					SeekStatus->flag.BpskSync = 0;         // BPSK 不同步
					SeekStatus->State = StartSeek;         // 重新开始搜台
				}
			}
		}break;
		case ReadBpskData:               // 0x05
		{
			if(SeekStatus->Tick5msCnt>=2)         // Read BpskData Every 2*5ms
			{
//				uint8_t TempVol = 0;
				SeekStatus->Tick5msCnt = 0;
				if(CheckBpskData(I2CDef, SeekStatus)==1)    // 对上台,但保存的数据不是有效数据.
				{
					SeekStatus->ReadTimerCounter = 0;       // For Read Rssi、ReadPilot、ReadBpskSync、ReadBpskData Counter
					SeekStatus->ReadRssiFailCnt = 0;    	// 读Rssi失败次数,清零
					SeekStatus->ReadBpskSyncFailCnt = 0;	// 读Bpsk失败次数,清零
					SeekStatus->State = VerifyFreq;         // Next Status 读BpskSync
					KT_WirelessMicRx_Tune(I2CDef, SeekStatus->CurrentChannelFreq);         // Tune
#ifdef	KT0656M_I2SEn
					if(SeekStatus->flag.ChannelNum==0)
                    {
					    KT_WirelessMicRx_SAIInit(I2CDef, &I2SConfig_CHA);       // I2S  Re_Config
                    }
                    else
                    {
                    	KT_WirelessMicRx_SAIInit(I2CDef, &I2SConfig_CHB);       // I2S  Re_Config
                    }
#endif

					SeekStatus->flag.SeekOK = 1;
					SeekStatus->flag.SaveData = 1;   // 需要保存标记置位
					SeekStatus->LastSeekFreqOKIndex = SeekStatus->SeekFreqIndex;           // 保存Freq
				}
				else if(SeekStatus->ReadTimerCounter++ >= UserSeekFreqConfig.ReadBpskDataMaxCnt)       // 读BPSK数据不匹配最大失败次数
				{
					SeekStatus->State = StartSeek;         // 重新开始搜台
				}
			}
		}break;
		case VerifyFreq:                  // 0x06
		{
			if(SeekStatus->Tick5msCnt>=20)         // Every 20*5ms
			{
				SeekStatus->Tick5msCnt = 0;
				CheckFreqID(I2CDef, SeekStatus);      // Check Bpsk FreqIndex
#ifdef	BpskEn                          // 手柄发了带ID的BPSK数据
				CheckFuncID(I2CDef, SeekStatus);      // Check Bpsk PrivateID
#endif
				if((SeekStatus->ReadRssiFailCnt>=UserSeekFreqConfig.ReadRssiFailMaxCnt)||(SeekStatus->ReadBpskSyncFailCnt>=UserSeekFreqConfig.ReadBpskSyncFailMaxCnt))
				{
					SeekStatus->flag.VolumeSmooth = 0;
					KT_WirelessMicRx_Volume(I2CDef, 0);
					SeekStatus->SmoothVol = 0;
					SeekStatus->ReadRssiFailCnt = 0;
					SeekStatus->ReadBpskSyncFailCnt = 0;
					SeekStatus->State = StartSeek;         // 重新开始搜台
				}
			}
		}break;
		default:break;
	}
}

uint8_t CheckBpskData(const SoftI2C_t *I2CDef,  KT056x_SeekFreqStatus_t *SeekStatus)         // 需根据用户程序实际判断处理
{
	User_Bpsk_t *User_BpskData = (User_Bpsk_t *)&KT065x_BpskData;
	uint16_t  PrivateIDold;
	KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);     // Update bpsk Data
//	if(User_BpskData->FactoryID != UserSeekFreqConfig.FactoryID)     //  出厂码不对，暂不启用
//	{
//		return 0;
//	}
	// SeekFreqIndex从0开始, FreqIndexID从1开始
	if(SeekStatus->SeekFreqIndex+1 != User_BpskData->FreqIndexID)       // SeekFreqIndex:0,1,2...  FreqIndexID:1,2,3...
	{
#if	0   // 方便快速跳转
		SeekStatus->SeekFreqIndex = User_BpskData->FreqIndexID-2;        // 直接调至临近的台
#endif
		return 0;
	}
	// 初次使用，强制对台
	if(User_BpskData->FunctionID == ChangePrivateID)        // FunctionID = ChngePrivateID 强制对手柄重新配对
	{
		if(KT_WirelessMicRx_GetRSSI(I2CDef) > UserSeekFreqConfig.ChangeIDRssiThreshold)      // RSSI达到修改ID条件
		{
			if(User_BpskData->PrivateID != SeekStatus->PrivateID)           //  当前ID与BPSK发送将要修改的ID不一致
			{
				if(SeekStatus->flag.ChangePrivateIDDis)             // 上电修改PrivateID超时,禁止操作
				{
					return 0;
				}
				else
				{
					PrivateIDold = User_BpskData->PrivateID;
					Delay_Ms(100);
					KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);     // Update bpsk Data
					if(PrivateIDold != User_BpskData->PrivateID)
					{
						PrivateIDold = User_BpskData->PrivateID;
						Delay_Ms(100);
						KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);     // Update bpsk Data
						if(PrivateIDold != User_BpskData->PrivateID)
						{
							PrivateIDold = User_BpskData->PrivateID;
							Delay_Ms(100);
							KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);     // Update bpsk Data
							if(PrivateIDold != User_BpskData->PrivateID)
							{
								return 0;   //
							}
						}
					}
					SeekStatus->PrivateID = PrivateIDold;          // 更新 PrivateID
					SeekStatus->flag.ChangePrivateIDDis = 1;       // 禁止本次开机再次修改ID
				}
			}
		}
		else
		{
			return 0;
		}
	}
	// SeekFreqIndex+1 == FreqIndexID,已对上台, 且FunctionID = 厂商ID 0x88
	else if(User_BpskData->FunctionID != VendorID)
	{
		return 0;
	}
	else if((SeekStatus->PrivateID != 0)&&(User_BpskData->PrivateID != SeekStatus->PrivateID))    // FunctionID = VendorID  0x88
	{
		return 0;
	}
	return 1;   // 对上台
}


static void CheckFreqID(const SoftI2C_t *I2CDef, KT056x_SeekFreqStatus_t *SeekStatus)      // Check FreqIndexID OK
{
	if(KT_WirelessMicRx_GetRSSI(I2CDef) < UserSeekFreqConfig.SeekRssiThresholdLow)    // 小于RSSI低门限
	{
		SeekStatus->ReadRssiFailCnt++;
	}
	else
	{
		SeekStatus->ReadRssiFailCnt = 0;
	}
#ifdef	BpskEn                          // 手柄发了带ID的BPSK数据
    User_Bpsk_t *User_BpskData = (User_Bpsk_t *)&KT065x_BpskData;
	if(KT_WirelessMicRx_GetBpskSyncStatus(I2CDef))     // bpsk sync = 1
	{
		if(SeekStatus->flag.LoadDataOK)               // 保存数据OK
		{
			KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);          // Update bpsk Data
			// BPSK频道ID对上并且PrivateID为0(初次使用)或相等(已经配对的手柄)
			if((SeekStatus->SeekFreqIndex+1 == User_BpskData->FreqIndexID)&&((SeekStatus->PrivateID==0)||(User_BpskData->PrivateID==SeekStatus->PrivateID)))
			{
				SeekStatus->ReadBpskSyncFailCnt = 0;
			}
			else
			{
				SeekStatus->ReadBpskSyncFailCnt++;
			}
		}
		else                                         // Flash未保存数据,
		{
			if(SeekStatus->SeekFreqIndex+1 == User_BpskData->FreqIndexID)    // 忽略PrivateID数据内容,仅对FreqIndexID比较
			{
				SeekStatus->ReadBpskSyncFailCnt = 0;
			}
			else
			{
				SeekStatus->ReadBpskSyncFailCnt++;
			}
		}
	}
	else          // bpsk sync = 0
	{
		SeekStatus->ReadBpskSyncFailCnt++;
	}
#else
	if(KT_WirelessMicRx_GetPilotStatus(I2CDef))
	{
		SeekStatus->ReadBpskSyncFailCnt = 0;	// 读Bpsk失败次数,清零
	}
	else
	{
		SeekStatus->ReadBpskSyncFailCnt++;
	}
	if(KT_WirelessMicRx_GetVolume(I2CDef) != SeekStatus->CurrentVolume)
	{
		SeekStatus->flag.VolumeSmooth = 1;       // 渐出声音标记
	}
#endif
}

static void CheckFuncID(const SoftI2C_t *I2CDef, KT056x_SeekFreqStatus_t *SeekStatus)     // Check FunctionID
{
	User_Bpsk_t *User_BpskData = (User_Bpsk_t *)&KT065x_BpskData;
	uint16_t  PrivateIDold;
	KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);     // Update bpsk Data
	switch(User_BpskData->FunctionID)
	{
		case ChangePrivateID:                   // 手柄请求更改ID
		{
			if(SeekStatus->flag.ChangePrivateIDDis)     // 开机超时或已经更改了ID禁止操作
			{
				break;
			}
			if(KT_WirelessMicRx_GetRSSI(I2CDef) >= UserSeekFreqConfig.ChangeIDRssiThreshold)   // 达到修改门限
			{
				PrivateIDold = User_BpskData->PrivateID;
				Delay_Ms(100);
				KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);     // Update bpsk Data
				if(PrivateIDold != User_BpskData->PrivateID)
				{
					PrivateIDold = User_BpskData->PrivateID;
					Delay_Ms(100);
					KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);     // Update bpsk Data
					if(PrivateIDold != User_BpskData->PrivateID)
					{
						PrivateIDold = User_BpskData->PrivateID;
						Delay_Ms(100);
						KT_WirelessMicRx_GetAUXCH(I2CDef, (KT065xM_BpskData_t *)User_BpskData);     // Update bpsk Data
						if(PrivateIDold != User_BpskData->PrivateID)
						{
							break;   //
						}
					}
				}
				SeekStatus->PrivateID = PrivateIDold;          // Update PrivateID
				SeekStatus->flag.ChangePrivateIDDis = 1;       // 禁止修改PrivateID,保证开机只能修改一次
				SeekStatus->flag.SaveData = 1;                 // 需要保存标志
			}
			SeekStatus->SmoothVol = 0;
			KT_WirelessMicRx_Volume(I2CDef, 0);            // Volume写0
			;
		}break;
		case ChangeCurrentChannelID:                 // 手柄请求换台
		{
#ifndef  UserRandomSeek                     // 用户随机搜台
			if((UserSeekFreqConfig.StartFreq[SeekStatus->flag.ChannelNum] + (User_BpskData->FreqIndexID-1)*UserSeekFreqConfig.SeekFreqStep[SeekStatus->flag.ChannelNum]) <= UserSeekFreqConfig.EndFreq[SeekStatus->flag.ChannelNum])
			{
				SeekStatus->CurrentChannelFreq = UserSeekFreqConfig.StartFreq[SeekStatus->flag.ChannelNum] + (User_BpskData->FreqIndexID-1)*UserSeekFreqConfig.SeekFreqStep[SeekStatus->flag.ChannelNum];
#else
			if(User_BpskData->FreqIndexID <= UserSeekFreqConfig.UserRandomFreqIndexNum[SeekStatus->flag.ChannelNum])
			{
				SeekStatus->CurrentChannelFreq = UserSeekFreqConfig.UserRandomFreqIndexHead[SeekStatus->flag.ChannelNum][User_BpskData->FreqIndexID-1];
#endif
				SeekStatus->LastSeekFreqOKIndex = SeekStatus->SeekFreqIndex;     // 保存上一个有效台
				SeekStatus->SeekFreqIndex = User_BpskData->FreqIndexID-1;
				KT_WirelessMicRx_Tune(I2CDef, SeekStatus->CurrentChannelFreq);   // Tune
#ifdef	KT0656M_I2SEn
                if(SeekStatus->flag.ChannelNum==0)
                {
				    KT_WirelessMicRx_SAIInit(I2CDef, &I2SConfig_CHA);       // I2S  Re_Config
                }
                else
                {
                	KT_WirelessMicRx_SAIInit(I2CDef, &I2SConfig_CHB);       // I2S  Re_Config
                }
#endif
				SeekStatus->ReadRssiFailCnt = 0;    	// 读Rssi失败次数,清零
				SeekStatus->ReadBpskSyncFailCnt = 0;	// 读Bpsk失败次数,清零
				SeekStatus->flag.SaveData = 1;          // 需要保存标记置位

			}
		}break;
		case DisConnectID:                          // 手柄请求断开连接
		{
			SeekStatus->flag.VolumeSmooth = 0;
			SeekStatus->SmoothVol = 0;
			KT_WirelessMicRx_Volume(I2CDef, 0);
			SeekStatus->State = StartSeek;
		}break;
		default:break;
	}
	if(User_BpskData->FunctionID == VendorID)    //  手柄发厂商ID 0x88
	{
		if(KT_WirelessMicRx_GetVolume(I2CDef) != SeekStatus->CurrentVolume)
		{
			SeekStatus->flag.VolumeSmooth = 1;       // 渐出声音标记
//			uint8_t TempVol = 0;
//			while(TempVol < SeekStatus->CurrentVolume)
//			{
//				KT_WirelessMicRx_Volume(I2CDef, TempVol++);        // 渐出声音
//				DelayMs(5);
//			}
		}
	}
}

