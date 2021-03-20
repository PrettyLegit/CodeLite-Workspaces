##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=A5_E1_Linked_Lists
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/Jimmy/Documents/GitHub/CodeLite Workspaces"
ProjectPath            :="C:/Users/Jimmy/Documents/GitHub/CodeLite Workspaces/A5_Linked_Lists"
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jimmy
Date                   :=20/03/2021
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
ObjectsFileList        :="A5_E1_Linked_Lists.txt"
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
Objects0=$(IntermediateDirectory)/node1.cpp$(ObjectSuffix) $(IntermediateDirectory)/node1_test.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/node1.cpp$(ObjectSuffix): node1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/node1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/node1.cpp$(DependSuffix) -MM node1.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Jimmy/Documents/GitHub/CodeLite Workspaces/A5_Linked_Lists/node1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/node1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/node1.cpp$(PreprocessSuffix): node1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/node1.cpp$(PreprocessSuffix) node1.cpp

$(IntermediateDirectory)/node1_test.cpp$(ObjectSuffix): node1_test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/node1_test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/node1_test.cpp$(DependSuffix) -MM node1_test.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Jimmy/Documents/GitHub/CodeLite Workspaces/A5_Linked_Lists/node1_test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/node1_test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/node1_test.cpp$(PreprocessSuffix): node1_test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/node1_test.cpp$(PreprocessSuffix) node1_test.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


