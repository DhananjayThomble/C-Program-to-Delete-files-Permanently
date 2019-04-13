#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main()
{
    printf("--------------------------Program to Delete File Permanently------------------\n");
    FILE *fp;

    char file_nm[30];

    printf("Choose the File \n");
     DIR *d;
    struct dirent *dir;
    d = opendir(".");
    char choice;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("\n%s\n", dir->d_name);
            printf("y/n");
            choice = getch();
            if(choice == 'y')
            {
                strcpy(file_nm,dir->d_name);
                fp = fopen(file_nm,"r");
                if(fp == NULL)
                {
                printf("Can not open the file");
                exit(2);
                }
                //Calculates File size
                fseek(fp,0,SEEK_END);
                unsigned long long int file_size;
                file_size = ftell(fp);
                // printf("Size of current file = %llu \n",file_size);
                fseek(fp,0,SEEK_SET);
                fclose(fp);
                // Create dummy file
                deleteFile(file_nm);
                createDummy(file_size,file_nm);
            }
            else{

            }

        }
        closedir(d);
    }


    getch();
    return 0;
}
void deleteFile(char *file_nm)
{
    FILE *fp;
    fp = fopen(file_nm,"r");
    if(fp == NULL)
    {
        printf("Can not open the file");
        exit(2);
    }
    int status;
    fclose(fp);
    status = remove(file_nm);
    if(status == 0)
        printf("File deleted successfully.");
    else
        perror("This error is occurred");
    fclose(fp);
}

void createDummy(unsigned long long int size,char *file_nm)
{
    FILE *fp2;

    fp2 = fopen(file_nm,"w");
    if(fp2 == NULL)
    {
        printf("Can not open the file");
        exit(2);
    }
    char ch;
    for(unsigned long long int i=0;i<size;i++)
    {
        fputc('*',fp2);
    }
    fclose(fp2);
    deleteFile(file_nm);
}

void fun1()
{
    srand(time(0));
    printf("%d",rand());
}
void openFolder()
{
    /*
 * C Program to List Files in Directory
 */


}

