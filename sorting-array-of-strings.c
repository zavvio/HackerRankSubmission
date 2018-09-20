// https://www.hackerrank.com/challenges/sorting-array-of-strings

int lexicographic_sort(const char* a, const char* b) {
    int i = 0;
    char x, y;
    
    while (1) {
        x = a[i];
        y = b[i];
        // shorter
        if (x == '\0')
            return 1;
        else if (y == '\0')
            return 0;
        // lower character
        if (x < y)
            return 1;
        else if (y < x)
            return 0;
        else
            i++;
    }
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return lexicographic_sort(a, b) == 1 ? 0 : 1;
}

int count_distinct_characters(const char* str) {
    int count[26] = {0};
    int i = 0, sum;
    char c;
    while ((c = str[i]) != '\0') {
        count[c - 'a'] = 1;
        i++;
    }
    for (i=0, sum=0; i<26; i++) {
        sum += count[i];
    }
    return sum;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a, count_b;
    count_a = count_distinct_characters(a);
    count_b = count_distinct_characters(b);
    if (count_a < count_b)
        return 1;
    else if (count_b < count_a)
        return 0;
    else
        return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_a < len_b)
        return 1;
    else if (len_b < len_a)
        return 0;
    else
        return lexicographic_sort(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char *buff;
    for (int i=0; i<len; i++) {
        for (int j=1; j<len; j++) {
            if (cmp_func(arr[j-1], arr[j]) != 1) {
                buff = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = buff;
            }
        }
    }
}
