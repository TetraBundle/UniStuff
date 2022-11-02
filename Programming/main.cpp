#include <iostream>
#include <string>
#include <cassert>

class Datetime
{
private: //kann man nur innerhalb der Klasse ansprechen, also nur innerhalb von Methoden derselben Klasse. z.B. Datetime

    int year,month,day,hour,minute;
public: //public ueberrall
    void set(int year, int month, int day, int hour, int minute){  //setter methoden sind zum setzen des wertes in der variab;e

        if (month > 12 || day > 31 || hour > 24 || minute > 60)
        {
            throw std::runtime_error("Zeitformat stimmt nedde");
        }

        this ->year=year;
        this ->month=month;   //Jedes Objekt enthaelt einen Zeiger "this", der auf das Objekt zeigt
        this ->day=day;
        this ->hour=hour;
        this ->minute=minute;
    }

    int getYear(){return year;};  //getter methoden sind zum auslesen
    int getMonth(){return month;};
    int getDay(){return day;};
    int getHour(){return hour;};
    int getMinute(){return minute;};

    int compare(const Datetime& other) //Um Kopien zu vermeiden wurde eine Referenz gewahelt, const bedeutet nicht aenderbar
    {

        /* if (year != other.year ){
                 return ((year > other.year) ? 1 : -1);
             }
             else if (month != other.month ){
                 return ((month > other.month) ? 1 : -1);
             }
             else if (day != other.day ){
                 return ((day > other.day) ? 1 : -1);
             }
             else if (hour != other.hour ){
                 return ((hour > other.hour) ? 1 : -1);
             }
             else if (minute != other.minute ) {
                 return ((minute > other.minute) ? 1 : -1);
             }else{
                 return 0;
             }
         }
         */
        int result = (year-other.year) + (month-other.month) + (day-other.day) + (hour-other.hour) + (minute-other.minute);

    }
};

class Match
{
private:
    std::string home,guest;
    Datetime datetime;
    int GoalsGuest, GoalsHome;
public:
    void set(std::string home, std::string guest, Datetime datetime, int GoalsGuest, int  GoalsHome){

        if(home == ""|| guest == ""){

            throw std::runtime_error("no value");
        }


        this ->home = home;
        this ->guest = guest;
        this ->datetime = datetime;
        this ->GoalsGuest = GoalsGuest;
        this ->GoalsHome = GoalsHome;



    }

    Datetime getBegins(){return datetime;};
    int getGoalsGuest(){return GoalsGuest;};
    int getGoalsHome(){return GoalsHome;};
    std::string getGuest(){return guest;};
    std::string getHome(){return home;};



};

void testMatch() {
    Match match;
    Datetime datetime1;
    Datetime datetime2;
    datetime1.set(2022, 10, 1, 15, 30);
    datetime2.set(2022, 11, 1, 15, 30);
    assert(datetime1.compare(datetime2)<0); //hier geprueft ob es stimmt mit compare bruh
    std::string home="Ducktown";
    std::string guest="Springfield";
    match.set(home, guest, datetime1, 0, 0);
    auto begins = match.getBegins();
    assert(2022 == begins.getYear());
    assert(10 == begins.getMonth());
    assert(30 == begins.getMinute());
    assert(1 == begins.getDay());
    assert(15 == begins.getHour());
    assert(match.getGoalsGuest() == 0);
    assert(match.getGoalsHome() == 0);
    assert(match.getGuest() == "Springfield");
    assert(match.getHome() == "Ducktown");
    home[0]='X';
    guest[0]='X';
    assert(match.getGuest() == "Springfield");
    assert(match.getHome() == "Ducktown");
}

int main()
{
    std::string y;
    Datetime lectureTime;
    lectureTime.set(2022,10,11,11,30);
    std::cout << y << std::endl;
    testMatch();

    //Vertraege koennen nicht erfuellt werden, wenn z.b. falsche values eingefuegt werden z.b. in monat 13 obwohl es keine 13 monate gibts

    //2min BTW
}