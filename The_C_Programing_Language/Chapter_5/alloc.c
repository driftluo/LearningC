#define ALLOCSIZE 10000 //  size of available space

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;

//  return pointer to n characters
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else 
        return 0;
}

//  free storage pointed to by p
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

//  strlen: return length of string s
int strlen1(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}

//  strlen: return length of string s
int strlen2(char *s) {
    int len;

    for(len = 0; *s != '\0'; s++) {
        len++;
    }
    return len;
}

// // strcpy: copy t to s; array subscript version
// void strcpy(char *s, char *t) {
//     int i;

//     i = 0;
//     while ((s[i] = t[i]) != '\0')
//         i++;
// }

// // strcpy: copy t to s; pointer version
// void strcpy(char *s, char *t) {
//     int i;

//     i = 0;
//     while ((*s = *t) != '\0')
//         s++;
//         t++;
// }

// // strcpy: copy t to s; pointer version 2
// void strcpy(char *s, char *t) {
//     while ((*s++ = *t++) != '\0')
//         ;
// }

// // strcpy: copy t to s; pointer version 3
// void strcpy(char *s, char *t) {
//     while (*s++ = *t++)
//         ;
// }

// // strcmp: return <0 if s<t, 0 if s==t, >0 if s>t
// int strcmp(char *s, char *t) {
//     int i;

//     for (i = 0; s[i] == t[i]; i++)
//         if (s[i] == '\0')
//             return 0;
//     return s[i] - t[i];
// }

// // strcmp: return <0 if s<t, 0 if s==t, >0 if s>t, pointer version
// int strcmp(char *s, char *t) {
//     for (; *s==*t; s++, t++)
//         if (*s == '\0')
//             return 0;
//     return *s - *t;
// }
