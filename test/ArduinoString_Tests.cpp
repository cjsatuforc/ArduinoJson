// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#include <gtest/gtest.h>
#include <ArduinoJson.h>

TEST(ArduinoStringTests, JsonBuffer_ParseArray) {
  DynamicJsonBuffer jsonBuffer;
  String json("[1,2]");
  JsonArray &array = jsonBuffer.parseArray(json);
  ASSERT_TRUE(array.success());
}

TEST(ArduinoStringTests, JsonBuffer_ParseObject) {
  DynamicJsonBuffer jsonBuffer;
  String json("{\"a\":1,\"b\":2}");
  JsonObject &object = jsonBuffer.parseObject(json);
  ASSERT_TRUE(object.success());
}