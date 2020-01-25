# Regex-to-Epsilon-NFA
Supports the three classic regular expression operations as taught in the computational theory classes, namely-
* Union,
* Concatenation, and
* Kleene closure

The program takes an infix regular expression, constructs a corresponding parse tree and recursively evaluates it to make a non-deterministic finite automata.

The C++ source code is incomplete, had to switch over to python midway after instruction from college. It has some of the code (not complete) for evaluating the expression tree (and constructing the FA while doing so) but not for constructing the expression tree itself. The Python source code is complete.
