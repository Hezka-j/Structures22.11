#include <iostream>
#include <ctime>
using namespace std;
struct Date {
    const int guaratee = 1;
    double price = 0.0;
    unsigned int sell_date_day;
    unsigned int sell_date_month;
    unsigned int sell_date_year;

    unsigned int date_day;
    unsigned int date_month;
    unsigned int date_year;
    unsigned int version;
};
struct Device {
    string type;
    
    string brand;
    string brand_phone[3] = { "Apple", "Xiaomi", "Samsung" };
    string brand_tablet[3] = { "Apple", "Samsung", "Lenovo" };
    string brand_computer[3] = { "Asus", "Acer", "Lenovo"};

    string model_phone[3] = { "Iphone", "Xiaomi", "Galaxy" };
    string model_tablet[3] = { "Ipad", "Galaxy Tab", "Lenovo" };
    string model_computer[3] = { "Asus", "Acer", "Lenovo" };

    string models_iphone[3] = { "Pro", "Pro Max", "  " };
    string models_xiaomi[3] = { "Redmi", "Poco", "  " };
    
    string model;
    Date number;
};

void GenerateDevice(Device& phone)
{
    cout << "Enter device -> ";
    cin >> phone.type;
    cin.ignore();
    
    int numb;
    int numb2;
    phone.number.version = 1 + rand() % 15;
    
    for (int i = 0; i < 3; i++)
    {
        
        numb = rand() % 3;
        if (phone.type == "Phone" || phone.type == "phone")
        {
           
            phone.brand = phone.brand_phone[numb];
            if(phone.brand == phone.brand_phone[0])
            {
                numb2 = rand() % 3;
                phone.model = phone.model_phone[numb] + phone.models_iphone[numb2];
            }
            else if (phone.brand == phone.brand_phone[1])
            {
                numb2 = rand() % 3;
                phone.model = phone.model_phone[numb] + phone.models_xiaomi[numb2];
            }
            else
                phone.model = phone.model_phone[numb];
            break;
            
        }
        else if (phone.type == "Tablet" || phone.type == "tablet")
        {

            phone.brand = phone.brand_tablet[numb];

            phone.model = phone.model_tablet[numb];
            break;
        }
        else if (phone.type == "Computer" || phone.type == "computer")
        {

            phone.brand = phone.brand_computer[numb];

            phone.model = phone.model_computer[numb];
            break;
        }
    }
    
    phone.number.sell_date_day = 1 + rand() % 29;
    phone.number.sell_date_month = 1 + rand() % 13;
    phone.number.sell_date_year = 2000 + rand() % (2024 - 2000);
    phone.number.price = (200000 + rand() % (500000 - 200000)) / 10.0;
    

}
void PrintDevice(const Device& phone)
{
    cout << "\nType device: " << phone.type << "\n";
    cout <<"Brand: " << phone.brand << "\n";
    cout <<"Model: " << phone.model  << " " << phone.number.version << "\n";
    printf("Sell date: %02d.%02d.%02d\n", phone.number.sell_date_day, phone.number.sell_date_month, phone.number.sell_date_year);
    cout << "Price of device: " << phone.number.price << "\n";
}
void CalculateGuaratee(Device& phone)
{
    cout << "Day now -> ";
    cin >> phone.number.date_day;
    cin.ignore();
    cout << "Month now -> ";
    cin >> phone.number.date_month;
    cin.ignore();
    cout << "Year now -> ";
    cin >> phone.number.date_year;
    cin.ignore();
    cout << "Guaratee " << phone.type << " to ";
    printf("%02d.%02d.%02d\n", phone.number.sell_date_day, phone.number.sell_date_month, phone.number.sell_date_year + 1);
    if (phone.number.sell_date_year > phone.number.date_year)
    {
        cout << "You don't have this devise(\n";
    }
    if (phone.number.sell_date_year + 1 < phone.number.date_year  && phone.number.date_month > phone.number.sell_date_month || phone.number.date_day > phone.number.sell_date_day)
    {
        cout << "Your warranty has expired\n";

    }
    else if (phone.number.sell_date_year + 1 >= phone.number.date_year && phone.number.sell_date_month <= phone.number.date_month || phone.number.sell_date_month >= phone.number.date_month && phone.number.sell_date_day >= phone.number.date_day || phone.number.sell_date_day <= phone.number.date_day)
    {
        cout << "Your guarantee is valid\n";
        
    }  
   
    
    else
    {

        cout << "Your warranty has expired\n";
    }
}
int main()
{
    srand(time(0));
    Device phone;
    GenerateDevice(phone);
    PrintDevice(phone);
    CalculateGuaratee(phone);
    
}
