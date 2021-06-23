#include "SS3D.h"
#include "soil.h"

SequenceSprite3D::SequenceSprite3D()
{
}

void SequenceSprite3D::Init(const char *imageDir, const char *imageName, int startFrame, int EndFrame, int framePerSecond)
{
	mFrameGAP = 1.0f / (float)framePerSecond;
	char szBuffer[256];
	mFrameCount = EndFrame - startFrame + 1;
	mTextures = new GLuint[mFrameCount];
	glGenTextures(mFrameCount, mTextures);
	mCurrentFrame = 0;
	for (int i = startFrame; i <= EndFrame; ++i)
	{
		memset(szBuffer, 0, 256);
		strcpy(szBuffer, imageDir);
		strcat(szBuffer, imageName);
		if (i < 10)
		{
			char temp[32] = {0};
			sprintf(temp, "000%d", i);
			strcat(szBuffer, temp);
		}
		else if (i >= 10 && i < 100)
		{
			char temp[32] = {0};
			sprintf(temp, "00%d", i);
			strcat(szBuffer, temp);
		}
		else if (i >= 100 && i < 1000)
		{
			char temp[32] = {0};
			sprintf(temp, "0%d", i);
			strcat(szBuffer, temp);
		}
		else if (i >= 1000)
		{
			char temp[32] = {0};
			sprintf(temp, "%d", i);
			strcat(szBuffer, temp);
		}
		strcat(szBuffer, ".png");

		mTextures[i - startFrame] = SOIL_load_OGL_texture(szBuffer, 0, 0, SOIL_FLAG_INVERT_Y | SOIL_FLAG_POWER_OF_TWO);
		printf("load frame %s\n", szBuffer);
	}
}

void SequenceSprite3D::SetRect(float x, float y, float width, float height)
{
	float halfWidth = width / 2.0f;
	float halfHeight = height / 2.0f;
	mMesh[0].x = x - halfWidth;
	mMesh[0].y = y - halfHeight;

	mMesh[1].x = x + halfWidth;
	mMesh[1].y = y - halfHeight;

	mMesh[2].x = x + halfWidth;
	mMesh[2].y = y + halfHeight;

	mMesh[3].x = x - halfWidth;
	mMesh[3].y = y + halfHeight;
}

void SequenceSprite3D::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glTranslatef(mPos.x, mPos.y, mPos.z);
	glColor4ub(255, 255, 255, 255);
	glBindTexture(GL_TEXTURE_2D, mTextures[mCurrentFrame]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3fv(mMesh[0].v);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3fv(mMesh[1].v);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3fv(mMesh[2].v);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3fv(mMesh[3].v);
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
}

void SequenceSprite3D::Update(float deltaTime)
{
	mTime += deltaTime;
	if (mTime > mFrameGAP)
	{
		mCurrentFrame++;
		if (mCurrentFrame == mFrameCount)
		{
			mCurrentFrame = 0;
		}
		mTime = 0.0f;
	}
}