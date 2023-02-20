#include <stdio.h>

char* monthNames[12] = {"January", "February", "March", "April", 
                            "May", "June", "July", "August",
                            "September", "October", "November", "December"};


float* read_data_from(char *file_name_) {
    const int months = 12;
    float* month_sales_data = (float *)malloc(sizeof(float)*months);

    FILE *fp = fopen(file_name_, "r+");

    for(int i = 0; i < months; ++i){
        fscanf(fp, "%f.2\n", &month_sales_data[i]);
    }

    return month_sales_data;
}

void min_max_avg(float sales[12]){
    float min = 0;
    float max = 0;
    float avg = 0;
    float sum = 0;
    int minmonth = 0;
    int maxmonth = 0;

    for (int i = 0; i < 12; i++) {
        sum += sales[i];
        if (i == 0) {
            min = sales[i];
            minmonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxmonth = i;
        }
    }
    avg = sum / 12;
    printf("\n\nSales Summary: \n\n");
    printf("Maximum sales:   $%.2f   (%s)\n",max, monthNames[maxmonth]);
    printf("Minimum sales:   $%.2f   (%s)\n",min, monthNames[minmonth]);
    printf("Average sales:   $%.2f\n", avg);
}
void six_month_avg(float sales[12]){
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++){
        float localsum = 0;
        for (int j = i; j < i+6; j++){
            localsum += sales[j];
        }
        float localavg = localsum / 6;
        printf("%-10s - %-10s %.2f\n", monthNames[i], monthNames[i+5], localavg);
    }
}

void print_sales_descending(float sales[12]){
    float sortedarray[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < 12; i++) {
        int newindex = 0;
        for(int k = 0; k < 12; k++){
            if (sales[i] < sales[k]){
                newindex += 1;
            }
        }
        sortedarray[i] = newindex;
    }
    printf("\n\nSales Report (Highest to Lowest)\n");
    printf("\n  Month     Sales   \n");
    for(int j = 0; j < 12; j++){
        int index = sortedarray[j];
        printf("%-10s $%.2f\n", monthNames[index], sales[index]);
    }


}


int main() {
    float* month_sales_data = read_data_from("input.txt");
    printf("Monthly Sales Report for 2022:\n");
    for (int i = 0; i < 12; i++ ) {
        printf("%-10s %.2f\n", month_sales_data[i], monthNames[i]);
    }
    min_max_avg(month_sales_data);
    six_month_avg(month_sales_data);
    print_sales_descending(month_sales_data);
    return 0;
}

