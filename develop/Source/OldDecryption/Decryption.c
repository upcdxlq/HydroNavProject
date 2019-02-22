/**********************************************
/*
/*		Copyright Huace Nav 2017
/*		The library is for the backword compatibility with the old register library.
/*		Origin code refers to HydroNav Software.
/*
**********************************************/


#include<time.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#include"sense4.h"

#include"Decryption.h"

//导入软件狗的接口库
#pragma comment(lib, "Sense4ST.lib")

#define FAN_PI "31415926535897932384626433832795288419716939937510"
#define USER_PIN "25917430"

#define FAN_TEMP1 35364541
#define FAN_TEMP0 33513192


static unsigned char OldDevPin[24] =
{
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
};

static unsigned char OldUserPin[8] =
{
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
};

static unsigned char NewDevPin[24] =
{
	'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
	'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
	'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
};

static unsigned char NewUserPin[8] =
{
	'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
};

static char book[10][10] = { { 'J','2','Z','Y','7','4','K','V','3','6' },
{ '0','F','1','D','I','9','3','H','2','8' },
{ 'B','9','A','7','8','Z','2','3','U','1' },//20121122 0->8
{ 'Q','Y','9','N','1','6','4','K','5','L' },
{ '2','0','C','4','W','7','L','A','1','9' },
{ 'R','7','2','8','6','E','9','J','4','M' },
{ '8','X','D','5','V','2','I','6','9','0' },
{ 'S','3','7','1','0','8','6','I','L','N' },
{ '9','T','E','3','U','5','X','1','8','7' },
{ 'M','5','6','F','2','G','1','D','0','P' }
};

static char DogId[9];//狗号
static char DogReg[25];//注册码

static void 
SetNewUserPin(char str[8])
{
	memcpy(NewUserPin, str, sizeof(char) * 8);
}

static int 
get_day_of_timeval(time_t timeval)
{
	return timeval / 3600 / 24;
}

static SENSE4_CONTEXT * 
AccessKey()
{
	SENSE4_CONTEXT * s4CtxList = NULL;
	SENSE4_CONTEXT * pReturnS4 = NULL;
	S4OPENINFO		S4_OpenInfo;
	DWORD			dwSize = 0;
	int i = 7;

	//枚举系统连接了多少个设备,这一步不用判断返回值，第一个参数输入NULL
	S4Enum(NULL, &dwSize);

	//如果得到的设备上下文内存数量为0或者不为sizeof(SENSE4_CONTEXT)的倍数，
	//说明没有找到设备或者列举设备出错。
	if ((0 == dwSize) || (dwSize % sizeof(SENSE4_CONTEXT))) return NULL;

	//根据返回的设备个数，分配空间给程序使用
	s4CtxList = (SENSE4_CONTEXT *)malloc(dwSize);

	//根据分配的空间，再次枚举设备，这次要判断函数返回值
	if (S4Enum(s4CtxList, &dwSize) != S4_SUCCESS)
	{
		free(s4CtxList);
		return NULL;
	}

	S4_OpenInfo.dwS4OpenInfoSize = sizeof(S4OPENINFO);
	S4_OpenInfo.dwShareMode = S4_EXCLUSIZE_MODE;
	//连接指定的设备
	if (S4OpenEx(&s4CtxList[0], &S4_OpenInfo) == S4_SUCCESS)
	{
		do
		{
			i--;
		} while (i >= 0);
	}
	else
	{
		free(s4CtxList);
		return NULL;
	}
	pReturnS4 = (SENSE4_CONTEXT *)malloc(sizeof(SENSE4_CONTEXT));
	memcpy(pReturnS4, s4CtxList, sizeof(SENSE4_CONTEXT));
	free(s4CtxList);
	return pReturnS4;
	//	return (&s4CtxList[0]);
}

static bool 
ExistDog()
{
	SENSE4_CONTEXT * pCtx = NULL;
	DWORD			dwRet;
	pCtx = AccessKey();

	if (pCtx == NULL)
	{
		return false;
	}

	dwRet = S4VerifyPin(pCtx, NewUserPin, 8, S4_USER_PIN);
	if (dwRet != S4_SUCCESS)
	{
		dwRet = S4Close(pCtx);
		//释放资源
		free(pCtx);
		pCtx = NULL;
		return false;
	}
	dwRet = S4Close(pCtx);

	//释放资源
	free(pCtx);
	pCtx = NULL;
	return true;
}


static bool 
ReadDogInfo(char dogNO[8], char regCode[24])
{
	SENSE4_CONTEXT * pCtx = NULL;
	DWORD			dwRet;
	DWORD			dwBytesWritten = 0;
	BYTE inBuff = 1;
	BYTE outBuff[64];

	//访问设备
	pCtx = AccessKey();
	if (pCtx == NULL)
	{
		return false;
	}
	dwRet = S4VerifyPin(pCtx, NewUserPin, 8, S4_USER_PIN);
	if (dwRet != S4_SUCCESS)
	{
		dwRet = S4Close(pCtx);
		//释放资源
		free(pCtx);
		pCtx = NULL;
		return false;
	}

	//读狗号
	dwRet = S4Execute(pCtx, "0003", &inBuff, 1, outBuff, 64, &dwBytesWritten);
	if (dwRet != S4_SUCCESS || dwBytesWritten != 8)
	{
		dwRet = S4Close(pCtx);
		//释放资源
		free(pCtx);
		pCtx = NULL;
		return false;
	}

	memcpy(dogNO, outBuff, 8);

	//读注册码
	inBuff = 2;
	dwRet = S4Execute(pCtx, "0003", &inBuff, 1, outBuff, 64, &dwBytesWritten);
	if (dwRet != S4_SUCCESS || dwBytesWritten != 24)
	{
		dwRet = S4Close(pCtx);
		//释放资源
		free(pCtx);
		pCtx = NULL;
		return false;
	}

	memcpy(regCode, outBuff, 24);

	dwRet = S4Close(pCtx);
	//释放资源
	free(pCtx);
	pCtx = NULL;
	return true;
}

static bool
HaveLock()
{
	bool ret = true;

	SetNewUserPin(USER_PIN);
	if (!ExistDog())
	{
		ret = false;
	}

	return ret;
}


static bool
ReadDog(char *dogId, char *dogReg)
{
	SetNewUserPin(USER_PIN);
	if (!ExistDog())
	{
		return false;
	}

	if (!ReadDogInfo(dogId, dogReg))
	{
		return false;
	}

	return true;
}


static time_t 
make_date(const char* strDate)
{
	int year, month, day;
	struct tm tm =	{ 0};
	char temp[9];
	if (strDate == NULL || strlen(strDate) != 8
		|| atoi(strDate) < 20070101 || atoi(strDate) > 20801231)
	{
		year = 2007; month = 01; day = 01;
	}
	else
	{
		strcpy(temp, strDate);
		temp[4] = '\0';
		year = atoi(temp);
		if (year > 2080 || year < 2007)
			year = 2007;

		strcpy(temp, strDate+4);
		temp[2] = '\0';
		month = atoi(temp);
		if (month > 12 || month < 1)
			month = 1;

		strcpy(temp, strDate + strlen(strDate) - 2);
		temp[2] = '\0';
		day = atoi(temp);
		if (day > 31 || day < 1)
			day = 1;
	}

		tm.tm_year = year - 1900;
		tm.tm_mon = month - 1;
		tm.tm_mday = day;
	return mktime(&tm);
}


static void 
swap_word(int length, char *wordP)
{
	char tmp;
	char ttt;
	int i;
	for (i = 0; i<length / 2; i++)
	{
		tmp = *(wordP + i);
		ttt = *(wordP + length - 1 - i);
		*(wordP + i) = ttt;
		*(wordP + length - 1 - i) = tmp;
	}
}

static int 
ch2int(char ch)
{
	int i = (ch > 0x39 || ch < 0x30) ? 0 :ch - 0x30;
	return i;
}

static char 
int2ch(int i)
{
	return (char)(0x30 + i);
}

// 0 .encrypt, 1 decrypt
static void 
word_book(int length, char *wordP, int flag)
{
	int a, b;
	char k, t;
	int i, j;
		char tmp = '\0';
	//char Key[] = FAN_PI;
	char *Key = FAN_PI;//20121122-1
	if (flag == 0)
	{
		for (i = 0; i<length; i++)
		{
			k = *(wordP + i);
			t = Key[i];
			a = ch2int(k);
			b = ch2int(t);
			*(wordP + i) = book[a][b];
		}
	}
	else
	{
		for (i = 0; i<length; i++)
		{

			k = *(wordP + i);
			t = Key[i];
			b = ch2int(t);
			for (j = 0; j<10; j++)
			{
				if (book[j][b] == k)
				{
					tmp = int2ch(j);
					break;
				}
			}
			*(wordP + i) = tmp;
		}
	}
}

// id + sn -> tm
static void
dogDecrypt(char* sid, char* sReg, char time[9])
{
	long id;
	char reg[24];
	char cn0[9], cn1[9], cn2[9];
	long sn, sn0, sn2;
	long FanTemp0;
	
	id = atoi(sid);
	memcpy(reg, sReg, 24);
	word_book(24, reg, 1);
	swap_word(24, reg);

	memcpy(cn0, reg, 8);
	cn0[8] = '\0';
	memcpy(cn1, reg + 8, 8);
	cn1[8] = '\0';
	memcpy(cn2, reg + 16, 8);
	cn2[8] = '\0';

	sn0 = atoi(cn0);
	//long sn1 = atoi(cn1);
	sn2 = atoi(cn2);

	sn = sn0 ^ FAN_TEMP1;
	if(sn - id < 100000000)
	{
		sprintf(time, "%08ld", sn - id);
	}

								   //20110511 =================================================================
								   //LONG FanTemp2 = sn ^ sn1; //预留
	FanTemp0 = sn ^ sn2;
	if ((FanTemp0 != FAN_TEMP0)) //若使用的是老注册机
	{
		strcpy(time, "20110730");
	}
}


long
CheckDog()
{
	time_t now, all, lock;
	char dogId[9]={'\0'}, dogReg[25]={'\0'},datetime[9]={'\0'};
	struct tm tm ={0};
		tm.tm_year = FINAL_YEAR - 1900;
		tm.tm_mon = FINAL_MONTH - 1;
		tm.tm_mday = FINAL_DAY;
		tm.tm_hour = FINAL_HOUR;
		tm.tm_min = FINAL_MINUTE;
		tm.tm_sec = FINAL_SECOND;
		tm.tm_isdst = 0;
	now = time(NULL);
	all = mktime(&tm);

	if (!HaveLock() || !ReadDog(dogId, dogReg))
	{
		return -1;
	}

	dogDecrypt(dogId, dogReg, datetime);
	memcpy(DogId,dogId,sizeof(DogId));
	memcpy(DogReg,dogReg,sizeof(DogReg));
	lock = make_date(datetime);

	if ((lock >= now) &&		// 使用期限大于或等于计算机当前的时间
		(lock <= all))			// 使用期限小于或等于永久版的时间
	{
		return lock;
	}
	else
	{
		return -2;
	}
}

char *
ReadDogId()
{
	return DogId;
}

char *
ReadDogReg()
{
	return DogReg;
}

bool 
WriteReg(const char *reg)
{
	SENSE4_CONTEXT * pCtx = NULL;
	DWORD			dwRet;
	DWORD			dwBytesWritten = 0;
		byte outBuff[24];
		byte reg_copy[25] = {'\0'};
	//访问设备
	pCtx = AccessKey();
	if(pCtx == NULL)
	{
		return false;
	}
	dwRet = S4VerifyPin(pCtx, NewUserPin, 8, S4_USER_PIN);
	if(dwRet != S4_SUCCESS)
	{
        dwRet = S4Close(pCtx);
		//释放资源
		free(pCtx);
		pCtx = NULL;
		return false;
	}

	if(strlen(reg) != 24)
	{
        dwRet = S4Close(pCtx);
		//释放资源
		free(pCtx);
		pCtx = NULL;
		return false;
	}
	memcpy(reg_copy, reg,24);
	dwRet = S4Execute(pCtx, "0003", reg_copy, 24, outBuff, 24, &dwBytesWritten);
    if(dwRet != S4_SUCCESS)
	{
        dwRet = S4Close(pCtx);
		//释放资源
		free(pCtx);
		pCtx = NULL;
		return false;
	}
    dwRet = S4Close(pCtx);
	//释放资源
	free(pCtx);
	pCtx = NULL;
	return true;
}

