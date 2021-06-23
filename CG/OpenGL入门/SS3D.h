#pragma once
#include <windows.h>
#include <gl/GL.h>
#include "List.h"
#include "texture.h"
#include "vector3f.h"

class SequenceSprite3D : public RenderableObject
{
public:
	float mFrameGAP;
	float mTime;
	int mFrameCount;
	int mCurrentFrame;
	GLuint *mTextures;
	SequenceSprite3D();
	Vector3f mMesh[4];
	Vector3f mPos;
	void Init(const char *imageDir, const char *imageName, int startFrame, int EndFrame, int framePerSecond);
	void SetRect(float x, float y, float width, float height);
	void Update(float deltaTime);
	virtual void Draw();
};