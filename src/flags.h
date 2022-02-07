#ifndef FLAGS_H
#define FLAGS_H

struct Flags {
    int S, Z, A, P;  // Status Flags
    void init() {
        S = Z = 0;
    }
};

#endif