struct FType {//searchType
  FType() {;}
  FType(size_t _sz, const char *_data) {
      set(_sz, _data);
  }
  friend ostream&
  operator<<(ostream& ost, const FType* s) {
      for (size_t i = 0; i < s->sz; ++i) { ost << s->data[i];}
      return ost;
  }
  void set(size_t _sz, const char *_data) {
        if (data != nullptr) delete data;
        this->sz =_sz;
        data = new char[_sz];
        for (size_t i = 0; i < _sz; ++i) { data[i]=_data[i];}
  }
  ~FType() {
      cout << "\n##FType die\n";
      cout << this << endl;
      cout << "\nsz :" << sz << ", data :" << data << endl;
      sz = 0;
      delete data;
}
  //var
  size_t sz = 0;
  char *data = nullptr;
};
