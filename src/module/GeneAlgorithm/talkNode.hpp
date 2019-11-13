#ifndef _LIST_H_
#define _LIST_H_

#include <list>

#endif

#ifndef _TALKNODE_
#define _TALKNODE_

#include "talkNode.cpp"

class TalkWord {
public :
    TalkWord(char data, uint location) : data(data), location(location), parent(0), sibling(0), child(0) {};
    //형제만 추가
    void addSibling(char _data, vec_uint _sibling);//탐색 전까지는 parent, child 는 Null 상태
private :
    char data;
    uint location;
    TalkWord* parent;
    TalkWord* sibling;
    TalkWord* child;
};

class TalkTree {
public :
    TalkTree() {};
    void searchDFS();
    void setPath(vec_uint path) { this.path = path;}
    vector < vec_uint > getPath () const { return this->path;}
private :
    TalkWord* root;
    vector < vec_uint > path;
}
#endif
