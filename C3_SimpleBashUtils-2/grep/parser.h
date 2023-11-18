#include <ctype.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NMAX 5000
#define MAX_LINE_LEN 5000
#define MAX_MATCHES 10

struct parsing_struct {
  int opt_e;
  int opt_i;
  int opt_v;
  int opt_c;
  int opt_l;
  int opt_n;
  int opt_h;
  int opt_s;
  int opt_f;
  int opt_o;
  int opt_error;

  char* namefiler;
};

void parser_arguments(int argc_pars, char* argv_pars[],
                      struct parsing_struct* my_parser, char* patterns[],
                      int* size, char* files[], int* file_size);

void fun_grep_search(char* namefile, char* pattern, FILE* readparser_file,
                     int count_file);
void fun_e_search(char* namefile, char* pattern[], FILE* readparser_file,
                  int count_file);
void fun_i_ignore_reg(char* namefile, char* pattern, FILE* readparser_file,
                      int count_file);
void fun_v_invert_pattern(char* namefile, char* pattern, FILE* readparser_file,
                          int count_file);
void fun_c_count_str_accord(char* namefile, char* pattern);
void fun_l_acoord_files(char* namefile, char* pattern);
void fun_n_num_str_search(char* namefile, char* pattern);
void fun_h_noname_file(char* namefile, char* pattern);
void fun_o_print_match(char* namefile, char* pattern, int count_file);
void fun_f_search(char* files[], char* file2, int count_file);
void fun_in_count_lower_ignore_reg(char* namefile, char* pattern,
                                   FILE* readparser_file, int count_file);

void fun_cv_count_invert_reg(char* namefile, char* pattern,
                             FILE* readparser_file, int count_file);
void fun_iv_ignore_invert_reg(char* namefile, char* pattern,
                              FILE* readparser_file, int count_file);
void fun_lv_name_invert_reg(char* namefile, char* pattern,
                            FILE* readparser_file, int count_file);
void fun_ho_noname_pattern_reg(char* namefile, char* pattern, int count_file);
void fun_nf_numstr_file_reg(char* files[], char* file_arg_2, int count_file);
