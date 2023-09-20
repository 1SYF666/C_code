#define _CRT_SECURE_NO_WARNINGS 1
#include"single_wcdma_demodulation.h"

int m_SamleSize = 8192;			//����ʱ��������һ�λ���8192�����������ؼ���
int spread_factor_Q = 256;		//Q·��Ƶ�볤�ȣ��Ѿ��̶�ס
int Gold_len = 38400;           //����ĳ���

//����Ҷ�任
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
		output[n] = sqrt((float)pDst[n].re * (float)pDst[n].re + (float)pDst[n].im * (float)pDst[n].im);   //��������ŵ��Ǹ��źŵ�ģֵ
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

//�渵��Ҷ�仯
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
		Module[n] = sqrt(ifft_real[n] * ifft_real[n] + ifft_imag[n] * ifft_imag[n]);  //��ֵ����
	}

	ippFree(pMemSpec);
	ippFree(Dst);
	ippFree(Src);

}

//�����ֵ���±�
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

//���ֵ
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

//�ı������ź�ģֵ
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

//�������
void SingleWcdma::Capture(float* inputI, float* inputQ, int signal_len, WCdata WCdmadata)
{
	//auto startTime = std::chrono::system_clock::now();

	//���źŽ��в��񣬼�����źŵ���ʼ���λ��

	int Gold_length = 128 * 4 * 4 * 4;						// һ�β��񳤶�Ϊ128*64=8192��
	int capture_len = Gold_length * point;					//  

	//    float* Capture_max = new float[2];
	//    memset(Capture_max, 0, sizeof(float) * 2);


	// �������ź�ȡ capture_len=8192*2=16384 �������ݶν�����ɢ����Ҷ�任��ʵ������� SignalFFTI�����У��鲿����� SignalFFTQ�����У�
	// Signaldata�����ŵ��Ǹ��źŵ�ģֵ������Ϊ 16384 ,�±�Ϊ0��Ԫ��Ϊʵ�����±�Ϊ1��Ԫ��Ϊ�鲿���Դ�����...	
	ippfft(inputI, inputQ, capture_len, 1, SignalFFTI, SignalFFTQ, Signaldata);

	float signal = 0;
	float noise = 0;
	float s[16384];
	for (int i = 0; i < 16384; i++) {  //����
		s[i] = Signaldata[i];
	}

	for (int i = 0; i < 50; i++) {
		signal += Signaldata[300 + i];  //signaldata�����±�300--349��Ԫ���ۼӵ�signal������
		noise += Signaldata[6000 + i];  //signaldata�����±�6000--6049��Ԫ���ۼӵ�noise������
	}
	float snr = signal / noise;         //�е��������   

	if (snr > 5) {

		//���� PNdata_buhuo_I��PNdata_buhuo_QӦ�ô�ŵ��ǣ��������ݽ��и���Ҷ�任��Ȼ����ȡ���������ݡ�
		//PNdata_buhuo_I��PNdata_buhuo_Q �����볤��Ϊ4096��Ȼ�����2��������ݱ��8192���ټ���8192����Ĳ���
		//��Ϊ ��ģ������������ź����ݶθ��������ݶν����ԣ�������ز��������Զ�ӦƵ����Ҫȡ������
		//��ѭ���ǽ���һ����������һ�������ĵ�˲���----��Ӧ��ʱ�����൱��Ƶ�ʳ˻���
		//Ȼ��Ƶ���˼������ݱ��浽�����У�DotMultI��DotMultQ
		for (int i = 0; i < capture_len; i++)
		{
			DotMultI[i] = SignalFFTI[i] * WCdmadata.PNdata_buhuo_I[i] - SignalFFTQ[i] * WCdmadata.PNdata_buhuo_Q[i];
			DotMultQ[i] = SignalFFTI[i] * WCdmadata.PNdata_buhuo_Q[i] + SignalFFTQ[i] * WCdmadata.PNdata_buhuo_I[i];
		}

		//�����渵��Ҷ�任��ת����ʱ��󣬽��еõ������ֵ���������ݵ�ģ���浽i_fft_abs����
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

		//�������ֵ
		float Capture_max[2] = { 0 };							//��һ��Ԫ�ش�����ֵ�±꣬�ڶ���Ԫ�ش�����ֵ
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


//ͬ������
void SingleWcdma::symbolsync(float* inputI, float* inputQ, int signallen, float* PNnow_jieI, float* PNnow_jieQ, Users muser, float* synchresultI, float* synchresultQ)
{
	/*  �ɰ汾���壺
		inputI �����ź�ʵ�����ݣ�inputQ �����ź��鲿����
		signallen �����źŵĳ���
		PNnow_jieI �Լ� PNnow_jieQ ���ⲿ���������ݣ������I·��Ƶ����˺� ��Point�������� ��ȡ���� ���ʵ�����鲿
		muser �������I·���ݣ���ÿһ���û�������Ϣ���ʡ���Ƶ�볤���Լ���Ƶ��
		synchresultI��synchresultQ �Ǵ�ģ�������������Ľ������I·��Q·�Ľ�������
	*/

	/*  �°汾���壺
		inputI �����ź�ʵ�����ݣ�inputQ �����ź��鲿����
		signallen �����źŵĳ���
		PNnow_jieI �Լ� PNnow_jieQ ���ⲿ���������ݣ����� Point�������� ��ȡ���� ���ʵ�����鲿
		PNnow_jieI��PNnow_jieQ ���������� 76800����---------------------------------------------------
		muser �������I·���ݣ���ÿһ���û�������Ϣ���ʡ���Ƶ�볤���Լ���Ƶ��
		synchresultI��synchresultQ ��ŵ��Ǵ�ģ�������������Ľ������I·��Q·�Ľ�������
	*/

	int i, j, k;
	int  Symbol, SymbolNum;
	//**************************************** α��ͬ�� *******************************************
	
	// α��ͬ����������뷨��һ��forѭ��Ȼ���Ӧ��һ���������ô��Ȼϣ��������ǣ�һ�����š��������Ż���������....
	// ����ȡ������Ƶ�볤��256������Ӧ256����Ƭ����һ����Ƭ���������㣬��512��
	// ������ӦQ·��˵��α��ͬ����һ��forѭ�����һ��������Ϣ������I·������˵��һ��forѭ��������ɸ����ţ�ȡ����I·��Ƶ�볤����Ϣ
	Symbol = point * spread_factor_Q;                               
	
	SymbolNum = floor(signallen / Symbol);                          // ������źŶ������ں��ж��ٸ�������Symbol���ȣ�floor��������ȡ����							

	int Simulation_Length = Symbol * SymbolNum;                     // ����ʹ�����ݳ��Ⱦ���Symbol����������
	
	float* PNsynchI = new float[Simulation_Length];                 //��� α��ͬ����һ��forѭ������Ľ������������ź���ź�
	memset(PNsynchI, 0, Simulation_Length * sizeof(float));			//���ɣ������ź� ���� ����Ĺ��� �൱�����������룬�����ĳ���������
	float* PNsynchQ = new float[Simulation_Length];
	memset(PNsynchQ, 0, Simulation_Length * sizeof(float));

	float* Vo_dep_I = new float[Simulation_Length];                 //��� α��ͬ����һ��forѭ������Ľ���������  ������ź��ź� ���� I·��Ƶ�� �Ľ�� 
	memset(Vo_dep_I, 0, Simulation_Length * sizeof(float));			//Ŀ���ǣ������ Vo_dep_I���л��֣��൱�ڶ�I·���ݽ����ˣ�����wash��Ƶ��+1��-1����һ����
	float* Vo_dep_Q = new float[Simulation_Length];
	memset(Vo_dep_Q, 0, Simulation_Length * sizeof(float));

	// ��������Ŀ���Ǵ�� �������ƺ����� �Լ����������� �ٽ��뻷·�˲��� һϵ�в��������õ����������
	int sys_gold_len = Gold_len * 2;                                // α��ͬ����Ҫ�����볤��38400*2=76800
	float* PNcodeCQ_I = new float[sys_gold_len];                    //�������I·��Q·����					
	memset(PNcodeCQ_I, 0, sys_gold_len * sizeof(float));
	float* PNcodeCQ_Q = new float[sys_gold_len];
	memset(PNcodeCQ_Q, 0, sys_gold_len * sizeof(float));

	float* PNcodeZH_I = new float[sys_gold_len];                     //��������������ƺ����ݣ��Ա�������������㣬
	memset(PNcodeZH_I, 0, sys_gold_len * sizeof(float));
	float* PNcodeZH_Q = new float[sys_gold_len];
	memset(PNcodeZH_Q, 0, sys_gold_len * sizeof(float));

	float* ovsfiCQ_A = new float[sys_gold_len];						  //���A�û���Ƶ�����ƺ����Ʋ����������					
	memset(ovsfiCQ_A, 0, sys_gold_len * sizeof(float));				  //��Ƶ��ֻ��ʵ��
	float* ovsfiZH_A = new float[sys_gold_len];
	memset(ovsfiZH_A, 0, sys_gold_len * sizeof(float));

	float* DLL_Phase_Part = new float[(SymbolNum + 1)];               //������·�˲������õ���������飬α��ͬ����forѭ����Ҫ�õ�
	memset(DLL_Phase_Part, 0, (SymbolNum + 1) * sizeof(float));
	float* DLL_Freq_Part = new float[(SymbolNum + 1)];
	memset(DLL_Freq_Part, 0, (SymbolNum + 1) * sizeof(float));
	float* EPNsynch = new float[(SymbolNum + 1)];
	memset(EPNsynch, 0, (SymbolNum + 1) * sizeof(float));

	float cqreal = 0, cqimag = 0, zhreal = 0, zhimag = 0, cqsum = 0, zhsum = 0;
	
	//--------------------------------------------------------------------------
	float* temp = new float[2];             //���������ʱ��֪������ʲô����           
	memset(temp, 0, sizeof(float) * 2);

	//��������൱�ڽ��н��Ų���
	for (int i = 0; i < SymbolNum; i++)      // ��ѭ���������з���
	{
		
		for (int j = 0; j < Symbol; j++)     // ��ѭ�����������ں��е����е㣨������512���㣩
		{
			//PNsynchI �� PNsynchQ�����ŵ��ǽ�������
			PNsynchI[i * Symbol + j] = inputI[i * Symbol + j] * PNnow_jieI[i * Symbol + j] - inputQ[i * Symbol + j] * PNnow_jieQ[i * Symbol + j];  // ��ż��������ݵ�ʵ������
			PNsynchQ[i * Symbol + j] = inputI[i * Symbol + j] * PNnow_jieQ[i * Symbol + j] + inputQ[i * Symbol + j] * PNnow_jieI[i * Symbol + j];  // ��ż��������ݵ��鲿����
		
			//����Vo_dep
			Vo_dep_I[i * Symbol + j] = PNsynchI[i * Symbol + j] * muser.Descramble_end_I[i * Symbol + j];
			Vo_dep_Q[i * Symbol + j] = PNsynchQ[i * Symbol + j] * muser.Descramble_end_I[i * Symbol + j];

		}

		//���¾��ǡ������š�������Ϊʲô�����ţ���Ϊ�����۹�ʽ�кܴ���
		//���ƺ�����Ϊ��ʹ����Ƶ��������� �������źŶ��룬����ֱ�ӵ�˽��н��Ž�������

		for (int j = 0; j < sys_gold_len - 1; j++)  // ��ѭ���Լ��������и�ֵ������Ŀ���Ƕ������������1����
		{											// ����Point��2(��һ����Ƭ��������)���������������������Ȼ�Ǵ���ģ���������
			PNcodeCQ_I[j] = PNnow_jieI[j + 1];		// Ӧ������һ����(�൱���ư����Ƭ)
			PNcodeCQ_Q[j] = PNnow_jieQ[j + 1];
			
			ovsfiCQ_A[j] = muser.Descramble_end_I[j + 1];
		}
		PNcodeCQ_I[sys_gold_len - 1] = PNnow_jieI[0];
		PNcodeCQ_Q[sys_gold_len - 1] = PNnow_jieQ[0];
		
		ovsfiCQ_A[sys_gold_len - 1] = muser.Descramble_end_I[0];


		for (int j = 1; j < sys_gold_len; j++)      // ��ѭ���Լ��������и�ֵ������Ŀ���Ƕ������������1����
		{											// ����Point��2(��һ����Ƭ��������)���������������������Ȼ�Ǵ���ģ���������									
			PNcodeZH_I[j] = PNnow_jieI[j - 1];		// Ӧ������һ����(�൱���ư����Ƭ)
			PNcodeZH_Q[j] = PNnow_jieQ[j - 1];

			ovsfiZH_A[j] = muser.Descramble_end_I[j - 1]; 
		}
		PNcodeZH_I[0] = PNnow_jieI[sys_gold_len - 1];
		PNcodeZH_Q[0] = PNnow_jieQ[sys_gold_len - 1];

		ovsfiZH_A[0] = muser.Descramble_end_I[sys_gold_len - 1];


		cqreal = 0;  cqimag = 0;
		zhreal = 0;  zhimag = 0;
		cqsum = 0;   zhsum = 0;

		for (int j = 0; j < Symbol; j++)            //�������--�����ź���������������ƺ���������ݽ��е�ˣ�Ȼ���ۼӽ��
		{											//�ۼӳ�����512������һ�������ڵĵ��������ۼ�
			cqreal = cqreal + inputI[i * Symbol + j] * PNcodeCQ_I[i * Symbol + j] - inputQ[i * Symbol + j] * PNcodeCQ_Q[i * Symbol + j];
			cqimag = cqimag + inputI[i * Symbol + j] * PNcodeCQ_Q[i * Symbol + j] + inputQ[i * Symbol + j] * PNcodeCQ_I[i * Symbol + j];
			
			zhreal = zhreal + inputI[i * Symbol + j] * PNcodeZH_I[i * Symbol + j] - inputQ[i * Symbol + j] * PNcodeZH_Q[i * Symbol + j];
			zhimag = zhimag + inputI[i * Symbol + j] * PNcodeZH_Q[i * Symbol + j] + inputQ[i * Symbol + j] * PNcodeZH_I[i * Symbol + j];
		}

		cqsum = cqreal * cqreal + cqimag * cqimag;  // ������ƽ��
		zhsum = zhreal * zhreal + zhimag * zhimag;

		j = i + 1;                                  // ����д�������𣿣�����������jû����������
		DLL_Phase_Part[j] = symbolsyncsactorInit.fSymbolSyncFactor2 * (cqsum - zhsum) / (cqsum + zhsum);
		DLL_Freq_Part[j] = 0.5 * (DLL_Freq_Part[i] + DLL_Phase_Part[j]);
		EPNsynch[j] = symbolsyncsactorInit.fSymbolSyncFactor1 * (cqsum - zhsum) / (cqsum + zhsum) + DLL_Freq_Part[j];

		//��ֵ�ж�
		if (EPNsynch[j] > symbolsyncsactorInit.ThresholdPositive)
		{
			for (k = 0; k < sys_gold_len; k++)      // �������½����ƺ���������Ƶ�� ���п�������,��������forѭ���еĽ��Ž�������
			{
				PNnow_jieI[k] = PNcodeCQ_I[k];
				PNnow_jieQ[k] = PNcodeCQ_Q[k];

				muser.Descramble_end_I[k] = ovsfiCQ_A[k];
			}

		}
		else if (EPNsynch[j] < symbolsyncsactorInit.ThresholdNegative)
		{
			for (k = 0; k < sys_gold_len; k++)		// �������½����ƺ���������Ƶ�� ���п�������,��������forѭ���еĽ��Ž�������
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


	//��������δ����Ƕ�һ�����Ž��л��֣���Ϊ����������жϣ�Ŀ�ĺ����ǽ����ת������
	float sumI1 = 0;
	float sumQ1 = 0;
	for (int i = 0; i < 512; i++)
	{
		sumI1 += PNsynchI[i];
		sumQ1 += PNsynchQ[i];
	}


	/************************  ���໷ȥƵƫ  ***************************/
	// �Խ����źŽ��л��ֲ�����ѡ��A�û�����Ƶ�볤��ԭ��
	// ���ȣ�I·��Ƶ��Ϊ����(256��128��64��32��)��ÿһ������ + 1�� - 1��������һ���ģ�
	// �����ڶ�һ�����Ż��߶�����Ž����ۼӵĻ��൱�� ��һ�����Ż������Ŷ����0��
	// ��Σ�Q·��Ƶ�볤Ϊ256����ȫΪ1����������ۼ������൱�ڻ�ԭ���������

	// ��һ�λ��ֲ���--�൱������Q·�������໷��������ز���Ȼ��I·��������ز��ﵽȥƵƫ��Ч��
	int sum_length = muser.spread_factor_I * point;
	int sum_number = floor(Simulation_Length / sum_length);

	float* Vo_sumreal = new float[sum_number];                  //��ŶԽ����źŻ��ֺ��ʵ������
	memset(Vo_sumreal, 0, sum_number * sizeof(float));			//����I·��Ƶ����Wash�룬��˻����൱��Ϊ����

	float* Vo_sumimag = new float[sum_number];                  //��ŶԽ����źŻ��ֺ���鲿����,����Q·��Ƶ��Ϊȫ1,
	memset(Vo_sumimag, 0, sum_number * sizeof(float));			//��˻�����sum_length����
																//�൱�ڻ�ԭ�� Q·��sum_length/spread_factor_Q * point������
	
	float* Vo_dep_A_sumreal = new float[sum_number];                    // ��Ŷ� �����źų���I·��Ƶ���Ľ�� ���ֺ��ʵ������
	memset(Vo_dep_A_sumreal, 0, sum_number * sizeof(float));			// ����I·��Ƶ����Wash�룬�����ź��ֳ�����I·��Ƶ�루������ʵ����sum_length����
																		// ��˻���sum_length�����൱�ڰ�I·���ݻ�ԭ������		
	
	float* Vo_dep_A_sumimag = new float[sum_number];                    // ��Ŷ� �����źų���I·��Ƶ���Ľ�� ���ֺ��ʵ������
	memset(Vo_dep_A_sumimag, 0, sum_number * sizeof(float));			// ����Q·��Ƶ����ȫһ�ģ������ź��ֳ�����I·��Ƶ�루������ʵ����sum_length��
																		// ��ô��ʱQ·���൱�� ��Ƶ��һ�������ڣ�+1��-1����һ���ˣ�
																		// ��˻���sum_length�����൱�ڰ�Q·���ݱ������
	//���ֲ���
	for (int k = 0; k < sum_number; k++)
	{
		int sumreal_temp = 0;
		int sumimag_temp = 0;
		int dep_sumreal_temp = 0;
		int dep_sumimag_temp = 0;
		//sum_length���Ƚ����ۼ�---����ָ���ֲ���
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
	
	//******************************�ͷ��ڴ�***************************  ����д���Ƿ������⣬�費��Ҫ�ͷ�
	DELETE_ARR(PNsynchI);
	DELETE_ARR(PNsynchQ);
	DELETE_ARR(Vo_dep_I);
	DELETE_ARR(Vo_dep_Q);
	//******************************�ͷ��ڴ�***************************  ����д���Ƿ������⣬�費��Ҫ�ͷ�


	int SRClen = sys_gold_len * point / muser.spread_factor_I;          // sys_gold_len*2=76800*2=153600��������ݳ����Ǵ�Ų���(Point=2)�������ʵ�����鲿��
	int src = muser.spread_factor_I / point;                            // I·��Ƶ�볤�ȳ���2Ϊʲô�� 


	float* NCO_Phase = new float[sum_number];				// ����˹��˹������Ҫ�õ���һЩ������������		
	memset(NCO_Phase, 0, sum_number * sizeof(float));		
	float* Discriminator_Out = new float[sum_number];
	memset(Discriminator_Out, 0, sum_number * sizeof(float));
	float* Freq_Control = new float[sum_number];
	memset(Freq_Control, 0, sum_number * sizeof(float));
	float* PLL_Phase_Part = new float[sum_number];
	memset(PLL_Phase_Part, 0, sum_number * sizeof(float));
	float* PLL_Freq_Part = new float[sum_number];
	memset(PLL_Freq_Part, 0, sum_number * sizeof(float));

	float* FsynchI = new float[sum_number];					// ���໷���������飬��ʵFsynchI�൱��Q·������
	memset(FsynchI, 0, sum_number * sizeof(float));
	float* FsynchQ = new float[sum_number];					// FsynchQ���������FsynchI��ͬ�����෴��ԭ������ʱ�����
	memset(FsynchQ, 0, sum_number * sizeof(float));


	float* Vo_dep_A_real = new float[sum_number];			// �������໷�Խ����źŻ��ֺ�ĸ����ز����
	memset(Vo_dep_A_real, 0, sum_number * sizeof(float));	// Ȼ����Vo_dep_A���ز�������ˣ���Vo_dep_AƵƫ����
	float* Vo_dep_A_imag = new float[sum_number];			// Vo_dep_A_real�൱��I·��A�û���������,		
	memset(Vo_dep_A_imag, 0, sum_number * sizeof(float));	// Vo_dep_A_imag������ܸ�Vo_dep_A_real��ͬ�����෴��ԭ������ʱ�����


	if (abs(sumI1) < abs(sumQ1))
	{

		for (int i = 1; i < sum_number; i++)
		{
			FsynchI[i] = Vo_sumreal[i] * cos(NCO_Phase[(i - 1)]) + Vo_sumimag[i] * sin(NCO_Phase[(i - 1)]);       //��˹��˹�����,�൱��Q·�������
			FsynchQ[i] = Vo_sumimag[i] * cos(NCO_Phase[(i - 1)]) - Vo_sumreal[i] * sin(NCO_Phase[(i - 1)]);

			Discriminator_Out[i] = (FsynchI[i] > 0 ? FsynchQ[i] : -FsynchQ[i]) - (FsynchQ[i] > 0 ? FsynchI[i] : -FsynchI[i]);//���FsynchI=0��,FsynchQ=0,��ȡ0����������

			PLL_Phase_Part[i] = Discriminator_Out[i] * CostasPll.fPLLLoopFilterCoef1;
			PLL_Freq_Part[i] = Discriminator_Out[i] * CostasPll.fPLLLoopFilterCoef2 + PLL_Freq_Part[i - 1];
			Freq_Control[i] = PLL_Phase_Part[i] + PLL_Freq_Part[i];
			NCO_Phase[i] = NCO_Phase[i - 1] + Freq_Control[i] * 2 * Pi;

			Vo_dep_A_real[i] = Vo_dep_A_sumreal[i] * cos(NCO_Phase[(i - 1)]) + Vo_dep_A_sumimag[i] * sin(NCO_Phase[(i - 1)]); //�൱��I·�������
			Vo_dep_A_imag[i] = Vo_dep_A_sumimag[i] * cos(NCO_Phase[(i - 1)]) - Vo_dep_A_sumreal[i] * sin(NCO_Phase[(i - 1)]);

			synchresultI[i] = Vo_dep_A_real[i];  //��I·�������������synchresultI������
			//synchresultQ[i] = FsynchQ[i];								 

			/*PNsynchI[i] = PNsynchI[i] * muser.Descramble_end_I[i];*/
			//printf("%d==%f\t", i, synchresultI[i]);
			//printf("%d==%f\n", i, synchresultQ[i]);
		}

		// �ڶ��λ��ֲ���--Ŀ���ǣ���Q·���ݡ�����������һ�λ��ֲ����� Vo_sumimag��ÿһ��Ԫ��
		// �൱�ڻ�ԭ��Q·������sum_length/spread_factor_Q * point�����ţ�������Ҫ���ֳ���Ϊ��
		// spread_factor_Q * point/sum_length����FsynchI���� ��Q·������ԭ����

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
			//**************************�ĵÿ��ܴ�������*********************************//
			FsynchI[i] = Vo_sumimag[i] * cos(NCO_Phase[(i - 1)]) + Vo_sumreal[i] * sin(NCO_Phase[(i - 1)]);
			FsynchQ[i] = Vo_sumreal[i] * cos(NCO_Phase[(i - 1)]) - Vo_sumimag[i] * sin(NCO_Phase[(i - 1)]);
			Discriminator_Out[i] = (FsynchI[i] > 0 ? FsynchQ[i] : -FsynchQ[i]) - (FsynchQ[i] > 0 ? FsynchI[i] : -FsynchI[i]);//���FsynchI=0��,FsynchQ=0,��ȡ0����������
			PLL_Phase_Part[i] = Discriminator_Out[i] * CostasPll.fPLLLoopFilterCoef1;
			PLL_Freq_Part[i] = Discriminator_Out[i] * CostasPll.fPLLLoopFilterCoef2 + PLL_Freq_Part[i - 1];
			Freq_Control[i] = PLL_Phase_Part[i] + PLL_Freq_Part[i];
			NCO_Phase[i] = NCO_Phase[i - 1] + Freq_Control[i] * 2 * Pi;

			//**************************�ĵÿ��ܴ�������*********************************//
			Vo_dep_A_real[i] = Vo_dep_A_sumimag[i] * cos(NCO_Phase[(i - 1)]) + Vo_dep_A_sumreal[i] * sin(NCO_Phase[(i - 1)]); //�൱��I·�������
			Vo_dep_A_imag[i] = Vo_dep_A_sumreal[i] * cos(NCO_Phase[(i - 1)]) - Vo_dep_A_sumimag[i] * sin(NCO_Phase[(i - 1)]);

			synchresultI[i] = Vo_dep_A_real[i];  //��I·�������������synchresultI������

			// �ڶ��λ��ֲ���--Ŀ���ǣ���Q·���ݡ�����������һ�λ��ֲ����� Vo_sumimag��ÿһ��Ԫ��
			// �൱�ڻ�ԭ��Q·������sum_length/spread_factor_Q * point�����ţ�������Ҫ���ֳ���Ϊ��
			// spread_factor_Q * point/sum_length����FsynchI���� ��Q·������ԭ����

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



