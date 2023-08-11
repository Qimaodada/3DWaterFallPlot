//////////////////////////////////////////////////////////////////////////
//
// 
// 
////////////////////////////////////////////////////////////////////////// 


#pragma once

#ifndef _SIGNAL_DEMOD_PROBE_H_
#define _SIGNAL_DEMOD_PROBE_H_

#include "SgnlPrcsDll.h"
#include "DataFIRDF.h"
#pragma pack(1)
class __declspec(dllexport)CSignalDemodProbe
{
public:
	CSignalDemodProbe(void);

	~CSignalDemodProbe(void);

	DWORD InitDemodParam(double dSamplingFreq,double dSymbolRate, double dFreqShift,SHORT nModuType,bool bIsDecode);

	DWORD InputData(double *pData,DWORD dwDataLen);

	double* GetSignalDemod(DWORD& dwSignLen); //ģ�������

	long* GetSignalDemod(DWORD& dwSignLen,bool flag);//���ֽ����� ����ͼ����

	CHAR* GetSignalSymbol(DWORD& dwBitNum);

protected:

	DWORD Demod_AM(double *pData,DWORD dwDataLen);

	DWORD Demod_FM(double *pData,DWORD dwDataLen);

	DWORD Demod_SSB(double *pData,DWORD dwDataLen);

	DWORD Demod_ASK(double *pData,DWORD dwDataLen);

	DWORD Demod_FSK(double *pData,DWORD dwDataLen);

	DWORD Demod_MSK(double *pData,DWORD dwDataLen);

	DWORD Demod_BPSK(double *pData,DWORD dwDataLen);

	DWORD Demod_QPSK(double *pData,DWORD dwDataLen);

	DWORD Demod_8PSK(double *pData,DWORD dwDataLen);

	DWORD Demod_16PSK(double *pData,DWORD dwDataLen);

	DWORD Demod_OQPSK(double *pData,DWORD dwDataLen);

	DWORD Demod_PI4DQPSK(double *pData,DWORD dwDataLen);

	DWORD Demod_SDPSK(double *pData,DWORD dwDataLen);	

	DWORD Demod_16QAM(double *pData,DWORD dwDataLen);

	DWORD Demod_32QAM(double *pData,DWORD dwDataLen);

	DWORD Demod_64QAM(double *pData,DWORD dwDataLen);	

protected:

	DWORD InitParam_AMS();

	DWORD InitParam_PSK();

	DWORD InitParam_FSK();
	//��ȡ�������
	void GetDemodPara(double *pCoef,BOOL bIsCL);
	//��ȡλͬ������
	void GetSymbolLoop(double *pCoef,SHORT M);
	//��ȡ�ز�ͬ������
	void GetCarrierLoop(double *pCoef);
	//��ȡAGC����
	void GetAGC();

protected:
	//�ز�ͬ����·����
	typedef struct{

		COMPLEX_SIGNAL dcDelay[2];

		double dDelay;

		double	dNCO_e;
		double	dNCO_p;

		double	dLpf_c1;
		double	dLpf_c2;
		double	dLpf_cc;

	}CARRIER_LOOP;

	//λͬ����·����
	typedef struct{

		SHORT	nIndex;

		COMPLEX_SIGNAL dcDelay;
		COMPLEX_SIGNAL dcMid;
	
		//�ڲ��ȡ�˲���
		SHORT	nIntrFIR_bLen;
		SHORT	nIntrFIR_sLen;
		double	*pIntrFIR_b;

		COMPLEX_SIGNAL *pIntrFIR_s;

		//ƥ���˲���
		SHORT	nMatchFIR_Len;
		double	*pMatcFIR_b;

		COMPLEX_SIGNAL *pMatcFIR_s;

		//DCO
		double	dDCO_f;
		double	dDCO_p;
		double	dDCO_e;

		//
		double	dLpf_c1;
		double	dLpf_c2;
		double	dLpf_cc;

	}SYMBOL_LOOP;

	//AGC����
	typedef struct{

		double	a;
		double	s;
		double	m;

		SHORT	n;

		SHORT	nFIRLen;
		double	*pFIR_d;
	}AGC;

protected:
	double m_dSamplingFreq;

	double m_dSymbolRate;

	double m_dFreqShift;

	SHORT m_nModuType;	

protected:
	LONG* m_pDemodBuf;

	DWORD	m_dwDemLen;
	// ������Ÿ���
	DWORD	m_dwSylNum;

protected:
	CARRIER_LOOP m_Clpf;

	SYMBOL_LOOP  m_Tlpf;

	AGC  m_Agc;

private:
	CDataFIRDF* m_pFilter;

	COMPLEX_SIGNAL m_dcPreData;

	double* m_pFSKDelay;
	SHORT	m_nFSKDelay;

	double* m_pSgnlBuf;
	DWORD   m_dwSgnlLen;

protected:

	// ��ֽ���
	bool m_bIsDecode;

	// ������
	CHAR* m_pBitBuf;	

	DWORD m_dwBufLen;
	// ����������
	DWORD m_dwBitNum;

	CHAR m_PreCode[4];

protected:
	DWORD InputSignal(LONG *pData,DWORD dwDataLen);	

	DWORD Decode_2Lvl(LONG *pData,DWORD dwDataLen);

	DWORD Decode_4Lvl(LONG *pData,DWORD dwDataLen);

	DWORD Decode_4Phase(LONG *pData,DWORD dwDataLen);

	DWORD Decode_8PSK(LONG *pData,DWORD dwDataLen);

	DWORD Decode_16PSK(LONG *pData,DWORD dwDataLen);

	DWORD Decode_16APSK(LONG *pData,DWORD dwDataLen);

	DWORD Decode_16QAM(LONG *pData,DWORD dwDataLen);

	DWORD Decode_32QAM(LONG *pData,DWORD dwDataLen);

	DWORD Decode_64QAM(LONG *pData,DWORD dwDataLen);
};


#endif //_SIGNAL_DEMOD_PROBE_H_