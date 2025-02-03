#include <stdio.h>

int main(void) {
  char salesInitial;
  int salesInput;
  int dSales = 0, eSales = 0, fSales = 0;
  int shouldExit = 0;

  // Repeat until shouldExit = 1
  do {
    printf("Salesperson: ");
    scanf(" %c", &salesInitial);

    switch (salesInitial) {
      // Valid salesperson initial, prompt for sale amount and add to that salesperson's count
      case 'd': case 'D':
      case 'e': case 'E':
      case 'f': case 'F':
        printf("Sale: ");
        scanf("%d", &salesInput);

        // Add salesInput to salesperson's total
        if (salesInitial == 'd' || salesInitial == 'D') {
            dSales += salesInput;
        } else if (salesInitial == 'e' || salesInitial == 'E') {
            eSales += salesInput;
        } else if (salesInitial == 'f' || salesInitial == 'F') {
            fSales += salesInput;
        }
      break;

      // User wants to exit, calculate total sales and print totals and highest selling salesperson then exit
      case 'z': case 'Z':
        int grandTotal = dSales + eSales + fSales;
        printf("\nD total: %d\n", dSales);
        printf("E total: %d\n", eSales);
        printf("F total: %d\n", fSales);

        printf("Grand Total: $%d\n", grandTotal);

        // Find which salesperson has the highest total sales
        if (dSales > eSales && dSales > fSales) {
            printf("Highest Sales: D");
        } else if (eSales > dSales && eSales > fSales) {
            printf("Highest Sales: E");
        } else if (fSales > dSales && fSales > eSales) {
            printf("Highest Sales: F");
        }

        shouldExit = 1;
      break;

      // Invalid salesperson, prompt for another
      default:
        printf("Error, invalid salesperson selected, please try again.\n");
        break;
    }
  } while (!shouldExit);

  return 0;
}
