#pragma once

#include <stdio.h>    
#include <stdlib.h>  
#include <math.h>   
#include <iostream>   

using namespace std;

//*******************2023/9/17 19:56*********************//
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;

#define PI 3.14159//Բ���ʺ궨��   
#define LENGTH_NAME_BMP 30//bmpͼƬ�ļ�������󳤶�   

//λͼ�ļ�ͷ����;   
//���в������ļ�������Ϣ�����ڽṹ����ڴ�ṹ������   
//Ҫ�Ǽ��˵Ļ���������ȷ��ȡ�ļ���Ϣ��   
typedef struct  tagBITMAPFILEHEADER {
    //WORD bfType;//�ļ����ͣ�������0x424D�����ַ���BM��   
    DWORD bfSize;//�ļ���С   
    WORD bfReserved1;//������   
    WORD bfReserved2;//������   
    DWORD bfOffBits;//���ļ�ͷ��ʵ��λͼ���ݵ�ƫ���ֽ���   
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;//��Ϣͷ��С   
    LONG biWidth;//ͼ����   
    LONG biHeight;//ͼ��߶�   
    WORD biPlanes;//λƽ����������Ϊ1   
    WORD biBitCount;//ÿ����λ��   
    DWORD  biCompression; //ѹ������   
    DWORD  biSizeImage; //ѹ��ͼ���С�ֽ���   
    LONG  biXPelsPerMeter; //ˮƽ�ֱ���   
    LONG  biYPelsPerMeter; //��ֱ�ֱ���   
    DWORD  biClrUsed; //λͼʵ���õ���ɫ����   
    DWORD  biClrImportant; //��λͼ����Ҫ��ɫ����   
}BITMAPINFOHEADER; //λͼ��Ϣͷ����   

typedef struct tagRGBQUAD {
    BYTE rgbBlue; //����ɫ����ɫ����   
    BYTE rgbGreen; //����ɫ����ɫ����   
    BYTE rgbRed; //����ɫ�ĺ�ɫ����   
    BYTE rgbReserved; //����ֵ   
}RGBQUAD;//��ɫ�嶨��   

//������Ϣ   
typedef struct tagIMAGEDATA
{
    BYTE blue;
    BYTE green;
    BYTE red;
}IMAGEDATA;


//��������   
BITMAPFILEHEADER strHead;
RGBQUAD strPla[256];//256ɫ��ɫ��   
BITMAPINFOHEADER strInfo;


//��ʾλͼ�ļ�ͷ��Ϣ   
void showBmpHead(BITMAPFILEHEADER pBmpHead);
void showBmpInforHead(tagBITMAPINFOHEADER pBmpInforHead);
