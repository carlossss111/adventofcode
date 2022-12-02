#include <stdio.h>
#include <stdlib.h>
#include "macros.h"

#define MUST_LOSE(c) c == 'X'
#define MUST_DRAW(c) c == 'Y'
#define MUST_WIN(c) c == 'Z'

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

int change_hand_and_score(const char their_choice, const char your_choice) {
    if(MUST_DRAW(your_choice)) {
        return 3 + extra_score(their_choice + 23);
    } else if (MUST_WIN(your_choice)) {
        if(x_beats_y(YOUR_PAPER, their_choice))     return 6 + extra_score(YOUR_PAPER);
        if(x_beats_y(YOUR_ROCK, their_choice))      return 6 + extra_score(YOUR_ROCK);
        if(x_beats_y(YOUR_SCISSORS, their_choice))  return 6 + extra_score(YOUR_SCISSORS);
    } else if (MUST_LOSE(your_choice)) {
        if(x_beats_y(their_choice, YOUR_PAPER))     return extra_score(YOUR_PAPER);
        if(x_beats_y(their_choice, YOUR_ROCK))      return extra_score(YOUR_ROCK);
        if(x_beats_y(their_choice, YOUR_SCISSORS))  return extra_score(YOUR_SCISSORS);
    }
    exit_err("Unreachable block reached...\n",1);
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
            //must change hand depending on what you roll
            your_hand = c;
            total_score += change_hand_and_score(their_hand, your_hand);
        }
    }

    fclose(fp);
    printf("Your score = %d\n", total_score);
    
    return 0;
}