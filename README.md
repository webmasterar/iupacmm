## iupacmm

This program will combine multiple sequences to create a single consensus sequence
that represents SNPs and indels using an augmented IUPAC super-alphabet. The
consensus sequence can be searched for a non-degenerate pattern in worst-case
O(nmd) time, where **n** is the length of the concensus sequence, **m** the length
of the pattern, and **d** the number of indels.

The program assumes the longest sequence in the sequences file is the first one
and that sequences are provided in multi-FASTA format. The patterns file can contain
one or more non-degenerate patterns seperated by new lines. Also, the program only
returns the starting position of the first match indicating that a given pattern
exists in the concensus sequence, but this doesn't necessarily mean that it exists
in any individual sequence in the file.

Usage:

`./iupacmm data/seqs.fasta data/patterns.txt`

License: GNU GPLv3 Copyright 2016 Ahmad Retha
