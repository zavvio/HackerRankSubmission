// https://www.hackerrank.com/challenges/variadic-functions-in-c

int sum (int count,...) {
    va_list ap;
    int sum = 0;
    va_start(ap, count);
    
    for (int i = 0; i < count; i++)
        sum += va_arg(ap, int);

    va_end (ap);
    return sum;
}

int min(int count,...) {
    va_list ap;
    int mini = MAX_ELEMENT, x;
    va_start(ap, count);
    
    for (int i = 0; i < count; i++) {
        x = va_arg(ap, int);
        if (x < mini) mini = x;
    }

    va_end (ap);
    return mini;
}

int max(int count,...) {
    va_list ap;
    int maxi = MIN_ELEMENT, x;
    va_start(ap, count);
    
    for (int i = 0; i < count; i++) {
        x = va_arg(ap, int);
        if (x > maxi) maxi = x;
    }

    va_end (ap);
    return maxi;
}
