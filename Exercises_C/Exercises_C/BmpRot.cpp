#define _CRT_SECURE_NO_WARNINGS 1

#include "BmpRot.h"   

//*******************2023/9/17 19:56*********************//

//��ʾλͼ�ļ�ͷ��Ϣ   
void showBmpHead(BITMAPFILEHEADER pBmpHead) {
    cout << "λͼ�ļ�ͷ:" << endl;
    cout << "�ļ���С:" << pBmpHead.bfSize << endl;
    cout << "������_1:" << pBmpHead.bfReserved1 << endl;
    cout << "������_2:" << pBmpHead.bfReserved2 << endl;
    cout << "ʵ��λͼ���ݵ�ƫ���ֽ���:" << pBmpHead.bfOffBits << endl << endl;
}

void showBmpInforHead(tagBITMAPINFOHEADER pBmpInforHead) {
    cout << "λͼ��Ϣͷ:" << endl;
    cout << "�ṹ��ĳ���:" << pBmpInforHead.biSize << endl;
    cout << "λͼ��:" << pBmpInforHead.biWidth << endl;
    cout << "λͼ��:" << pBmpInforHead.biHeight << endl;
    cout << "biPlanesƽ����:" << pBmpInforHead.biPlanes << endl;
    cout << "biBitCount������ɫλ��:" << pBmpInforHead.biBitCount << endl;
    cout << "ѹ����ʽ:" << pBmpInforHead.biCompression << endl;
    cout << "biSizeImageʵ��λͼ����ռ�õ��ֽ���:" << pBmpInforHead.biSizeImage << endl;
    cout << "X����ֱ���:" << pBmpInforHead.biXPelsPerMeter << endl;
    cout << "Y����ֱ���:" << pBmpInforHead.biYPelsPerMeter << endl;
    cout << "ʹ�õ���ɫ��:" << pBmpInforHead.biClrUsed << endl;
    cout << "��Ҫ��ɫ��:" << pBmpInforHead.biClrImportant << endl;
}
