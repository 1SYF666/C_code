#define _CRT_SECURE_NO_WARNINGS 1
#include"single_wcdma_demodulation.h"

int m_SamleSize = 8192;			//捕获时决定采用一次滑动8192个点进行自相关计算
int spread_factor_Q = 256;		//Q路扩频码长度，已经固定住
int Gold_len = 38400;           //扰码的长度

//傅里叶变换
void SingleWcdma::ippfft(float* data_real, float* data_imag, int FFT_LENGTH, int flag1, float* Ioutput, float* Qoutput, float* output)
{
	Ipp32fc* pDst = NULL;
	Ipp32fc* pSrc = NULL;
	int FFT_size = FFT_LENGTH;
	int FFTOrder = (log(FFT_size) / log(2)); //add by zhuxue
	IppsFFTSpec_C_32fc* pSpec = 0;
	Ipp8u* pMemSpec = 0;
	Ipp8u* pMemInit = 0;
	Ipp8u* pMemBuffer = 0;
	int sizeSpec = 0;
	int sizeInit = 0;
	int sizeBuffer = 0;
	int flag = IPP_FFT_NODIV_BY_ANY;
	int sizeFft = (int)FFT_size;
	//add by zhuxue
	pSrc = (Ipp32fc*)ippMalloc(sizeof(Ipp32fc) * sizeFft);
	pDst = (Ipp32fc*)ippMalloc(sizeof(Ipp32fc) * sizeFft);
	std::memset(pSrc, 0, sizeof(Ipp32fc) * sizeFft);
	std::memset(pDst, 0, sizeof(Ipp32fc) * sizeFft);
	for (int i = 0; i < sizeFft; i++)
	{
		pSrc[i].re = data_real[i];
		pSrc[i].im = data_imag[i];
	}
	/// get sizes for required buffers
	ippsFFTGetSize_C_32fc(FFTOrder, flag, ippAlgHintNone, &sizeSpec, &sizeInit, &sizeBuffer);
	//	printf("sizeSpec=%d,sizeInit=%d,sizeBuffer=%d\n", sizeSpec, sizeInit, sizeBuffer);
	/// allocate memory for required buffers
	pMemSpec = (Ipp8u*)ippMalloc(sizeSpec);
	if (sizeInit > 0)
	{
		pMemInit = (Ipp8u*)ippMalloc(sizeInit);
	}
	if (sizeBuffer > 0)
	{
		pMemBuffer = (Ipp8u*)ippMalloc(sizeBuffer);
	}
	/// initialize FFT specification structure
	ippsFFTInit_C_32fc(&pSpec, FFTOrder, flag, ippAlgHintNone, pMemSpec, pMemInit);
	/// free initialization buffer
	if (sizeInit > 0)
	{
		ippFree(pMemInit);
	}
	/// perform forward FFT
	ippsFFTFwd_CToC_32fc(pSrc, pDst, pSpec, pMemBuffer);
	for (int n = 0; n < sizeFft; n++)
	{
		output[n] = sqrt((float)pDst[n].re * (float)pDst[n].re + (float)pDst[n].im * (float)pDst[n].im);   //这个输出存放的是复信号的模值
		Ioutput[n] = (float)pDst[n].re;
		Qoutput[n] = (float)pDst[n].im;
		if (flag1 == -1)
		{
			Qoutput[n] = -Qoutput[n];
		}
	}
	/// ...
	/// free buffers
	if (sizeBuffer > 0)
	{
		ippFree(pMemBuffer);
	}
	ippFree(pMemSpec);
	ippFree(pDst);
	ippFree(pSrc);


}

//逆傅里叶变化
void SingleWcdma::ippifft(float* data_real, float* data_imag, int FFT_LENGTH, float* ifft_real, float* ifft_imag, float* Module)
{
	Ipp32fc* Src = (Ipp32fc*)ippMalloc(sizeof(Ipp32fc) * FFT_LENGTH);
	memset(Src, 0, sizeof(Ipp32fc) * FFT_LENGTH);
	Ipp32fc* Dst = (Ipp32fc*)ippMalloc(sizeof(Ipp32fc) * FFT_LENGTH);
	memset(Dst, 0, sizeof(Ipp32fc) * FFT_LENGTH);

	for (int i = 0; i < FFT_LENGTH; i++) {
		Src[i].re = data_real[i];
		Src[i].im = -1 * data_imag[i];
	}
	int FFTOrder = (log(FFT_LENGTH) / log(2));
	IppsFFTSpec_C_32fc* pSpec = 0;

	Ipp8u* pMemSpec = 0;
	Ipp8u* pMemInit = 0;
	Ipp8u* pMemBuffer = 0;

	int sizeSpec = 0;
	int sizeInit = 0;
	int sizeBuffer = 0;

	int flag = IPP_FFT_NODIV_BY_ANY;

	// get sizes for required buffers
	ippsFFTGetSize_C_32fc(FFTOrder, flag, ippAlgHintNone, &sizeSpec, &sizeInit, &sizeBuffer);

	// allocate memory for required buffers
	pMemSpec = (Ipp8u*)ippMalloc(sizeSpec);

	if (sizeInit > 0) {
		pMemInit = (Ipp8u*)ippMalloc(sizeInit);
	}

	if (sizeBuffer > 0) {
		pMemBuffer = (Ipp8u*)ippMalloc(sizeBuffer);
	}

	// initialize FFT specification structure
	ippsFFTInit_C_32fc(&pSpec, FFTOrder, flag, ippAlgHintNone, pMemSpec, pMemInit);

	// free initialization buffer
	if (sizeInit > 0) {
		ippFree(pMemInit);
	}

	// perform forward FFT
	ippsFFTFwd_CToC_32fc(Src, Dst, pSpec, pMemBuffer);


	// free buffers
	if (sizeBuffer > 0) {
		ippFree(pMemBuffer);
	}



	for (int n = 0; n < FFT_LENGTH; n++)
	{
		ifft_real[n] = (float)Dst[n].re / FFT_LENGTH;
		ifft_imag[n] = (float)-1 * Dst[n].im / FFT_LENGTH;
		Module[n] = sqrt(ifft_real[n] * ifft_real[n] + ifft_imag[n] * ifft_imag[n]);  //幅值计算
	}

	ippFree(pMemSpec);
	ippFree(Dst);
	ippFree(Src);

}

//找最大值即下标
void SingleWcdma::findmax(float* data, int len, float* out)
{
	float temp = 0;
	int max_flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (temp <= data[i]) {
			temp = data[i];
			max_flag = i;
		}
	}
	out[0] = max_flag;
	out[1] = temp;
}

//求均值
float SingleWcdma::meanArray(float* data, int len)
{
	float sum = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		sum += data[i];
	}
	return sum / len;

}

//改变输入信号模值
void SingleWcdma::AGC(float* BuffIn, float target_power)
{
	float* data_pow2 = new float[m_SamleSize];
	memset(data_pow2, 0, sizeof(float) * m_SamleSize);
	for (int i = 0; i < m_SamleSize; i++)
	{
		data_pow2[i] = BuffIn[i] * BuffIn[i];
	}
	float input_power = meanArray(data_pow2, m_SamleSize);
	float gain_factor = sqrt(target_power / input_power);
	for (int i = 0; i < m_SamleSize; i++)
	{
		BuffIn[i] = BuffIn[i] * gain_factor;
		//BuffIn[i] = BuffIn[i] /1000;
	}
	DELETE_ARR(data_pow2);

}

//捕获代码
void SingleWcdma::Capture(float* inputI, float* inputQ, int signal_len, WCdata WCdmadata)
{
	//auto startTime = std::chrono::system_clock::now();

	//对信号进行捕获，即获得信号的起始点的位置

	int Gold_length = 128 * 4 * 4 * 4;						// 一次捕获长度为128*64=8192点
	int capture_len = Gold_length * point;					//  

	//    float* Capture_max = new float[2];
	//    memset(Capture_max, 0, sizeof(float) * 2);


	// 对输入信号取 capture_len=8192*2=16384 长度数据段进行离散傅里叶变换，实部存放在 SignalFFTI数组中，虚部存放在 SignalFFTQ数组中，
	// Signaldata数组存放的是复信号的模值，长度为 16384 ,下标为0的元素为实部，下标为1的元素为虚部，以此类推...	
	ippfft(inputI, inputQ, capture_len, 1, SignalFFTI, SignalFFTQ, Signaldata);

	float signal = 0;
	float noise = 0;
	float s[16384];
	for (int i = 0; i < 16384; i++) {  //拷贝
		s[i] = Signaldata[i];
	}

	for (int i = 0; i < 50; i++) {
		signal += Signaldata[300 + i];  //signaldata数组下标300--349的元素累加到signal变量中
		noise += Signaldata[6000 + i];  //signaldata数组下标6000--6049的元素累加到noise变量中
	}
	float snr = signal / noise;         //有点像信噪比   

	if (snr > 5) {

		//下面 PNdata_buhuo_I、PNdata_buhuo_Q应该存放的是：扰码数据进行傅里叶变换后，然后再取共轭后的数据。
		//PNdata_buhuo_I、PNdata_buhuo_Q 是扰码长度为4096，然后采样2倍后的数据变成8192，再加上8192个点的操作
		//因为 此模块代码是利用信号数据段跟扰码数据段进行自（互）相关操作，所以对应频域上要取个共轭
		//此循环是进行一个复数与另一个复数的点乘操作----对应于时间卷积相当于频率乘积，
		//然后将频域点乘计算数据保存到数组中：DotMultI、DotMultQ
		for (int i = 0; i < capture_len; i++)
		{
			DotMultI[i] = SignalFFTI[i] * WCdmadata.PNdata_buhuo_I[i] - SignalFFTQ[i] * WCdmadata.PNdata_buhuo_Q[i];
			DotMultQ[i] = SignalFFTI[i] * WCdmadata.PNdata_buhuo_Q[i] + SignalFFTQ[i] * WCdmadata.PNdata_buhuo_I[i];
		}

		//进行逆傅里叶变换，转换到时域后，进行得到自相关值。复数数据的模保存到i_fft_abs数组
		ippifft(DotMultI, DotMultQ, capture_len, i_fft_I, i_fft_Q, i_fft_abs);

		//FILE* fp4;
		//char file_path4[500];
		//sprintf(file_path4, "E:/WCDMA1/signal.txt");   //11dB
		//fp4 = fopen(file_path4, "at");
		//for (int m = 0; m < 8192; m++)
		//{
		//	fprintf(fp4, "%f\n", i_fft_abs[m]);
		//}
		//fclose(fp4);

		//查找最大值
		float Capture_max[2] = { 0 };							//第一个元素存放最大值下标，第二个元素存放最大值
		findmax(i_fft_abs, capture_len, Capture_max);

		if (Capture_max[1] > 200 && Capture_max[0] < 8192) {    //???????
			startpoint = Capture_max[0];
			Signalflag = true;
		}
	}
	//auto endTime = std::chrono::system_clock::now();
	//auto time = std::chrono::duration_cast<microseconds>(endTime - startTime);
	//qDebug() << "spend time = " << time.count();


}


//同步代码
void SingleWcdma::symbolsync(float* inputI, float* inputQ, int signallen, float* PNnow_jieI, float* PNnow_jieQ, Users muser, float* synchresultI, float* synchresultQ)
{
	/*  旧版本含义：
		inputI 输入信号实部数据，inputQ 输入信号虚部数据
		signallen 输入信号的长度
		PNnow_jieI 以及 PNnow_jieQ 是外部传进来数据：扰码跟I路扩频码相乘后 再Point倍采样后 再取共轭 后的实部和虚部
		muser 里面包含I路数据（即每一个用户）的信息速率、扩频码长、以及扩频码
		synchresultI、synchresultQ 是此模块代码最终输出的结果，解I路和Q路的解扩数据
	*/

	/*  新版本含义：
		inputI 输入信号实部数据，inputQ 输入信号虚部数据
		signallen 输入信号的长度
		PNnow_jieI 以及 PNnow_jieQ 是外部传进来数据：扰码 Point倍采样后 再取共轭 后的实部和虚部
		PNnow_jieI、PNnow_jieQ 长度数据是 76800个点---------------------------------------------------
		muser 里面包含I路数据（即每一个用户）的信息速率、扩频码长、以及扩频码
		synchresultI、synchresultQ 存放的是此模块代码最终输出的结果，即I路和Q路的解扩数据
	*/

	int i, j, k;
	int  Symbol, SymbolNum;
	//**************************************** 伪码同步 *******************************************
	
	// 伪码同步：最初的想法是一次for循环然后对应着一次输出，那么自然希望输出的是：一个符号、两个符号或三个符号....
	// 所以取最大的扩频码长（256），对应256个码片，再一个码片采样两个点，即512，
	// 这样对应Q路来说，伪码同步中一次for循环输出一个符号信息；对于I路数据来说，一次for循环输出若干个符号（取决于I路扩频码长）信息
	Symbol = point * spread_factor_Q;                               
	
	SymbolNum = floor(signallen / Symbol);                          // 传入的信号段数据内含有多少个这样的Symbol长度（floor函数向下取整）							

	int Simulation_Length = Symbol * SymbolNum;                     // 这样使得数据长度就是Symbol的整数倍了
	
	float* PNsynchI = new float[Simulation_Length];                 //存放 伪码同步中一次for循环输出的结果，即输出解扰后的信号
	memset(PNsynchI, 0, Simulation_Length * sizeof(float));			//理由：输入信号 乘以 扰码的共轭 相当于消掉了扰码，进而的出解扰数据
	float* PNsynchQ = new float[Simulation_Length];
	memset(PNsynchQ, 0, Simulation_Length * sizeof(float));

	float* Vo_dep_I = new float[Simulation_Length];                 //存放 伪码同步中一次for循环输出的结果，即存放  输出解扰后信号 乘以 I路扩频码 的结果 
	memset(Vo_dep_I, 0, Simulation_Length * sizeof(float));			//目的是：后面对 Vo_dep_I进行积分，相当于对I路数据解扩了（利用wash扩频码+1和-1个数一样）
	float* Vo_dep_Q = new float[Simulation_Length];
	memset(Vo_dep_Q, 0, Simulation_Length * sizeof(float));

	// 以下声明目的是存放 扰码左移和右移 以及进行误差计算 再进入环路滤波器 一系列操作中所用到的相关数组
	int sys_gold_len = Gold_len * 2;                                // 伪码同步需要的扰码长度38400*2=76800
	float* PNcodeCQ_I = new float[sys_gold_len];                    //存放扰码I路和Q路数据					
	memset(PNcodeCQ_I, 0, sys_gold_len * sizeof(float));
	float* PNcodeCQ_Q = new float[sys_gold_len];
	memset(PNcodeCQ_Q, 0, sys_gold_len * sizeof(float));

	float* PNcodeZH_I = new float[sys_gold_len];                     //存放扰码左移右移后数据，以便下面进行误差计算，
	memset(PNcodeZH_I, 0, sys_gold_len * sizeof(float));
	float* PNcodeZH_Q = new float[sys_gold_len];
	memset(PNcodeZH_Q, 0, sys_gold_len * sizeof(float));

	float* ovsfiCQ_A = new float[sys_gold_len];						  //存放A用户扩频码左移和右移操作后的数据					
	memset(ovsfiCQ_A, 0, sys_gold_len * sizeof(float));				  //扩频码只有实部
	float* ovsfiZH_A = new float[sys_gold_len];
	memset(ovsfiZH_A, 0, sys_gold_len * sizeof(float));

	float* DLL_Phase_Part = new float[(SymbolNum + 1)];               //声明环路滤波器所用到的相关数组，伪码同步中for循环里要用到
	memset(DLL_Phase_Part, 0, (SymbolNum + 1) * sizeof(float));
	float* DLL_Freq_Part = new float[(SymbolNum + 1)];
	memset(DLL_Freq_Part, 0, (SymbolNum + 1) * sizeof(float));
	float* EPNsynch = new float[(SymbolNum + 1)];
	memset(EPNsynch, 0, (SymbolNum + 1) * sizeof(float));

	float cqreal = 0, cqimag = 0, zhreal = 0, zhimag = 0, cqsum = 0, zhsum = 0;
	
	//--------------------------------------------------------------------------
	float* temp = new float[2];             //这个变量暂时不知作用是什么？？           
	memset(temp, 0, sizeof(float) * 2);

	//点乘扰码相当于进行解扰操作
	for (int i = 0; i < SymbolNum; i++)      // 外循环遍历所有符号
	{
		
		for (int j = 0; j < Symbol; j++)     // 内循环遍历符号内含有的所有点（这里是512个点）
		{
			//PNsynchI 和 PNsynchQ里面存放的是解扰数据
			PNsynchI[i * Symbol + j] = inputI[i * Symbol + j] * PNnow_jieI[i * Symbol + j] - inputQ[i * Symbol + j] * PNnow_jieQ[i * Symbol + j];  // 存放计算后的数据的实部数据
			PNsynchQ[i * Symbol + j] = inputI[i * Symbol + j] * PNnow_jieQ[i * Symbol + j] + inputQ[i * Symbol + j] * PNnow_jieI[i * Symbol + j];  // 存放计算后的数据的虚部数据
		
			//计算Vo_dep
			Vo_dep_I[i * Symbol + j] = PNsynchI[i * Symbol + j] * muser.Descramble_end_I[i * Symbol + j];
			Vo_dep_Q[i * Symbol + j] = PNsynchQ[i * Symbol + j] * muser.Descramble_end_I[i * Symbol + j];

		}

		//以下就是“迟早门”操作，为什么打引号，因为跟理论公式有很大差距
		//左移和右移为了使得扩频码或者扰码 跟输入信号对齐，进而直接点乘进行解扰解扩操作

		for (int j = 0; j < sys_gold_len - 1; j++)  // 此循环以及后续四行赋值操作，目的是对扰码进行左移1个点
		{											// 由于Point是2(即一个码片是两个点)，这样再移两个点操作显然是错误的！！！！！
			PNcodeCQ_I[j] = PNnow_jieI[j + 1];		// 应该是移一个点(相当于移半个码片)
			PNcodeCQ_Q[j] = PNnow_jieQ[j + 1];
			
			ovsfiCQ_A[j] = muser.Descramble_end_I[j + 1];
		}
		PNcodeCQ_I[sys_gold_len - 1] = PNnow_jieI[0];
		PNcodeCQ_Q[sys_gold_len - 1] = PNnow_jieQ[0];
		
		ovsfiCQ_A[sys_gold_len - 1] = muser.Descramble_end_I[0];


		for (int j = 1; j < sys_gold_len; j++)      // 此循环以及后续四行赋值操作，目的是对扰码进行右移1个点
		{											// 由于Point是2(即一个码片是两个点)，这样再移两个点操作显然是错误的！！！！！									
			PNcodeZH_I[j] = PNnow_jieI[j - 1];		// 应该是移一个点(相当于移半个码片)
			PNcodeZH_Q[j] = PNnow_jieQ[j - 1];

			ovsfiZH_A[j] = muser.Descramble_end_I[j - 1]; 
		}
		PNcodeZH_I[0] = PNnow_jieI[sys_gold_len - 1];
		PNcodeZH_Q[0] = PNnow_jieQ[sys_gold_len - 1];

		ovsfiZH_A[0] = muser.Descramble_end_I[sys_gold_len - 1];


		cqreal = 0;  cqimag = 0;
		zhreal = 0;  zhimag = 0;
		cqsum = 0;   zhsum = 0;

		for (int j = 0; j < Symbol; j++)            //计算误差--即将信号数据与跟左移右移后的扰码数据进行点乘，然后累加结果
		{											//累加长度是512，即将一个符号内的点数进行累加
			cqreal = cqreal + inputI[i * Symbol + j] * PNcodeCQ_I[i * Symbol + j] - inputQ[i * Symbol + j] * PNcodeCQ_Q[i * Symbol + j];
			cqimag = cqimag + inputI[i * Symbol + j] * PNcodeCQ_Q[i * Symbol + j] + inputQ[i * Symbol + j] * PNcodeCQ_I[i * Symbol + j];
			
			zhreal = zhreal + inputI[i * Symbol + j] * PNcodeZH_I[i * Symbol + j] - inputQ[i * Symbol + j] * PNcodeZH_Q[i * Symbol + j];
			zhimag = zhimag + inputI[i * Symbol + j] * PNcodeZH_Q[i * Symbol + j] + inputQ[i * Symbol + j] * PNcodeZH_I[i * Symbol + j];
		}

		cqsum = cqreal * cqreal + cqimag * cqimag;  // 误差进行平方
		zhsum = zhreal * zhreal + zhimag * zhimag;

		j = i + 1;                                  // 这样写不报错吗？？？？？？？j没有声明好像
		DLL_Phase_Part[j] = symbolsyncsactorInit.fSymbolSyncFactor2 * (cqsum - zhsum) / (cqsum + zhsum);
		DLL_Freq_Part[j] = 0.5 * (DLL_Freq_Part[i] + DLL_Phase_Part[j]);
		EPNsynch[j] = symbolsyncsactorInit.fSymbolSyncFactor1 * (cqsum - zhsum) / (cqsum + zhsum) + DLL_Freq_Part[j];

		//阈值判断
		if (EPNsynch[j] > symbolsyncsactorInit.ThresholdPositive)
		{
			for (k = 0; k < sys_gold_len; k++)      // 此条件下将右移后的扰码和扩频码 进行拷贝操作,用于上面for循环中的解扰解扩操作
			{
				PNnow_jieI[k] = PNcodeCQ_I[k];
				PNnow_jieQ[k] = PNcodeCQ_Q[k];

				muser.Descramble_end_I[k] = ovsfiCQ_A[k];
			}

		}
		else if (EPNsynch[j] < symbolsyncsactorInit.ThresholdNegative)
		{
			for (k = 0; k < sys_gold_len; k++)		// 此条件下将左移后的扰码和扩频码 进行拷贝操作,用于上面for循环中的解扰解扩操作
			{
				PNnow_jieI[k] = PNcodeZH_I[k];
				PNnow_jieQ[k] = PNcodeZH_Q[k];

				muser.Descramble_end_I[k] = ovsfiZH_A[k];
			}
		}
	}

	//for (int i = 0; i < 153600; i++)
	//{
	//	printf("%d==%f\n", i, PNsynchQ[i]);
	//}
	DELETE_ARR(PNcodeCQ_I);
	DELETE_ARR(PNcodeCQ_Q);
	DELETE_ARR(ovsfiCQ_A);
	DELETE_ARR(PNcodeZH_I);
	DELETE_ARR(PNcodeZH_Q);
	DELETE_ARR(ovsfiZH_A);
	DELETE_ARR(DLL_Phase_Part);
	DELETE_ARR(DLL_Freq_Part);
	DELETE_ARR(EPNsynch);
	DELETE_ARR(temp);


	//下面这个段代码是对一个符号进行积分，作为下面的条件判断？目的好像是解决翻转的问题
	float sumI1 = 0;
	float sumQ1 = 0;
	for (int i = 0; i < 512; i++)
	{
		sumI1 += PNsynchI[i];
		sumQ1 += PNsynchQ[i];
	}


	/************************  锁相环去频偏  ***************************/
	// 对解扰信号进行积分操作，选择A用户的扩频码长的原因：
	// 首先：I路扩频码为长度(256、128、64、32等)，每一个码内 + 1和 - 1个数都是一样的，
	// 以至于对一个符号或者多个符号进行累加的话相当于 这一个符号或多个符号都变成0了
	// 其次：Q路扩频码长为256，且全为1，这个长度累加起来相当于还原这个符号了

	// 第一次积分操作--相当于利用Q路进入锁相环进而输出载波，然后I路乘以这个载波达到去频偏的效果
	int sum_length = muser.spread_factor_I * point;
	int sum_number = floor(Simulation_Length / sum_length);

	float* Vo_sumreal = new float[sum_number];                  //存放对解扰信号积分后的实部数据
	memset(Vo_sumreal, 0, sum_number * sizeof(float));			//由于I路扩频码是Wash码，因此积分相当于为零了

	float* Vo_sumimag = new float[sum_number];                  //存放对解扰信号积分后的虚部数据,由于Q路扩频码为全1,
	memset(Vo_sumimag, 0, sum_number * sizeof(float));			//因此积分了sum_length长度
																//相当于还原了 Q路中sum_length/spread_factor_Q * point个符号
	
	float* Vo_dep_A_sumreal = new float[sum_number];                    // 存放对 解扰信号乘以I路扩频码后的结果 积分后的实部数据
	memset(Vo_dep_A_sumreal, 0, sum_number * sizeof(float));			// 由于I路扩频码是Wash码，解扰信号又乘以了I路扩频码（周期其实就是sum_length），
																		// 因此积分sum_length长度相当于把I路数据还原出来了		
	
	float* Vo_dep_A_sumimag = new float[sum_number];                    // 存放对 解扰信号乘以I路扩频码后的结果 积分后的实部数据
	memset(Vo_dep_A_sumimag, 0, sum_number * sizeof(float));			// 由于Q路扩频码是全一的，解扰信号又乘以了I路扩频码（周期其实就是sum_length）
																		// 那么此时Q路中相当于 扩频码一个周期内（+1和-1次数一样了）
																		// 因此积分sum_length长度相当于把Q路数据变成零了
	//积分操作
	for (int k = 0; k < sum_number; k++)
	{
		int sumreal_temp = 0;
		int sumimag_temp = 0;
		int dep_sumreal_temp = 0;
		int dep_sumimag_temp = 0;
		//sum_length长度进行累加---就是指积分操作
		for (int z = 0; z < sum_length; z++)
		{
			sumreal_temp += PNsynchI[k * sum_length + z];
			sumimag_temp += PNsynchQ[k * sum_length + z];

			dep_sumreal_temp += Vo_dep_I[k * sum_length + z];
			dep_sumimag_temp += Vo_dep_Q[k * sum_length + z];

		}

		Vo_sumreal[k] = sumreal_temp/ sum_length;
		Vo_sumimag[k] = sumimag_temp/ sum_length;

		Vo_dep_A_sumreal[k] = dep_sumreal_temp / sum_length;
		Vo_dep_A_sumimag[k] = dep_sumimag_temp / sum_length;

	}
	
	//******************************释放内存***************************  这里写得是否有问题，需不需要释放
	DELETE_ARR(PNsynchI);
	DELETE_ARR(PNsynchQ);
	DELETE_ARR(Vo_dep_I);
	DELETE_ARR(Vo_dep_Q);
	//******************************释放内存***************************  这里写得是否有问题，需不需要释放


	int SRClen = sys_gold_len * point / muser.spread_factor_I;          // sys_gold_len*2=76800*2=153600？这个数据长度是存放采样(Point=2)后的扰码实部和虚部吗？
	int src = muser.spread_factor_I / point;                            // I路扩频码长度除以2为什么？ 


	float* NCO_Phase = new float[sum_number];				// “科斯塔斯环”里要用到的一些参数数组声明		
	memset(NCO_Phase, 0, sum_number * sizeof(float));		
	float* Discriminator_Out = new float[sum_number];
	memset(Discriminator_Out, 0, sum_number * sizeof(float));
	float* Freq_Control = new float[sum_number];
	memset(Freq_Control, 0, sum_number * sizeof(float));
	float* PLL_Phase_Part = new float[sum_number];
	memset(PLL_Phase_Part, 0, sum_number * sizeof(float));
	float* PLL_Freq_Part = new float[sum_number];
	memset(PLL_Freq_Part, 0, sum_number * sizeof(float));

	float* FsynchI = new float[sum_number];					// 锁相环输出存放数组，其实FsynchI相当于Q路输出结果
	memset(FsynchI, 0, sum_number * sizeof(float));
	float* FsynchQ = new float[sum_number];					// FsynchQ可能输出跟FsynchI相同或者相反，原因我暂时不清楚
	memset(FsynchQ, 0, sum_number * sizeof(float));


	float* Vo_dep_A_real = new float[sum_number];			// 利用锁相环对解扰信号积分后的跟踪载波输出
	memset(Vo_dep_A_real, 0, sum_number * sizeof(float));	// 然后用Vo_dep_A跟载波进行相乘，将Vo_dep_A频偏消掉
	float* Vo_dep_A_imag = new float[sum_number];			// Vo_dep_A_real相当于I路（A用户）输出结果,		
	memset(Vo_dep_A_imag, 0, sum_number * sizeof(float));	// Vo_dep_A_imag输出可能跟Vo_dep_A_real相同或者相反，原因我暂时不清楚


	if (abs(sumI1) < abs(sumQ1))
	{

		for (int i = 1; i < sum_number; i++)
		{
			FsynchI[i] = Vo_sumreal[i] * cos(NCO_Phase[(i - 1)]) + Vo_sumimag[i] * sin(NCO_Phase[(i - 1)]);       //科斯塔斯环输出,相当于Q路数据输出
			FsynchQ[i] = Vo_sumimag[i] * cos(NCO_Phase[(i - 1)]) - Vo_sumreal[i] * sin(NCO_Phase[(i - 1)]);

			Discriminator_Out[i] = (FsynchI[i] > 0 ? FsynchQ[i] : -FsynchQ[i]) - (FsynchQ[i] > 0 ? FsynchI[i] : -FsynchI[i]);//如果FsynchI=0，,FsynchQ=0,则取0，会有问题

			PLL_Phase_Part[i] = Discriminator_Out[i] * CostasPll.fPLLLoopFilterCoef1;
			PLL_Freq_Part[i] = Discriminator_Out[i] * CostasPll.fPLLLoopFilterCoef2 + PLL_Freq_Part[i - 1];
			Freq_Control[i] = PLL_Phase_Part[i] + PLL_Freq_Part[i];
			NCO_Phase[i] = NCO_Phase[i - 1] + Freq_Control[i] * 2 * Pi;

			Vo_dep_A_real[i] = Vo_dep_A_sumreal[i] * cos(NCO_Phase[(i - 1)]) + Vo_dep_A_sumimag[i] * sin(NCO_Phase[(i - 1)]); //相当于I路数据输出
			Vo_dep_A_imag[i] = Vo_dep_A_sumimag[i] * cos(NCO_Phase[(i - 1)]) - Vo_dep_A_sumreal[i] * sin(NCO_Phase[(i - 1)]);

			synchresultI[i] = Vo_dep_A_real[i];  //将I路数据输出保存在synchresultI数组中
			//synchresultQ[i] = FsynchQ[i];								 

			/*PNsynchI[i] = PNsynchI[i] * muser.Descramble_end_I[i];*/
			//printf("%d==%f\t", i, synchresultI[i]);
			//printf("%d==%f\n", i, synchresultQ[i]);
		}

		// 第二次积分操作--目的是：解Q路数据。由于上述第一次积分操作后 Vo_sumimag中每一个元素
		// 相当于还原出Q路数据中sum_length/spread_factor_Q * point个符号，故再需要积分长度为：
		// spread_factor_Q * point/sum_length，对FsynchI积分 将Q路真正还原出来

		int sum_length2 = spread_factor_Q / muser.spread_factor_I;

		int sum_number2 = floor(sum_number / sum_length2);

		for (int k = 0; k < sum_number2; k++)
		{
			int sum_temp = 0;

			for (int z = 0; z < sum_length2; z++)
			{
				sum_temp += FsynchI[k * sum_length2 + z];
			}

			synchresultQ[k] = sum_temp / sum_length2;
		}

	}
	else
	{
		for (int i = 1; i < sum_number; i++)
		{
			//**************************改得可能存在问题*********************************//
			FsynchI[i] = Vo_sumimag[i] * cos(NCO_Phase[(i - 1)]) + Vo_sumreal[i] * sin(NCO_Phase[(i - 1)]);
			FsynchQ[i] = Vo_sumreal[i] * cos(NCO_Phase[(i - 1)]) - Vo_sumimag[i] * sin(NCO_Phase[(i - 1)]);
			Discriminator_Out[i] = (FsynchI[i] > 0 ? FsynchQ[i] : -FsynchQ[i]) - (FsynchQ[i] > 0 ? FsynchI[i] : -FsynchI[i]);//如果FsynchI=0，,FsynchQ=0,则取0，会有问题
			PLL_Phase_Part[i] = Discriminator_Out[i] * CostasPll.fPLLLoopFilterCoef1;
			PLL_Freq_Part[i] = Discriminator_Out[i] * CostasPll.fPLLLoopFilterCoef2 + PLL_Freq_Part[i - 1];
			Freq_Control[i] = PLL_Phase_Part[i] + PLL_Freq_Part[i];
			NCO_Phase[i] = NCO_Phase[i - 1] + Freq_Control[i] * 2 * Pi;

			//**************************改得可能存在问题*********************************//
			Vo_dep_A_real[i] = Vo_dep_A_sumimag[i] * cos(NCO_Phase[(i - 1)]) + Vo_dep_A_sumreal[i] * sin(NCO_Phase[(i - 1)]); //相当于I路数据输出
			Vo_dep_A_imag[i] = Vo_dep_A_sumreal[i] * cos(NCO_Phase[(i - 1)]) - Vo_dep_A_sumimag[i] * sin(NCO_Phase[(i - 1)]);

			synchresultI[i] = Vo_dep_A_real[i];  //将I路数据输出保存在synchresultI数组中

			// 第二次积分操作--目的是：解Q路数据。由于上述第一次积分操作后 Vo_sumimag中每一个元素
			// 相当于还原出Q路数据中sum_length/spread_factor_Q * point个符号，故再需要积分长度为：
			// spread_factor_Q * point/sum_length，对FsynchI积分 将Q路真正还原出来

			int sum_length2 = spread_factor_Q / muser.spread_factor_I;
			int sum_number2 = floor(sum_number / sum_length2);

			for (int k = 0; k < sum_number2; k++)
			{
				int sum_temp = 0;

				for (int z = 0; z < sum_length2; z++)
				{
					sum_temp += FsynchI[k * sum_length2 + z];
				}

				synchresultQ[k] = sum_temp / sum_length2;
			}
		}

	}

	//synchresultI[0] = 0;
	//synchresultQ[0] = 0;

	DELETE_ARR(NCO_Phase);
	DELETE_ARR(Discriminator_Out);
	DELETE_ARR(Freq_Control);
	DELETE_ARR(PLL_Phase_Part);
	DELETE_ARR(PLL_Freq_Part);
	DELETE_ARR(FsynchI);
	DELETE_ARR(FsynchQ);
	DELETE_ARR(Vo_dep_A_real);
	DELETE_ARR(Vo_dep_A_imag);

}



