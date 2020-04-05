/*
  * TalkSession
*/
TalkSession::TalkSession(Speaker _speaker)
{
    this->speaker =_speaker;
}
//method
void TalkSession::addBundle(WordList _bundle)
{
    this->talkBundles.push_back(_bundle);
    this->laptime += _bundle.getLapTime();
}
//set
void TalkSession::setSpeaker(Speaker _speaker)
{
    this->speaker.setId(_speaker.getId());
}
void TalkSession::setLapTime(float _time)
{
    this->laptime =_time;
}
//get
Speaker TalkSession::getSpeaker() const
{
    return this->speaker;
}
float TalkSession::getLapTime() const
{
    return this->laptime;
}
vector < WordList > TalkSession::getTalkBundles() const
{
    return this->talkBundles;
}
/*
  * TalksHistory
*/
//method
void TalkHistory::addSession(TalkSession _ts)
{
    eachConversation.push_back(_ts);
}
//set
void TalkHistory::setLapTime(float _laptime)
{
    this->laptime =_laptime;
}
void TalkHistory::setFullTalk(WordList _wordlist)
{
    this->fullConversation =_wordlist;
}
//get
float TalkHistory::getLapTime() const
{
    return this->laptime;
}
// WordList TalkHistory::getFullTalk() const
// {
//     return this->fullConversation;
// }
WordList& TalkHistory::getFullTalk()
{
    return (this->fullConversation);
}
vector < TalkSession > TalkHistory::getTalkSession() const
{
    return this->eachConversation;
}
unsigned int TalkHistory::getSessionCount() const
{
    return this->eachConversation.size();
}
