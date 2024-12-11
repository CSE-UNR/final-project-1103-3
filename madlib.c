// Authors: Carter Brashear, Raidon Santos, Pearce Robinson
// CS135 final project: madlib
#include <stdio.h>

#define DEFAULT_INPUT_FILE "madlib1.txt"
#define MAX_LINE_LEN 100
#define MAX_NUM_LINES 100

void load_input_file(FILE *input_file, char file_buff[MAX_NUM_LINES][MAX_LINE_LEN]);
void print_buffer(char buffer[MAX_NUM_LINES][MAX_LINE_LEN]);
void get_words(char buffer[MAX_NUM_LINES][MAX_LINE_LEN]);
void get_word(char* destination, char word_type);
void remove_newlines(char file_buff[MAX_NUM_LINES][MAX_LINE_LEN]);

int main(int argc, char **argv) {
  FILE *input_file;
  if (argc <= 1) {
    // No arguments were passed into the executable so load the default file
    input_file = fopen(DEFAULT_INPUT_FILE, "r");
    if (input_file == NULL) {
      printf("ERROR: Failed to open file.");
      return 0;
    }
  } else {
    // An argument was passed into the executable so use it as the filename
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
      printf("ERROR: Failed to open file %s", argv[1]);
      return 0;
    }
  }

  // Reserve space to load the entire file into.
  char file_buff[MAX_NUM_LINES][MAX_LINE_LEN];
  //  printf("DEBUG: LOADING FILE...\n");
  load_input_file(input_file, file_buff);
  //  printf("DEBUG: GETTING INPUT...\n");
  get_words(file_buff);
  //  printf("DEBUG: PRINTING FILE...\n");
  remove_newlines(file_buff);
  print_buffer(file_buff);
}

void load_input_file(FILE *input_file, char file_buff[MAX_NUM_LINES][MAX_LINE_LEN]) {
  for (int i = 0; i < MAX_NUM_LINES; i++) {
    fgets(file_buff[i], MAX_LINE_LEN, input_file);
    if (file_buff[i][0] == '\n' || file_buff[i][0] == '\0') {
      continue;
    }
  }
}

void print_buffer(char buffer[MAX_NUM_LINES][MAX_LINE_LEN]) {
  for (int i = 0; buffer[i][0] != '\0'; i++) {
    printf("%s", buffer[i]);
  }
  printf("\n");
}

void get_words(char buffer[MAX_NUM_LINES][MAX_LINE_LEN]) {
  for (int i = 0; i < MAX_NUM_LINES; i++) {
    switch (buffer[i][0]) {
      case 'A':
      case 'N':
      case 'V':
        // If the line starts with an A N or V and the following character is a newline: then get the word from the user and store it over the same line
        if (buffer[i][1] == '\n') {
          get_word(buffer[i], buffer[i][0]);
        }
      default:
        break;
    }
  }
}

void get_word(char* destination, char word_type) {
  destination[0] = ' ';
  switch (word_type) {
    case 'A':
      printf("Enter an Adjective: ");
      scanf("%s", destination + 1);
      break;
    case 'N':
      printf("Enter a Noun: ");
      scanf("%s", destination + 1);
      break;
    case 'V':
      printf("Enter a Verb: ");
      scanf("%s", destination + 1);
      break;
  }
  // Add space afterwards
  char next_char = *(destination + MAX_LINE_LEN);
  switch (next_char) {
    case '.':
    case ':':
    case '!':
    case ',':
    case ';':
    case '?':
    case '"':
      break;
    default: {
      int i = 0;
      while (destination[i] != '\0') {
        i++;
      }
      destination[i] = ' ';
    }
  }
}

void remove_newlines(char file_buff[MAX_NUM_LINES][MAX_LINE_LEN]) {
  for (int h = 0; h < MAX_NUM_LINES; h++) {
    for (int k = 0; k < MAX_LINE_LEN; k++) {
      if (file_buff[h][k] == '\n') {
        file_buff[h][k] = '\0';
      }
    }
  }
}
