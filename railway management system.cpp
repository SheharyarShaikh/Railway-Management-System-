#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold train details
struct Train {
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string departureTime;
    string arrivalTime;
};

// Structure to hold user details
struct User {
    string username;
    string password;
    bool isAdmin;
};

// Structure to hold ticket details
struct Ticket {
    int ticketID;
    string passengerName;
    int trainNumber;
    string seatNumber;
};

// Function prototypes
void displayMenu();
void addTrain(vector<Train>& trains);
void viewTrains(const vector<Train>& trains);
void registerUser(vector<User>& users);
bool loginUser(const vector<User>& users, string& loggedInUser, bool& isAdmin);
void bookTicket(vector<Ticket>& tickets, const vector<Train>& trains);
void viewTickets(const vector<Ticket>& tickets);
bool trainExists(const vector<Train>& trains, int trainNumber);

int main() {
    vector<Train> trains;
    vector<User> users;
    vector<Ticket> tickets;
    string loggedInUser;
    bool isAdmin = false;
    int choice;
    
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch (choice) {
            case 1:
                registerUser(users);
                break;
            case 2:
                if (loginUser(users, loggedInUser, isAdmin)) {
                    cout << "Login successful!\n";
                }
                break;
            case 3:
                if (isAdmin) {
                    addTrain(trains);
                } else {
                    cout << "Admin access required!\n";
                }
                break;
            case 4:
                viewTrains(trains);
                break;
            case 5:
                bookTicket(tickets, trains);
                break;
            case 6:
                viewTickets(tickets);
                break;
            case 7:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}

void displayMenu() {
    cout << "\nRailway Management System" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Add Train (Admin Only)" << endl;
    cout << "4. View Trains" << endl;
    cout << "5. Book Ticket" << endl;
    cout << "6. View Tickets" << endl;
    cout << "7. Exit" << endl;
} 

void registerUser(vector<User>& users) {
    User newUser;
    cout << "Enter username: ";
    cin >> newUser.username;
    cout << "Enter password: ";
    cin >> newUser.password;
    cout << "Is admin? (1 for Yes, 0 for No): ";
    cin >> newUser.isAdmin;
    users.push_back(newUser);
    cout << "Registration successful!\n";
}

bool loginUser(const vector<User>& users, string& loggedInUser, bool& isAdmin) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            loggedInUser = username;
            isAdmin = user.isAdmin;
            return true;
        }
    }
    cout << "Invalid credentials!\n";
    return false;
}

void bookTicket(vector<Ticket>& tickets, const vector<Train>& trains) {
    if (trains.empty()) {
        cout << "No trains available for booking.\n";
        return;
    }
    Ticket newTicket;
    cout << "Enter Ticket ID: ";
    cin >> newTicket.ticketID;
    cin.ignore();
    cout << "Enter Passenger Name: ";
    getline(cin, newTicket.passengerName);
    cout << "Enter Train Number: ";
    cin >> newTicket.trainNumber;
    cout << "Enter Seat Number: ";
    cin >> newTicket.seatNumber;
    tickets.push_back(newTicket);
    cout << "Ticket booked successfully!\n";
}

void viewTickets(const vector<Ticket>& tickets) {
    if (tickets.empty()) {
        cout << "No tickets booked yet.\n";
        return;
    }
    cout << "\nList of Tickets:" << endl;
    for (const auto& ticket : tickets) {
        cout << "Ticket ID: " << ticket.ticketID << endl;
        cout << "Passenger Name: " << ticket.passengerName << endl;
        cout << "Train Number: " << ticket.trainNumber << endl;
        cout << "Seat Number: " << ticket.seatNumber << endl;
        cout << "---------------------------" << endl;
    }
}

void addTrain(vector<Train>& trains) {
    Train newTrain;
    cout << "Enter Train Number: ";
    cin >> newTrain.trainNumber;
    cin.ignore();
    
    if (trainExists(trains, newTrain.trainNumber)) {
        cout << "Train with this number already exists!\n";
        return;
    }
    
    cout << "Enter Train Name: ";
    getline(cin, newTrain.trainName);
    
    cout << "Enter Source Station: ";
    getline(cin, newTrain.source);
    
    cout << "Enter Destination Station: ";
    getline(cin, newTrain.destination);
    
    cout << "Enter Departure Time: ";
    getline(cin, newTrain.departureTime);
    
    cout << "Enter Arrival Time: ";
    getline(cin, newTrain.arrivalTime);
    
    trains.push_back(newTrain);
    cout << "Train added successfully!\n";
}

void viewTrains(const vector<Train>& trains) {
    if (trains.empty()) {
        cout << "No trains available.\n";
        return;
    }
    
    cout << "\nList of Trains:" << endl;
    for (const auto& train : trains) {
        cout << "Train Number: " << train.trainNumber << endl;
        cout << "Train Name: " << train.trainName << endl;
        cout << "Source: " << train.source << endl;
        cout << "Destination: " << train.destination << endl;
        cout << "Departure Time: " << train.departureTime << endl;
        cout << "Arrival Time: " << train.arrivalTime << endl;
        cout << "---------------------------" << endl;
    }
}

bool trainExists(const vector<Train>& trains, int trainNumber) {
    for (const auto& train : trains) {
        if (train.trainNumber == trainNumber) {
            return true;
        }
    }
    return false;
}
