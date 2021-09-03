// Chapter 5 exercise 9
// Jesse Anderson

#include <iostream.h>

struct brand{
 char *name;
 int amount;
 }AandW,Hires,IBC,Ramblin;

struct brand GetBrand();
char Menus();
void EnterInvntry(struct brand &rootbeer);
void Buy(struct brand &rootbeer);
void Sell(struct brand &rootbeer);
void Display();

void main(){
 struct brand temp;
 char tempmen;
 AandW.name="A & W Root Beer";
 Hires.name="Hires Root Beer";
 IBC.name="IBC Root Beer";
 Ramblin.name="Ramblin' Root Beer";
 do{
  tempmen = Menus();
  switch (tempmen){
	case 'E' : case 'e':
		EnterInvntry(GetBrand());
		break;
	case 'P' : case 'p':
		Buy(GetBrand());
		break;
	case 'S' : case 's':
		Sell(GetBrand());
		break;
	case 'D' : case 'd':
		Display();
		break;
	default: break;
	 }
  } while ((tempmen != 'Q') && (tempmen != 'q'));
}
struct brand GetBrand(){
 char tempbrand;
 cout << "Enter the brand of root beer you wish to enter information about: ";
 cout << "\n(A)&W\n(H)ires\n(I)BC\n(R)amblin'\n: ";
 cin >>(tempbrand);
 switch (tempbrand)
 {
  case 'A':case 'a':return AandW;
  case 'H':case 'h':return Hires;
  case 'R':case 'r':return Ramblin;
  case 'I':case 'i':return IBC;
  }
}

char Menus(){
 char choice;
 cout << "(E)nter Inventory\n";
 cout << "(P)urchase Soda\n";
 cout << "(S)ell Soda\n";
 cout << "(D)isplay inventory\n";
 cout << "(Q)uit program\n: ";
 cin >>  choice;
 return choice;
}

void EnterInvntry(struct brand &rootbeer){
 cout << "\nEnter the amount of "<<rootbeer.name<<" in stock: ";
 cin >> rootbeer.amount;
}
void Buy(struct brand &rootbeer){
 int tempamt;

 cout << "\nEnter the amount of "<<rootbeer.name<<" that you wish to buy: ";
 cin >>(tempamt);
 rootbeer.amount= rootbeer.amount + tempamt;
}
void Sell(struct brand &rootbeer){
 int tempamt;

 cout << "\nEnter the amount of "<<rootbeer.name<<" that you wish to sell: ";
 cin >>(tempamt);
 rootbeer.amount = rootbeer.amount - tempamt;
}
void Display(){
 cout << AandW.amount << " cases of "<<AandW.name<<" in stock.\n";
 cout << Hires.amount << " cases of "<<Hires.name<<" in stock.\n";
 cout << IBC.amount << " cases of "<<IBC.name<<" in stock.\n";
 cout << Ramblin.amount << " cases of "<<Ramblin.name<<" in stock.\n";
}
