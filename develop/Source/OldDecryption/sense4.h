/**************************************************************************************
*  Copyright (c) 2003,������˼������ݱ�������
*  All rights reserved.
* 
*  �ļ����ƣ�sense4.h
*  �ļ���ʶ��
*  ժ    Ҫ��������˼IV��̬���ӿ�Ľӿں�������������ֵ���壬�Լ���غ����Ĳ�������
*
*  ��ǰ�汾��2.3.1
*  ��    �ߣ�huang jian
*  ������ڣ�2004/04/23
*  ��ʷ�޸ļ�¼:
*
*		05/31/2005   Rename the product to EliteIV.
*       2004/04/23	v2.3.1	Huang Jian		��������USBģʽ��HIDģʽ�Ĺ���
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
	S4OpenEx���� 
*/

/** ��ռģʽ */
#define S4_EXCLUSIZE_MODE			0

/** ����ģʽ */ 
#define S4_SHARE_MODE				1

//@}

//@{
/**
	S4Control����ctlCode����
*/
/** LED�� */
#define S4_LED_UP					0x00000004  

/** LED�� */ 
#define S4_LED_DOWN					0x00000008  

/** LED��˸ */ 
#define S4_LED_WINK					0x00000028  

/** ȡ�豸���� */
#define S4_GET_DEVICE_TYPE			0x00000025	

/** ȡ��Ƭ���к� */ 
#define S4_GET_SERIAL_NUMBER		0X00000026	

/** ȡVM���� */ 
#define S4_GET_VM_TYPE				0X00000027  

/** ȡ��Ƭ���ÿռ� */ 
#define S4_GET_DEVICE_USABLE_SPACE	0x00000029  

/** �����û�ָ����ID���豸�� */
#define S4_SET_DEVICE_ID			0x0000002a   

/** �����豸 */
#define S4_RESET_DEVICE             0x00000002  

/** ��õ�ǰĿ¼��ʣ��ռ��С */
#define S4_DF_AVAILABLE_SPACE       0x00000031  

/** ��õ�ǰĿ¼��ĳ���ļ��Ĵ�С */ 
#define S4_EF_INFO                  0x00000032  

/**�����豸ģʽΪUSBģʽ */
#define S4_SET_USB_MODE                 0x00000041  

/** �����豸ģʽΪHIDģʽ */
#define S4_SET_HID_MODE                 0x00000042

#define S4_GET_CUSTOMER_NAME                    0x0000002b                      /** get the customer number*/
#define S4_GET_MANUFACTURE_DATE                 0x0000002c                      /** get the manufacture date of the device*/
#define S4_GET_CURRENT_TIME                     0x0000002d  

//@} 

//@{
/**
	S4Control������ctlCodeΪS4_GET_DEVICE_TYPEʱȡ�ص��豸���Ͷ���
*/
/** ������ */
#define S4_LOCAL_DEVICE				0x00		
/** �������� */ 
#define S4_MASTER_DEVICE			0x01		
/** ������� */
#define S4_SLAVE_DEVICE				0x02		

//@} 

//@{
/**
	S4Control������ctlCodeΪS4_GET_VM_TYPEʱȡ�ص�VM���Ͷ���
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
	S4VerifyPin��S4ChangePin����dwPinType����
*/
/** �û�PIN */
#define	S4_USER_PIN					0x000000a1		

/** ������PIN */  
#define S4_DEV_PIN					0x000000a2		 

/** S4ChangePin����dwPinType����,�޸���֤��Կ */
#define S4_AUTHEN_PIN				0x000000a3		 

//@}

//@{
/**
	S4WriteFile����bFileType(�ļ�����)����
*/

/** RSA��Կ�ļ� */
#define S4_RSA_PUBLIC_FILE			0x00000006		

/** RSA˽Կ�ļ� */ 
#define S4_RSA_PRIVATE_FILE			0x00000007		

/** ��ִ���ļ� */
#define S4_EXE_FILE					0x00000008		

/** �����ļ� */ 
#define S4_DATA_FILE				0x00000009		

/** XA User Mode��ʽ�����Bin�ļ� */ 
#define S4_XA_EXE_FILE				0x0000000b		

//@}

//@{
/**
	S4WriteFile����dwFlags(��־)����
*/

/** �������ļ� */
#define S4_CREATE_NEW				0x000000a5		

/** �����ļ����� */ 
#define S4_UPDATE_FILE				0x000000a6		

/** Ӳ������RSA��Կ�� */ 
#define S4_KEY_GEN_RSA_FILE			0x000000a7		

/** ���û�ı䵱ǰĿ¼�µ���Ȩ�� */ 
#define S4_SET_LICENCES				0x000000a8	

/** ������Ŀ¼��ֻ�����ڿ����� */	
#define S4_CREATE_ROOT_DIR			0x000000ab		

/** ������Ŀ¼ */ 
#define S4_CREATE_SUB_DIR			0x000000ac		

/** ����ģ�飨ֻ�������������� */
#define S4_CREATE_MODULE			0x000000ad		

/**
	����3�����������S4_CREATE_NEW�����߼�������
*/
/** ����EXE�ļ���Ч��VM�ɶ�д��Ĭ��ֵ�� */
#define S4_FILE_READ_WRITE          0x00000000      

/** ����EXE�ļ���Ч��VM���ɶ�д */
#define S4_FILE_EXECUTE_ONLY        0x00000100   

/** ����EXE�ļ���Ч����������ļ� */   
#define S4_CREATE_PEDDING_FILE		0X00002000		

//@}

//@{
/** �������������Ǹ�S4ExecuteEx����ʹ�õ�
*/
/** ���յ���VM��ִ���ļ���ʽִ�У�Ĭ��״̬ */
#define S4_VM_EXE					0x00000000		

/** ���յ���XA��ִ���ļ���ʽִ�� */
#define S4_XA_EXE					0x00000001		

//@}

//@{
/**
	����ֵ����
*/

/** �ɹ����� */
#define	S4_SUCCESS					0x00000000	

/** �豸�µ� */	 
#define S4_UNPOWERED				0x00000001

/** �������� */
#define	S4_INVALID_PARAMETER		0x00000002

/** ���䳬ʱ */
#define S4_COMM_ERROR				0x00000003

/** Э����� */
#define S4_PROTOCOL_ERROR			0x00000004

/** �豸æ */
#define S4_DEVICE_BUSY				0x00000005

/** �豸δ���� */
#define S4_KEY_REMOVED				0x00000006

/** ��������ռ䲻�� */
#define S4_INSUFFICIENT_BUFFER		0x00000011


#define S4_NO_LIST					0x00000012
#define S4_GENERAL_ERROR			0x00000013

/** ���ܲ�֧�ֻ�û���ļ�ϵͳ */
#define S4_UNSUPPORTED				0x00000014

/** �豸���Ͳ�ƥ�� */
#define S4_DEVICE_TYPE_MISMATCH		0x00000020

/** ����EXE�ļ�ʱ���ļ��ռ��Խ��ַ0x7FFF */
#define S4_FILE_SIZE_CROSS_7FFF		0x00000021

/**
	���������ģ��ʱ�������ǰĿ¼���Ǹ�Ŀ¼���򷵻ظô���
 */
#define S4_CURRENT_DF_ISNOT_MF		0x00000201

/**
	����ĳЩ����������������Ȩ������������ģ������ɡ������ʱ���ںϷ�ģ���£����ظô���
 */
#define S4_INVAILABLE_MODULE_DF			0x00000202

/**
	�����ļ�ʱ�����õ��ļ���С����0x7FFF������ƫ����Buffer�ĺͳ���0x7FFF
 */
#define S4_FILE_SIZE_TOO_LARGE		0x00000203
	
/**
	����Ŀ¼ʱ����Ŀ¼��С̫С�ˡ���������棬Ŀ¼��С��С988�ֽڡ�
	���ڵ�����Ŀ¼��С��СΪ134�ֽڡ�
 */
#define S4_DF_SIZE					0x00000204	

/** ��Ӳ���豸��֧�ָ���� */
#define S4_DEVICE_UNSUPPORTED		0x00006a81

/** δ�ҵ�ָ���ļ� */
#define S4_FILE_NOT_FOUND			0x00006a82

/** ��ȫ״̬������ */
#define S4_INSUFFICIENT_SECU_STATE  0x00006982

/** Ŀ¼�Ѵ��� */
#define S4_DIRECTORY_EXIST			0x00006901

/** �ļ��Ѵ��� */
#define S4_FILE_EXIST				0x00006a80

/** ��Ƭ�ռ䲻�� */
#define S4_INSUFFICIENT_SPACE		0x00006a84

/** ƫ����Խ�� */
#define S4_OFFSET_BEYOND			0x00006B00

/** ��Կ���� */
#define S4_PIN_BLOCK				0x00006983

/** �ļ����Ͳ�ƥ�� */
#define	S4_FILE_TYPE_MISMATCH		0x00006981

/** ��Կδ�ҵ� */
#define S4_CRYPTO_KEY_NOT_FOUND		0x00009403

/** Ӧ����ʱ���� */
#define S4_APPLICATION_TEMP_BLOCK	0x00006985

/** Ӧ���������� */
#define S4_APPLICATION_PERM_BLOCK	0x00009303

/** ���ݻ��������ȴ��� */
#define S4_DATA_BUFFER_LENGTH_ERROR	0x00006700	

/** Code��Խ�� */	
#define S4_CODE_RANGE				0x00010000

/**  ʹ���˱���ָ�� "RET I" */	
#define S4_CODE_RESERVED_INST		0x00020000

/** Ƭ��RAMԽ�� */	
#define S4_CODE_RAM_RANGE			0x00040000

/** λ����Խ�� */	
#define S4_CODE_BIT_RANGE			0x00080000

/** ���⹦�ܼĴ���Խ�� */	
#define S4_CODE_SFR_RANGE			0x00100000

/**  Ƭ��RAMԽ�� */	
#define S4_CODE_XRAM_RANGE			0x00200000

/** δ֪�Ĵ��� */
#define S4_ERROR_UNKNOWN			0xffffffff

//@}

/** ���ATR���� */
#define MAX_ATR_LEN					56					

/** ���ID���� */
#define MAX_ID_LEN					8		
			 
#define S4_RSA_MODULUS_LEN			128
#define S4_RSA_PRIME_LEN			64

//@{
/**
	�ṹ�嶨��
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
	�豸�İ汾���Ͷ��壬��ӦSENSE4_CONTEXT.dwVersion��ԭ���Ķ���ȥ�� 
*/
typedef enum{
	/** ��˼IV 2.0�汾 */
	SENSE4_CARD_TYPE_V2_00 = 0x00020000,				
	/** ��˼IV 2.1�汾 */
	SENSE4_CARD_TYPE_V2_01 = 0x00020001,				
	/** ��˼IV 2.2�汾 */
	SENSE4_CARD_TYPE_V2_02 = 0x00020002,				
	/** ��˼IV 2.3�汾 */
	SENSE4_CARD_TYPE_V2_30 = 0x00020300					
}CARD_VERSION;


/** 
	��˼IV�豸��Ϣ���� 
*/
typedef struct {
	/** �豸��������0��ʼ��� */
	DWORD 			dwIndex;							
	/** �汾�� */ 
	DWORD			dwVersion;	
	/** �豸��� */
	S4HANDLE		hLock;			
	/** ϵͳ���� */
	BYTE			reserve[12];						
	/** ATR��Ϣ */
	BYTE			bAtr[MAX_ATR_LEN];					
	/** ID�� */
	BYTE			bID[MAX_ID_LEN];					
	/** ATR���� */
	DWORD			dwAtrLen;							
}SENSE4_CONTEXT,*PSENSE4_CONTEXT;



/** RSA��Կ��ʽ���� */
typedef struct {
  unsigned char modulus[S4_RSA_MODULUS_LEN];			// modulus 
  unsigned char exponent[S4_RSA_MODULUS_LEN];			// public exponent 
} S4_RSA_PUBLIC_KEY;


/** RSA˽Կ��ʽ���� */
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
	@�ӿں���
*/

unsigned long WINAPI S4Startup(void);


unsigned long WINAPI S4Cleanup(void);


/**
		�о�����������SenseIV�豸����dwIndex��ΪΨһ��ʶ��
		�������s4CtxList=NULL������lpCtxListSize�з�����Ҫ�Ŀռ��С��
							
		@���� s4CtxList			[out]		��ŷ��ص��豸�б��ַ
		@���� lpCtxListSize		[in][out]	����s4CtxList�����ʵ�ʿռ��С

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.
  
*/
DWORD WINAPI S4Enum(
	OUT	SENSE4_CONTEXT *s4CtxList,
	IN OUT LPDWORD		lpCtxListSize
);


/**
		����ָ������˼IV�豸�����ظ��豸�����
							
		@���� s4Ctx			[in][out]	Ҫ���ӵ�SenseIV�豸��ָ��
			
		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.
						
*/
DWORD WINAPI S4Open(
	IN OUT	SENSE4_CONTEXT *s4Ctx
);


/**
		�Ͽ�ָ��SenseIV�豸�����ӣ�
							
		@���� s4Ctx			[in]	 ָ�����Ѵ򿪵�Sense4�豸��ָ��

			
		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.
						
*/
DWORD WINAPI S4Close(
	IN	SENSE4_CONTEXT *s4Ctx
);


/**
		�����豸�Ŀ�����Ϣ���糬ʱ����, ָʾ�����ã�����豸���ͣ�VM���͵ȡ�
							
		@���� s4Ctx				[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� ctlCode			[in]  �����豸������
		@���� inBuff			[in]  ���뻺��ָ��
		@���� inBuffLen			[in]  ���뻺��inBuff����
		@���� outBuff			[out] �������ָ��
		@���� outBuffLen		[in]  �������outBuff����
		@���� bytesReturned		[out] ʵ�ʷ��������ֽ�����ָ�룬����ΪNULL��

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.
						
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
							
		�ڵ�ǰĿ¼�½�����Ŀ¼��������Ŀ¼�ɹ�֮�󣬵�ǰĿ¼�л�Ϊ��Ŀ¼��
		
		@���� s4Ctx				[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpszDirID			[in]  Ҫ������Ŀ¼ID��4���ַ�
		@���� dwDirSize			[in]  Ҫ������Ŀ¼�Ŀռ��С
		@���� dwFlags			[in]  ����Ŀ¼ʱ�ı�־ѡ��

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.
						
*/
DWORD WINAPI S4CreateDir(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCSTR			lpszDirID,
	IN	DWORD			dwDirSize,
	IN	DWORD			dwFlags
);


/**
		ѡ���µĹ���Ŀ¼��
							
		@���� s4Ctx				[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpszPath			[in]  �¹���Ŀ¼·����ָ��

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.
						
*/
DWORD WINAPI S4ChangeDir(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCSTR			lpszPath
);


/**
		������ǰĿ¼����������
							
		@���� s4Ctx				[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpszDirID			[in]  �˲������ԣ�����NULL

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.				
						
*/
DWORD WINAPI S4EraseDir(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPCTSTR			lpszDirID
);


/**
		У�鵱ǰĿ¼�Ŀ�����PIN�����û�PIN�������Ӧ����Ȩ�ޡ�
							
		@���� s4Ctx				[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpPin				[in]  ��У���PIN���ָ�룬�û�PIN��Ϊ8�ֽڣ�������PIN��Ϊ24�ֽ�
		@���� dwPinLen			[in]  ��У���PIN�볤��
		@���� dwPinType			[in]  ��У���PIN����

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.								
						
*/
DWORD WINAPI S4VerifyPin(
	IN	SENSE4_CONTEXT *s4Ctx,
	IN	LPBYTE			lpPin,
	IN	DWORD			dwPinLen,
	IN	DWORD			dwPinType
);


/**
		���ĵ�ǰĿ¼�ĸ���PIN�롣
							
		@���� s4Ctx				[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpOldPin			[in]  ��PIN���ָ��
		@���� dwOldPinLen		[in]  ��PIN��ĳ���
		@���� lpNewPin			[in]  ��PIN���ָ��
		@���� dwNewPinLen		[in]  ��PIN��ĳ���
		@���� dwPinType			[in]  Ҫ�޸ĵ�PIN����

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.												
						
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
		�ڵ�ǰĿ¼�½���д�ļ�������
							
		@���� s4Ctx				[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpszFileID		[in]  ָ���ļ�ID��ָ��
		@���� dwOffset			[in]  ���ļ�ͷ��ʼ�ĵ�ַƫ������
		@���� lpBuffer			[in]  ָ��д���ļ������ݵ�ָ�롣
		@���� dwBufferSize		[in]  Ҫд���ļ��������ֽ�����
		@���� dwFileSize		[in]  �����ļ��ĳ��ȡ�
		@���� lpBytesWritten	[out] ����ʵ��д����ֽ�����
		@���� dwFlags			[in]  ��־��
		@���� bFileType			[in]  �ļ����ͣ�

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.																
						
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
		��ǰĿ¼��ִ�п�ִ���ļ�
							
		@���� s4Ctx					[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpszFileID			[in]  ָ���ļ�ID��ָ��
		@���� lpInBuffer			[in]  ָ�����������ָ��
		@���� dwInbufferSize		[in]  ���뻺������С
		@���� lpOutBuffer			[out] ������ݻ�����
		@���� dwOutBufferSize		[in]  ������ݻ�������С
		@���� lpBytesReturned		[out] ʵ�ʷ��ؽ���ĳ���

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.																

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
		��ǰĿ¼��ִ�п�ִ���ļ���Ҳ����ִ��XA�������ļ�
							
		@���� s4Ctx					[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpszFileID			[in]  ָ���ļ�ID��ָ��
		@���� dwFlag				[in]  ִ���ļ��Ĳ���
		@���� lpInBuffer			[in]  ָ�����������ָ��
		@���� dwInbufferSize		[in]  ���뻺������С
		@���� lpOutBuffer			[out] ������ݻ�����
		@���� dwOutBufferSize		[in]  ������ݻ�������С
		@���� lpBytesReturned		[out] ʵ�ʷ��ؽ���ĳ���

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.																

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
		�ڵ�ǰĿ¼�½�����Ŀ¼��������Ŀ¼�ɹ�֮�󣬵�ǰĿ¼�л�Ϊ��Ŀ¼��
		����MF�ļ�ʱ��ǿ�ƽ���ATR�ļ�

		@���� s4Ctx				[in]  ָ�����Ѵ򿪵�Sense4�豸��ָ��
		@���� lpszDirID			[in]  Ҫ������Ŀ¼ID��4���ַ�
		@���� dwDirSize			[in]  Ҫ������Ŀ¼�Ŀռ��С
		@���� dwFlags			[in]  ����Ŀ¼ʱ�ı�־ѡ��
		@���� pRootInfo			[in]  ������MFʱ���ò��������Ŀ¼ATR��Ϣ

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.																

*/
DWORD WINAPI S4CreateDirEx(
	IN  SENSE4_CONTEXT  *s4Ctx,
	IN  LPCSTR  		lpszDirID,
	IN  DWORD  			dwDirSize,
	IN  DWORD  			dwFlags,
	IN  S4CREATEDIRINFO	*pCreateDirInfo
);
						   


/**
		����pS4OpenInfo��dwShareMode��Ա�Ĺ�����ռ���壬����
	
		@���� s4Ctx					[in][out]	�оٺ��Ҫ���ӵ�S4ָ��
		@���� pS4OpenInfo			[in]		��������Ĺ�����ռ��Ϣ

		@����ֵ ����ɹ�,����0 (S4_SUCCESS).<br>
		���ʧ��, ����ֵ��0.																

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

//����������hex�ļ��Ĳ���
#define S4_HEX_FILE					0x0000000a
//����������XA_hex�ļ��Ĳ���
#define S4_XA_HEX_FILE				0x0000000c


DWORD WINAPI PS4WriteFile(
	IN	CONST SENSE4_CONTEXT * ps4Ctx,
	IN	LPCSTR	lpszFileID,
	IN	LPCSTR	lpszPCFilePath,
	IN	OUT DWORD * lpdwFileSize,//ע������Ĳ�����һ��ָ��
	IN	DWORD dwFlags,
	IN	DWORD dwFileType,
	OUT LPDWORD lpdwBytesWritten
	);


//@}						  

#ifdef __cplusplus
}
#endif

#endif  //__SENSE4_H__
