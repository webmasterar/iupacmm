//License: GNU GPLv3 Copyright 2016 Ahmad Retha
#include <iostream>
#include <fstream>
#include <string>
#include "nuc.hpp"
#include "iupacmm.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    if (argc != 3) {
        cerr << "Usage: ./iupacmm seqs.fasta patterns.txt" << endl;
        return 1;
    }

    ifstream seqs(argv[1], ios::in);
    if (!seqs.good()) {
        cerr << "Error opening seqs file!" << endl;
        return 1;
    }
    ifstream pats(argv[2], ios::in);
    if (!pats.good()) {
        cerr << "Error opening pattern file!" << endl;
        return 1;
    }

    string seq, pattern;

    //read in first seq verbatim
    string seqBuf;
    bool firstGTread = false;
    while(getline(seqs, seqBuf)) {
        if (seqBuf != "") {
            if (seqBuf[0] == '>') {
                if (firstGTread) {
                    break;
                } else {
                    firstGTread = true;
                    continue;
                }
            }
            seq += seqBuf;
        }
    }

    unsigned int i, j;

    //convert seq to numeric representation
    for (i = 0; i < seq.length(); i++) {
        seq[i] = NUC[seq[i]];
    }

    //read in the rest of the lines as summative seqs
    i = 0;
    while(getline(seqs, seqBuf)) {
        if (seqBuf != "") {
            if (seqBuf[0] == '>') {
                i = 0;
                continue;
            } else {
                for (j = 0; j < seqBuf.length(); j++, i++) {
                    seq[i] = seq[i] | NUC[seqBuf[j]];
                }
            }
        }
    }

    //then find the patterns
    int pos;
    while(getline(pats, pattern)) {
        if (pattern != "" && pattern[0] != '>' && pattern.length() <= seq.length()) {
            cout << pattern;

            //convert pattern to numeric representation
            for (i = 0; i < pattern.length(); i++) {
                pattern[i] = NUC[pattern[i]];
            }

            pos = findPattern(&seq, &pattern);
            if (pos == -1) {
                cout << " not found" << endl;
            } else {
                cout << " found at position " << pos << endl;
            }
        }
    }

    return 0;
}
