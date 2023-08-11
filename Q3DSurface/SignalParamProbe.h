////////////////////////////////////////////////////////////////////////// 
//
// 
// 
////////////////////////////////////////////////////////////////////////// 

#pragma once

#ifndef _SIGNAL_PARAM_PROBE_H_
#define _SIGNAL_PARAM_PROBE_H_

#include "SgnlPrcsDll.h"
#include "SpectrumProbe.h"
#pragma pack(1)
//////////////////////////////////////////////////////////////////////////
class __declspec(dllexport)CSignalParamProbe
{
public:
	CSignalParamProbe(void);

	~CSignalParamProbe(void);

	// ��ʼ������̽����
	DWORD InitParamProbe(double dSamplingFreq, double dPasswidth,DWORD dwFFTSize, SHORT nModuType = SMT_UNKNOWN);

	// �ź���ʽʶ��Ͳ�������
	DWORD InputData(double *pData, DWORD dwDataLen);

	// ��ȡ�źŲ���
	DWORD GetSignalParam(SIGNAL_DEMOD_PARAM& pSignalPara);

protected:
	// Modulation Recognition
	SHORT ModuRecognition(double *pData, DWORD dwDataLen);

	// Parameter Estimate
	DWORD ParamEstimate(double *pData, DWORD dwDataLen);

	// Spectrum Analysis Parameters
	DWORD GetSpecAnalParam(double *pData, DWORD dwDataLen);

	double GetAmplAveSqu(double* pSignAmpl, DWORD dwDataLen);

	double GetFreqAveSqu(double* pSignFreq, DWORD dwDataLen);

	// ����ƽ�������� //
	DWORD CalAverPowerSpecrum(double* pPoweSpec,double* pData, DWORD dwDataLen);
	// ����ƽ�������� //
	void CalAmplAverPowerSpecrum(double* pPoweSpec,double *pData, DWORD dwDataLen);
	// ���������źŴ��������Ƶ�� //
	void RoughEstiFcBnw(double& dCenterFreq, LONG& nBandwidth, double *pSignalPsd);

	void GetReferParam(double *pReferParam, double *pSignalPsd,LONG nBandwidth);

	void GetSpectrumParam(double *pSpecParam,double *pSignalPsd,LONG nBandwidth,double *pReferParam,short N);

	void GetSpecIdenParam(double* pIdenPara,double *pSpecParam2,double *pSpecParam4,double *pSpecParam8);

	void GetDiffSpecParam(double* pIdenPara,double* pSignAmpl,DWORD dwDataLen,LONG  nBandwidth,bool bIsFreq = FALSE);	

	void Amplitudenormalization(double* pFreqBuff,int N);

	void Frequencynormalization(double* pAmplBuff,int N,int M);	

	void NormalizationAmplFreq(double* pAmplBuff,double* pFreqBuff,int N,int M);

	// ��ȡ˲ʱ����/Ƶ�ʵ�ͳ����������
	double GetFrequencyStatParam(double* pInput,int Inlen);
	//�����Ĺ�һ��˲ʱ����/Ƶ�ʵĽ�����(�Ľ׾�) // 
	double GetFourthOrderParam(double *x,int len);
	// �����׶Գ��Բ��� //
	double GetSpectraSymmetParam(double *pSignalPsd,DWORD dwPSDLen);
	// ��ȡ�����ײ��� //
	void GetSpectraParam(double *pParam,double *pSignalPsd,DWORD dwPSDLen);
	// ��ȡ6dB��ƽ����//
	LONG GetLvlBandwidth(double *pSignalPsd,DWORD dwPSDLen, double dLvlThreshold);
	// ��ȡ�����׷�ֵ��Ŀ//
	void GetSpectraPeaksNum(double *pParam,double *pSignalPsd,DWORD dwPSDLen);
	// ���㹦���׵�����Ƶ�� //
	double CalSpectraCenterFreq(double* pInput,int N);
	// ����ASK�ķ������� //
	double CalASKSymbolRate(double* pDataIQ,DWORD dwDataLen);
	// ����FSK�ķ������� //
	double CalFSKSymbolRate(double* pDataIQ,DWORD dwDataLen);
	// ���ù����׼���FSk������Ƶ�� //
	void CalFSKCFDF_Spectra(double* pParam,double* pDataIQ,DWORD dwDataLen);	
	// ����˲ʱƵ�ʼ���FSk������Ƶ�� //
	void CalFSKCFDF_InstFrequ(double* pParam,double* pDataIQ,DWORD dwDataLen);
	// ����ASK������Ƶ�� //
	double CalASKFrequncy(double* pDataIQ,DWORD dwDataLen);
	// QAM�ź�ʶ�� //
	SHORT QAMRecognition(double* pDataIQ,DWORD dwDataLen,double dSymbolLen);

private:

	CSpectrumProbe* m_pFFTIQ;
	CSpectrumProbe* m_pFFTAD;

	//�������Ƶ�� Hz
	double	m_dSamplingFreq;	
	// ����ͨ������ Hz
	double m_dPasswidth;
	// �źŵ�������
	SHORT	m_nModuType;
	
	//�����ź�Ƶ�� Hz
	double	m_dSignalFreq;	
	//�źŵ������� Hz
	double	m_dSymbolRate;
	//�źŵ������� Hz
	double	m_dFreqShift;

	// �����׷�����FFT����
	DWORD	m_dwFFTSize;
	DWORD	m_dwFFTMove; 
	SHORT	m_nFFTAver;
	SHORT	m_nFFTWind;
	// ʶ��������ź����ݳ���
	DWORD	m_dwSignLen;

	DWORD  m_dwTmpBufLen;
	// �����źų���
	DWORD	m_dwIQLen;
	
	// ���������� Singal Stat. characteristic Parameters
	struct SpectrumAnanlysisParam{

		LONG   nBandwidth;	 // Estimate bandwidth
		double dCenterFreq;	 // Estimate center frequency

		double dAmplAveSqu;  // amplitude average square/amplitude square average
		double dDASPeakLvl;	 // Difference Amplitude Spectrum max.peak relative level
		LONG   nDASPeakIdx;  // Difference Amplitude Spectrum max.Peak Index	

		double dFreqAveSqu;  // amplitude average square/amplitude square average
		double dDFSPeakLvl;	 // Difference Amplitude Spectrum max.peak relative level
		LONG   nDFSPeakIdx;  // Difference Amplitude Spectrum max.Peak Index

		double  dAMForOrder;
		double  dFMForOrder;
		double  dFMStatWight;
		double  dAMStatWight;

		LONG   nSpecType;	 // Type of Spectrum
		LONG   nSpecPeakNum; // Spectrum peaks' number 
		LONG   nPeakIndex1;	 // 1st peak index
		LONG   nPeakIndex2;  // 2nd peak index
		double dSpecPeakLvl; // max.peak absolute level/max.peak relative level	

		LONG   nSquaPeakIdx1; // Square Spectrum max.Peak Index	
		LONG   nSquaPeakIdx2;

		LONG    nPsdPeakNum;  // Spectrum peaks' number	
		LONG    nPsdPeakIdx1; // 1st peak index
		LONG    nPsdPeakIdx2; // 2st peak index
		double  dPsdLvlBnd;	  // �����׵�ƽ����
		double  dPsdPeakDeT;  // 1st peak lvl - 2nd peak lvl
		double  dPsdCentFre;  // �����׶Գ�����Ƶ��
		double  dPsdSymmet;	  // �����׶Գ���
	}m_sap;

	double *m_pDataBuff;
	double *m_pSignalBuff;	
	double *m_pAmplBuff;	
	double *m_pFreqBuff;
	double *m_pTmpBufI;
	double *m_pTmpBufQ;

	double *m_pSignPsd;
	double *m_pAmplPSD;
	double *m_pBuffer1;
	double *m_pBuffer2;
	double *m_pBuffer3;
	LONG   *m_pPsdInex;
};


#endif // _SIGNAL_PARAM_PROBE_H_