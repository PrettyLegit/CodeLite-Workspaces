##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=A3_E2_Container_Class
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/Jimmy/OneDrive - Kennesaw State University/Documents/CodeLite Workspaces"
ProjectPath            :="C:/Users/Jimmy/OneDrive - Kennesaw State University/Documents/CodeLite Workspaces/A3_E2_Container_Class"
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jimmy
Date                   :=06/03/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="A3_E2_Container_Class.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
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
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/sequence.cpp$(ObjectSuffix) $(IntermediateDirectory)/sequence_test.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/sequence.cpp$(ObjectSuffix): sequence.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sequence.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sequence.cpp$(DependSuffix) -MM sequence.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Jimmy/OneDrive - Kennesaw State University/Documents/CodeLite Workspaces/A3_E2_Container_Class/sequence.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sequence.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sequence.cpp$(PreprocessSuffix): sequence.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sequence.cpp$(PreprocessSuffix) sequence.cpp

$(IntermediateDirectory)/sequence_test.cpp$(ObjectSuffix): sequence_test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sequence_test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sequence_test.cpp$(DependSuffix) -MM sequence_test.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Jimmy/OneDrive - Kennesaw State University/Documents/CodeLite Workspaces/A3_E2_Container_Class/sequence_test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sequence_test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sequence_test.cpp$(PreprocessSuffix): sequence_test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sequence_test.cpp$(PreprocessSuffix) sequence_test.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


