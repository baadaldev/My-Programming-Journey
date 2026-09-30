#include<stdio.h>
int main()
{

    int age[2];
    int cgpa[2];
    int i;
    for (int i=0;i<=1;i++){

        printf("Enter your age:");
        scanf("%d",&age[i]);
        printf("Enter your CGPA:");
        scanf("%d",&cgpa[i]);


    }

  printf("All data:\n");
  for(int i=0; i<=1;i++)
  {
      printf("Student %d\n",i+1);
      printf("Age : %d\n",age[i]);
      printf("CGPA: %d\n",cgpa[i]);


  }




    return 0;
}
