#include "tom_shelleck.h"

int main(void)
{
        int i;
        char str[] = "Yo no soy marinero, soy capitan, soy capitan", *del = " ";
        char **arr = strtok_array(str, del);

        if (!arr)
                return (1);
        for (i = 0; arr[i]; i++)
                printf("%s\n", arr[i]);
        for (i--; i >= 0; i--)
                free(arr[i]);
        free(arr);
        return (0);
}
