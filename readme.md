# KT0206平台代码上手指导：
用户主要关心如下几个文件  
\src\user\user_kt\user.c	--用户程序文件  
\src\user\user_kt\user.h	--用户头文件  
\src\API\api.c				--API接口函数  
\src\user_demo\*			--SDK的相关使用例程，比如常用的GPIO、串口、旋钮调音量等操作 

#### 用户代码  
在user.c中用户最先需要关心如下3个函数：  
void _user_schedule(void)  
void _user_init(void)  
void _user_delay_init(void)  

用户的第一条代码是在_user_init函数中执行，_user_init执行完会跳到_user_schedule中不断循环，_user_schedule可以看做是平时MCU中写的while(1)循环。  
在_user_init函数一般放IO的初始化。  
在_user_delay_init()是放一些需要延迟初始化的功能函数，比如音效使能。  


#### 关于用户软件定时器的使用：  
addUserTimerEvent()参数说明：  
pEvent 		：需要调用的函数指针；  
delayTime  	：延时的时间  
timerType	：定时器类型，timerOnce：执行一次；timerPeriod：不断循环。  
void addUserTimerEvent(void (*pEvent)(void) ,uint32_t delayTime,timerTypeEnum timerType)


#### 使用I2S特别说明：
对于使用I2S并且需要保持I2S的时钟不断，需要配置EFFECT_POST_SIDETONE_EN为1，如果不需要实时监听可以把SIDETONE_DEF_STAT配置为0；


# 集成开发环境使用

#### 工程代码导入
安装完成后File > Import > General > Existing Projects into Workspace, 选择我们的源码包目录即可。


#### 设置开发环境的默认编码格式
统一设置为UTF-8，避免中文乱码影响到代码编译。
菜单 > window > preferences 打开后 General > Workspace > Text file encoding > Other 选择UTF-8



# 其他说明
1. 文件夹名称叫KT020X_bootLibProj，boot代表的是芯片带boot程序，lib代表的是音效封装成了函数库。
2. 原来工程想叫KT0206_bootLibProj，专门跟踪KT0206的代码，但是因为有些KT0200或者KT0201的代码可能也会超过256K，也需要boot，故名称改为KT020X_bootLibProj。