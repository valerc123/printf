# _printf();
_printf - prints data according to a format.

SYNOPSIS
       _printf FORMAT [ARGUMENT]...

DESCRIPTION
       Print ARGUMENT(s) according to FORMAT, or execute according to OPTION:

       We  use the function printf() with % followed by the type of format speci‐
       fier, to show the value of the variable.  Format specifier is used  during
       input and output. It is a way to tell the compiler what type of data is in
       a variable during taking input using _printf(). Some examples are %c,  %d,
       %i, etc.

       %i - got replaced by value an integer variable,

       %d - got replaced by value an integer variable decimal base 10,

       %c - got replaced by value of a character variable,

       %s - got replaced by value of a string variable,

       %% - got replaced by a single '%'.

SEE ALSO
       printf(3).

BUGS
       No known bugs.

AUTHOR
       Valentina Rúa Carrillo, Nicolas Forero Puello.
