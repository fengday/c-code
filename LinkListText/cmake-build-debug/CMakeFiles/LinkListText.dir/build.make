# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\installation-package\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\installation-package\CLion\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\installation-package\c\code\11\LinkListText

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\installation-package\c\code\11\LinkListText\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LinkListText.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkListText.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkListText.dir/flags.make

CMakeFiles/LinkListText.dir/main.cpp.obj: CMakeFiles/LinkListText.dir/flags.make
CMakeFiles/LinkListText.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\installation-package\c\code\11\LinkListText\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkListText.dir/main.cpp.obj"
	D:\installation-package\CLion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LinkListText.dir\main.cpp.obj -c D:\installation-package\c\code\11\LinkListText\main.cpp

CMakeFiles/LinkListText.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkListText.dir/main.cpp.i"
	D:\installation-package\CLion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\installation-package\c\code\11\LinkListText\main.cpp > CMakeFiles\LinkListText.dir\main.cpp.i

CMakeFiles/LinkListText.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkListText.dir/main.cpp.s"
	D:\installation-package\CLion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\installation-package\c\code\11\LinkListText\main.cpp -o CMakeFiles\LinkListText.dir\main.cpp.s

# Object files for target LinkListText
LinkListText_OBJECTS = \
"CMakeFiles/LinkListText.dir/main.cpp.obj"

# External object files for target LinkListText
LinkListText_EXTERNAL_OBJECTS =

LinkListText.exe: CMakeFiles/LinkListText.dir/main.cpp.obj
LinkListText.exe: CMakeFiles/LinkListText.dir/build.make
LinkListText.exe: CMakeFiles/LinkListText.dir/linklibs.rsp
LinkListText.exe: CMakeFiles/LinkListText.dir/objects1.rsp
LinkListText.exe: CMakeFiles/LinkListText.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\installation-package\c\code\11\LinkListText\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LinkListText.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LinkListText.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkListText.dir/build: LinkListText.exe

.PHONY : CMakeFiles/LinkListText.dir/build

CMakeFiles/LinkListText.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LinkListText.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LinkListText.dir/clean

CMakeFiles/LinkListText.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\installation-package\c\code\11\LinkListText D:\installation-package\c\code\11\LinkListText D:\installation-package\c\code\11\LinkListText\cmake-build-debug D:\installation-package\c\code\11\LinkListText\cmake-build-debug D:\installation-package\c\code\11\LinkListText\cmake-build-debug\CMakeFiles\LinkListText.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkListText.dir/depend

