#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <unordered_map>
#include "vertexData.h"
#include "fbxsdk.h"
#include "texture.h"

struct Mat
{
	int mType; //0 lambert 1 phong other : lambert
	char mDiffuseColorTexture[256];
	Texture* mTexture;
};

class FBXModel
{
protected:
	void ImportNode(FbxNode *node);
	void ImportMaterial(FbxNode *node);
	void ImportMesh(FbxMesh *mesh);

public:
	char mFBXPath[256];
	std::vector<Mat*> mMaterials; //unique mat
	std::vector<std::vector<int>> mIndices;
	std::unordered_map<int, int> mMaterialIndexes;
	VertexData* mVertices;
	void Init(const char* filePath);
	void Draw();
};