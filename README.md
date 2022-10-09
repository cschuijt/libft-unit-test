# libft-unit-test
This is a small [µnit](https://nemequ.github.io/munit) test suite for libft, the first project in 42's core curriculum. Since the final product is a collection of functions, it lends itself very well to unit testing. Where possible, the tests will run your version of the standard library functions against the original and compare their output. For the Part 2 functions, I've done my best to make a comprehensive set of test cases.

## How to use
To use this during evaluations or just in your own project, follow these steps:
1. Copy the `munit.c`, `munit.h` and `test.c` files into your project's root folder.
2. Add the following task to your Makefile:
  ```make
  test : re
  	cc munit.c test.c -L . -l ft -o test
  	./test
  ```
 3. That's it! Run `make test` to recompile the library, then compile and run the test file.
 4. If you use this during development, you can add those files to your `.gitignore`, and you can set up a norm checking task that only validates your files, because the test suite is obviously not norm compliant.
 
 ## Omissions
 Unfortunately, not everything can be automatically tested, so some manual checking is still required for the following:
 * Malloc protection! The tests can't simulate a malloc failure (as far as I'm aware), so you will need to check for yourself whether appropriate precautions have been taken. If you don't, Moulinette will.
 * How you handle a zero-input in `ft_calloc`, because the specification leaves you to decide whether to pass a memory address or NULL.
 
 Beware that I haven't run my project through evals and Moulinette yet, so these tests do not necessarily reflect what is expected of your code. My tests may be off the mark, or may error when the code actually passes by Moulinette's standards. __Your mileage may vary.__ If any discrepancies show up later down the line, I'll update this.
