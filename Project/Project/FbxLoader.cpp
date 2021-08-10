#include "pch.h"
#include "FbxLoader.h"

FbxLoader::FbxLoader()
{
	m_pfbxManager = FbxManager::Create();

	m_pfbxIOSettings = FbxIOSettings::Create(m_pfbxManager, IOSROOT);
	m_pfbxManager->SetIOSettings(m_pfbxIOSettings);

	m_pfbxImporter = FbxImporter::Create(m_pfbxManager, "myImporter");
}

FbxLoader::~FbxLoader()
{
	m_pfbxManager->Destroy();
}

void FbxLoader::PrintTabs()
{
	for (int i = 0; i < m_nTabCnt; i++)
		cout << "  ";
}

void FbxLoader::Load(const char* pstrFileName)
{
	if (!m_pfbxImporter->Initialize(pstrFileName, -1, m_pfbxManager->GetIOSettings())) {
		cout << "FbxImporter::Initialize() failed\n";
		cout << "Error returned : " << m_pfbxImporter->GetStatus().GetErrorString() << endl;
		exit(-1);
	}

	FbxScene* pfbxScene = FbxScene::Create(m_pfbxManager, "myScene");
	m_pfbxImporter->Import(pfbxScene);

	FbxNode* pfbxRootNode = pfbxScene->GetRootNode();
	if (pfbxRootNode)
		LoadNodeHierarchy(pfbxRootNode);

	pfbxScene->Destroy();
}

void FbxLoader::LoadNodeHierarchy(FbxNode* pfbxNode)
{
	PrintTabs();
	cout << pfbxNode->GetName() << endl;
	++m_nTabCnt;

	for (int i = 0; i < pfbxNode->GetChildCount(); i++)
		LoadNodeHierarchy(pfbxNode->GetChild(i));

	--m_nTabCnt;
}