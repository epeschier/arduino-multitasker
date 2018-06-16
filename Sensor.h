#ifndef Sensor_h
#define Sensor_h

template <class T>
class Sensor {
  public:
    Sensor();
    T GetValue();
    bool ValueChanged();
  protected:
    T _value;
    T _previousValue;
};

template <class T>
Sensor<T>::Sensor() {
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
