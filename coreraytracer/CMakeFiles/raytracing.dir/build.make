# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aroquemaurel/projets/cpp/raytracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aroquemaurel/projets/cpp/raytracing

# Include any dependencies generated for this target.
include coreraytracer/CMakeFiles/raytracing.dir/depend.make

# Include the progress variables for this target.
include coreraytracer/CMakeFiles/raytracing.dir/progress.make

# Include the compile flags for this target's objects.
include coreraytracer/CMakeFiles/raytracing.dir/flags.make

coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o: coreraytracer/CMakeFiles/raytracing.dir/flags.make
coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o: coreraytracer/intervaloperators.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/aroquemaurel/projets/cpp/raytracing/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/intervaloperators.cpp.o -c /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/intervaloperators.cpp

coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/intervaloperators.cpp.i"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/intervaloperators.cpp > CMakeFiles/raytracing.dir/intervaloperators.cpp.i

coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/intervaloperators.cpp.s"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/intervaloperators.cpp -o CMakeFiles/raytracing.dir/intervaloperators.cpp.s

coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o.requires:
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o.requires

coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o.provides: coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o.requires
	$(MAKE) -f coreraytracer/CMakeFiles/raytracing.dir/build.make coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o.provides.build
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o.provides

coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o.provides.build: coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o

coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o: coreraytracer/CMakeFiles/raytracing.dir/flags.make
coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o: coreraytracer/texture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/aroquemaurel/projets/cpp/raytracing/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/texture.cpp.o -c /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/texture.cpp

coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/texture.cpp.i"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/texture.cpp > CMakeFiles/raytracing.dir/texture.cpp.i

coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/texture.cpp.s"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/texture.cpp -o CMakeFiles/raytracing.dir/texture.cpp.s

coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o.requires:
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o.requires

coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o.provides: coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o.requires
	$(MAKE) -f coreraytracer/CMakeFiles/raytracing.dir/build.make coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o.provides.build
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o.provides

coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o.provides.build: coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o

coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o: coreraytracer/CMakeFiles/raytracing.dir/flags.make
coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o: coreraytracer/raytracing.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/aroquemaurel/projets/cpp/raytracing/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/raytracing.cpp.o -c /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/raytracing.cpp

coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/raytracing.cpp.i"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/raytracing.cpp > CMakeFiles/raytracing.dir/raytracing.cpp.i

coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/raytracing.cpp.s"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/raytracing.cpp -o CMakeFiles/raytracing.dir/raytracing.cpp.s

coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o.requires:
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o.requires

coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o.provides: coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o.requires
	$(MAKE) -f coreraytracer/CMakeFiles/raytracing.dir/build.make coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o.provides.build
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o.provides

coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o.provides.build: coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o

# Object files for target raytracing
raytracing_OBJECTS = \
"CMakeFiles/raytracing.dir/intervaloperators.cpp.o" \
"CMakeFiles/raytracing.dir/texture.cpp.o" \
"CMakeFiles/raytracing.dir/raytracing.cpp.o"

# External object files for target raytracing
raytracing_EXTERNAL_OBJECTS =

coreraytracer/libraytracing.a: coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o
coreraytracer/libraytracing.a: coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o
coreraytracer/libraytracing.a: coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o
coreraytracer/libraytracing.a: coreraytracer/CMakeFiles/raytracing.dir/build.make
coreraytracer/libraytracing.a: coreraytracer/CMakeFiles/raytracing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libraytracing.a"
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && $(CMAKE_COMMAND) -P CMakeFiles/raytracing.dir/cmake_clean_target.cmake
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
coreraytracer/CMakeFiles/raytracing.dir/build: coreraytracer/libraytracing.a
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/build

coreraytracer/CMakeFiles/raytracing.dir/requires: coreraytracer/CMakeFiles/raytracing.dir/intervaloperators.cpp.o.requires
coreraytracer/CMakeFiles/raytracing.dir/requires: coreraytracer/CMakeFiles/raytracing.dir/texture.cpp.o.requires
coreraytracer/CMakeFiles/raytracing.dir/requires: coreraytracer/CMakeFiles/raytracing.dir/raytracing.cpp.o.requires
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/requires

coreraytracer/CMakeFiles/raytracing.dir/clean:
	cd /home/aroquemaurel/projets/cpp/raytracing/coreraytracer && $(CMAKE_COMMAND) -P CMakeFiles/raytracing.dir/cmake_clean.cmake
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/clean

coreraytracer/CMakeFiles/raytracing.dir/depend:
	cd /home/aroquemaurel/projets/cpp/raytracing && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aroquemaurel/projets/cpp/raytracing /home/aroquemaurel/projets/cpp/raytracing/coreraytracer /home/aroquemaurel/projets/cpp/raytracing /home/aroquemaurel/projets/cpp/raytracing/coreraytracer /home/aroquemaurel/projets/cpp/raytracing/coreraytracer/CMakeFiles/raytracing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : coreraytracer/CMakeFiles/raytracing.dir/depend

