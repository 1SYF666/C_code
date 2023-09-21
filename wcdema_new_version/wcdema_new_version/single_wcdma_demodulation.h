#pragma once

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include <vector>  //包含vector文件

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
    int Rb;                    // 信息速率
    int spread_factor_I;       // I路扩频码长度
    float* Descramble_end_I;   // 每一个用户的扩频码

};


struct WCdata {

    vector<Users> users;

    float* Descramble_I;
    float* Descramble_Q;

    float* PNdata_buhuo_I;   //申请数组，存放的是point倍采样的扰码，后又补了8192个零的
    float* PNdata_buhuo_Q;   
};


typedef struct
{
    float fSymbolSyncFactor1;               //符号同步系数1
    float fSymbolSyncFactor2;               //符号同步系数2
    int   ThresholdPositive;                //不同码速需要对应调整
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

    //函数声明
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




    //捕获模块需要用到的数组及变量申明
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
    int point = 2; //一个码片采样两个点

    SymbolSyncFactorWCDMA symbolsyncsactorInit;  // 伪码同步中，环路滤波器要用到的相关参数
    CostasPLLWCDMA CostasPll;                    // 科斯塔斯环中要用到的相关参数

  

    // WIni函数以及解调函数要用到的参数
    float* m_dataI;
    float* m_dataQ;
    float* m_dataIbu;
    float* m_dataQbu;
    int target_power = 1;
    bool Signalflag = false;


private:
    int llSlic;   //作用是什么？？？？？？？？

};

SingleWcdma::SingleWcdma()
{
}

SingleWcdma::~SingleWcdma()
{
}