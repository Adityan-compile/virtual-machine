#ifndef FLAGS_H
#define FLAGS_H

struct Flags {
    int S, Z;  // Status Flags
    void init() {
        S = Z = 0;
    }
};

#endif