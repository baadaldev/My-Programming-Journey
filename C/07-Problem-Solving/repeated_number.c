#include <stdio.h>

int main()
{
    int n;

    printf("How many numbers: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int found = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                printf("First repeated number = %d\n", arr[i]);
                found = 1;
                break;
            }
        }

        if(found)
        {
            break;
        }
    }

    if(!found)
    {
        printf("No Repeat\n");
    }

    return 0;
}
