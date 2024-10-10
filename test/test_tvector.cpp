#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> v1(10);
  TDynamicVector<int> v2(v1);

  EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	const int n = 10;
	TDynamicVector<int> v1(n);
	for (int i = 0; i < n; i++) {
		v1[i] = 3;
	}
	TDynamicVector<int> v2(v1);

	v2[0] = 4;

	EXPECT_EQ(v1[0], 3);
	EXPECT_EQ(v2[0], 4);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
  TDynamicVector<int> v(10);

  ASSERT_ANY_THROW(v.at(-5) = 1);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(10);

	ASSERT_ANY_THROW(v.at(15) = 1);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
  TDynamicVector<int> v(10);
  
  ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
  TDynamicVector<int> v1(10);
  TDynamicVector<int> v2(10);

  ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(5);

	v1 = v2;
    EXPECT_EQ(v1.size(), v2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(5);

	v1 = v2;
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(10);

	bool res;
	res = (v1 == v2);
	EXPECT_TRUE(res);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(10);

	bool res;
	res = (v == v);
	EXPECT_TRUE(res);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(5);

	bool res;
	res = (v1 == v2);
	EXPECT_FALSE(res);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);

	int val = 1;
	v1[0] = 1;
	v1[1] = 1;
	v2[0] = 2;
	v2[1] = 2;
	v1 = v1 + val;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);

	int val = 1;
	v1[0] = 2;
	v1[1] = 2;
	v2[0] = 1;
	v2[1] = 1;
	v1 = v1 - val;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);

	int val = 5;
	v1[0] = 1;
	v1[1] = 2;
	v2[0] = 5;
	v2[1] = 10;
	v1 = v1 * val;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	TDynamicVector<int> res(2);

	v1[0] = 1;
	v1[1] = 1;
	v2[0] = 2;
	v2[1] = 2;
	res[0] = 3;
	res[1] = 3;

	EXPECT_EQ(v1 + v2, res);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(1);
	TDynamicVector<int> v2(2);

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	TDynamicVector<int> res(2);

	v1[0] = 1;
	v1[1] = 1;
	v2[0] = 2;
	v2[1] = 2;
	res[0] = -1;
	res[1] = -1;

	EXPECT_EQ(v1 - v2, res);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(1);
	TDynamicVector<int> v2(2);

	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);

	v1[0] = 2;
	v1[1] = 2;
	v2[0] = 3;
	v2[1] = 3;

	ASSERT_NO_THROW(v1 * v2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(5);

	v1[0] = 2;
	v1[1] = 2;
	v2[0] = 3;
	v2[1] = 3;

	ASSERT_ANY_THROW(v1 * v2);
}

TEST(TDynamicVector, can_move_constructor)
{
	TDynamicVector<int> v1(2);
	int* tmp = v1.get_pMem();
	TDynamicVector<int> v2(std::move(v1));

	EXPECT_EQ(v1.size(), 0);
	EXPECT_EQ(v1.get_pMem(), nullptr);

	EXPECT_EQ(v2.size(), 2);
	EXPECT_EQ(v2.get_pMem(), tmp);
}

TEST(TDynamicVector, can_move_assign)
{
	TDynamicVector<int> v1(2);
	int* tmp = v1.get_pMem();
	TDynamicVector<int> v2 = std::move(v1);

	EXPECT_EQ(v1.size(), 0);
	EXPECT_EQ(v1.get_pMem(), nullptr);

	EXPECT_EQ(v2.size(), 2);
	EXPECT_EQ(v2.get_pMem(), tmp);
}

