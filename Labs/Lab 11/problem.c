/*
 * 	Lab 11
 *
 *	Programmer: Jacob Snarr   Date Completed: December 1st, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 25
#define MAX_LINE_ITEMS 200
#define MAX_READ_CHARS 200

typedef struct {
  char product_code[10];
  char description[50];
  double price;
  int quantity;
} product_t;

typedef struct {
  int invoice_id;
  char product_code[10];
  double price;
  int quantity;
  double total;
} line_item_t;

int read_products(product_t pa[], char *filename);
int read_line_items(line_item_t la[], char *filename);
void print_line_item(line_item_t l);
void print_line_items(line_item_t la[], int k);
void print_product(product_t p);
void print_products(product_t pa[], int k);
void zero_quantitites(int quantity_sums[], int pa_count);
void zero_totals(double total_sums[], int pa_count);
void calc_report(product_t pa[], int pa_count, line_item_t la[], int la_count, double total_sums[], int quantity_sums[]);
void print_report(product_t pa[], int pa_count, double total_sums[], int quantity_sums[]);
void write_report(product_t pa[], int pa_count, double total_sums[], int quantity_sums[], char *file_name);
void update_products(product_t pa[], int pa_count, int quantity_sums[]);
void write_products(product_t pa[], int pa_count, char *filename);

int main() {
  product_t pa[MAX_PRODUCTS];
  int pa_count = 0;

  line_item_t la[MAX_LINE_ITEMS];
  int la_count = 0;

  pa_count = read_products(pa, "products.csv");
  
  printf("\n%d products read.\n", pa_count);
  print_products(pa, pa_count);

  la_count = read_line_items(la, "lineitems.csv");
  
  printf("\n%d line items read.\n", la_count);
  print_line_items(la, la_count);

  double total_sums[pa_count];
  int quantity_sums[pa_count];

  zero_quantitites(quantity_sums, pa_count);
  zero_totals(total_sums, pa_count);
  
  calc_report(pa, pa_count, la, la_count, total_sums, quantity_sums);
  print_report(pa, pa_count, total_sums, quantity_sums);
  write_report(pa, pa_count, total_sums, quantity_sums, "report.txt");

  update_products(pa, pa_count, quantity_sums);
  printf("\nUpdated products\n");
  print_products(pa, pa_count);
  write_products(pa, pa_count, "newProducts.txt");
}

int read_products(product_t pa[], char *filename) {
  FILE *product_file;
  product_file = fopen(filename, "r");

  char line[MAX_READ_CHARS];
  char delims[] = ",";
  char *result = NULL;

  for (int i = 0; i <= MAX_PRODUCTS; i++) {
    if (fgets(line, MAX_READ_CHARS, product_file) == NULL) {
      return i;
    }
    char *ptr;
    strcpy(pa[i].product_code, strtok(line, delims));
    strcpy(pa[i].description, strtok(NULL, delims));
    pa[i].price = strtod(strtok(NULL, delims), &ptr);
    pa[i].quantity = atoi(strtok(NULL, delims));
  }
  fclose(product_file);
  return -1;
}

void print_product(product_t p) {
  printf("%-6s %-55s %5.2lf %12d\n", p.product_code, p.description, p.price, p.quantity);
}

void print_products(product_t pa[], int k) {
  for (int i = 0; i < k; i++) {
    print_product(pa[i]);
  }
}

int read_line_items(line_item_t la[], char *filename) {
  FILE *line_item_file;
  char line[MAX_READ_CHARS];
  char delims[] = ",";
  char *result = NULL;

  line_item_file = fopen(filename, "r");

  if (line_item_file == NULL) {
    perror("Error opening file");
    return -1;
  }

  for (int i = 0; i <= MAX_LINE_ITEMS; i++) {
    if (fgets(line, MAX_READ_CHARS, line_item_file) == NULL) {
      return i;
    }
    char *ptr;
    la[i].invoice_id = atoi(strtok(line, delims));
    strcpy(la[i].product_code, strtok(NULL, delims));
    la[i].price = strtod(strtok(NULL, delims), &ptr);
    la[i].quantity = atoi(strtok(NULL, delims));
    la[i].total = strtod(strtok(NULL, delims), &ptr);
  }
  fclose(line_item_file);
  return -1;
}

void print_line_item(line_item_t l) {
  printf("%-6d %-13s %-15.2lf %5d %11.2lf\n", l.invoice_id, l.product_code, l.price, l.quantity, l.total);
}

void print_line_items(line_item_t la[], int k) {
  for (int i = 0; i < k; i++) {
    print_line_item(la[i]);
  }
}

void zero_quantitites(int quantity_sums[], int pa_count) {
  for (int i = 0; i < pa_count; i++) {
    quantity_sums[i] = 0;
  }
}

void zero_totals(double total_sums[], int pa_count) {
  for (int i = 0; i < pa_count; i++) {
    total_sums[i] = 0.0;
  }
}

void calc_report(product_t pa[], int pa_count, line_item_t la[], int la_count, double total_sums[], int quantity_sums[]) {
  for (int i = 0; i < la_count; i++) {
    for (int j = 0; j < pa_count; j++) {
      if(!strcmp(pa[j].product_code, la[i].product_code)) {
        total_sums[j] += la[i].total;
        quantity_sums[j] += la[i].quantity;
        continue;
      }
    }
  }
}

void print_report(product_t pa[], int pa_count, double total_sums[], int quantity_sums[]) {
  int tot_quantity = 0;
  double tot_price = 0;

  printf("\nProduct Sales Report\n");
  printf("Code   Quantity      Total\n");
  for (int i = 0; i < pa_count; i++) {
    printf("%-6s %8d %10.2lf\n", pa[i].product_code, quantity_sums[i], total_sums[i]);
    tot_quantity += quantity_sums[i];
    tot_price += total_sums[i];
  }

  printf("\nTotal items sold: %18d\n", tot_quantity);
  printf("Total revenue from sales: %10.2lf\n", tot_price);
}

void write_report(product_t pa[], int pa_count, double total_sums[], int quantity_sums[], char *filename) {
  FILE *file;
  file = fopen(filename, "w+");

  int tot_quantity = 0;
  double tot_price = 0;

  fprintf(file, "Product Sales Report\n");
  fprintf(file, "Code   Quantity      Total\n");
  for (int i = 0; i < pa_count; i++) {
    fprintf(file, "%-6s %8d %10.2lf\n", pa[i].product_code, quantity_sums[i], total_sums[i]);
    tot_quantity += quantity_sums[i];
    tot_price += total_sums[i];
  }

  fprintf(file, "\nTotal items sold: %18d\n", tot_quantity);
  fprintf(file, "Total revenue from sales: %10.2lf\n", tot_price);

  fclose(file);
}

void update_products(product_t pa[], int pa_count, int quantity_sums[]) {
  for (int i = 0; i < pa_count; i++) {
    pa[i].quantity -= quantity_sums[i];
  }
}

void write_products(product_t pa[], int pa_count, char *filename) {
  FILE *file;
  file = fopen(filename, "w+");

  fprintf(file, "Updated Products\n");
  for (int i = 0; i < pa_count; i++) {
    fprintf(file, "%-6s %-55s %5.2lf %12d\n", pa[i].product_code, pa[i].description, pa[i].price, pa[i].quantity);
  }

  fclose(file);
}