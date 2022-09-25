import sys
import os
import CppHeaderParser # pip install robotpy-cppheaderparser


######################################################################
# @ 검색할 경로에 있는 모든 파일경로를 반환.
######################################################################
def SearchFiles(searchPath : str):
	result = list()
	for (root, dirs, files) in os.walk(searchPath):
		if len(files) > 0:
			for file in files:
				result.append(os.path.abspath(f"{root}\\{file}"))
	return result


######################################################################
# @ 텍스트파일 저장.
######################################################################
def SaveTextFile(saveFileFullName : str, writelines : list):
	with open(saveFileFullName, "w", encoding = "utf8") as textFile:
		textFile.writelines(writelines)


class FieldInfo:
	Name : str
	Type : str
	Permission : str

class MethodInfo:
	Name : str
	ReturnType : str
	Parameters : list # FieldInfo
	Permission : str

class ClassInfo:
	Name : str
	Namespace : str
	Fields : dict # name, FieldInfo
	Methods : dict # name, MethodInfo
	Parents : dict # name, ClassInfo
	Children : dict # name, ClassInfo


def Print(header):
	for key in header.classes:
		classInfo = header.classes[key]

		className = classInfo["name"]
		inherits = classInfo["inherits"]

		if not inherits:
			print(f"class {className}")
		else:
			parentClassName = dict(inherits[0])["class"]
			print(f"class {className} : {parentClassName}")

		for fieldInfo in classInfo["properties"]["private"]:
			fieldName = fieldInfo["name"]
			fieldType = fieldInfo["type"]
			print(f"\tprivate {fieldType} {fieldName}")

		for fieldInfo in classInfo["properties"]["protected"]:
			fieldName = fieldInfo["name"]
			fieldType = fieldInfo["type"]
			print(f"\protected {fieldType} {fieldName}")

		for fieldInfo in classInfo["properties"]["public"]:
			fieldName = fieldInfo["name"]
			fieldType = fieldInfo["type"]
			print(f"\public {fieldType} {fieldName}")

		for methodInfo in classInfo["methods"]["private"]:
			methodName = methodInfo["name"]
			returnType = methodInfo["rtnType"]
			parameters = methodInfo["parameters"]
			print(f"\tprivate {returnType} {methodName}()")
			for parameter in parameters:
				paramName = parameter["name"]
				paramType = parameter["type"]
				print(f"{paramType} {paramName}")

		for methodInfo in classInfo["methods"]["protected"]:
			methodName = methodInfo["name"]
			returnType = methodInfo["rtnType"]
			parameters = methodInfo["parameters"]
			print(f"\tprotected {returnType} {methodName}()")
			for parameter in parameters:
				paramName = parameter["name"]
				paramType = parameter["type"]
				print(f"{paramType} {paramName}")

		for methodInfo in classInfo["methods"]["public"]:
			methodName = methodInfo["name"]
			returnType = methodInfo["rtnType"]
			parameters = methodInfo["parameters"]
			print(f"\tpublic {returnType} {methodName}()")
			for parameter in parameters:
				paramName = parameter["name"]
				paramType = parameter["type"]
				print(f"\t\t{paramType} {paramName}")


######################################################################
# @ 진입점.
######################################################################
def OnMain(arguments : list):

	for fileFullName in SearchFiles("../AcroEngine"):
		extension = os.path.splitext(fileFullName)[1].lower()
		if extension == ".h":
			try:
				headerInfo = CppHeaderParser.CppHeader(fileFullName)
				#Print(headerInfo)
			except UnicodeDecodeError:
				print(f"UnicodeDecodeError '{fileFullName}'")
			except:
				print(f"except '{fileFullName}'")

			

	## PDF파일에서 추출된 텍스트를 저장.
	#with open(textFileFullName, "w") as file:
	#	file.write(pdfText)
	#	file.close()

	exit(0)


######################################################################
# @ 진입점.
######################################################################
if __name__ == "__main__":
	OnMain(sys.argv)