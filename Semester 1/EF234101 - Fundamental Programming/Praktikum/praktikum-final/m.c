#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ull unsigned long long
#define MAX_SIZE 200000
/* =========================== NOTES =========================
https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/         multiplication big number
https://www.geeksforgeeks.org/how-to-compute-mod-of-a-big-number/                    not helpful stuff but yeah
https://www.geeksforgeeks.org/modulo-power-for-large-numbers-represented-as-strings/ helpful stuff
https://www.geeksforgeeks.org/sum-two-large-numbers/                                 sum of two large numbers
https://www.geeksforgeeks.org/writing-power-function-for-large-numbers/              power for large numbers
   ===========================================================*/

// Function to reverse a string
void revString(char str[])
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move towards the center
        start++;
        end--;
    }
}

// Function for finding sum of larger numbers
char *findSum(const char *str1, const char *str2, char result[])
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (strlen(str1) > strlen(str2))
    {
        const char *temp = str1;
        str1 = str2;
        str2 = temp;
    }

    // Calculate length of both strings
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    // Reverse both strings
    char rev_str1[MAX_SIZE];
    char rev_str2[MAX_SIZE];
    strcpy(rev_str1, str1);
    strcpy(rev_str2, str2);

    revString(rev_str1);
    revString(rev_str2);

    int carry = 0;
    int i;
    for (i = 0; i < n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((rev_str1[i] - '0') + (rev_str2[i] - '0') + carry);
        result[i] = sum % 10 + '0';

        // Calculate carry for the next step
        carry = sum / 10;
    }

    // Add remaining digits of the larger number
    for (; i < n2; i++)
    {
        int sum = ((rev_str2[i] - '0') + carry);
        result[i] = sum % 10 + '0';
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
        result[i++] = carry + '0';

    // Null-terminate the result
    result[i] = '\0';

    // Reverse the resultant string
    revString(result);

    return result;
}

void multiplyStrings(const char *a, const char *b, char result[])
{
    if (a[0] == '0' || b[0] == '0')
    {
        strcpy(result, "0");
        return;
    }

    int m = strlen(a) - 1;
    int n = strlen(b) - 1;
    int carry = 0;

    char product[MAX_SIZE] = ""; // Adjust the size as needed

    for (int i = 0; i <= m + n || carry; ++i)
    {
        for (int j = (i > n) ? i - n : 0; j <= ((i < m) ? i : m); ++j)
        {
            carry += (a[m - j] - '0') * (b[n - i + j] - '0');
        }
        product[i] = carry % 10 + '0';
        carry /= 10;
    }

    revString(product);

    strcpy(result, product);
}

void solve(ull L, ull M, ull K)
{
    char Lstring[20];
    char Mstring[20];
    char Kstring[20];
    snprintf(Lstring, sizeof(Lstring), "%llu", L);
    snprintf(Mstring, sizeof(Mstring), "%llu", M); // convert to string
    snprintf(Kstring, sizeof(Kstring), "%llu", K);
    char ans[MAX_SIZE] = "0";
    for (ull i = M; i <= K; i++)
    {
        char temp1[MAX_SIZE];
        char tempX[MAX_SIZE];
        char one[5] = "1";
        strcpy(temp1, Mstring);
        if (L == 1)
        {
            strcpy(tempX, temp1);
        }
        else
        {
            for (ull j = 0; j < L - 1; j++)
            {
                char temp2[MAX_SIZE];
                strcpy(temp2, temp1);
                multiplyStrings(temp2, Mstring, temp1);
                strcpy(tempX, temp1);
                // printf("%s\n", tempX);
            }
        }
        findSum(tempX, ans, ans);
        findSum(Mstring, one, Mstring);
    }
    printf("%s\n", ans);
}

void debug(ull L, ull M)
{
    char Lstring[20];
    char Mstring[20];
    snprintf(Lstring, sizeof(Lstring), "%llu", L);
    snprintf(Mstring, sizeof(Mstring), "%llu", M); // convert to string
    char ans[MAX_SIZE];
    strcpy(ans, Lstring);
    for (ull i = 0; i < M - 1; i++)
    {
        char temp[MAX_SIZE];
        strcpy(temp, ans);
        multiplyStrings(temp, Lstring, ans);
    }
    printf("%s\n", ans);
}

int main()
{
    ull L, M, K;
    // scanf("%llu %llu", &L, &M);
    // debug(L, M);
    scanf("%llu %llu %llu", &L, &M, &K);
    solve(L, M, K);
    // char a[MAX_SIZE];
    // char b[MAX_SIZE];
    // char result[MAX_SIZE];
    // scanf("%s %s", a, b);
    // findSum(a, b, result);
    // printf("%s\n", result);
    // multiplyStrings(a, b, result);
    // printf("%s\n", result);
    return 0;
}