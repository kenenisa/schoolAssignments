//
//  main.cpp
//  Programming assignment
//
//  Created by kenenisa on 21/11/2022.
//

#include <iostream>

using namespace std;

int main() {
    // insert code here...
    cout << "Kenenisa winter supply store"<<endl;
    cout <<endl;
    cout <<endl;
   
    
    float milk_price = 6.25;
    float bread_price = 2.25;
    float discounted_bread_price = 1.5;
    float half_eggs_price = 2.0;
    float full_eggs_price = 3.5;
    float toilet_paper_5_price = 1.99;
    float toilet_paper_10_price = 1.49;
    float toilet_paper_more_price = 0.99;
    
    float milk_total;
    float bread_total;
    float half_eggs_total;
    float full_eggs_total;
    float toilet_total;
    float discount_total = 0;
    float total;
    
    int milk_amount = 0;
    int bread_amount = 0;
    int half_eggs_amount = 0;
    int full_eggs_amount = 0;
    int toilet_amount = 0;
    int toilet_amount_lifetime = 0;
    int total_amount = 0;

    
    int products_amount = 5;
    
    int selected_option;
    do{
        do{
            // used to track if user selected a product or other option
            bool is_product;
        
            cout << "Menu"<<endl;
            cout << "Enter the desegnated number to choose"<<endl<<endl;
            cout << "1. Milk --- $6.25/gallon" <<endl;
            cout << "2. Bread --- $2.25/loaf" <<endl;
            cout << "3. Half dozen Eggs --- $2.00" <<endl;
            cout << "4. Full dozen Eggs --- $3.50" <<endl;
            cout << "5. Toilet Papper --- for 1-5 $1.99/piece, for 6-10 $1.49/piece and for 11 or more $0.99/piece" <<endl;
            cout << "." <<endl;
            cout << "9. to checkout" <<endl;
            cout << "0. to quit" <<endl<<endl;
            
            // accept selection
            do{
                cout << "Select an option from the menu: ";
                cin >> selected_option;
                is_product = (selected_option < 0 || selected_option > products_amount) && selected_option != 9;
                if(is_product){
                    cout <<"Invalid Selection Input. Please try again!"<<endl;
                }
            }while(is_product);
            if(selected_option > 0 && selected_option <= products_amount){
                //accept a valid amount for selected item
                int entered_amount;
                do{
                    cout << "Please enter the amount: ";
                    cin >> entered_amount;
                    if(entered_amount <= 0){
                        cout << "Invalid amount. Please try again!"<<endl;
                    }
                }while(entered_amount <= 0);
                
                //evaluate amount to the right item
                switch (selected_option) {
                    case 1:
                        milk_amount = entered_amount;
                        break;
                    case 2:
                        bread_amount = entered_amount;
                        break;
                    case 3:
                        half_eggs_amount = entered_amount;
                        break;
                    case 4:
                        full_eggs_amount = entered_amount;
                        break;
                    case 5:
                        toilet_amount = entered_amount;
                        break;
                    default:
                        break;
                }
                
                //we have all the info we need to calculate total
                milk_total =milk_price * milk_amount;
                bread_total =bread_price * bread_amount;
                half_eggs_total = half_eggs_price * half_eggs_amount;
                full_eggs_total = full_eggs_price * full_eggs_amount;
                toilet_total = 0;
                
                if(toilet_amount <= 5){
                    toilet_total = toilet_amount * toilet_paper_5_price;
                }else if (toilet_amount <= 10){
                    toilet_total = toilet_amount * toilet_paper_10_price;
                }else{
                    toilet_total = toilet_amount * toilet_paper_more_price;
                }
                total = milk_total + bread_total + half_eggs_total + full_eggs_total + toilet_total;
                total_amount = milk_amount + bread_amount + half_eggs_amount + full_eggs_amount + toilet_amount;
                //display the subtotal
                cout <<endl;
                cout <<"==================="<<endl;
                cout<<"Subtotal"<<endl;
                cout<<"-------------------"<<endl;
                cout<<"Milk x"<<milk_amount<<" ................ $"<<milk_total<<endl;
                cout<<"Bread x"<<bread_amount<<" ............... $"<<bread_total<<endl;
                cout<<"Half a dozen eggs x"<<half_eggs_amount<<" ... $"<<half_eggs_total<<endl;
                cout<<"Full dozen eggs x"<<full_eggs_amount<<" ..... $"<<full_eggs_total<<endl;
                cout<<"Toilet paper x"<<toilet_amount<<" ........ $"<<toilet_total<<endl;
                cout<<"Total x"<<total_amount<<" ............... $"<<total<<endl;
                cout <<"==================="<<endl<<endl;
            }
        }while(selected_option != 9 && selected_option != 0);
       
        if(selected_option == 9){
            // user has chosen to checkout we calculate all the extra discounts
            char coupon;
            do{
                cout<<"Enter a coupon code if you have one or enter 'N' to skip: ";
                cin >> coupon;
                if(coupon != 'R' && coupon != 'N'){
                    cout <<"Invalid code. Please enter a valid coupon or 'N' to skip"<<endl;
                }
            }while(coupon != 'R' && coupon != 'N');
            //calclulate all the remaining discounts and total
            
            milk_total = milk_price * milk_amount;
            bread_total = bread_price * bread_amount;
            half_eggs_total = half_eggs_price * half_eggs_amount;
            full_eggs_total = full_eggs_price * full_eggs_amount;
            toilet_total = 0;
            // apply the "if two gallons of milk eggs are half price" rule
            if(milk_amount >= 2){
                half_eggs_total /= 2;
                full_eggs_total /= 2;
                discount_total += (half_eggs_price * half_eggs_amount) - half_eggs_total;
                discount_total += (full_eggs_price * full_eggs_amount) - full_eggs_total;
                cout << "Discount applied to eggs! since you bought "<< milk_amount <<" gallons of milk"<<endl;
                
            }
            // apply the coupon discount
            if(coupon == 'R'){
                //use the discounted bread price which is 1.50
                bread_total = discounted_bread_price * bread_amount;
                discount_total += (bread_price * bread_amount) - bread_total;
                cout << "Discount coupon applied! bread is now $1.50 per loaf"<<endl;
            }
            if(toilet_amount + toilet_amount_lifetime <= 5){
                toilet_total = toilet_amount * toilet_paper_5_price;
            }else if (toilet_amount + toilet_amount_lifetime <= 10){
                toilet_total = toilet_amount * toilet_paper_10_price;
            }else{
                toilet_total = toilet_amount * toilet_paper_more_price;
            }
            discount_total += (toilet_amount * toilet_paper_5_price) - toilet_total;
            //calculate total
            total = milk_total + bread_total + half_eggs_total + full_eggs_total + toilet_total;
            total_amount = milk_amount + bread_amount + half_eggs_amount + full_eggs_amount + toilet_amount;
            //display the subtotal
            cout <<endl;
            cout <<"==================="<<endl;
            cout<<"Total after discount"<<endl;
            cout<<"-------------------"<<endl;
            cout<<"Milk x"<<milk_amount<<" ................ $"<<milk_total<<endl;
            cout<<"Bread x"<<bread_amount<<" ............... $"<<bread_total<<endl;
            cout<<"Half a dozen eggs x"<<half_eggs_amount<<" ... $"<<half_eggs_total<<endl;
            cout<<"Full dozen eggs x"<<full_eggs_amount<<" ..... $"<<full_eggs_total<<endl;
            cout<<"Toilet paper x"<<toilet_amount<<" ........ $"<<toilet_total<<endl;
            cout<<"Total discount ........ -$"<<discount_total<<endl;
            cout<<"Total due x"<<total_amount<<" ............... $"<<total<<endl;
            cout <<"==================="<<endl;
            char purchase;
            do{
                cout << "Are you sure you want to checkout?(Y/N)";
                cin >> purchase;
                if(purchase != 'Y' && purchase != 'N'){
                    cout << "Invalid! Please enter only 'Y' or 'N' to choose."<<endl;
                }
            }while(purchase != 'Y' && purchase != 'N');
            if(purchase == 'Y'){
                cout << "Thank you for your purchase!"<<endl;
                toilet_amount_lifetime = toilet_amount;
            }else{
                cout << "Your checkout was succesfully canceled!"<<endl;
            }
            //reset after purchase
            milk_total = 0;
            bread_total = 0;
            half_eggs_total = 0;
            full_eggs_total = 0;
            toilet_total = 0;
            discount_total = 0;
            
            milk_amount = 0;
            bread_amount = 0;
            half_eggs_amount = 0;
            full_eggs_amount = 0;
            toilet_amount = 0;
            char shop_again;
            do{
                cout << "You want to shop again(Y/N)? ";
                cin >> shop_again;
                if(shop_again != 'Y' && shop_again != 'N'){
                    cout << "Invalid! Please enter only 'Y' or 'N' to choose."<<endl;
                }
            }while(shop_again != 'Y' && shop_again != 'N');
            if(shop_again == 'N'){
                break;
            }
        }
    }while(selected_option != 0);
    cout << "Bye, Comeback soon!"<<endl;
    
    return 0;
}
