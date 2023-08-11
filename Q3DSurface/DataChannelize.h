#pragma once

#include<afxwin.h>
#include "SgnlPrcsDll.h"
#include "DataFIRDF.h"


class __declspec(dllexport)CDataChannelize
{
public:
	CDataChannelize(void);
	~CDataChannelize(void);

	//�ŵ���������ʼ��
	DWORD InitChannelizeParam(
		double dSamplingFreq,
		double dSingalFreq,
		double dPassWidth,
		double dStopWidth,
		double &dOutSamplingFreq,
		short* pFactor = NULL,
		short  nFIRnum = 0);

	DWORD InputData(LONG* lpData, DWORD dwlen, bool bIsComplex);

	double* GetSignal(DWORD& dwDataLen);

protected:

	bool GetResamplingFactor(double dSamplingFreq, double dPassWidth, double &dOutSamplingFreq);

private:

	double m_dSamplingFreq;

	SIGNAL_CHANNEL_PARAM m_SignChanPara;	
	
	//���������
	double* m_pOutBuf;
	//�������������
	DWORD  m_dwOutLen;	
	
	//�ŵ������I·����
	double *m_pSignI;
	//�ŵ������Q·����
	double *m_pSignQ;
	//�ŵ������IQ����
	DWORD	m_dwSignLen;

	//�ŵ���������źų���
	DWORD m_dwIQOut;

	//DDC��λ
	double m_dCurrentPhase;	

	

	// �ڲ�  interpolation //
	bool m_bInterpolated;
	//�˲��ڲ屶��
	short		*m_pInterFactor;
	//�˲����鳤��
	short		m_nInterFIRnum;
	//�ź��˲�����
	CDataFIRDF **m_pInterFilter;	

	// ��ȡ decimation //
	bool m_bDecimated;
	// �˲���ȡ����
	short		*m_pDecimFactor;
	// ��ȡ���
	DWORD		*m_pDecimIndex;	
	// �ź��˲�����
	CDataFIRDF **m_pDecimFilter;	
	// �˲����鳤��
	short		m_nDecimFIRnum;

};
