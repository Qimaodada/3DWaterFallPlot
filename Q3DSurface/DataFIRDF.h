#pragma once

#include "SgnlPrcsDll.h"
#pragma pack(1)
class CDataFIRDF
{
public:
	CDataFIRDF(void);
	~CDataFIRDF(void);

	// ��ͨ�˲�����ʼ��
	BOOL IinitialLPFPara(
		short nLPFDesiType,
		double dPassWidth,
		double dStopWidth,		// <0.5
		double dPassRipple,    // 0.01
		double dStopAttenuation); // dB

	// �����˲�
	void Filter(double *pDataI,double *pDataQ,int nDataLen);

	// �����˲�
	void Filter(double *pData,int nDataLen);

protected:
	//�˲�������	
	SHORT  m_nLPFLen;
	//���ݻ�����
	double	*m_pDataI;	
	double	*m_pDataQ;
	//�˲���ϵ��
	double	*m_pLPFBuf;

	//��ȡ�˲�������
	SHORT LPFLength(
		short nWinType,
		double dPassWidth,
		double dStopWidth,
		double dPassRipple,
		double dStopAttenuation);

	//���ڴ��������˲������
	void WindowFuncFD(short nWinType,
		double dBandidth,
		double dStopAttenuation);

	//�Ȳ����˲������
	void EquirippleFD(
		double dPassWidth,
		double dStopWidth,
		double dPassRipple,
		double dStopAttenuation);
};
