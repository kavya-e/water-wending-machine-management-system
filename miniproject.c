#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct user
{
 char user_name[20];
 char password[20];
 char phone_no[20];
 int  min_balance;
 char date[11];
 char time[20];
};


void registration();
//void login();
void take_water_using_smartcard();
void unregister();
void recharge();
void show_balance();        // this function show balance in the smart card to the user
void take_water_using_coins();
void check_user_details();       // this function show balance in the smart card to the owner
void displayAll();
void display_less_balance();


char fname[]={"mydatabase2.dat"};

int main()
{
 int ch,n;
 int c=0;
 while(1)
 {
   system("cls");
   printf("\t\t\t\t********************************************************");
   printf("\n\t\t\t\t*       WATER VENDING MACHINE MANAGEMENT SYSTEM       *");
   printf("\n\t\t\t\t********************************************************");
   printf("\n\n\n\t\t\t\t1. USER\n\n\n\t\t\t\t2. OWNER");
   printf("\n\n\n\n\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
   scanf("%d",&n);
   if(n==1){
       system("cls");
       printf("\t\t\t###########################################################################");
       printf("\n\t\t\t############                                                 ##############");
       printf("\n\t\t\t############    Water vending machine management System      ##############");
       printf("\n\t\t\t############                                                 ##############");
       printf("\n\t\t\t###########################################################################");
       printf("\n\t\t\t---------------------------------------------------------------------------\n");

         printf("\n\n\n\t\t\t\t1. REGISTER\n\n\t\t\t\t2.TAKE WATER USING SMART CARD\n\n\t\t\t\t3.SHOW BALANCE IN SMART CARD\n\n\t\t\t\t4.UNREGISTER\n\n\n\n\n\n\t\t\t\tNot a registered user ???\n\t\t\t\tPRESS '5' TO TAKE WATER USING COINS ");
         printf("\n\n\n\n\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
         scanf("%d",&ch);

         switch(ch)
         {
                     case 1: system("cls");
                             registration();
                             break;
                     /*case 2: system("cls");
                             login();
                             break; */
                     case 2: system("cls");
                             take_water_using_smartcard();
                             break;
                     case 3: system("cls");
                             show_balance();
                             break;


                     case 4: system("cls");
                             unregister();
                             break;

                     case 5: system("cls");
                             take_water_using_coins();
                             break;

                     default: printf("\n\n\t\t\t\tINVALID CHOICE\n\n");
                             exit(0);
         }
         exit(0);
 }
 else if(n==2){
     char pass[10]="owner",password[10];
     int choice;
     system("cls");

     exa:
     printf("\n\n\t\t\t\tENTER PASSWORD  :");
     scanf("%s",password);
     if(strcmp(pass,password)==0){
         printf("\n\n\n\t\t\t==================================================================================================\n\n");
         printf("\n\n\t\t\t\t\t\tYOU'VE LOGGED IN SUCCESSFULLY\n\n");

         printf("\n\n\n\t\t\t\t1. CHECK USER DETAILS\n\n\t\t\t\t2. RECHARGE SMART CARD\n\n\t\t\t\t3. DISPLAY ALL USER DETAILS\n\n\t\t\t\t4. DISPLAY LESS BALANCE USERS\n");
         printf("\n\n\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
         scanf("%d",&choice);
         if(choice==1)
         {
             check_user_details();
             exit(0);
         }
         else if(choice==2)
         {
             recharge();
             exit(0);
         }
         else if(choice==3)
         {
            displayAll();
            exit(0);
         }
         else if(choice==4)
         {
            display_less_balance();
            exit(0);
         }

         else
         {
           printf("\n\n\t\t\t\tINVALID CHOICE\n\n");
           exit(0);
         }


     }
     else{
         printf("\n\n\t\tINCORRECT PASSWORD");
         c++;
         if(c==4){
             printf("\n\n\t\tTOO MANY ATTEMPTS");
             printf("\n\n\t\tTRY LATER");
             exit(0);
         }
         else if(c<4){
             printf("\n\n\t\tTRY AGAIN!!");
             goto exa;
         }

     }

   }
 else{
     printf("\n\n\t\t\t\tINVALID CHOICE\n\n");
     exit(0);
 }

 }

}

void registration()
{
   FILE *fp;
   struct user t1;
   char num[20];
   char uname[20];

   fp=fopen(fname,"a+");

   printf("\n\n\t\t\t\t\tPLEASE ENTER THE FOLLOWING DETAILS TO REGISTER !!");

   pqr:
   printf("\n\n\n\t\t\tENTER USERNAME  : ");
   scanf("%s",uname);

   while(1)
   {
       fread(&t1,sizeof(t1),1,fp);

       if(feof(fp))
       {
           break;
       }
       if(strcmp(t1.user_name,uname)==0)
       {

               printf("\n\n\n\t\t\t USERNAME ALREADY EXISTS. PLEASE ENTER A DIFFERENT USERNAME!!");
               goto pqr;
       }
   }

   strcpy(t1.user_name,uname);

   printf("\n\t\t\tENTER PASSWORD  :");
   scanf("%s",t1.password);

   xy:
   printf("\n\t\t\tENTER PHONE NUMBER  :");
   scanf("%s",num);
   if(strlen(num)!=10)
   {
       printf("\n\t\t\t INVALID NUMBER. PLEASE ENTER THE NUMBER AGAIN !! \n");
       goto xy;
   }
   else if(num[0]=='0')
   {
       printf("\n\t\t\t INVALID NUMBER. PLEASE ENTER THE NUMBER AGAIN !! \n");
       goto xy;
   }
   else
   {
       strcpy(t1.phone_no,num);
   }

   printf("\n\n\n\t\t\tYOUR CARD WILL BE RECHARGED WITH A BALANCE OF Rs 500 ");

   t1.min_balance=500;

   fwrite(&t1,sizeof(t1),1,fp);

   fclose(fp);

   printf("\n\n\t\t\tYOU HAVE SUCCESSFULLY REGISTERED!!\n\n\n");

   exit(0);
}

/*void login()
{
 FILE *fp;
 struct user t;
 char name[20],pass[20];


 int found=0;
 printf("\n\n\t\t\t\tENTER YOUR LOGIN CREDENTIALS !!");
 fp=fopen(fname,"r");

 printf("\n\n\n\t\t\tENTER USERNAME: ");
 scanf("%s",name);

 printf("\n\t\t\tENTER PASSWORD  :");
 scanf("%s",pass);

 while(1)
 {
     fread(&t,sizeof(t),1,fp);

     if(feof(fp))
     {
         break;
     }
     if((strcmp(t.user_name,name)==0) && (strcmp(t.password,pass)==0))
     {

             found=1;
             printf("\n\n\n\t\t\t====================================================================\n\n");
             printf("\n\n\t\t\t\t YOU HAVE LOGGED IN SUCCESSFULLY\n\n");

           //  printf("pw\t\t\t\tphone number is:  \t\t\t balance left in your smartcard :\n\n ");

             printf("%s",t.password);

             printf("\t\t\t\t%lld",t.phone_no);
             printf("\t\t\t\t%d",t.min_balance);

             printf("\n\n\n");

     }
 }
 if(found==0)
 {
     printf("\n\n\t\t\t incorrect login details \n\n\n");
 }
 fclose(fp);

 exit(0);
}
*/
void take_water_using_smartcard()
{
 int litres;
 char name[20],pass[20];
 FILE *fp,*fp1;
 struct user t,t1;

 int found=0,count=0;

 fp=fopen(fname,"r");
 fp1=fopen("temp.dat","w");

 printf("\n\n\n\t\t\t\t\tPLEASE ENTER YOUR LOGIN CREDENTIALS TO TAKE WATER  ");
 printf("\n\n\n\t\t\tENTER USERNAME  : ");
 scanf("%s",name);

 printf("\n\t\t\tENTER PASSWORD  :");
 scanf("%s",pass);

 while(1)
 {
     fread(&t,sizeof(t),1,fp);

     if(feof(fp))
     {
         break;
     }
     if((strcmp(t.user_name,name)==0)&&(strcmp(t.password,pass)==0))
     {
         found=1;
         fflush(stdin);

         printf("\n\n\t\t\t THE COST OF WATER FOR 1 LITRE IS Rs 10\n\n ");

         printf("\t\t\t ENTER THE NUMBER OF LITRES YOU WANT TO TAKE :");
         scanf("%d",&litres);


         printf("\n\t\t\t YOU WILL BE CHARGED : %d",(litres*10));

         if((litres*10)<=t.min_balance)
         {
             printf("\n\n\t\t\t BALANCE IN YOUR SMART CARD BEFORE TAKING WATER IS :  %d",t.min_balance);
             printf("\n\n\t\t\t Rs %d  WILL BE DEDUCTED FROM YOUR SMART CARD",(litres*10));
             printf("\n\n\t\t\t BALANCE IN YOUR SMART CARD AFTER TAKING WATER IS :  %d",(t.min_balance-(litres*10)));

             time_t raw;
             time(&raw);
             struct tm *time_ptr;
             time_ptr = localtime(&raw);

             char current_date[11];
             char current_time [20];
             strftime(current_date, sizeof(current_date), "%m/%d/%Y", time_ptr);
             strftime(current_time, sizeof(current_time), "%H:%M:%S", time_ptr);

             strcpy(t.date,current_date);
             strcpy(t.time,current_time);

             printf("\n\n\n\n\t\t\t\t\t\tTHANK YOU\n\n\n\n");


             t.min_balance=t.min_balance-(litres*10);
             fwrite(&t,sizeof(t),1,fp1);
         }
         else
         {

             printf("\n\t\t\t BALANCE IN YOUR SMART CARD IS :  %d",t.min_balance);
             printf("\n\n\t\t\t  THIS AMOUNT IS NOT SUFFICIENT TO TAKE THE WATER YOU REQUESTED. PLEASE RECHARGE YOUR SMART CARD\n\n");
             fwrite(&t,sizeof(t),1,fp1);
         }
     }
     else
     {
         fwrite(&t,sizeof(t),1,fp1);
     }
 }
 fclose(fp);
 fclose(fp1);

 if(found==0)
 {

     printf("\n\n\t\t\t\t\t\t\t SORRY NO RECORD FOUND !!  \n\n\n");

 }
 else
 {
     fp=fopen(fname,"w");
     fp1=fopen("temp.dat","r");

     while(1)
     {
         fread(&t,sizeof(t),1,fp1);

         if(feof(fp1))
         {
             break;
         }
         fwrite(&t,sizeof(t),1,fp);
     }

 }
 fclose(fp);
 fclose(fp1);
 exit(0);
}


void unregister()
{
 char name[20],pass[20];
 FILE *fp,*fp1;
 struct user t,t1;

 int found=0,count=0;

 fp=fopen(fname,"r");
 fp1=fopen("temp.dat","w");

 printf("\n\n\n\t\t\t\t\tPLEASE ENTER YOUR LOGIN CREDENTIALS TO UNREGISTER  ");
 printf("\n\n\n\t\t\tENTER USERNAME: ");
 scanf("%s",name);

 printf("\n\t\t\tENTER PASSWORD  :");
 scanf("%s",pass);


 while(1)
 {
     fread(&t,sizeof(t),1,fp);

     if(feof(fp))
     {
         break;
     }
     if((strcmp(t.user_name,name)==0)&&(strcmp(t.password,pass)==0))
     {
         found=1;
         printf("\n\n\n\t\t\t\t\t YOU HAVE BEEN SUCCESSFULLY UNREGISTERED !! \n\n");
     }
     else
     {
         fwrite(&t,sizeof(t),1,fp1);
     }
 }
 fclose(fp);
 fclose(fp1);

 if(found==0)
 {
     printf("\n\n\t\t\t\t\t SORRY NO RECORD FOUND !!\n\n\n\n");
 }
 else
 {
     fp=fopen(fname,"w");
     fp1=fopen("temp.dat","r");

     while(1)
     {
         fread(&t,sizeof(t),1,fp1);

         if(feof(fp1))
         {
             break;
         }
         fwrite(&t,sizeof(t),1,fp);
     }
 }
 fclose(fp);
 fclose(fp1);
 exit(0);
}

void recharge()
{
 int found=0,count=0,amount;

 char name[20];
 FILE *fp,*fp1;
 struct user t,t1;


 fp=fopen(fname,"r");
 fp1=fopen("temp.dat","w");
 system("cls");
 printf("\n\n\n\t\t\t======================================================================================\n\n");
 printf("\n\n\n\t\t\t\t\t\t\tWELCOME TO RECHARGE ZONE  !! ");
 printf("\n\n\n\t\t\t\t ENTER USERNAME: ");
 scanf("%s",name);





 while(1)
 {
     fread(&t,sizeof(t),1,fp);

     if(feof(fp))
     {
         break;
     }
     if((strcmp(t.user_name,name)==0))
     {
         found=1;
         fflush(stdin);

         printf("\n\t\t\t\t BALANCE IN YOUR SMART CARD BEFORE RECHARGING :  %d",t.min_balance);

         printf("\n\n\t\t\t\t ENTER THE AMOUNT TO RECHARGE :");
         scanf("%d",&amount);

         t.min_balance=t.min_balance+amount;
         printf("\n\n\t\t\t\t AMOUNT IN THE SMART CARD AFTER RECHARGING :  %d",t.min_balance);
         printf("\n\n\n\n\t\t\t\t\t\t\t THANK YOU\n\n\n");
         fwrite(&t,sizeof(t),1,fp1);

     }
     else
     {

         fwrite(&t,sizeof(t),1,fp1);
     }
 }
 fclose(fp);
 fclose(fp1);

 if(found==0)
 {
     printf("\n\n\t\t\t\t\t SORRY NO RECORD FOUND !! \n\n\n\n");
 }
 else
 {
     fp=fopen(fname,"w");
     fp1=fopen("temp.dat","r");

     while(1)
     {
         fread(&t,sizeof(t),1,fp1);

         if(feof(fp1))
         {
             break;
         }
         fwrite(&t,sizeof(t),1,fp);
     }

 }
 fclose(fp);
 fclose(fp1);
 exit(0);
}

void take_water_using_coins()
{
 int l,cash; char num[20];
 FILE *fp;
 fp=fopen("coins_database.txt","a+");

 struct coins{
   char user_name[20];
   char phone_no[20];
 }c;

 printf(" \n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME !!!!\n\n\n\n\n\n");

 printf("\t\t\tENTER YOUR NAME:  ");
 scanf("%s",c.user_name);

 xyz:
 printf("\n\n\t\t\tENTER YOUR PHONE NUMBER:  ");
 scanf("%s",&num);

 if(strlen(num)!=10)
 {
     printf("\n\t\t\t INVALID NUMBER. PLEASE ENTER YOUR NUMBER AGAIN !! \n");
     goto xyz;
 }
 else if(num[0]=='0')
 {
     printf("\n\t\t\t INVALID NUMBER. PLEASE ENTER YOUR NUMBER AGAIN !! \n");
     goto xyz;
 }
 else
 {
     strcpy(c.phone_no,num);
 }

 printf("\n\n\n\n\t\t\t THE COST OF WATER FOR 1 LITRE IS Rs 10\n\n\n");
 printf("\t\t\t HOW MANY LITRES DO WANT TO TAKE   ?  ");
 scanf("%d",&l);
 printf("\n\n\t\t\t PLEASE GIVE Rs %d",(l*10));
 xy:
 printf("\n\n\t\t\t CASH GIVEN  :  ");
 scanf("%d",&cash);

 if(cash<(l*10))
 {
     printf("\n\n\t\t\t SORRY, AMOUNT YOU GAVE US IS NOT SUFFICIENT ! \n\n\t\t\t ENTER THE AMOUNT AGAIN \n  ");
     goto xy;
 }
 else if(cash==(l*10))
 {
     printf("\n\n\t\t\t THANK YOU FOR TAKING WATER FROM US\n\n\n\n ");
     fwrite(&c,sizeof(c),1,fp);
     fclose(fp);
     exit(0);

 }
 else
 {
     printf("\n\n\t\t\t THANK YOU FOR TAKING WATER FROM US ");
     printf("\n\n\t\t\t BALANCE AMOUNT GIVEN BACK TO USER :  %d \n\n\n\n",(cash-(l*10)));
     fwrite(&c,sizeof(struct coins),1,fp);
     fclose(fp);
     exit(0);
 }
}

void show_balance()
{
 int found=0,count=0,amount;

 char name[20],pass[20];
 FILE *fp;
 struct user t;


 fp=fopen(fname,"r");


 printf("\n\n\n\t\t\t\t\tPLEASE ENTER YOUR LOGIN CREDENTIALS TO CHECK BALANCE IN YOUR SMART CARD  ");
 printf("\n\n\n\t\t\tENTER USERNAME: ");
 scanf("%s",name);

 printf("\n\t\t\tENTER PASSWORD  :");
 scanf("%s",pass);



 while(1)
 {
     fread(&t,sizeof(t),1,fp);

     if(feof(fp))
     {
         break;
     }
     if((strcmp(t.user_name,name)==0)&&(strcmp(t.password,pass)==0))
     {

         found=1;
         printf("\n\t\t\tBALANCE IN YOUR SMART CARD IS :  %d\n\n\n\n",t.min_balance);



     }
 }
 fclose(fp);


 if(found==0)
 {
     printf("\n\n\t\t\t\tSORRY, NO RECORD FOUND\n\n\n\n");
 }
 exit(0);

}


void check_user_details(){
 int found=0,count=0,amount,c=0;

 char name[20];
 FILE *fp;
 struct user t4;

 fp=fopen(fname,"r");

 printf("\n\n\n\t\t\t\t\tPLEASE ENTER USERNAME OF ANY CARD USER :  ");
 scanf("%s",name);


 while(1)
 {
     fread(&t4,sizeof(t4),1,fp);

     if(feof(fp))
     {
         break;
     }
     if((strcmp(t4.user_name,name)==0))
     {

         found=1;
         printf("\n\n\t\t\t\t MOBILE NUMBER : %s",t4.phone_no);
         printf("\n\n\t\t\t\t BALANCE LEFT IN  %s 's SMART CARD IS :  %d",name,t4.min_balance);
         printf("\n\n\t\t\t\t CARD WAS LAST USED ON : ");
         printf("\n\n\t\t\t\t DATE : %s",t4.date);
         printf("\n\n\t\t\t\t TIME : %s\n\n\n",t4.time);
         break;

     }
 }
 fclose(fp);


 if(found==0)
 {
     printf("\n\n\t\t\t\t\tSORRY, NO RECORD FOUND !!\n\n\n\n");
 }
 exit(0);
}



void displayAll()
{
    FILE *fp;
    struct user t;

    fp=fopen(fname,"r+");

    printf("\n===========================================================================================================\n\n");
    printf("\t\t\t\t\tALL USER DETAILS :\n\n");
    printf("=============================================================================================================\n\n");



    while(1)
    {
        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
            break;
        }
        printf("\n\n\t\t\t\t USER NAME : %s",t.user_name);
        printf("\n\n\t\t\t\t MOBILE NUMBER : %s",t.phone_no);
        printf("\n\n\t\t\t\t BALANCE LEFT IN  %s 's SMART CARD IS :  %d",t.user_name,t.min_balance);
        printf("\n\n\t\t\t\t CARD WAS LAST USED ON : ");
        printf("\n\n\t\t\t\t DATE : %s",t.date);
        printf("\n\n\t\t\t\t TIME : %s\n\n\n",t.time);

    }
  printf("==============================================================================================================\n\n");

  fclose(fp);
}


void display_less_balance()
{
    FILE *fp;
    struct user t;
    int n;
    int found=0;

    fp=fopen(fname,"r+");

    printf("================================================================================================================================================================\n\n");
    printf("\n\n\n\n\t\t\tenter an amount to display the list of all the users who have less amount than the entered amount in their smartcards :");
    scanf("%d",&n);
    while(1)
    {
        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
            break;
        }

        if(t.min_balance<=n)
        {
        found=1;
        printf("\n\n\t\t\t\t USER NAME : %s",t.user_name);
        printf("\n\n\t\t\t\t MOBILE NUMBER : %s",t.phone_no);
        printf("\n\n\t\t\t\t BALANCE LEFT IN  %s 's SMART CARD IS :  %d",t.user_name,t.min_balance);
        printf("\n\n\t\t\t\t CARD WAS LAST USED ON : ");
        printf("\n\n\t\t\t\t DATE : %s",t.date);
        printf("\n\n\t\t\t\t TIME : %s\n\n\n",t.time);
        }

    }
    if(found==0)
        printf("\n\n\nSORRY, no users found with balance less than %d\n",n);

    printf("================================================================================================================================================================\n\n");

    fclose(fp);
}
