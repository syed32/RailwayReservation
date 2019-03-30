#include<stdio.h>
#include "conio2.h"
#include "rlyres.h"
#include<ctype.h>
#include<string.h>

int enterchoice()
{
    int choice ;
    clrscr();
    textcolor(YELLOW);
    line();
    printf("\n");
    gotoxy(28,2);
    printf("RAILWAY RESERVATION SYSTEM\n");
    line();
    printf("\nSELECT AN OPTION");
    printf("\n\n1-VIEW TRAINS\n2-BOOK TICKETS\n3-VIEW TICKETS\n4-SEARCH TICKET NUMBER\n5-VIEW ALL BOOKINGS\n6-VIEW TRAIN BOOKING\n7-CANCEL TICKET\n8-CANCEL TRAIN\n9-QUIT");
    printf("\n\nENTER CHOICE: ");
    scanf("%d",&choice);
    if(choice>=1&&choice<=9)
        return choice;
    else
        return -1;
}
void add_trains()
{
    FILE *fptr;
    fptr=fopen("c:\\myproject\\alltrains.dat","rb");
    if(fptr==NULL)
    {
        Train alltrains[4]=
        {
            {"123","BPL","GWA",2100,1500},
            {"546","BPL","DEL",3500,2200},
            {"345","HBJ","AGR",1560,1135},
            {"896","HBJ","MUM",4500,3360},
        };
        fptr=fopen("c:\\myproject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fptr);
        fclose(fptr);
    }
    else
    {
        fclose(fptr);

    }
}
void view_trains()
{
    FILE *fptr;
    fptr=fopen("c:\\myproject\\alltrains.dat","rb");
    if(fptr==NULL)
    {
        textcolor(RED);
        printf("\nCANNOT OPEN FILE..");
    }
    else
    {
         clrscr();
         Train alltrains[4];
         fread(alltrains,4*sizeof(Train),1,fptr);
         int i;
         line();

         textcolor(YELLOW);
         printf("\n\tTRAIN_NO\tFROM\tTO\tFIRST_AC_FAIR\tSECOND_AC_FAIR\n");

         line();

         for(i=0;i<4;i++)
            printf("\n\t%s\t\t%s\t%s\t%d\t\t%d",alltrains[i].train_no,alltrains[i].from,alltrains[i].to,alltrains[i].fac_fare,alltrains[i].sac_fare);
         printf("\n\n");
         line();
    }
    fclose(fptr);
    textcolor(WHITE);
    printf("\nPress Any Key To Go Back To The Main Screen......");
    getch();
    clrscr();
}
int check_train_no(char *train_no)
{
    FILE *fptr;
    fptr=fopen("c:\\myproject\\alltrains.dat","rb");
    if(fptr==NULL)
    {
        textcolor(RED);
        printf("\nFILE CANNOT OPEN");
    }
    else
    {
        Train tr;
        while(fread(&tr,sizeof(tr),1,fptr)==1)
        {
            if(strcmp(tr.train_no,train_no)==0)
                return 1;
        }

    }
    fclose(fptr);
    return -1;
}

Passenger *get_passenger_details()
{
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("PRESS 0 TO EXIT");
    gotoxy(1,1);
    textcolor(YELLOW);

    printf("ENTER PASSENGER NAME: ");
    rep0:
    fflush(stdin);
    static Passenger psn;
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strlen(psn.p_name)<=0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("ENTER VALID NAME");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        gotoxy(1,18);
        printf("\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t");
        textcolor(YELLOW);
        gotoxy(17,3);
        printf("\t\t\t\t");
        gotoxy(18,3);
        goto rep0;
    }
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,24);
        textcolor(LIGHTRED);
        printf("RESERVATION CANCELLED");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    printf("ENTER GENDER(M/F): ");
    rep1:
    fflush(stdin);
    scanf("%c",&psn.gender);
    if(psn.gender!='m' && psn.gender!='f')
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        if(psn.gender=='0')
        {
            printf("RESERVATION CANCELLED");
            textcolor(WHITE);
            printf("\nPRESS ANY KEY TO CONTINUE..");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        printf("ENTER VALID GENDER");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        gotoxy(1,18);
        printf("\t\t\t\n");
        printf("\t\t\t\t");
        textcolor(YELLOW);
        gotoxy(19,2);
        printf("\t\t");
        gotoxy(19,2);
        goto rep1;
    }
    printf("ENTER MOBILE NO: ");
    rep2:
    scanf("%s",&psn.mob_no);
    if(strcmp(psn.mob_no,"0")==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("RESERVATION CANCELLED");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int z;
    z=check_mob_no(psn.mob_no);
    if(z==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("ENTER VALID MOBILE NUMBER");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        gotoxy(1,18);
        printf("\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t");
        textcolor(YELLOW);
        gotoxy(17,3);
        printf("\t\t\t\t");
        gotoxy(18,3);
        goto rep2;
    }

    printf("ENTER AGE: ");
    rep3:
    scanf("%d",&psn.age);
    if(psn.age==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("RESERVATION CANCELLED");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    if(psn.age<1)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("ENTER VALID AGE");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();

        gotoxy(1,18);
        printf("\t\t\t\n");
        printf("\t\t\t\t");
        textcolor(YELLOW);
        gotoxy(12,4);
        printf("\t\t");
        gotoxy(12,4);
        goto rep3;
    }

    printf("ENTER ADDRESS: ");
    fflush(stdin);
    gets(psn.address);
    if(psn.address=='0')
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("RESERVATION CANCELLED");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        return NULL;
    }

    int x;
    printf("ENTER TRAIN NO: ");
    rep4:
    scanf("%s",&psn.train_no);
    if(strcmp(psn.train_no,"0")==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("RESERVATION CANCELLED");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    x=check_train_no(psn.train_no);

    if(x==-1)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("ENTER VALID TRAIN NUMBER");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        gotoxy(1,18);
        printf("\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t");
        textcolor(YELLOW);
        gotoxy(17,6);
        printf("\t\t");
        gotoxy(17,6);
        goto rep4;
    }

    printf("ENTER CLASS (F-FIRST_AC / S-SECOND_AC): ");
    rep5:
    fflush(stdin);
    scanf("%c",&psn.p_class);
    if(psn.p_class=='0')
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("RESERVATION CANCELLED");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    if(psn.p_class!='f' && psn.p_class!='s')
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("ENTER VALID CLASS");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        gotoxy(1,18);
        printf("\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t");
        textcolor(YELLOW);
        gotoxy(40,7);
        printf("\t\t\t");
        gotoxy(41,7);
        goto rep5;
    }
    return &psn;
}
int check_mob_no(char *ptr)
{
    if(strlen(ptr)!=10)
        return 0;
    while(*ptr!='\0')
    {
        if(isdigit(*ptr)==0)
            return 0;
        ptr++;
    }
    return 1;
}
int get_booked_ticket_count(char *train_no,char train_class)
{
    FILE *fptr;
    fptr=fopen("c:\\myproject\\allbookings.dat","rb");
    if(fptr==NULL)
        return 0;
    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        fclose(fptr);
        remove("c:\\myproject\\allbookings.dat");
        return 0;
    }

        Passenger pr;


        int count=0;
        while(fread(&pr,sizeof(pr),1,fptr)==1)
        {
            if((strcmp(pr.train_no,train_no)==0) && pr.p_class==train_class)
            ++count;
        }
        fclose(fptr);
        return count;

}
int last_ticket_no()
{
    FILE *fptr;
    fptr=fopen("c:\\myproject\\allbookings.dat","rb");
    if(fptr==NULL)
        return 0;
    else
    {
        Passenger psn;
        fseek(fptr,-1*sizeof(psn),SEEK_END);
        fread(&psn,sizeof(psn),1,fptr);
        fclose(fptr);
        return psn.ticketno;
    }
}
int book_ticket(Passenger p)
{
    int total_record=get_booked_ticket_count(p.train_no,p.p_class);
    if(total_record==5)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("RESERVATION FULL ! SEATS NOT AVAILABLE");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY ...");
        getch();
        textcolor(YELLOW);
        return 0;
    }
    else
    {

    int ticket_no=last_ticket_no()+1;
    FILE *fptr;
    p.ticketno=ticket_no;
    fptr=fopen("c:\\myproject\\allbookings.dat","ab");
    if(fptr==NULL)
        return 0;
    fwrite(&p,sizeof(p),1,fptr);
    fclose(fptr);
    return p.ticketno;
    }
}
void view_ticket(int temp)
{
    FILE *fptr;
    int count=0;
    fptr=fopen("c:\\myproject\\allbookings.dat","rb");
    if(fptr==NULL)
        printf("\nFILE CANNOT OPEN");
    else
    {
        Passenger pr;
        while(fread(&pr,sizeof(pr),1,fptr)==1)
        {
            if(pr.ticketno==temp)
            {
                printf("\nNAME\t\t:%s",pr.p_name);
                printf("\nGENDER\t\t:%c",pr.gender);
                printf("\nMOB_NO\t\t:%s",pr.mob_no);
                printf("\nAGE\t\t:%d",pr.age);
                printf("\nADDRESS\t\t:%s",pr.address);
                printf("\nTRAIN_NO\t:%s",pr.train_no);
                printf("\nP_CLASS\t\t:%c",pr.p_class);
                printf("\nTICKET_NO\t:%d",pr.ticketno);

                count++;
            }
        }
        if(count==0)
        {
            gotoxy(1,18);
            textcolor(LIGHTRED);
            printf("\nNO DETAIL OF THE TICKET NUMBER FOUND");
            textcolor(YELLOW);
        }
    }
    gotoxy(1,18);
    textcolor(WHITE);
    printf("\n\nPRESS ANY KEY TO CONTINUE...");
    textcolor(YELLOW);
    fclose(fptr);
}
int accept_ticket_no()
{
        int temp;
        clrscr();
        gotoxy(60,1);
        textcolor(LIGHTGREEN);
        printf("PRESS 0 TO EXIT");
        gotoxy(1,1);
        textcolor(YELLOW);
        printf("ENTER THE TICKET NUMBER: ");
        rep1:
        scanf("%d",&temp);
        if(temp<0)
        {
            gotoxy(1,18);
            textcolor(LIGHTRED);
            printf("ENTER VALID TICKET NUMBER ");
            textcolor(WHITE);
            printf("\nPRESS ANY KEY TO CONTINUE..");
            getch();
            gotoxy(1,18);
            printf("\t\t\t\n");
            printf("\t\t\t\t");
            textcolor(YELLOW);
            gotoxy(26,1);
            printf("\t\t");
            gotoxy(26,1);
            goto rep1;
        }
        if(temp==0)
        {
            gotoxy(1,18);
            textcolor(LIGHTRED);
            printf("ENDING SHOWING TICKET");
            textcolor(WHITE);
            printf("\nPRESS ANY KEY TO CONTINUE..");
            getch();
            textcolor(YELLOW);
            return 0;
        }

        return temp;
}
char* accept_contact_no()
{
    static char mob_no[10];
    clrscr();
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("PRESS 0 TO EXIT");
    textcolor(YELLOW);
    gotoxy(1,3);
    printf("ENTER MOBILE NO: ");
    rep2:
    fflush(stdin);
    scanf("%s",&mob_no);
    if(strcmp(mob_no,"0")==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("CANCELLING INPUT");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int z;
    z=check_mob_no(mob_no);
    if(z==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("ERROR! INVALID MOBILE NUMBER");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        gotoxy(1,18);
        printf("\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t");
        textcolor(YELLOW);
        gotoxy(17,3);
        printf("\t\t\t\t");
        gotoxy(18,3);
        goto rep2;
    }
    return mob_no;
}
char *accept_train_no()
{
    static char train_no[20];
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("PRESS 0 TO EXIT");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("ENTER TRAIN NO: ");
    rep:
    fflush(stdin);
    scanf("%s",train_no);
    if(strcmp(train_no,"0")==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("CANCELLING TAKING INPUT");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int x;
    x=check_train_no(train_no);

    if(x==-1)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("NO DETAIL OF THIS TRAIN NUMBER FOUND");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        gotoxy(1,18);
        printf("\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t");
        textcolor(YELLOW);
        gotoxy(17,1);
        printf("\t\t");
        gotoxy(17,1);
        goto rep;
    }
    return train_no;

}
int* get_ticket_no(char *contact_no)
{
    FILE *fptr;
    fptr=fopen("c:\\myproject\\allbookings.dat","rb");
    if(fptr==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nFILE CANNOT OPEN");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int count=0;
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fptr)==1)
    {
        if(strcmp(pr.mob_no,contact_no)==0)
            ++count;
    }
    if(count==0)
    {
        fclose(fptr);
        return NULL;
    }
    rewind(fptr);
    int *p=(int *)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fptr)==1)
    {
        if(strcmp(pr.mob_no,contact_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fptr);
    return p;
}
void view_all_tickets(char *contact_no,int *ticket_no)
{
    if(ticket_no==NULL)
    {
            gotoxy(1,18);
            textcolor(LIGHTRED);
            printf("SORRY ! NO TICKETS ARE BOOKED AGAINST THIS MOBILE NUMBER");
            textcolor(WHITE);
            printf("\nPRESS ANY KEY TO CONTINUE..");
            getch();
            textcolor(YELLOW);
            return;
    }
    textcolor(YELLOW);
  //  printf("\nFOLLOWING ARE THE TICKETS FOR THE GIVEN MOBILE NUMBER\n");
    line();
    printf("\nTICKETS_NUMBER\n");
    line();
    int i;
    for(i=0;*(ticket_no+i)!=-1;i++)
        printf("\n\t%d",*(ticket_no+i));
    printf("\n");
    line();
    textcolor(WHITE);
    printf("\n\n\n\nPRESS ANY KEY TO CONTINUE...");
    textcolor(YELLOW);
}
void view_all_bookings()
{
    FILE *fptr;
    fptr=fopen("c:\\myproject\\allbookings.dat","rb");
    if(fptr==NULL)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nNO BOOKING DONE YET");
    }
    else
    {
        Passenger pr;
        line();
        printf("\nTRAIN NO\tTICKET NO\tCLASS\tNAME\t\tMOBILE NO\n");
        line();
        int t=4;
        while(fread(&pr,sizeof(pr),1,fptr)==1)
        {
            printf("\n%s\t\t%d\t\t%c\t%s",pr.train_no,pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(57,t);
            printf("%s",pr.mob_no);
            t++;
        }
    }
    fclose(fptr);
    printf("\n");
    gotoxy(1,17);
    line();
    gotoxy(1,18);
    textcolor(WHITE);
    printf("PRESS ANY KEY TO GO BACK TO THE MAIN SCREEN....");
    getch();
}
void view_booking(char *train_no)
{
    FILE *fptr;
    fptr=fopen("c:\\myproject\\allbookings.dat","rb");
    if(fptr==NULL)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nFILE CANNOT OPEN");
        getch();
        textcolor(YELLOW);
        return;
    }
    Passenger pr;
    int count=0;

    while(fread(&pr,sizeof(pr),1,fptr)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
           ++count;
           break;
        }

    }
    if(count==0)
    {
        fclose(fptr);
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("SORRY ! NO TICKETS ARE BOOKED AGAINST THIS TRAIN NUMBER");
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO CONTINUE..");
        getch();
        textcolor(YELLOW);
        fclose(fptr);
        return;
    }


    rewind(fptr);
    printf("\n");
    line();
    printf("\nTICKET NO\tCLASS\tGENDER\tNAME\tAGE\t\tMOBILE NO\n");
    line();
    int t=6;

    while(fread(&pr,sizeof(pr),1,fptr)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            printf("\n%d\t\t%c\t%c\t%d\t%s",pr.ticketno,pr.p_class,pr.gender,pr.age,pr.p_name);
            gotoxy(58,t);
            printf("%s",pr.mob_no);
            t++;
        }
    }

    gotoxy(1,20);
    line();
    gotoxy(1,21);
    printf("\n\nPRESS ANY KEY TO CONTINUE..");
    getch();
}
int line()
{
    int i;
    for(i=1;i<=80;i++)
        printf("-");
    return 0;
}
int cancel_ticket(int ticket_no)
{/*
    FILE *fptr1;
    fptr1=fopen("c:\\myproject\\allbookings.dat","rb");
    if(fptr1==NULL)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nFILE NOT OPEN ");
        return -1;
    }
    FILE *fptr2;
    fptr2=fopen("c:\\myproject\\temp.dat","wb");
    if(fptr2==NULL)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nFILE NOT CREATED ");
        return -1;
    }
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fptr1)==1)
    {
        if(pr.ticketno==ticket_no)
            count++;

        if(pr.ticketno!=ticket_no)
            fwrite(&pr,sizeof(pr),1,fptr2);

        fflush(stdin);
    }
    fclose(fptr1);
    fclose(fptr2);
    if(count==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nSORRY! NO TICEKT BOOKED AGAINST THE TICKET NUMBER");
        textcolor(WHITE);
        printf("\n PRESS ANY KEY TO CONTINUE....");
        remove("c:\\myproject\\temp.dat");
        return -1;
    }
    else
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\n SUCCESSFULLY CANCELLED! ");
        textcolor(WHITE);
        printf("\n PRESS ANY KEY TO CONTINUE....");
        remove("c:\\myproject\\allbookings.dat");
        rename("c:\\myproject\\temp.dat","c:\\myproject\\allbookings.dat");
        return 0;
    }
*/

FILE *fp1=fopen("c:\\myproject\\allbookings.dat","rb+");

  if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }

  FILE *fp2=fopen("c:\\myproject\\temp.dat","wb+");
  Passenger pr;
  int found=0;

  while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
      if(pr.ticketno!=ticket_no)
      {
          fwrite(&pr,sizeof(pr),1,fp2);
      }
      else
      {
          found=1;
      }
    }

    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("c:\\myproject\\temp.dat");
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nSORRY! NO TICEKT BOOKED AGAINST THE TICKET NUMBER");
        textcolor(WHITE);
        printf("\n PRESS ANY KEY TO CONTINUE....");
    }
    else
    {
        remove("c:\\myproject\\allbookings.dat");
        rename("c:\\myproject\\temp.dat","c:\\myproject\\allbookings.dat");
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\n SUCCESSFULLY CANCELLED! ");
        textcolor(WHITE);
        printf("\n PRESS ANY KEY TO CONTINUE....");

    }

return found;



}
int cancel_train(char *train_no)
{
    FILE *fptr1;
    fptr1=fopen("c:\\myproject\\allbookings.dat","rb");
    if(fptr1==NULL)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nFILE NOT OPEN ");
        return -1;
    }
    FILE *fptr2;
    fptr2=fopen("c:\\myproject\\temp.dat","wb");
    if(fptr2==NULL)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nFILE NOT CREATED ");
        return -1;
    }
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fptr1)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
            count++;
        else
            fwrite(&pr,sizeof(pr),1,fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);

    if(count==0)
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\nSORRY! NO TICEKT BOOKED AGAINST THIS TRAIN NUMBER");
        textcolor(WHITE);
        printf("\n PRESS ANY KEY TO CONTINUE....");
        remove("c:\\myproject\\temp.dat");
        return -1;
    }
    else
    {
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("\n SUCCESSFULLY CANCELLED! ");
        textcolor(WHITE);
        printf("\n PRESS ANY KEY TO CONTINUE....");
        remove("c:\\myproject\\allbookings.dat");
        rename("c:\\myproject\\temp.dat","c:\\myproject\\allbookings.dat");
        return 0;
    }

}



