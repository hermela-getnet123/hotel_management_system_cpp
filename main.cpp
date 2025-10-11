

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <fstream>
#define MAX_ROOMS 100
using namespace std;

struct MenuItem {
    int id;
    char name[50];
    float price;
};
MenuItem foodMenu[] = {
        {1, "Pasta", 120.50},
        {2, "Pizza", 500.00},
        {3, "Burger", 500.00},
        {4, "Salad", 120.00},
        {5, "Soup", 100.00},
        {6, "shiro", 150.00},
        {7, "tebse", 400.00},
        {8, "kitfo", 350.00},
        {9, "beyeayinet", 200.00},
        {10, "agelegel", 300.00},
        {11, "home special", 500.00}
    };
    int foodCount = sizeof(foodMenu) / sizeof(foodMenu[0]);

    MenuItem drinkMenu[] = {
        {1, "Coke", 100.00},
        {2, "Pepsi", 100.00},
        {3, "Orange Juice", 80.00},
        {4, "Water", 50.00},
        {5, "Coffee", 50.00}
    };
    int drinkCount = sizeof(drinkMenu) / sizeof(drinkMenu[0]);
double totalcost=0.0;
struct Guest {
    string name;
    int roomNumber;
    bool isCheckedIn;
   string roomType;
    vector<string> amenities;
};

struct FoodItem {
    string name;
    double price;
};

struct Service {
    string type;
    double cost;
};

vector<Service> services;
vector<Guest> guests;

struct Room {
    int roomNumber;
    string roomType;
    double pricePerNight;
    bool isBooked;
    string customerName;
    int nights;
};

bool isRoomOccupied(int roomNumber) {
    for (const auto& guest : guests) {
        if (guest.roomNumber == roomNumber && guest.isCheckedIn) {
            return true;
        }
    }
    return false;
}
Room rooms[MAX_ROOMS];
int totalRooms = 0;

void initializeRooms (int numRooms) {
    totalRooms = numRooms;
    for (int i = 0; i < totalRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isBooked = false;
        rooms[i].customerName = "";
        rooms[i].nights = 0;

        if (i % 3 == 0) {
            rooms[i].roomType = "Single";
            rooms[i].pricePerNight = 50.0;
        } else if (i % 3 == 1) {
            rooms[i].roomType = "Double";
            rooms[i].pricePerNight = 100.0;
        } else {
            rooms[i].roomType = "Suite";
            rooms[i].pricePerNight = 300.0;
        }
    }
}
void displayAvailableRooms() {
    cout << "Available Rooms:\n";
    bool found = false;
    for (int i = 0; i < totalRooms; i++) {
        if (!rooms[i].isBooked) {
            cout << "Room " << rooms[i].roomNumber
                 << " (" << rooms[i].roomType
                 << ", Price per night: $" <<fixed
                 << rooms[i].pricePerNight << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No rooms available.\n";
    }
}


void bookRoom() {
    int roomNumber;
    string customerName;
    int nights;

    cout << "Enter room number to book: ";
    cin >> roomNumber;

    if (roomNumber < 1 || roomNumber > totalRooms) {
        cout << "Invalid room number!\n";
        return;
    }

    if (rooms[roomNumber - 1].isBooked) {
        cout << "Room is already booked!\n";
        return;
    }

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Enter number of nights: ";
    cin >> nights;

    rooms[roomNumber - 1].isBooked = true;
    rooms[roomNumber - 1].customerName = customerName;
    rooms[roomNumber - 1].nights = nights;

    double totalPrice = rooms[roomNumber - 1].pricePerNight * nights;
    cout << "Room " << roomNumber << " successfully booked for " << customerName
         << " for " << nights << " nights. Total price: $"
         << fixed << totalPrice << "\n";
}

void cancelBooking() {
    int roomNumber;
    cout << "Enter room number to cancel booking: ";
    cin >> roomNumber;

    if (roomNumber < 1 || roomNumber > totalRooms) {
        cout << "Invalid room number!\n";
        return;
    }

    if (rooms[roomNumber - 1].isBooked) {
        cout << "Room is not booked!\n";
        return;
    }

    rooms[roomNumber - 1].isBooked = false;
    rooms[roomNumber - 1].customerName = "";
    rooms[roomNumber - 1].nights = 0;

    cout << "Booking for room " << roomNumber << " has been canceled.\n";
}

void displayBookings() {
    cout << "Current Bookings:\n";
    bool found = false;
    for (int i = 0; i < totalRooms; i++) {
        if (!rooms[i].isBooked) {
            double totalPrice = rooms[i].pricePerNight * rooms[i].nights;
            cout << "Room " << rooms[i].roomNumber << " (" << rooms[i].roomType
                 << ") is booked by " << rooms[i].customerName
                 << " for " << rooms[i].nights << " nights (Price per night: $"
                 << fixed << setprecision(2) << rooms[i].pricePerNight
                 << ", Total: $" << totalPrice << ").\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No rooms are currently booked.\n";
    }
}

void checkIn() {
    int numRooms=100;


    if (numRooms < 1 || numRooms > MAX_ROOMS) {
        cout << "Invalid number of rooms!\n";
        exit;
    }

    initializeRooms(numRooms);
    int choice;
    do {
        cout << "\n--- Hotel Room Booking System ---\n";
        cout << "1. Display Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Display All Bookings\n";
        cout << "5. exit from chose";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailableRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                displayBookings();
                break;
            case 5:
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

}


void Comment() {
    string comment;
    cout << "Enter your comment on our service ";
    cin.ignore();
    getline(cin, comment);
   cout<< " Thank you for your comment ";
}


void displayMenu(const char* title, MenuItem menu[], int foodcount) {
int itemCount;
    cout << "\n--- " << title << " ---" << endl;
    cout << "ID\tItem Name\t\tPrice" << endl;
    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < itemCount; ++i) {
        cout << menu[i].id << "\t" << menu[i].name << "\t\t" << menu[i].price << endl;
    }
}

void placeOrder(MenuItem foodMenu[], int foodCount, MenuItem drinkMenu[], int drinkCount) {
    int orderId, quantity, choice;
    float totalCost = 0;
    char orderChoice;

    do {
        cout << "\nWhich menu would you like to order from?" << endl;
        cout << "1. Food Menu" << endl;
        cout << "2. Drinks Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        MenuItem* menu = nullptr;
        int itemCount = 0;

        if (choice == 1) {
            menu = foodMenu;
            itemCount = foodCount;
        } else if (choice == 2) {
            menu = drinkMenu;
            itemCount = drinkCount;
        } else {
            cout << "Invalid choice! Returning to main menu..." << endl;
            return;
        }

        cout << "\nEnter the item ID to order: ";
        cin >> orderId;

        MenuItem* selectedItem = nullptr;
        for (int i = 0; i < itemCount; ++i) {
            if (menu[i].id == orderId) {
                selectedItem = &menu[i];
                break;
            }
        }

        if (selectedItem) {
            cout << "Enter quantity: ";
            cin >> quantity;
            totalCost += selectedItem->price * quantity;
            cout << "You added " << quantity << " x " << selectedItem->name
                 << " to your order. Subtotal: $" << totalCost << endl;
        } else {
            cout << "Invalid item ID! Please try again." << endl;
        }

        cout << "Do you want to order another item? (y/n): ";
        cin >> orderChoice;
    } while (orderChoice == 'y' || orderChoice == 'Y');

    cout << "\nYour total order cost is: $" << totalCost << endl;
    cout << "Thank you for your order!" << endl;
}


void displayFoodMenu() {

int choice;
    do {
        cout << "\n--- Ras Amba Hotel Food and Drinks Service ---" << endl;
        cout << "1. View Food Menu" << endl;
        cout << "2. View Drinks Menu" << endl;
        cout << "3. Order Items" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMenu("Food Menu", foodMenu, foodCount );
                break;
            case 2:
                displayMenu("Drinks Menu", drinkMenu, drinkCount);
                break;
            case 3:
                placeOrder(foodMenu, foodCount, drinkMenu, drinkCount);
                break;

            case 4:
                cout << "Thank you for visiting Ras Amba Hotel. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);


}


double calculateDeliveryFee(int hour) {
    if (hour >= 6 && hour <= 9) {
        return 5.0;
    } else if (hour >= 18 && hour <= 21) {
        return 10.0;
    } else {
        return 2.0;
    }
}


void showRoomService(vector<string>& selectedServices, double& totalCost) {
    int roomNumber, hour, minute;
    double deliveryFee = 0.0, foodCost = 0.0;
    vector<string> menu = {"1. Burger ($10)", "2. Pizza ($15)", "3. Salad ($8)", "4. Pasta ($12)", "5. Sandwich ($6)"};
    vector<int> prices = {10, 15, 8, 12, 6};
    int foodChoice;

    cout << "\n--- Room Service ---\n";
    cout << "Enter room number: ";
    cin >> roomNumber;
    cin.ignore();
    cout << "Enter time for service (hour minute): ";
    cin >> hour >> minute;

    cout << "\n--- Room Service Food Menu ---\n";
    for (const auto& item : menu) {
        cout << item << endl;
    }

    cout << "Please select a food item by number (enter 0 for no food): ";
    cin >> foodChoice;

    if (foodChoice >= 1 && foodChoice <= menu.size()) {
        foodCost = prices[foodChoice - 1];
        deliveryFee = calculateDeliveryFee(hour);
        totalCost += (foodCost + deliveryFee);
        selectedServices.push_back("Room Service: " + menu[foodChoice - 1] + " with delivery fee $" + to_string(deliveryFee));
        cout << "You selected: " << menu[foodChoice - 1] << " (Delivery Fee: $" << deliveryFee << ")" << endl;
    } else {
        cout << "No food ordered.\n";
    }
}
void showConciergeService(vector<string>& selectedServices, double& totalCost) {
    string request;
    double serviceCost = 20.0;
    cout << "\n--- Concierge Service ---\n";
    cout << "Please enter your request (e.g., reservation, tour booking): ";
    cin.ignore();
    getline(cin, request);
    totalCost += serviceCost;
    selectedServices.push_back("Concierge Service: " + request + " ($" + to_string(serviceCost) + ")");
    cout << "Your request has been booked. Fee: $" << serviceCost << endl;
}
void showSpaService(vector<string>& selectedServices, double& totalCost) {
    string treatment, time;
    double spaCost = 50.0;
    cout << "\n--- Spa and Wellness ---\n";
    cout << "Please enter the treatment you want (e.g., massage, facial): ";
    cin.ignore();
    getline(cin, treatment);
    cout << "Preferred time for the treatment: ";
    getline(cin, time);
    totalCost += spaCost;
    selectedServices.push_back("Spa and Wellness: " + treatment + " at " + time + " ($" + to_string(spaCost) + ")");
    cout << "Your spa treatment has been booked. Fee: $" << spaCost << endl;
}
void showLaundryService(vector<string>& selectedServices, double& totalCost) {
    string items, instructions;
    double laundryCost = 15.0;
    cout << "\n--- Laundry and Dry Cleaning ---\n";
    cout << "Please enter the items you want cleaned (e.g., shirts, trousers): ";
    cin.ignore();
    getline(cin, items);
    cout << "Any special instructions (e.g., delicate, fast drying)? ";
    getline(cin, instructions);
    totalCost += laundryCost;
    selectedServices.push_back("Laundry: " + items + " with instructions: " + instructions + " ($" + to_string(laundryCost) + ")");
    cout << "Your laundry service has been booked. Fee: $" << laundryCost << endl;
}
void showValetParking(vector<string>& selectedServices, double& totalCost) {
    string carDetails, licensePlate;
    double valetCost = 25.0;
    cout << "\n--- Valet Parking ---\n";
    cout << "Please enter your car's make and model: ";
    cin.ignore();
    getline(cin, carDetails);
    cout << "Please enter your car's license plate number: ";
    getline(cin, licensePlate);
    totalCost += valetCost;
    selectedServices.push_back("Valet Parking: " + carDetails + " (License Plate: " + licensePlate + ") ($" + to_string(valetCost) + ")");
    cout << "Your valet parking has been booked. Fee: $" << valetCost << endl;
}
void showFitnessCenter(vector<string>& selectedServices, double& totalCost) {
    string time;
     double fitnessCost = 10.0;
    cout << "Fitness Center:" << endl;
    cout << "- Gym with various fitness equipment." << endl;
    cout << "- Open 24 hours for hotel guests." << endl;

    cout << "Please enter the time you plan to visit (e.g., 9 AM): ";
    cin.ignore();
    getline(cin, time);
    selectedServices.push_back("Fitness Center: Visit at " + time+") ($" + to_string(fitnessCost) + ")");
    totalCost += 10.0;
    cout << "Your fitness center visit has been scheduled for: " << time << endl << endl;
}
void showBusinessServices(vector<string>& selectedServices, double& totalCost) {
    string service;
    cout << "\n--- Business Services ---\n";
    cout << "Enter the business service needed (e.g., printing, faxing): ";
    cin.ignore();
    getline(cin, service);
    selectedServices.push_back("Business Service: " + service);
    totalCost += 30.0;
    cout << "Your business service request has been booked.\n";
    cout << "Charge for Business Services: $30\n\n";
}

void showPoolAndRecreation(vector<string>& selectedServices, double& totalCost) {
    string request;
    cout << "\n--- Pool and Recreation ---\n";
    cout << "Enter any special request (e.g., poolside lounge reservation): ";
    cin.ignore();
    getline(cin, request);
    selectedServices.push_back("Pool and Recreation: " + request);
    totalCost += 10.0;
    cout << "Your pool and recreation request has been booked.\n";

}
void showSelectedServices(vector<string>& selectedServices, double& totalCost) {
    cout << "\n--- Selected Services ---\n";
    if (selectedServices.empty()) {
        cout << "You have not selected any services yet.\n";
    } else {
        for (const string& service : selectedServices) {
            cout << "- " << service << endl;
        }
        cout << "\nTotal Amount for All Services: $" << totalCost << endl;
    }
}

void addService() {

    vector<string> selectedServices;
    int choice;
    char anotherChoice;

    cout << "Welcome to the Hotel Service Request System!" << endl;
    do {
        cout << "Please choose a service by entering the corresponding number:" << endl;
        cout << "1. Room Service" << endl;
        cout << "2. Concierge Service" << endl;
        cout << "3. Spa and Wellness" << endl;
        cout << "4. Laundry and Dry Cleaning" << endl;
        cout << "5. Valet Parking" << endl;
        cout << "6. Fitness Center" << endl;
        cout << "7. Business Services" << endl;
        cout << "8. Pool and Recreational Activities" << endl;
        cout << "9. View Selected Services" << endl;
        cout << "0. Exit" << endl;

        while (true) {
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice >= 0 && choice <= 9) {
                break;
            } else {
                cout << "Invalid choice. Please select a number between 0 and 9." << endl;
            }
        }

        switch (choice) {
            case 1:
                showRoomService(selectedServices, totalcost);
                break;
            case 2:
                showConciergeService(selectedServices, totalcost);
                break;
            case 3:
                showSpaService(selectedServices, totalcost);
                break;
            case 4:
                showLaundryService(selectedServices, totalcost);
                break;
            case 5:
                showValetParking(selectedServices, totalcost);
                break;
            case 6:
                showFitnessCenter(selectedServices, totalcost);
                break;
            case 7:
                showBusinessServices(selectedServices, totalcost);
                break;
            case 8:
                showPoolAndRecreation(selectedServices, totalcost);
                break;
            case 9:
                showSelectedServices(selectedServices, totalcost);
                break;
            case 0:
                cout << "Thank you for using the hotel service system. Goodbye!" << endl;
                showSelectedServices(selectedServices,totalcost );

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Would you like to select another service? (Y/N): ";
        cin >> anotherChoice;

    } while (anotherChoice == 'Y' || anotherChoice == 'y');

    cout << "Thank you for using the hotel service system. Goodbye!" << endl;
    showSelectedServices(selectedServices, totalcost);

}
void Aboutus ()
{
    cout<< "Ras Amba Hotel: A Historic Landmark in Addis Ababa, Ethiopia/n";
cout<< "Ras Amba Hotel, located in the heart of Addis Ababa, Ethiopia, is a historic and cultural ";
cout<< "landmark that holds significant importance in the country's modern history. Over the decades, ";
cout<< "it has become a symbol of both the nation�s rich heritage and its journey toward modernization. ";
 cout<< "The hotel is not just a place of accommodation, but a focal point for social, political, and ";
 cout<< "diplomatic life in the Ethiopian capital. The combination of its strategic location, rich history, ";
 cout<< " and continued presence in the city makes Ras Amba Hotel a beloved institution in Addis Ababa./n";
cout<< "Founding and Origins/n";
cout<< "Ras Amba Hotel was established in the early 1950s, at a time when Ethiopia was experiencing a period ";
cout<< "of transformation. Following the coronation of Emperor Haile Selassie I in 1930, the country embarked ";
cout<< "on modernization efforts aimed at aligning Ethiopia with global standards. This period witnessed a ";
cout<< "series of infrastructure and architectural advancements, as Ethiopia sought to maintain its status ";
cout<< "as an independent and prosperous nation in the face of geopolitical challenges, including the looming ";
cout<< "threat of colonialism in Africa./n";
cout<< "The name Ras Amba is deeply rooted in Ethiopian history and nobility. Ras is a title granted to ";
cout<< "high-ranking military officers and regional governors, and it can be compared to the rank of Duke in ";
 cout<< "European aristocracy. The title of Ras is historically associated with Ethiopian royalty, and it ";
 cout<< " signifies respect and authority. The name �Ras Amba� was chosen for the hotel to reflect the ";
 cout<< " country�s aristocratic traditions and the hotel�s close ties to the Ethiopian elite. ";
cout<< "Situated on a hilltop, the hotel�s location offers magnificent views of Addis Ababa. It became an ";
cout<< "ideal venue for social gatherings, political meetings, and diplomatic functions. In the early years ";
cout<< " of its existence, Ras Amba Hotel was part of a wave of hotels that began to emerge in Addis Ababa ";
cout<< "  as the city grew in stature and influence. The construction of Ras Amba coincided with a time when  ";
cout<< "  the city was becoming an important political, economic, and cultural center in Africa. /n";
cout<< "Cultural Legacy and Modern-Day Relevance/n";
cout<< "Today, Ras Amba Hotel stands as a symbol of Addis Ababa�s historical and cultural identity. It serves ";
cout<< " as both a historical landmark and a modern business establishment. The hotel continues to provide lodging, ";
cout<< "  dining, and event spaces for a wide range of visitors, including tourists, business professionals, ";
  cout<< "and locals who appreciate the hotel�s long-standing role in Ethiopia�s history.";
cout<< "The hotel�s legacy goes beyond its role as an accommodation provider. It is a place where the past meets ";
cout<< "the present, where the stories of Ethiopian nobility, imperial rule, political change, and social evolution ";
cout<< " are still remembered. Ras Amba also plays an important role in the country�s tourism sector, as many ";
cout<< " visitors are drawn not only to the hotel�s amenities but also to its historical significance. For many ";
cout<< " Ethiopians, the hotel is a cherished institution that connects them to their past while also serving as ";
cout<< "  a point of continuity amid the changes in their country./n";
cout<< "Conclusion/n";
cout<< "Ras Amba Hotel in Addis Ababa is much more than just a place to stay; it is a historical institution that ";
cout<< " encapsulates the cultural, political, and social evolution of Ethiopia. From its founding in the 1950s, ";
cout<< "  the hotel has witnessed the rise and fall of political regimes, the transformation of Addis Ababa from ";
 cout<< " a small town into a bustling metropolis, and the development of Ethiopia into a modern state. Its historical ";
 cout<< " significance, architectural beauty, and role as a center for social and political life have solidified ";
 cout<< " Ras Amba Hotel�s place in the heart of Ethiopia's capital. ";
cout<< "Today, while it faces competition from more modern hotels, Ras Amba continues to be a beloved symbol of the ";
 cout<< "city�s past. It serves as a reminder of the continuity and resilience of Ethiopian culture, a testament to ";
 cout<< "the city�s rich heritage and the diverse layers of its evolving story. For both locals and visitors, Ras Amba ";
 cout<< " remains a cherished landmark that offers a glimpse into Ethiopia�s remarkable journey from the imperial era ";
 cout<< "  to the present day.";
}

int main() {

    cout << "**** WELCOME TO RAS AMBA HOTEL!!!! ****" << endl;
    int choice;

    do {
        cout << "\nHotel Reception Services Menu:\n";
        cout << "1. Check In\n";
        cout << "2. Food and drink service\n";
        cout << "3. Addtional Service\n";
        cout << "4. About us\n";
        cout << "5. Insert comment\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkIn();
                break;
            case 2:
                displayFoodMenu();
                break;
            case 3:
                addService();
                break;
            case 4:
                Aboutus();
                break;
            case 5:
                Comment();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
