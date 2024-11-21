#pragma once

int fibonacci_iterative(int sequence) {
    int a = 0;
    int b = 1;

    if (sequence == 0) {
        return a;
    }

    for (int i = 1; i < sequence; i++) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return b;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0) {
        return 0;
    }
    if (sequence == 1) {
        return 1;
    }
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
