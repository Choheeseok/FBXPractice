#include "pch.h"

int main()
{
	for (auto& p : directory_iterator("Fbx files/Models/")) {
		string extension;
		if (p.path().has_extension())
			extension = p.path().extension().string();

		if (extension == ".fbx" ||
			extension == ".FBX") {
		}
	}

	FbxManager* a{};
	a->Create();
}