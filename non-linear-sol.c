#include <stdio.h>
#include <math.h>

#define err 0.00000001

double dabs(double x)
{
    if (x>0) return x;
    else return -x;
}
double f(double x)
{
    return pow(x,3) - 2*pow(x,2) + 1;
}

void bisection();
void falpos();

int main(int argc, char const *argv[])
{
    printf("1. Enter 'B' to solve using bisection method\n");
    printf("2. Enter 'F' to solve using false-position method\n");
    printf("3. Enter 'Q' to quit\n");
    printf("\nEnter choice : ");
    char c;
    scanf("%c", &c);
    if (c == 'B') bisection();
    if (c == 'F') falpos();
    if (c == 'Q') return 0;
    else printf("Wrong input\n");
    return 0;
}

void bisection()
{
    int count = 0;
    double x1, x2, xmid;
    printf("\nEnter the two intial guesses : ");
    scanf("%lf%lf", &x1, &x2);
    printf("\nDo you want to see each step?[y/n] : \n");
    char cm;
    while (1)
    {
        while (getchar() != '\n');
        scanf("%c", &cm);
        if ((cm=='y')||(cm=='n')) break;
        else printf("Wrong input\n");
        printf("\n");
    }
    while (count<500)
    {
        xmid = (x1 + x2)/2;
        count++;
        if (dabs(f(xmid)) < err)
        {
            printf("The root is found at iteration no. %-3d and the root is %10lf\n\n", count, xmid);
            return;
        }
        if (cm == 'y') printf("At iteration no. %-3d the value of x is %13.8lf and f(x) is %13.8lf\n", count, xmid, f(xmid));
        if (f(x1)*f(xmid) > 0) x1 = xmid;
        else x2 = xmid;
    }
    printf("The function does not converge with the given intial guesses in 500 iterations\n\n");
}

void falpos()
{
    int count = 0;
    double x1, x2, x;
    printf("\nEnter the two intial guesses : ");
    scanf("%lf%lf", &x1, &x2);
    printf("\nDo you want to see each step?[y/n] : \n");
    char cm;
    while (1)
    {
        while (getchar() != '\n');
        scanf("%c", &cm);
        if ((cm=='y')||(cm=='n')) break;
        else printf("Wrong input\n");
        printf("\n");
    }
    while (count<500)
    {
        x = (x1*f(x2)-x2*f(x1))/(f(x2) - f(x1));
        count++;
        if (dabs(f(x)) < err)
        {
            printf("The root is found at iteration no. %-3d and the root is %10lf\n\n", count, x);
            return;
        }
        if (cm == 'y') printf("At iteration no. %-3d the value of x is %13.8lf and f(x) is %13.8lf\n", count, x, f(x));
        if (f(x1)*f(x) > 0) x1 = x;
        else x2 = x;
    }
    printf("The function does not converge with the given intial guesses in 500 iterations\n\n");
}