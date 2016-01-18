#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

static struct option const long_options[] =
{
    {"amount", optional_argument, NULL, 'a'},
    {NULL, 0, NULL, 0}
};

int main(int argc, char** argv) {
    int optc;
    extern char *optarg;

    /* Amount of characters to type before the monkey gets tired and quits.
     * Default monkey never quits.
     */
    int amount = -1;

    while ((optc = getopt_long(argc, argv, "a:", long_options, NULL)) != -1) {
        switch (optc) {
            case 'a':
                amount = atoi(optarg);
                break;
            default:
                printf("No arguments");
        }
    }

    srand(clock());
    int i;
    int current = 0;

    bool running = true;
    while(running)
    {
        current++;

        if (current >= amount && amount != -1) {
            running = false;
        }

        char randomletter = 'a' + (rand() % 27);
        if(randomletter == '{') {
            randomletter = '\n';
        }
        printf("%c", randomletter);
    }
}
