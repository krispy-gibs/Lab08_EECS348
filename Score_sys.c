

#include <stdio.h>


int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
         return 0; 
        }     
        
        if (score == 1) {
            break;
        }
                              

        if (score < 0) {
            printf("Please enter a non-negative score (or 1 to stop).\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        
        int found = 0;
        for (int td2 = 0; td2 * 8 <= score; ++td2) {
            for (int tdfg = 0; td2 * 8 + tdfg * 7 <= score; ++tdfg) {
                for (int td = 0; td2 * 8 + tdfg * 7 + td * 6 <= score; ++td) {
                    for (int fg = 0; td2 * 8 + tdfg * 7 + td * 6 + fg * 3 <= score; ++fg) {
                        int used = td2 * 8 + tdfg * 7 + td * 6 + fg * 3;
                        int rem = score - used;
                        if (rem < 0) continue;
                        if (rem % 2 == 0) {
                            int safety = rem / 2;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td2, tdfg, td, fg, safety);
                            found = 1;
                        }
                    }
                }
            }
        }

        if (!found) {
            printf("No combinations found.\n");
        }
    }

    return 0;
}

