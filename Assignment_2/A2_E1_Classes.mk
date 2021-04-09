##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=A2_E1_Classes
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/Jimmy/Documents/GitHub/CodeLite Workspaces"
ProjectPath            :="C:/Users/Jimmy/Documents/GitHub/CodeLite Workspaces/Assignment_2"
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jimmy
Date                   :=09/04/2021
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
ObjectsFileList        :="A2_E1_Classes.txt"
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
Objects0=$(IntermediateDirectory)/Rectangle.cpp$(ObjectSuffix) $(IntermediateDirectory)/TestRectangle.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Rectangle.cpp$(ObjectSuffix): Rectangle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Rectangle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Rectangle.cpp$(DependSuffix) -MM Rectangle.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Jimmy/Documents/GitHub/CodeLite Workspaces/Assignment_2/Rectangle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Rectangle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Rectangle.cpp$(PreprocessSuffix): Rectangle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Rectangle.cpp$(PreprocessSuffix) Rectangle.cpp

$(IntermediateDirectory)/TestRectangle.cpp$(ObjectSuffix): TestRectangle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TestRectangle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TestRectangle.cpp$(DependSuffix) -MM TestRectangle.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Jimmy/Documents/GitHub/CodeLite Workspaces/Assignment_2/TestRectangle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TestRectangle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TestRectangle.cpp$(PreprocessSuffix): TestRectangle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TestRectangle.cpp$(PreprocessSuffix) TestRectangle.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


