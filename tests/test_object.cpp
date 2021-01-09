#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../src/object.hpp"
#include "../src/render.hpp"
using namespace testing;
\

TEST(Object, getRect){
    Render render;
    render.createWindow("CyberBugEngine", 800, 600);
    Object *object = new Object(10, 12, 100, 102, "/home/artem/C++/CyberBugEngine/tests/test.png");

    EXPECT_EQ(object->getRect()->x, 10);
    EXPECT_EQ(object->getRect()->y, 12);
    EXPECT_EQ(object->getRect()->w, 100);
    EXPECT_EQ(object->getRect()->h, 102);
    ASSERT_THAT(0, Eq(0));
}
