/*
PROGRAM DESCRIPTION:
After prompting the user for details about their shopping needs, this program computes the total cost and item cost (e.g. cost per banana, for a person buying bananas).

NOTE TO STUDENTS:
The program is not yet finished! You will need to write the remainder of the program (find the "TODO" comments below and fill in your own code).

ABOUT:
This exercise in using operators and control structures was created by Scott Feister, February 2024 (updated Feb 2025) for Moorpark CS M125. Updated on September 22, 2024 for fruits-only and fixed-quantities to help avoid confusion.
*/

#include <iostream>
using namespace std;

int main() {
  // COST FOR FRUIT WHEN BOUGHT INDIVIDUALLY
  const int price_banana = 40; // cents for a single banana, if bought alone
  const int price_apple = 80; // cents for a single apple, if bought alone
  const int price_watermelon = 300; // cents for a single watermelon
  // By design, no multi-watermelon option exists (you don't buy crates of watermelons at a grocery store, am I right?)

  // COST FOR FRUIT WHEN BOUGHT IN PACKAGING
  const double price_bunch_bananas = 2.0; // dollars for a bunch of seven bananas
  const double price_bag_apples = 3.0; // dollars for a bag of eight apples

  // DECLARE OR INITIALIZE OTHER VARIABLES FOR FUTURE USAGE
  string product_type; // product name (e.g. 'banana', 'watermelon', or 'apple')
  string unit_type; // unit name (e.g. 'single', 'bag', or 'bunch')
  int quantity; // number of units of produce which will be purchased
  double total_cost = 0.0; // this variable will hold the cost of your total purchase
  double item_cost = 0.0; // this variable will hold the averaged cost per item (e.g. the cost of a single banana)
  string accept_sale; // whether the user accepted the sale offer

  // PROMPT USER TO INPUT DESIRED TYPE AND QUANTITY OF PRODUCT
  cout << "Enter name of product as a string (e.g. 'apple', 'banana', "
          "'watermelon'): ";
  cin >> product_type;
  cout << "Enter the unit of product, as a string (e.g. 'bunch', 'bag', 'single'): ";
  cin >> unit_type;
  cout << "Enter the number of units, as a positive integer: ";
  cin >> quantity;

  // OFFER USER AN OPTIONAL DISCOUNT
  cout << "Congratulations! You've been selected for a special promotion! Would you like to add one more unit to your cart and receive a 10% discount overall (y/n)?";
  cin >> accept_sale;

  // DO NOT EDIT ABOVE THIS LINE!

  // TODO: Finish this program to compute total price, and price per item!
  // TODO: Edit freely and significantly expand all code below
  // The code below is yours to delete, rewrite how you please!

  // TODO: INPUT VALIDATION
  // Print error statements if any of the inputs or combinations of inputs are invalid!

  if (quantity <= 0) {
    cout << "Invalid quantity entered! Quantity must be greater than zero. Aborting." << endl; // (this is an example of how I'd like you to print error messages for this lab)
    return 1; // abort
  }

  if (accept_sale != "y" && accept_sale != "n" && accept_sale != "Y" && accept_sale != "N") {
    cout << "Invalid promo input! Must be 'y' or 'n'." << endl; 
    return 1;
  }

  int items_per_unit = 0; 
  double price_per_unit = 0.0;

  if (product_type == "banana") {
    if (unit_type != "single" && unit_type != "bunch") {
      cout << "Invalid unit! Bananas must be 'single' or 'bunch'." << endl;
      return 1;
      }
      price_per_unit = (unit_type == "single") ? (price_banana / 100.0) : price_bunch_bananas;
      items_per_unit = (unit_type == "single") ? 1 : 7;
    }
  else if (product_type == "apple") {
    if (unit_type != "single" && unit_type != "bag") {
      cout << "Invalid unit! Apples must be 'single' or 'bag'. Aborting." << endl;
      return 1;
    }
    price_per_unit = (unit_type == "single") ? (price_apple / 100.0) : price_bag_apples;
    items_per_unit = (unit_type == "single") ? 1 : 8;
  } 
  else if (product_type == "watermelon") {
    if (unit_type != "single") {
      cout << "Invalid unit! Watermelon must be 'single'. Aborting." << endl;
      return 1;
    }
    price_per_unit = price_watermelon / 100.0;
    items_per_unit = 1;
  } 
  else {
    cout << "Invalid product! Choose 'apple', 'banana', or 'watermelon'. Aborting." << endl;
    return 1;
  }
  if (accept_sale == "y" || accept_sale == "Y") {
    quantity += 1;
    total_cost = (quantity * price_per_unit) * 0.90; // Calculate with 10% discount
  } else {
    total_cost = quantity * price_per_unit;
  }

  item_cost = total_cost / (quantity * items_per_unit);
      
  // DO NOT EDIT BELOW THIS LINE!

  // TELL USER THEIR FINAL TOTAL COST, AND COST PER FRUIT ITEM
  cout << "Your total cost will be : $" << total_cost << endl;
  cout << "Your cost per " << product_type << " will be : $" << item_cost
       << endl;

  return 0;
}
