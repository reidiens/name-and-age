# Name and Age

This program asks for your name and repeats it to you. And then, it asks for your age.... and it REPEATS IT TO YOU .. 🤯🤯🤯🤯

Yeah I know, it doesn't do much. However, I'm still pretty proud of this one. Not only does it get your name, but it separates it into your first and last names. It also truncates the string to get rid of trailing newlines so that the text output isn't messed up.
It also includes my very first custom header file, which defines 2 (very useful, if I may say so) functions:

### gstrunc()
This function, defined in the "easy_inp.h" header file, gets a string input from stdin using fgets. If the string ends with a newline, the newline is replaced with EOF, so as to preserve formatting. After that, it does a second check to see if the string now ends with an extra space. Again, if it does, the space is replaced with EOF.

The function is prototyped as:

``` int gstrunc(char* str) ```
