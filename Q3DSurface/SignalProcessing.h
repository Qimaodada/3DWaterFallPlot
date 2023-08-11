#pragma once
#include<iostream>
#include"SpectrumProbe.h"

using namespace std;

class SignalProcessing
{
public:
	SignalProcessing();
	~SignalProcessing();
	//初始化
	void InitSingalProcessing(DWORD dwFFTsize, DWORD SamplingRate);
	//获得瞬时包络
	double* CalSingalEnvelope(double* pData, long nDataLen);
	//获得瞬时频率
	double* CalSingalFrequency(double* pData, long nDataLen);
	//获得瞬时相位
	double* CalSingalPhase(double* pData, long nDataLen);
	//获取平方谱IQ
	void CalSignalSquare(double *pData,long nDataLen);
	//信号下变频
	void Signalddc(double *pData, long nDataLen, long nDDCFreq);
	//差分谱
	double* SignalProcessing::GetDiffSpecParam(double* pSignAmpl, DWORD dwDataLen, DWORD &dwSpecLen, bool bIsFreq);
	//采样率
	DWORD m_SamplingRate;
	//
	void GetOrderSpectrum(double* dIndata, DWORD Len, double* &spectrum, double* &spectrum2, double* &spectrum4, double* &spectrum8);
	void Noralization(double* &spectrum, DWORD Len);

private:
	//FFT点数
	DWORD m_dwFFTSize;
	CSpectrumProbe *m_pFFTAD;
	CSpectrumProbe *m_pFFTIQ;
	CSpectrumProbe *m_pFFTIQ2;
	CSpectrumProbe *m_pFFTIQ4;
	CSpectrumProbe *m_pFFTIQ8;
	double* m_pTmpBufI;
};