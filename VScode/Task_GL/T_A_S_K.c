#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_update(void) {

    char str[] = "ebcdeXIX";
    char *tmp;

    tmp = str;
    *(++tmp) = '0';

    for (int i=0; i < strlen(tmp)/2; i++)
        str [i] += 1;

 //Укажите промежуточные результаты (что выведет printf("%s", str) и printf("%s", tmp);
    // printf("%s\n", str);
    // printf("%s\n", tmp);


    str[2] = '\0';
    tmp += atoi(tmp) + 1;

 //Укажите промежуточные результаты (что выведет printf("%s", str) и printf("%s", tmp);

  printf("%s\n", str);
    printf("%s\n", tmp);



    tmp[0] = 'M';
    *(tmp + 1) = 'M';

    printf("%s", str);
    printf("%s", tmp);
} 

int main()
{
    str_update();
    return 0;
}

