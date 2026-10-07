#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class MoodEntry
{
private:
    string date;
    int rating;
    string note;

public:
    // Default constructor
    MoodEntry();

    // Parameterized constructor
    MoodEntry(string date, int rating, string note);

    // Mutators
    void setDate(string date);
    void setRating(int rating);
    void setNote(string note);

    // Accessors
    string getDate() const;
    int getRating() const;
    string getNote() const;

    // Display function
    void printEntry() const;
};


// Default constructor
MoodEntry::MoodEntry()
{
    date = "Unspecified";
    rating = 3;
    note = "No note";
}


// Parameterized constructor
MoodEntry::MoodEntry(string date, int rating, string note)
{
    setDate(date);
    setRating(rating);
    setNote(note);
}


// Set date
void MoodEntry::setDate(string date)
{
    if (!date.empty())
    {
        this->date = date;
    }
    else
    {
        this->date = "Unspecified";
    }
}


// Set rating
void MoodEntry::setRating(int rating)
{
    if (rating >= 1 && rating <= 5)
    {
        this->rating = rating;
    }
    else
    {
        this->rating = 3;
    }
}


// Set note
void MoodEntry::setNote(string note)
{
    if (!note.empty())
    {
        this->note = note;
    }
    else
    {
        this->note = "No note";
    }
}


// Get date
string MoodEntry::getDate() const
{
    return date;
}


// Get rating
int MoodEntry::getRating() const
{
    return rating;
}


// Get note
string MoodEntry::getNote() const
{
    return note;
}


// Print one entry
void MoodEntry::printEntry() const
{
    cout << "Date: " << date << endl;
    cout << "Rating: " << rating << "/5" << endl;
    cout << "Note: " << note << endl;
    cout << "------------------------" << endl;
}


int main()
{
    MoodEntry entries[20];
    int entryCount = 0;

    int choice;

    cout << "Welcome to MoodMate!" << endl;

    while (true)
    {
        cout << "\n===== MoodMate Menu =====" << endl;
        cout << "1. Add entry" << endl;
        cout << "2. View entries" << endl;
        cout << "3. View average rating" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        // Handle nonnumeric menu input
        if (!(cin >> choice))
        {
            cout << "Invalid menu choice. Please enter a number from 1 to 4."
                 << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Remove leftover newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            if (entryCount >= 20)
            {
                cout << "The log is full. No more entries can be added."
                     << endl;
                continue;
            }

            string date;
            string note;
            int rating;

            cout << "Enter date (YYYY-MM-DD): ";
            getline(cin, date);

            cout << "Enter rating (1-5): ";

            if (!(cin >> rating))
            {
                cout << "Invalid rating. The entry will use the fallback "
                     << "rating of 3." << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                rating = 3;
            }
            else
            {
                // Remove leftover newline before reading note
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter a short note: ";
            getline(cin, note);

            MoodEntry newEntry(date, rating, note);

            entries[entryCount] = newEntry;
            entryCount++;

            cout << "Entry added successfully." << endl;
        }
        else if (choice == 2)
        {
            if (entryCount == 0)
            {
                cout << "There are no entries to display yet." << endl;
            }
            else
            {
                cout << "\n===== Mood Entries =====" << endl;

                for (int i = 0; i < entryCount; i++)
                {
                    cout << "Entry " << (i + 1) << endl;
                    entries[i].printEntry();
                }
            }
        }
        else if (choice == 3)
        {
            if (entryCount == 0)
            {
                cout << "An average cannot be calculated because there "
                     << "are no entries." << endl;
            }
            else
            {
                int total = 0;

                for (int i = 0; i < entryCount; i++)
                {
                    total += entries[i].getRating();
                }

                double average =
                    static_cast<double>(total) / entryCount;

                cout << fixed << setprecision(1);
                cout << "Average rating: " << average << "/5.0" << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "Thank you for using MoodMate. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid menu choice. Please choose 1, 2, 3, or 4."
                 << endl;
        }
    }

    return 0;
}
