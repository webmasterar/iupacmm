//License: GNU GPLv3 Copyright 2016 Ahmad Retha
#ifndef __iupacmm__
#define __iupacmm__

#include <string>
#include "iupacmm.hpp"

#define DEL NUC['-']
#define matches(tc,pc) ((pc) & (tc)) == (pc)

int findPattern(std::string * seq, std::string * pattern);

#endif
