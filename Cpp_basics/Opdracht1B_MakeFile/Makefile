# Inside CXX we save the name of the compiler.
cxx = g++
# Compiler flags
#-Wall sets the compiler to display a large range of warnings if they exist
#-std=c++11 sets the language standard to c++11 for compiling.
cxxFlags = -Wall -std=c++11

#These variables are named cxx because it's a naming convention / standard for
#ease of reading that refer to compilation

# listing all directory names in the workfolder
srcDir = src
includeDir = include
buildDir = build
targetDir = target

#list all source files with .cpp
#wildcard is a function in make, where it looks for a certain pattern listed.
#In this case, wildcard looks for -all- .cpp files in the specified directory.
#Other applications include pattern matching and group matching.
# Source files
sources := $(wildcard $(srcDir)/*.cpp)

# Object files
#Object files are practically compiled pieces of code.
#The compiler takes the code, compiles it and throws it into a .o file in the build directory.
objects := $(sources:$(srcDir)/%.cpp=$(buildDir)/%.o)

# Executable name
# Signifying both the destination of the executable and the name of the file it dumps everything into.
target = $(targetDir)/executeable
# Default rule
all: $(target)

# Rule to create the executable
# First, it compares files listed in target to the ones in objects.
# If any object files have been modified more recently than its target file, this rule will trigger.
# then, it will do a mkdir. The @ causes it not to be printed in the console,
# and it uses mkdir to create a directory
#The command $(@D) is a macro in Makefile that specially targets the directory of the target.
#Usually the @ symbol is for not printing in the console, but in combination with a macro like D it has a different function.
#Lastly, it 
$(target): $(objects)
	@mkdir -p $(@D)
	$(cxx) $(cxxFlags) $^ -o $@

# Rule to compile source files into object files
$(buildDir)/%.o: $(srcDir)/%.cpp
	@mkdir -p $(@D)
	$(cxx) $(cxxFlags) -I$(includeDir) -c -o $@ $<

# Clean rule
clean:
	rm -rf $(buildDir) $(targetDir)

.PHONY: all clean
