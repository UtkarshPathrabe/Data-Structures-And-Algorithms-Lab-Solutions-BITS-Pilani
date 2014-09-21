//OffenceOps.h

#include "Offence.h"

extern owner populateVehicles(FILE *source);
extern driver populateDrivers(FILE *source);
extern void printVehicleListP(FILE * fp, owner node);
extern void printDriversListP(FILE * fp, driver node);
extern void printDriversList(FILE * fp, driver node);
extern void printOffensesListP(FILE * fp, offense node);

/* Hash table ADT functions */
extern driver insert_word(driver word_list, int uid, int license, int penalty, int *used);
extern owner insert_word1(owner word_list, int uid, int vno, int *used);
extern driver search_list(driver word_list, int license, int *count);
extern owner search_list1(owner word_list, int uid);
extern unsigned int hash(int data, int tbl_size);
extern driver search_table(table *hash_table, int license, int *count);
extern owner search_table1(table1 *hash_table, int uid);
extern table *grow_table(table *hash_table);
extern table1 *grow_table1(table1 *hash_table);
extern void destroy(driver word_list);
extern driver create_node(int uid, int license, int penalty);
extern owner create_node1(int uid, int vno);
extern void *gcalloc( int number, int size);
extern driver makeRevokeList(FILE *source, table *hash_table, table1 *hash_table1, int* count);

/* Various helper functions */
extern int ask_user(void);
extern table *build_table(FILE *input);
extern table1 *build_table1(FILE *input);
extern list *build_list(FILE *input);
extern void print_result(driver result, int count);
extern char *return_word(char *word, FILE *input);
extern void print_stats(table *hash_table);
extern double print_time(clock_t time);
