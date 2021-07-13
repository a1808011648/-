#pragma once

#include<windows.h>
#include<iostream>
#include<string>

using namespace std;

/************************************************************************/
/*函数名:UnicodeToAsni
  函数用途:将Unicode字符串转换为Asni(GBK-ASCCI)字符串
  参数:
  wchar_t *Wchar 要转换的源字符串
  返回值:返回一个char*指针，需要自行delete                              */
/************************************************************************/
char* UnicodeToAsni(wchar_t* WChar);


/************************************************************************
/* 函数名:HexToStr->此函数将编码转换成字符串
   函数用途:把字符编码转变为字符串
   参数:
   TCHAR *T_Buff 要转换的源编码
   BOOL   flags  源编码是否以大端模式存储
   返回值:返回一个char*指针，需要自行delete                             */       
/************************************************************************/
char* HexToStr(TCHAR *T_Buff,BOOL flags);

/************************************************************************/
/* 函数名:StrToHex						
   函数用途:把一个字符串转成Unicode编码或Asni(GBK-ASCCI)编码
   参数:
   char* Buff 源字符串,它可以是wchar_t类型，传参时强转即可
   int length 源字符串长度,wchar_t类型的话请乘以2
   BOOL Addspaces 是否为转换后的编码增加空格
   BOOL flags 编码是否以大端模式输出
   返回值:返回一个string类型，不需要自行delete
   */
/************************************************************************/
string StrToHex(char*Buff,int length,BOOL AddSpaces,BOOL flags);
