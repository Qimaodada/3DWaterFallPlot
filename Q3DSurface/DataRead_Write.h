#pragma once
typedef  unsigned long DWORD;
/*	dat�ļ���д	 */

// �������ݳ���.dat
DWORD GetFilelen(char* file,int s_len);
// ��short�����ļ�.dat
short* GetFileshort(char* file, DWORD size);
// ��char�����ļ�.dat
unsigned char* GetFilechar(char* file, DWORD size);

// дchar�����ļ�.dat
void outfilechar(char* file, char* pbuf, DWORD size);
// дlong�����ļ�.dat
void outfilelong(char* file, long* pbuf, DWORD size);
// дdouble�����ļ�
void outfiledouble(char* file, double* pbuf, DWORD size);
void outfileshort(char * file, short * pbuf, DWORD size);
