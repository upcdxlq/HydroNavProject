#ifndef DECRYPTION_H
#define DECRYPTION_H

#define _CRT_SECURE_NO_WARNINGS//½ûÖ¹¾¯¸æ
#pragma comment (linker,"/NODEFAULTLIB:libc.lib")

typedef  char bool;
#define true 1
#define false 0

#define FINAL_YEAR 2080
#define FINAL_MONTH 12
#define FINAL_DAY 31
#define FINAL_HOUR 0
#define FINAL_MINUTE 0
#define FINAL_SECOND 0

_declspec(dllexport) long CheckDog();
_declspec(dllexport) char *ReadDogId();
_declspec(dllexport) char *ReadDogReg();
_declspec(dllexport) bool WriteReg(const char *reg);
#endif // !DECRYPTION_H

