/**************************************************************************************
*  Copyright (c) 2003,北京深思洛克数据保护中心
*  All rights reserved.
* 
*  文件名称：sense4.h
*  文件标识：
*  摘    要：定义深思IV动态连接库的接口函数，函数返回值定义，以及相关函数的参数定义
*
*  当前版本：2.3.1
*  作    者：huang jian
*  完成日期：2004/04/23
*  历史修改记录:
*
*		05/31/2005   Rename the product to EliteIV.
*       2004/04/23	v2.3.1	Huang Jian		增加设置USB模式与HID模式的功能
*******************************************************************************************/


#ifndef __SENSE4_H__
#define	__SENSE4_H__

#ifdef  _MSC_VER
#pragma comment(linker, "/defaultlib:setupapi.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif


#if defined WIN32 || defined _WIN32 || defined _WIN64
#include <windows.h>
typedef HANDLE S4HANDLE;

#elif defined __MACH__
typedef io_connect_t S4HANDLE;

#else
typedef void*           S4HANDLE;
#endif

#ifndef		IN
#define		IN
#endif

#ifndef		OUT
#define		OUT
#endif

#if !defined _WINDOWS_

#define WINAPI

#define CONST const

typedef unsigned char   UCHAR;
typedef unsigned short  USHORT;
typedef unsigned int    UINT;
typedef unsigned long   ULONG;

typedef char            CHAR;
typedef char			TCHAR;

typedef void			VOID;

#ifndef _BYTE_DEFINED
#define _BYTE_DEFINED
typedef unsigned char   BYTE;
#endif

#ifndef _WORD_DEFINED
#define _WORD_DEFINED
typedef unsigned short  WORD;
#endif

#ifndef _DWORD_DEFINED
#define _DWORD_DEFINED
typedef unsigned long   DWORD;
#endif

typedef VOID*			LPVOID;
typedef CHAR*           LPSTR;
typedef CONST CHAR*     LPCSTR;
typedef CONST TCHAR*	LPCTSTR;
typedef BYTE*			LPBYTE;
typedef WORD*			LPWORD;
typedef DWORD*			LPDWORD;

typedef void*			S4HANDLE;

#endif /* !defined _WINDOWS */

//@{ 
/** 
	S4OpenEx参数 
*/

/** 独占模式 */
#define S4_EXCLUSIZE_MODE			0

/** 共享模式 */ 
#define S4_SHARE_MODE				1

//@}

//@{
/**
	S4Control参数ctlCode定义
*/
/** LED亮 */
#define S4_LED_UP					0x00000004  

/** LED灭 */ 
#define S4_LED_DOWN					0x00000008  

/** LED闪烁 */ 
#define S4_LED_WINK					0x00000028  

/** 取设备类型 */
#define S4_GET_DEVICE_TYPE			0x00000025	

/** 取卡片序列号 */ 
#define S4_GET_SERIAL_NUMBER		0X00000026	

/** 取VM类型 */ 
#define S4_GET_VM_TYPE				0X00000027  

/** 取卡片可用空间 */ 
#define S4_GET_DEVICE_USABLE_SPACE	0x00000029  

/** 设置用户指定的ID到设备中 */
#define S4_SET_DEVICE_ID			0x0000002a   

/** 重置设备 */
#define S4_RESET_DEVICE             0x00000002  

/** 获得当前目录的剩余空间大小 */
#define S4_DF_AVAILABLE_SPACE       0x00000031  

/** 获得当前目录下某个文件的大小 */ 
#define S4_EF_INFO                  0x00000032  

/**设置设备模式为USB模式 */
#define S4_SET_USB_MODE                 0x00000041  

/** 设置设备模式为HID模式 */
#define S4_SET_HID_MODE                 0x00000042

#define S4_GET_CUSTOMER_NAME                    0x0000002b                      /** get the customer number*/
#define S4_GET_MANUFACTURE_DATE                 0x0000002c                      /** get the manufacture date of the device*/
#define S4_GET_CURRENT_TIME                     0x0000002d  

//@} 

//@{
/**
	S4Control当参数ctlCode为S4_GET_DEVICE_TYPE时取回的设备类型定义
*/
/** 单机锁 */
#define S4_LOCAL_DEVICE				0x00		
/** 网络主锁 */ 
#define S4_MASTER_DEVICE			0x01		
/** 网络从锁 */
#define S4_SLAVE_DEVICE				0x02		

//@} 

//@{
/**
	S4Control当参数ctlCode为S4_GET_VM_TYPE时取回的VM类型定义
*/
/** VM51 */
#define S4_VM_51					0x00
		
/** VM251 binary */ 
#define S4_VM_251_BINARY			0x01
		
/** VM251 source */
#define S4_VM_251_SOURCE	    	0X02		 

//@}

//@{
/**
	S4VerifyPin和S4ChangePin参数dwPinType定义
*/
/** 用户PIN */
#define	S4_USER_PIN					0x000000a1		

/** 开发尚PIN */  
#define S4_DEV_PIN					0x000000a2		 

/** S4ChangePin参数dwPinType定义,修改认证密钥 */
#define S4_AUTHEN_PIN				0x000000a3		 

//@}

//@{
/**
	S4WriteFile参数bFileType(文件类型)定义
*/

/** RSA公钥文件 */
#define S4_RSA_PUBLIC_FILE			0x00000006		

/** RSA私钥文件 */ 
#define S4_RSA_PRIVATE_FILE			0x00000007		

/** 可执行文件 */
#define S4_EXE_FILE					0x00000008		

/** 数据文件 */ 
#define S4_DATA_FILE				0x00000009		

/** XA User Mode方式编译的Bin文件 */ 
#define S4_XA_EXE_FILE				0x0000000b		

//@}

//@{
/**
	S4WriteFile参数dwFlags(标志)定义
*/

/** 建立新文件 */
#define S4_CREATE_NEW				0x000000a5		

/** 更新文件数据 */ 
#define S4_UPDATE_FILE				0x000000a6		

/** 硬件产生RSA密钥对 */ 
#define S4_KEY_GEN_RSA_FILE			0x000000a7		

/** 设置或改变当前目录下的授权数 */ 
#define S4_SET_LICENCES				0x000000a8	

/** 建立跟目录（只适用于空锁） */	
#define S4_CREATE_ROOT_DIR			0x000000ab		

/** 建立子目录 */ 
#define S4_CREATE_SUB_DIR			0x000000ac		

/** 建立模块（只适用于网络锁） */
#define S4_CREATE_MODULE			0x000000ad		

/**
	以下3个参数必须和S4_CREATE_NEW进行逻辑或运算
*/
/** 仅对EXE文件有效：VM可读写，默认值。 */
#define S4_FILE_READ_WRITE          0x00000000      

/** 仅对EXE文件有效：VM不可读写 */
#define S4_FILE_EXECUTE_ONLY        0x00000100   

/** 仅对EXE文件有效：创建填充文件 */   
#define S4_CREATE_PEDDING_FILE		0X00002000		

//@}

//@{
/** 以下两个参数是给S4ExecuteEx函数使用的
*/
/** 按照调用VM可执行文件方式执行，默认状态 */
#define S4_VM_EXE					0x00000000		

/** 按照调用XA可执行文件方式执行 */
#define S4_XA_EXE					0x00000001		

//@}

//@{
/**
	返回值定义
*/

/** 成功返回 */
#define	S4_SUCCESS					0x00000000	

/** 设备下电 */	 
#define S4_UNPOWERED				0x00000001

/** 参数错误 */
#define	S4_INVALID_PARAMETER		0x00000002

/** 传输超时 */
#define S4_COMM_ERROR				0x00000003

/** 协议错误 */
#define S4_PROTOCOL_ERROR			0x00000004

/** 设备忙 */
#define S4_DEVICE_BUSY				0x00000005

/** 设备未连接 */
#define S4_KEY_REMOVED				0x00000006

/** 参数数组空间不够 */
#define S4_INSUFFICIENT_BUFFER		0x00000011


#define S4_NO_LIST					0x00000012
#define S4_GENERAL_ERROR			0x00000013

/** 功能不支持或没有文件系统 */
#define S4_UNSUPPORTED				0x00000014

/** 设备类型不匹配 */
#define S4_DEVICE_TYPE_MISMATCH		0x00000020

/** 建立EXE文件时，文件空间跨越地址0x7FFF */
#define S4_FILE_SIZE_CROSS_7FFF		0x00000021

/**
	创建网络版模块时，如果当前目录不是根目录，则返回该错误。
 */
#define S4_CURRENT_DF_ISNOT_MF		0x00000201

/**
	对于某些操作，比如设置授权操作。必须在模块下完成。如果此时不在合法模块下，返回该错误。
 */
#define S4_INVAILABLE_MODULE_DF			0x00000202

/**
	下载文件时，设置的文件大小超过0x7FFF，或者偏移与Buffer的和超过0x7FFF
 */
#define S4_FILE_SIZE_TOO_LARGE		0x00000203
	
/**
	创建目录时，该目录大小太小了。对于网络版，目录最小大小988字节。
	对于单机版目录大小最小为134字节。
 */
#define S4_DF_SIZE					0x00000204	

/** 该硬件设备不支持该项功能 */
#define S4_DEVICE_UNSUPPORTED		0x00006a81

/** 未找到指定文件 */
#define S4_FILE_NOT_FOUND			0x00006a82

/** 安全状态不满足 */
#define S4_INSUFFICIENT_SECU_STATE  0x00006982

/** 目录已存在 */
#define S4_DIRECTORY_EXIST			0x00006901

/** 文件已存在 */
#define S4_FILE_EXIST				0x00006a80

/** 卡片空间不够 */
#define S4_INSUFFICIENT_SPACE		0x00006a84

/** 偏移量越界 */
#define S4_OFFSET_BEYOND			0x00006B00

/** 密钥被锁 */
#define S4_PIN_BLOCK				0x00006983

/** 文件类型不匹配 */
#define	S4_FILE_TYPE_MISMATCH		0x00006981

/** 密钥未找到 */
#define S4_CRYPTO_KEY_NOT_FOUND		0x00009403

/** 应用临时锁定 */
#define S4_APPLICATION_TEMP_BLOCK	0x00006985

/** 应用永久锁定 */
#define S4_APPLICATION_PERM_BLOCK	0x00009303

/** 数据缓冲区长度错误 */
#define S4_DATA_BUFFER_LENGTH_ERROR	0x00006700	

/** Code区越界 */	
#define S4_CODE_RANGE				0x00010000

/**  使用了保留指令 "RET I" */	
#define S4_CODE_RESERVED_INST		0x00020000

/** 片内RAM越界 */	
#define S4_CODE_RAM_RANGE			0x00040000

/** 位操作越界 */	
#define S4_CODE_BIT_RANGE			0x00080000

/** 特殊功能寄存器越界 */	
#define S4_CODE_SFR_RANGE			0x00100000

/**  片外RAM越界 */	
#define S4_CODE_XRAM_RANGE			0x00200000

/** 未知的错误 */
#define S4_ERROR_UNKNOWN			0xffffffff

//@}

/** 最长的ATR定义 */
#define MAX_ATR_LEN					56					

/** 最长的ID定义 */
#define MAX_ID_LEN					8		
			 
#define S4_RSA_MODULUS_LEN			128
#define S4_RSA_PRIME_LEN			64

//@{
/**
	结构体定义
*/
/* file information definition*/
typedef struct{
	WORD EfID;
	BYTE EfType;
	WORD EfSize;
}EFINFO,*PEFINFO;

/* device production date structure definition*/
typedef struct {
        WORD    wYear;                                                          /* year*/
        BYTE    byMonth;                                                        /* month*/
        BYTE    byDay;                                                          /* the day of the month */
}S4_MANUFACTURE_DATE;

/* current time structure definition*/
#ifndef _TM_DEFINED

typedef struct {
        int tm_sec;                                                             /* seconds after the minute - [0,59] */
        int tm_min;                                                             /* minutes after the hour - [0,59] */
        int tm_hour;                                                            /* hours since midnight - [0,23] */
        int tm_mday;                                                            /* day of the month - [1,31] */
        int tm_mon;                                                             /* months since January - [0,11] */
        int tm_year;                                                            /* years since 1900 */
        int tm_wday;                                                            /* days since Sunday - [0,6] */
        int tm_yday;                                                            /* days since January 1 - [0,365] */
        int tm_isdst;                                                           /* daylight savings time flag */
} TM;
#define _TM_DEFINED
#endif

/** 
	设备的版本类型定义，对应SENSE4_CONTEXT.dwVersion，原来的定义去掉 
*/
typedef enum{
	/** 深思IV 2.0版本 */
	SENSE4_CARD_TYPE_V2_00 = 0x00020000,				
	/** 深思IV 2.1版本 */
	SENSE4_CARD_TYPE_V2_01 = 0x00020001,				
	/** 深思IV 2.2版本 */
	SENSE4_CARD_TYPE_V2_02 = 0x00020002,				
	/** 深思IV 2.3版本 */
	SENSE4_CARD_TYPE_V2_30 = 0x00020300					
}CARD_VERSION;


/** 
	深思IV设备信息定义 
*/
typedef struct {
	/** 设备索引，从0开始编号 */
	DWORD 			dwIndex;							
	/** 版本号 */ 
	DWORD			dwVersion;	
	/** 设备句柄 */
	S4HANDLE		hLock;			
	/** 系统保留 */
	BYTE			reserve[12];						
	/** ATR信息 */
	BYTE			bAtr[MAX_ATR_LEN];					
	/** ID号 */
	BYTE			bID[MAX_ID_LEN];					
	/** ATR长度 */
	DWORD			dwAtrLen;							
}SENSE4_CONTEXT,*PSENSE4_CONTEXT;



/** RSA公钥格式定义 */
typedef struct {
  unsigned char modulus[S4_RSA_MODULUS_LEN];			// modulus 
  unsigned char exponent[S4_RSA_MODULUS_LEN];			// public exponent 
} S4_RSA_PUBLIC_KEY;


/** RSA私钥格式定义 */
typedef struct {
  unsigned char modulus[S4_RSA_MODULUS_LEN];			// modulus 
  unsigned char publicExponent[S4_RSA_MODULUS_LEN];		// public exponent 
  unsigned char exponent[S4_RSA_MODULUS_LEN];			// private exponent 
  unsigned char prime[2][S4_RSA_PRIME_LEN];				// prime factors 
  unsigned char primeExponent[2][S4_RSA_PRIME_LEN];		// exponents for CRT 
  unsigned char coefficient[S4_RSA_PRIME_LEN];			// CRT coefficient 
} S4_RSA_PRIVATE_KEY;


typedef struct _S4CREATEDIRINFO {
	DWORD dwS4CreateDirInfoSize;
	BYTE  szAtr[8];
} S4CREATEDIRINFO;

typedef struct _S4OPENINFO {
	DWORD dwS4OpenInfoSize;
	DWORD dwShareMode;
} S4OPENINFO;

//@}


//@{
/** 
	@接口函数
*/

unsigned long WINAPI S4Startup(void);


unsigned long WINAPI S4Cleanup(void);


/**
		列举所有联机的SenseIV设备，以dwIndex作为唯一标识。
		如果参数s4CtxList=NULL，则在lpCtxListSize中返回需要的空间大小。
							
		@参数 s4CtxList			[out]		存放返回的设备列表地址
		@参数 lpCtxListSize		[in][out]	返回s4CtxList分配的实际空间大小

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.
  
*/
DWORD WINAPI S4Enum(
	OUT	SENSE4_CONTEXT *s4CtxList,
	IN OUT LPDWORD		lpCtxListSize
);


/**
		连接指定的深思IV设备，返回该设备句柄。
							
		@参数 s4Ctx			[in][out]	要连接的SenseIV设备的指针
			
		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.
						
*/
DWORD WINAPI S4Open(
	IN OUT	SENSE4_CONTEXT *s4Ctx
);


/**
		断开指定SenseIV设备的连接，
							
		@参数 s4Ctx			[in]	 指定的已打开的Sense4设备的指针

			
		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.
						
*/
DWORD WINAPI S4Close(
	IN	SENSE4_CONTEXT *s4Ctx
);


/**
		设置设备的控制信息，如超时设置, 指示灯设置，获得设备类型，VM类型等。
							
		@参数 s4Ctx				[in]  指定的已打开的Sense4设备的指针
		@参数 ctlCode			[in]  控制设备的命令
		@参数 inBuff			[in]  输入缓冲指针
		@参数 inBuffLen			[in]  输入缓冲inBuff长度
		@参数 outBuff			[out] 输出缓冲指针
		@参数 outBuffLen		[in]  输出缓冲outBuff长度
		@参数 bytesReturned		[out] 实际返回数据字节数的指针，不能为NULL。

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.
						
*/
DWORD WINAPI S4Control(
	IN 	SENSE4_CONTEXT		*s4Ctx,
	IN	DWORD				ctlCode,
	IN	LPVOID				inBuff,
	IN	DWORD				inBuffLen,
	OUT	LPVOID				outBuff,
	IN	DWORD				outBuffLen,
	OUT	LPDWORD				bytesReturned
);	


/**
							
		在当前目录下建立新目录，建立新目录成功之后，当前目录切换为新目录。
		
		@参数 s4Ctx				[in]  指定的已打开的Sense4设备的指针
		@参数 lpszDirID			[in]  要建立的目录ID，4个字符
		@参数 dwDirSize			[in]  要建立的目录的空间大小
		@参数 dwFlags			[in]  建立目录时的标志选项

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.
						
*/
DWORD WINAPI S4CreateDir(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCSTR			lpszDirID,
	IN	DWORD			dwDirSize,
	IN	DWORD			dwFlags
);


/**
		选择新的工作目录。
							
		@参数 s4Ctx				[in]  指定的已打开的Sense4设备的指针
		@参数 lpszPath			[in]  新工作目录路径的指针

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.
						
*/
DWORD WINAPI S4ChangeDir(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCSTR			lpszPath
);


/**
		擦除当前目录下所有内容
							
		@参数 s4Ctx				[in]  指定的已打开的Sense4设备的指针
		@参数 lpszDirID			[in]  此参数忽略，输入NULL

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.				
						
*/
DWORD WINAPI S4EraseDir(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCTSTR			lpszDirID
);


/**
		校验当前目录的开发商PIN或者用户PIN，获得相应访问权限。
							
		@参数 s4Ctx				[in]  指定的已打开的Sense4设备的指针
		@参数 lpPin				[in]  待校验的PIN码的指针，用户PIN码为8字节，开发商PIN码为24字节
		@参数 dwPinLen			[in]  待校验的PIN码长度
		@参数 dwPinType			[in]  待校验的PIN类型

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.								
						
*/
DWORD WINAPI S4VerifyPin(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPBYTE			lpPin,
	IN	DWORD			dwPinLen,
	IN	DWORD			dwPinType
);


/**
		更改当前目录的各种PIN码。
							
		@参数 s4Ctx				[in]  指定的已打开的Sense4设备的指针
		@参数 lpOldPin			[in]  旧PIN码的指针
		@参数 dwOldPinLen		[in]  旧PIN码的长度
		@参数 lpNewPin			[in]  新PIN码的指针
		@参数 dwNewPinLen		[in]  新PIN码的长度
		@参数 dwPinType			[in]  要修改的PIN类型

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.												
						
*/
DWORD WINAPI S4ChangePin(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPBYTE			lpOldPin,
	IN	DWORD			dwOldPinLen,
	IN	LPBYTE			lpNewPin,
	IN	DWORD			dwNewPinLen,
	IN	DWORD			dwPinType
);


/**
		在当前目录下进行写文件操作。
							
		@参数 s4Ctx				[in]  指定的已打开的Sense4设备的指针
		@参数 lpszFileID		[in]  指向文件ID的指针
		@参数 dwOffset			[in]  从文件头开始的地址偏移量。
		@参数 lpBuffer			[in]  指向写入文件的内容的指针。
		@参数 dwBufferSize		[in]  要写入文件的内容字节数。
		@参数 dwFileSize		[in]  创建文件的长度。
		@参数 lpBytesWritten	[out] 返回实际写入的字节数。
		@参数 dwFlags			[in]  标志项
		@参数 bFileType			[in]  文件类型，

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.																
						
*/
DWORD WINAPI S4WriteFile(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCSTR			lpszFileID,
	IN 	DWORD			dwOffset,
	IN	LPVOID			lpBuffer,
	IN	DWORD			dwBufferSize,
	IN	DWORD			dwFileSize,
	OUT LPDWORD			lpBytesWritten,
	IN	DWORD			dwFlags,
	IN	BYTE			bFileType
);


/**
		当前目录下执行可执行文件
							
		@参数 s4Ctx					[in]  指定的已打开的Sense4设备的指针
		@参数 lpszFileID			[in]  指向文件ID的指针
		@参数 lpInBuffer			[in]  指向输入参数的指针
		@参数 dwInbufferSize		[in]  输入缓冲区大小
		@参数 lpOutBuffer			[out] 输出数据缓冲区
		@参数 dwOutBufferSize		[in]  输出数据缓冲区大小
		@参数 lpBytesReturned		[out] 实际返回结果的长度

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.																

*/
DWORD WINAPI S4Execute(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCSTR			lpszFileID,
	IN	LPVOID			lpInBuffer,
	IN	DWORD			dwInbufferSize,
	OUT	LPVOID			lpOutBuffer,
	IN 	DWORD			dwOutBufferSize,
	OUT	LPDWORD			lpBytesReturned
);

/**
		当前目录下执行可执行文件，也可以执行XA二进制文件
							
		@参数 s4Ctx					[in]  指定的已打开的Sense4设备的指针
		@参数 lpszFileID			[in]  指向文件ID的指针
		@参数 dwFlag				[in]  执行文件的参数
		@参数 lpInBuffer			[in]  指向输入参数的指针
		@参数 dwInbufferSize		[in]  输入缓冲区大小
		@参数 lpOutBuffer			[out] 输出数据缓冲区
		@参数 dwOutBufferSize		[in]  输出数据缓冲区大小
		@参数 lpBytesReturned		[out] 实际返回结果的长度

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.																

*/
DWORD WINAPI S4ExecuteEx(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCSTR			lpszFileID,
	IN  DWORD			dwFlag,
	IN	LPVOID			lpInBuffer,
	IN	DWORD			dwInbufferSize,
	OUT	LPVOID			lpOutBuffer,
	IN 	DWORD			dwOutBufferSize,
	OUT	LPDWORD			lpBytesReturned
);





/**
		在当前目录下建立新目录，建立新目录成功之后，当前目录切换为新目录。
		建立MF文件时，强制建立ATR文件

		@参数 s4Ctx				[in]  指定的已打开的Sense4设备的指针
		@参数 lpszDirID			[in]  要建立的目录ID，4个字符
		@参数 dwDirSize			[in]  要建立的目录的空间大小
		@参数 dwFlags			[in]  建立目录时的标志选项
		@参数 pRootInfo			[in]  当建立MF时，该参数填入根目录ATR信息

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.																

*/
DWORD WINAPI S4CreateDirEx(
	IN  SENSE4_CONTEXT  *s4Ctx,
	IN  LPCSTR  		lpszDirID,
	IN  DWORD  			dwDirSize,
	IN  DWORD  			dwFlags,
	IN  S4CREATEDIRINFO	*pCreateDirInfo
);
						   


/**
		按照pS4OpenInfo中dwShareMode成员的共享、独占意义，打开锁
	
		@参数 s4Ctx					[in][out]	列举后的要连接的S4指针
		@参数 pS4OpenInfo			[in]		填入打开锁的共享、独占信息

		@返回值 如果成功,返回0 (S4_SUCCESS).<br>
		如果失败, 返回值非0.																

*/
DWORD WINAPI S4OpenEx(
	IN  OUT  	SENSE4_CONTEXT 	*s4Ctx,
	IN			S4OPENINFO		*pS4OpenInfo
);


#define S4WF_INVALID_S4CONTEXT		0x00000101
#define S4WF_INVALID_FILE_ID		0x00000102
#define S4WF_INVALID_PC_FILE		0x00000103
#define S4WF_INVALID_FLAGS			0x00000104
#define S4WF_INVALID_FILE_SIZE		0x00000105
#define S4WF_INVALID_FILE_TYPE		0x00000106

//补充了下载hex文件的参数
#define S4_HEX_FILE					0x0000000a
//补充了下载XA_hex文件的参数
#define S4_XA_HEX_FILE				0x0000000c


DWORD WINAPI PS4WriteFile(
	IN	CONST SENSE4_CONTEXT * ps4Ctx,
	IN	LPCSTR	lpszFileID,
	IN	LPCSTR	lpszPCFilePath,
	IN	OUT DWORD * lpdwFileSize,//注意输入的参数是一个指针
	IN	DWORD dwFlags,
	IN	DWORD dwFileType,
	OUT LPDWORD lpdwBytesWritten
	);


//@}						  

#ifdef __cplusplus
}
#endif

#endif  //__SENSE4_H__
