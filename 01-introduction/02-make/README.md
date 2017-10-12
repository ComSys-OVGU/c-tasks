# GNU Make
## Motivation
Invoking the compiler by hand is a tedious task and a waste of time. Automating
the build process is therefore very desirable. One of the most popular tool
for build automation is GNU Make. As a result, the whole build process can be
done by running `make`. In addition to simplifying the build process, GNU Make
speeds up recompilations significantly: It will only regenerate files whose
source files have been changed.

## Syntax
The code describing the build process has to be stored in a file called
`Makefile`. When `make` is called, it will search in the current directory for
this file and start with the creation of the first target in this file.

```
# A line starting with "#" is a comment and ignored
# The next line declares the target "foo", which depends on the files
# "foo-source1", "foo-source2" and "foo-source3"
foo: foo-source1 foo-source2 foo-source3
	command-to-create-foo
# All lines with indent following a declaration will be executed line by line.
# This/These command(s) should create the target
#
# Of course, "foo-source1" itself could be an intermediate step in the build
# process. So if "foo-source1" is specified as a target in the Makefile, it
# will be created by GNU Make before "foo" is created. 
#
# Variables in Makefiles are created by assigning a value to them:
CFLAGS = -std=c99
# And the value of the variable can be retrieved by $(CFLAGS)
# Also variables can be extended like this
CFLAGS += -Wall
# After this, the variable "CFLAGS" will have the value "-std=c99 -Wall"
#
# You might want to create targets that do not create any files. E.g. if your
# project creates the executables "foo" and "bar" you might want to create a
# target "all", which creates both of them. This can be done by:
all: foo bar
# Please note that for "all" no commands are listed. A GNU Make target does not
# required commands to be valid.
#
# This will specify that the targets "all" and "clean" will not create any file:
.PHONY: all clean
# These targets are called "phony" targets
#
# Special variables:
#	$@ specifies the target
#	$< specifies the first dependency of a target (the first source file)
#	$^ specifies all dependencies of a a target (all source files)
```
## Task
- This folder contains the same source file you already have seen in the Hello
  World task, as well as a Makefile skeleton
- Update the Makefile to
	- Provide the "phony" target `all` as first (default) target, which depends
	  on the target `hello`
	- Create the (non-phony) target `hello`, which depends on `hello.o` and
	  creates the executable `hello` by linking `hello.o`
	- Set the variables `CC` and `CFLAGS`, so that the target `hello.o` creates
	  the object file `hello.o` by compiling `hello.c` using `gcc` as compiler
	  using the arguments `-c -std=c99 -Wall -Wextra -pedantic -Werror -O0 -g`
