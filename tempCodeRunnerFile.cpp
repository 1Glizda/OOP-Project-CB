#include <iostream>
#include <string>
#include <fstream>
#include <random>

class EventLocation {
    private:
        int maxSeats;
        int numRows;
        int numZones;
        int seatsPerRow;
    public:
        EventLocation(int maxSeats, int numRows, int numZones, int seatsPerRow) {
            this->maxSeats = maxSeats;
            this->numRows = numRows;
            this->numZones = numZones;
            this->seatsPerRow = seatsPerRow;
        }
        int getMaxSeats() { return maxSeats; }
        int getNumRows() { return numRows; }
        int getNumZones() { return numZones; }
        int getSeatsPerRow() { return seatsPerRow; }
};

class Event {
    private:
        std::string name;
        std::string date;
        std::string time;
    public:
        Event(std::string name, std::string date, std::string time) {
            this->name = name;
            this->date = date;
            this->time = time;
        }
        std::string getName() { return name; }
        std::string getDate() { return date; }
        std::string getTime() { return time; }
};

class Ticket {
    private:
        std::string id;
        std::string type;
    public:
        Ticket(std::string type) {
            this->type = type;
            // Generate unique ID using random number generator
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(1000000, 9999999);
            id = std::to_string(dist(mt));
        }
        std::string getId() { return id; }
        std::string getType() { return type; }
};

class TicketManager {
    private:
        EventLocation location;
        Event event;
        int numIssued;
    public:
        TicketManager(EventLocation location, Event event) {
            this->location = location;
            this->event = event;
            numIssued = 0;
        }
        bool generateTicket(std::string type) {
            if (numIssued >= location.getMaxSeats()) {
                std::cout << "Error: all tickets have been issued for this event." << std::endl;
                return false;
            }
            Ticket ticket(type);
            std::cout << "Ticket generated with ID: " << ticket.getId() << std::endl;
            numIssued++;
            return true;
        }
        bool validateTicket(std::string id) {
            // Verify that the given ID is valid (i.e. matches a previously issued ticket
            for (int i = 0; i < numIssued; i++) {
                if (ticketList[i].getId() == id) {
                    std::cout << "Ticket with ID " << id << " is valid for the " << event.getName() << " event on " << event.getDate() << " at " << event.getTime() << std::endl;
                    return true;
                }
            }
            std::cout << "Error: ticket with ID " << id << " is not valid for this event." << std::endl;
            return false;
        }
    private:
        Ticket ticketList[1000];
};

int main() {
    EventLocation location(1000, 50, 2, 20);
    Event event("Concert", "Jan 1, 2022", "8:00 PM");
    TicketManager manager(location, event);

    while (true) {
        std::cout << "1. Generate Ticket" << std::endl;
        std::cout << "2. Validate Ticket" << std::endl;
        std::cout << "3. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter ticket type (VIP, General, etc): ";
            std::string type;
            std::cin >> type;
            manager.generateTicket(type);
        } else if (choice == 2) {
            std::cout << "Enter ticket ID: ";
            std::string id;
            std::cin >> id;
            manager.validateTicket(id);
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
        }
    }
    return 0;
}