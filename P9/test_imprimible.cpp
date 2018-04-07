#include <iostream>
#include <string>

class IPrintable 
{
public:
    virtual void Print () = 0;
};

class Clock
{
private:
    int seg {0};
    int min {0};
    int hor {0};

public:
    Clock () = default;
    Clock (int _seg, int _min, int _hor);
    void SetTime (int _seg, int _min, int _hor);
    int GetHours ();
    int GetMinutes ();
    int GetSeconds ();
    bool operator== (const Clock & rhs);
};

Clock::Clock (int _seg, int _min, int _hor)
{
    (_seg >= 0 && _seg<=59) ? this->seg = _seg : this->seg = 0;
    (_min >= 0 && _min<=59) ? this->min = _min : this->min = 0;
    (_hor >= 0 && _hor<=23) ? this->hor = _hor : this->hor = 0;
}

void Clock::SetTime (int _seg, int _min, int _hor)
{
    this->seg = _seg;
    this->min = _min;
    this->hor = _hor;
}

int Clock::GetHours ()
{
    return (this->hor);
}

int Clock::GetMinutes ()
{
    return (this->min);
}

int Clock::GetSeconds ()
{
    return (this->seg);
}

bool Clock::operator== (const Clock &rhs)
{
    if (this->seg == rhs.seg){
        if (this->min == rhs.min){
            if(this->hor == rhs.hor){ return true; }}}
    return false;
}


class UserClock : public Clock, public IPrintable
{
public:
	UserClock (int _seg, int _min, int _hor);
    virtual void Print () override ;
};

UserClock::UserClock (int _seg, int _min, int _hor) : Clock{_seg, _min, _hor}
{
	//nada
}

void UserClock::Print ()
{	
	std::string horario, horafull, hora, minu, segu;
	int hora_temp;
    if (GetHours()<12)
    {
    	horario = " AM";
    	if (GetHours () == 0)
    		hora_temp = 12;
    }
    else 
    {
    	horario = " PM";
    	if (GetHours() != 12)
    		hora_temp = GetHours() - 12;
    }  

    if (hora_temp <10 )
        {
            hora = "0"+std::to_string (hora_temp);
        }
    else hora = std::to_string (hora_temp);

    if (GetMinutes () <10 )
        {
            minu = "0"+std::to_string (GetMinutes());
        }
    else minu = std::to_string (GetMinutes());

    if (GetSeconds () <10 )
        {
            segu = "0"+std::to_string (GetSeconds ());
        }
    else segu = std::to_string (GetSeconds ());

    horafull = hora + ":" + minu + ":" + segu + " " + horario ;
    std::cout<<"La hora es: "<< horafull <<std::endl;
}



int main ()
{
	UserClock reloj (10, 15, 18);
	UserClock reloj2 (45, 2, 13);
	reloj.Print ();
    reloj2.Print ();

	(reloj==reloj2) ? std::cout<< "Los relojes son iguales"<<std::endl : std::cout<< "Los relojes no son iguales"<<std::endl;
}

