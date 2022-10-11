# libft-unit-test
This is a small [µnit](https://nemequ.github.io/munit) test suite for libft, the first project in 42's core curriculum. Since the final product is a collection of functions, it lends itself very well to unit testing. Where possible, the tests will run your version of the standard library functions against the original and compare their output. For the Part 2 functions, I've done my best to make a comprehensive set of test cases.

## WIP in progress
Right now, the tests cover all of part 1, a little bit of part 2 and none of the bonus. More to come as I actually write these myself.
These functions are still missing:
* Part 2:
  * Everything except for `ft_itoa` and `ft_substr`. It's my first week here, okay?

## How to use
To use this during evaluations or just in your own project, follow these steps:
1. Clone this repo onto your machine.
2. Copy the `munit.c`, `munit.h` and `test.c` files into your libft project's root folder.
3. Add the following task to your Makefile:
  ```make
  test : re
  	cc munit.c test.c -L . -l ft -o test
  	./test
  ```
4. That's it! Run `make test` to recompile the library, then compile and run the test file. If you're on an operating system which doesn't use BSD libaries by default, you may have to add `-lbsd` to the task listed above.
 
 ## Configuration
 Near the top of `test.c` there are several booleans which let you turn different parts of the test suite (part 1, part 2 and the bonus part) on or off. By setting the value to `false`, the tests will be skipped. __Please note that the tests won't compile if you have not yet written all of the functions in your selected parts!__ The ability to opt out of later parts is there for your convenience.
 
 ## Omissions
 Unfortunately, not everything can be automatically tested, so some manual checking is still required for the following:
 * Malloc protection! The tests can't simulate a malloc failure (as far as I'm aware), so you will need to check for yourself whether appropriate precautions have been taken. If you don't, Moulinette will.
 * How you handle a zero-input in `ft_calloc`, because the specification leaves you to decide whether to pass a memory address or NULL.
 
 Beware that I haven't run my project through evals and Moulinette yet, so these tests do not necessarily reflect what is expected of your code. My tests may be off the mark, or may error when the code actually passes by Moulinette's standards. __Your mileage may vary.__ If any discrepancies show up later down the line, I'll update this.
