#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"

int main()
{
    int choice;
    add_trains();
    while(1)
    {
        choice=enterchoice();
        switch(choice)
        {

                case 1:
                    {
                        view_trains();
                        break;
                    }
                case 2:
                    {
                        clrscr();
                        int ticket_no;
                        struct Passenger *ps;
                        ps=get_passenger_details();
                        if(ps!=NULL)
                        {
                            ticket_no=book_ticket(*ps);
                            if(ticket_no!=0)
                            {
                                printf("\nReservation Successfully done..... ");
                                printf("\nYour ticket nummber is: %d",ticket_no);
                            }
                        }
                        getch();
                        break;
                    }
                case 3:
                    {
                        int ticket_no;
                        do
                        {
                        ticket_no=accept_ticket_no();
                        if(ticket_no!=0)
                            view_ticket(ticket_no);
                        getch();
                        }while(ticket_no!=0);
                        getch();
                        break;
                    }
                case 4:
                    {
                        char *contact_no;
                        int *ticket_no;
                        do
                        {

                        clrscr();
                        contact_no=accept_contact_no();
                        if(contact_no!=NULL)
                        {
                            ticket_no=get_ticket_no(contact_no);
                            view_all_tickets(contact_no,ticket_no);
                        }
                        getch();

                        }while(contact_no!=NULL);
                        break;
                    }
                case 5:
                    {
                        clrscr();
                        view_all_bookings();
                        getch();
                        break;
                    }
                case 6:
                    {
                        char *train_no;
                        do
                        {

                        clrscr();
                        train_no=accept_train_no();
                        if(train_no!=NULL)
                            view_booking(train_no);

                        }while(train_no!=NULL);

                        break;
                    }
                case 7:
                    {
                        int ticket_no;
                        do{
                        ticket_no=accept_ticket_no();
                        if(ticket_no!=0)
                            cancel_ticket(ticket_no);
                        getch();
                        }while(ticket_no!=0);

                        break;

                    }
                case 8:
                    {
                        char *train_no;
                        do{
                        clrscr();
                        train_no=accept_train_no();
                        if(train_no!=NULL)
                        {
                            int found;
                            found=check_train_no(train_no);
                            if(found==1)
                                cancel_train(train_no);
                        }
                        getch();
                        }while(train_no!=NULL);

                        break;
                    }
                case 9:
                    {
                        exit(0);

                    }
                default:
                    {
                        textcolor(LIGHTRED);
                        printf("\nWRONG CHOICE ! TRY AGAIN");
                        printf("\nENTER ANY KEY...");
                        _getch();
                        clrscr();

                    }
        }
        fflush(stdin);

    }
    _getch();
    return 0;
}
