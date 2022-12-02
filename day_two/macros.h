#define FILE_PATH "input_files/puzzle_input.txt"
#define exit_err(str, code) fprintf(stderr, str); exit(code)

typedef int bool;
#define true 1
#define false 0

#define CPU_ROCK 'A'
#define CPU_PAPER 'B'
#define CPU_SCISSORS 'C'
#define YOUR_ROCK 'X'
#define YOUR_PAPER 'Y'
#define YOUR_SCISSORS 'Z'

#define IS_ROCK(hand) (hand == 'A' || hand == 'X')
#define IS_PAPER(hand) (hand == 'B' || hand == 'Y')
#define IS_SCISSORS(hand) (hand == 'C' || hand == 'Z')

#define IS_YOUR_TURN(hand) (c == YOUR_PAPER || c == YOUR_ROCK || c == YOUR_SCISSORS)
#define IS_THEIR_TURN(hand) (c == CPU_PAPER || c == CPU_ROCK || c == CPU_SCISSORS)

#define extra_score(your_choice) (int) your_choice - 'W'

#define draws(x, y) x - 23 == y || y - 23 == x
