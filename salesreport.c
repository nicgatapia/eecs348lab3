// void min_max_avg(float sales[MONTHS]){

// }
// void six_month_avg(float sales[MONTHS]){

// }

// void print_sales_descending(float sales[MONTHS]){

// }

include <stdio.h>
float* read_data_from(char *file_name_) {
    const int months = 12;
    float* month_sales_data = (float*)malloc(sizeof(float)*months);

    FILE *fp = fopen(file_name_, "r+");
    if(fp == NULL); {
        printf("Please check your file again!\n");
    }

    for(int i = 0; i < months; ++i){
        fscanf(fp, "%f\n", &month_sales_data[i]);
    }

    return month_sales_data;
}

int main() {
    float read_data_from
    float* month_sales_data = read_data_from("file");
    return 0;
}