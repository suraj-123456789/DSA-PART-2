// file handling linear search
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char city[50];
    char std_code[5];
} CityStd;

int main()
{
    FILE *fp;
    char cname[50];
    int flag = 0;

    fp = fopen("cities.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening cities.txt\n");
        return 0;
    }

    CityStd list[10];
    int count = 0;

    while (!feof(fp))
    {
        fscanf(fp, "%s %s", list[count].city, list[count].std_code);
        count++;
    }

    fclose(fp);

    printf("Enter city name: ");
    scanf("%s", cname);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(cname, list[i].city) == 0)
        {
            printf("STD code for %s: %s\n", cname, list[i].std_code);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("City is Not found\n");
    }

    return 0;
}
