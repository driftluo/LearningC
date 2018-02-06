/*
Functions like  isupper can be implemented to save space or to save time.
Explore both possibilities.
*/

// 函数形式，节省空间
int isupper(char c) {
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

// 宏，节省函数调用的时间，但是 c 的宏不是卫生宏，容易出问题
#define isupper(c)  ((c) >= 'A' && (c) <= 'Z') ? 1 : 0
