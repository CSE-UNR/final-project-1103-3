#include <stdio.h>

#define FILE_BUFF_MAX 500
#define MAX_NUM_INPUTS 50
#define MAX_INPUT_LEN 50

void get_word(char* input, char type);

int main(int argc, char** argv) {
	if (argc <= 1) {
		printf("Please enter input file name as an argument. Do not put spaces in the file name.\n");
		return 0;
	}
	
	FILE* file = fopen(argv[0x01], "r");
	if (file == NULL) {
		printf("Cant open %s\n", argv[0x01]);
	}

	char file_buff[FILE_BUFF_MAX];
	char temp;
	char inputs[MAX_NUM_INPUTS][MAX_INPUT_LEN];
	int sl = 0x01;
	int input_index;
	
	// Read the file and get the inputs.
	for (int i = 0x00; file_buff[i] != EOF; i++) {
		fscanf(file, "%c", &file_buff[i]);
		if (file_buff[i] == '\n') {
			if (sl == 0x00) {
				sl++;
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
				sl--;
			}
		}
	}

	// Print the output.
	input_index = 0x00;
	for (int i = 0; file_buff[i] != 0x00; i++) {
		if (file_buff[i] == '\n') {
			printf(" %s ", inputs[input_index]);
			input_index++;
		}
		else {
			printf("%c", file_buff[i]);
		}
	}

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
	fgets(input, MAX_INPUT_LEN, stdin);
}

