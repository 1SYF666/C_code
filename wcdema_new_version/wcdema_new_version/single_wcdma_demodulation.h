#pragma once

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include <vector>  //����vector�ļ�

#include"omp.h"
#include"ipp.h"


using namespace std::chrono;
using namespace std;

#define DELETE_ARR(ptr)\
if (ptr != NULL)\
{\
    delete[] ptr;\
    ptr = NULL;\
}

#define FREE_MALLOC(ptr)\
if (ptr != NULL)\
{\
    free(ptr);\
    ptr = NULL;\
}

#ifndef Pi
#define Pi (acos(-1.0))
#endif // !Pi

struct Users {
    int Rb;                    // ��Ϣ����
    int spread_factor_I;       // I·��Ƶ�볤��
    float* Descramble_end_I;   // ÿһ���û�����Ƶ��

};


struct WCdata {

    vector<Users> users;

    float* Descramble_I;
    float* Descramble_Q;

    float* PNdata_buhuo_I;   //�������飬��ŵ���point�����������룬���ֲ���8192�����
    float* PNdata_buhuo_Q;   
};


typedef struct
{
    float fSymbolSyncFactor1;               //����ͬ��ϵ��1
    float fSymbolSyncFactor2;               //����ͬ��ϵ��2
    int   ThresholdPositive;                //��ͬ������Ҫ��Ӧ����
    int   ThresholdNegative;
}SymbolSyncFactorWCDMA;


typedef struct
{
    float fPLLLoopFilterCoef1;
    float fPLLLoopFilterCoef2;
}CostasPLLWCDMA;




class SingleWcdma
{
public:
	SingleWcdma();
	~SingleWcdma();

    //��������
    void ippfft(float* data_real, float* data_imag, int FFT_LENGTH, int flag1, float* Ioutput, float* Qoutput, float* output);
    void ippifft(float* data_real, float* data_imag, int FFT_LENGTH, float* ifft_real, float* ifft_imag, float* Module);

    void findmax(float* data, int len, float* out);
    float meanArray(float* data, int len);
    void  AGC(float* BuffIn, float target_power);
    void Capture(float* inputI, float* inputQ, int signal_len, WCdata WCdmadata);
    
    void symbolsync(float* inputI, float* inputQ, int signallen, float* PNnow_jieI, float* PNnow_jieQ, Users muser, float* synchresultI, float* synchresultQ);


    void InitSync();

    void WInit(WCdata WCdmadata);

    void judgment(float* inputi, float* inputq, Users muser, int signallen, int* demoresulti, int* demoresultq, signalout* signal_SOQP_Out, int useNum);
    int readgold();

    void Demodulation(float* data_realin, float* data_imagin, WCdata WCdmadata, long long llBaseTime, signalout* signal_SOQP_Out);




    //����ģ����Ҫ�õ������鼰��������
    float* SignalFFTI;
    float* SignalFFTQ;
    float* Signaldata;
    float* DotMultI;
    float* DotMultQ;
    float* i_fft_abs;
    float* i_fft_I;
    float* i_fft_Q;
    int startpoint = 0;
    bool Signalflag = false;
    int point = 2; //һ����Ƭ����������

    SymbolSyncFactorWCDMA symbolsyncsactorInit;  // α��ͬ���У���·�˲���Ҫ�õ�����ز���
    CostasPLLWCDMA CostasPll;                    // ��˹��˹����Ҫ�õ�����ز���

  

    // WIni�����Լ��������Ҫ�õ��Ĳ���
    float* m_dataI;
    float* m_dataQ;
    float* m_dataIbu;
    float* m_dataQbu;
    int target_power = 1;
    bool Signalflag = false;


private:
    int llSlic;   //������ʲô����������������

};

SingleWcdma::SingleWcdma()
{
}

SingleWcdma::~SingleWcdma()
{
}