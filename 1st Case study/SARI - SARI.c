#include <stdio.h>
#include <string.h>
#include <conio.h>

int a = 0, i = 0, bquantity[100];
char basketlist[100][50];
float Pbasket[100];

void UpdateStock(){}

void grid(){
 for (i=0;i<80;i++){
 textcolor(YELLOW);
 gotoxy(i,1);
 cprintf ("Ò");}
 for (i=0;i<80;i++){
 gotoxy(i,24);
 cprintf ("Ò");}
 for (i=2;i<24;i++){
 gotoxy(1,i);
 cprintf ("³");
 }
 for (i=2;i<24;i++){
 gotoxy(79,i);
 cprintf("³");
 }
}

void NNFuctStock(char stock[50][10], int Pricestock[50]) {
    system ("cls");
    printf("================================================\n");
    printf("\tSTOCK\n");
    printf("================================================\n");
    for (i = 32; i < 50 && stock[i][0] != '\0'; i++) {
	printf("%d = %s | %i\n", i + 1, stock[i], Pricestock[i]);
    }

    printf("================================================\n");
}

void NFuctStock(char stock[50][10], int Pricestock[50]) {
    system ("cls");
    printf("================================================\n");
    printf("\tSTOCK\n");
    printf("================================================\n");
    for (i = 16; i < 31 && stock[i][0] != '\0'; i++) {
	printf("%d = %s | %i\n", i + 1, stock[i], Pricestock[i]);
    }

    printf("================================================\n");
}

void FuctStock(char stock[50][10], int Pricestock[50]) {
    system ("cls");
    printf("================================================\n");
    printf("\tSTOCK\n");
    printf("================================================\n");
    for (i = 0; i < 15 && stock[i][0] != '\0'; i++) {
	printf("%d = %s | %i\n", i + 1, stock[i], Pricestock[i]);
    }

    printf("================================================\n");
}

void ReItem(char item[15][10][50], int choice){
FILE *tempF, *file, *tempP, *fileP;
int line=0, Pline = 0;
char name[25], tempFile[27], filename[25], Pfile[25], Ptemp[27],buffer[50], delI[10];
printf ("NAME OF ITEM LIKE TO REMOVE: ");
scanf ("%s",name);
sprintf(filename,"%s.txt",item[choice - 1][0]);
strcpy(tempFile, "temp_");
strcat(tempFile,filename);
sprintf(Pfile,"P%s",filename);
sprintf(delI,"%s.txt",name);
strcpy(Ptemp,"tempP_");
strcat(Ptemp,Pfile);
file = fopen(filename,"r");
tempF = fopen(tempFile,"w");
tempP = fopen(Ptemp,"w");
fileP = fopen (Pfile,"r");
if (tempF == NULL || file == NULL || tempP == NULL || fileP == NULL){
    printf ("\nNO FILE FOUND\n");
    return;
}

 while (fgets(buffer, sizeof(buffer), file) != NULL) {
	if (strcmp(buffer, name) != 0) {
	    fputs(buffer, tempF); line++;
	}else {fputs('\0',tempF);}
    }
 while (fgets(buffer, sizeof(buffer), fileP) != NULL) {
	if (line != Pline) {
	    fputs(buffer, tempP); Pline++;
	}else {fputs('\0',tempP);}
    }
fclose(file);
fclose(tempF);
fclose(fileP);
fclose(tempP);

remove(delI);
remove(Pfile);
rename(Ptemp, Pfile);
remove(filename);
rename(tempFile, filename);
return;
}

void AddItem(int choice, char item[15][10][50]) {
    float temprice;
    char tempName[25], buffer[27], buff2[27], buffP[27], buffI[100];
    int foundDuplicate = 0, i;
    FILE *ITEMFILE, *ADDTOITEM, *PRICE;

    printf("NAME OF THE ITEM :: ");
    scanf("%s", tempName);

    for (i = 0; i < 10; i++) {
	if (strcmp(item[choice - 1][i], tempName) == 0) {
	    foundDuplicate = 1;
	    continue;
	}
    }

    if (foundDuplicate == 1) {
	printf("\nITEM IS ALREADY IN THE %s\n", item[choice - 1][0]);
    } else {
	printf("PRICE OF ITEM:: ");
	scanf("%f", &temprice);
	printf("INFORMATION OF THE ITEM\n:");
	scanf(" %[^\n]", buffI);

	sprintf(buffP, "P%s.txt", item[choice - 1][0]);
	sprintf(buffer, "%s.txt", tempName);
	sprintf(buff2, "%s.txt", item[choice - 1][0]);

	ITEMFILE = fopen(buffer, "w");
	ADDTOITEM = fopen(buff2, "a");
	PRICE = fopen(buffP, "a");

	fprintf(ADDTOITEM, "\n%s", tempName);
	fprintf(PRICE, "\n%.2f", temprice);
	fprintf(ITEMFILE, "\n\n%s", buffI);

	fclose(PRICE);
	fclose(ITEMFILE);
	fclose(ADDTOITEM);
	printf("\n%s\n", item[choice - 1][0]);
    }
}

void removeCat() {
    char name[25], Pname[25], temp[15], filename[10], buff[50], delP[10], delI[10], Pfilename[10], Ptemp[15];
    FILE *tempF, *file, *Pfile, *tempP;

    printf("NAME OF ITEM WOULD YOU LIKE TO REMOVE: ");
    scanf("%s", name);

    strcpy(Pfilename,"X.txt");
    strcpy(Ptemp,"Ptemp_");
    strcat(Ptemp,Pfilename);
    strcpy(filename, "Y.txt");
    strcpy(temp, "temp_");
    strcat(temp, filename);
    sprintf(delP,"P%s.txt", name);
    sprintf(delI,"%s.txt", name);
    sprintf(Pname,"P%s",name);
    tempF = fopen(temp, "w");
    file = fopen(filename, "r");
    tempP = fopen(Ptemp,"w");
    Pfile = fopen(Pfilename,"r");


    if (tempF == NULL || file == NULL || Pfile == NULL || tempP == NULL) {
	printf("Error opening files.\n");
	return;
    }

    while (fgets(buff, sizeof(buff), file) != NULL) {
	if (strcmp(buff, name) != 0) {
	    fputs(buff, tempF);
	}else {fputs('\0',tempF);}
    }
      while (fgets(buff, sizeof(buff), Pfile) != NULL) {
	if (strcmp(buff, Pname) != 0) {
	    fputs(buff, tempP);
	}else {fputs('\0',tempP);}
    }

    fclose(file);
    fclose(tempF);
    fclose(tempP);
    fclose(Pfile);

    remove(delI);
    remove(delP);

    remove(Pfilename);
    remove(filename);
    rename(temp, filename);
    rename(Ptemp, Pfilename);
}

void addtoCat(char item[15][10][50], char name[25]) {
int foundDuplicate;
char filename[25];
FILE *categories = fopen("Y.txt","a");
FILE   *PRICE = fopen("X.txt","a");
printf ("\nNAME OF CATEGORY :");
scanf ("%s",name);
for (i = 0; i < 15 && item[i][0][0] != '\0'; i++) {
if (strcmp(item[i][0], name) == 0) {
foundDuplicate = 1;
break;}
}
if (foundDuplicate == 1) {
printf("\nCATEGORY IS TAKEN\n");
}else{
sprintf (filename,"P%s",name);
fprintf (PRICE, "\n%s",filename);
fprintf(categories,"\n%s",name);
fclose(PRICE);
fclose(categories);
sprintf (filename, "%s.txt", name);
categories = fopen(filename,"w");
fclose (categories);
sprintf (filename, "P%s.txt", name);
categories = fopen(filename,"w");
fclose(categories);
}
}

void LoadtoArray(char item[15][10][50], float PriceItem[15][10], char stock[50][10], int Pricestock[25]) {
    int category, j;
    char categories[25];
    FILE *items = fopen("Y.txt", "r");

    if (items == NULL) {
	items = fopen("Y.txt", "w");
	printf("\nRESTART YOUR SYSTEM PLEASE\n");
	return;
    }
    for (category = 0; category < 15; category++) {
	fscanf(items, "%24s", item[category][0]); // Specify max length to prevent overflow
    }

    fclose(items);

    for (i = 0; i < category; i++) {
	sprintf(categories, "%s.txt", item[i][0]);
	items = fopen(categories, "r");

	for (j = 1; j < 10; j++) {
	    fscanf(items, "%24s", item[i][j]); // Specify max length
	}
	fclose(items);
    }

     for (i = 0; i < category; i++) {
	sprintf(categories, "P%s.txt", item[i][0]);
	items = fopen(categories, "r");

	for (j = 1; j < 10; j++) {
	    if (fscanf(items, "%f", &PriceItem[i][j]) != 1) {
		printf("Error reading data from category file\n");
		break;
	    }
	}

	fclose(items);
    }

     items = fopen("STOCK.txt", "r");
    if (items == NULL) {
	items = fopen("STOCK.txt", "w");
	printf("\nRESTART YOUR SYSTEM PLEASE\n");
	return;
    }

    for (i = 0; i < 50; i++) {
	fscanf(items, "%9s", stock[i]); // Specify max length
    }

    fclose(items);

    items = fopen("Pstock.txt", "r");
    if (items == NULL) {
	items = fopen("Pstock.txt", "w");
	printf("\nRESTART YOUR SYSTEM PLEASE\n");
	return;
    }

    for (i = 0; i < 50; i++) {
	fscanf(items, "%d", &Pricestock[i]); // Use %d for integers
    }
    fclose(items);
}

void PdisplayAll(char name[50], float total) {
    float some = 0;
    FILE *newfile = fopen("RECEIT.txt","a");
    if (newfile == NULL) {
    printf ("RETART SYSTEM");
    newfile = fopen ("RECEIT.txt","w");
    }
    fprintf(newfile,"\n\n\n\n\nNAME: %s\n", name);
    fprintf(newfile,"==============================================================================\n");
    fprintf(newfile,"\t\tRECEIPT\n");
    fprintf(newfile,"==============================================================================\n");

    for (i = 0; i < a; i++) {
	    some = (Pbasket[i] * bquantity[i]);
	total += (Pbasket[i] * bquantity[i]);
	fprintf(newfile," %-50s   |  %.2f x %i = %.2f\n", basketlist[i], Pbasket[i], bquantity[i],some);
    }

    fprintf(newfile,"==============================================================================\n");
    fprintf(newfile,"\n\t\t\t\t\t\t\tTOTAL:     %.2fPhp ", total);
fclose (newfile);
}

void displayAll(char name[50], float total) {
    float some = 0;

    system("cls");
    printf("\nNAME: %s\n", name);
    printf("==============================================================================\n");
    printf("\t\tRECEIPT\n");
    printf("==============================================================================\n");

    for (i = 0; i < a; i++) {
	    some = (Pbasket[i] * bquantity[i]);
	total += (Pbasket[i] * bquantity[i]);
	printf(" %-50s   |  %.2f x %i = %.2f\n", basketlist[i], Pbasket[i], bquantity[i],some);
    }

    printf("==============================================================================\n");
    printf("\n\t\t\t\t\t\t\tTOTAL:     %.2fPhp ", total);
}

void AskName(int choice, char name[50]) {
    printf("Would you like to add your name? \n 1 = YES\n 0 = NO\n");
    scanf("%i", &choice);

    if (choice >= 1) {
	printf("\nNAME: ");
	scanf(" %[^\n]", name);
    }

    if (choice == 0) {
	name = "USER";
    }
}

void DisplayBasket() {
    int des, exit = 1;
    system("cls");

    printf("\nItems in your basket:\n");
    printf("===============================================================================\n");
    for (i = 0; i < a && basketlist[i][0] != '\0'; i++) {
	printf("%i = %-20s | %i\n", i + 1, basketlist[i], bquantity[i]);
    }
    printf("===============================================================================\n");
    printf("\nWOULD YOU LIKE TO REMOVE AN ITEM? \n 1 = YES\n 0 = NO\n::");
    scanf("%i", &des);

    if (des == 1) {
	while (exit > 0) {
	    system("cls");
	    printf("\nItems in your basket:\n");
	    printf("===========================================================================");
	    for (i = 0; i < a; i++) {
		printf("%i = %s\n", i + 1, basketlist[i]);
	    }
	    printf("===========================================================================\n");
	    printf("\nWhat number would you like to remove?\n::");
	    scanf("%i", &des);

	    if (des == 0) {
		break;
	    }

	    basketlist[des - 1][0] = '\0';
	    bquantity[des - 1] = 0;
	    Pbasket[des - 1] = 0;

	    printf("Remove more? \n1 = Yes\n0 = No\n");
	    scanf("%i", &exit);
	}
    }
}

void Basket(int choice, char item[15][10][50], int numItem, float PriceItem[15][10]) {
    int des, quantity;
    char fileName[50], line[100], foundDuplicate = 0, j;
    FILE *ItemInfo;
    textcolor(WHITE);
    cprintf("YOU HAVE PICKED :");textcolor(RED);cprintf(" %s"  , item[choice - 1][numItem]);
    printf("\nDO YOU WANT TO ADD THIS TO THE BASKET? OR GIVE INFORMATION?\n 1=ADD TO BASKET\n 2=INFORMATION\n 0=EXIT\n");
    scanf("%i", &des);

    if (des == 2) {
	sprintf(fileName, "%s.txt", item[choice - 1][numItem]);
	ItemInfo = fopen(fileName, "r");

	if (ItemInfo == NULL) {
	    printf("Error opening file %s for reading\n", fileName);
	    return;
	}

	system("cls");
	printf("Information for %s:\n", item[choice - 1][numItem]);

	while (fgets(line, sizeof(line), ItemInfo) != NULL) {
	    printf("%s", line);
	}

	printf("\n\nAdd to basket? \n1=Add to basket\n0=Exit\n: ");
	scanf("%i", &des);
    }

    if (des == 1) {
	printf("\nHow many would you like?\n");
	scanf("%i", &quantity);
	a++;

	for (i = 0; i < a && basketlist[i][0] != '\0'; i++) {
	    // Loop until an empty slot is found
	}

	if (i == 0) {
	    strcpy(basketlist[i], item[choice - 1][numItem]);
	    Pbasket[i] = PriceItem[choice - 1][numItem];
	    bquantity[i] = quantity;
	    printf("\nAdded the item to the basket\n");
	} else {
	    // Check if the item is already in the basket
	    sprintf(fileName, "%s", item[choice - 1][numItem]);

	    // Iterate through all items in the basket
	    for (j = 0; j < a && basketlist[j][0] != '\0'; j++) {
		if (strcmp(basketlist[j], fileName) == 0) {
		    foundDuplicate = 1;
		    break;
		}
	    }

	    if (foundDuplicate == 1) {
		for (j=0;j < a && basketlist[j][0] != '\0'; j++){
		if (strcmp(basketlist[j], fileName) == 0){
		  bquantity[j] += quantity;}
			}
		printf("\nItem already in the basket\n");

	    } else {
		strcpy(basketlist[i], item[choice - 1][numItem]);
		Pbasket[i] = PriceItem[choice - 1][numItem];
		bquantity[i] = quantity;
		printf("\nAdded the item to the basket\n");
	    }
	}
    }
}

void DisplayItem(char item[15][10][50], int choice, int itemlist, float PriceItem[15][10]) {
    system("cls");
    textcolor(CYAN);
    cprintf("================================================================================");
    printf("\t\t\t\t\t%s\n", item[choice - 1]);
    cprintf("================================================================================");

    for (i = 1; i < itemlist; i++) {
	if (item[choice - 1][i][0] == '\0') {
	    break;
	}
	printf("%i = %-30s |    %.2fPhp \n", i, item[choice - 1][i], PriceItem[choice - 1][i]);
    }

    cprintf("================================================================================\n");
}
void DisplayCategories(char item[15][10][50]) {
    textcolor(GREEN);
    cprintf("================================================================================");
    printf("\t\t\t\t  CATEGORIES\n");
    textcolor(GREEN);
    cprintf("================================================================================");
    for (i = 0; i < 15 && item[i][0][0] != '\0'; i++) {
	printf("%d = %s\n", i + 1, item[i][0]);
    }
    textcolor(GREEN);
    cprintf("================================================================================\n");
}

void TITLE() {
    system("cls");
    textcolor(YELLOW);
    cprintf("================================================================================");
    textcolor(WHITE);
    printf("\t\t\t\tSARI SARI STORE\n");
    textcolor(YELLOW);
    cprintf("================================================================================");
}

void main() {
    char name[50];
    int Pricestock[25],choice, numItem, quit = 0;
    float total = 0;
    float PriceItem[15][10];
    char item[15][10][50];
    char stock[50][10];

    LoadtoArray(item,PriceItem,stock, Pricestock);
    system("cls");
    grid();
    gotoxy(1,10);
    textcolor(YELLOW);
    cprintf ("³=============================================================================");
    gotoxy (30,4);
    textcolor(BROWN);
    cprintf("NAME:");
    scanf("%s",name);
    gotoxy(30,5);
    textcolor(RED);
    cprintf ("NUMBERS ONLY");
    gotoxy(30,6);
    textcolor(BROWN);
    cprintf ("PASSWORD:");
    scanf("%i",&numItem);

   if (strcmp(name, "ADMIN") == 0 && numItem == 12345) {
    // Your code here for the case where the name is "ADMIN" and the password is 12345
	    quit = 0;
	    while (quit == 0){
		LoadtoArray(item, PriceItem, stock, Pricestock);
		TITLE();
		DisplayCategories(item);
		printf(" 1 = ADD CATEGORY\n 2 = REMOVE CATEGORY\n 3 = PICK A CATEGORY\n 4 = CHECK STOCK\n 0 = EXIT CHOICE :: ");
		scanf("%i", &choice);
		if (choice == 1) {
	    addtoCat(item,name);
	    continue;
	    }

		if (choice == 2) {
	    removeCat();
	    return;
		}


		if (choice == 3) {
		    system("cls");
		    DisplayCategories(item);
		    printf("0 = EXIT\nCHOOSE ONE:  ");
		    scanf("%i", &choice);
		    DisplayItem(item, choice, sizeof(item[choice - 1]) / sizeof(item[choice - 1][0]), PriceItem);
		    printf("\n 1 = ADD ITEM\n 2 = REMOVE AN ITEM\n 0 = EXIT\n CHOICE ::");
		    scanf("%i", &numItem);
		    if (numItem == 1) {
			    AddItem(choice,item);
			    continue;
		    }

		    if (numItem == 2) {
			    ReItem(item,choice);
			    return;
		    }

		    if (numItem == 0 || choice > 3) {
					break;
				    }

		}
			if (choice == 4) {
			FuctStock(stock,Pricestock);
			printf("WOULD YOU LIKE TO\n 1 = ADD\n 2 = REMOVE\n 3 = NEXT\n any key = EXIT\n ::");
			scanf("%i",&choice);
			switch(choice){
		    case 1:
			printf ("sunod na yan");
			break;
		    case 2:
			printf ("sunod na yan");
			break;
		    case 3:
				NFuctStock(stock,Pricestock);
				printf("WOULD YOU LIKE TO\n 1 = ADD\n 2 = REMOVE\n 3 = NEXT\n 0 = EXIT\n");
				scanf("%i",&choice);
					switch(choice){
			    case 1:
				printf ("sunod na yan");
				break;
			    case 2:
				printf ("sunod na yan");
				break;
			    case 3:
					NNFuctStock(stock,Pricestock);
					printf("WOULD YOU LIKE TO\n 1 = ADD\n 2 = REMOVE\n 0 = EXIT\n");
					scanf("%i",&choice);
					default:
					break;
					    }
		    default:
			break;
			}
		}

		if (choice == 0 || choice > 5) {
		    break;
		}
 printf ("\nDo you really want to exit\n 0 = NO\n 1 = YES :: ");
 scanf ("%i",&quit);
	    }
	}
else {
	LoadtoArray(item, PriceItem, stock, Pricestock);

	while (quit == 0) {
	    TITLE();
	    DisplayCategories(item);
	    printf("0 = EXIT\nCHOOSE ONE:  ");
	    scanf("%i", &choice);

	    if (choice > 0) {
		DisplayItem(item, choice, sizeof(item[choice - 1]) / sizeof(item[choice - 1][0]), PriceItem);
	    } else {
		break;
	    }
	    textcolor(BLUE);
	    cprintf("WHAT WOULD YOU LIKE TO BUY?  ");
	    scanf("%i", &numItem);

	    if (numItem != 0 || numItem > 0) {
		Basket(choice, item, numItem, PriceItem);
	    } else {
		continue;
	    }

	    DisplayBasket();
	    printf("\n\nWould you like to take out all you've ordered? \n1 = YES \n0 = NO \nchoice: ");
	    scanf("%i", &quit);
	}
	UpdateStock();
	system("cls");
	AskName(choice, name);
	displayAll(name, total);
	PdisplayAll(name, total);
    }
    getch();
}
