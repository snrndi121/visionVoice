/*
  * WordNode
*/
/*
  * WordList
*/
WordList::WordList(string _str, float _startTime, float _endTime)
{
    this->startTime =_startTime;
    this->endTime =_endTime;
    //initialize timing
    float total_time = this->getLapTime();
    uint wordlist_size = _str.size();
    float _timing = 0;
    if (wordlist_size > 0) {
        _timing = total_time / wordlist_size;
    } else {
        cerr << "WordList::WordList() has a string of zero length" << endl;
    }
    //Add word : (word, timing, index)
    for (uint i = 0; i <_str.size(); ++i) {
        this->add(_str[i], -1, _timing);
    }
}
//method
void WordList::add(char _word, int _index, float _timing)
{
    WordNode wn = this->makeWord(_word, _index, _timing);
    sentence.push_back(wn);
}
//WordNode = (word, index, timing)
WordNode WordList::makeWord(char _word, int _index, float _timing)
{
    //(word, index)
    // static int tag = 0;
    cvtWordType cwt(_word);
    WordNode wn;
    wn.code = cwt.mother_word;
    wn.index = _index;
    //(word, index, timing)
    if (_timing <= 0) {
        cerr << "WordList::makeWord() cannot initialize timing.\n";
    } else {
        uint last = sentence.size();
        if (last > 0) {
            wn.startTime = sentence[last - 1].endTime;
            wn.endTime = wn.startTime + _timing;
        } else {
            wn.startTime = this->startTime;
            wn.endTime = startTime + _timing;
        }
    }
    // cout << tag++ << ' ' << wn.startTime << ' ' << wn.endTime << endl;
    return wn;
}
//set
void WordList::setLap(float _startTime, float _endTime)
{
    startTime =_startTime;
    endTime =_endTime;
}
void WordList::setLapAt(uint _index, float _startTime, float _endTime)
{
    if (this->sentence.size() <=_index) {
        cerr << "WordList::setLapAt() got wrong parameter." << endl;
        return ;
    }
    this->sentence[_index].startTime =_startTime;
    this->sentence[_index].endTime =_endTime;
}
void WordList::setScore(float _score)
{
    score =_score;
}
//get
string WordList::getString() const
{
    string res;
    for (uint i = 0; i < sentence.size(); ++i) {
        res += sentence[i].code;
    }
    return res;
}
vector < WordNode > WordList::getSentence() const
{
    return sentence;
}
float WordList::getLapTime() const
{
    if (endTime <= startTime) {
        cerr << "WordList::getLapTime has wrong member variables.\n";
        return -1;
    }
    return (endTime - startTime);
}
float WordList::getStartTime() const
{
    return this->startTime;
}
float WordList::getEndTime() const
{
    return this->endTime;
}
uint WordList::size() const
{
    return sentence.size();
}
/*
  * WordCandidate
*/
// void WordCandidate::add(WordList wl)
// {
//     candidates.push_back(wl);
// }
// void setRepresent(string _origin)
// {
//     origin =_origin;
// }
