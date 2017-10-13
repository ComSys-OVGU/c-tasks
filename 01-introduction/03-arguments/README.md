# Command Line Arguments
## Motivation
Often specific details of the behaviour of a program cannot be configured at
compile time. Instead, methods to configure a program a run time are needed.

Lets for example look at the shell command `cp`, which creates a copy of a file.
Specifying the name of the file to copy and the name of the copy to create in
the C source file of the program `cp` would be terrible for its usability.
Instead, `cp` allows to specify source and destination at runtime by calling it
with command line arguments, e.g. `cp orignal_file copy_of_original_file`.

In this task you will learn who to use command line arguments in your own C
programs.

## Task
- Create the program `knights`
	- The source should be placed in `knights.c`. Replace its contents with your
	  solution
	- A Makefile for this program is already provided
- If `knights` is called with no arguments, it should print: "We are The Knights
  Who Say "Ni!". We demand a shrubbery. One that looks nice. And not to
  expensive."
- If the application is called with one or more arguments, of which at least one
  is "shrubbery", it should print: "We are no longer The Knights Who Say "Ni!".
  We are now The Knights Who Say Ekki-Ekki-Ekki-Ekki-PTANG. Zoom-Boing.
  Z'nourrwringmm. Bring us another shrubbery. Slightly higher than the first
  one. Then you now must cut down the mightiest tree in the forest - with a
  herring!"
- If the application is called with five or more arguments, of which at least
  five are "it", it should print: "Arrhhg!". This has priority over the
  "shrubbery"-case
- If no of the cases above match, the command should behave as it was called
  with no arguments
- The current source code in `knights.c` contains some useful hints
