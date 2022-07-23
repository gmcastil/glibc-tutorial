Character Handling
------------------
One of the first noteworthy things in this chapter is the dependance of things
that might at first glance be insignificant but are probably important, like the
dependance of the GNU C library on the locale specified.  As an example,
consider the `int isspace(int c)` function, which returns true if <i>c</i> is a
whitespace character. In the standard C locale, isspace returns true for the
standard whitespace characters.  But what about other locales?

This chapter is rather short and basically just introduces the methods for
classifying individual characters as alphabetic, digits, whitespace, etc. and
broadens the discussion to include the handling of what it refers to as wide
characters.  This chapter might feel more useful after reading Chapter 7 on
locales and internationalization.
