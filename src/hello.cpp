using namespace std;
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE hello
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "BoundingBox.h"
#include "BoundingBox.cc"

BOOST_AUTO_TEST_SUITE( hello );

int add(int i, int j)
{
    return i + j;
}
 
BOOST_AUTO_TEST_CASE(Add)
{
    BOOST_CHECK(add(2, 2) == 4);
}


BOOST_AUTO_TEST_CASE(CollidesTrue)
{
	auto b1 = make_shared<BoundingBox>(BoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
	auto b2 = make_shared<BoundingBox>(BoundingBox(Vector3(0.40f, 0.40f, 0.40f), 0.5f, 0.5f, 0.5f));
	BOOST_CHECK(b1->CollidesWith(b2));
	BOOST_CHECK(b2->CollidesWith(b1));
}

BOOST_AUTO_TEST_CASE(CollidesFalse)
{
	auto b1 = make_shared<BoundingBox>(BoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
	auto b2 = make_shared<BoundingBox>(BoundingBox(Vector3(0.50f, 0.50f, 0.50f), 0.5f, 0.5f, 0.5f));
	BOOST_CHECK(!b1->CollidesWith(b2));
	BOOST_CHECK(!b2->CollidesWith(b1));
}

BOOST_AUTO_TEST_SUITE_END()
