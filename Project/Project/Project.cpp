#include "pch.h"
#include "FbxLoader.h"

int main()
{
	FbxLoader a;

	for (auto& p : directory_iterator("Fbx files/Models/")) {
		string extension;
		if (p.path().has_extension())
			extension = p.path().extension().string();

		if (extension == ".fbx" ||
			extension == ".FBX") {
			a.Load(p.path().string().c_str());
			cout << endl << endl;
		}
	}
}