##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=buildBinaryFile
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Donna/Documents/AssignmentLabsCPlusPlus/c1020a23Lab4
ProjectPath            :=C:/Users/Donna/Documents/AssignmentLabsCPlusPlus/c1020a23Lab4/buildBinaryFile
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Donna
Date                   :=20/11/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW-64/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="buildBinaryFile.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-64/bin/ar.exe rcu
CXX      := C:/MinGW-64/bin/g++.exe
CC       := C:/MinGW-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/activity.cpp$(ObjectSuffix) $(IntermediateDirectory)/participant.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/activity.cpp$(ObjectSuffix): activity.cpp $(IntermediateDirectory)/activity.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Donna/Documents/AssignmentLabsCPlusPlus/c1020a23Lab4/buildBinaryFile/activity.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/activity.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/activity.cpp$(DependSuffix): activity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/activity.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/activity.cpp$(DependSuffix) -MM activity.cpp

$(IntermediateDirectory)/activity.cpp$(PreprocessSuffix): activity.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/activity.cpp$(PreprocessSuffix) activity.cpp

$(IntermediateDirectory)/participant.cpp$(ObjectSuffix): participant.cpp $(IntermediateDirectory)/participant.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Donna/Documents/AssignmentLabsCPlusPlus/c1020a23Lab4/buildBinaryFile/participant.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/participant.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/participant.cpp$(DependSuffix): participant.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/participant.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/participant.cpp$(DependSuffix) -MM participant.cpp

$(IntermediateDirectory)/participant.cpp$(PreprocessSuffix): participant.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/participant.cpp$(PreprocessSuffix) participant.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Donna/Documents/AssignmentLabsCPlusPlus/c1020a23Lab4/buildBinaryFile/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


