#include "parser.h"

int main(int argc, char* argv[]) {
  FILE* readparser_file;
  struct parsing_struct option_struct = {0};
  // char search_string[MAX_LINE_LEN] = {0};
  char* patterns[100] = {0};
  char* files[100] = {0};
  int arr_w_pat_size = 0;
  int arr_w_fil_size = 0;

  parser_arguments(argc, argv, &option_struct, patterns, &arr_w_pat_size, files,
                   &arr_w_fil_size);

  int count_file = argc - optind;  // передавать в каждый  if else

  // printf("before: argc(%d) - optind(%d) = %d\n", argc, optind, (argc -
  // optind)); printf("count_file = %d\n", count_file);

  //  нету флага -е - один паттерн
  if (!option_struct.opt_e && !option_struct.opt_f) {
    patterns[0] = (char*)malloc((strlen(argv[optind]) + 1) * sizeof(char));
    strcpy(patterns[0], argv[optind]);
    arr_w_pat_size++;
    optind++;
  }

  while (argc > optind) {
    // -s success
    if (((readparser_file = fopen(argv[optind], "rb")) == NULL) &&
        !option_struct.opt_s) {
      fprintf(stderr, "%s: %s: No such file or directory\n", argv[0],
              argv[optind]);
    }

    // сдвоенные !!!!!!
    // -in
    else if ((readparser_file != NULL) && option_struct.opt_i &&
             option_struct.opt_n) {
      int in_count = count_file;
      // printf("\n----- in -----\n");
      fun_in_count_lower_ignore_reg(argv[optind], *patterns, readparser_file,
                                    in_count);
      // in_count--;
    }

    // -cv
    else if ((readparser_file != NULL) && option_struct.opt_c &&
             option_struct.opt_v) {
      int in_count = count_file;
      fun_cv_count_invert_reg(argv[optind], *patterns, readparser_file,
                              in_count);
      // in_count--;
    }
    // -iv
    else if ((readparser_file != NULL) && option_struct.opt_i &&
             option_struct.opt_v) {
      int in_count = count_file;
      fun_iv_ignore_invert_reg(argv[optind], *patterns, readparser_file,
                               in_count);
      // in_count--;
    }
    // -lv
    else if ((readparser_file != NULL) && option_struct.opt_l &&
             option_struct.opt_v) {
      int in_count = count_file;
      fun_lv_name_invert_reg(argv[optind], *patterns, readparser_file,
                             in_count);
      // in_count--;
    }
    // -ho
    else if ((readparser_file != NULL) && option_struct.opt_h &&
             option_struct.opt_o) {
      int in_count = count_file;
      fun_ho_noname_pattern_reg(argv[optind], *patterns, in_count);
      // in_count--;
    }
    // -nf
    else if ((readparser_file != NULL) && option_struct.opt_n &&
             option_struct.opt_f) {
      int in_count = count_file;
      // printf("||||||| TEST -nf |||||||||");
      fun_nf_numstr_file_reg(files, argv[optind], in_count);
      // in_count--;
    }

    // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // -e несколько паттернов
    else if ((readparser_file != NULL) && option_struct.opt_e) {
      int e_count = count_file;
      fun_e_search(argv[optind], patterns, readparser_file, e_count);
      // e_count--;
    }
    // -i
    else if ((readparser_file != NULL) && option_struct.opt_i &&
             !option_struct.opt_n) {
      int i_count = count_file;
      fun_i_ignore_reg(argv[optind], *patterns, readparser_file, i_count);
      // i_count--;
    }
    // -v
    else if ((readparser_file != NULL) && option_struct.opt_v) {
      int v_count = count_file;
      fun_v_invert_pattern(argv[optind], *patterns, readparser_file, v_count);
      // v_count--;
    }
    // -c
    else if ((readparser_file != NULL) && option_struct.opt_c) {
      fun_c_count_str_accord(argv[optind], *patterns);
    }
    // -l
    else if ((readparser_file != NULL) && option_struct.opt_l) {
      fun_l_acoord_files(argv[optind], *patterns);
    }
    // -n
    else if ((readparser_file != NULL) && option_struct.opt_n) {
      fun_n_num_str_search(argv[optind], *patterns);
    }
    // -h
    else if ((readparser_file != NULL) && option_struct.opt_h) {
      fun_h_noname_file(argv[optind], *patterns);
    }
    // -o
    else if ((readparser_file != NULL) && option_struct.opt_o) {
      int o_count = count_file;
      fun_o_print_match(argv[optind], *patterns, o_count);
    }
    // -f
    else if ((readparser_file != NULL) && option_struct.opt_f) {
      int f_count = count_file;
      // printf(" -argv[optind]- %s -- \n", argv[optind]);
      // printf(" -files[0]----- %s -- \n", files[0]);
      // printf(" -----f-------- %d -- \n", option_struct.opt_f);
      // // printf(" -n- %d -- \n", option_struct.opt_n);
      // printf("\nWHILE -- count_file -- WHILE = %d\n\n", count_file);
      fun_f_search(files, argv[optind], f_count);
      // f_count--;
    }
    // grep default
    else if ((readparser_file != NULL)) {
      int def_count = count_file;
      fun_grep_search(argv[optind], *patterns, readparser_file, def_count);
    }
    optind++;
  }

  for (int i = 0; i < 100; i++) {
    if (files[i] != NULL) {
      free(files[i]);
      files[i] = NULL;
    }
  }

  for (int i = 0; i < 100; i++) {
    if (patterns[i] != NULL) {
      free(patterns[i]);
      patterns[i] = NULL;
    }
  }
  fclose(readparser_file);
}
