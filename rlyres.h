#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train
{
    char train_no[20];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
struct Passenger
{
    char p_name[20];
    char gender;
    char mob_no[10];
    int age;
    char address[30];
    char train_no[20];
    char p_class;
    int ticketno;

};

typedef struct Train Train;
typedef struct Passenger Passenger;


int enterchoice();
void add_trains();     //add the database of the trains.
void view_trains();    //show the train details.
int book_ticket(Passenger);
int* get_ticket_no(char *); //ascepting pasenger mob. no returning all his ticket no.
int check_train_no(char *);
Passenger *get_passenger_details();
int last_ticket_no();
int check_mob_no(char *);

void view_all_bookings();
void view_ticket(int);

void view_booking(char *);

int accept_ticket_no();
char *accept_contact_no();
char *accept_train_no();

void view_all_tickets(char*,int*);
int cancel_ticket(int);
int cancel_train(char *);

int line();
#endif // RLYRES_H_INCLUDED
