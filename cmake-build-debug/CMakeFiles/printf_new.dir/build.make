# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/vlad/Загрузки/clion-2019.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vlad/Загрузки/clion-2019.3.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vlad/CLionProjects/printf_new

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vlad/CLionProjects/printf_new/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/printf_new.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/printf_new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/printf_new.dir/flags.make

CMakeFiles/printf_new.dir/ft_printf.c.o: CMakeFiles/printf_new.dir/flags.make
CMakeFiles/printf_new.dir/ft_printf.c.o: ../ft_printf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/CLionProjects/printf_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/printf_new.dir/ft_printf.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf_new.dir/ft_printf.c.o   -c /home/vlad/CLionProjects/printf_new/ft_printf.c

CMakeFiles/printf_new.dir/ft_printf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf_new.dir/ft_printf.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vlad/CLionProjects/printf_new/ft_printf.c > CMakeFiles/printf_new.dir/ft_printf.c.i

CMakeFiles/printf_new.dir/ft_printf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf_new.dir/ft_printf.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vlad/CLionProjects/printf_new/ft_printf.c -o CMakeFiles/printf_new.dir/ft_printf.c.s

CMakeFiles/printf_new.dir/check.c.o: CMakeFiles/printf_new.dir/flags.make
CMakeFiles/printf_new.dir/check.c.o: ../check.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/CLionProjects/printf_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/printf_new.dir/check.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf_new.dir/check.c.o   -c /home/vlad/CLionProjects/printf_new/check.c

CMakeFiles/printf_new.dir/check.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf_new.dir/check.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vlad/CLionProjects/printf_new/check.c > CMakeFiles/printf_new.dir/check.c.i

CMakeFiles/printf_new.dir/check.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf_new.dir/check.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vlad/CLionProjects/printf_new/check.c -o CMakeFiles/printf_new.dir/check.c.s

CMakeFiles/printf_new.dir/func.c.o: CMakeFiles/printf_new.dir/flags.make
CMakeFiles/printf_new.dir/func.c.o: ../func.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/CLionProjects/printf_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/printf_new.dir/func.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf_new.dir/func.c.o   -c /home/vlad/CLionProjects/printf_new/func.c

CMakeFiles/printf_new.dir/func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf_new.dir/func.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vlad/CLionProjects/printf_new/func.c > CMakeFiles/printf_new.dir/func.c.i

CMakeFiles/printf_new.dir/func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf_new.dir/func.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vlad/CLionProjects/printf_new/func.c -o CMakeFiles/printf_new.dir/func.c.s

# Object files for target printf_new
printf_new_OBJECTS = \
"CMakeFiles/printf_new.dir/ft_printf.c.o" \
"CMakeFiles/printf_new.dir/check.c.o" \
"CMakeFiles/printf_new.dir/func.c.o"

# External object files for target printf_new
printf_new_EXTERNAL_OBJECTS =

printf_new: CMakeFiles/printf_new.dir/ft_printf.c.o
printf_new: CMakeFiles/printf_new.dir/check.c.o
printf_new: CMakeFiles/printf_new.dir/func.c.o
printf_new: CMakeFiles/printf_new.dir/build.make
printf_new: CMakeFiles/printf_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vlad/CLionProjects/printf_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable printf_new"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/printf_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/printf_new.dir/build: printf_new

.PHONY : CMakeFiles/printf_new.dir/build

CMakeFiles/printf_new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/printf_new.dir/cmake_clean.cmake
.PHONY : CMakeFiles/printf_new.dir/clean

CMakeFiles/printf_new.dir/depend:
	cd /home/vlad/CLionProjects/printf_new/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vlad/CLionProjects/printf_new /home/vlad/CLionProjects/printf_new /home/vlad/CLionProjects/printf_new/cmake-build-debug /home/vlad/CLionProjects/printf_new/cmake-build-debug /home/vlad/CLionProjects/printf_new/cmake-build-debug/CMakeFiles/printf_new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/printf_new.dir/depend

