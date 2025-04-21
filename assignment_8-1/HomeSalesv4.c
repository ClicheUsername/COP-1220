#include <stdio.h>

typedef struct {
  char salesPersonInitial;
  int salesPersonSales;
} SalesPerson;

int main(void) {
  char salesInitial;
  int salesInput;
  int shouldExit = 0;

  // Initialize each sales person file
  FILE *dSalesFile = fopen("dSales.txt", "w+");
  FILE *eSalesFile = fopen("eSales.txt", "w+");
  FILE *fSalesFile = fopen("fSales.txt", "w+");

  fprintf(dSalesFile, "0");
  fprintf(eSalesFile, "0");
  fprintf(fSalesFile, "0");
  
  rewind(dSalesFile);
  rewind(eSalesFile);
  rewind(fSalesFile);
  
  // Repeat until shouldExit = 1
  do {
    printf("Salesperson: ");
    scanf(" %c", &salesInitial);

    switch (salesInitial) {
    // Valid salesperson initial, prompt for sale amount and add to that
    // salesperson's count
    case 'd':
    case 'D':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
      printf("Sale: ");
      scanf("%d", &salesInput);

      // Add salesInput to salesperson's total
      if (salesInitial == 'd' || salesInitial == 'D') {
        int dSales;
        fscanf(dSalesFile, "%d", &dSales);
        rewind(dSalesFile);
        fprintf(dSalesFile, "%d", dSales + salesInput);
        rewind(dSalesFile);
      } else if (salesInitial == 'e' || salesInitial == 'E') {
        int eSales;
        fscanf(eSalesFile, "%d", &eSales);
        rewind(eSalesFile);
        fprintf(eSalesFile, "%d", eSales + salesInput);
        rewind(eSalesFile);
      } else if (salesInitial == 'f' || salesInitial == 'F') {
        int fSales;
        fscanf(fSalesFile, "%d", &fSales);
        rewind(fSalesFile);
        fprintf(fSalesFile, "%d", fSales + salesInput);
        rewind(fSalesFile);
      }
      break;

    // User wants to exit, calculate total sales and print totals and highest
    // selling salesperson then exit
    case 'z':
    case 'Z': {
      SalesPerson salesPersonD = {'D', 0};

      SalesPerson salesPersonE = {'E', 0};

      SalesPerson salesPersonF = {'F', 0};

      rewind(dSalesFile);
      rewind(eSalesFile);
      rewind(fSalesFile);
      
      fscanf(dSalesFile, "%d", &salesPersonD.salesPersonSales);
      fscanf(eSalesFile, "%d", &salesPersonE.salesPersonSales);
      fscanf(fSalesFile, "%d", &salesPersonF.salesPersonSales);

      int grandTotal = salesPersonD.salesPersonSales +
                       salesPersonE.salesPersonSales +
                       salesPersonF.salesPersonSales;
      printf("\nD total: %d\n", salesPersonD.salesPersonSales);
      printf("E total: %d\n", salesPersonE.salesPersonSales);
      printf("F total: %d\n", salesPersonF.salesPersonSales);

      printf("Grand Total: $%d\n", grandTotal);

      // Find which salesperson has the highest total sales
      if (salesPersonD.salesPersonSales > salesPersonE.salesPersonSales &&
          salesPersonD.salesPersonSales > salesPersonF.salesPersonSales) {
        printf("Highest Sales: D");
      } else if (salesPersonE.salesPersonSales >
                     salesPersonD.salesPersonSales &&
                 salesPersonE.salesPersonSales >
                     salesPersonF.salesPersonSales) {
        printf("Highest Sales: E");
      } else if (salesPersonF.salesPersonSales >
                     salesPersonD.salesPersonSales &&
                 salesPersonF.salesPersonSales >
                     salesPersonE.salesPersonSales) {
        printf("Highest Sales: F");
      }

      shouldExit = 1;
      break;
    }
    // Invalid salesperson, prompt for another
    default:
      printf("Error, invalid salesperson selected, please try again.\n");
      break;
    }
  } while (!shouldExit);

  fclose(dSalesFile);
  fclose(eSalesFile);
  fclose(fSalesFile);

  return 0;
}
