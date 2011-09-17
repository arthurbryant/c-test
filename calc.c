#include <stdio.h>

void calc(int unit)
{
    int s, h, e;
    int sum, square;
    for(h = 1; h <=unit-1; ++h)
        for(e = 0; e <=unit-1; ++e)
        {
            square = (h*unit+e) * (unit*h+e);
            for(s = 1; s <= unit-1; ++s)
            {
                sum = unit*unit*s + unit*h + e;
                //printf("%d != %d\n", square, sum);
                if(square == sum)
                {
                    printf("%d\n", sum);
                    }
            }
        }
}
int main(int argc, char * argv[])
{
    int unit;
    for(unit = 2; unit <= 10; ++unit)
    {
        printf("unit = %d\n", unit);
        calc(unit);
        printf("------------------------");
    }
    return 0;
}
