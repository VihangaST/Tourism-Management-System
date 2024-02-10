#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<string>

using namespace std;
int operationMode;
void menu();//main menu function 

//ManageMenu class
class TourismManagement
{
protected:
    string userName; //Hiding Admin name

public:
    TourismManagement()//Constructor
    {
        cout << "\n\t\t\tOperation modes\n\t\t\t1.Education Mode\n\t\t\t2.Regular Mode" << endl;
        cout << "\t\tEnter the selected mode number: ";
        cin >> operationMode;
        cout << endl;
        if (operationMode == 1)
        {
            cout << "\n\tTourismManagement-Constructor\n" << endl;
        }

        system("color 0B"); //changing terminal color
        //Front page
        cout << "**********************************************************************\n";
        cout << "**************WELCOME TO SMART TOURISM MANAGEMENT SYSTEM**************\n";
        cout << "**********************************************************************\n";
        cout << "\n\n\n\t\t Enter Your Name to Continue : ";
        cin >> userName;
        cout << "\n\n**********************************************************************\n";
        cout << "----------------------------------------------------------------------\n";
        cout << "**********************************************************************\n";

        Sleep(1500);
        system("CLS");
        menu(); //calling manu function to load second preview
    }

    ~TourismManagement() {
        if (operationMode == 1)
        {
            cout << "\n\tTourismManagement-Destructor\n" << endl;
        }
    }//Destructor
};

//Customer class
class Customer
{
private:
    int age, mobileNo, noOfAdults, noOfChildren;
public:
    string customerName, homeAddress;
    char all[999];
    static int customerID;
public:
    Customer() {
        if (operationMode == 1)
        {
            cout << "\n\tCustomer-Constructor\n" << endl;
        }
    }//constructor
    ~Customer() {
        if (operationMode == 1)
        {
            cout << "\n\tCustomer-Destructor\n" << endl;
        }
    } //destructor
    void getDetails()
    {
        if (operationMode == 1)
        {
            cout << "\n\tCustomer-getDetails()\n" << endl;
        }
        ofstream out("old-customer-details.txt", ios::app); //write customer details to file
        {
            cout << "\n\t* Enter Customer ID(XXXX) : ";
            cin >> customerID;
            cout << "\t* Enter Name    \t: ";
            cin >> customerName;
            cout << "\t* Enter Age    \t\t: ";
            cin >> age;
            cout << "\t* Enter Mobile Number   : ";
            cin >> mobileNo;
            cout << "\t* Home city    \t\t: ";
            cin >> homeAddress;
            cout << "\t* No of adults    \t: ";
            cin >> noOfAdults;
            cout << "\t* No of children    \t: ";
            cin >> noOfChildren;

        }
        out << "\nCustomer ID\t: " << customerID << "\ncustomerName\t: " << customerName << "\nAge\t\t: " << age << "\nMobile Number\t: " << mobileNo << "\nAddress\t\t: " << homeAddress << "\nNo of adults\t: " << noOfAdults << "\nNo of children\t: " << noOfChildren << "\n---------------------" << endl;
        out.close(); //closing the old-customers.txt file
        cout << "\n-----Your information is recorded-----\n" << endl;
    }
    void displayDetails() //function to show old customer records
    {
        if (operationMode == 1)
        {
            cout << "\n\tCustomer-displayDetails()\n" << endl;
        }
        ifstream inputFile("old-customer-details.txt"); //input data to the old-customer-details.txt file
        {
            if (!inputFile)
            {
                cout << "File Error!" << endl;
            }
            while (!(inputFile.eof()))
            {
                inputFile.getline(all, 999);
                cout << all << endl;
            }
            inputFile.close();
        }
    }
};

//Static variable
int Customer::customerID;

//Cab class
class Cabs
{
private:
    int choice;
public:
    char cabType;
    int distance, cabSelection;
    float cabCost;
    static float lastCabCost;
public:
    Cabs() {
        if (operationMode == 1)
        {
            cout << "\n\tCabs-Constructor\n" << endl;
        }
    }
    ~Cabs() {
        if (operationMode == 1)
        {
            cout << "\n\tCabs-Destructor\n" << endl;
        }
    }
    void cabDetails(int extra)
    {
        if (operationMode == 1)
        {
            cout << "\n\tCabs-cabDetails(int)\n" << endl;
        }
        cout << "\tAvailable type of cabs\n" << endl;
        cout << "\t1. Rent a STANDARD Cab" << endl;
        cout << "\t2. Rent a LUXURY Cab" << endl;
        cout << "\n--------------------------------------------------" << endl;
        cout << "\nEnter Kilometers you have to travel: ";
        cin >> distance;
        cout << "\n--------------------------------------------------" << endl;

        cout << "\tCost for tours under two Options.\n" << endl;
        cout << "\t1-Cost for a STANDARD Cab : Rs." << distance * (150 + extra) << endl;
        cout << "\t2-Cost for a LUXURY Cab : Rs." << distance * (250 + extra) << endl;

        cout << "\nEnter your preferred type:";
        cin >> cabSelection;
        cout << endl;



        if (cabSelection == 1) {
            cabCost = distance * (150 + extra);
            lastCabCost = cabCost;
            cout << "--------------------------------------------------" << endl;
            cout << "\n    YOU HAVE SUCCESSFULLY HIRED A STANDARD CAB !" << endl;
            cout << "Your tour will cost Rs." << cabCost << " for a STANDARD cab\n" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "Goto Menu to take the payment receipt" << endl;

        }
        else if (cabSelection == 2) {
            cabCost = distance * (250 + extra);
            lastCabCost = cabCost;
            cout << "--------------------------------------------------" << endl;
            cout << "\n    YOU HAVE SUCCESSFULLY HIRED A LUXURY CAB !\n" << endl;
            cout << "\nYour tour will cost Rs." << cabCost << " for a LUXURY cab\n" << endl;
            cout << "------------------------------------------------" << endl;
            cout << "Goto Menu to take the payment receipt" << endl;

        }
        else {
            cout << "Error! \nPlease Wait! Redirecting to Previous Menu... " << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\n-----> Enter 0 to Redirect Main Menu: ";
        cin >> choice;
        system("CLS");
        if (choice == 0) {
            menu();
        }
        else {
            menu();
        }
    }
};

//AdventureCabs class
class AdventureCabs : public Cabs
{
public:
    AdventureCabs() {
        if (operationMode == 1)
        {
            cout << "\n\tAdventureCabs-Constructor\n" << endl;
        }
    }
    ~AdventureCabs() {
        if (operationMode == 1)
        {
            cout << "\n\tAdventureCabs-Destructor\n" << endl;
        }
    }
    void adventureCabDetails() {
        if (operationMode == 1)
        {
            cout << "\n\tAdventureCabs-adventureCabDetails()\n" << endl;
        }
        cout << "--------------------------------------------------" << endl;
        cout << "\n\tYOU SELECTED ADVENTURE CABS \n" << endl;
    }
    void cabDetails_parent() {
        
        Cabs::cabDetails(5);
    }
};

//tourCabClass
class TourCabs : public Cabs
{
public:
    TourCabs() {
        if (operationMode == 1)
        {
            cout << "\n\tTourCabs-Constructor\n" << endl;
        }
    }
    ~TourCabs() {
        if (operationMode == 1)
        {
            cout << "\n\tTourCabs-Destructor\n" << endl;
        }
    }
    void tourCabDetails() {
        if (operationMode == 1)
        {
            cout << "\n\tTourCabs-tourCabDetails()\n" << endl;
        }
        cout << "--------------------------------------------------" << endl;
        cout << "\t\tYOU SELECTED TOUR CABS\n." << endl;
    }
    void cabDetails_parent() {
        if (operationMode == 1)
        {
            cout << "\n\tTourCabs-cabDetails_parent()\n" << endl;
        }Cabs::cabDetails(0);
    }
};

//static variable
float Cabs::lastCabCost;

//Booking class
class Booking
{
public:
    int packageSelection;
    int gotoMenu;
    static float bookingCost;
    int selection;
public:
    Booking() {
        if (operationMode == 1)
        {
            cout << "\n\tBooking-Constructor\n" << endl;
        }
    }
    ~Booking() {
        if (operationMode == 1)
        {
            cout << "\n\tBooking-Destructor\n" << endl;
        }
    }
    void bookingDetails(float factor)
    {
        if (operationMode == 1)
        {
            cout << "\n\tBooking-bookingDetails(float)\n" << endl;
        }
        cout << "Make your vacation enjoyable...." << endl;
        cout << "#Food and beverage #Swimming Pool" << endl;
        cout << "#Outside catering service #Car parking" << endl;
        cout << "#Ground #Indoor badminton court" << endl;
        cout << "____________________________________" << endl;
        cout << "\n\tOffered Packages:\n" << endl;
        cout << "1. Bred and Breakfast" << endl;
        cout << "   Basic facilities just for Rs." << 5000 * factor << endl;
        cout << "2. Half board" << endl;
        cout << "   Enjoy Premium just for Rs." << 10000 * factor << endl;
        cout << "3. Full board" << endl;
        cout << "   Live a Luxury just for Rs." << 15000 * factor << endl;
        cout << "____________________________________" << endl;
        cout << "\nEnter your prefer package number :";
        cin >> packageSelection;
        cout << "____________________________________" << endl;


        if (packageSelection == 1) {
            bookingCost = 5000 * factor;
            cout << "\nYou have successfully booked STANDARD PACKAGE" << endl;
            cout << "Goto Menu and take the receipt" << endl;
        }
        else if (packageSelection == 2) {
            bookingCost = 10000 * factor;
            cout << "\nYou have successfully booked PREMIUM PACKAGE" << endl;
            cout << "Goto Menu and take the receipt" << endl;
        }
        else if (packageSelection == 3) {
            bookingCost = 15000 * factor;
            cout << "\nYou have successfully booked LUXURY PACKAGE" << endl;
            cout << "Goto Menu to take the receipt" << endl;
        }
        else {
            cout << "Error! Please Wait!--> Redirecting to Previous Menu \n" << endl;
            system("CLS");
            bookingDetails(factor);

        }

        cout << "\n----->Enter 0 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 0) {
            menu();
        }
        else {
            menu();
        }
    }
};

//Villa class
class Villa :public Booking
{
public:
    int villaSelection;

public:
    Villa() {
        if (operationMode == 1)
        {
            cout << "\n\tVilla-Constructor\n" << endl;
        }
    }
    ~Villa() {
        if (operationMode == 1)
        {
            cout << "\n\tVilla-Destructor\n" << endl;
        }
    }
    void villaDetails()
    {
        if (operationMode == 1)
        {
            cout << "\n\tVilla-villaDetails()\n" << endl;
        }
        cout << "\tAVAILABLE VILLAS\n" << endl;
        string villaNo[] = { "SUNSET VILLA", "CLOUDY EYES VILLA", "WOODLANDS VILLA" };
        for (int i = 0; i < 3; i++)
        {
            cout << "\t" << (i + 1) << "- Villa " << villaNo[i] << endl;
        }
        cout << "\nSelect the preferred villa : ";
        cin >> villaSelection;
        cout << "____________________________________" << endl;
        cout << "____________________________________" << endl;

    }
    void bookingDetails_parent()
    {
        if (operationMode == 1)
        {
            cout << "\n\tVilla-bookingDetails_parent()\n" << endl;
        }
        if (villaSelection == 1)
        {
            cout << "***-WELCOME TO SUNSET VILLA-***\n" << endl;
            Booking::bookingDetails(1);
        }
        else if (villaSelection == 2)
        {
            cout << "***-WELCOME TO CLOUDY EYES VILLA-***\n" << endl;
            Booking::bookingDetails(2);
        }
        else
        {
            cout << "***-WELCOME TO WOODLANDS VILLA-***\n" << endl;
            Booking::bookingDetails(3);
        }

    }
};

//Hotel class
class Hotel :public Booking
{
public:
    int hotelSelection;

public:
    Hotel() {
        if (operationMode == 1)
        {
            cout << "\n\tHotel-Constructor\n" << endl;
        }
    }
    ~Hotel() {
        if (operationMode == 1)
        {
            cout << "\n\tHotel-Destructor\n" << endl;
        }
    }
    void hotelDetails()
    {
        if (operationMode == 1)
        {
            cout << "\n\tHotel-hotelDetails()\n" << endl;
        }
        cout << "AVAILABLE HOTELS\n" << endl;

        string hotelNo[] = { "SEASONS", "SUMMER", "FLORA" };
        for (int j = 0; j < 3; j++)
        {
            cout << "\t" << (j + 1) << "- Hotel " << hotelNo[j] << endl;
        }
        cout << "\nSelect the preferred hotel : ";
        cin >> hotelSelection;
        cout << "\n____________________________________" << endl;
        cout << "____________________________________" << endl;
    }
    void bookingDetails_parent()
    {
        if (operationMode == 1)
        {
            cout << "\n\tHotel-bookingDetails_parent()\n" << endl;
        }
        if (hotelSelection == 1)
        {
            cout << "******-WELCOME TO HOTEL SEASONS-******\n" << endl;
            Booking::bookingDetails(1.5);
        }
        else if (hotelSelection == 2)
        {
            cout << "******-WELCOME TO HOTEL SUMMER-******\n" << endl;
            Booking::bookingDetails(2.5);
        }
        else
        {
            cout << "******-WELCOME TO HOTEL FLORA-******\n" << endl;
            Booking::bookingDetails(3.5);
        }
    }
};

//static variable
float Booking::bookingCost;

class PaymentMethod :public Booking, Cabs
{
public:
    char paymentType;
    static char method;

public:
    PaymentMethod() {
        if (operationMode == 1)
        {
            cout << "\n\tPaymentMethods-Constructor\n" << endl;
        }
    }
    ~PaymentMethod() {
        if (operationMode == 1)
        {
            cout << "\n\tPaymentMethods-Destructor\n" << endl;
        }
    }
    void charges()
    {
        if (operationMode == 1)
        {
            cout << "\n\tPaymentMethods-charges()\n" << endl;
        }
        cout << "Description\t\t Total" << endl;
        cout << "Hotel/Villa cost:\t " << fixed << setprecision(2) << Booking::bookingCost << endl;
        cout << "Travelling cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
        cout << "_________________________________" << endl;
        cout << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::bookingCost + Cabs::lastCabCost << endl;

        cout << "Payment Type\nDo you prefer\n\t1-Cash\n\t2-Card : ";
        cin >> paymentType;
        method = paymentType;
    }

};

//static variable
char PaymentMethod::method;

//Payment class
class Payments : public Booking, Cabs, Customer, PaymentMethod//Multiple Inheritance 
{

public:
    Payments() {
        if (operationMode == 1)
        {
            cout << "\n\tPayments-Constructor\n" << endl;
        }
    }
    ~Payments() {
        if (operationMode == 1)
        {
            cout << "\n\tPayments-Destructor\n" << endl;
        }
    }
    void printBill()
    {
        if (operationMode == 1)
        {
            cout << "\n\tPayments-printBill()\n" << endl;
        }
        //Define file object with appropiate stream
        ofstream outputFile("receipt.txt"); //receipt details outputing to the file 
        {
            outputFile << "-----SMART Tourism Management----" << endl;
            outputFile << "--------------Receipt------------" << endl;
            outputFile << "_________________________________" << endl;
            outputFile << "Customer ID: " << Customer::customerID << endl << endl;
            outputFile << "Description\t\t Total" << endl;
            outputFile << "Hotel/Villa cost:\t " << fixed << setprecision(2) << Booking::bookingCost << endl;
            outputFile << "Travelling cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
            outputFile << "Payment method : " << PaymentMethod::method << endl;
            outputFile << "_________________________________" << endl;
            outputFile << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::bookingCost + Cabs::lastCabCost << endl;
            outputFile << "_________________________________" << endl;
            outputFile << "------------THANK YOU------------" << endl;
            outputFile << "----------VISIT US AGAIN---------" << endl;

        }
        outputFile.close();
    }

    void displayBill()
    {
        if (operationMode == 1)
        {
            cout << "\n\tPayments-displayBill()\n" << endl;
        }
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

//shopDetails class
class ShopDetails
{
private:
    int choice;
public:
    ShopDetails() {
        if (operationMode == 1)
        {
            cout << "\n\tShopDetails-Constructor\n" << endl;
        }
    }
    ~ShopDetails() {
        if (operationMode == 1)
        {
            cout << "\n\tShopDetails-Destructor\n" << endl;
        }
    }
    void printingShopDetails() {
        if (operationMode == 1)
        {
            cout << "\n\tShopDetails-printingShopDetails()\n" << endl;
        }
        cout << "__________________________________________________" << endl;
        cout << "\t\tNearest Shopping centres" << endl;
        cout << "__________________________________________________" << endl;
        cout << "\nAraliya Creations\n Flower Road,Kegalle.\nTel: 1223654412" << endl;
        cout << "\nElina shopping centre\n No:1/E, Perera Street,Kegalle.\nTel: 0711153265" << endl;
        cout << "\nElephant lovers\n Lora Garden,Kegalle.\nTel: 1224445526" << endl;
        cout << "\n-----> Enter 0 to Redirect Main Menu: ";
        cin >> choice;
        system("CLS");
        if (choice == 0) {
            menu();
        }
        else {
            menu();
        }
    }
};

//menu function
void menu() //menu function contain main menu
{
    int mainChoice, inChoice, gotoMenu;
    cout << "\t *** SMART Tourism Management System *** \n" << endl;
    cout << "***************************************************************" << endl;
    cout << "-------------------------Main Menu-----------------------------" << endl;
    cout << "***************************************************************" << endl;
    cout << "\t* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ *" << endl;
    cout << "\t*|\t                                       |*" << endl;
    cout << "\t*|\tUser Account                      -> 1 |*" << endl;
    cout << "\t*|\tBookings Management               -> 2 |*" << endl;
    cout << "\t*|\tCabs Management                   -> 3 |*" << endl;
    cout << "\t*|\tCharges & Bill                    -> 4 |*" << endl;
    cout << "\t*|\tNearest Shopping centre Details   -> 5 |*" << endl;
    cout << "\t*|\tExit                              -> 6 |*" << endl;
    cout << "\t*|\t                                       |*" << endl;
    cout << "\t*|\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |*" << endl;
    cout << "\t*************************************************" << endl;
    cout << "\t*************************************************" << endl;
    cout << "\t*************************************************" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    //creating objects
    //Cabs a3;
    //Booking a4;

    if (mainChoice == 1)
    {
        cout << "__________________________________\n" << endl;
        cout << "-----------User Account-----------\n" << endl;
        cout << "\t1. New Customer" << endl;
        cout << "\t2. Old Customers details" << endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        Customer a2;//creating object
        if (inChoice == 1)
        {

            cout << "\t\tNew Customer" << endl;
            a2.getDetails();
        }
        else if (inChoice == 2) {
            string passcode;
            cout << "Enter the Passcode: ";
            cin >> passcode;
            if (passcode == "aaa")
            {
                a2.displayDetails();
            }
            else
            {
                cout << "Protected.You cannot access." << endl;
                Sleep(1100);
                system("CLS");
                menu();
            }
        }
        else {
            cout << "Error! Please Wait!--> Redirecting to Previous Menu \n" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "----->Enter 0 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 0) {
            menu();
        }
        else {
            menu();
        }
    }
    else if (mainChoice == 3)
    {
        char cabType;
        cout << "__________________________________\n" << endl;
        cout << "--------------SMART CABS-----------\n" << endl;
        cout << "\tA. Rent a tour cab" << endl;
        cout << "\tB. Rent an adventure cab" << endl;
        cout << "__________________________________\n" << endl;
        cout << "Enter the type of cab you prefer: ";
        cin >> cabType;
        cout << "\n" << endl;
        system("CLS");
        if (cabType == 'A' || cabType == 'a')//Rent a tour Cab
        {
            TourCabs x2;
            x2.tourCabDetails();
            x2.cabDetails_parent();
        }
        else if (cabType == 'B' || cabType == 'b')//Rent an adventure Cab
        {
            AdventureCabs x1;
            x1.adventureCabDetails();
            x1.cabDetails_parent();
        }
    }
    else if (mainChoice == 2)
    {
        int selection;
        cout << "____________________________________" << endl;
        cout << "---------Booking Management---------" << endl;
        cout << "\n\t1- Villa" << endl;
        cout << "\t2- Hotel\n" << endl;
        cout << "Enter the type you prefer: ";
        cin >> selection;
        cout << "____________________________________\n" << endl;

        if (selection == 1)
        {
            Villa y1;
            y1.villaDetails();
            y1.bookingDetails_parent();
        }
        else if (selection == 2)
        {
            Hotel y2;
            y2.hotelDetails();
            y2.bookingDetails_parent();
        }
    }
    else if (mainChoice == 4)
    {
        cout << "-----------Chargers and Bill-----------\n" << endl;
        cout << "----------->Your total cost<-----------\n" << endl;
        Payments a6;
        a6.printBill();//Writing to file
        PaymentMethod a7;
        a7.charges();//Payment description

        cout << "\n\tYour receipt is ready\n" << endl;
        cout << "Enter 1 to display your receipt: \nor Enter another number to back main menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            system("CLS");
            a6.displayBill();
            cout << "----->Enter 0 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 0) {
                menu();
            }
            else {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 5)
    {
        ShopDetails a5;
        a5.printingShopDetails();
    }
    else if (mainChoice == 6)
    {
        cout << "\n\n\tTHANK YOU! HAVE A NICE DAY!" << endl;
        Sleep(1100);
        system("CLS");
        TourismManagement();
    }
    else
    {
        cout << "Error! \nPlease Wait! Redirecting to Previous Menu... " << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

//main function
int main()
{
    
    TourismManagement a1;//creating object
    return 0;
}
