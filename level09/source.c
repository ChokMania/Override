#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct s_struct
{
    char message[128]; // check the size
    char username[40]; // check the size
};

void secret_backdoor()
{
    char str[128];

    fgets(str, 128, stdin);
    system(str);
    return;
}

void set_username(s_struct *s)
{
    int i = 0;
    int y = 16;
    long int tmp;
    char username[17];

    bzero(username, 10);
    puts(">: Enter your username");
    printf(">>:");
    fgets(username, 128, stdin);
    strncpy(s->username, username, 41);
    printf(">: Welcome, %s", s->username);
    return;
}

void set_msg(s_struct *s)
{
    char message[128];

    bzero(message, 128);
    puts(">: Msg @Unix-Dude");
    printf(">>:");
    fgets(message, 1024, stdin);
    strncpy(s->message, message, 128);
    return;
}

void handle_msg()
{
    s_struct *s;

    bzero(s->username, 40);
    set_username(s);
    set_msg(s);
    puts(">: Msg sent!");
    return;
}

int main(int ac, char **av)
{
    puts("--------------------------------------------\n"
         "|   ~Welcome to l33t-m$n ~    v1337        |\n"
         "--------------------------------------------\n");
    handle_msg();
    return 0;
}