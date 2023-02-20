#include <stdio.h>

int main(void) {
  int score, td, safety, fg, xp, tpc;

  int valid_score;
  valid_score = 0;
  while (valid_score == 0){
    printf("Enter a score: ");
    scanf("%d", &score);
    if (score >= 2) {
      valid_score = 1;
    }
    else {
        printf("Please enter a valid score.\n");
        exit(0);
    }
  }

  for (tpc = 0; tpc <= score / 8; tpc++){
    int remaining = score - tpc * 8;
    for (xp = 0; xp <= remaining / 7; xp++){
      remaining = remaining - xp * 7;
      for (td = 0; td <= remaining / 6; td++) {
        remaining = remaining - td * 6;
          for (fg = 0; fg <= remaining / 3; fg++) {
            remaining = remaining - fg * 3;
            for (safety = 0; safety <= remaining / 2; safety++) {
              remaining = remaining - safety * 2;
              if (tpc * 8 + xp * 7 + td * 6 + fg * 3 + safety * 2) {
                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", tpc, xp, td, fg, safety);
              }
            }
          }
        }
      }
    }
    return 0;
  }