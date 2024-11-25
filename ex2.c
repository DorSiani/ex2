/******************
Name: Dor Siani
ID: 332019967
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int scnum;
	int running = 1;
	
	while (running){
		printf("Choose an option:\n\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\n\t6. Festival Of Laughter\n\t7. Exit\n");
		scanf("%d", &scnum);
		switch(scnum) {
			case 1: {
				char eyes, nose, mouth;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				int facesize = -1;
				printf("Enter face size:\n");
				scanf("%d", &facesize);
				while ((facesize < 0) || (facesize%2 == 0)) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &facesize);
				}
				printf("%c", eyes);
				for (int i=0;i<facesize;i++){
					printf(" ");
				}
				printf("%c\n", eyes);
				for (int i=0;i<facesize/2+1;i++){
					printf(" ");
				}
				printf("%c\n", nose);
				printf("\\");
				for (int i=0;i<facesize;i++){
					printf("%c", mouth);
				}
				printf("/\n");
				break;
			}
			case 2: {
				int num, sum_right = 0, sum_left = 0;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while (num <= 0){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				while (num >= 10){
					sum_right += num%10;
					int num1 = num, i = 1;
					while (num1 >= 10) {
        				num1 /= 10;
						i *= 10;
    			}
					sum_left += num1;
					num -= num1*i;
					num /= 10;
				}
				if (sum_left == sum_right){
					printf("This number is balanced and brings harmony!\n");
				} else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			}
			case 3: {
				int num, sum = 0;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while (num <= 0){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				for (int i = 1; i <= num/2; i++){
					if (num % i == 0) {
						sum += i;
					}
				}
				(sum > num) ? printf("This number is generous!\n") : printf("This number does not share.\n");
				break;
			}
			case 4: {
				int num, num1, completes = 1, reversed = 0;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while (num <= 0){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				for (int i = 2; i <= num/2; i++){
					if (num % i == 0) {
						completes = 0;
						break;
					}
				}
				if (completes == 1){
					num1 = num;
					while (num != 0) {
						reversed = reversed * 10 + num % 10;
						num /= 10;
					}
					for (int i = 2; i <= reversed/2; i++){
						if (reversed % i == 0) {
							completes = 0;
							break;
						}
					}
				}
				if (completes == 1){
					printf("This number completes the circle of joy!\n");
				} else {
					printf("The circle remains incomplete.\n");
				}
				break;
			}
			case 5: {
				int num, num1, num2;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while (num <= 0){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				printf("Between 1 and %d only these numbers bring happiness: ", num);
				for (int i = 1; i <= num; i++){
					num2 = i;
					if (i == 7){
						printf("7 ");
					}
					while ((num2 > 9)){
						num1 = 0;
						while (num2 > 0){
							num1 += (num2%10)*(num2%10);
							num2 /= 10;
						}
						num2 = num1;
					}
					if (num2 == 1){
						printf("%d ", i);
					}
				}
				printf("\n");
				break;
			}
			case 6: {
				int input_ok = 0;
					char text_smile[100], text_cheer[100];
					int smile, cheer, max;
					printf("Enter a smile and cheer number:\n");
				do {
					scanf(" %[^:]: %d,%[^:]: %d", text_smile, &smile, text_cheer, &cheer);
					int start_smile=0;
					for (int i=0; i<100; i++) {
						if (text_smile[i] != ' ') {
							start_smile = i;
							break;
						}
					}
					int is_smile_text_ok = 0;
					if (text_smile[start_smile] == 's' 
						&& text_smile[start_smile+1] == 'm'
						&& text_smile[start_smile+2] == 'i'
						&& text_smile[start_smile+3] == 'l'
						&& text_smile[start_smile+4] == 'e'
					){
						is_smile_text_ok = 1;
					}

					int start_cheer=0;
					for (int i=0; i<100; i++) {
						if (text_cheer[i] != ' ') {
							start_cheer = i;
							break;
						}
					}
					int is_cheer_text_ok = 0;
					if (text_cheer[start_cheer] == 'c' 
						&& text_cheer[start_cheer+1] == 'h'
						&& text_cheer[start_cheer+2] == 'e'
						&& text_cheer[start_cheer+3] == 'e'
						&& text_cheer[start_cheer+4] == 'r'
					){
						is_cheer_text_ok = 1;
					}


					if (is_smile_text_ok&& is_cheer_text_ok && (smile > 0)&&(cheer > 0)){
						input_ok = 1;
					} else {
						printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					}
				}while (!input_ok);

				input_ok = 0;
				printf("Enter maximum number for the festival:\n");
				do {
					scanf(" %d", &max);
					if (max > 0){
						input_ok = 1;
					}else {
						printf("Only positive maximum number is allowed, please try again:\n");
					}
				}while (!input_ok);

				for (int i = 1; i <= max; i++){
					if (i % smile == 0){
						if (i % cheer == 0){
							printf("Festival!\n");
						}else{
							printf("Smile!\n");
						}
					}else if (i % cheer == 0){
							printf("Cheer!\n");
						}else{
							printf("%d\n", i);
						}
					
				}

				break;
			}
			case 7: {
				printf("Thank you for your journey through Numeria!\n");
				running = 0;
				break;
			}
			default: {
				printf("This option is not available, please try again.\n\n");
			}
		}
	}
	
    
	return 0;
}
