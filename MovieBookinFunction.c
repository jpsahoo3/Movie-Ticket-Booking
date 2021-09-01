void insert_details() {

    FILE *fp;
    struct book b;
    printf("Enter Movie Code:\n");
    scanf("%s", b.code);
    printf("Enter Movie Name:\n");
    scanf("%s", b.name);
    printf("Enter Release Date:\n");
    scanf("%s", b.date);
    printf("Enter Ticket Price:\n");
    scanf("%d", &b.cost);

    fp = fopen("data.txt", "a");
    long fsize=0;
    fseek(fp,0,SEEK_END);
    fsize=ftell(fp);
    if (fp == NULL) {
        printf("File not Found.\n");
    } 
    else {
        if(fsize!=0){
            fprintf(fp,"\n%s %s %s %d",b.code,b.name,b.date,b.cost);
        }
        else{
            fprintf(fp,"%s %s %s %d",b.code,b.name,b.date,b.cost);
        }
        printf("Recorded Successfully");
    }
    printf("\n");
    fclose(fp);

}

void find() //find details
{
    struct book b;
    FILE *fp;

    char ch[20];
    printf("Enter Movie Code:");
    scanf("%s", ch);

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File does not exist!");
        exit(1);

    } else {
        while(fgetc(fp)!=EOF)
        {
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.code,ch)==0)
            {
                printf("Record Found\n");
                printf("\n\t\tMovie Name:%s",b.name);
                printf("\n\t\tMovie Date:%s",b.date);
                printf("\n\t\t\nPrice of Ticket:%d",b.cost);
                break;
            }
        }
    }

    fclose(fp);

}

void viewAll() {

   char ch;
   FILE *fp;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File does not exist!");
        exit(1);

    } else {
        printf("%s %s %s %s\n", "Code", "Name", "Date", "Cost");
        while((ch=fgetc(fp))!=EOF)
        {
            printf("%c",ch );    
        }
    }

    fclose(fp);

}
//for ticket booking 

void book_ticket() {
    struct book b;
    FILE *fp;

    FILE *ufp;

    int total_seat, total_amount;
    char name[20], mobile[20];


    char ch; //used in display all movies
    char movie_code[20]; //for searching

    // disply all moives by default for movie code
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File does not exist!");
        exit(1);
    }
    else{
        while((ch=fgetc(fp))!=EOF)
        {
            printf("%c",ch );    
        }
    }
    fclose(fp);
    //display ends
    //printf("\n For Book ticket Choice Movie(Enter Movie Code First Letter Of Movie)\n");
    printf("Enter the movie code :\n");
    scanf("%s", movie_code);

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File does not exist!");
        exit(1);
    }
    else {
        while(fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost)!=EOF)
        {
            if(strcmp(b.code,movie_code)==0){
                printf("Record Found\n");
                printf("\n\t\tCode:%s",b.code);
                printf("\n\t\tMovie Name:%s",b.name);
                printf("\n\t\tMovie Date:%s",b.date);
                printf("\n\t\t\nPrice of Ticket:%d",b.cost);
                break;
            }
            
        }

    }
    printf("\nFill Details");
    printf("\nYour Name: \n");
    scanf("%s", name);
    printf("Mobile Number: \n");
    scanf("%s", mobile);
    printf("The total number of tickets:\n"); 
    scanf("%d", &total_seat);
    
    total_amount=b.cost*total_seat;
    printf("\nENJOY MOVIE \n");
    //total_amount=b.cost*total_seat;
    printf("\n\t\tName:%s",name);
    printf("\n\t\tMobile Number:%s",mobile);
    printf("\n\t\tMovie Name:%s",b.name);
    printf("\n\t\tTotal seats:%d",total_seat);
    printf("\n\t\tCost Per Ticket:%d",b.cost);
    printf("\n\t\tTotal Amount:%d",total_amount);


    ufp = fopen("oldTransaction.txt", "a");
    if(ufp==NULL)
    {
        printf("File does not exist!");
        exit(1);
    }
    else{
        fprintf(ufp,"%s %s %d %d %s %d \n",name,mobile,total_seat,b.cost*total_seat,b.name,b.cost);
        printf("\n Record insert Successfully to the old record file");
    }
    fclose(ufp);
    fclose(fp);

}
//for view all user transactions

void old_record() {
    char ch;
    FILE *fp;
    fp = fopen("oldTransaction.txt", "r");
    if (fp == NULL) {
        printf("File not Found!");
        exit(1);

    } else {
            while((ch=fgetc(fp))!=EOF)
            {
                printf("%c\t",ch);    
            } 
        printf("\n");
    }
    fclose(fp);
}
