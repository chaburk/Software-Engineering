#include <stdio.h>

void calculate_scores(int total);

int main(){
	int total = 0;
	do{
		printf("Enter 0 or 1 to STOP\n");
		printf("Enter the NFL score: \n");
		scanf("%d", &total);
		if (total == 0 || total == 1){
			break;
		}
		calculate_scores(total);
	}while(total != 0 || total != 1);

	return 0;
}

void calculate_scores(int total){
	int SCORES[5] = {2,3,6,7,8};
	for(int td2 = 0; td2 <= total / SCORES[4]; td2++){
		for(int td1 = 0; td1 <= total / SCORES[3]; td1++){
			for(int td = 0; td <= total / SCORES[2]; td++){
				for(int fg = 0; fg <= total / SCORES[1]; fg++){
					for(int safety = 0; safety <= total / SCORES[0]; safety++){
						if((td2 * SCORES[4])+ (td1 * SCORES[3]) + (td * SCORES[2] + (fg * SCORES[1]) + (safety * SCORES[0])) == total){
							printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, safety);
							}
						}
					}
				}
			}
	}
}
