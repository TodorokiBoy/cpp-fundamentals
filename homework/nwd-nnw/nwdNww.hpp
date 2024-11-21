#pragma once

int NWD(int lhs, int rhs) {
    if (lhs == 0 || rhs == 0) {
        return std::abs(lhs + rhs);
    }
    lhs = std::abs(lhs);
    rhs = std::abs(rhs);
    while (rhs != 0) {
        int temp = lhs;
        lhs = rhs;
        rhs = temp % rhs;
    }
    return lhs;
}

int NWW(int lhs, int rhs) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    }
    return std::abs(lhs / NWD(lhs, rhs) * rhs);
}
