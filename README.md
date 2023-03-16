# Name and Age

This program asks for your name and repeats it to you. And then, it asks for your age.... and it REPEATS IT TO YOU .. 🤯🤯🤯🤯

Yeah I know, it doesn't do much. However, I'm still pretty proud of this one. Not only does it get your name, but it separates it into your first and last names. It also truncates the string to get rid of trailing newlines so that the text output isn't messed up.

It also includes my very first custom header file, `easy_inp.h`, which defines 2 (very useful, if I may say so) functions:

## gstrunc()
This function, defined in the `easy_inp.h` header file, gets a string input from stdin using `fgets()`. If the string ends with a newline, the newline is replaced with `EOF`, so as to preserve future formatting. After that, it does a second check to see if the string now ends with an extra space. Again, if it does, the space is replaced with `EOF`.

The function is prototyped as:

``` int gstrunc(char* str) ```

`str` is the pointer where the inputted string is stored. Possible return values are:

 - 1, indicating that the string has been stored successfully, and 
 - 0, indicating that the string has been left blank (only a nl), or that it hasn't been stored successfully.

All in all, I believe this to be a very useful function, since it combines `fgets()` with a truncation check, along with providing useful error-checking values. It makes getting & printing strings a breeze, which can be a pain in C, since it has no built-in string handlers.

## gint()

This function used to be called `gintfstr()`, which stood for Get Int From String. As you can guess, that's exactly what it does. It receives a string from stdin using `fgets()`, and then runs the string through `sscanf()` to detect a numerical value and convert it to `int`. If you're wondering why I don't just use `scanf()`, it's because `scanf()` doesn't provide input buffering. If you were to input a character when `scanf()` expects an integer, all sorts of weird, kooky bugs can occur. Getting the number through `fgets()` guarantees that we get a string output. We can then run this string through `sscanf()` to achieve 3 things:
 
 - Make sure we have a guaranteed (and expected) string input
 - Easily parse the string to an integer
 - Easily check for errors based on the output of `sscanf()`

The function is prototyped as:

``` int gint(int* num_int) ```

`num_int` is a pointer to the integer variable that we wish to hold the inputted value. Possible return values are:

 - 1, indicating that the integer has been parsed from the string and stored successfully
 - 0, indicating that `sscanf()` did not parse the integer and that there has been some input error, and
 - -1, indicating that the string has been left blank (only a nl entered)

I plan on using this function all the time. The main reason I created a custom header file was to be able to port this function to various programs without having to worry about declaring it each time. I hate dealing with the error-checking involved with receiving integer input, and this function helps greatly.

One little thing about the function that some people may not like, though, is that it creates a string, `num_str`, of 128 bytes to hold the string that `fgets()` stores. Of course, this memory is freed every time the function is exited.

The header file `easy_inp.h` also defines two constants used in the functions: STR_LEN_HIGH and STR_LEN_LOW. Their values are 512 and 128, respectively, and are used in `gstrunc()` and `gint()`, repectively. They are used to tell `fgets()` the max length of the string it should be looking for. In `gint()`, STR_LEN_LOW is also used to tell `malloc()` how much space to allocate for `num_hold`. The values for these constants may or may not be adequate, depending on what they're being used for. I tried to make them big enough to avoid overflow errors in this program, while still being a reasonable size.

## How to run:
 - Navigate to the directory of the program
 - If you wish to change the custom header or function definitions, edit `easy_inp.c`. For the main program, edit `main.c`
 - If you edited anything, use the command

```$ gcc -c [FILE_NAME]```

to create new object files. This must be run once for each file you edit, every time you edit it.
 - After that, use

```$ gcc easy_inp.c main.c -o main``` 
to recompile.
 - Finally, you use

```$ ./main```
to run the program.

## Known Bugs/Stuff to Fix:
 - ?? Not sure. Need this program to be tested by more experienced programmers who can find bugs/optimizations that I cannot find myself.
