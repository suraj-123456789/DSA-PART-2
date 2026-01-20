// file handling binary search
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char city[50];
    char std_code[5];
} CityStd;
CityStd list[50];

int binary_search(char *, int, int);

int main()
{
    FILE *fp;
    char cname[50];
    fp = fopen("cities.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening cities.txt\n");
        return 0;
    }
    int count = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s", list[count].city, list[count].std_code);
        // printf("\n%s\t:%s", list[count].city, list[count].std_code);
        count++;
    }

    fclose(fp);

    printf("\nEnter city name: ");
    scanf("%s", cname);

    int n = binary_search(cname, 0, count - 1);

    if (n != -1)
    {
        printf("STD code for %s : %s\n", cname, list[n].std_code);
    }
    else
    {
        printf("City Not found\n");
    }
    return 0;
}

int binary_search(char cname[50], int lb, int ub)
{
    int mid;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        int c = strcmp(cname, list[mid].city);

        if (c == 0)
        {
            return mid;
        }
        if (c < 0)
        {
            ub = mid - 1;
        }
        else if (c > 0)
        {
            lb = mid + 1;
        }
    }
    return -1;
}
