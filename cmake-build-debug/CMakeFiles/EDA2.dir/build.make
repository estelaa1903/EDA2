# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\alexs\CLionProjects\EDA2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\alexs\CLionProjects\EDA2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EDA2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/EDA2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/EDA2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EDA2.dir/flags.make

CMakeFiles/EDA2.dir/main.c.obj: CMakeFiles/EDA2.dir/flags.make
CMakeFiles/EDA2.dir/main.c.obj: CMakeFiles/EDA2.dir/includes_C.rsp
CMakeFiles/EDA2.dir/main.c.obj: C:/Users/alexs/CLionProjects/EDA2/main.c
CMakeFiles/EDA2.dir/main.c.obj: CMakeFiles/EDA2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexs\CLionProjects\EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/EDA2.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/EDA2.dir/main.c.obj -MF CMakeFiles\EDA2.dir\main.c.obj.d -o CMakeFiles\EDA2.dir\main.c.obj -c C:\Users\alexs\CLionProjects\EDA2\main.c

CMakeFiles/EDA2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EDA2.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexs\CLionProjects\EDA2\main.c > CMakeFiles\EDA2.dir\main.c.i

CMakeFiles/EDA2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EDA2.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexs\CLionProjects\EDA2\main.c -o CMakeFiles\EDA2.dir\main.c.s

CMakeFiles/EDA2.dir/users.c.obj: CMakeFiles/EDA2.dir/flags.make
CMakeFiles/EDA2.dir/users.c.obj: CMakeFiles/EDA2.dir/includes_C.rsp
CMakeFiles/EDA2.dir/users.c.obj: C:/Users/alexs/CLionProjects/EDA2/users.c
CMakeFiles/EDA2.dir/users.c.obj: CMakeFiles/EDA2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexs\CLionProjects\EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/EDA2.dir/users.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/EDA2.dir/users.c.obj -MF CMakeFiles\EDA2.dir\users.c.obj.d -o CMakeFiles\EDA2.dir\users.c.obj -c C:\Users\alexs\CLionProjects\EDA2\users.c

CMakeFiles/EDA2.dir/users.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EDA2.dir/users.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexs\CLionProjects\EDA2\users.c > CMakeFiles\EDA2.dir\users.c.i

CMakeFiles/EDA2.dir/users.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EDA2.dir/users.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexs\CLionProjects\EDA2\users.c -o CMakeFiles\EDA2.dir\users.c.s

CMakeFiles/EDA2.dir/menu.c.obj: CMakeFiles/EDA2.dir/flags.make
CMakeFiles/EDA2.dir/menu.c.obj: CMakeFiles/EDA2.dir/includes_C.rsp
CMakeFiles/EDA2.dir/menu.c.obj: C:/Users/alexs/CLionProjects/EDA2/menu.c
CMakeFiles/EDA2.dir/menu.c.obj: CMakeFiles/EDA2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexs\CLionProjects\EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/EDA2.dir/menu.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/EDA2.dir/menu.c.obj -MF CMakeFiles\EDA2.dir\menu.c.obj.d -o CMakeFiles\EDA2.dir\menu.c.obj -c C:\Users\alexs\CLionProjects\EDA2\menu.c

CMakeFiles/EDA2.dir/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EDA2.dir/menu.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexs\CLionProjects\EDA2\menu.c > CMakeFiles\EDA2.dir\menu.c.i

CMakeFiles/EDA2.dir/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EDA2.dir/menu.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexs\CLionProjects\EDA2\menu.c -o CMakeFiles\EDA2.dir\menu.c.s

# Object files for target EDA2
EDA2_OBJECTS = \
"CMakeFiles/EDA2.dir/main.c.obj" \
"CMakeFiles/EDA2.dir/users.c.obj" \
"CMakeFiles/EDA2.dir/menu.c.obj"

# External object files for target EDA2
EDA2_EXTERNAL_OBJECTS =

EDA2.exe: CMakeFiles/EDA2.dir/main.c.obj
EDA2.exe: CMakeFiles/EDA2.dir/users.c.obj
EDA2.exe: CMakeFiles/EDA2.dir/menu.c.obj
EDA2.exe: CMakeFiles/EDA2.dir/build.make
EDA2.exe: CMakeFiles/EDA2.dir/linklibs.rsp
EDA2.exe: CMakeFiles/EDA2.dir/objects1.rsp
EDA2.exe: CMakeFiles/EDA2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\alexs\CLionProjects\EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable EDA2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EDA2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EDA2.dir/build: EDA2.exe
.PHONY : CMakeFiles/EDA2.dir/build

CMakeFiles/EDA2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EDA2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EDA2.dir/clean

CMakeFiles/EDA2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\alexs\CLionProjects\EDA2 C:\Users\alexs\CLionProjects\EDA2 C:\Users\alexs\CLionProjects\EDA2\cmake-build-debug C:\Users\alexs\CLionProjects\EDA2\cmake-build-debug C:\Users\alexs\CLionProjects\EDA2\cmake-build-debug\CMakeFiles\EDA2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EDA2.dir/depend

