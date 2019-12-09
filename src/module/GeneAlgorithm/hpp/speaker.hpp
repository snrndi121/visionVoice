#ifndef _SPEAKER_H_
#define _SPEAKER_H_

class Speaker {
public :
    Speaker(){};
    Speaker(unsigned int);
    void setId(unsigned int);
    unsigned int getId() const;
private :
    unsigned int id;
    //string name;
    //Image img;
};

#endif
#ifndef _SPEAKER_CPP_
#define _SPEAKER_CPP_
#include "speaker.cpp"
#endif
