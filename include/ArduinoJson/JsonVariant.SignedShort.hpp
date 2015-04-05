// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {

inline JsonVariant::JsonVariant(signed short value) {
  _type = Internals::JSON_LONG;
  _content.asLong = value;
}

template <>
inline signed short JsonVariant::as<signed short>() const {
  return _type == Internals::JSON_LONG
             ? static_cast<signed short>(_content.asLong)
             : 0;
}
}
