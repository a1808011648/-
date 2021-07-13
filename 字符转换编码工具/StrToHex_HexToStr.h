#pragma once

#include<windows.h>
#include<iostream>
#include<string>

using namespace std;

/************************************************************************/
/*������:UnicodeToAsni
  ������;:��Unicode�ַ���ת��ΪAsni(GBK-ASCCI)�ַ���
  ����:
  wchar_t *Wchar Ҫת����Դ�ַ���
  ����ֵ:����һ��char*ָ�룬��Ҫ����delete                              */
/************************************************************************/
char* UnicodeToAsni(wchar_t* WChar);


/************************************************************************
/* ������:HexToStr->�˺���������ת�����ַ���
   ������;:���ַ�����ת��Ϊ�ַ���
   ����:
   TCHAR *T_Buff Ҫת����Դ����
   BOOL   flags  Դ�����Ƿ��Դ��ģʽ�洢
   ����ֵ:����һ��char*ָ�룬��Ҫ����delete                             */       
/************************************************************************/
char* HexToStr(TCHAR *T_Buff,BOOL flags);

/************************************************************************/
/* ������:StrToHex						
   ������;:��һ���ַ���ת��Unicode�����Asni(GBK-ASCCI)����
   ����:
   char* Buff Դ�ַ���,��������wchar_t���ͣ�����ʱǿת����
   int length Դ�ַ�������,wchar_t���͵Ļ������2
   BOOL Addspaces �Ƿ�Ϊת����ı������ӿո�
   BOOL flags �����Ƿ��Դ��ģʽ���
   ����ֵ:����һ��string���ͣ�����Ҫ����delete
   */
/************************************************************************/
string StrToHex(char*Buff,int length,BOOL AddSpaces,BOOL flags);
