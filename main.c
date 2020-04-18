#include <stdio.h>
#include <stdlib.h>

int main()
{

     int t=0,s,c=0;
     FILE *fp,*fptr;
     char ch;
     int k=0;
     unsigned int num=0;
     unsigned int ar[10010];
     int i=0,j,choice;
     int pizzaslice,pizzatype;
     int arr[10000];
     int arrr[10000];
     char str[15];
     /////Converting data of file into array////
     printf("1)a_example \n");
     printf("2)b_small \n");
     printf("3)c_medium \n");
     printf("4)d_quite_big \n");
     printf("5)e_also_big \n");
     printf("Enter The input data set you want to verify:");
     scanf("%d",&choice);

     switch(choice)
     {
     case 1:
         fp=fopen("C:\\Users\\march\\Documents\\Our Programs\\c\\file handling\\a_example.txt","r");
        break;
    case 2:
        fp=fopen("C:\\Users\\march\\Documents\\Our Programs\\c\\file handling\\b_small.txt","r");
        break;
    case 3:
        fp=fopen("C:\\Users\\march\\Documents\\Our Programs\\c\\file handling\\c_medium.txt","r");
        break;
    case 4:
        fp=fopen("C:\\Users\\march\\Documents\\Our Programs\\c\\file handling\\d_quite_big.txt","r");
        break;
    case 5:
        fp=fopen("C:\\Users\\march\\Documents\\Our Programs\\c\\file handling\\e_also_big.txt","r");
        break;
        default:
        exit(0);

     }

    if(fp==NULL)
        printf("Sorry");
    while(1)
    {
        ch=fgetc(fp);
        k=ch;
        if(k==EOF)
           break;
          else
            {
               if(ch>=48&&ch<=57)
                    num=num*10+(ch-'0');

                if(ch==' ')
                {
                    ar[i]=num;
                    num=0;
                    i++;
                }
                if(ch=='\n')
                {
                    ar[i]=num;
                    num=0;
                    i++;
                }
            }
    }
    pizzaslice=ar[0];
    pizzatype=ar[1];
    for(j=0;j<(i);j++)
    ar[j]=ar[j+1];
    for(j=0;j<(i);j++)
    ar[j]=ar[j+1];
    k=0;
    fclose(fp);
//////Counting/////////////////////////
        for(s=0;s<pizzatype;s++)
        {
            t=t+ar[s];
            arr[k]=s;
            k++;
            if(t>pizzaslice)
                break;
        }
        for(s=0;s<k;s++)
        {
            t=t-ar[s];
            for(j=0;j<k;j++)
                arr[j]=arr[j+1];
            k--;
            if(t<pizzaslice)
            break;
        }
        for(s=0;s<k;s++)
        {
            t=t+ar[s];
            if(t>pizzaslice)
            {
                t=t-ar[s];
                break;
            }
            arrr[c]=c;
            c++;
        }
        fptr=fopen("Output.txt","w");
    printf("%d\n",(c+k));



    itoa((c+k),str,10);
    fputs(str,fptr);
    fputs("\n",fptr);


    for(s=0;s<c;s++)
       {
           itoa(arrr[s],str,10);
           fputs(str,fptr);
          fputs(" ",fptr);
           printf("%d ",arrr[s]);

       }
    for(s=0;s<k;s++)
    {
        itoa(arr[s],str,10);
        fputs(str,fptr);
           fputs(" ",fptr);
           printf("%d ",arr[s]);
    }
fclose(fptr);
    return 0;
}
