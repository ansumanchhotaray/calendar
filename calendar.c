#include <stdio.h>

int main(void)
{
    char *monthsList[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = 1;
    int year = 1;

    printf("Enter month: "); 
    scanf("%i", &month);
    month--;

    printf("Enter year: ");
    scanf("%i", &year);

    printf("\n%s, ", monthsList[month]);
    printf("%04i\n", year);
    printf("Mon Tue Wed Thu Fri Sat Sun\n");

    int blanks = 0;
    for (int i = 0; i <= year-1; i++)
    {
        if (i-1 % 4 == 0)
        {
            days[1] = 29;
        }
        else if (i % 4 != 0)
        {
            days[1] = 28;
        }

        if (i != year-1)
        {
            for (int j = 1; j <= 12; j++)
            {
                int a = days[j-1] + blanks;
                int b = a % 7;
                blanks = b;
            }
        }
        else if (i == year-1)
        {
            for (int j = 1; j <= month; j++)
            {
                int a = days[j-1] + blanks;
                int b = a % 7;
                blanks = b;
            }
        }
    }

    printf("%*s", 4 * blanks, "");

    for (int date = 1; date <= days[month]; date++)
    {
        int end = blanks + date;

        printf("%3i ", date);

        if((end % 7) == 0 || date == days[month])
        {
            printf("\n");
        }
    }
}
