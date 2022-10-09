# Add this task to your Makefile to compile the tests with your library.
# This assumes that you've set everything else up correctly: your required
# tasks, your compilation of the functions, your assembling of the library
# and putting it in the root directory of your project.

test : re
	cc munit.c test.c -L . -l ft -o test
	./test
