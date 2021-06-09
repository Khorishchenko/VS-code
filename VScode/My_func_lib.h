#ifndef MyLib_H
#define MyLib_H

int mystrlen(const char* str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char* mystrcpy(char* str1, char* str2) {
    int i = 0;
    while (i<=mystrlen(str2))
        str1[i] = str2[i++];
    return str1;
}

char* mystrcat(char* str1, char* str2) {
    int i = 0, n = mystrlen(str1);
    while (i <= mystrlen(str2))
        str1[n + i] = str2[i++];
    return str1;
}

char* mystrchr(char* str, char sym) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == sym)
            return &str[i];
        i++;}
    return 0;
}

char* mystrstr(char* str1, char* str2) {
    int i = 0, j=0;
    while (str1[i] != '\0') {
        if (str2[j] == '\0')
            return &str1[i - j];
        else if (str1[i] == str2[j])
            j++;
        else
            j = 0;
        i++;
    }
    return 0;
}
#endif
