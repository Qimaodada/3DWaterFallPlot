#pragma once
#include<iostream>
#include"SpectrumProbe.h"

using namespace std;

class SignalProcessing
{
public:
	SignalProcessing();
	~SignalProcessing();
	//��ʼ��
	void InitSingalProcessing(DWORD dwFFTsize, DWORD SamplingRate);
	//���˲ʱ����
	double* CalSingalEnvelope(double* pData, long nDataLen);
	//���˲ʱƵ��
	double* CalSingalFrequency(double* pData, long nDataLen);
	//���˲ʱ��λ
	double* CalSingalPhase(double* pData, long nDataLen);
	//��ȡƽ����IQ
	void CalSignalSquare(double *pData,long nDataLen);
	//�ź��±�Ƶ
	void Signalddc(double *pData, long nDataLen, long nDDCFreq);
	//�����
	double* SignalProcessing::GetDiffSpecParam(double* pSignAmpl, DWORD dwDataLen, DWORD &dwSpecLen, bool bIsFreq);
	//������
	DWORD m_SamplingRate;
	//
	void GetOrderSpectrum(double* dIndata, DWORD Len, double* &spectrum, double* &spectrum2, double* &spectrum4, double* &spectrum8);
	void Noralization(double* &spectrum, DWORD Len);

private:
	//FFT����
	DWORD m_dwFFTSize;
	CSpectrumProbe *m_pFFTAD;
	CSpectrumProbe *m_pFFTIQ;
	CSpectrumProbe *m_pFFTIQ2;
	CSpectrumProbe *m_pFFTIQ4;
	CSpectrumProbe *m_pFFTIQ8;
	double* m_pTmpBufI;
};