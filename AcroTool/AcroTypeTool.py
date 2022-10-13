#############################################################################
# @ 전방선언.
#############################################################################
import os
import sys


#############################################################################
# @ 라인 추가.
#############################################################################
def AppendLine(cppline : list, line : str, tab : int = 0):
	if tab > 0:
		indent = str()
		for i in range(tab):
			indent += "\t"
		cppline.append(f"{indent}{line}\n")
	else:
		cppline.append(f"{line}\n")


#############################################################################
# @ 클래스 메타데이터 생성.
#############################################################################
def GenerateReflectionCPP(cppname : str, namespaces : list(), classnames : list()):
	cppline = list()
	AppendLine(cppline, f"// Generated from AcroTypeTool ().")
	AppendLine(cppline, f"")

	# add include default files.
	AppendLine(cppline, f"#include \"AcroEngine.h\"")
	AppendLine(cppline, f"#include \"IAssembly.h\"")
	AppendLine(cppline, f"#include \"AType.h\"")
	AppendLine(cppline, f"#include \"TTypeDef.h\"")

	# add include classses files.
	for e in enumerate(classnames):
		index = e[0]
		classname = e[1]
		AppendLine(cppline, f"#include \"{classname}.h\"")
	
	#if len(namespaces) == 0:
	#	namespaces.append(f"")

	# load all types.
	indent = 0
	count = len(namespaces)
	for e in enumerate(namespaces):
		index = e[0]
		namespace = e[1]
		AppendLine(cppline, f"{namespace}", indent)
		AppendLine(cppline, f"{{", indent)
		if index + 1 == count:
			indent += 1
			AppendLine(cppline, f"class AcroEngineAssembly : public AcroEngine::IAssembly", indent)
			AppendLine(cppline, f"{{")
			AppendLine(cppline, f"public:")
			indent += 1
			AppendLine(cppline, f"virtual void Assemble() override", indent)
			AppendLine(cppline, f"{{", indent)
			indent += 1
			for classname in classnames:
				AppendLine(cppline, f"AcroEngine::LoadType(new TTypeDef<{classname}>());", indent)
			indent -= 1
			AppendLine(cppline, f"}}", indent)
			indent -= 1
			AppendLine(cppline, f"}};", indent)
			indent -= 1
		AppendLine(cppline, f"}}", indent)
		indent += 1
	

#############################################################################
# @ 메인함수.
#############################################################################
def OnMain(arguments : list):
	# 인자로 받은 경로 안의 모든 헤더파일을 전부 부른 뒤... 기록한다.
	# 그리고 기록된 데이터를 저장한다.
	GenerateReflectionCPP("AcroEngineGenerated.h", ["AcroEngine"], ["Object"])
	pass


#############################################################################
# @ 진입점.
#############################################################################
if __name__ == "main":
	OnMain(sys.argv)