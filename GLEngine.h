/****************************************************************************
**
** GLEngine.h
**
** Copyright (C) September 2015 Hotride
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
*****************************************************************************
*/
//---------------------------------------------------------------------------
#ifndef GLEngineH
#define GLEngineH
//---------------------------------------------------------------------------
class TVector;
//---------------------------------------------------------------------------
//����� �� ������ � ��������� OpenGL
class TGLEngine : public IGLEngine
{
private:
	//�������� ����������
	HDC m_DC;

	//�������� OpenGL
	HGLRC m_RC;

	//��������� ������� ������
	bool GLSetupPixelFormat();

	//������ ��������� �������������� ��������
	GLuint m_OldTexture;

public:
	TGLEngine() {m_DC = NULL; m_RC = NULL;}
	~TGLEngine() {}
	
	HDC GetDC() const {return m_DC;}
	HGLRC GetRC() const {return m_RC;}

	SETGET(GLuint, OldTexture);

	//������������� OpenGL
	bool Install(HWND hWnd);

	//���������� ������ � OpenGL
	void Uninstall() {wglMakeCurrent(NULL, NULL); wglDeleteContext(m_RC);}

	//���������� ������� ������
	void UpdateRect();

	//�������� ������� 16 � 32 ���
	void BindTexture16(GLuint &texture, int width, int height, PWORD pixels);
	void BindTexture32(GLuint &texture, int width, int height, PDWORD pixels);

	//�������� ����� � ������ ���������
	void BeginDraw();

	//��������� ��������� � ������� ��� ������������ �� �����
	void EndDraw();

	//�������� ����� ���������
	void BeginStencil();

	//��������� ����� ���������
	void EndStencil();

	//������� ������� ���������
	void ViewPort(int x, int y, int width, int height);

	//������������ ����������� ������� ���������
	void RestorePort();

	//������� ������� ��������� (���������, ��������� �������)
	void Scissor(int x, int y, int width, int height);



	//���������� �����
	void DrawLine(int x, int y, int targetX, int targetY);

	//���������� �������������
	void DrawPolygone(int x, int y, int width, int height);

	//���������� ����
	void DrawCircle(float x, float y, float radius, int gradientMode = 0);



	//���������� �������� ���������
	void DrawLandTexture(GLuint &texture, int &x, int &y, RECT &rc, TVector *normals);

	//���������� ��������
	void Draw(GLuint &texture, int &x, int &y, int width, int height);

	//���������� ���������� ��������
	void DrawRotated(GLuint &texture, int &x, int &y, int width, int height, float &angle);

	//���������� �������� � ������������ ����������� ���������
	void Draw(GLuint &texture, int &x, int &y, int width, int height, bool &mirror);

	//���������� �������� �������� ���������
	void DrawSitting(GLuint &texture, int &x, int &y, int width, int height, bool &mirror);

	//���������� ����
	void DrawShadow(GLuint &texture, int &x, int &y, int width, int height, bool &mirror);

	//��������� �������� �� �������� ��������
	void Draw(GLuint &texture, int &x, int &y, int width, int height, int &drawWidth, int &drawHeight);

	//���������� ���
	void DrawResizepic(TTextureObject **th, int &x, int &y, int &width, int &height);
};
//---------------------------------------------------------------------------
extern TGLEngine g_GL;
//---------------------------------------------------------------------------
#endif