#include "StdAfx.h"
#include"StrToHex_HexToStr.h"





char* UnicodeToAsni(wchar_t* WChar){

	char* buff = NULL;
	int len = WideCharToMultiByte(CP_ACP,0,WChar,wcslen(WChar),NULL,0,NULL,NULL);
	buff = new char[len+1];
	memset(buff,0,len+1);
	WideCharToMultiByte(CP_ACP,0,WChar,wcslen(WChar),buff,len,NULL,NULL);
	return buff;
}

char* HexToStr(TCHAR *T_Buff,BOOL flages = FALSE){

	TCHAR* c = T_Buff;
	int i = 0;
	int t = 0;
	int m_end = 0;
	int m_begin = 0;
	int len = 0;
	if(sizeof(TCHAR)>1){
		len =wcslen(T_Buff)*2 + 2;
	}else{
		len = strlen((char*)T_Buff)+1;
	}
	
	char* temp = new char[len];
	
	memset(temp,0,len);

	while (*c != '\0' ) {

		if (*c != ' ') {

			temp[i] = *c;
			i++;
		}
		c = c + 1;

	}
	len = strlen(temp);
	char*  p = temp;
	char* buffer = new char[len+2];
	memset(buffer,0,len);
	int length = strlen(temp);

	for (int i = 0; i < length; i++) {
		temp[i] = tolower(temp[i]);
	}

	i = 0;
	while (*p != '\0') {
		t = 0;
		char* tmp = p;
		
		for (int y = 0; y < 2; y++){
			m_begin = 0;
			for (int x = 0; x < 2; x++) {
				//将0-F 16进制的编码转换成10进制                                                                                   
				if (*tmp >= '0' && *tmp <= '9') {
					t = *tmp - '0';
				}
				else if (*tmp >= 'a' && *tmp <= 'f') {
					t = *tmp - 'a' + 10;
				}
				else {
					t = *tmp - 'A' + 10;
				}
				if (*tmp == '\0') {
					t = 0;
				}
				m_begin = m_begin * 16 + t;//这是一种算法，列如61 16进制编码，第一次得到6，第二次用6*16+1得到正确的10进制97
				tmp++;

			}


			if(flages == TRUE){
				//如果flags等于1，以大端形式存储
				if (y == 0) {
					buffer[i + 1] = m_begin; //如果以大端形式存储，那么编码将存储顺序反过来
				}
				else {
					buffer[i] = m_begin;
					i+=2;
				}
			}else{
				//否则默认以windows小端形式
				buffer[i] = m_begin;
				i++;

			}

			p = p + 2;


		}

	}
	delete temp;
	return buffer;
}


string StrToHex(char*Buff,INT length,BOOL AddSpaces = FALSE,BOOL flags =FALSE){

	string ret;
	const char*hex = "0123456789ABCDEF";
	if (flags == TRUE) //以小端形式输出
	{
		for(int i = 0;i<length;i++){

			if(AddSpaces == FALSE){ //如果flags等于0代表增加选择框没被选中，以不加空格小端方式输出

				ret.push_back(hex[((Buff[i+1]>>4)&0xf)]);
				ret.push_back(hex[(Buff[i+1])&0xf]);
				ret.push_back(hex[((Buff[i]>>4)&0xf)]);
				ret.push_back(hex[(Buff[i])&0xf]);

			}else{//否则以加空格小端方式输出

				ret.push_back(hex[((Buff[i+1]>>4)&0xf)]);
				ret.push_back(hex[(Buff[i+1])&0xf]);
				ret.push_back(32);;
				ret.push_back(hex[((Buff[i]>>4)&0xf)]);
				ret.push_back(hex[(Buff[i])&0xf]);
				ret.push_back(32);

			}

			i++;

		}
	} 
	else
	{
		for(int i = 0;i<length;i++){

			if(AddSpaces == FALSE){

				ret.push_back(hex[((Buff[i]>>4)&0xf)]);
				ret.push_back(hex[(Buff[i])&0xf]);


			}else{


				ret.push_back(hex[((Buff[i]>>4)&0xf)]);
				ret.push_back(hex[(Buff[i])&0xf]);
				ret.push_back(32);

			}

		}
	}

	return ret;
}