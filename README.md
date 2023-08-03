What's the point here anyway
============================

LAPACK is a brilliant library that remains the single most performant linear algebra library out there. Sure, there's other tools out there Eigen for one is also fantastic, particularly for quick prototyping. For many things Eigen can actually outperform LAPACK. The point here isn't to debate the benefits. Many projects large and small have opted to use either (or even other libraries). The aim here isn't to resolve that at all. In fact, odds are you should use CBLAS (or this project should leverage it in the future). 

No the point here is that it's is time for FORTRAN to die. The undeniable utility of LAPACK means FORTRAN lives on and sneaks its way into projects it really has no business being a part of. Sure, vanilla FORTRAN lapack will certainly beat this hack of a library (particularly on super computers I can't test on). But for a lot of people, a lot of projects, just aren't on that scale. So the aim here is to create a drop in replacement for LAPACK in projects that would otherwise be purely C/C++ and put an end to the frankenstein creations that still proliferate. 

see the docs [here](https://lakebookman.github.io/cpplapack2023/)
