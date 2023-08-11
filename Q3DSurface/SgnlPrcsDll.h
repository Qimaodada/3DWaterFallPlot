//////////////////////////////////////////////////////////////////////////
//	SgnlPrcsDll.h
// 
//////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef _SGNLPRCSDLL_H_
#define _SGNLPRCSDLL_H_

#include ".\CmnHdr.h"
#include ".\fftw3.h"
#include ".\OfflineError.h"
#pragma comment(lib,"./fftw3.lib")

#pragma pack(1)

/////////////////////// �źŴ���ģ����ز��� ////////////////////////////

// �����ļ�·���� //
extern  TCHAR g_pzdllSetupFile[];
// ��ʱ�ļ�·�� //
extern  TCHAR g_pzdllTmpFilePath[];

// ϵͳ�����źŵ�����ʽ���� //
extern  SHORT  g_ndllModuTypeNum;
extern  SHORT*  CONST g_pdllSysModuType; 
extern  TCHAR** CONST g_pdllSysModuName;

// ϵͳ������Ƶ�źŵ�����ʽ���� //
extern  SHORT  g_ndllFHModuNum;
extern  SHORT*  CONST g_pdllFHModuType; 

// �ɼ�������ͨ������ //
extern  WORD g_dllDataChanNum;
// �ɼ����ź�ͨ������ //
extern  WORD g_dllSignalChanNum;

// �˲���������� //
extern  SHORT  g_dllLPFType ;
// ���/ͨ������ //
extern  double g_dllStopwidthFactor;
// ͨ������ lg//
extern  double g_dllPassRipple;
// ���˥�� dB//
extern  double g_dllStopRipple;
// ������� //
extern  double g_dllDemodFactor;
// DDC����ȡ���� //
extern  double g_dllExtractMax; 


/////////////////////////////�źŴ���ģ�鳣��/////////////////////////////
// �ļ�·������󳤶� //
CONST SHORT OSA_MAX_PATH = 8*MAX_PATH;

CONST double PI = 3.1415926535897932384626433832795;

CONST double RATIO_MIN = 3.5;	// dSamplingFreq/dPassWidth
CONST double RATIO_MAX = 8.0;

// �������ź�ͨ����Ŀ���ֵ //
CONST WORD CHANNEL_NUM_MAX = 10;

CONST double PASS_RIPPLE_MIN = 0.00001;
CONST double PASS_RIPPLE_MAX = 2; 

CONST double STOP_RIPPLE_MIN = 20;
CONST double STOP_RIPPLE_MAX = 100; 

// �ź���С������ //
CONST WORD DETECTION_BANDWIDTH_MIN = 5;

// ⧷��źſ���ʱ�ν���������ĸ��� //
CONST WORD UCV_DEM_ZEROS_NUM = 16;
// �źż�������� //
CONST WORD UCV_SIGNAL_NUM_MAX = 16;

const WORD UVFH_SPCTRA_NUM_MIN = 8;
const WORD UVFH_SPCTRA_NUM_MAX = 100;
const WORD UVFH_BANDWIDTH_MIN = 5;
const WORD UVFH_SIGNAL_NUM_MAX = 64;
const WORD UVFH_NET_NUM_MAX = 8;
const WORD UVFH_FREQ_SET_MAX = 1024;

const double UVFH_NET_SORT_PAR = 0.25;
const SHORT  UVFH_NET_SORT_NUM = 4;


// �źŵ�������������Ŀ���ֵ
CONST WORD SMT_NUM_MAX = 32;

// �źŵ������� //
enum SignalModulationType
{
	SMT_UNKNOWN = 0,
	SMT_NOISE,
	SMT_CW,
	SMT_AM,
	SMT_FM,
	SMT_DSB,
	SMT_SSB,	
	SMT_MSK,
	SMT_GMSK,	
	SMT_2FSK,
	SMT_4FSK,
	SMT_2ASK,
	SMT_4ASK,
	SMT_2CPM,
	SMT_4CPM,
	SMT_BPSK,
	SMT_QPSK,
	SMT_8PSK,
	SMT_OQPSK,
	SMT_SDPSK,
	SMT_PI4DQPSK,
	SMT_8QAM,
	SMT_16QAM,
	SMT_32QAM,
	SMT_64QAM,	
	SMT_16PSK,	
	SMT_16APSK, //4+12
	SMT_USB_LINK11,
	SMT_LSB_LINK11,
	SMT_ISB_LINK11,
	SMT_UHF_LINK11,
	SMT_UHF_LINK4A
};


//FFT�Ӵ����� //
enum WindowFunction
{
	Boxcar,
	Hanning,
	Hamming,
	Blackman,
	Blackman_Harris,
};

//�˲�����Ʒ������� //
enum FIRLPFDesignType
{
	FIRLPFDT_Hanning,
	FIRLPFDT_Hamming,
	FIRLPFDT_Blackman,
	FIRLPFDT_Kaiser,
	FIRLPFDT_Equiripple,
};

// ���������� //
enum EqualizerType
{
	EQUATYPE_NO,
	EQUATYPE_MCMA,
	EQUATYPE_MDFE
};

//////////////////////////////////////////////////////////////////////////

// ���ź� //
typedef struct{	
	double I;
	double Q;
}COMPLEX_SIGNAL;

// �����ļ���Ϣ //
typedef struct {
	SHORT	nFileType;			//�ļ�����
	SHORT	nDataType;			//��������
	DWORD	dwOpenOffset;		//�ļ���ȡƫ���ֽ���
	bool	bIsInverse;			//���ױ�־ 
	bool	bIsComplex;			//����ͨ����־
	double	dTuneFreq;			//��гƵ�� Hz	
	double	dIntermediateFreq;	//��ƵƵ�� Hz	
	double	dSamplingFreq;		//����Ƶ�� Hz
} DATA_FILE_PARAM;

// �����ŵ����� //
typedef struct {
	SHORT	nDataChannelID;		//����ͨ��Ψһ��ʶ��	
	double	dTuneFreq;			//��гƵ�� Hz	
	double	dIntermediateFreq;	//��ƵƵ�� Hz	
	double	dBandwidth;			//�ŵ����� Hz	
	double	dSamplingFreq;		//����Ƶ�� Hz
	bool	bIsInverse;			//���ױ�־ 
	bool	bIsComplex;			//����ͨ����־
}DATA_CHANNEL_PARAM;

// �ź�ͨ������ //
typedef struct {
	SHORT  nSignalChannelID;	//�ź�ͨ��Ψһ��ʶ��
	double dCenterFreq;			//�ź�Ƶ�� Hz
	double dBandwidth;			//ͨ������ Hz
	double dStopWidth;			//������� Hz
	double dOutSamplingFreq;	//�������Ƶ�� Hz
} SIGNAL_CHANNEL_PARAM;

// �����ײ��� //
typedef struct {	
	DWORD	dwFFTSize;	//FFT����
	DWORD	dwFFTMove;	//FFTƽ������	
	SHORT	nWindType;	//FFT����������	
	SHORT	nAverNum;	//FFTƽ������
} SPECTRUM_PROBE_PARAM;

// �źŽ������ //
typedef struct {	
	SHORT  nSCID;		//�ź�ͨ����
	SHORT  nModuType;	//�źŵ�������
	double dTimeFrom;	//��ʼʱ�� s
	double dDuration;	//����ʱ�� s
	double dSignalFreq;	//�ź�Ƶ�� Hz
	double dSymbolRate;	//�������� kBd
	double dFreqShift;	//Ƶƫ Hz
	double dOutSampling;//�������
	double dEstimSNR;	//����� dB	
} SIGNAL_DEMOD_PARAM;

// �źż�������� //
typedef struct{
	SHORT  nSCID;		// �ź�ͨ����
	double dTimeFrom;	// ��ʼʱ�� ms
	double dDuration;	// פ��ʱ�� ms	
	double dCenterFreq; // ����Ƶ��Hz
	double dPassWidth;  // �źŴ���Hz
	double dEstimSNR;	// ����� dB
} SIGNAL_DETECT_PARAM;

// �źŲ���ͳ�� //
typedef struct {
	DWORD  dwCntSum;	//����ͳ������
	DWORD  dwCntNum;	//��ǰ�źŲ������ִ���
	SHORT  nSCID;		//�ź�ͨ����
	SHORT  nModuType;	//�źŵ�������
	double dTimeFrom;	//��ʼʱ�� s
	double dDuration;	//����ʱ�� s
	double dSignalFreq;	//�ź�Ƶ�� Hz
	double dSymbolRate;	//�������� kBd
	double dFreqShift;	//Ƶƫ Hz
	double dEstimSNR;	//����� dB
} SIGNAL_STAT_PARAM;


// ��Ƶ��ѡ��� //
typedef struct{
	SHORT  nNetID;		// ��̨��
	SHORT  nFreqNum;	// Ƶ�ʸ���
	double* pFreqSet;	// Ƶ�ʼ� Hz
	double dCycleTime;	// ��Ƶ���� ms
	double dDuration;	// פ��ʱ�� ms	
	double dPassWidth;	// �źŴ��� Hz
	double dAverLevel;  // �ź�ƽ����ƽ dB
	double dMinFreqStep; // ��С������ Hz
	double dMaxFreqStep; // ��������Hz
	double dSortParam;   // ��ѡ����
}USFH_NETSORT_RESULT;

// ��ʱ�źż�������� //
typedef struct{
	double dCenterFreq;	// ����Ƶ��Hz
	double dPassWidth;	// �źŴ���Hz
	double dAverLevel;	// �źŵ�ƽ dB
	double dTimeFrom;	// ��ʼʱ�� ms
	double dTimeStop;	// ����ʱ�� ms
	double dDuration;	// פ��ʱ�� ms	
	double dCycleTime;	// ��Ƶ���� ms
	double dSortParam;  // ��ѡ����
} USTH_SIGNAL_DETECT_PARAM;

// ��ƵƵ�����ݲ��� //
typedef struct{
	SHORT nChanNum;				// ͨ����
	double dIntermediateFreq;	// ��ƵƵ�� Hz
	double dBandwidth;			// �ŵ����� Hz
	double dStartFreq;			// ��ʼƵ�� Hz
	double dFreqScale;			// Ƶ�ʷֱ��� Hz
	double dTimeScale;			// ʱ��ֱ��� s
	double dLevlScale;			// ������ƽ
	LONG  lSpcLinNum;			// ��������
}SAVE_WTFL_PARAM;

//////////////////////// �ź�ģ�麯�� ////////////////////////////////////

// ������Ϣ��ʾ //
extern  void MsgBoxLastErrorShow(DWORD dwErrorID);

// ����Сֵ //
extern  LONG GetMinVal(LONG* X,int N);
extern  double GetMinVal(double* X,int N);

// �����ֵ //
extern  LONG GetMaxVal(LONG* X,int N);
extern  double GetMaxVal(double* X,int N);
extern  LONG GetMaxIndex(double* X, LONG N, double& dMaxValue);

// �źŹ�һ�� //
extern  bool SignalNormalize(double* pData,DWORD dwDataLen);
extern  bool SignalNormalize(LONG* pData,double* pSigIQ,DWORD dwDataLen);

// �����ź�ƽ�� //
extern  void CalSignalSquare(double *pData, LONG lDataLen);
extern  void CalSignalSquare(double *pDataI, double *pDataQ, LONG lDataLen);

// ��ȡ�ź�˲ʱ���� //
extern  void CalSingalEnvelope(double *pData, LONG lDataLen, double* pResult);
// ��ȡ�ź�˲ʱƵ�� //
extern  void CalSingalFrequency(double* pData,LONG nDataLen,double* pResult);
// ��ȡ�ź�˲ʱ��λ //
extern  void CalSingalPhase(double* pData,LONG nDataLen,double* pResult);

// ��ȡ�ź�Ƶ�� //
extern  double GetSignalFreq(double dSignalFreq,DATA_CHANNEL_PARAM* pChanPara,bool bInv = true);
// ��ȡ�ź�����Ƶ�� //
extern  double GetDigitalFreq(double dSignalFreq,DATA_CHANNEL_PARAM* pChanPara,bool bInv = true);
// ���ε��Ƶ�AM���//
extern double* Twice_AM(double* data, DWORD size);
//ʵ�źű�Ϊ���źŵ��±�Ƶ
extern  double* ddc(double *sign, double fs, double fc, DWORD size);
//ACARS�ź�AMԤ�Ƚ��
extern double* ACARS_AM(double *sign, DWORD size);
//ϣ�����ر任


#endif //#ifndef _SGNLPRCSDLL_H_

//////////////////////////// End of File /////////////////////////////////
