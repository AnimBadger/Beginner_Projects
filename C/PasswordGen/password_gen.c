#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    unsigned int password_len;

    printf("Enter Length of password: ");
    scanf("%d",&password_len);
    if (password_len < 7)
    {
        printf("Password must be more than 6, %d entered\n", password_len);
        return (1);
    }

    char *password = malloc(password_len + 1);
    char *digits = "0123456789";
    int digits_len = strlen(digits);

    char *lowers = "qwertyuiopasdfghjklzxcvbnm";
    int lowers_len = strlen(lowers);

    char *uppers = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int uppers_len = strlen(uppers);

    char *symbols = "!#&";
    int symbols_len = strlen(symbols);

    srand(time(NULL) * getpid());

    int i;

    for (i = 0; i < password_len; i++)
    {
        int char_type = rand() % 4;

        if (char_type == 0)
        {
            password[i] = digits[rand() % digits_len];
        }
        else if (char_type == 1)
        {
            password[i] = lowers[rand() % lowers_len];
        }
        else if (char_type == 2)
        {
            password[i] = uppers[rand() % uppers_len];
        }
        else
        {
            password[i] = symbols[rand() % symbols_len];
        }
    }
    password[password_len] = '\0';

    printf("Your password is\n");
    printf("%s\n", password);

    free(password);
    return (0);
}