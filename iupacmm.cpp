//License: GNU GPLv3 Copyright 2016 Ahmad Retha
#include <iostream>
#include <string>
#include "nuc.hpp"
#include "iupacmm.hpp"

using namespace std;

int findPattern(string * seq, string * pattern)
{
    int n = (*seq).length();
    int m = (*pattern).length();
    int i, j, k, l;

outer:
    i = -1;
    while (i <= n - m)
    {
        i++;
        j = k = l = 0;

inner:
        if (matches((*seq)[i + j], (*pattern)[j]))
        {
            j++;
            k = l = j;
            if (j == m) {
                return i;
            } else {
                goto inner;
            }
        }
        else
        {

secondInner:
            k = l;
            while (i + k < n && matches((*seq)[i + k], DEL) && !(matches((*seq)[i + k], (*pattern)[j]))) {
                k++;
            }
            if (matches((*seq)[i + k], (*pattern)[j])) {
                j++;
                l = k;
                if (j == m) {
                    return i;
                } else {
                    goto secondInner;
                }
            }
        }
    }

    return -1;
}
