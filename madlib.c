// Author: Pearce Robinson, Raidon Santos, Carter Brashear
// 12/9/2024
// Madlib final project
#include <stdio.h>

#define FILE_BUFF_MAX 5000
#define MAX_NUM_INPUTS 50
#define MAX_INPUT_LEN 50

void get_word(char* input, char type);
void print_result(char* filebuff, char inputs[MAX_NUM_INPUTS][MAX_INPUT_LEN]);
void punctuation_fix(char* filebuff, char inputs[MAX_NUM_INPUTS][MAX_INPUT_LEN], int char_index, int input_index);

int main(int argc, char** argv) {
	if (argc <= 1) {
		printf("Please enter input file name as an argument. Do not put spaces in the file name.\n");
		return 0;
	}
	
	FILE* file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("Cant open %s\n", argv[1]);
	}

	char file_buff[FILE_BUFF_MAX];
	char temp;
	char inputs[MAX_NUM_INPUTS][MAX_INPUT_LEN];
	int odd_line = 1;
	int input_index;
	
	// Read the file and get the inputs.
	int i = 0;
	do {
		fscanf(file, "%c", &file_buff[i]);
		if (file_buff[i] == '\n') {
			if (odd_line == 0) {
				odd_line++;
			}
			else {
				fscanf(file, "%c", &temp);
				switch (temp) {
					case 'A':
						get_word(inputs[input_index], 'A');
						input_index++;
						i--;
						break;
					case 'N':
						get_word(inputs[input_index], 'N');
						input_index++;
						i--;
						break;
					case 'V':
						get_word(inputs[input_index], 'V');
						input_index++;
						i--;
						break;
					default:
						break;
				}
				odd_line--;
			}
		}
		i++;
	} while (file_buff[i] != EOF);

	file_buff[i - 1] = 0;

	
	print_result(file_buff, inputs);

	return 0;
}

void get_word(char* input, char type) {
	switch (type) {
		case 'A':
			printf("Enter an A: ");
			break;
		case 'N':
			printf("Enter an N: ");
			break;
		case 'V':
			printf("Enter an V: ");
			break;
	}
	scanf("%s", input);
}

void print_result(char* filebuff, char inputs[MAX_NUM_INPUTS][MAX_INPUT_LEN]){
	// Print the output.
	int input_index = 0;
	int i = 0;
	do {
		if (filebuff[i] == '\n') {
			punctuation_fix(filebuff, inputs, i, input_index);
			input_index++;
		}
		else {
			printf("%c", filebuff[i]);
		}
		i++;
	} while (filebuff[i] != '\0'); 
	printf("\n");
}

void punctuation_fix(char* filebuff, char inputs[MAX_NUM_INPUTS][MAX_INPUT_LEN], int char_index, int input_index) {
	switch(filebuff[char_index+1]) {
		case '.':
			printf(" %s", inputs[input_index]);
			break;
		case ',':
			printf(" %s", inputs[input_index]);
			break;
		case '!':
			printf(" %s", inputs[input_index]);
			break;
		case '?':
			printf(" %s", inputs[input_index]);
			break;
		default:
			printf(" %s ", inputs[input_index]);
			break;
	}
}

