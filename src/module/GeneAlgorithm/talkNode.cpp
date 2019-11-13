#include "userType.hpp"

void TalkWord::addSibling(char _data, vec_uint _sibling) {
    if (vec_uint.size() == 0) {
        cerr << " > talkNode::addsibling is empty.";
        return;
    }
    talkNode* curSibling = this->sibling;
    for (uint i = 0; i < _sibling.size(); ++i) {
        talkNode tn(_data, _sibling[i]);
        if (curSibling != 0) {
            curSibling->sibling = &tn;
        } else {
            curSibling = &tn;
        }
    }
}
