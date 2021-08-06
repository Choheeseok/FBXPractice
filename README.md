# FBXPractice

Visual Studio 2019 / Debug / x64
FBX SDK 2020.2.1 VS2019

1)
C/C++ - 일반 - FBX설치경로/include
(C:\Program Files\Autodesk\FBX\FBX SDK\2020.2.1\include)

2)
C/C++ - 코드 생성 - 런타임 라이브러리 - 다중 스레드 디버그 DLL(/MDd)

3)
링커 - 일반 - 추가 라이브러리 디렉터리 - FBX설치경로/lib/vs2019/x64/debug
(C:\Program Files\Autodesk\FBX\FBX SDK\2020.2.1\lib\vs2013\x64\debug)

4)
링커 - 입력 - 추가 종속성 - libfbxsdk-md.lib

5)
링커 - 입력 - 특정 기본 라이브러리 무시 - LIBMCT