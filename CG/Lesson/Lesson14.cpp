#include "stdafx.h"
#include <stdio.h>	
#include <iostream>												// 标准输入输出头文件
#include <olectl.h>												// OLE控制库头文件
#include <math.h>												// 数学函数头文件
#include "Texture.h"
#include <glut.h>		


int width=1024, height=768;
int ww=width,hh=height;  // get the current window's size
float rotatex=0, rotatey=0;

int edge=50;  //the cube's edge

GLuint textureid[6];


void init();
void Display(void);
void Reshape(int w,int h);
void myidle(void);
void Cube(void);


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
 
	char *argv[] = {"hello ", " "};
	int argc = 2; // must/should match the number of strings in argv

	glutInit(&argc, argv);    //初始化GLUT库；
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   //设置显示模式；（缓冲，颜色类型）
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1024 / 2 - 250, 768 / 2 - 250);
	glutCreateWindow("3D-cube texture");  //创建窗口，标题为“Rotating 3D World”；
	 glutReshapeFunc(Reshape);
	init();
	glutDisplayFunc(Display);  //用于绘制当前窗口；
	glutIdleFunc(myidle);
	glutMainLoop();   //表示开始运行程序，用于程序的结尾；

	return 0;
}



void init(void)
{
	//glClearColor(1.0,1.0,1.0,1.0);
	glLineWidth(1.0);
	glPointSize(1.0);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	BuildTexture("smile.jpg", textureid[0]);
	BuildTexture("smile1.jpg", textureid[1]);
	BuildTexture("smile2.jpg", textureid[2]);
	BuildTexture("smile3.jpg", textureid[3]);
	BuildTexture("smile4.jpg", textureid[4]);
	BuildTexture("smile5.jpg", textureid[5]);

	glEnable(GL_TEXTURE_2D);

}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2*edge,2*edge, 2*edge,0,0,0,0,1,0);  //set the viewing point 
	glRotatef(rotatey,0,1,0);  //rorate about the y axis
	glRotatef(rotatex,1,0,0);  //rorate about the x axis
	Cube();   // draw a cube ,it's center located in the original point 
	glutSwapBuffers();
}


void Reshape(GLsizei w,GLsizei h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	ww=w;
	hh=h;

	gluPerspective(50,ww/hh,20,1000);  //透视投影
	glViewport(0,0,w,h);
	glMatrixMode(GL_MODELVIEW);
}


void Cube()
{
	glBindTexture(GL_TEXTURE_2D, textureid[0]);
	glBegin(GL_QUADS);
	//front face
	glNormal3f(0,0,1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(edge/2,edge/2,edge/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-edge/2,edge/2,edge/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-edge/2,-edge/2,edge/2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(edge/2,-edge/2,edge/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textureid[1]);
	glBegin(GL_QUADS);
	//back face
	glNormal3f(0,0,-1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-edge/2,edge/2,-edge/2);  
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(edge/2,edge/2,-edge/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(edge/2,-edge/2,-edge/2);	
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-edge/2,-edge/2,-edge/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textureid[2]);
	glBegin(GL_QUADS);
	//left face
	glNormal3f(-1,0,0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-edge/2,edge/2,edge/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-edge/2,edge/2,-edge/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-edge/2,-edge/2,-edge/2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-edge/2,-edge/2,edge/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textureid[3]);
	glBegin(GL_QUADS);
	//right face
	glNormal3f(1,0,0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(edge/2,edge/2,-edge/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(edge/2,edge/2,edge/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(edge/2,-edge/2,edge/2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(edge/2,-edge/2,-edge/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textureid[4]);
	glBegin(GL_QUADS);
	//upper face
	glNormal3f(0,1,0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(edge/2,edge/2,edge/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(edge/2,edge/2,-edge/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-edge/2,edge/2,-edge/2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-edge/2,edge/2,edge/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textureid[5]);
	glBegin(GL_QUADS);
	//lower face
	glNormal3f(0,-1,0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(edge/2,-edge/2,edge/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-edge/2,-edge/2,edge/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-edge/2,-edge/2,-edge/2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(edge/2,-edge/2,-edge/2);
	glEnd();
}

void myidle()
{
	::Sleep(1);
	rotatex+=1;
	rotatey+=1;	
	glutPostRedisplay();
}


#ifndef GL_TEXTURE_LOADER
#define GL_TEXTURE_LOADER

#include <gl/gl.h>
#include <gl/glu.h>


typedef struct													// 建立一个结构体
{
	GLubyte	*imageData;											// 图像数据(最高bit)
	GLuint	bpp;												// 每一象素的图像颜色深度
	GLuint	width;												// 图像宽度
	GLuint	height;												// 图像高度
	GLuint	texID;												// 纹理ID
} TextureTga;



// 载入TGA,BMP,JPG,GIF等文件
bool BuildTexture(char *filename,GLuint &texid);

#endif



#include "stdafx.h"
#include <stdio.h>
#include <string.h>
//#include <stdafx.h>											// 标准输入输出头文件
#include <olectl.h>												// OLE控制库头文件
#include <math.h>												// 数学函数头文件
//#include <gl.h>
//#include <glu.h>
//#include <glaux.h>
//#include <glut.h>												// OpenGL32库的头文件
#include "Texture.h"
#define GL_CLAMP_TO_EDGE	0x812F

bool BuildTexture(char *filename,GLuint &texid )					// 载入一个.TGA 文件到内存
{  
			
	GLubyte		TGAheader[12] = {0,0,2,0,0,0,0,0,0,0,0,0};				// 没有压缩的TGA Header
	GLubyte		TGAcompare[12];								// 用来比较TGA Header
	GLubyte		header[6];									// Header里，头六个有用字节
	GLuint		bytesPerPixel;				  	// 保存TGA文件里每个像素用到的字节数
	GLuint		imageSize;							// 用来保存随机产生的图像的大小
	GLuint		temp;											// 临时变量
	GLuint		type = GL_RGBA;								// 将默认的GL模式设置为RBGA (32 BPP)
	GLubyte	*imageData;										// 图像数据(最高bit)
	GLuint	bpp;											// 每一象素的图像颜色深度
	GLuint	width;												// 图像宽度
	GLuint	height;												// 图像高度
   

    HDC			hdcTemp;										// DC用来保存位图
	HBITMAP		hbmpTemp;									// 保存临时位图
	IPicture	*pPicture;										// 定义IPicture Interface
	OLECHAR		wszPath[MAX_PATH+1];						// 图片的完全路径
	char		szPath[MAX_PATH+1];								// 图片的完全路径
	long		lWidth;												// 图像宽度
	long		lHeight;												// 图像高度
	long		lWidthPixels;									// 图像的宽带(以像素为单位)
	long		lHeightPixels;									// 图像的高带(以像素为单位)
	GLint		glMaxTexDim ;							// 保存纹理的最大尺寸
	
	
	
    if (strstr(filename, "JPG")||strstr(filename, "bmp")||strstr(filename, "jpg")||strstr(filename, "BMP"))
   {
	   
        
	if (strstr(filename, "http://"))								// 如果路径包含http:// 则...
	{
		strcpy(szPath, filename);								// 把路径拷贝到szPath
	}
	else														// 否则从文件导入图片
	{
		GetCurrentDirectoryA(MAX_PATH, szPath);							// 取得当前路径
		strcat(szPath, "\\");											// 添加字符"\"
		strcat(szPath, filename);									// 添加图片的相对路径
	}

	MultiByteToWideChar(CP_ACP, 0, szPath, -1, wszPath, MAX_PATH);		// 把ASCII码转化为Unicode标准码
	HRESULT hr = OleLoadPicturePath(wszPath, 0, 0, 0, IID_IPicture, (void**)&pPicture);

	if(FAILED(hr))												// 如果导入失败
	{
		// 图片载入失败出错信息
		MessageBoxA (HWND_DESKTOP, "图片导入失败!\n(TextureLoad Failed!)", "Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;													// 返回FALSE
	}

	hdcTemp = CreateCompatibleDC(GetDC(0));						// 建立窗口设备描述表
	if(!hdcTemp)														// 建立失败?
	{
		pPicture->Release();											// 释放IPicture
		// 图片载入失败出错信息
		MessageBoxA (HWND_DESKTOP, "图片导入失败!\n(TextureLoad Failed!)", "Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;													// 返回FALSE
	}

	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &glMaxTexDim);	// 取得支持的纹理最大尺寸
	
	pPicture->get_Width(&lWidth);					// 取得IPicture 宽度(转换为Pixels格式)
	lWidthPixels	= MulDiv(lWidth, GetDeviceCaps(hdcTemp, LOGPIXELSX), 2540);
	pPicture->get_Height(&lHeight);					// 取得IPicture 高度(转换为Pixels格式)
	lHeightPixels	= MulDiv(lHeight, GetDeviceCaps(hdcTemp, LOGPIXELSY), 2540);

	// 调整图片到最好的效果
	if (lWidthPixels <= glMaxTexDim)					// 图片宽度是否超过显卡最大支持尺寸
		lWidthPixels = 1 << (int)floor((log((double)lWidthPixels)/log(2.0f)) + 0.5f); 
	else										// 否则,将图片宽度设为显卡最大支持尺寸
		lWidthPixels = glMaxTexDim;
 
	if (lHeightPixels <= glMaxTexDim)					// 图片高度是否超过显卡最大支持尺寸
		lHeightPixels = 1 << (int)floor((log((double)lHeightPixels)/log(2.0f)) + 0.5f);
	else										// 否则,将图片高度设为显卡最大支持尺寸
		lHeightPixels = glMaxTexDim;

	// 建立一个临时位图
	BITMAPINFO	bi = {0};												// 位图的类型
	DWORD		*pBits = 0;								// 指向位图Bits的指针

	bi.bmiHeader.biSize			= sizeof(BITMAPINFOHEADER);				// 设置结构大小
	bi.bmiHeader.biBitCount		= 32;									// 32 位
	bi.bmiHeader.biWidth		= lWidthPixels;							// 宽度像素值
	bi.bmiHeader.biHeight		= lHeightPixels;						// 高度像素值
	bi.bmiHeader.biCompression	= BI_RGB;								// RGB 格式
	bi.bmiHeader.biPlanes		= 1;									// 一个位平面

	// 建立一个位图这样我们可以指定颜色和深度并访问每位的值
	hbmpTemp = CreateDIBSection(hdcTemp, &bi, DIB_RGB_COLORS, (void**)&pBits, 0, 0);
	
	if(!hbmpTemp)														// 建立失败?
	{
		DeleteDC(hdcTemp);									// 删除设备描述表
		pPicture->Release();											// 释放IPicture
		// 图片载入失败出错信息
		MessageBoxA (HWND_DESKTOP, "图片导入失败!\n(TextureLoad Failed!)", "Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;													// 返回FALSE
	}

	SelectObject(hdcTemp, hbmpTemp);				// 选择临时DC句柄和临时位图对象

	// 在位图上绘制IPicture
	pPicture->Render(hdcTemp, 0, 0, lWidthPixels, lHeightPixels, 0, lHeight, lWidth, -lHeight, 0);

	// 将BGR转换为RGB　将ALPHA值设为
	for(long i = 0; i < lWidthPixels * lHeightPixels; i++)				// 循环遍历所有的像素
	{
		BYTE* pPixel	= (BYTE*)(&pBits[i]);							// 获取当前像素
		BYTE  temp		= pPixel[0];					// 临时存储第一个颜色像素(蓝色)
		pPixel[0]		= pPixel[2];							// 将红色值存到第一位
		pPixel[2]		= temp;								// 将蓝色值存到第三位
		pPixel[3]		= 255;										// ALPHA值设为
	}

	glGenTextures(1, &texid);											// 创建纹理

	// 使用来自位图数据生成的典型纹理
	glBindTexture(GL_TEXTURE_2D, texid);		// 绑定纹理

	
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// 线形滤波
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   // 线形滤波


    /*
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	*/
  //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR); //缩小采用三线性滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//放大采用线性滤波
 //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 

  
  //   glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  


	// 生成纹理
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, lWidthPixels, lHeightPixels, 0, GL_RGB, GL_UNSIGNED_BYTE, pBits);
//	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,lWidthPixels, lHeightPixels,0,GL_RGB,GL_UNSIGNED_BYTE,pBits);

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, lWidthPixels, lHeightPixels, GL_RGBA, GL_UNSIGNED_BYTE, pBits);

	DeleteObject(hbmpTemp);												// 删除对象
	DeleteDC(hdcTemp);													// 删除设备描述表

	pPicture->Release();												// 释放IPicture


   }


   
   else if (strstr(filename, "TGA")||strstr(filename, "tga"))									// 如果路径包含http:// 则...
	{
         
//	GLuint	texID;												// 纹理ID
	FILE *file = fopen(filename, "rb");									// 打开TGA 文件

	if (file == NULL)										// 文件是否已存在?
	{
		// 图片载入失败出错信息
		MessageBoxA (HWND_DESKTOP, "图片导入失败!\n(TextureLoad Failed!)", "Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;												// 返回FALSE
	}

	if (fread(TGAcompare,1,sizeof(TGAcompare),file) != sizeof(TGAcompare)// 是否有十二个字节可读?
		|| memcmp(TGAheader,TGAcompare,sizeof(TGAheader)) != 0			// header和我们想要的是否相符?
		|| fread(header,1,sizeof(header),file) != sizeof(header))		// 如果是读下六个字节
	{
		fclose(file);										// 如果失败,关闭文件
		// 图片载入失败出错信息
		MessageBoxA (HWND_DESKTOP, "图片导入失败!\n(TextureLoad Failed!)", "Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;													// 返回FALSE
	}

	width  = header[1] * 256 + header[0];				// 确定的TGA 宽度(高字节*256+低字节)
	height = header[3] * 256 + header[2];				// 确定的TGA 高度(高字节*256+低字节)
    
 	if (width	<= 0											// 宽度是否小于等于
		|| height	<= 0										// 高度是否小于等于
		||(header[4] != 24 && header[4] != 32))							// TGA 是位或位?
	{
		fclose(file);								// 任何一个不成立, 则关闭文件
		// 图片载入失败出错信息
		MessageBoxA (HWND_DESKTOP, "图片导入失败!\n(TextureLoad Failed!)", "Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;													// 返回FALSE
	}

    bpp	= header[4];									// 获取TGA每个像素的位(24 or 32)
	bytesPerPixel	= bpp / 8;									// 除以以取得每个像素的字节
	imageSize		= width*height*bytesPerPixel;		// 计算TAG数据所需要的内存

	imageData = (GLubyte *)malloc(imageSize);			// 开辟一个内存空间用来存储TGA数据

	if (imageData == NULL 								// 用来存储的内存是否存在?
		|| fread(imageData, 1, imageSize, file) != imageSize)	// 图像大小是否和内存空间大小相符？
	{
		if (imageData != NULL)									// 图像数据是否载入
		{
			free(imageData);									// 如果是释放图像数据
		}
		fclose(file);													// 关闭文件
		MessageBoxA (HWND_DESKTOP, "图片导入失败!\n(TextureLoad Failed!)", "Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;													// 返回FALSE
	}

	for (GLuint i=0; i<int(imageSize); i+=bytesPerPixel)				// 循环遍历图像数据
	{												// 交换第一和第三字节(红和蓝)
		temp=imageData[i];							// 将图像数据‘i’的值存在临时变量中
		imageData[i] = imageData[i + 2];				// 将第三个字节的值存到第一个字节里
		imageData[i + 2] = temp;					// 将临时变量的值存入第三字节(第一字节的值)
	}

	fclose (file);													// 关闭文件

	//创建一种纹理
	glGenTextures(1, &texid);									// 产生OpenGL纹理ID

	glBindTexture(GL_TEXTURE_2D, texid);						// 绑定纹理
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// 线性滤波
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// 线性滤波

	
	if (bpp == 24)												// TGA图片是不是24 位的
	{
		type = GL_RGB;								// 如果是将'type'设置为GL_RGB
	}

	glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, imageData);
	
    free(imageData);
   }
	

   DeleteObject(hbmpTemp);												// 删除对象
	DeleteDC(hdcTemp);											// 删除设备描述表
	return TRUE;											// 纹理创建成功，返回正确
}




#include "stdafx.h"
#include <stdio.h>	
//#include <iostream.h>									// 标准输入输出头文件
//#include <olectl.h>									// OLE控制库头文件
#include <math.h>									// 数学函数头文件
//#include <gl/gl.h>
//#include <gl/glu.h>
#include <glaux.h>
#include "Texture.h"
#include <glut.h>		

int width=512,height=512;
int ww=width,hh=height;  // get the current window's size
//float rotatex=0, rotatey=0;

int fire=1;
int k=4;
int edge=50;  //the cube's edge

GLuint textureid[16];
int flag=0;

void init();
void Display(void);
void Reshape(int w,int h);
void mymenu(int value);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
 
	char *argv[] = {"hello ", " "};
	int argc = 2; // must/should match the number of strings in argv

	glutInit(&argc, argv);    //初始化GLUT库；
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   //设置显示模式；（缓冲，颜色类型）
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1024 / 2 - 250, 768 / 2 - 250);
	glutCreateWindow("Start Picture");  //创建窗口，标题为“Rotating 3D World”；
	
	 glutCreateMenu(mymenu);   //添加快捷菜单
    glutAddMenuEntry("start picture1-plane shooting",0);
    glutAddMenuEntry("start picture2-roaming system",1);
	glutAddMenuEntry("start picture3-3D box pusher",2);
	glutAddMenuEntry("start picture4-snow man",3);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);   //将菜单付给鼠标右键
	
	glutReshapeFunc(Reshape);
	init();
	glutDisplayFunc(Display);  //用于绘制当前窗口；
	glutMainLoop();   //表示开始运行程序，用于程序的结尾；

	return 0;
}



void init(void)
{

//glClearColor(1.0,1.0,1.0,1.0);

//glCullFace(GL_BACK);
//glEnable(GL_CULL_FACE);

BuildTexture("start1.jpg", textureid[0]);
BuildTexture("start2.jpg", textureid[1]);
BuildTexture("start3.jpg", textureid[2]);
BuildTexture("start4.jpg", textureid[3]);

glEnable(GL_TEXTURE_2D);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (fire==1)
    glBindTexture(GL_TEXTURE_2D, textureid[flag]);

	glBegin(GL_QUADS);
	    glTexCoord2f(0.0f, 0.0f);
        glVertex2f(-edge/2,-edge/2);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(edge/2,-edge/2);
		
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(edge/2,edge/2);
		
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-edge/2,edge/2);
	glEnd();
	glutSwapBuffers();
}

void mymenu(int value)
{

	  flag=value;
	  glutPostRedisplay();
} 


void Reshape(GLsizei w,GLsizei h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	ww=w;
	hh=h;

    gluOrtho2D(-edge/2,edge/2,-edge/2,edge/2);
	glViewport(0,0,w,h);
	glMatrixMode(GL_MODELVIEW);

}




#include "stdafx.h"
#include <stdio.h>	
//#include <iostream.h>
//#include "windows.h"	
#include <math.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
#include <glaux.h>

#include "Texture.h"
#include <glut.h>


#define PI 3.14159

float theta=-90.0; //圆环旋转角
float angle=10; //左右场景每次旋转角
float sightangle=-90;
float s=10; //前后直走步长
float R=100; 
int inner=10,outer=80;

float eyex=0,eyey=0,eyez=outer+4*inner+50;  //初始视点位置
float atx=0,aty=0,atz=0;     //初始目标点位置
float atx1,atz1,eyex1,eyez1;

float tt=0,tt2=0;

// void specialkeyboard(int key, int x, int y);
void mykeyboard(unsigned char key, int x, int y);
void Display(void);
void Reshape(int w, int h);
void myidle();
void drawground();
void drawsphere();
void drawwall();
void init();

GLuint textureid[3];


/*
// Light and material Data
GLfloat fLightPos[4]   = { -100.0f, 100.0f, 50.0f, 1.0f };  // Point source
GLfloat fNoLight[] = { 0.0f, 0.0f, 0.0f, 0.0f };
GLfloat fLowLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
GLfloat fBrightLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
*/ 


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
 
	char *argv[] = {"hello ", " "};
	int argc = 2; // must/should match the number of strings in argv

	glutInit(&argc, argv);    //初始化GLUT库；
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   //设置显示模式；（缓冲，颜色类型）
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1024 / 2 - 250, 768 / 2 - 250);
	glutCreateWindow("Rotating 3D World");  //创建窗口，标题为“Rotating 3D World”；
	 glutReshapeFunc(Reshape);
	init();
	glutDisplayFunc(Display);  //用于绘制当前窗口；
	 glutKeyboardFunc(mykeyboard);
	glutIdleFunc(myidle);
	glutMainLoop();   //表示开始运行程序，用于程序的结尾；

	return 0;
}






void init()
{


	//define light position1
	GLfloat light_position1[]={-outer,outer,outer+4*inner+50,0.0};
	//	GLfloat light_position1[]={0,0,0,0.0};
	GLfloat light_position2[]={+outer,-outer,outer+inner,0.0};

	//GLfloat light color1
	GLfloat light_ambient1[]={1.0,1.0,1.0,1.0};
	GLfloat light_diffuse1[]={1.0,1.0,1.0,1.0};
	GLfloat light_specular1[]={1.0,1.0,1.0,1.0};

	//GLfloat light color2
	GLfloat light_ambient2[]={0.8,0.8,0.8,1.0};
	GLfloat light_diffuse2[]={0.8,0.8,0.8,1.0};
	GLfloat light_specular2[]={0.8,0.8,0.8,1.0};

    // light model- global light	
	GLfloat lmodel_ambient[]={0.8,0.2,0.2,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	

	// set light source location
	glLightfv(GL_LIGHT0,GL_POSITION,light_position1);
	glLightfv(GL_LIGHT1,GL_POSITION,light_position2);

	// set light source color;
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient1);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse1);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular1);

	// set light source color;
    glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient2);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse2);
	glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular2);


    
	// set material let material fits color	
	
    glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
    

	//make light source enable;
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

	//clear color
	glClearColor(0.0,0.0,0.0,0.0);

	//Color shade mode
	glShadeModel(GL_SMOOTH);
   // glShadeModel(GL_FLAT);  

     // polygon mode   
     glPolygonMode(GL_FRONT,GL_FILL);

	 //set material reflection
	
  	GLfloat mat_specular1[]={1.0,1.0,1.0,1.0};
	GLfloat mat_shininess1[]={60.0};
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular1);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess1);

     // depth detecting
	  glEnable(GL_DEPTH_TEST);

	 	 
	  BuildTexture("tu.jpg", textureid[0]);
	   BuildTexture("tu1.jpg", textureid[1]);
	    BuildTexture("tu2.jpg", textureid[2]);
	 
	 
	  
}


void Display(void)
{

	
    glClearColor(1,1,1,1);
//	glClear(GL_COLOR_BUFFER_BIT);
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

 
//	gluLookAt(0,-10,350,0,0,0,0,1,0);

    gluLookAt(eyex,eyey,eyez,atx,aty,atz,0,1,0);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);

	drawwall();	
	drawground();

	drawsphere();
	

	glutSwapBuffers();
//	glFlush();
}


void drawsphere()
{
 
	float tr;
	GLUquadricObj *qobj;
   

	
	tr=(outer+3*inner);

	
    // glDisable(GL_TEXTURE_2D);

	

  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);

	/*GLfloat planes[]={0.5,0.0,0.0,0.5};
	GLfloat planet[]={0.0,0.5,0.0,0.5};*/

	GLfloat planes[]={1,0.5,0.5,0.5};
	GLfloat planet[]={2,0.5,3,0.5};

glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
glTexGenfv(GL_S,GL_OBJECT_LINEAR,planes);
glTexGenfv(GL_T,GL_OBJECT_LINEAR,planet);
glBindTexture(GL_TEXTURE_2D, textureid[0]);

   
	glRotatef(theta,0,1,0);
  
	glPushMatrix();
		glPushMatrix();
		  	glColor3f(1.0,0,0.0);
	      glutSolidTorus(inner,outer,50,80); 
		glPopMatrix();

	 
		glPushMatrix();		 
			glTranslatef(outer,0,0);
			glRotatef(theta,0,1,0);
			glTranslatef(-outer,0,0);
	     
		  glEnable(GL_TEXTURE_2D);
		  glDisable(GL_TEXTURE_GEN_S);
          glDisable(GL_TEXTURE_GEN_T);
		  glBindTexture(GL_TEXTURE_2D, textureid[1]);
			glPushMatrix();		      
				glTranslatef(tr,0,0);
				glRotatef(-45,1,0,0);
					glColor3f(0.0,1.0,0.3);
					qobj=gluNewQuadric();
			//	glutSolidSphere(inner,40,40);
					gluQuadricNormals(qobj, GLU_SMOOTH);	
                   gluQuadricTexture(qobj, GL_TRUE);	
					gluSphere(qobj,inner,40,60);
			glPopMatrix();
		glPopMatrix();
      glPopMatrix();

}

void drawground()
{
  
  int colorflag=1;  
  
   glEnable(GL_TEXTURE_2D);
 glBindTexture(GL_TEXTURE_2D, textureid[0]);
  glNormal3f(0,1,0);
   for (int i=-outer-4*inner;i<outer+4*inner;i+=2*inner) 
   {
	   /*
      if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);
          */
				colorflag=-colorflag;  
				
             glColor3f(1.0,1.0,1.0);
  
	   for (int j=-outer-4*inner;j<outer+4*inner;j+=2*inner) 
   {
		   if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;  
	   glBegin(GL_QUADS);
	   //   glTexCoord2f(0.0f, 0.0f); 
	    glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 	 
	   glVertex3d(j,-outer-4*inner,i); 
		 // glTexCoord2f(1.0f, 0.0f);
	    glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
		  glVertex3d(j,-outer-4*inner,i+2*inner);
		 // glTexCoord2f(1.0f, 1.0f);
		  glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
          glVertex3d(j+2*inner,-outer-4*inner,i+2*inner);
		 // glTexCoord2f(0.0f, 1.0f);
		  glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3d(j+2*inner,-outer-4*inner,i);    		
       glEnd();
   }
  }


   glNormal3f(0,-1,0);
    colorflag=1;

 for (int i=-outer-4*inner;i<outer+4*inner;i+=2*inner) 
 {
	  if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;

	   for (int j=-outer-4*inner;j<outer+4*inner;j+=2*inner) 
   {
		   if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;  
	   glBegin(GL_QUADS);
	     //  glTexCoord2f(0.0f, 0.0f); 
	        glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3d(j,outer+4*inner,i);
		   //  glTexCoord2f(0.0f, 1.0f); 
		      glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
		  glVertex3d(j,outer+4*inner,i+2*inner);
		     //  glTexCoord2f(1.0f, 1.0f); 
		       glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
          glVertex3d(j+2*inner,outer+4*inner,i+2*inner);
		     // glTexCoord2f(1.0f, 0.0f); 
		       glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3d(j+2*inner,outer+4*inner,i);    		
       glEnd();
   }
 }


}


void drawwall()
{
  int i,j;

 glNormal3f(1,0,0);

  int colorflag=1;
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, textureid[0]);
  
   //left
     for (i=-outer-4*inner;i<outer+4*inner;i+=2*inner) 
	 {
		
		 if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;

	   for (j=-outer-4*inner;j<outer+4*inner;j+=2*inner) 
   {
		   
		   if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;  

		   
	   glBegin(GL_QUADS);
	       // glTexCoord2f(0.0f, 0.0f); 
	         glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3d(-outer-4*inner,j,i); 
		    // glTexCoord2f(1.0f, 0.0f); 
		      glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3d(-outer-4*inner,j+2*inner,i);
		     // glTexCoord2f(1.0f, 1.0f); 
		       glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
          glVertex3d(-outer-4*inner,j+2*inner,i+2*inner);
		     //glTexCoord2f(0.0f, 1.0f); 
		       glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
		  glVertex3d(-outer-4*inner,j,i+2*inner); 		  
       glEnd();
   }
	 }

  
    colorflag=1;

	glNormal3f(0,-1,0);
   
   //right
     for (i=-outer-4*inner;i<=outer+4*inner-2*inner;i+=2*inner)   //for z
	 {
		  if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;

	   for (j=-outer-4*inner;j<=outer+4*inner-2*inner;j+=2*inner)   //for y
   {
	   if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;  

	   glBegin(GL_QUADS);
	       // glTexCoord2f(0.0f, 0.0f); 
	        glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3f(outer+4*inner,j,i);           
		   // glTexCoord2f(1.0f, 0.0f); 
		     glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3f(outer+4*inner,j+2*inner,i);
		   // glTexCoord2f(1.0f, 1.0f); 
		       glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
          glVertex3f(outer+4*inner,j+2*inner,i+2*inner);
		    //  glTexCoord2f(0.0f, 1.0f); 
		        glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
		  glVertex3f(outer+4*inner,j,i+2*inner);    		
       glEnd();
    
   }
	 	 }

	 colorflag=1;

	 glNormal3f(0,0,1);
	   	
  //front
	  glBindTexture(GL_TEXTURE_2D, textureid[2]);
	  glColor3f(1.0,1.0,0.0);
     for (i=-outer-4*inner;i<=outer+4*inner-2*inner;i+=2*inner)   //for z
	 {
		 /* 
		 if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;
				*/

		 for (j=-outer-4*inner;j<=outer+4*inner-2*inner;j+=2*inner)   //for y
   {
			 /*
	   if (colorflag>0)    glColor3f(1.0,1.0,0.0);
				else         glColor3f(1.0,1.0,1.0);

				colorflag=-colorflag;  
				*/

	   glBegin(GL_QUADS);
	       // glTexCoord2f(0.0f, 0.0f); 
	        glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3f(j,i,-outer-4*inner);           
		  //glTexCoord2f(1.0f, 0.0f); 
		      glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i)/(2*outer+8*inner)); 
		  glVertex3f(j+2*inner,i,-outer-4*inner);
		     //glTexCoord2f(1.0f, 1.0f); 
		       glTexCoord2f((float)(outer+4*inner+j+2*inner)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
          glVertex3f(j+2*inner,i+2*inner,-outer-4*inner);
		     //  glTexCoord2f(0.0f, 1.0f); 
		        glTexCoord2f((float)(outer+4*inner+j)/(2*outer+8*inner), (float)(outer+4*inner+i+2*inner)/(2*outer+8*inner)); 
		  glVertex3f(j,i+2*inner,-outer-4*inner);    		
       glEnd();
    
   }
	 }
   

}



void myidle()
{

	theta+=0.5;
//	if (theta>=360.0) theta-=360.0;    
	glutPostRedisplay();
}

void Reshape(GLsizei w,GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	 glOrtho(-outer-6*inner,outer+6*inner,-outer-4*inner,outer+4*inner,20,2*outer+8*inner+50);
	 gluPerspective(90,w/h,10,2*outer+8*inner+250);
	glViewport(0,0,w,h);
	glMatrixMode(GL_MODELVIEW);

    

}

void mykeyboard(unsigned char key, int x, int y)
{

   switch(key)
	   {  
 case 'W':
 case 'w':// 向前走

	 eyex1=eyex-s*sin(sightangle*2*PI/360-PI/2);
	 eyez1=eyez-s*cos(sightangle*2*PI/360-PI/2);

     atx1=atx-s*sin(sightangle*2*PI/360-PI/2);
	 atz1=atz-s*cos(sightangle*2*PI/360-PI/2);

	 eyex=eyex1;
	 eyez=eyez1;

	 atz=atz1;
	 atx=atx1;
                    
	                         break;
case 'S':
case 's'://向后走
     eyex1=eyex+s*sin(sightangle*2*PI/360-PI/2);
	 eyez1=eyez+s*cos(sightangle*2*PI/360-PI/2);

     atx1=atx+s*sin(sightangle*2*PI/360-PI/2);
	 atz1=atz+s*cos(sightangle*2*PI/360-PI/2);

	 eyex=eyex1;
	 eyez=eyez1;

	 atz=atz1;
	 atx=atx1;             
		                      break;
case 'A':
case 'a'://左转
    /* atx1=eyex+(atx-eyex)*cos(angle*2*PI/360.0)+(eyez-atz)*sin(angle*2*PI/360.0);
     atz1=eyez-(eyez-atz)*sin(angle*2*PI/360.0)+(atx-eyex)*cos(angle*2*PI/360.0);*/
     
	 atx1=eyex+(atx-eyex)*cos(angle*2*PI/360.0)+(eyez-atz)*sin(angle*2*PI/360.0);
     atz1=eyez-(eyez-atz)*cos(angle*2*PI/360.0)-(-atx+eyex)*sin(angle*2*PI/360.0);
	 
	 atx=atx1;
	 atz=atz1;

	 sightangle=sightangle+angle;

		                      break;
case 'D':
case 'd'://右转
   /*atx1=eyex+(atx-eyex)*cos(-angle*2*PI/360.0)+(eyez-atz)*sin(-angle*2*PI/360.0);
     atz1=eyez-(eyez-atz)*sin(-angle*2*PI/360.0)+(atx-eyex)*cos(-angle*2*PI/360.0);*/

	atx1=eyex+(atx-eyex)*cos(angle*2*PI/360.0)-(eyez-atz)*sin(angle*2*PI/360.0);
     atz1=eyez-(eyez-atz)*cos(angle*2*PI/360.0)+(-atx+eyex)*sin(angle*2*PI/360.0);

	 atx=atx1;
	 atz=atz1;

	  sightangle=sightangle-angle;

							 break;   
                 }
   //参数修改后调用重画函数，屏幕图形将发生改变
                 glutPostRedisplay();  


}
