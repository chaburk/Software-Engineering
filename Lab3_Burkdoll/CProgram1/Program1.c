#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float* read_data_from(char *file_name);

void sales_report(float data[], int size, char **month_names);
void sales_summary(float data[], int size, char **month_names);
void six_month_moving(float data[], int size, char **month_names);
void high_to_low(float data[], float ordered[], int size, char **month_names);

void bubbleSort(float arr[], int n);

int main(){
	char *month_names[12] = {"January", "February", "March", "April", "May", "June",
			  "July", "August", "September", "October", "November", "December"};
	const int MONTHS = 12;
	float* month_sales_data = read_data_from("input.txt");
	float ordered[MONTHS];

	sales_report(month_sales_data, MONTHS, month_names);
	sales_summary(month_sales_data, MONTHS, month_names);
	six_month_moving(month_sales_data, MONTHS, month_names);
	for(int i = 0; i < MONTHS; ++i){
		ordered[i] = month_sales_data[i];
	}
	bubbleSort(ordered, MONTHS);
	high_to_low(month_sales_data, ordered, MONTHS, month_names);

	return 0;
}

float* read_data_from(char *file_name){
	const int MONTHS = 12;
	float *month_sales_data = (float*)malloc(sizeof(float) * MONTHS);

	FILE* fp = fopen(file_name, "r");
	if(!fp){
		printf("Please check your file again\n");
	}
	for(int i = 0; i < MONTHS; ++i){
		fscanf(fp, "%f\n", &month_sales_data[i]);
	}

	return month_sales_data;
}

void swap(float* xp, float* yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(float arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void sales_report(float data[], int size, char **month_names){
	printf("Monthly sales report for 2022\n");
	printf("Month     Amount\n");
	for(int i = 0; i < size; ++i){
		printf("%-10s", month_names[i]);
		printf("%.2f\n", data[i]);
	}
	printf("\n");
}

void sales_summary(float data[], int size, char **month_names){
	printf("Sales summary:\n");
	float min = data[0];
	int min_name = 0;
	float max = data[0];
	int max_name = 0;
	float average = 0.0;
	for(int i = 0; i < size; ++i){
		if(data[i]< min){
			min = data[i];
			min_name = i;
		}
		if(data[i] > max){
			max = data[i];
			max_name = i;
		}
		average = average + data[i];
	}
	average = average/size;
	printf("Minimum sales: %15.2f ", min);
	printf("(%s)\n", month_names[min_name]);
	printf("Maximum sales: %15.2f (%s)\n", max, month_names[max_name]);
	printf("Average sales: %15.2f\n\n", average);
}

void six_month_moving(float data[], int size, char **month_names){
	float total = 0.0;
	printf("Six-Month Moving Average Report:\n");
	for(int i = 0; i < 7; ++i){
		for(int j = i; j < (i + 6); ++j){
			total = total + data[j];
		}
		total = total / 6;
		printf("%10s - %-10s ", month_names[i], month_names[i+5]);
		printf("%.2f\n", total);
		total = 0.0;
	}
	printf("\n");
}

void high_to_low(float data[], float ordered[], int size, char **month_names){
	printf("Sales Report(Highest to Lowest\n");
	printf("Month     Sales\n");
	for(int i = size - 1; i >= 0; --i){
		for(int j = 0; j < size ; ++j){
			if(ordered[i] == data[j]){
				printf("%-10s", month_names[j]);
				printf("%.2f\n",ordered[i]);
				break;
			}
		}
	}
}
