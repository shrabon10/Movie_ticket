#include<stdio.h>   //standard header
#include<string.h>  //header for using string
#include<stdlib.h>  //header for using file
#include<windows.h> //header for using sleep()

struct booker_information   //structure for customer (booker) information
{
    char u_name[100];
    char u_phone[11];
    char u_mail[100];
    char u_address[200];
}var;

char movie_1[] = "Hawa";  //declaring strings as global for easy changing when necessary
char movie_2[] = "Din : The Day";
char movie_3[] = "Top Gun : Maverick";
char movie_4[] = "Bullet Train";
char movie_5[] = "Orphan : First Kill";

char upmov_1[] = "Avatar : The Way of Water";
char upmov_2[] = "Black Panther : Wakanda Forever";
char upmov_3[] = "Black Adam";
char upmov_4[] = "Blonde";
char upmov_5[] = "Pinocchio";

char time_1[] = "10.00 AM";
char time_2[] = "11.30 AM";
char time_3[] = "1.30 PM";
char time_4[] = "3.00 PM";
char time_5[] = "4.30 PM";
char time_6[] = "6.00 PM";
char time_7[] = "7.30 PM";
char time_8[] = "9.00 PM";

char dim_1[] = "IMAX";
char dim_2[] = "3D";
char dim_3[] = "2D";

char request[1000];

void cur_mov();     //function for showing current movies
void upc_mov();     //function for showing upcoming movies
void time_sel();    //function for showing show times

int main(){
    FILE *fp1;
    fp1 = fopen("tick_info.txt", "a+");
    FILE *fp2;
    fp2 = fopen("request_info.txt", "a+");
    int pass;
    char user[50];
    login_prompt:
    printf("\n\n----Please login first ----\n");    //Login part
    printf("\nEnter your username = ");
    scanf("%s", &user);
    printf("Enter your password (default is 123) = ");
    scanf("%d", &pass);
    if (pass != 123)
    {
        printf("Enter a valid password to login\n");
        goto login_prompt;
    }
    else if (pass == 123)
    {
        system("cls");
        int user_in, time, dim, ticket, mov, pay_amount, bank_num, bank_pin;
        printf("\n\nLogin successful\nWelcome\n");
        Sleep(1000);
        system("cls");
        main_menu:  // primary menu with every function
        system("cls");
        printf("\nFTN CINEPLEX\n");
        printf("Online Ticket Booking Portal\n");
        printf("Type the corresponding number to your requirements\n");
        printf("<1> - Currently Showing Movie List\n");
        printf("<2> - Ticket Booking\n");
        printf("<3> - Upcoming Movie Premiers\n");
        printf("<4> - Movie Request to Re-Screen or Premier\n");
        printf("<5> - Exit\n");
        printf("\nEnter your input = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 1:         //currently showing section
            system("cls");
            menu1:
            printf("\nCurrently Showing - \n");
            cur_mov();
            printf("\nType '0' to return to main menu\n");
            printf("\nType '1' to go to ticket booking \n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 0:         //returns to main menu
                goto main_menu;

            case 1:         //switches to ticket booking
                goto menu2;

            default:           //returns to currently showing
                printf("Enter valid number\n");
                goto menu1;
            }
        case 2:             //ticket booking section
            system("cls");
            menu2:
            printf("\nTicket Booking - \n");
            printf("\nType the corresponding movie number to book ticket\n");
            cur_mov();
            printf("\nType '0' to return to main menu \n");
            printf("\nEnter your input = "); //movie selection
            scanf("%d", &mov);
            switch (mov)    //movie selection storing
            {
            case 1:
                goto dim_select_des;

            case 2:
                goto dim_select_des;

            case 3:
                goto dim_select_des;

            case 4:
                goto dim_select_des;

            case 5:
                goto dim_select_des;

            case 0:
                goto main_menu;

            default:
                printf("\nEnter a valid number\n");
                goto menu2;
            }
            dim_select_des:
            system("cls");
            printf("\nWhich dimension you would like to see the movie in?\n"); //descending sort
            printf("\nEnter the corresponding number for the dimension (price sorted in descending order) \n");
            printf("\n<1> - IMAX ------- 1000 Tk\n");
            printf("\n<2> - 3D   -------  500 Tk\n");
            printf("\n<3> - 2D   -------  300 Tk\n");
            printf("\nEnter 0 to sort the prices in ascending order\n");
            printf("\nEnter your input = ");
            scanf("%d", &dim);
            if (dim==0)
            {
                dim_select_asc:
                system("cls");
                printf("\nWhich dimension you would like to see the movie in?\n"); //ascending sort
                printf("\nEnter the corresponding number for the dimension (price sorted in ascending order) \n");
                printf("\n<1> - 2D   -------  300 Tk\n");
                printf("\n<2> - 3D   -------  500 Tk\n");
                printf("\n<3> - IMAX ------- 1000 Tk\n");
                printf("\nEnter 0 to sort the prices in descending order\n");
                printf("\nEnter your input = ");
                scanf("%d", &dim);
                if (dim==0)
                {
                    goto dim_select_des;
                }
                else if (dim==1)
                {
                    dim=3;
                }
                else if (dim==3)
                {
                    dim = 1;
                }
                if (dim<0 || dim>3 )
                {
                printf("\nEnter a valid input\n");
                goto dim_select_asc;
                }
            }
            if (dim<0 || dim>3 )
            {
                printf("\nEnter a valid input\n");
                goto dim_select_des;
            }
            system("cls");
            printf("\nEnter the corresponding time for the show\n");  //time select
            time_sel();
            printf("\nEnter your input = ");
            scanf("%d", &time);
            system("cls");
            printf("\nEnter the number of tickets for the show = ");  //ticket select
            scanf("%d", &ticket);
            system("cls");
            printf("\nEnter personal information\n"); //personal info
            printf("\nEnter your name = ");
            scanf("%s", &var.u_name);
            printf("\nEnter your phone number = ");
            scanf("%s", &var.u_phone);
            printf("\nEnter your email address = ");
            scanf("%s", &var.u_mail);
            printf("\nEnter your current address = ");
            scanf("%s", &var.u_address);
            if (dim == 1)
            {
                pay_amount = 1000 * ticket;
            }
            else if (dim == 2)
            {
                pay_amount = 500 * ticket;
            }
            else if (dim == 3)
            {
                pay_amount = 300 * ticket;
            }
            printf("\nTotal payable money = %d Tk\n", pay_amount);
            before_pay:     //going to payment
            printf("\nType 1 to go for payment\n");
            printf("\nType 0 to cancel booking and return to main menu\n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 1:
                goto pay;

            case 0:
                goto main_menu;

            default:
                printf("\nEnter a valid number");
                goto before_pay;
            }
            pay:
            system("cls");
            printf("\nAmount to pay = %d Tk\n", pay_amount);
            printf("\nEnter your mobile banking account number = ");
            scanf("%d", &bank_num);
            printf("\nEnter your account pin number = ");
            scanf("%d", &bank_pin);
            printf("\nTransaction successful\n");
            Sleep(1000);
            printf("\nTicket Booking Confirmed\n");     //booking confirmation
            Sleep(1000);
            system("cls");
            printf("\n\nBooking Details --- \n\n");
            fprintf(fp1,"\n\nBooking Details --- \n\n");
            switch (mov)
            {
            case 1:
                printf("\nMovie Name = %s\n", movie_1);
                fprintf(fp1, "\nMovie Name = %s\n", movie_1);
                goto show_time;

            case 2:
                printf("\nMovie Name = %s\n", movie_2);
                fprintf(fp1, "\nMovie Name = %s\n", movie_2);
                goto show_time;

            case 3:
                printf("\nMovie Name = %s\n", movie_3);
                fprintf(fp1, "\nMovie Name = %s\n", movie_3);
                goto show_time;

            case 4:
                printf("\nMovie Name = %s\n", movie_4);
                fprintf(fp1, "\nMovie Name = %s\n", movie_4);
                goto show_time;

            case 5:
                printf("\nMovie Name = %s\n", movie_5);
                fprintf(fp1, "\nMovie Name = %s\n", movie_5);
                goto show_time;

            default:
                goto show_time;
            }
            show_time:
            switch (time)
            {
            case 1:
                printf("\nShow time = %s\n", time_1);
                fprintf(fp1, "\nShow time = %s\n", time_1);
                goto dimension;

            case 2:
                printf("\nShow time = %s\n", time_2);
                fprintf(fp1, "\nShow time = %s\n", time_2);
                goto dimension;

            case 3:
                printf("\nShow time = %s\n", time_3);
                fprintf(fp1, "\nShow time = %s\n", time_3);
                goto dimension;

            case 4:
                printf("\nShow time = %s\n", time_4);
                fprintf(fp1, "\nShow time = %s\n", time_4);
                goto dimension;

            case 5:
                printf("\nShow time = %s\n", time_5);
                fprintf(fp1, "\nShow time = %s\n", time_5);
                goto dimension;

            case 6:
                printf("\nShow time = %s\n", time_6);
                fprintf(fp1, "\nShow time = %s\n", time_6);
                goto dimension;

            case 7:
                printf("\nShow time = %s\n", time_7);
                fprintf(fp1, "\nShow time = %s\n", time_7);
                goto dimension;

            case 8:
                printf("\nShow time = %s\n", time_8);
                fprintf(fp1, "\nShow time = %s\n", time_8);
                goto dimension;

            default:
                goto dimension;
            }
            dimension:
            switch (dim)
            {
            case 1:
                printf("\nDimension = %s\n", dim_1);
                fprintf(fp1, "\nDimension = %s\n", dim_1);
                goto tick_info;

            case 2:
                printf("\nDimension = %s\n", dim_2);
                fprintf(fp1, "\nDimension = %s\n", dim_2);
                goto tick_info;

            case 3:
                printf("\nDimension = %s\n", dim_3);
                fprintf(fp1, "\nDimension = %s\n", dim_3);
                goto tick_info;

            default:
                goto tick_info;
            }
            tick_info:
            printf("\nTicket Amount = %d\n", ticket);
            fprintf(fp1, "\nTicket Amount = %d\n", ticket);
            printf("\n\nBuyer Details ---\n\n");
            fprintf(fp1, "\n\nBuyer Details ---\n\n");
            printf("\nName = %s\n", var.u_name);
            fprintf(fp1, "\nName = %s\n", var.u_name);
            printf("\nPhone Number = %s\n", var.u_phone);
            fprintf(fp1, "\nPhone Number = %s\n", var.u_phone);
            printf("\nE-mail address = %s\n", var.u_mail);
            fprintf(fp1, "\nE-mail address = %s\n", var.u_mail);
            printf("\nAddress = %s\n", var.u_address);
            fprintf(fp1, "\nAddress = %s\n", var.u_address);
            fprintf(fp1, "--------------------End of booking\n");
            after_booking:
            printf("\nType '0' to return to main menu\n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 0:         //returns to main menu
                goto main_menu;

            default:           //returns to tick_info
                printf("\nEnter valid number\n");
                goto after_booking;
            }

        case 3:     //upcoming section
            menu3:
            system("cls");
            printf("\nUpcoming Movie Premiers - \n");
            printf("\n1. ''%s''\n", upmov_1);
            printf("\n2. ''%s''\n", upmov_2);
            printf("\n3. ''%s''\n", upmov_3);
            printf("\n4. ''%s''\n", upmov_4);
            printf("\n5. ''%s''\n", upmov_5);
            printf("\nType '0' to return to main menu\n");
            printf("\nType '1' to request movie premier outside this list\n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 0:         //returns to main menu
                goto main_menu;

            case 1:
                goto menu4;

            default:           //returns to upcoming
                printf("\nEnter valid number\n");
                goto menu3;
            }
        case 4:     //request section
            menu4:
            system("cls");
            printf("\nEnter the name of the movie you would like us to premier or rescreen = ");
            scanf("%s", &request);
            fprintf(fp2, "%s\n", request);
            fprintf(fp2, "--------------------End of request\n");
            printf("\nYour request was recorded\n");
            Sleep(1000);
            system("cls");
            menu4_n:
            printf("\nType '0' to return to main menu\n");
            printf("\nType '1' to enter new request\n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 0:         //returns to main menu
                goto main_menu;

            case 1:
                goto menu4;

            default:           //returns to input
                printf("\nEnter valid number\n");
                goto menu4;
            }
        case 5:
            system("cls");
            printf("\nThank You\n");
            Sleep(1000);
            return 0;
        default:
            system("cls");
            printf("\nEnter a valid input\n");
            Sleep(1000);
            goto main_menu;
        }
    }
}

void cur_mov(){
    printf("\n1. ''%s''\n", movie_1);
    printf("\n2. ''%s''\n", movie_2);
    printf("\n3. ''%s''\n", movie_3);
    printf("\n4. ''%s''\n", movie_4);
    printf("\n5. ''%s''\n", movie_5);
}

void upc_mov(){
    printf("\n1. ''%s''\n", upmov_1);
    printf("\n2. ''%s''\n", upmov_2);
    printf("\n3. ''%s''\n", upmov_3);
    printf("\n4. ''%s''\n", upmov_4);
    printf("\n5. ''%s''\n", upmov_5);
}

void time_sel(){
    printf("\n<1> - 10.00 AM\n");
    printf("\n<2> - 11.30 AM\n");
    printf("\n<3> - 1.30 PM\n");
    printf("\n<4> - 3.00 PM\n");
    printf("\n<5> - 4.30 PM\n");
    printf("\n<6> - 6.00 PM\n");
    printf("\n<7> - 7.30 PM\n");
    printf("\n<8> - 9.00 PM\n");
}
