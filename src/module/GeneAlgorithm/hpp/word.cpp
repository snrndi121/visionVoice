/*
  * WordNode
*/
/*
  * WordList
*/
WordList::WordList(string _str, float _startTime, float _endTime)
{
    for (uint i = 0; i <_str.size(); ++i) {
        this->add(_str[i]);
    }
    this->startTime =_startTime;
    this->endTime =_endTime;
}
//method
void WordList::add(char _word, int _index)
{
    WordNode wn = this->makeWord(_word, _index);
    sentence.push_back(wn);
}
WordNode WordList::makeWord(char _word, int _index)
{
    cvtWordType cwt(_word);
    WordNode wn;
    wn.code = cwt.mother_word;
    wn.index = _index;
    return wn;
}
//set
void WordList::setLap(float _startTime, float _endTime)
{
    startTime =_startTime;
    endTime =_endTime;
}
void WordList::setScore(float _score)
{
    score =_score;
}
//get
string WordList::getSentence() const
{
    string res;
    for (uint i = 0; i < sentence.size(); ++i) {
        res += sentence[i].code;
    }
    return res;
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
