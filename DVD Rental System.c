#include<stdio.h>/*for use of scanf(), printf(), fopen(), fread(), fwrite(), rewind(),feof() and fclose()*/
#include<windows.h> /*for use system(¡°pause¡±)*/
#include<stdlib.h>/*for use system(¡°pause¡±), system(¡°cls¡±) and srand()*/
#include<time.h>/*for use time()*/
#include<stdbool.h>/*for use type bool*/
#include<string.h>/*for use strcmp() and strcpy() */

typedef struct movie{
	char movie_title[50];/*store title*/
	char directors[10][50];/*store director*/
	char actors[10][50];/*store actors*/
	int age_limits;/*1 represent suitable for children,
				   0 represent suitable for children */
	int genre;/*different number represent different type*/
	int copies;/*store the number of copies*/
	int stock_statue[2];/*stock_statue[0] is available value, stock_statue[1] is lend value*/
	int rental_duration;/*Provisional number of lease days*/
	int charge;/*the fee within the rental duration(Days)*/
}movie;/*Define the structure to store the information of movie*/

typedef struct customer{
	char account_number[20];/*store account number*/
	char name[20];/*store name*/
	int age;/*store age*/
	int telephone_number;/*store telephone number*/
	char address[50];/*store address*/
	int pending_charge;/*store pending charge*/
	char rental_history[100][50];/*store unreturn book*/
}customer;/*Define the structure to store the information of customer*/

int homepage(){/*Print the interface to ask users choice and output correct option in homepage*/
	int choice;/*store the choice*/
	system("cls");
	printf("Please choice the option you want\n");
	printf("1. Search the movie\n");
	printf("2. Log in as Branch manager\n");
	printf("3. Log in as Rental desk worker \n");
	printf("4. Quit\n");
	/*print the list*/
	while (1 != scanf("%d", &choice) || choice < 1 || choice > 4)
		/*judge the input whether it is suitable*/
	{
		system("cls");
		printf("Choice error, please do it again");
		printf("Please choice the option you want\n");
		printf("1. Search the movie\n");
		printf("2. Log in as Branch manage\n");
		printf("3. Log in as Rental desk worker \n");
		printf("4. Quit\n");
		fflush(stdin);
	}
	return choice;
	/*return correct choice*/
} //

bool Manager_Login(){/*check the manager account and output the result*/
	char manager[10] = "boss";
	char manager_code[10] = "123456";/*store correct manager account*/
	char p_manager[10];
	char p_manager_code[10];/*store the tested account*/
	printf("username:\n");
	scanf("%s", p_manager);
	printf("password:\n");
	scanf("%s", p_manager_code);/*get tested account*/
	if (!strcmp(p_manager, manager) && !strcmp(p_manager_code, manager_code))
	{
		printf("Log in successfully!\n");
		system("pause");
		return true;
	}
	else
	{
		printf("Log in fail!\n");
		system("pause");
		return false;
	}
	/*compare and return the result*/
}

bool Worker_Login(){/*check the worker account and output the result*/
	char worker[10] = "worker";
	char worker_code[10] = "654321";
	char p_worker[10];
	char p_worker_code[10];
	printf("username:\n");
	scanf("%s", p_worker);
	fflush(stdin);
	printf("password:\n");
	scanf("%s", p_worker_code);
	if (!strcmp(p_worker, worker) && !strcmp(p_worker_code, worker_code))
	{
		printf("Log in successfully!");
		system("pause");
		return true;
	}
	else
	{
		printf("Log in fail!\n");
		system("pause");
		return false;
	}
}

int search_page(){/*Print the interface to ask users choice and return a correct option in search page*/
	int choice;
	system("cls");
	printf("Please choice the option you want\n");
	printf("1. Search the movie by title\n");
	printf("2. Search the movie by actor\n");
	printf("3. Search the movie by movie director\n");
	printf("4. Quit\n");
	while (1 != scanf("%d", &choice) || choice < 1 || choice > 4)
		/*check the input*/
	{
		system("cls");
		printf("Choice error, please do it again");
		printf("Please choice the option you want\n");
		printf("1. Search the movie by title\n");
		printf("2. Search the movie by actor\n");
		printf("3. Search the movie by movie director\n");
		printf("4. Quit\n");
		fflush(stdin);
	}
	return choice;
}

int manager_page(){/*Print the interface to ask users choice and return a correct option in manager page*/
	int choice;
	system("cls");
	printf("Please choice the option you want\n");
	printf("1. Add movie\n");
	printf("2. Edit movie\n");
	printf("3. Delete movie\n");
	printf("4. Add customer\n");
	printf("5. Edit customer\n");
	printf("6. Delete customer\n");
	printf("7. View current stock status\n");
	printf("8. Quit\n");
	while (1 != scanf("%d", &choice) || choice < 1 || choice > 8)
	{
		system("cls");
		printf("Choice error, please do it again");
		printf("Please choice the option you want\n");
		printf("1. Add movie\n");
		printf("2. Edit movie\n");
		printf("3. Delete movie\n");
		printf("4. Add customer\n");
		printf("5. Edit customer\n");
		printf("6. Delete customer\n");
		printf("7. View current stock status\n");
		printf("8. Quit\n");
		fflush(stdin);
	}
	return choice;
}

int worker_page(){/*Print the interface to ask users choice and output a correct option in worker page*/
	int choice;
	system("cls");
	printf("Please choice the option you want\n");
	printf("1. Service\n");
	printf("2. Quit\n");
	while (1 != scanf("%d", &choice) || choice < 1 || choice > 2)
	{
		system("cls");
		printf("Choice error, please do it again");
		printf("Please choice the option you want\n");
		printf("1. Service\n");
		printf("2. Quit\n");
		fflush(stdin);
	}
	return choice;
}

int movie_edit_page(){/*Print the interface to ask users choice and output correct option in movie edit page*/
	int choice;
	system("cls");
	printf("Please choice the option you want to edit\n");
	printf("1. Movie title\n");
	printf("2. Directors\n");
	printf("3.Actors\n");
	printf("4.Age limits\n");
	printf("5.Genre\n");
	printf("6.Copies\n");
	printf("7.Stock statue\n");
	printf("8.Rental duration\n");
	printf("9.charge\n");
	printf("10. Quit\n");
	while (1 != scanf("%d", &choice) || choice < 1 || choice > 10)
	{
		system("cls");
		printf("Choice error, please do it again");
		printf("Please choice the option you want to edit\n");
		printf("1. Movie title\n");
		printf("2. Directors\n");
		printf("3.Actors\n");
		printf("4.Age limits\n");
		printf("5.Genre\n");
		printf("6.Copies\n");
		printf("7.Stock statue\n");
		printf("8.Rental duration\n");
		printf("9.charge\n");
		printf("10. Quit\n");
		fflush(stdin);
	}
	return choice;
}

int customer_edit_page(){/*Print the interface to ask users choice and output a correct option in customer edit page*/
	int choice;
	system("cls");
	printf("Please choice the option you want to edit\n");
	printf("1. Name\n");
	printf("2. Age\n");
	printf("3. Telephone number\n");
	printf("4. Address\n");
	printf("5. Pending charge\n");
	printf("6. Rental history\n");
	printf("7. Quit\n");

	while (1 != scanf("%d", &choice) || choice < 1 || choice > 7)
	{
		system("cls");
		printf("Choice error, please do it again");
		printf("Please choice the option you want to edit\n");
		printf("1. Name\n");
		printf("2. Age\n");
		printf("3. Telephone number\n");
		printf("4. Address\n");
		printf("5. Pending charge\n");
		printf("6. Rental history\n");
		printf("7. Quit\n");
		fflush(stdin);
	}
	return choice;
}

void print_movie(movie compare){/*print the information of the movie*/
	system("cls");
	int i = 0;
	printf("Title:%s", compare.movie_title);
	printf("\nDirector:");
	while (strlen(*(compare.directors + i)) != 0)
	{
		printf("%s\n", *(compare.directors + i));
		i++;
	}
	/*print all director*/
	i = 0;
	printf("\nActor:");
	while (strlen(*(compare.actors + i)) != 0)
	{
		printf("%s\n", *(compare.actors + i));
		i++;
	}
	/*print all actors*/
	printf("\nAge limits:");
	switch (compare.age_limits)
	{
	case 1:
		printf("Suitable for children to watch!\n ");
		break;
	case 2:
		printf("Not suitable for children to watch ");
		break;
	}
	/*print age limit according the number stored*/
	printf("Genre:");
	switch (compare.genre)
	{
	case 1:
		printf("Comedy\n");
		break;
	case 2:
		printf("Horror film \n");
		break;
	case 3:
		printf("Literary film \n ");
		break;
	case 4:
		printf("Science fiction\n ");
		break;
	}
	/*print genre according the number stored*/
	printf("number of copies:%d\n", compare.copies);
	/*print copies*/
	system("pause");
}

bool Comprehensive_search(){/*search the movie according title ,director or actor*/
	movie compare = { 0 };
	char title[50];
	char actor[50];
	char movie_director[50];
	int p = 0;
	int q = 0;
	int y = 0;
	switch (search_page())
	{
	case 1:/*search with title*/
		printf("The title you want to search:\n");
		scanf("%s", title);
		FILE* f1 = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
		rewind(f1);
		/*open the file*/
		while (!feof(f1))
			/*check the end*/
		{
			fread(&compare, sizeof(movie), 1, f1);
			/*get current strcuture from file*/
			if (!strcmp(compare.movie_title, title))
				/*compare and determine whether it is wanted*/
			{
				print_movie(compare);
				p++;
				/*print the information if matching*/
			}
		}
		if (p == 0)
			printf("The title does not exist \n");
		/*print the result if nothing match*/
		fclose(f1);
		system("pause");
		break;
	case 2:/*search with actor*/
		printf("The actor you want to search:\n");
		scanf("%s", actor);
		FILE* f2 = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
		int a;
		rewind(f2);
		while (!feof(f2))
		{
			fread(&compare, sizeof(movie), 1, f2);
			a = 0;
			while (strlen(*(compare.actors + a)) != 0)
				/*check each actor one by one*/
			{
				if (!strcmp(*(compare.actors + a), actor))
				{
					print_movie(compare);
					q++;
				}
				a++;
			}
		}
		if (q == 0)
			printf("The actor does not exist \n");
		fclose(f2);
		system("pause");
		break;
	case 3:/*search with director*/
		printf("The movie director you want to search:\n");
		scanf("%s", movie_director);
		FILE* f3 = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
		int z;
		rewind(f3);
		while (!feof(f3))
		{
			fread(&compare, sizeof(movie), 1, f3);
			z = 0;
			while (strlen(*(compare.directors + z)) != 0)
			{
				if (!strcmp(*(compare.directors + z), movie_director))
				{
					print_movie(compare);
					y++;
				}
				z++;
			}
		}
		if (y == 0)
			printf("The movie director does not exist \n");
		fclose(f3);
		system("pause");
		break;
	case 4:
		return false;
	}
	return true;
	/*return the result*/
}

void add_movie(){/*collect the information and store it in the file*/
	movie add = { 0 };
	/*store the collect information*/
	char movie_title[50];
	printf("\nMovie title:");
	scanf("%s", movie_title);
	strcpy(add.movie_title, movie_title);
	/*collect title*/
	char directors[10][50];
	int d1, p1;
	printf("\nThe number of directors:");
	while (1 != scanf("%d", &d1))
	{
		printf("\nInput error, please try again!");
		printf("\nThe number of directors:");
		fflush(stdin);
	}
	/*make sure the input is a number*/
	/*give tips for input error*/
	for (p1 = 0; p1 < d1; p1++)
	{
		printf("\n%d:", p1 + 1);
		scanf("%s", (directors + p1));
		strcpy((add.directors + p1), (directors + p1));
	}
	/*collect director*/
	char actors[10][50];
	int d2, p2;
	printf("\nThe number of actors:");
	while (1 != scanf("%d", &d2))
		printf("\nInput error, please try again!");
	for (p2 = 0; p2 < d2; p2++)
	{
		printf("\n%d:", p2 + 1);
		scanf("%s", (actors + p2));
		strcpy((add.actors + p2), (actors + p2));
	}
	/*collect actors*/
	int age_limits;
	printf("\nIs it suitable for children to watch?(1:Yes or 0:No)");
	scanf("%d", &age_limits);
	fflush(stdin);
	while (age_limits != 1 && age_limits != 0)
		/*judge the input whether it is correct*/
	{
		fflush(stdin);
		printf("\nInput error, please try again!");
		printf("\nIs it suitable for children to watch?(Y or N)");
		scanf("%d", &age_limits);
	}
	/*make sure the input is a number*/
	/*give tips for input error*/
	add.age_limits = age_limits;

	int genre;
	printf("\nPlease choose the genre:");
	printf("\n1: comedy ");
	printf("\n2: Horror film ");
	printf("\n3: Literary film ");
	printf("\n4: Science fiction\n");
	scanf("%d", &genre);
	fflush(stdin);
	while (genre != 1 && genre != 2 && genre != 3 && genre != 4)
	{
		printf("\nInput error, please try again!");
		printf("\n1: comedy ");
		printf("\n2: Horror film ");
		printf("\n3: Literary film ");
		printf("\n4: Science fiction\n");
		scanf("%d", &genre);
		fflush(stdin);
	}
	add.genre = genre;
	/*get correct genre*/

	int copies;
	fflush(stdin);
	printf("\n The number of copies:");
	while (1 != scanf("%d", &copies))
	{
		fflush(stdin);
		printf("\n Input error, please try again");
		printf("\n The number of copies:");
		fflush(stdin);
	}
	add.copies = copies;
	/*get correct copies*/
	int stock_statue[2];
	fflush(stdin);
	printf("\n The number of avaliable:");

	while (1 != scanf("%d", (stock_statue + 0)) || stock_statue[0]<0 || stock_statue[0]>copies)
		/*the number of available should less the copies*/
	{
		printf("\n Input error, please try again");
		printf("\n The number of avaliable:");
		fflush(stdin);
	}
	add.stock_statue[0] = stock_statue[0];
	add.stock_statue[1] = copies - stock_statue[0];
	/*get correct stocj statue*/
	int rental_duration;
	printf("\n The rental duration(DAYS):");
	while (1 != scanf("%d", &rental_duration))
	{
		printf("\n Input error, please try again");
		printf("\n The rental duration(DAYS):");
		fflush(stdin);
	}
	/*get correctr rental duration*/
	int charge = 0;
	printf("\n The charge(YUAN):");
	while (1 != scanf("%d", &charge))
	{
		printf("\n Input error, please try again");
		printf("\n The charge(YUAN):");
		fflush(stdin);
	}
	add.charge = charge;
	/*get correct charge*/
	save_m(add);
	/*add the movit into data file*/
	system("pause");
	return;
}

void edit_movie(){/*edit special users wanted information of the movie*/
	char movie_title_research[50];
	printf("\nThe Movie title you want to edit:");
	scanf("%s", movie_title_research);
	FILE*p = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
	movie store;
	char movie_title[50];
	char directors[10][50];
	char actors[10][50];
	int age_limits;
	int genre;
	int copies;
	int stock_statue[2];
	int rental_duration;
	int charge;
	/*store the new information*/
	bool flag = true;
	/*control the loop*/
	rewind(p);
	while (!feof(p))
	{
		fread(&store, sizeof(movie), 1, p);
		if (!strcmp(store.movie_title, movie_title_research))
			/*get the old verison*/
		{
			while (flag)
			{
				switch (movie_edit_page())
				{
				case 1:
					printf("\nNew Movie title:");
					scanf("%s", movie_title);
					strcpy(store.movie_title, movie_title);
					break;
				case 2:
					; int d1, p1;
					printf("\nThe number of directors:");
					while (1 != scanf("%d", &d1))
					{
						printf("\nInput error, please try again!");
						printf("\nThe number of directors:");
						fflush(stdin);
					}
					for (p1 = 0; p1 < d1; p1++)
					{
						printf("\n%d:", p1 + 1);
						scanf("%s", (directors + p1));
						strcpy((store.directors + p1), (directors + p1));
					}
					break;
				case 3:
					; int d2, p2;
					printf("\nThe number of actors:");
					while (1 != scanf("%d", &d2))
					{
						printf("\nInput error, please try again!");
						fflush(stdin);
					}
					for (p2 = 0; p2 < d2; p2++)
					{
						printf("\n%d:", p2 + 1);
						scanf("%s", (actors + p2));
						strcpy((store.actors + p2), (actors + p2));
					}
					break;
				case 4:
					printf("\nIs it suitable for children to watch?(1:Yes or 0:No)");
					scanf("%d", &age_limits);
					fflush(stdin);
					while (age_limits != 1 && age_limits != 0)
					{
						printf("\nInput error, please try again!");
						printf("\nIs it suitable for children to watch?(Y or N)");
						scanf("%d", &age_limits);
						fflush(stdin);
					}
					store.age_limits = age_limits;
					break;
				case 5:
					printf("\nPlease choose the genre:");
					printf("\n1: comedy ");
					printf("\n2: Horror film ");
					printf("\n3: Literary film ");
					printf("\n4: Science fiction\n");
					fflush(stdin);
					scanf("%d", &genre);
					while (genre != 1 && genre != 2 && genre != 3 && genre != 4)
					{
						printf("\nInput error, please try again!");
						printf("\n1: comedy ");
						printf("\n2: Horror film ");
						printf("\n3: Literary film ");
						printf("\n4: Science fiction");
						fflush(stdin);
						scanf("%d", &genre);
					}
					store.genre = genre;
					break;
				case 6:
					fflush(stdin);
					printf("\n The number of copies:");
					while (1 != scanf("%d", &copies))
					{
						printf("\n Input error, please try again");
						printf("\n The number of copies:");
						fflush(stdin);
					}
					store.copies = copies;
					break;
				case 7:
					printf("\n The number of avaliable:");
					while (1 != scanf("%d", (stock_statue + 0)))
					{
						printf("\n Input error, please try again");
						printf("\n The number of avaliable:");
						fflush(stdin);
					}
					store.stock_statue[0] = stock_statue[0];
					store.stock_statue[1] = stock_statue[1];
					break;
				case 8:
					printf("\n The rental duration(DAYS):");
					while (1 != scanf("%d", &rental_duration))
					{
						printf("\n Input error, please try again");
						printf("\n The rental duration(DAYS):");
						fflush(stdin);
					}
					break;
				case 9:
					printf("\n The charge(YUAN):");
					while (1 != scanf("%d", &charge))
					{
						printf("\n Input error, please try again");
						printf("\n The charge(YUAN):");
						fflush(stdin);
					}
					store.charge = charge;
					break;
				case 10:
					flag = false;
					break;
				}
				/*get new verison*/
			}
			fseek(p, -sizeof(movie), SEEK_CUR);
			fwrite(&store, sizeof(movie), 1, p);
			fclose(p);
			printf("\nEdit successfully!");
			system("pause");
			/*Overlay old versions*/
			return;
		}
	}
	printf("\nThe title doesn't exist!");
	/*give tip if the title doesn't exist*/
	system("pause");
	fclose(p);
	return;
}

void delete_movie(){/*Delete the specified movie  */
	movie blank = { 0 };
	/*use to overlay the specified*/
	char movie_title_research[50];
	printf("\nThe Movie title you want to delete:");
	scanf("%s", movie_title_research);
	/*get the specified movie*/
	FILE*p = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
	movie store;
	rewind(p);
	while (!feof(p))
	{
		fread(&store, sizeof(movie), 1, p);
		if (!strcmp(store.movie_title, movie_title_research))
			/*found the specified movie and get the data*/
		{
			fseek(p, -sizeof(movie), SEEK_CUR);
			fwrite(&blank, sizeof(movie), 1, p);
			system("pause");
			printf("Delete successfully");
			fclose(p);
			return;
		}
		/*overlay*/
	}
	system("pause");
	printf("\nThe title doesn't exist!");
	/*give tip if the title doesn't exist*/
	fclose(p);
	return;
}

void add_customer(){/*add new customer in file*/
	customer add = { 0 };
	/*new structure to store the new customer*/
	char account_number[20];
	int x;
	printf("\nAccount number(Character lengths range from 5 to 15 ):");
	x = scanf("%s", account_number);
	while (strlen(account_number)<5 || strlen(account_number)>15 || x != 1)
		/*judge the account whether it is suitable*/
	{
		fflush(stdin);
		printf("Input error, please try again!\n");
		printf("\nAccount number(Character lengths range from 5 to 15 ):");
		x = scanf("%s", account_number);
		/*give tip and ask again if not suitable*/
	}
	strcpy(add.account_number, account_number);
	/*store the account number  information  in to new structure*/


	char name[20];
	printf("\nName:");
	scanf("%s", name);
	strcpy(add.name, name);
	/*get name*/
	int age;
	fflush(stdin);
	printf("\n Age:");
	while (1 != scanf("%d", &age))
	{
		printf("\n Input error, please try again");
		scanf("%d", &age);
		printf("\n Age:");
		fflush(stdin);
	}
	add.age = age;
	/*get age*/
	double telephone_number = 0;
	fflush(stdin);
	printf("\n Telephone number (11 digit number) : ");
	scanf("%lf", &telephone_number);
	while (telephone_number<10000000000 || telephone_number>99999999999)
	{
		printf("\n Input error, please try again");
		printf("\n Telephone number (11 digit number) : ");
		fflush(stdin);
		scanf("%lf", &telephone_number);
	}
	add.telephone_number = telephone_number;
	/*get telephone number*/

	char address[50];
	printf("\nAddress:");
	scanf("%s", address);
	strcpy(add.address, address);
	/*get address*/
	int pending_charge;
	fflush(stdin);
	printf("\n Pending charge:");
	while (1 != scanf("%d", &pending_charge))
	{
		printf("\n Input error, please try again");
		printf("\n The number of copies:");
		fflush(stdin);
	}
	add.pending_charge = pending_charge;
	/*get correct pending charge*/
	char rental_history[100][50];
	int d1, p1;
	printf("\nThe number of books rent:");
	while (1 != scanf("%d", &d1))
	{
		printf("\nInput error, please try again!");
		printf("\nThe number of directors:");
		fflush(stdin);
	}
	for (p1 = 0; p1 < d1; p1++)
	{
		printf("\n%d:", p1 + 1);
		fflush(stdin);
		scanf("%s", (rental_history + p1));
		strcpy((add.rental_history + p1), (rental_history + p1));
	}
	/*get rental history(usually it is 0)*/
	save_c(add);
	/*save it in database*/
	system("pause");
	return;
}

void edit_customer(){/*edit special users wanted information of the customer*/
	char AN_research[20];/*get the account number want to be edited*/
	printf("\nThe Account Number you want to edit:");
	scanf("%s", AN_research);
	/*get the account number want to be edited*/
	FILE*p = fopen("C:\\EEE101_Assessment4_32\\customer.dat", "rb+");
	customer store;
	char account_number[20];
	char name[20];
	int age;
	double telephone_number = 0;
	char address[50];
	int pending_charge;
	char rental_history[100][50];
	/*store new information*/
	int d1, p1;
	/*parameter in procesee*/
	bool flag = true;
	/*control the loop*/
	rewind(p);
	while (!feof(p))
	{
		fread(&store, sizeof(customer), 1, p);
		if (!strcmp(store.account_number, AN_research))
			/*find customer and get old verison*/
		{
			while (flag)
			{
				switch (customer_edit_page())
				{
				case 1:
					printf("\nName:");
					scanf("%s", name);
					strcpy(store.name, name);
					break;
				case 2:
					fflush(stdin);
					printf("\n Age:");
					while (1 != scanf("%d", &age))
					{
						printf("\n Input error, please try again");
						printf("\n Age:");
						fflush(stdin);
					}
					store.age = age;
					break;
				case 3:
					fflush(stdin);
					printf("\n Telephone number (11 digit number) : ");
					scanf("%lf", &telephone_number);
					while (telephone_number<10000000000 || telephone_number>99999999999)
					{
						printf("\n Input error, please try again");
						printf("\n Telephone number (11 digit number) : ");
						fflush(stdin);
						scanf("%lf", &telephone_number);
					}
					store.telephone_number = telephone_number;
					break;
				case 4:
					printf("\nAddress:");
					scanf("%s", address);
					strcpy(store.address, address);
					break;
				case 5:
					fflush(stdin);
					printf("\n Pending charge:");
					while (1 != scanf("%d", &pending_charge))
					{
						printf("\n Input error, please try again");
						printf("\n The number of copies:");
						fflush(stdin);
					}
					store.pending_charge = pending_charge;
					break;
				case 6:
					printf("\nThe number of books rent:");
					while (1 != scanf("%d", &d1))
					{
						printf("\nInput error, please try again!");
						printf("\nThe number of directors:");
						fflush(stdin);
					}
					for (p1 = 0; p1 < d1; p1++)
					{
						printf("\n%d:", p1 + 1);
						fflush(stdin);
						scanf("%s", (rental_history + p1));
						strcpy((store.rental_history + p1), (rental_history + p1));
					}
					break;
				case 7:
					flag = false;
					break;
				}
				/*get new verison*/
			}
			fseek(p, -sizeof(customer), SEEK_CUR);
			fwrite(&store, sizeof(customer), 1, p);
			fclose(p);
			printf("\nEdit successfully!");
			/*Overlay old versions*/
			system("pause");
			return;
		}
	}
	printf("\nThe account number doesn't exist!");
	/*give tip if the account number doesn't exist*/
	system("pause");
	fclose(p);
	return;
}

void delete_customer(){/*Delete the specified customer  */
	customer blank = { 0 };
	/*use to overlay the specified*/
	char AD_research[50];
	printf("\nThe customer you want to delete:");
	scanf("%s", AD_research);
	/*get the specified movie*/
	FILE*p = fopen("C:\\EEE101_Assessment4_32\\customer.dat", "rb+");
	customer store;
	rewind(p);
	while (!feof(p))
	{
		fread(&store, sizeof(customer), 1, p);
		if (!strcmp(store.account_number, AD_research))
			/*found the specified movie and get the data*/
		{
			fseek(p, -sizeof(customer), SEEK_CUR);
			fwrite(&blank, sizeof(customer), 1, p);
			printf("Delete successfully");
			system("pause");
			fclose(p);
			return;
		}
		/*overlay*/
	}
	printf("\nThe customer doesn't exist!");
	/*give tip if the title doesn't exist*/
	system("pause");
	fclose(p);
	return;
}

int save_m(movie add){/*save the movie in the file*/
	FILE* fp = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
	movie compare;
	rewind(fp);
	while (!feof(fp))
	{
		fread(&compare, sizeof(movie), 1, fp);
		if (!strcmp(compare.movie_title, add.movie_title))
		{
			printf("\nThe title has existed!");
			fclose(fp);
			return 0;
		}
	}
	/*chech whether it is exist*/
	if (fwrite(&add, sizeof(movie), 1, fp) == 1)
	{
		printf("Add successfully!\n");
		fclose(fp);
		return 1;
		/*add it into file*/
	}
	else
	{
		printf("Add fail!\n");
		/*output tip if fail*/
		fclose(fp);
		return 0;
	}

}

int save_c(customer add){/*save the movie in the file*/
	FILE* fpc = fopen("C:\\EEE101_Assessment4_32\\.dat", "wb+");
	customer compare;
	rewind(fpc);
	while (!feof(fpc))
	{
		fread(&compare, sizeof(customer), 1, fpc);
		if (!strcmp(compare.account_number, add.account_number))
		{
			printf("\nThe customer has existed!");
			return 0;
		}
	}
	FILE* pc;
	pc = fopen("C:\\EEE101_Assessment4_32\\customer.dat", "wb");
	rewind(pc);
	if (fwrite(&add, sizeof(customer), 1, pc) == 1)
	{
		printf("Add successfully!\n");
		fclose(pc);
		return 1;
	}
	else
	{
		printf("Add fail!\n");
		fclose(pc);
		return 0;
	}
}

void view(){/*Print stock */
	FILE* fp = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
	movie list;
	rewind(fp);
	while (fread(&list, sizeof(movie), 1, fp) != 0)
		/*get the information*/
	{
		if (strlen(list.movie_title) != 0)
			printf("\nTitle:%s  available:%d  loan:%d", list.movie_title, list.stock_statue[0], list.stock_statue[1]);
		/*print the information*/
	}
	printf("\nThat is all");
	/*show the enf*/
	fclose(fp);
	system("pause");
	return;
}


int main(){
	bool flag_home1 = true;
	bool flag_home2;
	bool flag_home3;
	bool flag = true;
	/*control different loops*/

	while (flag){
		switch (homepage())
			/*according to option the choice option*/
		{
		case 1:
			flag_home1 = true;
			/*start search*/
			while (flag_home1)
				flag_home1 = Comprehensive_search();
			break;
		case 2:
			/*manager page*/
			flag_home2 = Manager_Login();
			while (flag_home2)
				/*start manager page if log successfully*/
			{
				switch (manager_page())
					/*choose case according the manager choice*/
				{
				case 1:
					add_movie();
					break;
				case 2:
					edit_movie();
					break;
				case 3:
					delete_movie();
					break;
				case 4:
					add_customer();
					break;
				case 5:
					edit_customer();
					break;
				case 6:
					delete_customer();
					break;
				case 7:
					view();
					/*Print stock */
					break;
				case 8:
					flag_home2 = false;
					/*finish this loop*/
					break;

				}
			}
			break;

		case 3:
			flag_home3 = Worker_Login();
			/*start worker page if log successfully*/
			while (flag_home3)
			{
				switch (worker_page())
				{
				case 1:/*rent the movie*/
					; printf("\nCustomer's account number\n");
					char serve[20] = { 0 };
					scanf("%s", serve);
					int c;
					bool flag = true;
					char Title[50];
					/*get account*/
					FILE* fp = fopen("C:\\EEE101_Assessment4_32\\customer.dat", "rb+");
					customer compare = { 0 };
					rewind(fp);
					while (!feof(fp))
					{
						fread(&compare, sizeof(customer), 1, fp);
						if (!strcmp(compare.account_number, serve))
							/*find account*/
						{
							while (flag)
							{
								system("cls");
								fflush(stdin);
								printf("\n1. Rent");
								printf("\n2. Return");
								printf("\n3. Quit\n");
								scanf("%d", &c);
								/*print suvice page*/
								switch (c)
								{
								case 1:/*rent movie*/
									; bool flag_rent = false;
									printf("\nTitle:");
									scanf("%s", Title);
									FILE*p1 = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
									movie store1;
									rewind(p1);
									while (!feof(p1))
									{
										fread(&store1, sizeof(movie), 1, p1);
										if (!strcmp(store1.movie_title, Title))
											/*get movie data*/
										{
											if (store1.stock_statue[0] > 0)
												/*check whether the copies is enough*/
											{
												store1.stock_statue[0]--;
												store1.stock_statue[1]++;
												fseek(p1, -sizeof(movie), SEEK_CUR);
												fwrite(&store1, sizeof(movie), 1, p1);
												/*find the movie and change its stock startue*/
												int count = 0;
												while (strlen(*(compare.rental_history + count)) != 0)
												{
													count++;
												}
												strcpy((compare.rental_history + count), Title);
												compare.pending_charge = compare.pending_charge + store1.charge;
												/*update the pending charge automatically */
												printf("\Rent successfully!");
												flag_rent = true;
												system("pause");/*add the history in the account*/
												fclose(p1);
												break;
											}
											else
												printf("No available ");
											/*give tips if the copies is not enough*/
											system("pause");
											break;
										}
									}

									if (flag_rent == false)printf("\nThis title is not accessable!");
									/*give tips if the title doesn't exist*/
									system("pause");
									fclose(p1);
									break;
								case 2:/*return movie*/
									; char blank[20] = { 0 };
									printf("\nTitle:");
									scanf("%s", Title);
									int count = 0;
									int t = 0;
									bool find_history = false;
									while (strlen(*(compare.rental_history + count)) != 0){
										count++;
									}
									while (t <= count)
									{
										if (!strcmp((compare.rental_history + t), Title))
										{
											find_history = true;
											break;
										}
										t++;
									}
									if (find_history == false)
									{
										printf("You haven't rent this DVD!");
										system("pause");
									}
									/*check whether the DVD is rent*/
									while (find_history)
									{
										FILE*p2 = fopen("C:\\EEE101_Assessment4_32\\movie.dat", "rb+");
										movie store2;
										int fine;
										bool re = false;
										rewind(p2);
										while (!feof(p2))
										{
											fread(&store2, sizeof(movie), 1, p2);
											if (!strcmp(store2.movie_title, Title))
											{
												store2.stock_statue[0]++;
												store2.stock_statue[1]--;
												fseek(p2, -sizeof(movie), SEEK_CUR);
												fwrite(&store2, sizeof(movie), 1, p2);
												/*update the movie stock statue*/
												fclose(p2);
												strcpy((compare.rental_history + t), blank);
												fflush(stdin);
												printf("\n Fined: ");
												scanf("%d", &fine);
												compare.pending_charge = compare.pending_charge + fine;
												/*update the charge and history*/
												printf("Pending charge: %d", compare.pending_charge);
												printf("Yuan ");
												printf("\nReturn successfully!");
												/*give result*/
												re = true;
												system("pause");
												break;
											}

										}
										if (re = false)
										{
											printf("\nReturn fail!");
											/*give tips if fail*/
											system("pause");
										}
										fclose(p2);
										break;
									}
									break;
								case 3:
									flag = false;

									break;
								default:
									printf("\ nInpur error, please try again!");
									/*check the input and give the result*/
									system("pause");
									break;
								}

							}
							fseek(fp, -sizeof(customer), SEEK_CUR);
							fwrite(&compare, sizeof(customer), 1, fp);
							fclose(fp);
							system("pause");
							fclose(fp);
							break;
						}
					}
					if (strlen(compare.account_number) == 0)
					{
						printf("\nThe account doesn't existed!");
						system("pause");
					}
					fclose(fp);
					break;
				case 2:
					flag_home3 = false;
					/*finish worker loop*/
					break;
				}
			}
			break;
		case 4:
			flag = false;
			/*finish homepage loop*/
			return 0;
		}
	}
	return 0;
}