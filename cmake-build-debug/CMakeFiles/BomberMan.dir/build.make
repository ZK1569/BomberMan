# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\CNM-CUR\CLionProjects\BomberMan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BomberMan.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BomberMan.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BomberMan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BomberMan.dir/flags.make

CMakeFiles/BomberMan.dir/Code/main.c.obj: CMakeFiles/BomberMan.dir/flags.make
CMakeFiles/BomberMan.dir/Code/main.c.obj: ../Code/main.c
CMakeFiles/BomberMan.dir/Code/main.c.obj: CMakeFiles/BomberMan.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BomberMan.dir/Code/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BomberMan.dir/Code/main.c.obj -MF CMakeFiles\BomberMan.dir\Code\main.c.obj.d -o CMakeFiles\BomberMan.dir\Code\main.c.obj -c C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\main.c

CMakeFiles/BomberMan.dir/Code/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BomberMan.dir/Code/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\main.c > CMakeFiles\BomberMan.dir\Code\main.c.i

CMakeFiles/BomberMan.dir/Code/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BomberMan.dir/Code/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\main.c -o CMakeFiles\BomberMan.dir\Code\main.c.s

CMakeFiles/BomberMan.dir/Code/Func/map.c.obj: CMakeFiles/BomberMan.dir/flags.make
CMakeFiles/BomberMan.dir/Code/Func/map.c.obj: ../Code/Func/map.c
CMakeFiles/BomberMan.dir/Code/Func/map.c.obj: CMakeFiles/BomberMan.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BomberMan.dir/Code/Func/map.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BomberMan.dir/Code/Func/map.c.obj -MF CMakeFiles\BomberMan.dir\Code\Func\map.c.obj.d -o CMakeFiles\BomberMan.dir\Code\Func\map.c.obj -c C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\map.c

CMakeFiles/BomberMan.dir/Code/Func/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BomberMan.dir/Code/Func/map.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\map.c > CMakeFiles\BomberMan.dir\Code\Func\map.c.i

CMakeFiles/BomberMan.dir/Code/Func/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BomberMan.dir/Code/Func/map.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\map.c -o CMakeFiles\BomberMan.dir\Code\Func\map.c.s

CMakeFiles/BomberMan.dir/Code/Func/show.c.obj: CMakeFiles/BomberMan.dir/flags.make
CMakeFiles/BomberMan.dir/Code/Func/show.c.obj: ../Code/Func/show.c
CMakeFiles/BomberMan.dir/Code/Func/show.c.obj: CMakeFiles/BomberMan.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/BomberMan.dir/Code/Func/show.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BomberMan.dir/Code/Func/show.c.obj -MF CMakeFiles\BomberMan.dir\Code\Func\show.c.obj.d -o CMakeFiles\BomberMan.dir\Code\Func\show.c.obj -c C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\show.c

CMakeFiles/BomberMan.dir/Code/Func/show.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BomberMan.dir/Code/Func/show.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\show.c > CMakeFiles\BomberMan.dir\Code\Func\show.c.i

CMakeFiles/BomberMan.dir/Code/Func/show.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BomberMan.dir/Code/Func/show.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\show.c -o CMakeFiles\BomberMan.dir\Code\Func\show.c.s

CMakeFiles/BomberMan.dir/Code/Func/player.c.obj: CMakeFiles/BomberMan.dir/flags.make
CMakeFiles/BomberMan.dir/Code/Func/player.c.obj: ../Code/Func/player.c
CMakeFiles/BomberMan.dir/Code/Func/player.c.obj: CMakeFiles/BomberMan.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/BomberMan.dir/Code/Func/player.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BomberMan.dir/Code/Func/player.c.obj -MF CMakeFiles\BomberMan.dir\Code\Func\player.c.obj.d -o CMakeFiles\BomberMan.dir\Code\Func\player.c.obj -c C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\player.c

CMakeFiles/BomberMan.dir/Code/Func/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BomberMan.dir/Code/Func/player.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\player.c > CMakeFiles\BomberMan.dir\Code\Func\player.c.i

CMakeFiles/BomberMan.dir/Code/Func/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BomberMan.dir/Code/Func/player.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\CNM-CUR\CLionProjects\BomberMan\Code\Func\player.c -o CMakeFiles\BomberMan.dir\Code\Func\player.c.s

# Object files for target BomberMan
BomberMan_OBJECTS = \
"CMakeFiles/BomberMan.dir/Code/main.c.obj" \
"CMakeFiles/BomberMan.dir/Code/Func/map.c.obj" \
"CMakeFiles/BomberMan.dir/Code/Func/show.c.obj" \
"CMakeFiles/BomberMan.dir/Code/Func/player.c.obj"

# External object files for target BomberMan
BomberMan_EXTERNAL_OBJECTS =

BomberMan.exe: CMakeFiles/BomberMan.dir/Code/main.c.obj
BomberMan.exe: CMakeFiles/BomberMan.dir/Code/Func/map.c.obj
BomberMan.exe: CMakeFiles/BomberMan.dir/Code/Func/show.c.obj
BomberMan.exe: CMakeFiles/BomberMan.dir/Code/Func/player.c.obj
BomberMan.exe: CMakeFiles/BomberMan.dir/build.make
BomberMan.exe: CMakeFiles/BomberMan.dir/linklibs.rsp
BomberMan.exe: CMakeFiles/BomberMan.dir/objects1.rsp
BomberMan.exe: CMakeFiles/BomberMan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable BomberMan.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BomberMan.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BomberMan.dir/build: BomberMan.exe
.PHONY : CMakeFiles/BomberMan.dir/build

CMakeFiles/BomberMan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BomberMan.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BomberMan.dir/clean

CMakeFiles/BomberMan.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\CNM-CUR\CLionProjects\BomberMan C:\Users\CNM-CUR\CLionProjects\BomberMan C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug C:\Users\CNM-CUR\CLionProjects\BomberMan\cmake-build-debug\CMakeFiles\BomberMan.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BomberMan.dir/depend

