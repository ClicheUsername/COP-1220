#include <stdio.h>

typedef struct {
  char salesPersonInitial;
  int salesPersonSales;
} SalesPerson;

int main(void) {
  char salesInitial;
  int salesInput;

  int shouldExit = 0;

  // Initialize each sales person struct
  SalesPerson salesPersonD = {
    'D',
    0
  };

  SalesPerson salesPersonE = {
    'E',
    0
  };

  SalesPerson salesPersonF = {
    'F',
    0
  };

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
        salesPersonD.salesPersonSales += salesInput;
      } else if (salesInitial == 'e' || salesInitial == 'E') {
        salesPersonE.salesPersonSales += salesInput;
      } else if (salesInitial == 'f' || salesInitial == 'F') {
        salesPersonF.salesPersonSales += salesInput;
      }
      break;

    // User wants to exit, calculate total sales and print totals and highest
    // selling salesperson then exit
    case 'z':
    case 'Z': {
      int grandTotal =
      salesPersonD.salesPersonSales + salesPersonE.salesPersonSales + salesPersonF.salesPersonSales;
      printf("\nD total: %d\n", salesPersonD.salesPersonSales);
      printf("E total: %d\n", salesPersonE.salesPersonSales);
      printf("F total: %d\n", salesPersonF.salesPersonSales);

      printf("Grand Total: $%d\n", grandTotal);

      // Find which salesperson has the highest total sales
      if (salesPersonD.salesPersonSales > salesPersonE.salesPersonSales &&
        salesPersonD.salesPersonSales > salesPersonF.salesPersonSales) {
        printf("Highest Sales: D");
      } else if (salesPersonE.salesPersonSales > salesPersonD.salesPersonSales &&
        salesPersonE.salesPersonSales > salesPersonF.salesPersonSales) {
        printf("Highest Sales: E");
      } else if (salesPersonF.salesPersonSales > salesPersonD.salesPersonSales &&
        salesPersonF.salesPersonSales > salesPersonE.salesPersonSales) {
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

  return 0;
}
