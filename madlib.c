#include <stdio.h>

#define DEFAULT_INPUT_FILE "madlib1.txt"
#define MAX_LINE_LEN 100
#define MAX_NUM_LINES 100

int open_input_file(FILE *input_file, int argc, char **argv);
void load_input_file(FILE *input_file, char file_buff[MAX_NUM_LINES][MAX_LINE_LEN]);
void print_buffer(char buffer[MAX_NUM_LINES][MAX_LINE_LEN]);
void get_words(char buffer[MAX_NUM_LINES][MAX_LINE_LEN]);
void get_word(char* destination, char word_type);

int main(int argc, char **argv) {
  FILE *input_file;
  printf("DEBUG: OPENGING FILE...\n");
  if (argc <= 1) {
    // No arguments were passed into the executable so load the default file
    printf("File not found, reverting to base file.");
    input_file = fopen(DEFAULT_INPUT_FILE, "r");
    if (input_file == NULL) {
      // TODO: Print error message
      return 0;
    }
  } else {
    // An argument was passed into the executable so use it as the filename
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
      // TODO: Print error message
      return 0;
    }
  }

  // Reserve space to load the entire file into.
  char file_buff[MAX_NUM_LINES][MAX_LINE_LEN];
  printf("DEBUG: LOADING FILE...\n");
  new_load_input_file(input_file, file_buff);
  printf("DEBUG: GETTING INPUT...\n");
  get_words(file_buff);
  printf("DEBUG: PRINTING FILE...\n");
  print_buffer(file_buff);
}

int open_input_file(FILE *input_file, int argc, char **argv) {
  if (argc <= 1) {
    // No arguments were passed into the executable so load the default file
    input_file = fopen(DEFAULT_INPUT_FILE, "r");
    if (input_file == NULL) {
      // TODO: Print error message
      printf("File not found, reverting to base file.");
      return 0;
    }
  } else {
    // An argument was passed into the executable so use it as the filename
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
      // TODO: Print error message
      return 0;
    }
  }
  return 1;
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
  switch (word_type) {
    case 'A':
      printf("Enter an Adjective: ");
      scanf("%s", destination);
      break;
    case 'N':
      printf("Enter a Noun: ");
      scanf("%s", destination);
      break;
    case 'V':
      printf("Enter a Verb: ");
      scanf("%s", destination);
      break;
  }
}
