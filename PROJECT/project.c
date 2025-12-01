#include<stdio.h>
#include<ctype.h>
#include<string.h>
void printmenu() {                                                            //Function to print menu
    printf(" SNACKS\tPRICE (in Rs)\n""\n""PIZZA\t195\n""BURGER\t50\n""CHOWMIEN\t120\n"
"GRILLED SANDWICH\t130\n""VEG WRAP\t90\n""\n""STARTERS\tPRICE (in RS)\n"
"PANEER TIKKA\t250\n""CHILLY PANEER\t130\n""CRISPY CORN\t290\n""CHEESE BALLS\t230\n"
"HARA BHARA KABBAB\t190\n""\n""MAIN COURSE\tPRICE (IN Rs)\n""SHAHI PANEER\t330\n"
"MANCHURIAN\t390\n""DAL TADKA\t225\n""VEG CHOWPSY\t300\n""PANEER BUTTER MASALA\t350\n"
"FRIED RICE\t210\n""NAAN\t65\n""TAWA ROTI\t15\n""VEG BIRYANI\t190\n""BREAD BASKET\t290\n"
"\n""DESERTS\tPRICE (IN Rs)\n""ICE CREAM (2 SCOOPS)\t60\n""GULAB JAMUN\t45\n""CHOCOLATE BROWNIE\t120\n"
"RASMALAI\t50\n""FRUIT CUSTARD\t150\n""\n""BEVERAGES\tPRICE (IN Rs)\n""SOFT DRINKS\t50\n"
"COLD COFFEE\t45\n""HOT COFFEE\t35\n""SHAKE\t(MANGO, CHOCOLATE,  BUTTERSCOTCH, OREO)\t90\n");
}
struct Item {                                                                  //Declaration of structure
  char name[50];                                                               //Varaiable to store item name    
  float price;                                                                 //Variable to store item price
  int quantity;                                                                //Variable to store item's quantity 
};
struct Item menu[]={                                                            //Defining restaurant's menu {"item",price,0(default quantity)}                                        
    {"PIZZA",195,0},{"BURGER",50,0},{"CHOWMIEN",120,0},{"GRILLED SANDWICH",130,0},
{"VEG WRAP",90,0},{"PANEER TIKKA",250,0},{"CHILLY PANEER",130,0},{"CRISPY CORN",290,0},
{"CHEESE BALLS",230,0},{"HARA BHARA KABBAB",190,0},{"SHAHI PANEER",330,0},
{"MANCHURIAN",390,0},{"DAL TADKA",225,0},{"VEG CHOWPSY",300,0},{"PANEER BUTTER MASALA",350,0},
{"FRIED RICE",210,0},{"NAAN",65,0},{"TAWA ROTI",15,0},{"VEG BIRYANI",190,0},{"BREAD BASKET",290,0},
{"ICE CREAM",60,0},{"GULAB JAMUN",45,0},{"CHOCOLATE BROWNIE",120,0},{"RASMALAI",50,0},{"FRUIT CUSTARD",150,0},
{"SOFT DRINKS",50,0},{"COLD COFFEE",35,0},{"HOT COFFEE",35,0},{"SHAKE",90,0}
};
void takeorder(struct Item orders[],int n) {                                    //Function to take order from the customer    
    for(int i=0;i<n;i++) {                                                      //Loop to collect order one by one
        printf("Enter the item:\n");                                            //Asking user to enter the item
        scanf(" %[^\n]", orders[i].name);                                       //Accepting value from user
        printf("Enter the quantity:\n");                                        //Asking user to enter quantity
        scanf("%d", &orders[i].quantity);                                       //Accepting value from the user
        for(int k = 0; orders[i].name[k] != '\0'; k++) {                        //Loop to convert each letter into uppercase 
           orders[i].name[k] = toupper(orders[i].name[k]);  
        }
        int found = 0;
        for(int j = 0; j < sizeof(menu)/sizeof(menu[0]); j++) {                 //Loop to compare the item ordered that whether it is present in the menu
            if(strcmp(orders[i].name,menu[j].name) == 0) {     
               orders[i].price = menu[j].price;                                  //If yes,storing its price
               found = 1;
               break;
            }
        }
    }
}
void printorder(struct Item orders[],int n) {                                   //Function to confirm customer's order
    int i;
    printf("Reconfirming your order.\nYou ordered\n");
    for(i = 0; i < n;i++) {                                                      //Loop to print the order
        printf("%s", orders[i].name);
        printf("%d", orders[i].quantity);
        printf("\n");
    }
}
void printbill(struct Item orders[],int n) {                                     //Function to print bill
    float subtotal = 0.0;
    printf("\n==============BILL===============\n");
    printf("\n");
    printf("%s %23s %24s %34s", "Sr.No.", "Item", "Qty", "Amount");
    printf("\n");
    for(int i = 0; i < n;i++) {
    int j = i + 1;
    float amount = orders[i].price * orders[i].quantity;
    subtotal = subtotal + amount;
    printf("%d   %26s %23d  %35.2f\n", j, orders[i].name, orders[i].quantity, amount);
    }
  float tax = subtotal * 0.05;
  float total = subtotal + tax;
  printf("\n");
  printf("Subtotal:                     Rs %.2f\n", subtotal);
  printf("Tax (5%%):                     Rs %.2f\n", tax);
  printf("Total Bill:                   Rs %.2f\n", total);
  printf("\n");
  printf("Thank you for the visit.I Hope you enjoyed dining with us.!\n");
  printf("\n");
}
int main() {
    printf("Welcome to the Restaurant\n");                                       //Greeting the customer
    int n,m,s,a;                                                                 //Declaration
    char ch;                                                                     //Declaration
    printmenu();                                                                 //Calling the function to print menu
    struct Item orders[30];
    printf("How many items you want to order initially.\n");
    scanf("%d", &n);
    int quantity[n];
    takeorder(orders,n);                                                         //Calling the function to take order
    printorder(orders,n);                                                        //Calling the function to confirm order
    printbill(orders,n);                                                         //Calling the function to print billl
    return 0;
}
