#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to represent a movie ticket
struct MovieTicket {
    string movieName;
    double ticketPrice;
    MovieTicket* next; // Pointer to the next ticket in the linked list
};

// Function to add a new movie ticket to the collection
void addTicket(MovieTicket*& head, const string& movieName, double ticketPrice) {
    MovieTicket* newTicket = new MovieTicket{ movieName, ticketPrice, nullptr };

    if (head == nullptr) {
        // If the list is empty, make the new ticket the head
        head = newTicket;
    } else {
        // Traverse the list to find the last ticket and add the new ticket
        MovieTicket* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newTicket;
    }
}

// Function to display all movie tickets in the collection
void displayAllTickets(const MovieTicket* head) {
    cout << "All Movie Tickets:\n";
    const MovieTicket* current = head;
    while (current != nullptr) {
        cout << "Movie: " << setw(20) << current->movieName
             << "   Ticket Price: $" << fixed << setprecision(2) << current->ticketPrice << endl;
        current = current->next;
    }
    cout << endl;
}

// Function to search for a movie ticket with a specific movie name
MovieTicket* searchTicketByMovie(const MovieTicket* head, const string& movieName) {
    const MovieTicket* current = head;
    while (current != nullptr) {
        if (current->movieName == movieName) {
            return const_cast<MovieTicket*>(current); // Cast away const for demonstration purposes
        }
        current = current->next;
    }
    return nullptr;
}

// Function to display movie tickets within a specified price range
void displayTicketsByPrice(const MovieTicket* head, double minPrice, double maxPrice) {
    cout << "Movie Tickets within Price Range $" << minPrice << " to $" << maxPrice << ":\n";
    const MovieTicket* current = head;
    while (current != nullptr) {
        if (current->ticketPrice >= minPrice && current->ticketPrice <= maxPrice) {
            cout << "Movie: " << setw(20) << current->movieName
                 << "   Ticket Price: $" << fixed << setprecision(2) << current->ticketPrice << endl;
        }
        current = current->next;
    }
    cout << endl;
}

// Function to calculate and display the average ticket price
void displayAverageTicketPrice(const MovieTicket* head) {
    if (head == nullptr) {
        cout << "No tickets available.\n";
        return;
    }

    double total = 0.0;
    int count = 0;

    const MovieTicket* current = head;
    while (current != nullptr) {
        total += current->ticketPrice;
        count++;
        current = current->next;
    }

    double average = total / count;
    cout << "Average Ticket Price: $" << fixed << setprecision(2) << average << endl << endl;
}

// Function to find and display the movie with the highest ticket price
void displayMovieWithHighestPrice(const MovieTicket* head) {
    if (head == nullptr) {
        cout << "No tickets available.\n";
        return;
    }

    const MovieTicket* current = head;
    double maxPrice = current->ticketPrice;
    string movieWithMaxPrice = current->movieName;

    while (current != nullptr) {
        if (current->ticketPrice > maxPrice) {
            maxPrice = current->ticketPrice;
            movieWithMaxPrice = current->movieName;
        }
        current = current->next;
    }

    cout << "Movie with the Highest Ticket Price:\n";
    cout << "Movie: " << setw(20) << movieWithMaxPrice
         << "   Ticket Price: $" << fixed << setprecision(2) << maxPrice << endl << endl;
}

// Function to calculate and display the total revenue from all tickets
void displayTotalRevenue(const MovieTicket* head) {
    if (head == nullptr) {
        cout << "No tickets available.\n";
        return;
    }

    double totalRevenue = 0.0;
    const MovieTicket* current = head;
    while (current != nullptr) {
        totalRevenue += current->ticketPrice;
        current = current->next;
    }

    cout << "Total Revenue from Movie Tickets: $" << fixed << setprecision(2) << totalRevenue << endl << endl;
}

// Function to delete all movie tickets and free memory
void deleteAllTickets(MovieTicket*& head) {
    MovieTicket* current = head;
    while (current != nullptr) {
        MovieTicket* nextTicket = current->next;
        delete current;
        current = nextTicket;
    }
    head = nullptr; // Set head to nullptr after deleting all tickets
}

int main() {
    MovieTicket* ticketList = nullptr;

    // Adding movie tickets to the collection
    addTicket(ticketList, "Inception", 10.50);
    addTicket(ticketList, "Titanic", 8.75);
    addTicket(ticketList, "Avengers: Endgame", 12.25);
    addTicket(ticketList, "Jurassic Park", 9.99);

    // Displaying all movie tickets
    displayAllTickets(ticketList);

    // Searching for a movie ticket by movie name
    string searchMovie = "Titanic";
    MovieTicket* searchedTicket = searchTicketByMovie(ticketList, searchMovie);
    if (searchedTicket != nullptr) {
        cout << "Found Ticket for Movie '" << searchMovie << "':\n";
        cout << "Movie: " << setw(20) << searchedTicket->movieName
             << "   Ticket Price: $" << fixed << setprecision(2) << searchedTicket->ticketPrice << endl << endl;
    } else {
        cout << "Ticket for Movie '" << searchMovie << "' not found.\n\n";
    }

    // Displaying movie tickets within a specified price range
    double minPrice = 9.0, maxPrice = 11.0;
    displayTicketsByPrice(ticketList, minPrice, maxPrice);

    // Displaying the average ticket price
    displayAverageTicketPrice(ticketList);

    // Displaying the movie with the highest ticket price
    displayMovieWithHighestPrice(ticketList);

    // Displaying the total revenue from all tickets
    displayTotalRevenue(ticketList);

    // Cleaning up and deleting all movie tickets
    deleteAllTickets(ticketList);

    return 0;
}