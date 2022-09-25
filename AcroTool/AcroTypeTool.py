#############################################################################
# @ 전방선언.
#############################################################################
import os
import sys


#############################################################################
# @ 헤더 클래스.
#############################################################################
class TypeClass:
	def __init__(self) -> None:
		pass


class VariableInfo:
	_Name : str
	_Type : str

class FunctionInfo:
	_Name : str
	_ReturnTypeNam : str # _Type
	_ParamterTypes : list # VariableInfo

class ClassInfo:
	_Name: str
	_Namespace: str
	_Parents : list # ClassInfo._Name
	_Childs : list # ClassInfo._Name
	_VariableInfos : VariableInfo
	_FunctionInfos : FunctionInfo

class EnumInfo:
	_Name : str


def Block(codeBlock : str):
	pass

def Parse(code : str):
	pass

#############################################################################
# @ 메인함수.
#############################################################################
def OnMain(arguments : list):
	# 인자로 받은 경로 안의 모든 헤더파일을 전부 부른 뒤... 기록한다.
	# 그리고 기록된 데이터를 저장한다.
	# 
	pass


#############################################################################
# @ 진입점.
#############################################################################
if __name__ == "main":
	OnMain(sys.argv)