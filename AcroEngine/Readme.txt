
# 지원툴셋:
 - AcroBuildTool:
 - AcroTypeTool:
 - AcroAssetTool:

 - AcroEditor:
 
# 구조:
AcroCore
	AcroEngine
		AcroEngineData
		EngineScripting (파이썬)

# 컴파일 및 배포:
 - Windows : VISUALSTUDIO
 - Android : CMAKE + NDK ==> ANDROIDSTUDIO
 - iOS : CMAKE ==> XCODE

# 변수스타일:
- immutable
	- 기존 C++ 스타일로 AcroCore 안에 정의된 변수를 사용.
- AObject
	- 모두 시리얼라이즈 되며, 레퍼런스카운트를 가지고, 리플렉션을 사용할 수 있음.
	- 생성과 소멸 (Instantiate ==> Destroy) 과정 필요.
	- AcroTypeTool 을 통해 코드생성 작업을 필요로 함.
	- 무겁지만 유용함.
