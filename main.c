#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int pass=1234;
int ch=0,ch0=0,ch9=0,test=0,test1=0,tst=0,vcard=0,chqk,alchk,tp;
char tran[50];

SYSTEMTIME t;
struct date{
int dd,mm,yyyy;
};

struct {
    int empid;
    char name[60];
    int acc_no;
    char address[60];
    double phone;
    double panno;
    double addno;
    struct date dob;
    char acc_type[15];
    char passwd[15];
    char prof[15];
    float amt;
    struct date deposit;
    struct date withdraw;
}add,upd,check,rem,transaction,cust;

void add_acc(void){

do{
int choice,acno=10000;
FILE *ptr;
GetSystemTime(&t);
ptr=fopen("Record.dat","a+");
check.acc_no=acno;


while(fscanf(ptr,"%d %s %s %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s %s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type,add.passwd)!=EOF)
    {
    if(check.acc_no==add.acc_no){


        while(check.acc_no==add.acc_no){
            check.acc_no++;
        }
    }
   }
add.acc_no=check.acc_no;
printf("\n\nyour account no is     : %d", add.acc_no);
acno++;
printf("\nenter customer name    :");
scanf("%s",add.name);
printf("\nenter customer address :");
scanf("%s",add.address);
printf("\nenter mob_no           :");
scanf("%lf",&add.phone);
printf("\nenter add_no           :");
scanf("%lf",&add.addno);
printf("\nenter dob (dd/mm/yyyy)  :");
scanf("%d%d%d",&add.dob.dd,&add.dob.mm,&add.dob.yyyy);
printf("\namount of deposit      :");
scanf("%f",&add.amt);
printf("%d/%d/%d %d:%d",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute);
printf("\ntype of account\n\t#saving\n\t#current\n\t#fixed1(for 1 year)\n\t#fixed2(for 2 years)\n\t#fixed3(for 3 years)\n\n\tenter your choice:");
scanf("%s",add.acc_type);
printf("\nPls set the  Password   :");
scanf("%s",add.passwd);


printf("your acc_type is %s", add.acc_type);

    fprintf(ptr,"%d\t\t%s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type, add.passwd);


     fclose(ptr);
     printf("\naccount created successfully!");

printf("Enter 1 For go to Main Menu Or 0 For Exit");
scanf("%d",&ch);
if(ch==1){

    ch=2;
    main();
}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();
}


}while(ch==2);
}

void view(void)
{
    system("cls");
    FILE *view;
    view=fopen("Record.dat","r");

    printf("Acc_No\t\tName\t\tAddress\t\tPhone No\t\tDOB\t\tACC_Opening Date");

    while(fscanf(view,"%d %s %s %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s %s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type, add.passwd)!=EOF)
    {
    ch9=1;
        printf("\n%d\t\t%s\t\t%s\t\t%lf\t\t%d/%d/%d\t\t%d/%d/%d\n",add.acc_no,add.name,add.address,add.phone,add.dob.dd,add.dob.mm,add.dob.yyyy,t.wDay,t.wMonth,t.wYear);
   }
    if(ch9==0){
        printf("\n\t\t\t\t\t\t!!!No Record Found!!!");
    }
    fclose(view);
    printf("\n\n\t\t\t\t\tEnter [1] For Go to Menu And [0] For Exit");
    scanf("%d",&ch9);
    if(ch9==1){
            ch=2;
        main();
    }else{
    close();}
}


void upinfo1()
{
    int test=1;
    FILE *old, *newrec;
    old=fopen("Record.dat","r");
    newrec=fopen("new.dat","w");
    upd.acc_no=check.acc_no;
    if(alchk!=8){
    printf("Enter the Account No  :");
    scanf("%d",&upd.acc_no);
    }
    while(fscanf(old,"%d %s %s %lf %lf  %d/%d/%d %f %d/%d/%d %d:%d %s%s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type,add.passwd)!=EOF)
    {
    if(upd.acc_no==add.acc_no)
        {
            test=3;
            printf("Enter 1 for Update the Address And 2 for Phone No.  ");
            scanf("%d",&ch);

            if(ch==1){
                printf("Enter the New Address");
                scanf("%s",upd.address);
                    fprintf(newrec,"       %d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, upd.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type, add.passwd);
                                      printf("\n\n Address Updated  successfully!");
            } else
                {
                    printf("Enter the New Phone_No. ");
                    scanf("%lf",&upd.phone);
                     fprintf(newrec,"       %d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, upd.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type,add.passwd);
                                      printf("\n\Phone_No Updated successfully!");
                }

        }else{
           fprintf(newrec,"       %d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type, add.passwd);
                  }

   }
   fclose(old);
   fclose(newrec);
    remove("Record.dat");
    rename("new.dat","Record.dat");

    if(test!=3){
        printf("!!!Record Not Found!!!");
    }
        printf("\n Press 1 for Main Menu and 0 For Exit");
        scanf("%d",&ch);
        if(ch==1){
                if(alchk!=8){
                       ch=2;
           main();
                }else{
                ch=3;
                main();
                }

        }else{
        close();
        }


}

void transact(void)
{
    system("cls");
    int test=1;
    FILE *old, *newrec, *transact;
    old=fopen("Record.dat","r");
    newrec=fopen("new.dat","w");
    transact=fopen("Transactions.dat","a+");
    transaction.acc_no=check.acc_no;
    if(alchk!=8){
    printf("Enter the Account No  :");
    scanf("%d",&transaction.acc_no);
    }
    while(fscanf(old,"%d %s %s %lf %lf  %d/%d/%d %f %d/%d/%d %d:%d %s%s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type, add.passwd)!=EOF)
    {
    if(add.acc_no==transaction.acc_no)
        {
            test=3;
           if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    ch=2;
                    main();
                }
             printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&ch);
            if(ch==1){
                printf("Enter the Amount You Want to Deposit:Rs.");
                scanf("%f/-",&transaction.amt);
                 char tran[50] = "Deposited_On";
                 add.amt+=transaction.amt;
                    fprintf(newrec,"%d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type,add.passwd);
                    fprintf(transact,"%d\t%f\t%s\t%d/%d/%d %d:%d  %f\n",add.acc_no,transaction.amt,tran,t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,add.amt);
                    printf("\n\nDeposited successfully!");
            } else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    char tran[50] = "Withdrawn_at";
                   // add.tran[20]= "Withdrawn_at";
                    add.amt-=transaction.amt;
                     fprintf(newrec,"%d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type,add.passwd);
                    fprintf(transact,"%d\t%f\t%s\t%d/%d/%d %d:%d  %f\n",add.acc_no,transaction.amt,tran,t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,add.amt);
                    printf("\n\nWithdrawn successfully!");
                }

        }else{
           fprintf(newrec,"%d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type,add.passwd);
                  }

   }
   fclose(old);
   fclose(newrec);
   fclose(transact);
    remove("Record.dat");
    rename("new.dat","Record.dat");

    if(test!=3)
    {
        printf("\n\t\t\t!!! Record not found");
    }

  printf("\n\tEnter 1 For go to Main Menu Or 0 For Exit");
scanf("%d",&ch);
if(ch==1){
    if(alchk!=8){
        ch=2;
    main();
    }else{
    ch=3;
    main();
    }

}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();

}
}

void  remacc(void)
{
tst=1;
test=0;
    FILE *old, *newrec;
    old=fopen("Record.dat","r");
    newrec=fopen("new.dat","w");

    printf("Enter the Account No of customer For Remove it");
    scanf("%d",&rem.acc_no);
    while(fscanf(old,"%d %s %s %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s%s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type,add.passwd)!=EOF)
    {
        if(add.acc_no!=rem.acc_no)
        {
             fprintf(newrec,"       %d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type,add.passwd);
        }else{
            test=1;

            printf("\n\n\t\t\t\t\tRecord Deleted Successfully!\n");
        }
    }

     fclose(old);
   fclose(newrec);
    remove("Record.dat");
    rename("new.dat","Record.dat");

    if(test==0){
        printf("\n\t\t\t!!!This Account Already Does Not Exist\n");
    }
        printf("Enter 1 For Go to Main Menu And 0 For Exit");
        scanf("%d",&test1);
        if(test1==1)
        {
            ch=2;
            main();
        }else if(test1==0)
        {
           close();
        }
        else{
        printf("!!!Invalid Input");
       close();
        }



}

void Checkdet()
{
     system("cls");
    FILE *view;
    view=fopen("Record.dat","r");

    printf("Enter the [1] For Display perticular Account Details And [0] for All");
    scanf("%d",&ch9);

    if(ch9!=1){
    printf("Acc_No\t\tName\t\tAddress\t\tPhone_No\t\tAdd_No\t\tPan_No\t\tDOB\t\tBalance\t\tToday Time\t\tAcc_Type\n");

    while(fscanf(view,"%d %s %s %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type, add.passwd)!=EOF)
    {

        printf("\n%d\t\t%s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type);

  }
  }else if(ch9==1){

        printf("Enter the Account_No");
        scanf("%d",&check.acc_no);

          printf("Acc_No\t\tName\t\tAddress\t\tPhone_No\t\tAdd_No\t\tPan_No\t\tDOB\t\tBalance\t\tToday Time\t\tAcc_Type\n");

    while(fscanf(view,"%d %s %s %lf %lf  %d/%d/%d %f %d/%d/%d %d:%d %s%s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type,add.passwd)!=EOF)
    {
        if(add.acc_no==check.acc_no){
        printf("\n%d\t%s\t%s\t%lf\t%lf\t%d/%d/%d\t%f\t%d/%d/%d %d:%d\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type);
       ch0=5;
        }
    }
    if(ch0!=5)
    {
    printf("This Account No Does not Exist");
    ch0=0;
    }

  }
  fclose(view);
      printf("Enter 1 For go to Main Menu Or 0 For Exit");
scanf("%d",&ch);
if(ch==1){

    vcard=1;
    main();
}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();
}


}
void addemp()
{
  do{

FILE *ptr;
int choice,acno1=100;
check.empid=acno1;

ptr=fopen("EmpRecord.dat","a+");
GetSystemTime(&t);


while(fscanf(ptr,"%d %s %s %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s",&cust.empid,cust.name, cust.address, &cust.phone,&cust.addno,&cust.dob.dd,&cust.dob.mm,&cust.dob.yyyy, &cust.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, cust.prof)!=EOF)
    {

       if(check.empid==cust.empid){
           while(check.empid==cust.empid){
            check.empid++;

        }
        }

   }
cust.empid=check.empid;
printf("\n\nEmp ID               : %d", cust.empid);

printf("\nEnter Employee name    :");
scanf("%s",cust.name);
printf("\nenter Employee address :");
scanf("%s",cust.address);
printf("\nEnter mob_no           :");
scanf("%lf",&cust.phone);
printf("\nEnter add_no           :");
scanf("%lf",&cust.addno);
printf("\nEnter dob (dd/mm/yyyy)  :");
scanf("%d%d%d",&cust.dob.dd,&cust.dob.mm,&cust.dob.yyyy);
printf("\nSalary Account      :");
scanf("%f",&cust.amt);
printf("%d/%d/%d %d:%d",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute);
printf("\nEnter the Job Profile");
scanf("%s",cust.prof);

printf("your Job Profile is %s", cust.prof);

    fprintf(ptr,"%d %s %s %lf %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s\n",cust.empid,cust.name, cust.address, cust.phone,cust.addno,cust.panno,cust.dob.dd,cust.dob.mm,cust.dob.yyyy, cust.amt, t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute, cust.prof);
    printf("\nNew Joining is successfully done!");


     fclose(ptr);
     cust.empid++;

printf("Enter 1 For go to Main Menu Or 0 For Exit");
scanf("%d",&ch);
if(ch==1){

    vcard=1;
    main();
}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();
}


}while(ch==2);
ch=1;
tst=1;
}

void  rememp(void)
{
    system("cls");
tst=1,test=0;
    FILE *old, *newrec;
    old=fopen("EmpRecord.dat","r");
    newrec=fopen("Empnew.dat","w");

    printf("Enter the Empid Of Employee to Remove it");
    scanf("%d",&rem.empid);
  while(fscanf(old,"%d %s %s %lf %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s",&cust.empid,cust.name, cust.address, &cust.phone,&cust.addno,&cust.panno,&cust.dob.dd,&cust.dob.mm,&cust.dob.yyyy, &cust.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, cust.prof)!=EOF)
  {
        if(cust.empid!=rem.empid)
        {
      fprintf(newrec,"\n       %d %s %s %lf %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s",cust.empid,cust.name, cust.address, cust.phone,cust.addno,cust.panno,cust.dob.dd,cust.dob.mm,cust.dob.yyyy, cust.amt, t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute, cust.prof);

        }else{
            test=1;

            printf("\n\n\t\t\t\t\tRecord Deleted Successfully!\n");
        }
    }
       fclose(old);
   fclose(newrec);
      remove("EmpRecord.dat");
    rename("Empnew.dat","EmpRecord.dat");

    if(test==0){
        printf("\n\t\t\t!!!This EmpId Already Does Not Exist\n");
    }
     printf("Enter 1 For go to Main Menu Or 0 For Exit");
scanf("%d",&ch);
if(ch==1){

    vcard=1;
    main();
}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();
}



}

void saldist(){
  FILE *old, *newrec, *transact;
    old=fopen("EmpRecord.dat","r");
    newrec=fopen("Empnew.dat","w");
    transact=fopen("EmpSalary.dat","a+");

    printf("Enter Employee ID  :");
    scanf("%d",&transaction.empid);

    while(fscanf(old,"%d %s %s %lf %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s",&cust.empid,cust.name, cust.address, &cust.phone,&cust.addno,&cust.panno,&cust.dob.dd,&cust.dob.mm,&cust.dob.yyyy, &cust.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, cust.prof)!=EOF)
  {
    if(cust.empid==transaction.empid)
        {
            test=1;

                printf("Enter the Salary:Rs.");
                scanf("%f/-",&transaction.amt);

                 cust.amt+=transaction.amt;
                     fprintf(newrec,"\n       %d %s %s %lf %lf  %d/%d/%d %f %d/%d/%d %d:%d %s",cust.empid,cust.name, cust.address, cust.phone,cust.addno,cust.dob.dd,cust.dob.mm,cust.dob.yyyy, cust.amt, t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute, cust.prof);
                    fprintf(transact,"\n%d %s %d/%d/%d %f ",cust.empid,cust.name,t.wDay,t.wMonth,t.wYear,cust.amt);
                    printf("\n\n Process successfully Done!");
                    break;
            }
    }
      fclose(old);
   fclose(newrec);
   fclose(transact);
    remove("EmpRecord.dat");
    rename("Empnew.dat","EmpRecord.dat");

    if(test== 0)
        {printf("!!!Record Not Found!!! ");
        }

    printf("Enter 1 For go to Main Menu Or 0 For Exit");
scanf("%d",&ch);
if(ch==1){

    vcard=1;
    main();
}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();
}

}



void transfer(void)
{
    system("cls");
    int test=1;
    FILE *old, *newrec, *transact;
    old=fopen("Record.dat","r");
    newrec=fopen("new.dat","w");
    transact=fopen("Transactions.dat","a+");
    transaction.acc_no=check.acc_no;

    printf("Enter the Account No of Recipient :");
    scanf("%d",&transaction.acc_no);

    while(fscanf(old,"%d %s %s %lf %lf  %d/%d/%d %f %d/%d/%d %d:%d %s%s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type, add.passwd)!=EOF)
    {
    if(add.acc_no==transaction.acc_no)
        {
            test=3;
           if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT TRANSFER MONEY TO FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    ch=2;
                    main();
                }
                printf("Enter the Amount You Want to TRANSFER :Rs.");
                scanf("%f/-",&transaction.amt);
                 char tran[50] = "Transfered to";
                 add.amt+=transaction.amt;
                    fprintf(newrec,"%d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type,add.passwd);
                    fprintf(transact,"%d\t%f\t%s\t%d\t%d/%d/%d %d:%d  %f\n",check.acc_no,transaction.amt,tran,add.acc_no,t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,add.amt);

                     tran[50] = "Received from";

                    fprintf(transact,"%d\t%f\t%s\t%d\t%d/%d/%d %d:%d  %f\n",add.acc_no,transaction.amt,tran,check.acc_no,t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,add.amt);

                    printf("\n\Process Successfully Done!");
            }
        else{
           fprintf(newrec,"%d\t      %s\t\t%s\t\t%lf\t\t%lf\t\t%d/%d/%d\t\t%f\t\t%d/%d/%d %d:%d\t\t%s\t\t%s\n",add.acc_no,add.name, add.address, add.phone,add.addno,add.dob.dd,add.dob.mm,add.dob.yyyy, add.amt, t.wDay,t.wMonth,t.wYear,t.wHour, t.wMinute, add.acc_type,add.passwd);
                  }
    }

   fclose(old);
   fclose(newrec);
   fclose(transact);
    remove("Record.dat");
    rename("new.dat","Record.dat");

    if(test!=3)
    {
        printf("\n\t\t\t!!! Record not found");
    }

  printf("\n\tEnter 1 For go to Main Menu Or 0 For Exit");
scanf("%d",&ch);
if(ch==1){
    if(alchk!=8){
        ch=2;
    main();
    }else{
    ch=3;
    main();
    }

}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();

}
}

/**
void bankstat1()
{
    system("cls");
FILE *old;
old=fopen("Transactions.dat","r");

printf("Enter the Account No Off Which Transactions Need To Display\n\t\t");
scanf("%d",&check.acc_no);
printf("Account_No   Transacted Amount  transaction  Date-type   Current Balance");

  while(fscanf(old,"%d%f%s%d/%d/%d %d%d%f",&add.acc_no,&transaction.amt,tran,&t.wDay,&t.wMonth,&t.wYear,&t.wHour,&t.wMinute,&add.amt)!=EOF)
  {
      if(check.acc_no==add.acc_no){

        printf("%d\t%f\t%s\t%d/%d/%d %d:%d  %f\n",add.acc_no,transaction.amt,tran,t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,add.amt);
test=3;
      }

  }


  if(test!=3){
     printf("No Any Transaction Done Yet");
      printf("\n\n\t\t\t!!!Record Not Found!!!");
  }
  fclose(old);


    printf("Enter 1 For go to Main Menu Or 0 For Exit");
scanf("%d",&ch);
if(ch==1){

    vcard=1;
    main();
}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();
}


}*/
void bankstat()
{
    system("cls");
FILE *old;
old=fopen("Transactions.dat","r");
test=1;
      if(alchk!=8){
    printf("Enter the Account No Off Which Transactions Need To Display\n\t\t");
    scanf("%d",&check.acc_no);
    }


printf("Account_No   Transacted Amount  transaction-type  Date-Time  Current Balance");

  while(fscanf(old,"\t%d%f\t\t%s\t%d/%d/%d %d:%d  %f\n",&add.acc_no,&transaction.amt,tran,&t.wDay,&t.wMonth,&t.wYear,&t.wHour,&t.wMinute,&add.amt)!=EOF)
  {
        if(check.acc_no==add.acc_no)
        {
      printf("\n\t%d\t%f\t%s\t%d/%d/%d %d:%d  %f\n",add.acc_no,transaction.amt,tran,t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,add.amt);
        test=3;
        }
    }
  if(test!=3){
     printf("\nNo Any Transaction Done Yet");
      printf("\n\n\t\t\t!!!Record Not Found!!!");
  }
  fclose(old);


    printf("\nEnter 1 For go to Main Menu Or 0 For Exit\t\t");
scanf("%d",&ch);
if(ch==1){
        if(alchk!=8){
            vcard=1;
    main();
        }else{
        ch=3;
        main();
        }

}else if(ch==0){
close();
}else{
printf("!!!Invalid Option");
close();
}
}


float interest(float t,float amount,int rate)
{
    float si;
    si=(rate*t*amount)/100.0;
    return (si);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

int main()
{
    int ch2,i=1;

    if(test==0 && ch==0){
    printf("\n\n\t\t\t\t\t\t\t\t*****  welcome to the pro_bank  *****");
    printf("\n\n\t\t\t\t\t\t\t\t*****          login as         *****");

    printf("\n\n\t\t\t\t\t\t\t        *****     1.admin 2.employee 3.customer  *****\n\n\t\t\t\t\t\t\t\t\t\t");
     scanf("%d",&ch);
    }



    if(ch==1 && vcard!=1){

        system("cls");
        do{
        if(tst==0){
        printf("\n\n\t\t\t\t\t\t\t\t*****  welcome to the pro_bank  *****");
        printf("\n\n\t\t\t\t\t\t\t\t*****    enter  the  password   ***** \n\t\t\t\t\t\t\t\t\t        *****\n\t\t\t\t\t\t\t\t\t\t");
        scanf("%d",&pass);

        if(pass==1234 && i<4){
                pass=1;
                printf("\n\n\t\t\t\t\t\t\t\t\tpassword match!\n\n\t\t\t\t\t\t\t\tloading");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);

            printf(". ");
        }
        printf("\n");
                system("pause");
				system("cls");
        }  else{
                        printf("\n\n\t\t\t\t\t\t\t\tpassword does not match!\n\n\t\t\t\t\t\t\t\ttry again");
                        test1++;
                        i++;
                      }

        }}while(i<4);

                    if(i==3){
                        printf("\n\n\t\t\t\t\t\t\t\tsorry you can not get access!\n\n\t\t\t\t\t\t\t\ttry again");
                        test1=5;
                        close();
                      }
    }
        if(pass==1 || vcard==1){

        system("cls");
        printf("\n\n\t\t*****  [1].cheque acc_details [2].add_employee [3].rem_employee [4].Salary Dist  [5].Bank Statement  *****\n");
            scanf("%d",&ch2);


            switch(ch2)
            {
            case 1:
                {
                    Checkdet();
                }
            case 2:
                {
                    addemp();
                }
            case 3:
                {
                    rememp();
                }
            case 4:
                {
                    saldist();
                }
             case 5:
                {
                    bankstat();
                }
            case 6:
                {

                }
            }
        }

    else if(ch==2 ){

        system("cls");
        printf("\n\n\t\t      *****  1.new_account 2.transaction 3.rem_account 4.update_info 5.view_costomers  *****\n");
         scanf("\n\n\t\t\t\t\t\t\t\t%d",&ch0);

            switch(ch0)
            {
            case 1:
                {
                    add_acc();
                }
            case 2:
                {
                    transact();
                }
            case 3:
                {
                    remacc();
                }
            case 4:
                {
                    upinfo1();
                }
             case 5:
                {
                    view();
                }
            }

    }else if(ch==3){

 system("cls");
 FILE *old;
old=fopen("Record.dat","r");
    if(ch0==2 && tp!=8){
        printf("\n\n\t\t      *****  1.Log-in 2.Sign_In  *****\n");
        scanf("\n\n\t\t\t\t\t\t\t\t%d",&ch0);

                 printf("\n\n\t\t      *****  Enter Account No *****\n");
                 scanf("\t\t%d",&check.acc_no);
                 printf("\n\n\t\t      *****  Enter Account Password *****\n");
                 scanf("\t\t%s",&check.passwd);
        }
        if(ch0==2){

  while(fscanf(old,"%d %s %s %lf %lf %d/%d/%d %f %d/%d/%d %d:%d %s %s",&add.acc_no,add.name, add.address, &add.phone,&add.addno,&add.dob.dd,&add.dob.mm,&add.dob.yyyy, &add.amt, &t.wDay, &t.wMonth, &t.wYear, &t.wHour, &t.wMinute, add.acc_type,add.passwd)!=EOF)
  {
        chqk=strcmp(add.passwd,check.passwd);
        if(check.acc_no==add.acc_no)
        {
            alchk=8;
            tp=8;
       printf("\n\n\t\t      *****  1.transaction 2.update_info 3.Transfer 4.view Transactions *****\n");
         scanf("\n\n\t\t\t\t\t\t\t\t%d",&ch0);

            switch(ch0)
            {
            case 1:
                {
                    transact();
                }
            case 2:
                {
                    upinfo1();
                }
            case 3:
                {
                    transfer();
                }
             case 4:
                {
                    bankstat();
                }
            }
            }else if(ch0==1){
                add_acc();
            }
        }

        }


    }else{
    printf("\n\n\t\t\t\t\t\t\t\t          invalid! input\n\t\t\t\t\t\t\t\t      press 1 for try again and 0 for colse \n\n\t\t\t\t\t\t\t\t\t\t");
    scanf("%d", &ch2);
    if(ch2==1){

    ch2=1;
    system("cls");
    }
    else{
        close();
    }
    }

}
