##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Parking
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/kesan/OneDrive/Desktop/Documents/WorkCPP
ProjectPath            :=C:/Users/kesan/OneDrive/Desktop/Documents/WorkCPP/Parking
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=kesan
Date                   :=25/04/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="C:/Program Files/mingw-w64/mingw64/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files/mingw-w64/mingw64/bin/g++.exe" -shared -fPIC
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
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Parking.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="C:/Program Files/mingw-w64/mingw64/bin/windres.exe"
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := "C:/Program Files/mingw-w64/mingw64/bin/ar.exe" rcu
CXX      := "C:/Program Files/mingw-w64/mingw64/bin/g++.exe"
CC       := "C:/Program Files/mingw-w64/mingw64/bin/gcc.exe"
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files/mingw-w64/mingw64/bin/as.exe"


##
## User defined environment variables
##
Objects0=$(IntermediateDirectory)/Vehicle.cpp$(ObjectSuffix) $(IntermediateDirectory)/Parking_lot.cpp$(ObjectSuffix) $(IntermediateDirectory)/Automob.cpp$(ObjectSuffix) $(IntermediateDirectory)/Billing.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Vehicle.cpp$(ObjectSuffix): Vehicle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vehicle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Vehicle.cpp$(DependSuffix) -MM Vehicle.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/kesan/OneDrive/Desktop/Documents/WorkCPP/Parking/Vehicle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vehicle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vehicle.cpp$(PreprocessSuffix): Vehicle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vehicle.cpp$(PreprocessSuffix) Vehicle.cpp

$(IntermediateDirectory)/Parking_lot.cpp$(ObjectSuffix): Parking_lot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Parking_lot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Parking_lot.cpp$(DependSuffix) -MM Parking_lot.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/kesan/OneDrive/Desktop/Documents/WorkCPP/Parking/Parking_lot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Parking_lot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Parking_lot.cpp$(PreprocessSuffix): Parking_lot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Parking_lot.cpp$(PreprocessSuffix) Parking_lot.cpp

$(IntermediateDirectory)/Automob.cpp$(ObjectSuffix): Automob.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Automob.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Automob.cpp$(DependSuffix) -MM Automob.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/kesan/OneDrive/Desktop/Documents/WorkCPP/Parking/Automob.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Automob.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Automob.cpp$(PreprocessSuffix): Automob.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Automob.cpp$(PreprocessSuffix) Automob.cpp

$(IntermediateDirectory)/Billing.cpp$(ObjectSuffix): Billing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Billing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Billing.cpp$(DependSuffix) -MM Billing.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/kesan/OneDrive/Desktop/Documents/WorkCPP/Parking/Billing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Billing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Billing.cpp$(PreprocessSuffix): Billing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Billing.cpp$(PreprocessSuffix) Billing.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/kesan/OneDrive/Desktop/Documents/WorkCPP/Parking/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


