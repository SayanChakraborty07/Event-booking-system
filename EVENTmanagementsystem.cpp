
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <conio.h>

using namespace std;

map<string, tuple<string, string, string>> userDetails;

class Event
{
protected:
    string eventName;
    string eventDate;
    string eventOrganizer;
    string eventGuest;
    string eventVenue;
    string eventTiming;
    int seats;

public:
    Event(string name, string date, string organization, string guest, string venue, string timing, int seat)
        : eventName(name), eventDate(date), eventOrganizer(organization), eventGuest(guest), eventVenue(venue), eventTiming(timing), seats(seat) {}

    void display() const
    {
        cout << "Event Name: " << eventName << endl;
        cout << "Event Date: " << eventDate << endl;
        cout << "Organizer: " << eventOrganizer << endl;
        cout << "Guest: " << eventGuest << endl;
        cout << "Venue: " << eventVenue << endl;
        cout << "Time: " << eventTiming << endl;
        cout << "Seats Available: " << seats << endl;
    }

    string getName() const { return eventName; }
    int getSeats() const { return seats; }

    bool bookSeat()
    {
        if (seats > 0)
        {
            seats--;
            return true;
        }
        return false;
    }

    void cancelSeat() { seats++; }
};

class EventManager
{
    vector<Event *> events;
    map<string, vector<Event *>> userBookings;

public:
    void addEvent(Event *e) { events.push_back(e); }

    void showEvents()
    {
        if (events.empty())
        {
            cout << "No Events Available" << endl;
            cout<<" "<<endl;
            return;
        }
        cout << "Available Events:" << endl;
        for (size_t i = 0; i < events.size(); i++)
        {
            cout << i + 1 << ". ";
            events[i]->display();
            cout << "-----------------------------" << endl;
        }
    }

    void bookEvent(const string &username, int index)
    {
        if (index < 1 || index > events.size())
        {
            cout << "Invalid Event Selection" << endl;
            return;
        }

        if (events[index - 1]->bookSeat())
        {
            userBookings[username].push_back(events[index - 1]);
            cout << "Booking Confirmed!" << endl;
        }
        else
        {
            cout << "No seats available!" << endl;
        }
    }

    void cancelBooking(const string &username, int index)
    {
        if (userBookings.find(username) == userBookings.end() || index < 1 || index > userBookings[username].size())
        {
            cout << "Invalid Booking" << endl;
            return;
        }

        userBookings[username][index - 1]->cancelSeat();
        userBookings[username].erase(userBookings[username].begin() + (index - 1));
        cout << "Booking Canceled!" << endl;
    }
};

string getPassword()
{
    string password;
    char ch;

    while (true)
    {
        ch = _getch();
        if (ch == 13)
            break;

        if (ch == 8)
        {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            password.push_back(ch);
            cout << "*";
        }
    }
    cout << endl;
    return password;
}

void registerUser()
{
    string email, username, password, mobile;

    cout << "Enter Email ID: ";
    cin >> email;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    password = getPassword(); 

    cout << "Enter Mobile Number: ";
    cin >> mobile;

    userDetails[email] = make_tuple(username, password, mobile);
    cout << "Registration Successful!\n";
}

bool loginUser(string &loggedInUser)
{
    string email, password;
    cout << "Enter Email ID: ";
    cin >> email;
    cout << "Enter Password: ";
    password = getPassword();

    if (userDetails.find(email) != userDetails.end() && get<1>(userDetails[email]) == password)
    {
        loggedInUser = get<0>(userDetails[email]);
        cout << "Login Successful!" << endl;
        return true;
    }
    else
    {
        cout << "Invalid Credentials!" << endl;
        return false;
    }
}

int main()
{
    EventManager manager;
    string loggedInUser = "";
    int choice;

    Event *frostFest = new Event("Frost Fest", "31/11", "Takshak", "Krispie Kristina", "Swami Vivekananda Stadium", "7 PM - 2 AM", 2000);
    Event *rangBarse = new Event("Rang Barse", "25/03", "Takshak", "DJ KAT", "Kshudiram Basu School Ground", "12 PM - 6 PM", 3000);
    manager.addEvent(frostFest);
    manager.addEvent(rangBarse);

    while (true)
    {
        cout << "########## -| Eventhopia |- ##########" << endl;
        cout << "1. Register\n2. Login\n3. Exit\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            if (loginUser(loggedInUser))
            {
                int ch;
                while (true)
                {
                    cout << "\n1. View Events\n2. Book Event\n3. Cancel Booking\n4. Logout\nEnter Choice: "<<endl;
                    cout<<" "<< endl;
                    cin >> ch;

                    if (ch == 1)
                        manager.showEvents();
                    else if (ch == 2)
                    {
                        int eventIndex;
                        cout << "Enter Event Number for Booking: ";
                        cin >> eventIndex;
                        manager.bookEvent(loggedInUser, eventIndex);
                    }
                    else if (ch == 3)
                    {
                        int cancelIndex;
                        cout << "Enter Booking Number to Cancel: ";
                        cin >> cancelIndex;
                        manager.cancelBooking(loggedInUser, cancelIndex);
                    }
                    else if (ch == 4)
                    {
                        loggedInUser = "";
                        cout << "Logged Out Successfully!" << endl;
                        break;
                    }
                    else
                        cout << "Invalid Choice! Try Again." << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting Program..." << endl;
            break;
        }
        else
        {
            cout << "Invalid Choice! Please Try Again." << endl;
        }
    }
    return 0;
}
