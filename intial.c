#include <stdio.h>
#include <stdlib.h>

char choice;
char *cities[]={"Karachi","Hyderabad","Lahore","Islamabad"};
char city_name_cal[21];
int  i, n=1, j, table_loop=1, k;
int num_of_elements = sizeof(cities) / sizeof(cities[0]);

void restart_program(){
	char r;
	printf("\nRestart program? (Y/N): ");
	scanf("%s", &r);
	if(r =='Y' || r =='y'){
		
		printf("\n------------------------------\n");
		print_statements();
	}
	else  if(r=='N' || r=='n'){
		printf("Thankyou for using this program.");
	}
	else{
		printf("bruhhh");
	}
}

double calculate_crime_rate(int population_cal, int reported_crimes_cal) {
    if (population_cal <= 0) {
        printf("The population size is not valid\n");
        return -1; 
    }
    double crime_rate = ((double)reported_crimes_cal / population_cal) * 1000;
    
    return crime_rate;
}

void karachi(){
	printf("\nNumber of reported crimes: 50000");
	printf("\nTotal population: 20300000");
	printf("\nCrime rate: 2.46 per 1000 residents\n");
}

void hyderabad(){
	printf("\nNumber of reported crimes: 10000");
	printf("\nTotal population: 1403786");
	printf("\nCrime rate: 7.12 per 1000 residents\n");
}

void lahore(){
	printf("\nNumber of reported crimes: 100");
	printf("\nTotal population: 10,000");
	printf("\nCrime rate: 1203\n");
}

void islamabad(){
	printf("\nNumber of reported crimes: 100");
	printf("\nTotal population: 10,000");
	printf("\nCrime rate: 1203\n");
}

typedef void (*function_ptr)();

function_ptr tables[] = { karachi, hyderabad, lahore, islamabad};

void calculation(){
	
	int reported_crimes_cal, population_cal;
	
	printf("\nKindly input the city's name : ");
	scanf("%20s", &city_name_cal);
	printf("\nKindly input the reported number of crimes: ");
	scanf("%d", &reported_crimes_cal);
	printf("\nKindly input the population of the city: ");
	scanf("%d", &population_cal);
	
	double crime_rate = calculate_crime_rate(population_cal, reported_crimes_cal);
	double inflation_rate = (crime_rate / 1000) + (reported_crimes_cal / (double)population_cal) * 10;
	
	printf("\n------------------------------\n");
	printf("\nName of City: %s", city_name_cal);
	printf("\nNumber of reported crimes: %d", reported_crimes_cal);
	printf("\nTotal population: %d", population_cal);
	printf("\nThe crime rate is: %.2f per 1,000 residents\n", crime_rate);
	printf("Hypothetical inflation rate: %.2f%%\n", inflation_rate);
}

void print_statements(){
	printf("----CRIME RATE EVALUATION----\n\n");
	printf("A.)View Data-base\n");
	printf("B.)Calculate Crime-rate\n");
	printf("\n------------------------------\n");
	printf("Choose A/B : ");
	scanf("\n%c", &choice);
		
		if(choice == 'A' || choice == 'a'){
			printf("\n");
			printf("DATABASE : ");
			
			for(i=0;i<num_of_elements;i++){
				printf(" || %d.%s || ", n,  cities[i]);
				n++;
			}
				printf("\n\nChoose a city by entering the number assigned to it (example-->1.Karachi : 1) : ");
				scanf("%d", &n);
					
					for(j=0;j<num_of_elements;j++){
					
						if(n==table_loop){
							printf("\nTABLE FOR %s: ", cities[j]);
							tables[j]();
							j = num_of_elements;
							restart_program();
						}
						else{
							table_loop++;
						}
					}
			}
			else if(choice == 'B' || choice == 'b'){
				calculation();
				restart_program();
			}		
	
			else{
				printf("------------------------------\n");
				printf("Please Choose either A or B\n\n");
				print_statements();
				}	
}

int main (){
	
	system("color E0");
	
	print_statements();
	
	return 0;
}
