#include<stdio.h>
#include"Decryption.h"
#pragma comment(lib,"OldDecryption.lib")

int
main()
{
	long flag = CheckDog();
	if(flag>0){
		printf("Succeed in identification!\r\n");
		printf("The dogid is %s\r\nThe register code is %s\r\n",ReadDogId(), ReadDogReg());
	}else 
		printf("Fail to identify!\r\n");

	printf("Please press Enter to exit\r\n");
	getchar();
}