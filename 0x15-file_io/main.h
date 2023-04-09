#ifndef FILE_INPUT_OUT
#define FILE_INPUT_OUT

#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_osabi(unsigned char *e_ident);
void is_elf(unsigned char *elf);
void print_magic(unsigned char *e);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);

#endif
