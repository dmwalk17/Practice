##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=c1020a23Lab3
ConfigurationName      :=Debug
WorkspacePath          :=E:/c1020a23Lab3
ProjectPath            :=E:/c1020a23Lab3/c1020a23Lab3
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=dwalker1
Date                   :=03/12/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="c1020a23Lab3.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
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
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/TimeDateStamp.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sensor.cpp$(ObjectSuffix) $(IntermediateDirectory)/Race.cpp$(ObjectSuffix) $(IntermediateDirectory)/Racer.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/TimeDateStamp.cpp$(ObjectSuffix): TimeDateStamp.cpp $(IntermediateDirectory)/TimeDateStamp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/c1020a23Lab3/c1020a23Lab3/TimeDateStamp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TimeDateStamp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TimeDateStamp.cpp$(DependSuffix): TimeDateStamp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TimeDateStamp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TimeDateStamp.cpp$(DependSuffix) -MM TimeDateStamp.cpp

$(IntermediateDirectory)/TimeDateStamp.cpp$(PreprocessSuffix): TimeDateStamp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TimeDateStamp.cpp$(PreprocessSuffix) TimeDateStamp.cpp

$(IntermediateDirectory)/Sensor.cpp$(ObjectSuffix): Sensor.cpp $(IntermediateDirectory)/Sensor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/c1020a23Lab3/c1020a23Lab3/Sensor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sensor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sensor.cpp$(DependSuffix): Sensor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sensor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sensor.cpp$(DependSuffix) -MM Sensor.cpp

$(IntermediateDirectory)/Sensor.cpp$(PreprocessSuffix): Sensor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sensor.cpp$(PreprocessSuffix) Sensor.cpp

$(IntermediateDirectory)/Race.cpp$(ObjectSuffix): Race.cpp $(IntermediateDirectory)/Race.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/c1020a23Lab3/c1020a23Lab3/Race.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Race.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Race.cpp$(DependSuffix): Race.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Race.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Race.cpp$(DependSuffix) -MM Race.cpp

$(IntermediateDirectory)/Race.cpp$(PreprocessSuffix): Race.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Race.cpp$(PreprocessSuffix) Race.cpp

$(IntermediateDirectory)/Racer.cpp$(ObjectSuffix): Racer.cpp $(IntermediateDirectory)/Racer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/c1020a23Lab3/c1020a23Lab3/Racer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Racer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Racer.cpp$(DependSuffix): Racer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Racer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Racer.cpp$(DependSuffix) -MM Racer.cpp

$(IntermediateDirectory)/Racer.cpp$(PreprocessSuffix): Racer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Racer.cpp$(PreprocessSuffix) Racer.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/c1020a23Lab3/c1020a23Lab3/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
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


