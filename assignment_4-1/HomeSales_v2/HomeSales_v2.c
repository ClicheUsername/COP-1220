#include <stdio.h>

int main(void) {
  char salesInitial;
  int salesInput;

  char salesPerson[3];
  int salesPersonSales[3];
  int shouldExit = 0;

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
        salesPerson[0] = 'D';
        salesPersonSales[0] += salesInput;
      } else if (salesInitial == 'e' || salesInitial == 'E') {
        salesPerson[1] = 'E';
        salesPersonSales[1] += salesInput;
      } else if (salesInitial == 'f' || salesInitial == 'F') {
        salesPerson[2] = 'F';
        salesPersonSales[2] += salesInput;
      }
      break;

    // User wants to exit, calculate total sales and print totals and highest
    // selling salesperson then exit
    case 'z':
    case 'Z': {
      int grandTotal =
          salesPersonSales[0] + salesPersonSales[1] + salesPersonSales[2];
      printf("\nD total: %d\n", salesPersonSales[0]);
      printf("E total: %d\n", salesPersonSales[1]);
      printf("F total: %d\n", salesPersonSales[2]);

      printf("Grand Total: $%d\n", grandTotal);

      // Find which salesperson has the highest total sales
      if (salesPersonSales[0] > salesPersonSales[1] &&
          salesPersonSales[0] > salesPersonSales[2]) {
        printf("Highest Sales: D");
      } else if (salesPersonSales[1] > salesPersonSales[0] &&
                 salesPersonSales[1] > salesPersonSales[2]) {
        printf("Highest Sales: E");
      } else if (salesPersonSales[2] > salesPersonSales[0] &&
                 salesPersonSales[2] > salesPersonSales[1]) {
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
