#include <stdio.h>
#include <stdlib.h>
#include "macros.h"

//rock paper scissors
bool x_beats_y(const char x, const char y) {
    if (IS_ROCK(x) && IS_SCISSORS(y)) {
        return true;
    } else if (IS_SCISSORS(x) && IS_PAPER(y)) {
        return true;
    } else if (IS_PAPER(x) && IS_ROCK(y)) {
        return true;
    }
    return false;
}

//you win = 6 points, draw = 3 points, you lose = 0 points
int battle_score(const char their_choice, const char your_choice) {
    if(x_beats_y(your_choice, their_choice)) {
        return 6;
    } else if(draws(your_choice, their_choice)) {
        return 3;
    } else {
        return 0;
    }
}

int main(int argc, char** argv) {
    int total_score = 0;
    char your_hand, their_hand;
    char c;

    FILE* fp;
    if (!(fp = fopen(FILE_PATH,"r"))) {
       exit_err("Error opening input file...\n", 1);
    }

    //go through each character and calculate the winners
    while((c = fgetc(fp)) != EOF) {
        if(IS_THEIR_TURN(c)) {
            their_hand = c;
        } else if(IS_YOUR_TURN(c)) {
            your_hand = c;
            total_score += battle_score(their_hand, your_hand);
            total_score += extra_score(your_hand);
        }
    }

    fclose(fp);
    printf("Your score = %d\n", total_score);
    
    return 0;
}