#include <iostream>
using namespace std;

int seat[10][10] = { 0 };
int row, col, num;

void seat_layout()
{
    cout << "----Seat Layout (0=Available, 1=Unavailable)----" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << seat[i][j] << " ";
        }
        cout << endl;
    }
}

void single_seat()
{
    while (true) {
        cout << "Enter row and column to book: ";
        cin >> row >> col;
        if (row >= 0 && row <= 10 && col >= 0 && col <= 10) {
            if (seat[row][col] == 0) {
                seat[row][col] = 1;
                cout << "Seat booked successfully." << endl;
                break;
            }
            else {
                cout << "Seat already booked. Please choose another seat." << endl;
            }
        }
        else {
            cout << "Invalid row or column. Please try again." << endl;
        }
    }
}

void block_of_seats()
{
    while (true) {
        cout << "Enter row, starting column, and number of seats to book: ";
        cin >> row >> col >> num;
        if (row >= 0 && row <= 10 && col >= 0 && col <= 10 && num <= 10 - col) {
            bool canBook = true;
            for (int i = 0; i < num; i++) {
                if (seat[row][col + i] == 1) {
                    canBook = false;
                    break;
                }
            }
            if (canBook == true) {
                for (int i = 0; i < num; i++) {
                    seat[row][col + i] = 1;
                }
                cout << "Seats booked successfully." << endl;
                break;
            }
            else {
                cout << "Seat(s) already booked. Please choose other seats." << endl;
            }
            canBook = true;
        }
        else {
            cout << "Invalid row or column or number of seats. Please try again." << endl;
        }
    }
}

void cancel_booking()
{
    while (true) {
        cout << "Enter row and column to cancel: ";
        cin >> row >> col;
        if (row >= 0 && row <= 10 && col >= 0 && col <= 10) {
            if (seat[row][col] == 1) {
                seat[row][col] = 0;
                cout << "Booking cancelled successfully." << endl;
                break;
            }
            else {
                cout << "Seat is not booked. Please try again." << endl;
            }
        }
        else {
            cout << "Invalid row or column or number of seats. Please try again." << endl;
        }
    }
}

void available_seat()
{
    cout << "----Available Seats----" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (seat[i][j] == 0) {
                cout << "Seat (" << i << "," << j << ") is available." << endl;
            }
        }
    }
}

void main_menu()
{
    while (true) {
        cout << "******************************" << endl;
        cout << "* Cinema Seat Booking System *" << endl;
        cout << "******************************" << endl;
        cout << "1. View Seat Layout" << endl;
        cout << "2. Book a Single Seat" << endl;
        cout << "3. Book Block of Seats" << endl;
        cout << "4. Cancel Seat Booking" << endl;
        cout << "5. Display Available Seat Only" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice(1-6): ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            seat_layout();
            break;
        case 2:
            single_seat();
            break;
        case 3:
            block_of_seats();
            break;
        case 4:
            cancel_booking();
			break;
        case 5:
            available_seat();
            break;
        case 6:
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again.";
        }
    }
}

int main()
{
    main_menu();
    return 0;
}
