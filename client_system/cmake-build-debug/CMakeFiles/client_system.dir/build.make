# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\CommuteSoftWare\client_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\CommuteSoftWare\client_system\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/client_system.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client_system.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client_system.dir/flags.make

CMakeFiles/client_system.dir/main.cpp.obj: CMakeFiles/client_system.dir/flags.make
CMakeFiles/client_system.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\CommuteSoftWare\client_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client_system.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\client_system.dir\main.cpp.obj -c D:\code\CommuteSoftWare\client_system\main.cpp

CMakeFiles/client_system.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_system.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\CommuteSoftWare\client_system\main.cpp > CMakeFiles\client_system.dir\main.cpp.i

CMakeFiles/client_system.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_system.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\CommuteSoftWare\client_system\main.cpp -o CMakeFiles\client_system.dir\main.cpp.s

# Object files for target client_system
client_system_OBJECTS = \
"CMakeFiles/client_system.dir/main.cpp.obj"

# External object files for target client_system
client_system_EXTERNAL_OBJECTS =

client_system.exe: CMakeFiles/client_system.dir/main.cpp.obj
client_system.exe: CMakeFiles/client_system.dir/build.make
client_system.exe: CMakeFiles/client_system.dir/linklibs.rsp
client_system.exe: CMakeFiles/client_system.dir/objects1.rsp
client_system.exe: CMakeFiles/client_system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\code\CommuteSoftWare\client_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable client_system.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\client_system.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client_system.dir/build: client_system.exe

.PHONY : CMakeFiles/client_system.dir/build

CMakeFiles/client_system.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\client_system.dir\cmake_clean.cmake
.PHONY : CMakeFiles/client_system.dir/clean

CMakeFiles/client_system.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\CommuteSoftWare\client_system D:\code\CommuteSoftWare\client_system D:\code\CommuteSoftWare\client_system\cmake-build-debug D:\code\CommuteSoftWare\client_system\cmake-build-debug D:\code\CommuteSoftWare\client_system\cmake-build-debug\CMakeFiles\client_system.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client_system.dir/depend

