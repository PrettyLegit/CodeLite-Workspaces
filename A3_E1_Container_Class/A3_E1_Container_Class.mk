##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=A3_E1_Container_Class
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/Jimmy/OneDrive - Kennesaw State University/Documents/CodeLite Workspaces"
ProjectPath            :="C:/Users/Jimmy/OneDrive - Kennesaw State University/Documents/CodeLite Workspaces/A3_E1_Container_Class"
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
ObjectsFileList        :="A3_E1_Container_Class.txt"
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
Objects0=$(IntermediateDirectory)/bag_demo.cpp$(ObjectSuffix) $(IntermediateDirectory)/bag1.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/bag_demo.cpp$(ObjectSuffix): bag_demo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bag_demo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bag_demo.cpp$(DependSuffix) -MM bag_demo.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Jimmy/OneDrive - Kennesaw State University/Documents/CodeLite Workspaces/A3_E1_Container_Class/bag_demo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bag_demo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bag_demo.cpp$(PreprocessSuffix): bag_demo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bag_demo.cpp$(PreprocessSuffix) bag_demo.cpp

$(IntermediateDirectory)/bag1.cpp$(ObjectSuffix): bag1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bag1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bag1.cpp$(DependSuffix) -MM bag1.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Jimmy/OneDrive - Kennesaw State University/Documents/CodeLite Workspaces/A3_E1_Container_Class/bag1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bag1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bag1.cpp$(PreprocessSuffix): bag1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bag1.cpp$(PreprocessSuffix) bag1.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


