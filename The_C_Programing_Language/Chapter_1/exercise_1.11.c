#include <stdio.h>

/*
 How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any?
利用文本文件进行测试 `$ a.out < test.txt`
1. 输入数据过大，溢出 int 值范围
2. 输入值无换行符，不符合统计标准
*/

#define IN 1
#define OUT 0

void main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c ==  '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
