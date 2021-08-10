#pragma once
#include "pch.h"

class FbxLoader
{
private:
	FbxManager* m_pfbxManager{};
	FbxIOSettings* m_pfbxIOSettings{};
	FbxImporter* m_pfbxImporter{};
	FbxScene* m_pfbxScene{};

	unsigned int m_nTabCnt{};

private:
	void PrintTabs();
public:
	FbxLoader();
	~FbxLoader();

	void Load(const char* pstrFileName);
	void LoadNodeHierarchy(FbxNode* pfbxNode);
};
