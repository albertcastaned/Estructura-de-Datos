/*--------------------------------/
 *
 * Actividad de programacion
 * Fecha: 20 de Agosto
 * Autor: Alberto Castañeda Arana
 * 
/--------------------------------*/

#define TIMER_H_

#include <string>
#include <sstream>

class Timer
{
    public:
        Timer()
        {
            hours=0;
            mins=0;
        }

        Timer(int hh,int mm)
        {
            hours=hh%24;

            if(mm>=60)
            {
                mins = mm%60;
                hours+=(mm/60);
            }else{
                mins = mm;
            }
        }

        Timer(const Timer &source)
        {
            hours = source.hours;
            mins = source.mins;
        }
        std::string toString() const;
        int getHours() const;
        int getMins() const;
        void operator= (const Timer&);
        void operator+= (const Timer&);

    private:
        int hours;
        int mins;


};

int Timer::getHours() const{
    return hours;
}

int Timer::getMins() const{
    return mins;
}

void Timer::operator= (const Timer &right){
    hours = right.hours;
    mins = right.mins;
}
void Timer::operator+= (const Timer &right){
    hours += right.hours;
    mins += right.mins;
    hours=hours%24;

    if(mins>=60)
    {
        
        hours+=(mins/60);
        mins = mins%60;
    }
}

bool operator== (const Timer &right, const Timer &left)
{
    if((right.getHours() == left.getHours()) && (right.getMins() == left.getMins()))
    {
        return true;
    }else{
        return false;
    }
}
bool operator> (const Timer &right, const Timer &left)
{
    if(right.getHours() > left.getHours())
    {
        return true;
    }else{
        if(right.getMins() > left.getMins())
        {
            return true;
        }else{
            return false;
        }
    }
}


std::string Timer::toString() const {
	 std::stringstream aux;

	 if (hours < 10) {
		 aux << "0";
	 }
	 aux << hours << ":";
	 if (mins < 10) {
		 aux << "0";
	 }
	 aux << mins;
	 return aux.str();
}