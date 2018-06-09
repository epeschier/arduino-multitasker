#ifndef Sensor_h
#define Sensor_h

template <class T>
class Sensor {
  public:
    Sensor();
    T GetValue();
    bool ValueChanged();
  protected:
    virtual void Init() = 0;
    T _value;
    T _previousValue;
};

template <class T>
Sensor<T>::Sensor() {
  Init();
}

template <class T>
void Sensor<T>::Init() {

}

template <class T>
T Sensor<T>::GetValue() {
  _previousValue = _value;
  return _value;
}

template <class T>
bool Sensor<T>::ValueChanged() {
  return (_previousValue != _value);
}
#endif
